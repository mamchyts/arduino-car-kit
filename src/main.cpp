#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
    myServo.attach(13);
}

void loop() {
    myServo.write(0);
    delay(3000);

    myServo.write(90);
    delay(3000);

    myServo.write(180);
    delay(3000);

    myServo.write(90);
    delay(3000);
}