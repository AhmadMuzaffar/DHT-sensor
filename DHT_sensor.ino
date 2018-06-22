//#include <Adafruit_AM2320.h>
#include "DHT.h"
#define DHTPIN 3     // what pin we're connected to digital pin 2
#define DHTTYPE DHT11   // DHT 22  (AM2302)

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  Serial.print("Humidity: \n"); 
  Serial.print(h);
  Serial.print(" %\t \n");
  Serial.print("Temperature: \n"); 
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t \n");
  Serial.print("Heat index: \n");
  Serial.print(hi);
  Serial.println(" *F");
}
