const int potPin1 = 5;

int potValue = 0;

//software timer variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 20; //not reliable with values less than 20ms

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
analogReadResolution(8);

}

void loop() {
  // put your main code here, to run repeatedly:
currentTime = millis(); //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime; //store current time as last time so we know when timer last occured
    potValue = analogRead(potPin1); //read sensor and assign to variable called adcRead

    //Serial. println(val); //to send human-readable data to Arduino monitor
    Serial.write(map(potValue, 0, 255, 250, 500));  //to send binary data to Processing

    //code in here will only run every 20ms, freeing up our CPU for other tasks
  }

}
