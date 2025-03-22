const int AND = 4;
const int TID = 6;
const int SON = 8;
const int RAN = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(AND, OUTPUT);
  pinMode(TID, OUTPUT);
  pinMode(SON, OUTPUT);
  pinMode(RAN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(AND, HIGH);
  delay(400); 

  digitalWrite(TID, HIGH);
  delay(500); 

  digitalWrite(SON, HIGH);
  delay(600);

  digitalWrite(RAN, HIGH);
  delay(700);

  delay(900);

  digitalWrite(AND, LOW);

  digitalWrite(TID, LOW);

  digitalWrite(SON, LOW);

  digitalWrite(RAN, LOW);

  delay(900);
if (digitalRead(TID) == HIGH && digitalRead(SON) == HIGH) {
    digitalWrite(TID, LOW);
    digitalWrite(SON, LOW);
    digitalWrite(RAN, HIGH);
    digitalWrite(AND, HIGH);
  }

    delay(900);

  digitalWrite(AND, HIGH);
    delay(800);
    digitalWrite(TID, HIGH);
    delay(800);
    digitalWrite(SON, HIGH);
    delay(800);
    digitalWrite(RAN, HIGH);
    delay(800);

    digitalWrite(AND, LOW);
    delay(800);
    digitalWrite(TID, LOW);
    delay(800);
    digitalWrite(SON, LOW);
    delay(800);
    digitalWrite(RAN, LOW);
    delay(800);

    delay (1300);
}