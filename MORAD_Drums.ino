// Copyright 2019 Rich Heslip
//
// Author: Rich Heslip 
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
// 
// See http://creativecommons.org/licenses/MIT/ for more information.
//
// -----------------------------------------------------------------------------
//
// 
// sample player inspired by Jan Ostman's ESP8266 drum machine http://janostman.wordpress.com
// completely rewritten for the Motivation Radio Eurorack module
// plays samples in response to gate/trigger inputs and MIDI note on messages
// will play any 22khz sample file converted to a header file in the appropriate format
// Feb 3/19 - initial version

#include <Arduino.h> 

#include <WiFi.h>
//#include <i2s.h>
//#include <i2s_reg.h>
#include <pgmspace.h>
//#include "driver/i2s.h"
//#include "freertos/queue.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MIDI.h"
#include <menu.h>
#include <menuIO/clickEncoderIn.h>
#include <menuIO/keyIn.h>
#include <menuIO/chainStream.h>
#include <menuIO/serialOut.h>
#include <menuIO/adafruitGfxOut.h>
#include <menuIO/serialIn.h>
#include "MORAD_IO.h"


// MIDI stuff
uint8_t MIDI_Channel=10;  // default MIDI channel for percussion
struct SerialMIDISettings : public midi::DefaultSettings
{
  static const long BaudRate = 31250;
};
// must use HardwareSerial for extra UARTs
HardwareSerial MIDISerial(2);

// instantiate the serial MIDI library
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, MIDISerial, MIDI, SerialMIDISettings);

// create OLED display device
#define OLED_RESET -1  // unused port - to keep the compiler happy
Adafruit_SSD1306 display(OLED_RESET);

// encoder 
ClickEncoder clickEncoder(ENC_A,ENC_B,ENC_SW,4); // divide by 4 works best with my encoder
ClickEncoderStream encStream(clickEncoder,1);
  
// sample interrupt timer defs
#define DAC_TIMER_MICROS 46  // 22khz interrupt rate for DAC
#define ENC_TIMER_MICROS 1000 // 1khz for encoder
hw_timer_t * timer0 = NULL;
hw_timer_t * timer1 = NULL;

// ADC readings
#define ADC_RANGE 4097  // 12 bit ADC
uint16_t CV_in[4];

// we have four voices that can play any sample when triggered by the Gate inputs
// this structure holds the settings for each voice

enum CV_MODE {NONE,VOLUME,SAMPLE};

#define NUM_VOICES 4
struct voice_t {
  uint8_t sample; 
  uint8_t mix; 
  uint8_t cv_mode;
} voice[NUM_VOICES] = {
  0,      // default voice 0 assignment 
  127,    // max volume
  NONE,   // CV not assigned
  
  3,      // default voice 1 assignment 
  127,    // max volume
  NONE,   // CV not assigned
  
  7,    // default voice 2 assignment 
  127,    // max volume
  NONE,   // CV not assigned
  
  17,    // default voice 3 assignment 
  127,   // max volume
  NONE,   // CV not assigned
};  

// we can have an arbitrary number of samples but don't go too crazy because they have to be processed in the ISR at 22khz
// sound sample files must be 22khz 16 bit signed PCM format - see the sample include files for examples
// sample files are compiled into arrays and stored in ESP32 program flash
// if your sketch is too big you may have to fiddle with the flash partition scheme to enable more of the flash to be used for program space
// reading samples from the SPIFFs file system would be cool but its a lot more overhead
// calling the SPIFFs libraries from an ISR will probably not work anyway

// the header files can be auto generated by the wav2header utility
// put your 22khz or 44khz PCM wav files in a sample directory, run the utility and it will generate all the header files
//#include "GMsamples/samples.h"  // general MIDI set - do not run wav2header on these or it will mess up the midi mapping
// #include "808samples/samples.h" // 808 sounds
//#include "PNSsamples/samples.h"   // PNS soundfont set
// #include "Angular_Jungle_Set/samples.h"   // Jungle soundfont set - great!
//#include "WSA1_DRUMKIT/samples.h"   // WSA1 soundfont set
#include "Angular_Techno_Set/samples.h"   // Techno

#define NUM_SAMPLES (sizeof(sample)/sizeof(sample_t))

// ISR at 22khz writes the MCP4822 DAC using soft SPI and samples one ADC channel at a time
// single hardware SPI transactions are very slow on ESP32 Arduino and you can't use the SPI library from an ISR
// this ISR takes approx 25us to run but it depends how many samples are playing

void ICACHE_RAM_ATTR onTimer(){
  int32_t samplesum=0;
  uint32_t spiword,adcdata;
  static uint8_t channel;
//  digitalWrite(GATEout_0,1); // to time ISR  
  for (int i=0; i< NUM_SAMPLES;++i) {  // look for samples that are playing, scale their volume, and add them up
    if (sample[i].sampleindex < sample[i].samplesize) samplesum+=(int32_t)(sample[i].samplearray[sample[i].sampleindex++]*sample[i].play_volume);  // thats a mouthful!
  }
  samplesum=samplesum>>7;  // adjust for play_volume multiply above
  if  (samplesum>32767) samplesum=32767; // clip if sample sum is too large
  if  (samplesum<-32767) samplesum=-32767;
  samplesum+=32768; // convert to unsigned for DAC output
  
  spiword=(uint16_t) samplesum>> 4; // scale sum of samples from 16 bits to 12 bits
  // send sum of samples to DAC
  spiword = spiword & 0x0fff; // mask off 4 msbs which are DAC control
  spiword=spiword | 0x3000; // send to 1st DAC, use 2.048v reference
  digitalWrite(DAC0_CS,0); // assert DAC0 CS
  for (int i=0;i<16;++i) { // write it out SPI mode 0, MSB first
    digitalWrite(MOSI,(bool)(spiword & 0x8000)); // MSB first
    digitalWrite(SCLK,0); 
    digitalWrite(SCLK,1); 
    spiword=spiword<<1;   
  }
  digitalWrite(DAC0_CS,1); // deassert CS
  
  // sample the ADCs round robin style
  channel=channel&0x3; // ADC channel 0-3
  spiword=0x00060000 | (channel << 14); // start bit, single ended mode and channel #
  // read the ADC
  digitalWrite(ADC_CS,0); // assert DAC0 CS
  for (int i=0;i<19;++i) { // write it out SPI mode 0, MSB first
    digitalWrite(MOSI,(bool)(spiword & 0x00040000)); // MSB first
    digitalWrite(SCLK,0);
    spiword=spiword<<1;   // do this here to add some data setup time. also squares up the clock a bit
    adcdata|=(bool)digitalRead(MISO);
    digitalWrite(SCLK,1); 
    adcdata=adcdata<<1;  
  }
  digitalWrite(ADC_CS,1); // deassert CS
  CV_in[channel++]=(uint16_t)(~adcdata & 0xfff); // invert and save the ADC result - external buffer amp is inverting
 
//  digitalWrite(GATEout_0,0); // to time ISR
}



// encoder timer interrupt handler at 1khz
// we also sample the gate/trigger inputs and trigger sample playback

// trigger counters
// the CV inputs are sampled at a different rate which could cause an "accent" input to be missed due to timing skew
// so we trigger the sample the second time we see the gate active

uint8_t trigcnt[NUM_VOICES] = {0,0,0,0}; // trigger counters

void ICACHE_RAM_ATTR encTimer(){
  uint8_t sample_toplay,volume_toplay;
  uint32_t offset;
   
  clickEncoder.service();    // check the encoder inputs

 // handle drum triggers
  bool trigger;
  for (int i=0; i< NUM_VOICES;++i) {
    switch (i) { // sample gate inputs
      case 0:
        trigger=!digitalRead(GATEin_0); // active low gate inputs
        break;
      case 1:
        trigger=!digitalRead(GATEin_1);
        break; 
      case 2:
        trigger=!digitalRead(GATEin_2);
        break;
      case 3:
        trigger=!digitalRead(GATEin_3);
        break;
    }
    
    if (trigger) { 
      if (trigcnt[i]<=3) ++trigcnt[i];
      if (trigcnt[i]==2) { // trigger on second sample of gate active
      sample_toplay=voice[i].sample;  // default sample to play
      volume_toplay=voice[i].mix;     // default volume level to play
        switch (voice[i].cv_mode) { // handle CV inputs
          case NONE:
            break;
          case VOLUME:
            volume_toplay=(voice[i].mix*CV_in[i]/ADC_RANGE); // set play volume from mix level and CV in
            break;
          case SAMPLE:
            offset=CV_in[i]*NUM_SAMPLES/ADC_RANGE+NUM_SAMPLES/2+1;  // 0V in = sample selected in menu
            sample_toplay=(sample_toplay+(uint8_t)offset) % NUM_SAMPLES; // select sample using CV as an offset into the sample table
            break; 
          default:
            voice[i].cv_mode=NONE;  // if its messed up fix it        
        }
        sample[voice[i].sample].play_volume=volume_toplay;  // set volume
        sample[sample_toplay].sampleindex=0; // start sample playback on selected sample
      }
    }
    else trigcnt[i]=0;
  }
}

// serial MIDI handler

void HandleNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
  if (channel==MIDI_Channel) {
      for (int i=0; i< NUM_SAMPLES;++i) {  // 
        if (sample[i].MIDINOTE == note) {
          sample[i].play_volume=velocity;  // use MIDI volume
          sample[i].sampleindex=0;  // if note matches sample MIDI note number, start it playing 
        }
      }
  }
}

#include "menusystem.h"  // has to follow encoder instance and sampledefs.h

void maindisplay(void) {
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextColor(WHITE);
  display.println("    MORAD DRUMS");
  display.println();
  display.println("Press for Setup Menu");
  display.display();
}

//when menu is suspended
result idle(menuOut& o,idleEvent e) {
  maindisplay();
  return proceed;
}

void setup() {
//  WiFi.forceSleepBegin();             
//  delay(1);
//  WiFi.disconnect();
//  WiFi.mode(WIFI_OFF);
//  WiFi.forceSleepBegin();
 // delay(1);                          
//  system_update_cpu_freq(160);

 Serial.begin(115200);

 Serial.print("Number of Samples ");
 Serial.println(NUM_SAMPLES);      
 /* 
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

 // Serial.print(F("IP address is ")); 
 // Serial.println(WiFi.localIP()); 


  AppleMIDI.begin("MORAD"); // 'MORAD' will show up as the session name

  AppleMIDI.OnReceiveNoteOn(OnAppleMidiNoteOn);
  */
// set up I/O pins
// set up SPI pins for soft SPI
  pinMode(SCLK, OUTPUT);     
  pinMode(MOSI, OUTPUT); 

  pinMode(DAC0_CS, OUTPUT);
  pinMode(DAC1_CS, OUTPUT);
  pinMode(ADC_CS, OUTPUT);  
  digitalWrite(DAC0_CS, HIGH); // deassert chip selects
  digitalWrite(DAC1_CS, HIGH);
  digitalWrite(ADC_CS, HIGH);
  pinMode(GATEout_0, OUTPUT);
  pinMode(GATEout_1, OUTPUT);
  pinMode(GATEout_2, OUTPUT);
  pinMode(GATEout_3, OUTPUT);
  
  pinMode(GATEin_0, INPUT);
  pinMode(GATEin_1, INPUT);
  pinMode(GATEin_2, INPUT);
  pinMode(GATEin_3, INPUT);

//  Set up serial MIDI port
  MIDISerial.begin(31250, SERIAL_8N1, MIDIRX,MIDITX ); // midi port

  // set up serial MIDI library callbacks
  MIDI.setHandleNoteOn(HandleNoteOn);  // 

  // Initiate serial MIDI communications, listen to all channels
  MIDI.begin(MIDI_CHANNEL_OMNI);
  
// set up timer interrupt to update DAC
  // Use 1st timer of 4 (counted from zero).
  // Set 80 divider for prescaler (see ESP32 Technical Reference Manual for more info).
  timer0 = timerBegin(0, 80, true);

  // Attach timer ISR to our timer.
  timerAttachInterrupt(timer0, &onTimer, true);

  // Set alarm to trigger ISR (value in microseconds).
  // Repeat the alarm (third parameter)
  timerAlarmWrite(timer0, DAC_TIMER_MICROS, true);
  // Start the timer 
  timerAlarmEnable(timer0);

  // 2nd timer for encoder and trigger sampling
  timer1 = timerBegin(1, 80, true);
  timerAttachInterrupt(timer1, &encTimer, true);
  // Set alarm to trigger ISR (value in microseconds).
  // Repeat the alarm (third parameter)
  timerAlarmWrite(timer1, ENC_TIMER_MICROS, true);
  timerAlarmEnable(timer1);

   // start up the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.clearDisplay();
  display.println("MORAD DRUMS Feb 3/19");
  display.display();
  delay(3000);

    // set up the menu system
  nav.idleTask=idle;//point a function to be used when menu is suspended
  nav.idleOn(); // start up in idle state
  nav.navRoot::timeOut=30; // inactivity timeout

  maindisplay(); 
}



void loop() {
  
  MIDI.read();  // do serial MIDI
  
  //do menus on a need to draw basis:
  nav.doInput();
  if (nav.changed(0)) {//only draw if changed
    nav.doOutput();
    display.display();
  }  
}



