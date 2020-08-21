#include <Servo.h>
#define trigPin 7
#define echoPin 6
#define ledpin1 9
#define ledpin2 10
#define piezoPin 11

Servo servo;
int sound = 250;
void setup() {
	Serial.begin (9600);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
	servo.attach(8);
	pinMode(ledpin1 , OUTPUT);
  	pinMode(ledpin2 , OUTPUT);
	}

void loop() {
	long duration, distance;
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration/2) / 29.1;
	if (distance < 40) {
        digitalWrite(ledpin1, HIGH);
      	digitalWrite(ledpin2, HIGH);
        tone(11, 523, 1);
      	servo.write(0);
       	delay(1);
      	tone(11, 523, 333);
        servo.write(53);
        delay(333);
      	tone(11, 659, 333);
        servo.write(106);
        delay(333);
      	tone(11, 784, 333);
        servo.write(159);
		delay(666);
      	tone(11, 784, 333);
		servo.write(106);
		delay(333);
        tone(11, 659, 333);
		servo.write(53);
		delay(333);
      	tone(11, 523, 333);
		servo.write(0);
		delay(666);
		}
  
	else {
		servo.write(0);
		digitalWrite(ledpin1, LOW);
      	digitalWrite(ledpin2, LOW);
		}
  
	if (distance > 60 || distance <= 0){
		Serial.println("The distance is more than 60");
	}
  
	else {
		Serial.print(distance);
		Serial.println(" cm");
		}
}