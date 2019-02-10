
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
// definitions for Arduino Menu System
// https://github.com/neu-rah/ArduinoMenu/tree/master/src/menuIO

//using namespace Menu;

#define gfxWidth 128
#define gfxHeight 32
#define fontX 6    // font width in pixels
#define fontY 10  // vertical text spacing
#define MAX_DEPTH 2 // max menu depth?
#define textScale 1

// save settings to eeprom - not yet implemented
result  savesetup(void) {
  return proceed;
}

TOGGLE(voice[0].cv_mode,subMenu_CV_A_MODE,"CV A  ",doNothing,noEvent,wrapStyle,
  VALUE("Not Assigned",NONE,doNothing,noEvent),
  VALUE("Volume",VOLUME,doNothing,noEvent),
  VALUE("Sample",SAMPLE,doNothing,noEvent)
);

TOGGLE(voice[1].cv_mode,subMenu_CV_B_MODE,"CV B  ",doNothing,noEvent,wrapStyle,
  VALUE("Not Assigned",NONE,doNothing,noEvent),
  VALUE("Volume",VOLUME,doNothing,noEvent),
  VALUE("Sample",SAMPLE,doNothing,noEvent)
);

TOGGLE(voice[2].cv_mode,subMenu_CV_C_MODE,"CV C  ",doNothing,noEvent,wrapStyle,
  VALUE("Not Assigned",NONE,doNothing,noEvent),
  VALUE("Volume",VOLUME,doNothing,noEvent),
  VALUE("Sample",SAMPLE,doNothing,noEvent)
);

TOGGLE(voice[3].cv_mode,subMenu_CV_D_MODE,"CV D  ",doNothing,noEvent,wrapStyle,
  VALUE("Not Assigned",NONE,doNothing,noEvent),
  VALUE("Volume",VOLUME,doNothing,noEvent),
  VALUE("Sample",SAMPLE,doNothing,noEvent)
);

MENU(mainMenu,"        SETUP",doNothing,noEvent,wrapStyle,
  FIELD(voice[0].sample,"Sample A","",0,(NUM_SAMPLES-1),1,0,doNothing,noEvent,wrapStyle),
  FIELD(voice[0].mix,"Level A","",0,127,1,0,doNothing,noEvent,wrapStyle),
  SUBMENU(subMenu_CV_A_MODE),
  FIELD(voice[1].sample,"Voice B","",0,(NUM_SAMPLES-1),1,0,doNothing,noEvent,wrapStyle),
  FIELD(voice[1].mix,"Level B","",0,127,1,0,doNothing,noEvent,wrapStyle),
  SUBMENU(subMenu_CV_B_MODE),
  FIELD(voice[2].sample,"Voice C","",0,(NUM_SAMPLES-1),1,0,doNothing,noEvent,wrapStyle),
  FIELD(voice[2].mix,"Level C","",0,127,1,0,doNothing,noEvent,wrapStyle),
  SUBMENU(subMenu_CV_C_MODE),
  FIELD(voice[3].sample,"Voice D","",0,(NUM_SAMPLES-1),1,0,doNothing,noEvent,wrapStyle),
  FIELD(voice[3].mix,"Level D","",0,127,1,0,doNothing,noEvent,wrapStyle),
  SUBMENU(subMenu_CV_D_MODE),
  FIELD(MIDI_Channel,"MIDI Channel","",1,16,1,0,doNothing,noEvent,wrapStyle),
  OP("Save Setup",savesetup,enterEvent),
  EXIT("<Exit Setup Menu")
 );
 
  // define menu colors --------------------------------------------------------
//  {{disabled normal,disabled selected},{enabled normal,enabled selected, enabled editing}}
//monochromatic color table
const colorDef<uint16_t> colors[] MEMMODE={
  {{WHITE,BLACK},{WHITE,BLACK,BLACK}},//bgColor
  {{BLACK,WHITE},{BLACK,WHITE,WHITE}},//fgColor
  {{BLACK,WHITE},{BLACK,WHITE,WHITE}},//valColor
  {{BLACK,WHITE},{BLACK,WHITE,WHITE}},//unitColor
  {{BLACK,WHITE},{WHITE,WHITE,WHITE}},//cursorColor
  {{BLACK,WHITE},{WHITE,BLACK,BLACK}},//titleColor
};

//the encoder button is a keyboard with only one key 
keyMap encBtn_map[]={{-ENC_SW,defaultNavCodes[enterCmd].ch}};  //negative pin numbers use internal pull-up, switch is on when low
keyIn<1> encButton(encBtn_map);   //1 is the number of keys

// menu system is driven by the encoder stream
MENU_INPUTS(in,&encStream);

MENU_OUTPUTS(out,MAX_DEPTH
  ,ADAGFX_OUT(display,colors,fontX,fontY,{0,0,gfxWidth/fontX,gfxHeight/fontY})
  ,NONE //must have 2 items at least if using this macro
);

NAVROOT(nav,mainMenu,MAX_DEPTH,in,out);


