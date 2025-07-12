#include <LiquidCrystal.h>

// Inicialização do LCD: (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

// Pinos e Variáveis
int sensorGas = A0;
int ledVerde = 2;
int ledAmarelo = 3;
int ledVermelho = 4;
int leituraGas = 0;
int concentracaoGas = 0;
int buzzer = 13;

void setup() {
  Serial.begin(9600); // Inicialização serial para monitoramento
  lcd.begin(16, 2); // Inicizalização LCD 16x2
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensorGas, INPUT);
  lcd.print("Monitoramento");
  delay(2000);
  lcd.clear();
}

void loop() {
  leituraGas = analogRead(sensorGas);
  // Converte o valor para uma faixa percentual
  concentracaoGas = map(leituraGas, 273, 725, 0, 100);
  // Exibe a porcentagem no monitor serial
  Serial.print("Valor: ");
  Serial.print(concentracaoGas);
  Serial.println(" %");
  
  lcd.clear();
   
  if (concentracaoGas > 90) {
    // Alta concentração gás
    lcd.setCursor(0, 1);
    lcd.print("PERIGO");
    delay(1000);
    lcd.setCursor(0, 0);
    lcd.print("EVACUAR");
    delay(1000);
    tone(buzzer,1000,10000); // Barulho buzzer
    digitalWrite(ledVermelho, HIGH); // LED vermelho acende
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  } else if (concentracaoGas > 5) {
    // Média concentração de gás
    lcd.setCursor(0, 0);
    lcd.print("Valor = ");
    lcd.print(concentracaoGas);
    lcd.print(" %");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("ATENCAO");
    delay(1000);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH); // LED amarelo acende
    digitalWrite(ledVerde, LOW);
  } else {
    // Baixa concentração de gás
    lcd.setCursor(0, 0);
    lcd.print("Valor = ");
    lcd.print(concentracaoGas);
    lcd.print(" %");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("SEGURO");
    delay(1000);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH); // LED verde acende
  }

  delay(1000); // Intervalo entre leituras
}

  // Limpa o display após nova leitura