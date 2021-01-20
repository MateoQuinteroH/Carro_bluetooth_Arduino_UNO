#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT(12,13);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
void setup()
{
  BT.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  Serial.begin(9600);   // Inicializamos  el puerto serie  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}
 
void loop()
{
  char comando;
  if(BT.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    //Serial.write(BT.read());
    //Serial.println(char(BT.read()));
    comando = char(BT.read());
      /* Movimiento adelante */
  if(comando == 'A')
  {
    Serial.println("El carro se mueve adelante");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  /* Movimiento atrás */
  if(comando == 'B')
  {
    Serial.println("El carro se mueve atrás");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  /* Movimiento a la derecha */
  if(comando == 'C')
  {
    Serial.println("El carro se mueve a la derecha");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  /* Movimiento a la izquierda */
  if(comando == 'D')
  {
    Serial.println("El carro se mueve a la izquierda");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  /* Detener el movimiento */
  if(comando == 'E')
  {
    Serial.println("El carro se detuvo.");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  }



  
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT.write(Serial.read());
  }
}
