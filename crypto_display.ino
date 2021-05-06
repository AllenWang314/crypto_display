#include <WiFi.h> //Connect to WiFi Network
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <ArduinoJson.h>
#include "support_functions.h"

//// GLOBAL VARIABLES ////
int last_update_millis;
double etc_price;
char request_buffer[IN_BUFFER_SIZE]; //char array buffer to hold HTTP request
char response_buffer[OUT_BUFFER_SIZE]; //char array buffer to hold HTTP response

//// CONSTANTS ////
const char GET_URL[] = "GET http://api.nomics.com/v1/currencies/ticker?key=YOUR_API_KEY_GOES_HERE&ids=ETC&interval=1d,30d&convert=USD&per-page=100&page=1 HTTP/1.1\r\n";
const char HOST[] = "api.nomics.com";
char network[] = "MIT GUEST";
char password[] = "";
uint8_t channel = 1; //network channel on 2.4 GHz
byte bssid[] = {0x04, 0x95, 0xE6, 0xAE, 0xDB, 0x41}; //6 byte MAC address of AP you're targeting.

// hardware instances
TFT_eSPI tft = TFT_eSPI();
////////////////////////////

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.setTextSize(3);
  tft.fillScreen(TFT_BLACK);
  Serial.begin(115200);
  connect_to_wifi();

  last_update_millis = millis();
  etc_price = 0;
}

void loop() {
  if (millis() - last_update_millis > 5000) {
    tft.fillScreen(TFT_BLACK);
    get_updates(); // get updates from server
    tft.setCursor(0,0);
    last_update_millis = millis();
  }
}

/*
 * get all necessary data from server to update global variables
 * returns true if there are new non processed updates from server
 *
 * updates most recent update variable and update hash
 */
boolean get_updates() {
  sprintf(request_buffer, GET_URL, 0);
  strcat(request_buffer, "Host: api.nomics.com\r\n");
  strcat(request_buffer, "\r\n");
  do_http_request("api.nomics.com", request_buffer, response_buffer, OUT_BUFFER_SIZE, RESPONSE_TIMEOUT, 0);
  DynamicJsonDocument doc(2048);
  char * start_ptr = strchr(response_buffer,'{');
  char * end_ptr = strrchr(response_buffer,'}');
  end_ptr[1] = '\0';
  deserializeJson(doc, start_ptr);
  etc_price = doc["price"];
  tft.println(etc_price);
}

