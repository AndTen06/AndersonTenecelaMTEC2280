const int potPin1 = 5;
const int potPin2 = 7;

int potValue1 = 0;
int potValue2 = 0;

const int button1 = 1;
const int button2 = 2;

bool buttonValue1 = 0;
bool buttonValue2 = 0;


//software timer variables
int lastTime = 0;
int currentTime = 0;
int timerInterval = 20; //not reliable with values less than 20ms

void setup() {
  // put your setup code here, to run once:

Serial.begin(115200);
analogReadResolution(8);
pinMode(button1, INPUT_PULLUP); 
pinMode(button2, INPUT_PULLUP);

}

void loop() {

buttonValue1 = !digitalRead(button1);
buttonValue2 = !digitalRead(button2);
currentTime = millis(); //read current elapsed time
  if (currentTime - lastTime >= timerInterval)  //if we have reached our timer interval...
  {
    lastTime = currentTime; //store current time as last time so we know when timer last occured
    potValue1 = analogRead(potPin1);
    potValue2 = analogRead(potPin2); //read sensor and assign to variable called adcRead

    Serial.write(potValue1); //1st byte
    Serial.write(potValue2); //2nd byte
    Serial.write(buttonValue1);                     //3rd byte
    Serial.write(buttonValue2);                     //4th byte
    Serial.write('e');                              //5th byte

  
  }

}
