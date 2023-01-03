//This code is use for scan the present baudrate of bluetooth device

#include <SoftwareSerial.h>

#define JDY33_BAUD_CMD "AT+BAUD8\r\n"

SoftwareSerial jdy33(2,3);

unsigned long timeTest = 0;
unsigned long prevTime = 0;

long baudArray1[8]={115200,9600,2400,4800,19200,38400,57600,128000};

long baudArray[8]={8,4,2,3,5,6,7,9};

uint8_t countArray=0;
uint8_t countArray1=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Start scan baudrate!");

  Serial.println("Scanning...");

  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println("Start scanning: " + String(baudArray[countArray]));
  // jdy33.begin(baudArray1[countArray1]);

  // String temp = "";

  // unsigned long start = millis();

  // jdy33.print(JDY33_BAUD_CMD);

  // while(millis() - start <= 500){
  //   if(jdy33.available()){
  //     char c = jdy33.read();
  //     temp += c;
  //   }else;
  // }

  // if(temp.indexOf("OK") > -1){
  //   Serial.println("Success");
  // }else{
  //   Serial.println("Failed!");
  // }

  
  
  Serial.println("Baudrate: " + String(baudArray1[countArray1]) + "?");

  jdy33.begin(baudArray1[countArray1]);

  readBluetooth(baudArray1[countArray1]);
 
  if(countArray < 7 && countArray1 < 7){
    countArray++;
    countArray1++;
  }else{
    Serial.println("___Fail___");
    Serial.println("Please check the connection or hardware");
    countArray = 0;
    countArray1 = 0;
  }
}

// void readSim(long _baud){
//   unsigned long Starttime=millis();
//   String tempdata= "";
//   bool stopwhile = false;
//   sim800ds.print(JDY33_BAUD_CMD);
//   while((millis() - Starttime <=400)){
//     if(sim800ds.available()){
//       char uu = sim800ds.read();
//       delay(1);
//       tempdata += uu;
//     }else;
//   }
  
//   sim800ds.print(JDY33_BAUD_CMD);
//   Starttime=millis();
//   while((millis() - Starttime <=400)){
//     if(sim800ds.available()){
//       char uu = sim800ds.read();
//       tempdata += uu;
//     }else;
//   }
  
//   if(tempdata.indexOf("OK") > -1){
//     Serial.println(" Finished OK " + String(_baud));
//     if(_baud != 9600){
//       Serial.println(" Reset to " + String(_baud));
//     }else;
//     while(1);
//   }else;
// }

void readBluetooth(long _baud){

  unsigned long Starttime=millis();
  String tempdata= "";
  bool stopwhile = false;

  jdy33.print(JDY33_BAUD_CMD);

  while((millis() - Starttime <=400)){
    if(jdy33.available()){
      char uu = jdy33.read();
      delay(1);
      tempdata += uu;
    }else;
  }
  
  jdy33.print(JDY33_BAUD_CMD);
  Starttime=millis();
  while((millis() - Starttime <=400)){
    if(jdy33.available()){
      char uu = jdy33.read();
      tempdata += uu;
    }else;
  }
  
  if(tempdata.indexOf("OK") > -1){
    Serial.println(" Finished OK" + String(_baud));
    if(_baud != 115200){
      Serial.println(" Reset to 115200");
      jdy33.begin(115200);
    }else;
    while(1);
  }else;
}
