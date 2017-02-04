/*********************************************************************
  This is a library for wifi module ESP8266
  Notice: This library only support AP mode and for other modes some
          development has been needed.
  
  ------> http://www.easymcu.ir
  
  Check out the links above for our tutorials and wiring diagrams
  
  Written by Morteza Zandi for EasyMCU.
  BSD license, All text above must be included in any redistribution
 *********************************************************************/

#ifndef __ESP8266_HPP__
#define __ESP8266_HPP__

#include "Wstring.h"
#include "HW_serial.h"
#include "delay.h"
#include "common_func.h"


#define ESP8266_ECHO_DISABLE 			        false
#define ESP8266_ECHO_ENABLE				        true

#define ESP8266_STA 							1
#define ESP8266_AP 								2
#define ESP8266_STA_AP							3

#define ESP8266_LONG_DELAY						350		//millis	500
#define ESP8266_SHORT_DELAY						250		//millis	300
#define ESP8266_READ_LOOP_DELAY 				10		//millis

class ESP8266
{
	public:
		ESP8266(uint8_t mod, char *ssid, char *pass, uint16_t port = 23, uint8_t encrypt = 4, bool multi = 1, bool echo = ESP8266_ECHO_DISABLE, uchar serNum = 2);
		ESP8266(uint8_t mod = ESP8266_AP, const char *ssid = "EasyMCU", const char *pass = "12345678", uint16_t port = 23, uint8_t encrypt = 4, bool multi = 1, bool echo = ESP8266_ECHO_DISABLE, uchar serNum = 2);	
		void init(uint8_t mod, char *ssid, char *pass, uint16_t port, uint8_t encrypt, bool multi, bool echo );
		void init(uint8_t mod = ESP8266_AP, const char *ssid = "EasyMCU", const char *pass = "12345678", uint16_t port = 23, uint8_t encrypt = 4, bool multi = 1, bool echo = ESP8266_ECHO_DISABLE );	
		void write(char *buf);
		void write(const char *buf)
		{
			write(buf);
		}
		void writeln(String str);
		void write(String str);	
		void setTimeout(uint32_t val);
		String read(void);
		uint16_t available(void);
			
	private:
		UART *serx;
	
};

#endif

