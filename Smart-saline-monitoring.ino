#include<Servo.h>
#define BUZZER_PIN 7
#define TOUCH_PAD_PIN 3
#define REDLED_PIN 5
#define GREENLED_PIN 6
Servo servo;
void redLedBlink()
{
  digitalWrite(REDLED_PIN, HIGH);
  delay(500);
  digitalWrite(REDLED_PIN, LOW);
  delay(500);
}
void setup()
{
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TOUCH_PAD_PIN, INPUT);
  pinMode(REDLED_PIN, OUTPUT);
  pinMode(GREENLED_PIN, OUTPUT);
  servo.attach(9);
  Serial.begin(9600);
}
void loop()
{
  int touchPadStatus = digitalRead(TOUCH_PAD_PIN);
  if (touchPadStatus == 1)
  {
    Serial.println("the cyrines bottle is almost empty");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(20000);
    servo.write(180);
    delay(25);
    redLedBlink();
    break;
  }
  else if (touchPadStatus == 0)
  {
    Serial.println("the cyrine bottle is full and no need to worry");
    digitalWrite(BUZZER_PIN, LOW);
    servo.write(0);
    digitalWrite(GREENLED_PIN, HIGH);
  }
}
