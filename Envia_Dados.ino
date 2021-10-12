void envia_dados()
{
  if((millis()-tempo_passado)>=2000)//verifica se passou o tempo
  {
    Serial.println("----------------------------- Enaviando dados --------------------------------");
    pot=map(analogRead(pinpot),0,1023,0,100);
    Serial.print("Valor lido pelo potenciômetro: ");    Serial.println(pot);
    dtostrf(pot,0,0,pot_converted );
    Serial.print("Valor lido pelo potenciômetro (convertido): ");    Serial.println(pot_converted);
    MQTT.publish ("pot_maluco_209092014", pot_converted);
    
    tempo_passado=millis();
  if (topicStr.equals(MQTT_COMMAND_TOPIC)) {
    if (payloadStr.equals("ON")) {
      digitalWrite(GPIO7_LED, HIGH);
      MQTT.publish(MQTT_STATE_TOPIC, "ON");
      Serial.print("LED LIGOU");

    } else if (payloadStr.equals("OFF")) {
      digitalWrite(GPIO7_LED, LOW);
      MQTT.publish(MQTT_STATE_TOPIC, "OFF");
      Serial.print("LED DESLIGOU");
    }

}

}
