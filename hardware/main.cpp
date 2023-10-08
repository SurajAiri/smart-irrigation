#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // Create a BMP280 instance

void setup()
{
    Serial.begin(115200); // Start serial communication
    Wire.begin(D2, D1);   // Initialize I2C communication with D2 as SDA and D1 as SCL
    if (!bmp.begin(0x76))
    {
        Serial.println("Could not find a valid BMP280 sensor, check wiring!");
        while (1)
            ;
    }
}

void loop()
{
    float temperature = bmp.readTemperature();
    float pressure = bmp.readPressure() / 100.0F; // Convert Pa to hPa

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    delay(1000); // Wait for 1 second before reading again
}