#include <SoftwareSerial.h>

SoftwareSerial jdy33(2,3);

char c;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  jdy33.begin(9600);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(jdy33.available()){   
    c = jdy33.read();
    Serial.print(c);
    
  }

  if(Serial.available()){
    c = Serial.read();
    jdy33.print(c);
  }
}
