#include <SoftwareSerial.h>

/////////////////////////////
/* Definicion de pines */


/////////////////////////////

/////////////////////////////
/* Variables publicas */


/////////////////////////////

/////////////////////////////
/* Definicion de funciones */
SoftwareSerial gpstest(rxPin, txPin);
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

  gpstest.begin(9600);
  while(!gpstest){
    ;
  }
  gpstest.println("Serial de software iniciado");
  
}

void loop() { // Superbucle
  
  // LLamar a getNMEA() para obtener posicion

  if(Serial.available()){
    gpstest.println(Serial.read());
  }
  if(gpstest.available()){
    Serial.println(gpstest.read());
  }

  
  /*  Paquete de ejemplo  */
  // RPM, tempSensor1, tempSensor2, tempSensor3, Latitud, Longitud
  // 2500,49,78,65,25.2525252,31.31313113
}

int getRPM(){ // Funcion para extraer mediante <Metodo aun no definido> las revoluciones del vehiculo

  return rpmVal;
}

float getTS1(){ // Funcion para extraer el valor del sensor de temperatura 1

  return ts1;
}

float getTS2(){ // Funcion para extraer el valor del sensor de temperatura 2

  return ts2;
}

float getTS3(){ // Funcion para extraer el valor del sensor de temperatura 3

  return ts3;
}

String getNMEA(){ // Funcion para extraer los datos NMEA que necesitamos del GPS

  return latlonGPS;
}

void uploadLoRa(String fPL){  // Funcion para publicar al modulo de radio a travez de Serial simulado el paquete final

  // loraSerial.println(fPL);
}

void uploadMEM(String fPM){ // Funcion para publicar al modulo de almacenamiento localal
  /*  
    Probablemente sea buena idea, manejar los datos en BSON/JSON para que los datos guardados sean exportables a la base de datos
  */
}