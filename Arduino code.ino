#include <Servo.h>
#define trigPin 7
#define echoPin 6
#define ledpin1 9
#define ledpin2 10

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
		servo.write(160);
        digitalWrite(ledpin1, HIGH);
      	digitalWrite(ledpin2, HIGH);
		delay(1500);
		servo.write(20);
		delay(1000);
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
  
	delay(500);
}