volatile int TOGGLE = LOW;
#include <Servo.h>
Servo rasen;
const int button01 = 12;
const int button02 = 8;
const int button03 = 9;
unsigned long time_mil;
unsigned long time_1;
int mode_flg = 0;
float count_s;
float count_s4;


void blink(void){
  if(digitalRead(2) ==LOW){
    TOGGLE=LOW;
  }else{
    TOGGLE=HIGH;
  }
}
void setup() {
  pinMode(2,INPUT_PULLUP);
  pinMode(button01,INPUT_PULLUP);
  pinMode(button02,INPUT_PULLUP);
  pinMode(button03,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),blink,CHANGE);
  Serial.begin(9600);
  rasen.attach(6);
}

void loop() {
  time_mil = millis();
  int value01;
  value01 = digitalRead(button01);
  if(value01 == LOW)
  {
    Serial.println("Start");
    delay(300);
    while(1)
    {
      char c;
      c = Serial.read();
      rasen.write(50);
      int A=0;
      A=A+analogRead(0);
      if(A<500)
      {
        time_1 = millis();
        Serial.println("HIGH");
        while(2)
        {
          int A=0;
          A=A+analogRead(0);
          if(A>500)
          {
            time_mil=millis()-time_1;
            count_s = (float)time_mil/1000;
            count_s4 = count_s * 4;
            Serial.println("LOW");
            //Serial.println(count_s);
            break;
          }
        }
      }
      int value01;
      value01 = digitalRead(button01);
      if(value01 == LOW)
      {
        rasen.write(1);
        Serial.println("button01_HIGH");
        delay(300);
      }
      int value02;
      value02 = digitalRead(button02);
      if(value02 == LOW)
      {
        rasen.write(1);
        Serial.println("button02_HIGH");
        delay(300);
      }
      int value03;
      value03 = digitalRead(button03);
      if(value03 == LOW)
      {
        rasen.write(1);
        Serial.println("button03_HIGH");
        delay(300);
      }
      Serial.println(count_s4);
    }
  }
}
  
