
#include <Servo.h>

Servo servo;

int ldr0;
int ldr1;

void setup(){
  Serial. begin(9600);
  
  servo.attach(9);
  //servo.write(90);
  pinMode(A0, INPUT);
   pinMode(A1, INPUT);
   delay(1000);
} 
void loop(){

 
 ldr0=analogRead(A0);
 ldr1=analogRead(A1);
 
 Serial.print(ldr0);
 Serial.print("-");
 Serial.println(ldr1);

 while((ldr1-ldr0)>10){
   ldr0=analogRead(A0);
 ldr1=analogRead(A1);
    servo.write(servo.read()-1);
    delay(50);
  }
   while((ldr1-ldr0)<-10){
   ldr0=analogRead(A0);
 ldr1=analogRead(A1);
    servo.write(servo.read()+1);
    delay(50);
  }

}
