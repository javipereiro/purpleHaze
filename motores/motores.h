/* motorsUp para iniciar los motores facilmente */
void motorsUp(){
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel B pin
}
/* motorR recibe un double, positivo o negativo para ir hacia delante o hacia atrás.
Si recibe 0 activa el freno, si recibe 0.1 se queda en pto muerto */

void motorR(double a){
  double b;
  if(a==0){
    digitalWrite(9, HIGH); // Activa el freno
  }
  if(a==0.1){
    digitalWrite(9, LOW); // Desactiva el freno
    analogWrite(3, 0);
  }
  else if(a<0){
    if(a<-100){
      a=-100;
    }
    b=255*(-a/100);
    digitalWrite(9, LOW); // Desactiva el freno
    digitalWrite(12, LOW); // Marcha atras
    analogWrite(3, b);   //Spins the motor on Channel A at full speed
  }
  else if(a>0){
    if(a>100){
      a=100;
    }
      b=255*(a/100);
      digitalWrite(9, LOW);  // Desactiva el freno 
      digitalWrite(12, HIGH); // Marcha adelante
      analogWrite(3,b);   //Spins the motor on Channel A at full speed
    }

  }
/* motorL hace lo mismo que motorR.
  La constatne c sirve para calibrar el motor*/
void motorL(double a){
  double b;
  const double c=0.75;
  if(a==0){
    digitalWrite(8, HIGH); // Activa el freno
  }
  if(a==0.1){
    digitalWrite(8, LOW); // Desactiva el freno
    analogWrite(11, 0);
  }
  else if(a<0){
    if(a<-100){
      a=-100;
    }
    b=255*(-a*c/100);
    digitalWrite(8, LOW); // Desactiva el freno
    digitalWrite(13, LOW); // Marcha atras
    analogWrite(11, b);   //Spins the motor on Channel A at full speed
  }
  else if(a>0){
    if(a>100){
      a=100;
    }
    b=255*(a*c/100);
    digitalWrite(8, LOW);  // Desactiva el freno 
    digitalWrite(13, HIGH); // Marcha adelante
    analogWrite(11, b);   //Spins the motor on Channel A at full speed
  }
}