#include <Servo.h>
#define OPEN 160
#define CLOSED 37
int clawState = 1;
int echoPin = 7;
int trigPin = 6;

Servo servo1;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(9);
pinMode(echoPin, INPUT);
pinMode(trigPin, OUTPUT);
servo1.write(OPEN);

}

double pingDistance(){
   float pulse;
  float distance;
    digitalWrite(trigPin, LOW);
    delay(20);
    digitalWrite(trigPin, HIGH);
    delay(20);
    digitalWrite(trigPin, LOW);
  pulse = pulseIn(echoPin, HIGH);
  distance = pulse/29.387/2;
    Serial.println(distance);
    return distance;
  }



void clawGrab(int clawState){
 if (clawState == 1) {
    if(pingDistance() <= 15.00){
      delay(1200);
      servo1.write(CLOSED);
       Serial.println("closed");
       delay(3000);
      while (pingDistance() <= 20.00){
         Serial.println("delay");
       
        }

      }
    }

    
  }

void clawRelease(int clawState) {
  if (clawState == 0){
         if(pingDistance() <= 15.00){
      delay(1200);
      servo1.write(OPEN);
       Serial.println("open");
         delay(3000);
      while (pingDistance() <= 20.00){
         Serial.println("delay");
        pingDistance();
        } 
   
      }
  }

  
}




void loop() {

//claw open/close control

if (clawState == 1){

  clawGrab(clawState);

  if(servo1.read() != OPEN){
    clawState--;
  }
   Serial.println(clawState);
  // delay(1000);
  }
  
if (clawState == 0) {

clawRelease(clawState);
 if(servo1.read() != CLOSED){
    clawState++;
    }
 Serial.println(clawState);
// delay(1000);
  }


  delay(20);

}
