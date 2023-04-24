#include<Servo.h>
#define in1 2
#define in2 4
#define enA 3
#define in3 7
#define in4 8
#define enB 9
#define trig 5
#define echo 6
#define buzzer 10
#define led 12
#define rainSensor A1
#define waterSpeed A2
#define waterLevel A3
Servo servo;
long duration;
long distance;

void dam_open() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
  delay(250);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}

void dam_close() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  delay(250);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}

void led_buzzer_on() {
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
  delay(200);
  digitalWrite(buzzer, HIGH);
  Serial.println("Alerting the villagers and all the higher authorities ");
  Serial.println("The level of water is: ");
}

void led_buzzer_off() {
  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);
}

void servo_write() {
  for (int pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(15);
  }
}

void ultraSonic() {
  digitalWrite(trig, LOW);
  delay(2);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration * 0.0342) / 2;
}

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(rainSensor, INPUT);
  pinMode(waterSpeed, INPUT);
  pinMode(waterLevel, INPUT);
  pinMode(led, OUTPUT);
  servo.attach(11);
  Serial.begin(115200);
}

void loop() {
  //ultrasonic controlling modules
  ultraSonic();
  
}
