import processing.serial.*; 

Serial myPort; 
byte[] val; 

void setup()
{
  size (800, 500);
  textAlign(CENTER);
  textSize(50);
  
  
  printArray(Serial.list()); // this line prints the port list to the console
  String portName = Serial.list()[2]; //change the number in the [] for the port you need
  myPort = new Serial(this, portName, 115200);  //open selected port at given baud rate
}
void draw() 
{
  if (myPort.available() > 0)
  { 
  val = myPort.readBytesUntil('e');       
  }
  
 if (val.length == 5)
 {
   println(val);
   
   int pot1 = int(map(val[0], -128, 127, 0, 255));
   int pot2 = int(map(val[1], -128, 127, 0, 255));
   
   boolean button1 = boolean(val[2]);
   boolean button2 = boolean(val[3]);
   
    background(255);
    fill(pot1, 0, 0); 
    circle(324, 184, 220);
    
    fill(pot2, 0, 0); 
    circle(124, 184, 220);
    if (button1)
    {
      fill(0, 255, 0);
    }
    
    if (button2)
    {
      fill(0, 0, 255);
    }
   triangle(120, 100, 212, 80, 344, 150);
 }

}
