#include <Servo.h>
Servo s1;
Servo s2;
Servo s3;
String readSerial;
int value_servo;
String name_servo;
void setup() {
  // put your setup code here, to run once:
  s1.attach(3);
  s3.attach(5);
  s2.attach(6);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // start at 45
//  s1.write(45);
//  s3.write(90);
  if(Serial.available() > 0){
    readSerial = Serial.readString();
    Serial.println(readSerial);
    readSerial.trim();
    int index = readSerial.lastIndexOf(',');
    int length = readSerial.length();
    name_servo = readSerial.substring(0,index);
    String s_val = readSerial.substring(index,length);
    int index2 = s_val.lastIndexOf(',');
    s_val = s_val.substring(index-1,s_val.length());
    value_servo = s_val.toInt();
    Serial.println(s_val);
    if(name_servo.equals("s1")){
      Serial.println("Servo 1");
      s1.write(value_servo);
      Serial.println(value_servo);
    }
    if(name_servo.equals("s2")){
      Serial.println("Servo 2");
      s3.write(value_servo);
      Serial.println(value_servo);
    }
  }
}