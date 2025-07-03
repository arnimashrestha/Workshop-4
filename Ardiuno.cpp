//Variables
//Setting Variables for the pins
//Used Analog In, because 
//Analog input pins (A0, A1, A2) allow the ardiuno to read 
//variable voltages from external sensors or devices
const int sensorPin = A0;   

//setting variable names to avoid confusion 
const int redLED = 7;   
const int blueLED = 6;   
const int greenPin = 5;     

// Light level thresholds (adjust as needed)
const int darkThreshold = 400;
const int brightThreshold = 800;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(blueLED, OUTPUT);
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
    digitalWrite(redLED, 0);
    digitalWrite(blueLED, 0);
  } else if (lightVal < darkThreshold) {
    // Turn Off Lights
    digitalWrite(redLED, HIGH);
    digitalWrite(greenPin, 0);
    digitalWrite(blueLED, 0);
  } else if  (lightVal > darkThreshold && lightVal< brightThreshold) {
    // Lights
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, 0);
    digitalWrite(greenPin, 0);
  }

  delay(200);  // Slight delay to avoid flicker
}