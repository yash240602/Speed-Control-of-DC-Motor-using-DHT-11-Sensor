#include <DHT.h>

// Set the type of DHT sensor you're using
#define DHTTYPE DHT11
// Pin to which the DATA pin of the DHT11 is connected
#define DHTPIN 2

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Read the temperature in Celsius
  float temperature = dht.readTemperature();
  // Read the humidity
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Control the output based on the temperature
  if (temperature > 30 && temperature <= 35) {
    analogWrite(5, 150);
  } else if (temperature > 25 && temperature <= 30) {
    analogWrite(5, 90);
  } else if (temperature > 15 && temperature <= 25) {
    analogWrite(5, 40);
  } else {
    // If the temperature is outside the specified range, turn off the output
    analogWrite(5, 0);
  }

  // Print the temperature and humidity to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Wait 2 seconds before the next reading
  delay(2000);
}
