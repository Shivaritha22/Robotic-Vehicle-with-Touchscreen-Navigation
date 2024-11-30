#define trigPin 12

#define echoPin 11

#define buzz 4
#include <SoftwareSerial.h>
SoftwareSerial blue(0, 1);
char Incoming_value = 0;
long duration, distance;
char t;
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;


void setup()
{
  // set all the motor control pins to outputs
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzz, OUTPUT);
}

void forwardMove()
{

  //forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

}

void reverseMove()
{ 

  //reverse
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);

}

void leftMove()
{ 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);

}

void rightMove()
{ 

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

void stopp()
{ 

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void objectDetected()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  delay(1000);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);

}

void loop() {
  

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if(distance < 5 )

{ digitalWrite(buzz,HIGH);


objectDetected();

}
else{digitalWrite(buzz,LOW);}
Serial.print(distance);

Serial.println(" cm");

  if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("/n");
    if (Incoming_value == 'F')
    {
      forwardMove();
    }
    else if (Incoming_value == 'B')
    {
      reverseMove();
    }
    else if (Incoming_value == 'R')
    {
      rightMove();
    }
    else if (Incoming_value == 'L')
    {
      leftMove();
    }
    else if (Incoming_value == 'S')
    {
      stopp();
    }
  }

}
