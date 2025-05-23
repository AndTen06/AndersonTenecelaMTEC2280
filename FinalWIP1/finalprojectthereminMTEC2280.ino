const int echo1 = 10;
const int trigger1 = 11;
const int echo2 = 5;
const int trigger2 = 6;
long duration = 0;
long duration2 = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(115200);
   analogReadResolution(10); 
   pinMode(trigger1, OUTPUT);
   pinMode(trigger2, OUTPUT);
   pinMode(echo1, INPUT);
   pinMode(echo2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigger1, LOW);
digitalWrite(trigger2, LOW);
delayMicroseconds(5);

digitalWrite(trigger1, HIGH);
digitalWrite(trigger2, HIGH);
delayMicroseconds(10);

digitalWrite(trigger1, LOW);
digitalWrite(trigger2, LOW);

duration = pulseIn(echo1, HIGH);
duration2 = pulseIn(echo2, HIGH);
//duration = digitalRead(echo1);

float distance = (duration*.0343)/2; 
float frequency = map(distance, 5, 30, 440, 1760);

  Serial.print(duration);
  Serial.print('/');
  Serial.print(duration2);
	Serial.println('e');  
	delay(200);  

}
