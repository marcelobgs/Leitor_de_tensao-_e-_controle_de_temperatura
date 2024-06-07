#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);  // Pinos do LCD (RS, E, D4, D5, D6, D7)
int pot;
void setup() {
    lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
}

void loop() {
    int sensorTemp = analogRead(A0);  // Leitura do sensor de temperatura
    float temperaturaC = map(((sensorTemp - 20) * 3.04), 0, 1023, -40, 125);  // Conversão para Celsius

    int sensorTensao = analogRead(A0);  // Leitura de tensão de saída da Porta A0
    float tensao = (sensorTensao / 1023.0) * 5.0;  // Conversão para tensão (0-5V)
	
  	// Primeira linha
    lcd.clear();  // Limpa o LCD
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperaturaC);
    lcd.print(" C");
	
  	// Segunda linha
    lcd.setCursor(0, 1);
    lcd.print("Tensao: ");
    lcd.print(tensao);
    lcd.print(" V");

    delay(1000);  // Aguarda 1 segundo antes de ler novamente
}
