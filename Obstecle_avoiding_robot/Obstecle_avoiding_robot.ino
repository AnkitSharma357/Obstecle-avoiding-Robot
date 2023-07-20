#include<Servo.h>
Servo myservo; //creating servo object
const int servo=9; //define servo pin
int trigger=4,echo=7;
int In1=11,In2=6,In3=5,In4=3;
void setup()
{
  myservo.attach(servo);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(In1,OUTPUT);
  pinMode(In2,OUTPUT);
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);

}
void loop()
{
  if(distance()<30){
    find_way();
  }
  else{
    myservo.write(61);
    motor_forward();
  }
  
}

int distance(){
  int time;
  float dist;

  digitalWrite(trigger,HIGH);
  delay(10);
  digitalWrite(trigger,LOW);
  time=pulseIn(echo,HIGH);
  dist=(time*0.034)/2;
  while(dist<=10)
  {
    digitalWrite(trigger,HIGH);
    delay(10);
    digitalWrite(trigger,LOW);
    time=pulseIn(echo,HIGH);
    dist=(time*0.034)/2;
    analogWrite(In2,225);
    analogWrite(In4,225);
    delay(500);
  }

  return(dist);
}

void motor(int b)
{
  while(distance()>10){
    if(b>=0 && b<=10){
      analogWrite(In1,0);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=11 && b<=20){
      // myservo.write(61);
      analogWrite(In1,95);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=21 && b<30){
      // myservo.write(61);
      analogWrite(In1,90);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=31 && b<=40){
      // myservo.write(61);
      analogWrite(In1,100);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=41 && b<=50){
      // myservo.write(61);
      analogWrite(In1,105);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=51 && b<=60){
      // myservo.write(61);
      analogWrite(In1,110);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=61 && b<=70){
      motor_forward();
      delay(500);
      break;
    }
    else if(b>=71 && b<=80){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=81 && b<=90){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,120);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=91 && b<=100){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,115);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=101 && b<=110){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,110);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=111 && b<=120){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,100);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=121 && b<=130){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,90);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else if(b>=131 && b<=147){
      // myservo.write(61);
      analogWrite(In1,225);
      analogWrite(In3,0);
      analogWrite(In2,0);
      analogWrite(In4,0);
      delay(500);
      break;
    }
    else{
      // myservo.write(61);
      analogWrite(In3,0);
      analogWrite(In4,0);
      analogWrite(In1,0);
      analogWrite(In2,0);
    } 
    break;
  }
}

void motor_stop()
{
  analogWrite(In3,0);
  analogWrite(In4,0);
  analogWrite(In1,0);
  analogWrite(In2,0);
}

void motor_forward()
{
      analogWrite(In1,225);
      analogWrite(In3,225);
      analogWrite(In2,0);
      analogWrite(In4,0);
}


int find_way()

{
  if(distance()<30){
    for(int i=0;i<=145;i++){
      if(distance()>30){
        motor(i);
        break;
      }
      else if(i==14){
        find();
        break;
      }
      else{
        motor_stop();
        myservo.write(i);
        delay(3);
      }
      
    }

  }
  else{
    motor_forward();
  }
}

void find()

{
  if(distance()<30){
    for(int j=145;j>=0;j--)
    {
      if(distance()>30){
        motor(j);
        break;
      }
      else if(j==0){
        find_way();
        break;
      }
      else{
        motor_stop();
        myservo.write(j);
        delay(3);
      }
    }
  }
  else{
    motor_forward();
  }
}

