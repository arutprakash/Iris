//ANIMATRONIC EYES

//ARDUINO

#include <Servo.h>

Servo servhor;//create servo object to control a servo
Servo servver;
int trigPin1 = 5;
int echoPin1 = 6;
int trigPin2 = 2;
int echoPin2 = 3;
int trigPin3 = 8;
int echoPin3 = 9;
int trigPin4 = 12;
int echoPin4 = 13;
String inp;
String pos;

void setup()
{
  servhor.attach(11);//attachs the servo on pin 9 to servo object
  servver.attach(10);
  servhor.write(90);
  servver.write(90);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  Serial.begin(9600);

}

void loop()
{
  if (Serial.available())

  {
     
    
    digitalWrite(trigPin1, LOW);
    digitalWrite(trigPin2, LOW);
    digitalWrite(trigPin3, LOW);
    digitalWrite(trigPin4, LOW);
    long duration1, distance1, duration2, distance2,duration3,distance3,duration4,distance4;
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1 / 2) / 29.1;
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin3, LOW);
    duration3 = pulseIn(echoPin3, HIGH);
    distance3 = (duration3 / 2) / 29.1;
    digitalWrite(trigPin4, HIGH);
    delayMicroseconds(100);
    digitalWrite(trigPin4, LOW);
    duration4 = pulseIn(echoPin4, HIGH);
    distance4 = (duration4 / 2) / 29.1;
      
    

    if ((distance1 < 20))
    {
      servhor.write(0);
      Serial.print("Left  ");

    }
    else if (distance2 < 20)
    {
      servhor.write(170);
      Serial.print("Right ");

    }
    else if ((distance2 > 20) && (distance1 > 20))
    {
      servhor.write(90);
      Serial.print("Center");

    }
    
    if ((distance3 < 20))
    {
      servver.write(0);
      Serial.print("Up    ");

    }
    else if (distance4 < 20)
    {
      servver.write(170);
      Serial.print("Down  ");

    }
    else if ((distance3 > 20) && (distance4 > 20))
    {
      servver.write(90);
      Serial.print("Center");

    }
  }
}


/*
PYTHON

import serial 
from time import sleep 

arduino = serial.Serial('/dev/ttyACM0', 9600) # object creation
sleep(1.55)
while True: 
arduino.write(b" ") 
# write position to serial port
horpos = str(arduino.read(6)) 
# read serial port for arduino echo
verpos = str(arduino.read(6))
print(horpos,",",verpos) # print arduino echo to console
*/
