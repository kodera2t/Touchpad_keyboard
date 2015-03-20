//Touchpad keyboard program for ohmic resistive sheet
// Fev.27, 2015 kodera2t
///This program is free software: you can redistribute it and/or modify
///it under the terms of the GNU General Public License as published by
///the Free Software Foundation, either version 3 of the License, or
// any later version.

#include <stdint.h>
#include "TouchScreen.h"

#define YP A3  // must be an analog pin, use "An" notation!
#define XM A2  // must be an analog pin, use "An" notation!
#define YM A1   // can be a digital pin
#define XP A0   // can be a digital pin

/// Magic number "370" is a ohmic value of your touchpad
/// Need to adjust for your own touch pad
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 370);
  int flag=0;
  int capsflag=0;
void setup(void) {
//  Keyboard.begin(4800);
  Keyboard.begin();
}

void loop(void) {
  int ydiv=(934-230)/12; /// key size (width) of character key. Need to modify to fit your case
  int sample_x,sample_y;
  int i;
  TSPoint p = ts.getPoint();
  if (p.z > ts.pressureThreshhold) {
//       Keyboard.print("X = "); Keyboard.print(p.x);  // for fitting to your touchpad
//       Keyboard.print("\tY = "); Keyboard.print(p.y);
//       Keyboard.print("\tPressure = "); Keyboard.println(p.z);

       sample_x=p.x;
       sample_y=p.y;

       if(capsflag==1){
         flag=1;
       }
       
       if((785<sample_x)&&(sample_x<900)) /// first line of keyboard
       {
         /// DELETE
         if((53<sample_y)&&(sample_y<190))
         {
           Keyboard.write(0x08);
           goto outloop;
         }
         else for(i=0;i<13;i++){ ///staring first line of keyboard next to "DELETE"
           //i++;
          if(((230+ydiv*i)<sample_y)&&(sample_y<(230+ydiv*(i+1))))
         {
           switch(i){
           case 0:
           if(flag==1){
            Keyboard.print("+");  
            flag=0;          
           }else{
           Keyboard.print("=");
           }
           goto outloop;
           case 1:
           if(flag==1){
            Keyboard.print("_");  
            flag=0;          
           }else{
           Keyboard.print("-");
           }
           goto outloop;
           case 2:
           if(flag==1){
            Keyboard.print(")");  
            flag=0;          
           }else{
           Keyboard.print("0");
           }
           goto outloop;
           case 3:
           if(flag==1){
            Keyboard.print("(");  
            flag=0;          
           }else{
           Keyboard.print("9");
           }
           goto outloop;
           case 4:
           if(flag==1){
            Keyboard.print("*");  
            flag=0;          
           }else{
           Keyboard.print("8");
           }
           goto outloop;
           case 5:
           if(flag==1){
            Keyboard.print("&");  
            flag=0;          
           }else{
           Keyboard.print("7");
           }
           goto outloop;
           case 6:
           if(flag==1){
            Keyboard.print("^");  
            flag=0;          
           }else{
           Keyboard.print("6");
           }
           goto outloop;
           case 7:
           if(flag==1){
            Keyboard.print("%");  
            flag=0;          
           }else{
           Keyboard.print("5");
           }
           goto outloop;
           case 8:
           if(flag==1){
            Keyboard.print("$");  
            flag=0;          
           }else{
           Keyboard.print("4");
           }
           goto outloop;
           case 9:
           if(flag==1){
            Keyboard.print("#");  
            flag=0;          
           }else{
           Keyboard.print("3");
           }
           goto outloop;
           case 10:
           if(flag==1){
            Keyboard.print("@");  
            flag=0;          
           }else{
           Keyboard.print("2");
           }
           goto outloop;
           case 11:
           if(flag==1){
            Keyboard.print("!");  
            flag=0;          
           }else{
           Keyboard.print("1");
           }
           goto outloop;
           case 12:
           if(flag==1){
            Keyboard.print("~");  
            flag=0;          
           }else{
           Keyboard.print("`");
           }
           goto outloop;
         }          
         }        
         }
       }//end of first line
outloop:


       if((625<sample_x)&&(sample_x<785)) /// second line of keyboard
       {

       //special keys of second line
         if((900<sample_y)&&(sample_y<950))
         {
           Keyboard.write(0x09); ////horizontal tab
           goto outloop2;
         }       
         if((53<sample_y)&&(sample_y<130))
         {
           if(flag==0){
           Keyboard.write(0x5c); /////back slash
           goto outloop2;
           }else
           Keyboard.print("|");
           flag=0;
           goto outloop2;
         }         else for(i=0;i<12;i++){
           //i++;
          if(((170+ydiv*i)<sample_y)&&(sample_y<(170+ydiv*(i+1))))
         {
           switch(i){
           case 0:
           if(flag==1){
            Keyboard.print("}");  
            flag=0;          
           }else{
           Keyboard.print("]");
           }
           goto outloop2;
           case 1:
           if(flag==1){
            Keyboard.print("{");  
            flag=0;          
           }else{
           Keyboard.print("[");
           }
           goto outloop2;
           case 2:
           if(flag==1){
            Keyboard.print("P");  
            flag=0;          
           }else{
           Keyboard.print("p");
           }
           goto outloop2;
           case 3:
           if(flag==1){
            Keyboard.print("O");  
            flag=0;          
           }else{
           Keyboard.print("o");
           }
           goto outloop2;
           case 4:
           if(flag==1){
            Keyboard.print("I");  
            flag=0;          
           }else{
           Keyboard.print("i");
           }
           goto outloop2;
           case 5:
           if(flag==1){
            Keyboard.print("U");  
            flag=0;          
           }else{
           Keyboard.print("u");
           }
           goto outloop2;
           case 6:
           if(flag==1){
            Keyboard.print("Y");  
            flag=0;          
           }else{
           Keyboard.print("y");
           }
           goto outloop2;
           case 7:
           if(flag==1){
            Keyboard.print("T");  
            flag=0;          
           }else{
           Keyboard.print("t");
           }
           goto outloop2;
           case 8:
           if(flag==1){
            Keyboard.print("R");  
            flag=0;          
           }else{
           Keyboard.print("r");
           }
           goto outloop2;
           case 9:
           if(flag==1){
            Keyboard.print("E");  
            flag=0;          
           }else{
           Keyboard.print("e");
           }
           goto outloop2;
           case 10:
           if(flag==1){
            Keyboard.print("W");  
            flag=0;          
           }else{
           Keyboard.print("w");
           }
           goto outloop2;
           case 11:
           if(flag==1){
            Keyboard.print("Q");  
            flag=0;          
           }else{
           Keyboard.print("q");
           }
           goto outloop2;

         }          
         }        
         }
       }//end of second line
outloop2:

       if((500<sample_x)&&(sample_x<600)) /// third line of keyboard
       {

       //special keys of second line
       ///CAPS lock!
         if((897<sample_y)&&(sample_y<950))
         {
             if(capsflag==0){
          capsflag=1;
            }else{
            capsflag=0;
            flag=0;
            }
           goto outloop3;
         }
                ///ENTER
         if((60<sample_y)&&(sample_y<173))
         {
           Keyboard.write(0xB0);
           goto outloop3;
         }
         
         
         
        for(i=0;i<11;i++){
           //i++;
          if(((230+ydiv*i)<sample_y)&&(sample_y<(230+ydiv*(i+1))))
         {
           switch(i){
           case 0:
           if(flag==1){
            Keyboard.write(0x22);  
            flag=0;          
           }else{
           Keyboard.print("'");
           }
           goto outloop3;
           case 1:
           if(flag==1){
            Keyboard.print(":");  
            flag=0;          
           }else{
           Keyboard.print(";");
           }
           goto outloop3;
           case 2:
           if(flag==1){
            Keyboard.print("L");  
            flag=0;          
           }else{
           Keyboard.print("l");
           }
           goto outloop3;
           case 3:
           if(flag==1){
            Keyboard.print("K");  
            flag=0;          
           }else{
           Keyboard.print("k");
           }
           goto outloop3;
           case 4:
           if(flag==1){
            Keyboard.print("J");  
            flag=0;          
           }else{
           Keyboard.print("j");
           }
           goto outloop3;
           case 5:
           if(flag==1){
            Keyboard.print("H");  
            flag=0;          
           }else{
           Keyboard.print("h");
           }
           goto outloop3;
           case 6:
           if(flag==1){
            Keyboard.print("G");  
            flag=0;          
           }else{
           Keyboard.print("g");
           }
           goto outloop3;
           case 7:
           if(flag==1){
            Keyboard.print("F");  
            flag=0;          
           }else{
           Keyboard.print("f");
           }
           goto outloop3;
           case 8:
           if(flag==1){
            Keyboard.print("D");  
            flag=0;          
           }else{
           Keyboard.print("d");
           }
           goto outloop3;
           case 9:
           if(flag==1){
            Keyboard.print("S");  
            flag=0;          
           }else{
           Keyboard.print("s");
           }
           goto outloop3;
           case 10:
           if(flag==1){
            Keyboard.print("A");  
            flag=0;          
           }else{
           Keyboard.print("a");
           }
           goto outloop3;
         }          
         }        
         }
       }//end of third line
outloop3:

       if((362<sample_x)&&(sample_x<430)) /// fourth line of keyboard
       {

       //special keys of second line
       ///LEFT SHIFT
         if((870<sample_y)&&(sample_y<950))
         {
          flag=1;
          //            Keyboard.print("L-shift");  
          goto outloop4;
         }
       ///RIGHT SHIFT
         if((60<sample_y)&&(sample_y<185))
         {
          flag=1;
          //                      Keyboard.print("R-shift");  
           goto outloop4;
         }
         
         
         
        for(i=0;i<11;i++){
           //i++;
          if(((270+ydiv*i)<sample_y)&&(sample_y<(270+ydiv*(i+1))))
         {
           switch(i){
           case 0:
           if(flag==1){
            Keyboard.print("?");  
            flag=0;          
           }else{
           Keyboard.print("/");
           }
           goto outloop4;
           case 1:
           if(flag==1){
            Keyboard.print(">");  
            flag=0;          
           }else{
           Keyboard.print(".");
           }
           goto outloop4;
           case 2:
           if(flag==1){
            Keyboard.print("<");  
            flag=0;          
           }else{
           Keyboard.print(",");
           }
           goto outloop4;
           case 3:
           if(flag==1){
            Keyboard.print("M");  
            flag=0;          
           }else{
           Keyboard.print("m");
           }
           goto outloop4;
           case 4:
           if(flag==1){
            Keyboard.print("N");  
            flag=0;          
           }else{
           Keyboard.print("n");
           }
           goto outloop4;
           case 5:
           if(flag==1){
            Keyboard.print("B");  
            flag=0;          
           }else{
           Keyboard.print("b");
           }
           goto outloop4;
           case 6:
           if(flag==1){
            Keyboard.print("V");  
            flag=0;          
           }else{
           Keyboard.print("v");
           }
           goto outloop4;
           case 7:
           if(flag==1){
            Keyboard.print("C");  
            flag=0;          
           }else{
           Keyboard.print("c");
           }
           goto outloop4;
           case 8:
           if(flag==1){
            Keyboard.print("X");  
            flag=0;          
           }else{
           Keyboard.print("x");
           }
           goto outloop4;
           case 9:
           if(flag==1){
            Keyboard.print("Z");  
            flag=0;          
           }else{
           Keyboard.print("z");
           }
           goto outloop4;
         }          
         }        
         }
       }//end of fourth line
outloop4:


       if((80<sample_x)&&(sample_x<280)) /// fifth line of keyboard
       {

       //special keys of second line
       ///LEFT CTRL
       //////CAUTION!!: CTRL key assigned to CTRL+C for my purpose
         if((874<sample_y)&&(sample_y<942))
         {
         Keyboard.write(0x80);
          goto outloop5;
         }
         
          if((760<sample_y)&&(sample_y<796))
         {
         Keyboard.write(0x82);
          goto outloop5;
         }   
              if((310<sample_y)&&(sample_y<687))
         {
         Keyboard.write(0x20);
          goto outloop5;
         }   
                   if((191<sample_y)&&(sample_y<310))
         {
         Keyboard.write(0x86);
          goto outloop5;
         }       
       ///RIGHT CTRL
       //////CAUTION!!: CTRL key assigned to CTRL+C for my purpose
         if((60<sample_y)&&(sample_y<183))
         {
         Keyboard.write(0x84);
           goto outloop5;
         }
         

       }//end of fourth line
outloop5:


     if(flag==1){
       digitalWrite(13,HIGH);
     }else{
       digitalWrite(13,LOW);
     }
     if(capsflag==1){
       digitalWrite(12,HIGH);
     }else{
       digitalWrite(12,LOW);
     }
     
  //}
  delay(400);
  }
  }


//  delay(10);
//}
