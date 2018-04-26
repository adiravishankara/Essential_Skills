 #include "config.h"
AdafruitIO_Feed *analog17 = io.feed("analog17");
float val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 5;//Variable for Soil moisture Power

void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();
  Serial.print("sending -> ");
  Serial.print("Soil Moisture = ");    
  Serial.println(readSoil());
  analog17->save(readSoil());
  delay(10000);//take a reading every second
}
//This is a function used to get the soil moisture content
int readSoil(){
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(10);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    //val = map(val,0,1024,0,880);
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}


