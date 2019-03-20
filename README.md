# Drum Machine/Sample player sketch for the Motivation Radio Eurorack module

Motivation Radio is a general purpose eurorack module based on the ESP32 with:

	* 4 Gate/Trigger inputs

	* 4 CV inputs -5V to +5V range, 12 bit resolution

	* 4 Gate/Trigger outputs 0-6V

	* 4 CV outputs 0-6.144V 12 bit resolution

	* 128x32 OLED display

	* Encoder with switch

	* MIDI in and out with 1/8 jacks - MIDI in works with either polarity (Korg or Arturia), MIDI out is MMA standard (Korg)

	* Bluetooth and Wifi are supported by the ESP32 module

PCBs and panels for Motivation Radio are available from Pusherman: https://pushermanproductions.com/product/motivation-radio-esp32-based-eurorack-breakout-module-pcb-fr4-panel/

Motivation Radio is intended mainly for interfacing eurorack to other devices (e.g. iPad) wirelessly but it can do more!

This example shows how to play audio samples at 22khz on one of the DAC outputs. 

* Gate inputs - sample triggers. sample can be selected in the menu. Serial MIDI input can also trigger samples: sample 0=Note 35, sample 1=Note 36 etc. MIDI channel 10 default, can change in the menu.

* CV inputs - selectable in the menu as volume (e.g. accent input), sample number, or no action

* Gate outputs - not currently used

* CV outputs - left output is audio out - note it has a DC offset of 3V at idle. Will hard limit if the sum of the samples exceeds 16 bits 

* NOTE: "save config" in the menu is not currently implemented


# Software Dependendencies:

* Adafruit Graphics library and the SSD1306 driver https://github.com/adafruit/Adafruit-GFX-Library https://github.com/adafruit/Adafruit_SSD1306

* Arduino Menu system https://github.com/neu-rah/ArduinoMenu

* Clickencoder (included in the sketch library directory)

"wav2header" utility is included which will auto generate the required header files from 22 or 44khz .wav files. see resources/readme.md

Compiled with Arduino 1.85 with ESP32 Arduino installed. Use "ESP32 DEV Module" as the board and "NO OTA (Large App)" as the partition scheme. This partition scheme has a limit of 2Mb for the app size. I think its possible to create a partition scheme to use most of the 4Mb of flash but I have not tried it. 

More info in the Wiki: https://github.com/rheslip/Motivation-Radio-Drum-Machine/wiki

Rich Heslip Feb 2019

