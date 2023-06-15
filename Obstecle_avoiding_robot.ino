#include<Servo.h>
Servo myservo; //creating servo object
const int servo=2; //define servo pin
int pos; //variable for position
const int trigger=4,echo=5; //trigger and echo pin
const int rightfor=10,rightback=11,leftfor=6,leftback=9;
float distance;
int angle;
void setup()
{
  Serial.begin(9600);
  myservo.attach(servo);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(rightfor,OUTPUT);
  pinMode(rightback,OUTPUT);
  pinMode(leftfor,OUTPUT);
  pinMode(leftback,OUTPUT);
}
void loop()
{
  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  int time=pulseIn(echo,HIGH);
  float distance=(time*0.034)/2;
  if(distance<20){
    angle=find(distance);
    Serial.print("angle:-------- ");
    Serial.println(angle);
  }
  else if(){
    run(angle);
  }
  
}
 int find(float distance){
  	while(distance<20){
      //for stop the motor
      digitalWrite(rightfor,0);
  	  digitalWrite(rightback,0);
      digitalWrite(leftfor,0);
  	  digitalWrite(leftback,0);
      //--------------------//
      digitalWrite(trigger,HIGH);
      delay(10);
      digitalWrite(trigger,LOW);
      int time=pulseIn(echo,HIGH);
      float distance=(time*0.034)/2;
      Serial.println(distance);
      if(distance<40){
        for(pos=0;pos<=180;pos++){
          Serial.print("pos1: ");
          Serial.println(pos);
          digitalWrite(trigger,HIGH);
          delay(10);
          digitalWrite(trigger,LOW);
          int time=pulseIn(echo,HIGH);
          float distance=(time*0.034)/2;
          if(distance>20){return pos;}
          else if(distance<10){
    		    digitalWrite(rightback,1);
    		    digitalWrite(leftback,1);
            digitalWrite(rightfor,0);
    		    digitalWrite(leftfor,0);
  			}
          else{
          	myservo.write(pos);
          	delay(10);
          }
        }
        for(pos=180;pos>=0;pos--){
          Serial.print("pos2: ");
          Serial.println(pos);
          digitalWrite(trigger,HIGH);
          delay(10);
          digitalWrite(trigger,LOW);
          int time=pulseIn(echo,HIGH);
          float distance=(time*0.034)/2;
          if(distance>20){return pos;}
          else if(distance<10){
    		    digitalWrite(rightback,1);
    		    digitalWrite(leftback,1);
            digitalWrite(rightfor,0);
    		    digitalWrite(leftfor,0);
  			}
          else{
          	myservo.write(pos);
          	delay(10);
          }
        }
      }
      else{Serial.println("servo OFF");}
      if(distance>20){break;}
    }
  }

void run(int angle){
	
}
