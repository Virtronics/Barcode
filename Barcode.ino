// Arduino Shields Barcode Shield demo code
// www.arduino.com.au
// v1.00 11-Oct-2011 - first version
// v1.01 18-Oct-2011 - add startup serial print title
// tested on Arduino Uno,Mega
// v1.02 11-Nov-12 Unplug barcode shield to allow for upload

const int BeeperPin = 11;      // piezo beeper pin
byte serialin; // Serial data read in
byte linefeed=0; // for appending a linfeed so each barcode is on a new line
  
  
void setup() // standard arduino setup initializing loop
{
  pinMode(BeeperPin, OUTPUT);   // initialize Beeper output
  tone(BeeperPin,2500,50); // beep at 2.5kHz for 20ms    
  delay(100);
  tone(BeeperPin,2500,50); // beep at 2.5kHz for 20ms    
  Serial.begin(9600); // initialize the serial communication to 9600 baud
  Serial.println("Barcode Shield for Arduino v1.02"); // startup title
  Serial.println("www.arduino.com.au"); // website address
}

// Note that the barcode is aimed and triggered by a hardware switch
void loop() // standard arduino loop
{
  while (Serial.available()) {   // check for data from barcode scanner
    serialin = Serial.read(); // read in barcode character at 9600 baud
    Serial.write(serialin);
    delay(10); // allow 1ms delay for next barcode character to be scanned in
    linefeed = 1; // set so that whole barcode has a linefeed appended
  }
  
  if (linefeed>0) { // barcode has been full received
    linefeed = 0;
    tone(BeeperPin,2000,20); // beep at 2.5kHz for 20ms    
    Serial.print("\n\r"); // send out a linefeed to separate barcodes
  }
}

