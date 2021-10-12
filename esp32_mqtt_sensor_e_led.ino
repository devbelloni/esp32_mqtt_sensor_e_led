//------------------------------------------------------ bibliotecas ----------------------------------------------------
#include <ESP8266WiFi.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO
#include <PubSubClient.h>

//------------------------------------------------------ instâncias ------------------------------------------------------
WiFiClient esp32;
PubSubClient MQTT (esp32);

//--------------------------------------------------- definições WiFi ----------------------------------------------------
const char* ssid = "CLARO_2G4A3C1E";
const char* senha = "E74A3C1E";
char pot_converted [4];
// -------------------------------------------------- definições MQTT ---------------------------------------------------
#define mqtt_id "esp8266_iot_209092014" // identificando no broker. deve ser único.
// #define mqtt_login ""
// #define mqtt_senha ""

const char* broker_id = "mqtt.eclipseprojects.io"; // endereço do broker
int porta = 1883; // porta da conexão com o broker

// ------------------------------------------------- variáveis globais --------------------------------------------------
unsigned long tempo_passado = millis();
int pot;
#define pinpot A0 // entrada do potenciômetro A0
#define GPIO7_LED 13 //DEFINIR PIN DO LED 
const char * MQTT_COMMAND_TOPIC = "ledSala/set"; //Topico onde o Device subscreve.
const char * MQTT_STATE_TOPIC = "ledSala/state"; //Topico onde o Device publica.


 void setup() {
  Serial.begin(9600);
  inicia_wifi();
  inicia_mqtt();
  pinMode(pinpot,INPUT);
  pinMode(GPIO7_LED,OUTPUT);
  }

void loop() {
reconecta_wifi();
reconecta_mqtt();
MQTT.loop(); // mantém viva a conexão com o broker
envia_dados();

}
