#include <WiFi.h>

// Definição das constantes de configuração do WiFi
const char* SSID = "NomeDaRedeWiFi";
const char* PASSWORD = "SenhaDaRedeWiFi";

// Definição dos pinos dos sensores
const int sensorPin1 = 34;
const int sensorPin2 = 35;

// Variáveis globais para armazenar os valores dos sensores
float sensorValue1;
float sensorValue2;

// Função para conexão com o WiFi
void connectToWiFi() {
  // Inicialização da conexão com o WiFi
  WiFi.begin(SSID, PASSWORD);

  // Aguarda até que a conexão WiFi seja estabelecida ou que ocorram 5 tentativas
  int connectionAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && connectionAttempts < 5) {
    delay(1000);
    Serial.println("Tentando conectar ao WiFi...");
    connectionAttempts++;
  }
}

void setup() {
  // Inicialização da comunicação serial para depuração
  Serial.begin(9600);

  // Configuração dos pinos dos sensores como entrada
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);

  // Conexão com o WiFi
  connectToWiFi();

  // Verifica se a conexão foi estabelecida e exibe uma mensagem correspondente
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi conectado com sucesso!");
  } else {
    Serial.println("Falha na conexão WiFi. Operando em modo offline.");
  }
}

void loop() {
  // Leitura dos sensores
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

  // Cálculo da média das leituras
  float averageValue = (sensorValue1 + sensorValue2) / 2.0;

  // Verificação da qualidade da cana com base na média das leituras
  if (averageValue >= 100 && averageValue <= 200) {
    Serial.println("Cana de boa qualidade! Pronta para a colheita.");
  } else if (averageValue > 200) {
    Serial.println("Cana de baixa qualidade. Não colher!");
  } else {
    Serial.println("Cana de qualidade média. Verificar procedimentos.");
  }

  // Aguardar antes da próxima leitura dos sensores
  delay(5000);
}




