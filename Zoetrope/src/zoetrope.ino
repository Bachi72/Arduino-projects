const int onPin=5;
const int directionPin=4;
const int enablePin=9;
const int controlPin1=2;
const int controlPin2=3;
const int motorSpeed=A0;

int previousOnPin=0;
int previousDirectionPin=0;

int motorDirection=1;
int motorenable=0;


void setup()
{
  pinMode(onPin,INPUT);
  pinMode(motorSpeed,INPUT);
  pinMode(enablePin,OUTPUT); 
  pinMode(controlPin1,OUTPUT);
  pinMode(controlPin2,OUTPUT); 
  
}

void loop()
{
  int motor=digitalRead(onPin);
  delay(1);
  int motorDirectionState=digitalRead(directionPin);
  delay(1);
  int Speed=analogRead(motorSpeed)/4;
  
  if(motor != previousOnPin)
  { 
    if(motor==HIGH)
    {
      motorenable= !motorenable;
    }
  }
  
  if(motorDirectionState != previousDirectionPin)
  {
    if(motorDirectionState==HIGH)
    {
      motorDirection = !motorDirection;
    }
  }
  
  if(motorDirection==1)
  {
    digitalWrite(controlPin1,HIGH);
    digitalWrite(controlPin2,LOW);
  }
  else
  {
    digitalWrite(controlPin1,LOW);
    digitalWrite(controlPin2,HIGH);
  }
  
  if(motorenable==1)
  {
    analogWrite(enablePin,Speed);
  }
  else
  {
    analogWrite(enablePin,0);
  }
  previousDirectionPin=motorDirectionState;
  previousOnPin=motor;
}
