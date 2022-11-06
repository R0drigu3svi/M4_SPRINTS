const int buzzer = 1;
const int ledVermelho = 47;
const int ledAzul = 45;
const int ledVerde = 35;
const int ledBranco = 37;
const int botao1 = 5;
const int botao2 = 4;
const int LDR = 7;
int valores[100];
int Vatual = 0;
void som(int value){
  tone(buzzer, 100*value, 500);
}
void luz(int value){
    if(value == 15){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 14){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, LOW);
  } else if(value == 13){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 12){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, LOW);
  } else if(value == 11){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 10){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, LOW);
  } else if(value == 9){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 8){
      digitalWrite(ledVermelho, HIGH);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, LOW);
  } else if(value == 7){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 6){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, LOW);
  } else if(value == 5){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 4){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, HIGH);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, LOW);
  } else if(value == 3){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 2){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledBranco, LOW);
  } else if(value == 1){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, HIGH);
  } else if(value == 0){
      digitalWrite(ledVermelho, LOW);
      digitalWrite(ledAzul, LOW);
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledBranco, LOW);
  }
}
void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledBranco, OUTPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  for(int i = 0; i <100; i++){
    valores[i] = -1;
  }
}
void loop() {
  if(!digitalRead(botao1)){
    int a = map(analogRead(LDR), 32, 4063, 0, 15);
    Serial.println(a);
    valores[Vatual] = a;
    som(a);
    luz(a);
    Vatual += 1;
    delay(1000);
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAzul, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledBranco, LOW);
  }
  if(!digitalRead(botao2)){
    //Serial.println("entrou");
    for(int i = 0; i < Vatual; i++){
      som(valores[i]);
      luz(valores[i]);
      valores[i] = -1;
      delay(1000);
    }
  }
}
