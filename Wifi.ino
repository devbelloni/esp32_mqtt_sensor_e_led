void inicia_wifi(){
delay (50);
  Serial.println("------------ Iniciando conexão WiFi ------------------");
  Serial.print("Conectando-se na rede: ");
  Serial.println (ssid);
  Serial.println ("Aguarde...");
    reconecta_wifi();
}
 
void reconecta_wifi()
{
 if(WiFi.status() == WL_CONNECTED)
 { // veriricando se está conectado ao WIFI
  return;// enquanto não tiver conectado
 }
 
while (WiFi.status() != WL_CONNECTED)
  {
  WiFi.begin("CLARO_2G4A3C1E", "E74A3C1E");// 
  Serial.println(".");
  delay(5000);
  }
Serial.println();
Serial.print("Conectado com sucesso na rede: ");Serial.println(ssid);
Serial.print("IP: ");
Serial.println(WiFi.localIP());
Serial.print("Endereço MAC: ");
Serial.println(WiFi.macAddress());  

}
