const int ledPin = 13;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

void printValue(char *label, int value) {
  Serial.print("\"");
  Serial.print(label);
  Serial.print("\": ");
  Serial.print(value);
}

void printComma() {
  Serial.print(", ");
}

void loop(){
  blink(1);
  delay(500);

  Serial.print("{");
  
  printValue("prox-front", analogRead(A0)); printComma();
  printValue("prox-left",  analogRead(A1)); printComma();
  printValue("prox-right", analogRead(A2)); printComma();
  printValue("prox-back",  analogRead(A3)); printComma();
  
  printValue("audio", analogRead(A4)); printComma();
  printValue("etoh",  analogRead(A5)); printComma();
  printValue("smoke", analogRead(A6)); printComma();

  printValue("motion", digitalRead(7));

  Serial.println("}");
}



void blink(int numberOfTimes){
  for (int i = 0; i < numberOfTimes; i++)  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}


