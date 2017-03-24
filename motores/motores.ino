#include <Servo.h>
#include "motores.h"
#include "sharps.h"
int m,r,l;
Servo servo;
void setup(){
  motorsUp();
  Serial.begin(9600);
  servo.attach(6);
  int rd = servo.read();
  servo.write(81);}
void loop(){
  boolean actions = true;
  if (actions){//Condicion provisional para programa de prueba
  motorR(90);
  motorL(90);
  m= sharpMRead();
  if(m>150){ // Condicion para dar media vuelta
    motorsStop(); 
    delay(1000);
    motorR(90);
    motorL(-90);
    delay(1200);
  }
  r = sharpRRead();
  if(r>300){ //Para corregir un poco la trayectoria hacia la izquierda
    motorL(50);
    motorR(100);
    delay(1000);
  }
  l = sharpLRead();
  if(l>300){//Para corregir un poco la trayectoria hacia la derecha
    motorR(50);
    motorL(100);
    delay(1000);
  }
  Serial.print("M=");
  Serial.println(m);
  
  Serial.print("R=");
  Serial.println(r);
  
  Serial.print("L=");
  Serial.println(l);

  }
  else{// Condicion para lectura de cnys (en analogicos del 0 al 4)
    int aux [5];
    for(int i=0;i<5;i++){
      aux[i]=analogRead(i);
    }
    Serial.print("[");
    for(int i=0;i<5;i++){
      Serial.print(aux[i]);
      if(i!=4){
      Serial.print(",");
      }
      else{
      Serial.println("]");
      }
    }
    delay(1500);
  }
  
}

