import processing.serial.*; 

Serial myPort; 
int val = 0; 

void setup()
{
  size (800, 500);
  textAlign(CENTER);
  textSize(50);
  
  
  printArray(Serial.list()); // this line prints the port list to the console
  String portName = Serial.list()[0]; //change the number in the [] for the port you need
  myPort = new Serial(this, portName, 115200);  //open selected port at given baud rate
}
void draw() 
{
  if (myPort.available() > 0) // If data is available,...
  { 
  val = myPort.read();       // ...read it and store it in val
  }
  
  color c = color(val, 250, 200);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
rect(300, 100, val, 300);
triangle(40, 300, 162, 30, 260, 300);
ellipse(700, 184, 120, 120);
  
}
