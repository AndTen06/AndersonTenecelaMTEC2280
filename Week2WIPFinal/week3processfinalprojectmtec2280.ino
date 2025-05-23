const int echoPin1 = 10;
const int triggerPin1 = 11;
const int echoPin2 = 5;
const int triggerPin2 = 6;
long duration = 0;
long duration2 = 0;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(10); 
  pinMode(triggerPin1, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);

}

void loop() 
{
  //TRIGGER A 5 microsecond pulse
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(5);

  digitalWrite(triggerPin2, LOW);

  //READ ECHO
  duration2 = pulseIn(echoPin2, HIGH);
  delayMicroseconds(2);

  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(5);

  digitalWrite(triggerPin1, LOW);

  duration = pulseIn(echoPin1, HIGH);
  

  Serial.print(duration); 
  Serial.print('/');
  Serial.print(duration2);
	Serial.println('/');  
	delay(10);  

}

