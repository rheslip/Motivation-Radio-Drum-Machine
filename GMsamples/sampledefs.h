
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
// sampledefs.h - sample table definitions
// builds the sample table structure

#ifndef SAMPLEDEFS_H_
#define SAMPLEDEFS_H_

#define BASS2_SIZE (sizeof(Bass2)/sizeof(int16_t))
#define BASS1_SIZE (sizeof(Bass1)/sizeof(int16_t))
#define SIDESTICK_SIZE (sizeof(SideStick)/sizeof(int16_t))
#define SNARE1_SIZE (sizeof(Snare1)/sizeof(int16_t))
#define CLAP_SIZE (sizeof(Clap)/sizeof(int16_t))
#define SNARE2_SIZE (sizeof(Snare2)/sizeof(int16_t))
#define LOW_TOM_SIZE (sizeof(Low_Tom)/sizeof(int16_t))
#define HAT_CLOSED_SIZE (sizeof(Hat_Closed)/sizeof(int16_t))
#define TOM1_SIZE (sizeof(Tom1)/sizeof(int16_t))
#define PEDAL_HAT_SIZE (sizeof(Pedal_Hat)/sizeof(int16_t))
#define MID_TOM2_SIZE (sizeof(Mid_Tom2)/sizeof(int16_t))
#define OPEN_HAT_SIZE (sizeof(Open_Hat)/sizeof(int16_t))
#define MID_TOM1_SIZE (sizeof(Mid_Tom1)/sizeof(int16_t))
#define HI_TOM_SIZE (sizeof(Hi_Tom)/sizeof(int16_t))
#define CRASHCYM1_SIZE (sizeof(CrashCym1)/sizeof(int16_t))
#define LONG_RIDE_SIZE (sizeof(Long_Ride)/sizeof(int16_t))
#define CHINACYM_SIZE (sizeof(ChinaCym)/sizeof(int16_t))
#define RIDE_BELL_SIZE (sizeof(Ride_Bell)/sizeof(int16_t))
#define TAMBOURINE_SIZE (sizeof(Tambourine)/sizeof(int16_t))
#define SPLASHCYM_SIZE (sizeof(SplashCym)/sizeof(int16_t))
#define COWBELL_SIZE (sizeof(Cowbell)/sizeof(int16_t))
#define CRASHCYM2_SIZE (sizeof(CrashCym2)/sizeof(int16_t))
#define BONGOHI_SIZE (sizeof(BongoHi)/sizeof(int16_t))
#define BONGOLO_SIZE (sizeof(BongoLo)/sizeof(int16_t))
#define CONGASLAP_SIZE (sizeof(CongaSlap)/sizeof(int16_t))
#define CONGAHI_SIZE (sizeof(CongaHi)/sizeof(int16_t))
#define CONGALOW_SIZE (sizeof(CongaLow)/sizeof(int16_t))
#define TIMBALE1_SIZE (sizeof(Timbale1)/sizeof(int16_t))
#define TIMBALE2_SIZE (sizeof(Timbale1)/sizeof(int16_t))
#define AGOGOHI_SIZE (sizeof(AgogoHi)/sizeof(int16_t))
#define AGOGOLO_SIZE (sizeof(AgogoLo)/sizeof(int16_t))
#define CABASA_SIZE (sizeof(Cabasa)/sizeof(int16_t))
#define MARACAS_SIZE (sizeof(Maracas)/sizeof(int16_t))


// sample table holds the sample information

struct sample_t {
  const int16_t * samplearray; // pointer to sample array
  uint32_t samplesize; // size of the sample array
  uint32_t sampleindex; // current sample array index when playing. index at last sample= not playing
  uint8_t MIDINOTE;  // MIDI note on that plays this sample
  uint8_t play_volume; // play volume 0-127
  char sname[20];        // sample name
} sample[] = { // fill it with default sample info

  Bass2,      // pointer to sample array
  BASS2_SIZE, // size of the sample array
  BASS2_SIZE, // sampleindex. if at end of sample array sound is not playing
  35,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Bass Drum 2",  // sample name

  Bass1,      // pointer to sample array
  BASS1_SIZE, // size of the sample array
  BASS1_SIZE, // sampleindex at end of sample array = not playing
  36,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Bass Drum 1",  // sample name

  SideStick,      // pointer to sample array
  SIDESTICK_SIZE, // size of the sample array
  SIDESTICK_SIZE, // sampleindex at end of sample array = not playing
  37,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Side Stick",  // sample name

  Snare1,      // pointer to sample array
  SNARE1_SIZE, // size of the sample array
  SNARE1_SIZE, // sampleindex at end of sample array = not playing
  38,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Snare 1",  // sample name

  Clap,      // pointer to sample array
  CLAP_SIZE, // size of the sample array
  CLAP_SIZE, // sampleindex at end of sample array = not playing
  39,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Hand Clap",  // sample name
  
  Snare2,      // pointer to sample array
  SNARE2_SIZE, // size of the sample array
  SNARE2_SIZE, // sampleindex at end of sample array = not playing
  40,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Snare 2",  // sample name
  
  Low_Tom,  
  LOW_TOM_SIZE,
  LOW_TOM_SIZE, // sampleindex at end of sample array = not playing
  41,
  127,       // play volume 0-127
  "Low Tom",
  
  Hat_Closed,  
  HAT_CLOSED_SIZE,
  HAT_CLOSED_SIZE, // sampleindex at end of sample array = not playing
  42,
  127,       // play volume 0-127
  "Closed Hat",

  Tom1,  
  TOM1_SIZE,
  TOM1_SIZE, // sampleindex at end of sample array = not playing
  43,
  127,       // play volume 0-127
  "Tom1",

  Pedal_Hat,  
  PEDAL_HAT_SIZE,
  PEDAL_HAT_SIZE, // sampleindex at end of sample array = not playing
  44,
  127,       // play volume 0-127
  "Pedal Hat",
  
  Mid_Tom2,  
  MID_TOM2_SIZE,
  MID_TOM2_SIZE, // sampleindex at end of sample array = not playing
  45,
  127,       // play volume 0-127
  "Mid Tom 2",

  Open_Hat,  
  OPEN_HAT_SIZE,
  OPEN_HAT_SIZE, // sampleindex at end of sample array = not playing
  46,
  127,       // play volume 0-127
  "Open Hat",

  Mid_Tom1,      // pointer to sample array
  MID_TOM1_SIZE, // size of the sample array
  MID_TOM1_SIZE, // sampleindex at end of sample array = not playing
  47,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Mid Tom 1",  // sample name

  Hi_Tom,      // pointer to sample array
  HI_TOM_SIZE, // size of the sample array
  HI_TOM_SIZE, // sampleindex at end of sample array = not playing
  48,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "High Tom",  // sample name

  CrashCym1,      // pointer to sample array
  CRASHCYM1_SIZE, // size of the sample array
  CRASHCYM1_SIZE, // sampleindex at end of sample array = not playing
  49,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Crash Cymbal 1",  // sample name

  Long_Ride,      // pointer to sample array
  LONG_RIDE_SIZE, // size of the sample array
  LONG_RIDE_SIZE, // sampleindex at end of sample array = not playing
  51,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Long Ride",  // sample name

  ChinaCym,      // pointer to sample array
  CHINACYM_SIZE, // size of the sample array
  CHINACYM_SIZE, // sampleindex at end of sample array = not playing
  52,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "China Cymbal",  // sample name

  Ride_Bell,      // pointer to sample array
  RIDE_BELL_SIZE, // size of the sample array
  RIDE_BELL_SIZE, // sampleindex at end of sample array = not playing
  53,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Ride Bell",  // sample name  

  Tambourine,      // pointer to sample array
  TAMBOURINE_SIZE, // size of the sample array
  TAMBOURINE_SIZE, // sampleindex at end of sample array = not playing
  54,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Tambourine",  // sample name  

  SplashCym,      // pointer to sample array
  SPLASHCYM_SIZE, // size of the sample array
  SPLASHCYM_SIZE, // sampleindex at end of sample array = not playing
  55,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Splash Cymbal",  // sample name  


  Cowbell,      // pointer to sample array
  COWBELL_SIZE, // size of the sample array
  COWBELL_SIZE, // sampleindex at end of sample array = not playing
  56,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Cowbell",  // sample name  

  CrashCym2,      // pointer to sample array
  CRASHCYM2_SIZE, // size of the sample array
  CRASHCYM2_SIZE, // sampleindex at end of sample array = not playing
  57,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Crash Cymbal 2",  // sample name  

  BongoHi,      // pointer to sample array
  BONGOHI_SIZE, // size of the sample array
  BONGOHI_SIZE, // sampleindex at end of sample array = not playing
  60,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Bongo Hi",  // sample name  

  BongoLo,      // pointer to sample array
  BONGOLO_SIZE, // size of the sample array
  BONGOLO_SIZE, // sampleindex at end of sample array = not playing
  61,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Bongo Low",  // sample name  

  CongaSlap,      // pointer to sample array
  CONGASLAP_SIZE, // size of the sample array
  CONGASLAP_SIZE, // sampleindex at end of sample array = not playing
  62,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Conga Slap",  // sample name  

  CongaHi,      // pointer to sample array
  CONGAHI_SIZE, // size of the sample array
  CONGAHI_SIZE, // sampleindex at end of sample array = not playing
  63,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Conga Hi",  // sample name  

  CongaLow,      // pointer to sample array
  CONGALOW_SIZE, // size of the sample array
  CONGALOW_SIZE, // sampleindex at end of sample array = not playing
  64,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Conga Low",  // sample name

  Timbale1,      // pointer to sample array
  TIMBALE1_SIZE, // size of the sample array
  TIMBALE1_SIZE, // sampleindex at end of sample array = not playing
  65,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Timbale Hi",  // sample name  

  Timbale2,      // pointer to sample array
  TIMBALE2_SIZE, // size of the sample array
  TIMBALE2_SIZE, // sampleindex at end of sample array = not playing
  66,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Timbale Low",  // sample name  

  AgogoHi,      // pointer to sample array
  AGOGOHI_SIZE, // size of the sample array
  AGOGOHI_SIZE, // sampleindex at end of sample array = not playing
  67,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Agogo Hi",  // sample name  

  AgogoLo,      // pointer to sample array
  AGOGOLO_SIZE, // size of the sample array
  AGOGOLO_SIZE, // sampleindex at end of sample array = not playing
  68,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Agogo Low",  // sample name 
  
  Cabasa,      // pointer to sample array
  CABASA_SIZE, // size of the sample array
  CABASA_SIZE, // sampleindex at end of sample array = not playing
  69,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Cabasa",  // sample name    
  
  Maracas,      // pointer to sample array
  MARACAS_SIZE, // size of the sample array
  MARACAS_SIZE, // sampleindex at end of sample array = not playing
  70,            // MIDI note on that plays this sample
  127,       // play volume 0-127
  "Maracas",  // sample name    
};



#endif // SAMPLEDEFS_H_
