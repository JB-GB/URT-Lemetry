#include <SoftwareSerial.h>

/////////////////////////////
/* Definicion de pines */
int loraRX = 6; // Declarar el pin de Recibo de datos LORA
int loraTX = 7; // Declarar el pin de Envio de datos LORA
int tachPin = ; //  Declara el pin de datos del sensor inductivo anclado a la flecha
int accel1 = ; // Data Pin accelerometer Sensor 1 (Check I2C)
int accel2 = ; // Data Pin accelerometer Sensor 2 (Check I2C)
int accel3 = ; // Data Pin accelerometer Sensor 3 (Check I2C)
int accel4 = ; // Data Pin accelerometer Sensor 4 (Check I2C)
int engTemp = ; // Data pin engine temperature sensor
int brkTemp = ; // Data pin brakes temperature sensor
/////////////////////////////

/////////////////////////////
/* Variables publicas */
int rpmVal,;
String latlonGPS, fPacket;
/////////////////////////////

/////////////////////////////
/* Definicion de funciones */
SoftwareSerial lora(loraRX, loraTX);
void uploadLoRa(String fPL);
void uploadMEM(String fPM);
/////////////////////////////

void setup() {  // Inicializacion del dispositivo
  Serial.begin(9600);
  while(!Serial){
    ;
  }
  Serial.println("Serial de la computadora iniciado");

  lora.begin(9600); // Necesitamos verificar el data rate sea de 115200 baudios
  while(!lora){
    ;
  }
  Serial.println("Serial de software iniciado");
  
  // Configurar el sim808 con AT+CGNSSEQ=RMC (TIME,DATE,POSITION,COURSE,SPEED)
}

void loop() { // Superbucle
  
  /*
    - Paquete de ejemplo  
    RPM, accel1, accel2, accel3, accel4, engTemp, brkTemp;
    2500,149,178,165,25.2525252,31.31313113
    
    - Patron de eventos:
      1. Recibir los datos con getRPM
      2. Recibir los datos de los 3 sensores de temperatura
      3. Recibir el string del getNMEA
  */
  
  // Crea el paquete unto de datos a enviar
  fPacket = String(); // 

  // Envia el paquete a funciones de envio
  uploadLoRa(fPacket);  // Sendin LoRa packets | Envío a LoRa
  uploadMEM(fPacket);   // Local memory data upload | Almacenado local de información
}


void uploadLoRa(String fPL){  // Funcion para publicar al modulo de radio a travez de Serial simulado el paquete final
  // lora.println(fPL);
}

void uploadMEM(String fPM){ // Funcion para publicar al modulo de almacenamiento local
  /*  
    Probablemente sea buena idea, manejar los datos en BSON/JSON para que los datos guardados sean exportables a la base de datos
  */
}