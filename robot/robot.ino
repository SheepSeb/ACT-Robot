#include <Servo.h>
struct Leg
{
  /* data */
  Servo high;
  Servo low;
  Servo mid;
};

Leg legL1,legL2;
Leg legR1,legR2;

String readSerial;
void move_forword(leg, ){ 
  
}

void setup() {
  // put your setup code here, to run once:

  // LEG LEFT 1 ATTACHMENT
  legL1.low.attach(3);
  legL1.mid.attach(4);
  legL1.high.attach(5);

  legL1.low.write(45);
  legL1.mid.write(45);
  legL1.high.write(45);

  // LEG LEFT 2 ATTACHMENT
  legL2.mid.attach(6);
  legL2.low.attach(7);
  legL2.high.attach(8);

  legL2.low.write(45);
  legL2.mid.write(45);
  legL2.high.write(45);

  // LEG Right 1 ATTACHMENT
  legR1.low.attach(9);
  legR1.mid.attach(10);
  legR1.high.attach(11);

  legR1.low.write(45);
  legR1.mid.write(45);
  legR1.high.write(45);

  // LEG Right 2 ATTACHMENT
  legR2.low.attach(12);
  legR2.mid.attach(13);
  legR2.high.attach(14);

  legR2.low.write(45);
  legR2.mid.write(45);
  legR2.high.write(45);

  Serial.begin(115200);
}

void loop() {
//  put your main code here, to run repeatedly:
//  start at 45
//  s1.write(45);
//  s3.write(90);
  if(Serial.available() > 0){
    readSerial = Serial.readString(); // send data only when you receive data:
    Serial.println(readSerial);
    readSerial.trim(); //taie enter-ul
    int index = readSerial.lastIndexOf(',');
    int length = readSerial.length();
    name_servo = readSerial.substring(0,index);
    String s_val = readSerial.substring(index,length);
    int index2 = s_val.lastIndexOf(',');
    s_val = s_val.substring(index-1,s_val.length());
    value_servo = s_val.toInt();
    Serial.println(s_val);
    
    switch(name_servo) {
      case "s1":
        Serial.println("Servo 1"); 
        s1.write(value_servo);
        Serial.println(value_servo);
        break;
        
      case "s2":
        Serial.println("Servo 2");
        s3.write(value_servo);
        Serial.println(value_servo);
        break;
    }
    
//    if(name_servo.equals("s1")){ //switch
//      Serial.println("Servo 1"); 
//      s1.write(value_servo);
//      Serial.println(value_servo);
//    }
//    if(name_servo.equals("s2")){
//      Serial.println("Servo 2");
//      s3.write(value_servo);
//      Serial.println(value_servo);
//    }
    
  }
}
