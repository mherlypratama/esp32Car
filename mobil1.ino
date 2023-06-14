#include <Blynk.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial 

#define BLYNK_TEMPLATE_ID "TMPL68_duKGx_"
#define BLYNK_TEMPLATE_NAME "mobilan"
#define BLYNK_AUTH_TOKEN "79fosR0Y_Zg3oDv4pn8IWxSOQBlIqxgW"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Redmi10";
char pass[] = "herly2233";

int forward = 0;
int backward = 0;
int left = 0;
int right = 0;
int speed;

const int EnableL = 5;
const int HighL = 4;    //Left
const int LowL = 2;

const int EnableR = 14;
const int HighR = 13;  //Right
const int LowR = 12;

// ARDUINO UNO
// const int EnableL = 5;
// const int HighL = 6;    //Left
// const int LowL = 7;

// const int EnableR = 10;
// const int HighR = 8;  //Right
// const int LowR = 9;

void setup() {
  // put your setup code here, to run once:
  Blynk.begin(auth, ssid, pass);
  Serial.begin(9600);
  pinMode(EnableL, OUTPUT);
  pinMode(HighL, OUTPUT);
  pinMode(LowL, OUTPUT);

  pinMode(EnableR, OUTPUT);
  pinMode(HighR, OUTPUT);
  pinMode(LowR, OUTPUT);

}
BLYNK_WRITE(V0){
  forward = param.asInt();
}

BLYNK_WRITE(V1){
  backward = param.asInt();
}

BLYNK_WRITE(V2){
  left = param.asInt();
}

BLYNK_WRITE(V3){
  right = param.asInt();
}

BLYNK_WRITE(V4){
  speed = param.asInt();
}

void Stop()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, 0);
  
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, 0);
}
void Forward()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL, speed);
  
  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR, speed);
}

void Backward()
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, speed);
  
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, speed);
}

void Left()
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, 0);
  
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, 255);
}

void Right()
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL, 255);
  
  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR, 0);
} 

void smartcar(){
  if(forward==1){
    Forward();
  }else if(Backward==1){
    Backward();
  }else if(left==1){
    Left();
  }else if(right==1){
    Right();
  }else if(forward==0 && backward==0 && left==0 && right==0){
    Stop();
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  // Backward();
  // delay(1000);
  // Right();
  // delay(1000);
  // Forward();
  // delay(1000);
  // Left();
  // delay(100);
  Blynk.run();
  smartcar();
}
