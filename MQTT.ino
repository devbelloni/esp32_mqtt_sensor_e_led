void inicia_mqtt()
{
  Serial.println();
  Serial.println("------------------------------- Iniciando conexão -------------------------------");
  reconecta_mqtt();
}

void reconecta_mqtt()
{
  while (!MQTT.connected()) // enquanto não estiver conectado
  {
    MQTT.setServer (broker_id, porta);
    Serial.print("Tentando se conectar ao Broker: ");
    Serial.println(broker_id);
    Serial.print("Pela porta: ");
    Serial.println(porta);
    Serial.print("Aguarde");
    
    delay (1000);
    if (MQTT.connect(mqtt_id))// se conectar ao Broker
    {
      Serial.println();
      Serial.println("Conectado ao Broker com sucesso");      
    }
    else 
    {
      Serial.println("Falha de conexão com o Broker");
      Serial.println("Haverá nova tentativa de conexão em 2 segundos.");
      delay(2000);
    }
  }
}
