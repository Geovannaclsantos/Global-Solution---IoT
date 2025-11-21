#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Aqui eu inicializo o display LCD. 
// O endereço 0x27 é o mais comum, mas dependendo do módulo pode ser 0x3F.
// O display tem 16 colunas e 2 linhas.
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ldrPin = A0;    // Esse é o pino onde o sensor LDR está ligado.
const int buzzerPin = 2;  // Esse é o pino do buzzer (caixinha que faz barulho).

void setup() {
  // Inicializo o LCD informando que ele tem 16 colunas e 2 linhas.
  lcd.begin(16, 2);

  // Acendo a luz de fundo do LCD para aparecer o texto.
  lcd.backlight();

  // Configuro o pino do buzzer como saída, porque ele vai emitir sinais.
  pinMode(buzzerPin, OUTPUT);

  // Garante que o buzzer comece desligado.
  noTone(buzzerPin);
}

void loop() {
  // Aqui eu leio o valor do LDR. Ele vai de 0 a 1023 no Arduino.
  // Quanto mais luz, menor é a resistência do LDR, então o valor muda conforme a iluminação.
  int ldrValue = analogRead(ldrPin);

  // Aqui eu converto esse valor do LDR para uma frequência de som.
  // Usei o "map" para transformar o número entre 0–1023 em 200–2000 Hz.
  // Isso faz o buzzer tocar mais agudo quando tem mais luz.
  int frequency = map(ldrValue, 0, 1023, 200, 2000);

  // Limpo o LCD antes de escrever de novo.
  lcd.clear();

  // Escrevo a primeira linha do LCD.
  lcd.print("LDR Value:");

  // Vou para a segunda linha e mostro o valor lido do sensor.
  lcd.setCursor(0, 1);
  lcd.print(ldrValue);

  // Aqui eu faço o buzzer tocar uma nota com a frequência que calculei.
  // Ele toca por 100 milissegundos.
  tone(buzzerPin, frequency, 100);

  // Pauso meio segundo antes de repetir tudo de novo.
  delay(500);
}
