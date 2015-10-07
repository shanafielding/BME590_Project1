  /*
  Piano.ino
  An Arduino piano.
  @author: Suyash Kumar
  @author: Shana Fielding
  @author: Amy Zhao 
  */
  
  #include <Wire.h>  
  #include "Max3421e.h"
  #include "Usbhost.h"
  #include "AndroidAccessory.h"
  
  
  #define numKeys 8
  #define piezo 7
  #define startButton 47
  #define winLED 22
  #define endButton 45
  
  
  AndroidAccessory acc("Manufacturer",
  		"Model",
  		"Description",
  		"1.0",
  		"http://yoursite.com",
                  "0000000012345678");
  
  int pianoPins[numKeys]={42, 40, 38, 36, 34, 32, 30, 28};

  void setup(){
    // set communiation speed
    Serial.begin(115200);
   
    Serial.print("\r\nStart");
    boolean out = acc.isConnected();
    Serial.println(out, DEC);
    acc.powerOn();
    //Set all pins:
    pinMode(winLED, OUTPUT);
    for (int i=0;i<numKeys;i++){
      pinMode(pianoPins[i],INPUT);
    }
  }
  
  void loop(){
    boolean c = digitalRead(42);
    boolean d = digitalRead(40);
    boolean e = digitalRead(38);
    boolean f = digitalRead(36);
    boolean g = digitalRead(34);
    boolean a = digitalRead(32);
    boolean b = digitalRead(30);
    boolean h = digitalRead(28);
    
    byte msg[1];
    if(acc.isConnected()) {
      int len;
      len = acc.read(msg, sizeof(msg), 1); // read data into msg variable  
      if (len>0) {
        if (msg[0]=='Y'){
          digitalWrite(winLED, HIGH);
        } 
      }
      if (c) acc.write('C');    
      if (d) acc.write('D');
      if (e) acc.write('E');
      if (f) acc.write('F');
      if (g) acc.write('G');
      if (a) acc.write('A');
      if (b) acc.write('B');
      if (h) acc.write('H');
      
  }
  
}
