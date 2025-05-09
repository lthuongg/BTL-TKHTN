#include <SPI.h>
#include <LoRa.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define NSS 5
#define RST 14
#define DI0 2

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

String receivedData = "";

float windSpeed = 0.0, rainfall = 0.0, temperature = 0.0, humidity = 0.0;
int packet_count = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  // Cấu hình LoRa
  LoRa.setPins(NSS, RST, DI0);
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

  LoRa.setSignalBandwidth(62.5E3);
  LoRa.setSpreadingFactor(11);
  LoRa.setCodingRate4(5);
  LoRa.setTxPower(20);
  Serial.println("LoRa Initialized successfully.");

  Wire.begin(21, 22);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed. Check your connections.");
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Wind Speed: " + String(windSpeed));
  display.println("Rainfall: " + String(rainfall));
  display.println("Temperature: " + String(temperature));
  display.println("Humidity: " + String(humidity));
  display.println("Packet: " + String(packet_count));
  display.display();
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Received packet '");

    receivedData = "";
    while (LoRa.available()) {
      receivedData += (char)LoRa.read();
    }
    packet_count++;

    Serial.println(receivedData);

    windSpeed = extractValue(receivedData, "Toc do gio: ");
    rainfall = extractValue(receivedData, "Luong mua: ");
    temperature = extractValue(receivedData, "Nhiet do: ");
    humidity = extractValue(receivedData, "Do am: ");

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Wind Speed: " + String(windSpeed));
    display.println("Rainfall: " + String(rainfall));
    display.println("Temperature: " + String(temperature));
    display.println("Humidity: " + String(humidity));
    display.println("Packet: " + String(packet_count));
    display.display();

    Serial.print("Toc do gio: ");
    Serial.println(windSpeed);
    Serial.print("Luong mua: ");
    Serial.println(rainfall);
    Serial.print("Nhiet do: ");
    Serial.println(temperature);
    Serial.print("Do am: ");
    Serial.println(humidity);
  }
}

float extractValue(String data, String label) {
  int startIndex = data.indexOf(label);
  if (startIndex == -1) return -1;

  startIndex += label.length();
  int endIndex = data.indexOf(",", startIndex);
  if (endIndex == -1) {
    endIndex = data.indexOf("\n", startIndex);
  }

  String value = data.substring(startIndex, endIndex);
  return value.toFloat();
}
