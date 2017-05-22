#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8);
#include <Servo.h> 
 
Servo myservo;  
 
int pos = 0;   
int motor1Pin1 = 12; 
int motor1Pin2 = 13;
int enable1Pin = 11; 
int motor2Pin1 = 3;
int motor2Pin2 = 4;
int enable2Pin = 6; 
int state;
int flag=0;        
int stateStop=0;

void setup() {
    // giris cikis ayarlari
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    pinMode(3,OUTPUT);
    Serial.begin(9600);
    Serial.println("basla");
  mySerial.begin(9600);
}

void loop() {
   
    if(mySerial.available() > 0){     
      state = mySerial.read();   
      Serial.println(state);
      flag=0;
    }   

    // arac ileri hareket eder
    if (state == 70) {
       
  
      
       analogWrite(enable1Pin, 250);
       analogWrite(enable2Pin, 250);
       
       
       
      digitalWrite(motor1Pin1,  LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        
        
        if(flag == 0){
          Serial.println("ileri!");
          flag=1;
        
      
    }
    }
    


     
    
    // dur
    if (state == 83) {
       
  
      
       analogWrite(enable1Pin, 255);
       analogWrite(enable2Pin, 255);
       
       
       
      digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        
        
        if(flag == 0){
          Serial.println("DUR!");
          flag=1;
        
      
    }
    }


//geri
      if (state == 66) {
       
  
      
       analogWrite(enable1Pin, 255);
       analogWrite(enable2Pin, 255);
       
       
       
      digitalWrite(motor1Pin1,  HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        
        
        if(flag == 0){
          Serial.println("GERİ!");
          flag=1;
        
      
    }
    }



//ileri sag
      if (state == 71) {
       
  
      
       analogWrite(enable1Pin, 200);
       analogWrite(enable2Pin, 250);
       
       
       
      digitalWrite(motor1Pin1,  LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        
        
        if(flag == 0){
          Serial.println("ileri sag!");
          flag=1;
        
      
    }
    }


   //SOL
    if (state == 76) {
      //F =82
  
      
       analogWrite(enable1Pin, 255);
       analogWrite(enable2Pin, 255);
       
       
       
      digitalWrite(motor1Pin1,  LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        
        
        if(flag == 0){
          Serial.println("SAG!");
          flag=1;
        
      
    }
       
  
       
       
       
    }

     //SAG
    if (state == 82) {
       analogWrite(enable1Pin, 255);
       analogWrite(enable2Pin, 255);
       
       
       
      digitalWrite(motor1Pin1,  HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH); 
        
        if(flag == 0){
          Serial.println("SOL!");
          flag=1;
        
      
    }
    }
    
}


