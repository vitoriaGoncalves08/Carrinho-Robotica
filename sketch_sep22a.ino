/*#include <Ultrasonic.h>
Ultrasonic ultrassom(A0,A1);*/

int port2 = 2;
int port3 = 3;
int port4 = 4;
int port5 = 5;
int sensor1 = A2;
int sensor2 = A3;

long distancia = 0;

void setup() {
  Serial.begin(9600);
  pinMode(port2, OUTPUT);
  pinMode(port3, OUTPUT);
  pinMode(port4, OUTPUT);
  pinMode(port5, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  Serial.begin(9600);  
  /*digitalWrite(port2, 1);//FRENTE esquerda
  digitalWrite(port4, 1);//FRENTE direita LADO DIREITO
  digitalWrite(port3, 1);//RÉ esquerda LADO ESQUERDO
  digitalWrite(port5, 1);//RÉ direita LADO ESQUERDO*/
}

void loop() {
  /*distancia = ultrassom.Ranging(CM);
  Serial.print(distancia);
  Serial.println("CM");
  
  if(distancia <= 20){
    parar();
    delay(1500);
    re();
    delay(1000);
    virarD();
    delay(900);
  }else if (distancia > 20){
    frente();
  }*/
  
  sensor1 = analogRead(A2); 
  sensor2 = analogRead(A3);

  /*Serial.print("Direito: ");
  Serial.println(sensor1);
  Serial.print("Esquerdo: ");
  Serial.println(sensor2);
  delay(1500);*/

  if(sensor1 <= 76 && sensor2 <= 76){
    frente();
  }else if(sensor1 >= 100 && sensor2 <= 100){
    virarE();
  }else if(sensor2 >= 100 && sensor1 <= 100){
    virarD();
  }
}

void acoes(){
 frente();
 delay(4000);
 parar();
 delay(2000);
 re();
 delay(4000);
 parar();
 delay(2000);
 virarD();
 delay(900);
 parar();
 delay(2000);
 frente();
 delay(2000);
 virarE();
 delay(900);
}
void frente(){
  digitalWrite(port2, 1);
  digitalWrite(port3, 0);
  digitalWrite(port4, 1);
  digitalWrite(port5, 0);
}
void re(){
  digitalWrite(port2, 0);
  digitalWrite(port3, 1);
  digitalWrite(port4, 0);
  digitalWrite(port5, 1); 
}
void parar(){
  digitalWrite(port2, LOW);
  digitalWrite(port3, LOW);
  digitalWrite(port4, LOW);
  digitalWrite(port5, LOW); 
}
void virarD(){
  digitalWrite(port2, 1);
  digitalWrite(port3, 0);
  digitalWrite(port4, 0);
  digitalWrite(port5, 1); 
}
void virarE(){
  digitalWrite(port2, 0);
  digitalWrite(port3, 1);
  digitalWrite(port4, 1);
  digitalWrite(port5, 0); 
}





