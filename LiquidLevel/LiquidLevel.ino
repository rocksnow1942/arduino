#include <SoftwareSerial.h>;

const int US100_TX = 12;
const int US100_RX = 14;
 
SoftwareSerial puertoUS100(US100_RX, US100_TX);

unsigned int OneBit = 0;
unsigned int MSByteDist = 0;
unsigned int LSByteDist = 0;
unsigned int mmDist = 0;
int blank = 0;
int temp = 0;

 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  puertoUS100.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  puertoUS100.flush();  
//  do {
//    blank=puertoUS100.read();
//    } while(blank!=-1);
// 
  puertoUS100.write(0x55);  
//  delay(100);
  
  MSByteDist = puertoUS100.read();  
//  delay(500);
  LSByteDist  = puertoUS100.read();
  
  
  mmDist  = MSByteDist * 256 + LSByteDist;  
     
      Serial.print("Distancia: ");
      Serial.print(mmDist, DEC);
      Serial.println(" mm");
//
// blank = 0;
//do {
//    blank=puertoUS100.read();
//    } while(blank!=-1);
//    
//    puertoUS100.write(0x50);  
// 
//    delay(1000);
//    blank=puertoUS100.read();
//    Serial.println(blank,DEC);
    
//    temp = puertoUS100.read(); // lectura del byte
//    temp -= 45; // corrige offset de 45º
//    Serial.print("Temperatura: ");
//    Serial.print(temp, DEC);
//    Serial.println(" ºC.");
        
    delay(100);

}
