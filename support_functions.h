#ifndef _SUPPORT_FUNCTIONS_
#define _SUPPORT_FUNCTIONS_

#include <WiFi.h> //Connect to WiFi Network

const int RESPONSE_TIMEOUT = 6000; //ms to wait for response from host
const int POSTING_PERIOD = 6000; //ms to wait between posting step
const uint16_t IN_BUFFER_SIZE = 1000; //size of buffer to hold HTTP request
const uint16_t OUT_BUFFER_SIZE = 2000; //size of buffer to hold HTTP response
const int JSON_BODY_SIZE = 1000;

void connect_to_wifi();

uint8_t char_append(char* buff, char c, uint16_t buff_size) ;

void do_http_request(char* host, char* request, char* response, uint16_t response_size, uint16_t response_timeout, uint8_t serial);

#endif
