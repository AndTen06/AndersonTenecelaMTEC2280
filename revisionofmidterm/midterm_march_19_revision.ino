const int AND = 4;
const int TID = 6;
const int SON = 15;
const int RAN = 17;

const int piezoPin = 1;
const int potPin = 5;
int ButtonValue = 0;
int buttonstate;
const int onOff = 2;
int ms = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogWriteResolution(piezoPin, 16);
  analogReadResolution(8);
  pinMode(AND, OUTPUT);
  pinMode(TID, OUTPUT);
  pinMode(SON, OUTPUT);
  pinMode(RAN, OUTPUT);


  
}

void loop() {
  // put your main code here, to run repeatedly:

  bool buttonPress = digitalRead(onOff); 

  Serial.println(buttonPress);


  for (int bright = 0; bright <= 255; bright++)
  {
    analogWrite(AND, bright);
    analogWrite(TID, bright);
    analogWrite(SON, bright);
    analogWrite(RAN, bright);
    delay(200);

    //Serial.printf("FOR LOOP 1: %bright \n",bright);
  }

    for (int bright = 255; bright >= 0; bright--)
  {
    analogWrite(AND, bright);
    analogWrite(TID, bright);
    analogWrite(SON, bright);
    analogWrite(RAN, bright);


    //Serial.printf("FOR LOOP 2: %bright \n",bright);
  }

  digitalWrite(AND, HIGH);
  delay(125); 

  digitalWrite(TID, HIGH);
  delay(300); 

  digitalWrite(SON, HIGH);
  delay(550);

  digitalWrite(RAN, HIGH);
  delay(450);

  delay(100);

  digitalWrite(AND, LOW);

  digitalWrite(TID, LOW);

  digitalWrite(SON, LOW);

  digitalWrite(RAN, LOW);

  delay(100);
if (digitalRead(TID) == HIGH && digitalRead(SON) == HIGH) {
    digitalWrite(TID, LOW);
    digitalWrite(SON, LOW);
    digitalWrite(RAN, HIGH);
    digitalWrite(AND, HIGH);
  }

    delay(100);

  digitalWrite(AND, HIGH);
    delay(100);
    digitalWrite(TID, HIGH);
    delay(300);
    digitalWrite(SON, HIGH);
    delay(580);
    digitalWrite(RAN, HIGH);
    delay(200);

    digitalWrite(AND, LOW);
    delay(50);
    digitalWrite(TID, LOW);
    delay(100);
    digitalWrite(SON, LOW);
    delay(300);
    digitalWrite(RAN, LOW);
    delay(200);

     ButtonValue = digitalRead (onOff);
     
     if (ButtonValue != 0) {
      digitalWrite(AND, HIGH);
      digitalWrite(TID, HIGH);
      digitalWrite(SON, HIGH);
      digitalWrite(RAN, HIGH);
     }

     else{
      digitalWrite(AND, LOW);
      digitalWrite(TID, LOW);
      digitalWrite(SON, LOW);
      digitalWrite(RAN, LOW);
     }

      int potRead = analogRead(potPin);
      int value = map(potRead, 0, 255, 1, 20);
  
        tone(piezoPin, 200 * value, 500);
        tone(piezoPin, 300 * value, 700);
        tone(piezoPin, 100 * value, 600);
        tone(piezoPin, 150 * value, 300);
        tone(piezoPin, 400 * value, 400);
        tone(piezoPin, 300 * value, 550);
        tone(piezoPin, 120 * value, 400);
        tone(piezoPin, 350 * value, 670);
        tone(piezoPin, 200 * value, 500);
        tone(piezoPin, 100 * value, 300);
        tone(piezoPin, 350 * value, 300);
        tone(piezoPin, 220 * value, 400);
        tone(piezoPin, 250 * value, 500);
        tone(piezoPin, 400 * value, 500);
        tone(piezoPin, 300 * value, 550);
        tone(piezoPin, 150 * value, 100);

        Serial.println("pot");
        Serial.println(potRead);
      


    }
