
#include<L298N.h>
#include<Servo.h>
#define frontrightmotor1 8
#define frontrightmotor2 9
#define frontrightmotorenable 2
#define frontleftmotor1 10
#define frontleftmotor2 11
#define frontleftmotorenable 3
#define backrightmotor1 12
#define backrightmotor2 13
#define backrightmotorenable 4
#define backleftmotor1 21
#define backleftmotor2 22
#define backleftmotorenable 5
#define topmotor1 23
#define topmotor2 24
#define topmotorenable 6
#define stq 49 
#define q1 50
#define q2 51
#define q3 52
#define q4 53
Servo servo1;
#define echo 27
#define trig 28
long duration;
long distance;
#define redled1 48
#define redled2 47
#define greenled1 46
#define greenled2 45

void forward()
{
  digitalWrite(frontrightmotor1,HIGH);
  digitalWrite(frontrightmotor2,LOW);
  analogWrite(frontrightmotorenable,255);
  digitalWrite(frontleftmotor1,HIGH);
  digitalWrite(frontleftmotor2,LOW);
  analogWrite(frontleftmotorenable,255);
  digitalWrite(backrightmotor1,HIGH);
  digitalWrite(backrightmotor2,LOW);
  analogWrite(backrightmotorenable,255);
  digitalWrite(backleftmotor1,HIGH);
  digitalWrite(backleftmotor2,LOW);
  analogWrite(backleftmotorenable,255);
  digitalWrite(greenled1,HIGH);
  digitalWrite(greenled2,HIGH);
}
void backward()
{
 digitalWrite(frontrightmotor1,LOW);
 digitalWrite(frontrightmotor2,HIGH);
 analogWrite(frontrightmotorenable,255);
 digitalWrite(frontleftmotor1,LOW);
 digitalWrite(frontleftmotor2,HIGH);
 analogWrite(frontleftmotorenable,255);
 digitalWrite(backrightmotor1,LOW);
 digitalWrite(backrightmotor2,HIGH);
 analogWrite(backrightmotorenable,255);
 digitalWrite(backleftmotor1,LOW);
 digitalWrite(backleftmotor2,HIGH);
 analogWrite(backleftmotorenable,255);
 digitalWrite(redled1,HIGH);
 digitalWrite(redled2,HIGH);
}
void right()
{
 digitalWrite(frontrightmotor1,LOW);
 digitalWrite(frontrightmotor2,HIGH);
 analogWrite(frontrightmotorenable,175);
 digitalWrite(frontleftmotor1,HIGH);
 digitalWrite(frontleftmotor2,LOW);
 analogWrite(frontleftmotorenable,255);
 digitalWrite(backrightmotor1,LOW);
 digitalWrite(backrightmotor2,HIGH);
 analogWrite(backrightmotorenable,175);
 digitalWrite(backleftmotor1,HIGH);
 digitalWrite(backleftmotor2,LOW);
 analogWrite(backleftmotorenable,255);
 digitalWrite(greenled1,HIGH);
 digitalWrite(redled2,HIGH);
 delay(1000);
}
void left()
{
 digitalWrite(frontrightmotor1,HIGH);
 digitalWrite(frontrightmotor2,LOW);
 analogWrite(frontrightmotorenable,255); 
 digitalWrite(frontleftmotor1,LOW);
 digitalWrite(frontleftmotor2,HIGH);
 analogWrite(frontleftmotorenable,175);
 digitalWrite(backrightmotor1,HIGH);
 digitalWrite(backrightmotor2,LOW);
 analogWrite(backrightmotorenable,255);
 digitalWrite(backleftmotor1,LOW);
 digitalWrite(backleftmotor2,HIGH);
 analogWrite(backleftmotorenable,175);
 digitalWrite(greenled2,HIGH);
 digitalWrite(redled1,HIGH);
 delay(1000);
}
void stop()
{
 digitalWrite(frontrightmotor1,LOW);
 digitalWrite(frontrightmotor2,LOW);
 analogWrite(frontrightmotorenable,50); 
 digitalWrite(frontleftmotor1,LOW);
 digitalWrite(frontleftmotor2,LOW);
 analogWrite(frontleftmotorenable,50);
 digitalWrite(backrightmotor1,LOW);
 digitalWrite(backrightmotor2,LOW);
 analogWrite(backrightmotorenable,50);
 digitalWrite(backleftmotor1,LOW);
 digitalWrite(backleftmotor2,LOW);
 analogWrite(backleftmotorenable,50);
 digitalWrite(redled1,HIGH);
 digitalWrite(redled2,HIGH);
 delay(1000);
}
void clockwise()
{
 digitalWrite(topmotor1,HIGH);
 digitalWrite(topmotor2,LOW);
 analogWrite(topmotorenable,200);
 delay(500);
}
void counterclockwise()
{
  digitalWrite(topmotor1,LOW);
  digitalWrite(topmotor2,HIGH);
  analogWrite(topmotorenable,200);
  delay(500);
}
void wait()
{
  digitalWrite(topmotor1,LOW);
  digitalWrite(topmotor2,LOW);
  analogWrite(topmotorenable,50);
  delay(500);
}

 void setup()  
{
 pinMode(frontrightmotor1,OUTPUT);
 pinMode(frontrightmotor2,OUTPUT);
 pinMode(frontrightmotorenable,OUTPUT);
 pinMode(frontleftmotor1,OUTPUT);
 pinMode(frontleftmotor2,OUTPUT);
 pinMode(frontleftmotorenable,OUTPUT);
 pinMode(backrightmotor1,OUTPUT);
 pinMode(backrightmotor2,OUTPUT);
 pinMode(backrightmotorenable,OUTPUT);
 pinMode(backleftmotor1,OUTPUT);
 pinMode(backleftmotor2,OUTPUT);
 pinMode(backleftmotorenable,OUTPUT);
 pinMode(topmotor1,OUTPUT);
 pinMode(topmotor2,OUTPUT);
 pinMode(topmotorenable,OUTPUT);
 pinMode(stq,INPUT);
 pinMode(q1,INPUT);
 pinMode(q2,INPUT);
 pinMode(q3,INPUT);
 pinMode(q4,INPUT);
 Serial.begin(9600);
 servo1.attach(7);
 pinMode(redled1,OUTPUT);
 pinMode(redled2,OUTPUT);
 pinMode(greenled1,OUTPUT);
 pinMode(greenled2,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(trig,OUTPUT);
 
}

void loop()
 {
    int D1=digitalRead(q1);
    int D2=digitalRead(q2);
    int D3=digitalRead(q3);
    int D4=digitalRead(q4);
    if(D1==LOW && D2==HIGH && D3==LOW && D4==LOW)
    forward();
    else if(D1==LOW && D2==LOW && D3==LOW && D4==HIGH)
    backward();
    else if(D1==LOW && D2==HIGH && D3==HIGH && D4==LOW)
    right();
    else if(D1==LOW && D2==LOW && D3==HIGH && D4==LOW)
    left();
    else if(D1==HIGH && D2==LOW && D3==HIGH && D4==LOW)
    stop();
    else if(D1==HIGH && D2==LOW && D3==LOW && D4==LOW)
    counterclockwise();
    else if(D1==HIGH && D2==HIGH && D3==LOW && D4==LOW)
    clockwise();
     else if(D1==LOW && D2==LOW && D3==LOW && D4==LOW)
     wait();
 }
void ultra(){
 
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
}
{
  ultra();
  servo1.write(0);
  if(distance <= 10)
  {
    servo1.write(180);
    delay(15);
  }
}
}
 
