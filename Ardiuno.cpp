//Variables
//Setting Variables for the pins
//Used Analog In, because 
//Analog input pins (A0, A1, A2) allow the ardiuno to read 
//variable voltages from external sensors or devices
const int sensorPin = A0;   

//setting variable names to avoid confusion 
const int redPin = 7;   
const int bluePin = 6;   
const int greenPin = 5;     

// Light level thresholds (adjust as needed)
const int darkThreshold = 400;
const int brightThreshold = 800;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // "analog read" reads the value from a specified analog input pin
  //in our case, it is A0
  int lightVal = analogRead(sensorPin);  

  if (lightVal > brightThreshold) {
    // Brightest (flashlight)
    //The green channel on this LED is very bright
    //turn it on with analogWrite(pin,50)
    //to avoid straining your eyes
    analogWrite(greenPin, 50); 
    digitalWrite(redPin, 0);
    digitalWrite(bluePin, 0);
  } else if (lightVal < darkThreshold) {
    // Turn Off Lights
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
  } else if  (lightVal > darkThreshold && lightVal< brightThreshold) {
    // Lights
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
  }

  delay(200);  // Slight delay to avoid flicker
}