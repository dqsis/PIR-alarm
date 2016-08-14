// Alarm system using a PIR sensor 

// Dimitrios Kiousis | dqsis.com
// 2016-08-13 
// -----------------------------

//  Define LED pin(s)
int userLED00Pin = 9;

// Define piezo pin(s)
int piezoPin = 8;

// Define PIR pin(s)
int PIRPin = 2;

// PIR sensor status variable declaration
int PIRstatus = 0;

// Define initial warning time stamp and warning interval
long warnTS = -30000L;
long warnIN = 30000L;

// The setup routine runs once when you press reset:
void setup() {
  
  // Declare INPUTS
  pinMode(PIRPin, INPUT); // declare PIR sensor as input
 
  // Declare OUTPUTS 
  pinMode(userLED00Pin, OUTPUT); // declare LED as output
  
  // Open the serial port and set data rate 
  Serial.begin(9600);
  
}

// The loop routine runs over and over again forever:
void loop() {

  // Read PIR status 
  PIRstatus = digitalRead(PIRPin);  
  
  // If the PIR detects motion 
  if (PIRstatus == HIGH) { 
    
    // Blink LED
    digitalWrite(userLED00Pin, HIGH);
    delay(75);
    digitalWrite(userLED00Pin, LOW);
    delay(75);

    // Sound the buzzer 
    tone(piezoPin, 50, 100);

    // Print out a warning (once every half minute) 
    long now = millis();
    if (now > (warnTS + warnIN)){
      Serial.println("MOVEMENT DETECTED! ");
      warnTS = now;
    }
    
  }

  
}
