// IE3027: Electrónica Digital 2 - 2021
// Proyecto 2
// María Andrea López
// Enma López

//***************************************************************
// Librerias
//***************************************************************
#include <stdint.h>
#include <stdbool.h>

//***************************************************************
// Prototipos de funciones
//***************************************************************
void emergencia(void);

//***************************************************************
// Variables
//***************************************************************
const int player1_button1 = 4;
const int player1_button3 = 5;
const int player1_button2 = 6;

const int player2_button1 = 8;
const int player2_button2 = 9;
const int player2_button3 = 10;

int estado_boton1 = 0;
int estado_boton2 = 0;
int estado_boton3 = 0;
int estado_boton4 = 0;
int estado_boton5 = 0;
int estado_boton6 = 0;

int bandera0 = 0;
int bandera1 = 0;
int bandera2 = 0;
int bandera3 = 0;
int bandera4 = 0;
int bandera5 = 0;
int bandera6 = 0;

int inByte;
int instruccion;
int bloqueo = 0;
int bloqueoBotones1 = 0;
int bloqueoBotones2 = 0;

//***************************************************************
// Setup
//***************************************************************
void setup() {
  Serial.begin(9600);
  
  pinMode(player1_button1, INPUT);
  pinMode(player1_button2, INPUT);
  pinMode(player1_button3, INPUT);
  
  pinMode(player2_button1, INPUT);
  pinMode(player2_button2, INPUT);
  pinMode(player2_button3, INPUT);
}

//***************************************************************
// Loop
//***************************************************************
void loop() 
{ 
//************** Lectura de boones *****************    
  estado_boton1 = digitalRead(player1_button1);
  estado_boton2 = digitalRead(player1_button2);
  estado_boton3 = digitalRead(player1_button3);
  estado_boton4 = digitalRead(player2_button1);
  estado_boton5 = digitalRead(player2_button2);
  estado_boton6 = digitalRead(player2_button3);

//******************** Jugador 1 ***********************
  emergencia(); 

  if (bloqueo == 0){
    if(estado_boton1 == HIGH & estado_boton2 == LOW & estado_boton3 == LOW)
    {
      bandera1 = 1;
      delay(10);
      inByte = 7;
      Serial.write(inByte);
    }
    else
    {
      if(bandera1 == 1 & estado_boton1 == LOW)
      {
        Serial.println("1");
        inByte = 1;
        Serial.write(inByte);
        
        bandera1 = 0;
      }
    }
  }

// **********************************
  emergencia();
  
  if (bloqueo == 0){
    if(estado_boton2 == HIGH & estado_boton1 == LOW & estado_boton3 == LOW)
    {
      bandera2 = 1;
      delay(10);
      inByte = 8;
      Serial.write(inByte);
    }
    else
    {
      if(bandera2 == 1 & estado_boton2 == LOW)
      {
        Serial.println("2");
        inByte = 2;
        Serial.write(inByte);
        
        bandera2 = 0;
      }
    }
  }

// **********************************
  emergencia();
  
  if (bloqueo == 0 & bloqueoBotones1 == 0){
    if(estado_boton3 == HIGH & estado_boton2 == LOW & estado_boton1 == LOW)
    {
      bandera3 = 1;
    }
    else
    {
      if(bandera3 == 1 & estado_boton3 == LOW)
      {
        Serial.println("3");
        inByte = 3;
        Serial.write(inByte);
        
        bandera3 = 0;
      }
    }
  }

  //******************** Jugador 2 ***********************
  emergencia();
  
  if (bloqueo == 0){
    if(estado_boton4 == HIGH & estado_boton5 == LOW & estado_boton6 == LOW)
    {
      bandera4 = 1;
      delay(10);
      inByte = 9;
      Serial.write(inByte);
    }
    else
    {
      if(bandera4 == 1 & estado_boton4 == LOW)
      {
        Serial.println("4");
        inByte = 4;
        Serial.write(inByte);
        
        bandera4 = 0;
      }
    }
  }

// **********************************
  emergencia();
  
  if (bloqueo == 0){
    if(estado_boton5 == HIGH & estado_boton4 == LOW & estado_boton6 == LOW)
    {
      bandera5 = 1;
      delay(10);
      inByte = 5;
      Serial.write(inByte);
    }
    else
    {
      if(bandera5 == 1 & estado_boton5 == LOW)
      {
        Serial.println("5");
        inByte = 21;
        Serial.write(inByte);
        
        bandera5 = 0;
      }
    }
  }

// **********************************  
  emergencia();
  
  if (bloqueo == 0 & bloqueoBotones2 == 0){
    if(estado_boton6 == HIGH & estado_boton4 == LOW & estado_boton5 == LOW)
    {
      bandera6 = 1;
    }
    else
    {
      if(bandera6 == 1 & estado_boton6 == LOW)
      {
        Serial.println("6");
        inByte = 6;
        Serial.write(inByte);
        
        bandera6 = 0;
      }
    }
  }

// **********************************  
  emergencia();
  if (bloqueo == 0){
    if(estado_boton1 == LOW & estado_boton2 == LOW & estado_boton3 == LOW & estado_boton4 == LOW & estado_boton5 == LOW & estado_boton6 == LOW)
    {
      bandera0 = 1;
    }
    else
    {
      if(bandera0 == 1)
      {
        Serial.println("0");
        inByte = 0;
        Serial.write(inByte);
        
        bandera0 = 0;
      }
    }
  }    
}

//***************************************************************
// Funciones
//***************************************************************
void emergencia(void) // Leer estado del juego en la tiva
{
  if (Serial.available())
  {
    instruccion = Serial.read();
  }
  if (instruccion == 5)
  {
    bloqueoBotones1 = 0;
  }
  if (instruccion == 3)
  {
    bloqueoBotones1 = 1;
  }
  if (instruccion == 4)
  {
    bloqueoBotones2 = 0;
  }
  if (instruccion == 2)
  {
    bloqueoBotones2 = 1;
  }
  if (instruccion == 1)
  {
    bloqueo = 1;
  }
  if (instruccion == 0)
  {
    bloqueo = 0;
  }
//***************************************************************************  
}
