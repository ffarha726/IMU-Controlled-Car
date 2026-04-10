

#include<nRF24L01.h>
#include<RF24.h>
#include<SPI.h>
RF24 radio(7, 8); // CE, CSN any digital pins 
const byte address[6] = "00001";
struct Data_Package {
  int xAxis; // right and left
  int yAxis; // forward and backward
};
Data_Package myData;
void setup()

{

  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
   radio.setPALevel(RF24_PA_MIN);
   radio.stopListening();
}

void loop() 

{
  int X  ;
  int Y  ;
  myData.xAxis = X;
  myData.yAxis = Y;
  radio.stopListening(); 
  radio.write(&myData, sizeof(Data_Package)); 
  
  delay(50);
}

