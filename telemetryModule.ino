#include <SoftwareSerial.h>

/////////////////////////////
/* Definicion de pines */
int loraRX = 6; // Declarar el pin de Recibo de datos LORA
int loraTX = 7; // Declarar el pin de Envio de datos LORA
int gpsRX = 8; // Declarar el pin de Recibo de datos GPS
int gpsTX = 9; // Declarar el pin de Envio de datos GPS
int dpTS1 = ; // Data Pin Temperature Sensor 1 
int dpTS2 = ; // Data Pin Temperature Sensor 2
int dpTS3 = ; // Data Pin Temperature Sensor 3
/////////////////////////////

/////////////////////////////
/* Variables publicas */
int rpmVal, ts1, ts2, ts3;
String latlonGPS, fPacket;
/////////////////////////////

/////////////////////////////
/* Definicion de funciones */
SoftwareSerial lora(loraRX, loraTX);
int getRPM();
float getTS1();
float getTS2();
float getTS3();
String getNMEA();
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
  
}

void loop() { // Superbucle
  
  /*
    - Paquete de ejemplo  (Max packet size: 39 bytes)
    RPM, tempSensor1, tempSensor2, tempSensor3, Latitud, Longitud
    2500,149,178,165,25.2525252,31.31313113
    
    - Patron de eventos:
      1. Recibir los datos con getRPM
      2. Recibir los datos de los 3 sensores de temperatura
      3. Recibir el string del getNMEA
  */
  
  // Crea el paquete unto de datos a enviar
  fPacket = String(getRPM()) + String(getTS1()) + String(getTS2()) + String(getTS3()) + getNMEA();

  // Envia el paquete a funciones de envio
  uploadLoRa(fPacket);
  uploadMEM(fPacket);
  
  //Texto de ejemplo:
  if(Serial.available()){
    gpstest.println(Serial.read());
  }
  if(gpstest.available()){
    Serial.println(gpstest.read());
  } 
}

int getRPM(){ // Funcion para extraer mediante <Metodo aun no definido> las revoluciones del vehiculo

  return rpmVal; //Devolviendo variable con nombre generico
}

float getTS1(){ // Funcion para extraer el valor del sensor de temperatura 1

  return ts1; //Devolviendo variable con nombre generico
}

float getTS2(){ // Funcion para extraer el valor del sensor de temperatura 2

  return ts2; //Devolviendo variable con nombre generico
}

float getTS3(){ // Funcion para extraer el valor del sensor de temperatura 3

  return ts3; //Devolviendo variable con nombre generico
}

String getNMEA(){ // Funcion para extraer los datos NMEA que necesitamos del GPS

  return latlonGPS; //Devolviendo variable con nombre generico
}

void uploadLoRa(String fPL){  // Funcion para publicar al modulo de radio a travez de Serial simulado el paquete final
  // lora.println(fPL);
}

void uploadMEM(String fPM){ // Funcion para publicar al modulo de almacenamiento local
  /*  
    Probablemente sea buena idea, manejar los datos en BSON/JSON para que los datos guardados sean exportables a la base de datos
  */
}