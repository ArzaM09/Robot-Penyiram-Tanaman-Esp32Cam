int in1 = 2;
int in2 = 4;
int in3 = 7;
int in4 = 8;
int relay = 11;
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  Serial.begin(115200);  // Inisialisasi koneksi serial ke ESP32
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(relay, OUTPUT);
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  servo5.attach(10);
  servo1.write(0);
  servo2.write(0);
  servo3.write(120);
}

void loop() {
  if (Serial.available() > 0) {
    int receivedChar = Serial.read();  // Membaca karakter dari ESP32
    Serial.println(receivedChar);
    if (receivedChar == 1){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    else if (receivedChar == 2){
      Serial.println("nahhhhh");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    else if (receivedChar == 0){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
      digitalWrite(relay, LOW);
      servo1.write(0);
      servo2.write(0);
      servo3.write(180);
      servo4.write(90);
      servo5.write(120);
    }
    else if (receivedChar == 3){
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, HIGH);
    }
      else if (receivedChar == 4){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
      else if (receivedChar == 5){
      digitalWrite(relay, HIGH);
    }
      else if (receivedChar == 90){
      servo1.write(90);
    }
      else if (receivedChar == 180){
      servo1.write(180);
    }
      else if (receivedChar == 100){  
      servo2.write(90);
    }
      else if (receivedChar == 190){  
      servo4.write(180);
     }
      else if (receivedChar == 110){  
      servo5.write(180);
     }
}
}