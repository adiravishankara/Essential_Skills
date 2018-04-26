float val = 0; //value for storing moisture value 
int soilPin = A0;//Declare a variable for the soil moisture sensor 
int soilPower = 5;//Variable for Soil moisture Power
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);   // open serial over USB

  pinMode(soilPower, OUTPUT);//Set D7 as an OUTPUT
  digitalWrite(soilPower, LOW);//Set to LOW so no power is flowing through the sensor
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(readSoil());
delay(1000);
}
int readSoil(){
    digitalWrite(soilPower, HIGH);//turn D7 "On"
    delay(50);//wait 10 milliseconds 
    val = analogRead(soilPin);//Read the SIG value form sensor 
    digitalWrite(soilPower, LOW);//turn D7 "Off"
    return val;//send current moisture value
}
