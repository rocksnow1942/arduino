
const int pwmPin = 0;


void setup() {
  // setup pwm pin
  pinMode(pwmPin, OUTPUT);
  analogWriteFreq(100);
  
  

  // serial 
  Serial.begin(115200);
  Serial.print("Hello\n");
}

void pwmDuty(unsigned int duty) {
    analogWrite(pwmPin, duty);
  }

void loop() {
  // put your main code here, to run repeatedly:
  static int direction = 200;
  static int duty = 1;
  if (duty>=1224 || duty<=0) {
      direction = -direction;
      
    };

     duty += direction;
     pwmDuty(duty);
     Serial.print("Current duty: ");
     Serial.println(duty);
  
   delay(2000);
}
