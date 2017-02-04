/*********************************************************************
  This is a library for wifi module ESP8266
  Notice: This library only support AP mode and for other modes some
          development has been needed.
  
  ------> http://www.easymcu.ir
  
  Check out the links above for our tutorials and wiring diagrams
  
  Written by Morteza Zandi for EasyMCU.
  BSD license, All text above must be included in any redistribution
 *********************************************************************/

#include "esp8266.h"

	ESP8266::ESP8266(uint8_t mod, char *ssid, char *pass, uint16_t port , uint8_t encrypt, bool multi, bool echo, uchar serNum)
	{
		switch(serNum)
		{
			case 1:
				serx = &serial1;
				break;
			
			case 2:
				serx = &serial2;
				break;
			
			case 3:
				serx = &serial3;
				break;			
		}
		init(mod, ssid, pass, port, encrypt, multi);
	}

	/***************************************************************************************************/
	
	ESP8266::ESP8266(uint8_t mod, const char *ssid, const char *pass, uint16_t port, uint8_t encrypt, bool multi, bool echo, uchar serNum)
	{
		switch(serNum)
		{
			case 1:
				serx = &serial1;
				break;
			
			case 2:
				serx = &serial2;
				break;
			
			case 3:
				serx = &serial3;
				break;			
		}		
		init(mod, ssid, pass, port, encrypt, multi);	
	}

	/***************************************************************************************************/
	
	void ESP8266::init(uint8_t mod, char *ssid, char *pass, uint16_t port, uint8_t encrypt, bool multi, bool echo)
	{
		String str;	
		
		delay.ms(ESP8266_LONG_DELAY);		
		
		if(echo)
		{	
			serx->println("AT");
		}
		else
		{
			serx->println("ATE0");
		}
		
		delay.ms(ESP8266_LONG_DELAY);
		
		str = "AT+CWMODE=";
		str = str + mod;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);
		
		str = "AT+CWSAP=\"";
		str = str + ssid + "\",\"" + pass  + "\",1," + encrypt;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);	
		
		str = "AT+CIPMUX=";
		str = str + multi;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);

		str = "AT+CIPSERVER=1,";
		str = str + port;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);	
		
	}

	/***************************************************************************************************/	
	
	void ESP8266::init(uint8_t mod, const char *ssid, const char *pass, uint16_t port, uint8_t encrypt, bool multi, bool echo)
	{
		String str;
		
		delay.ms(ESP8266_LONG_DELAY);		
		
		if(echo)
		{	
			serx->println("AT");
		}
		else
		{
			serx->println("ATE0");
		}
		
		delay.ms(ESP8266_LONG_DELAY);
		
		str = "AT+CWMODE=";
		str = str + mod;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);
		
		str = "AT+CWSAP=\"";
		str = str + ssid + "\",\"" + pass  + "\",1," + encrypt;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);	
		
		str = "AT+CIPMUX=";
		str = str + multi;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);

		str = "AT+CIPSERVER=1,";
		str = str + port;
		serx->println(str);
		delay.ms(ESP8266_LONG_DELAY);	
		
	}

	/***************************************************************************************************/	
	
	void ESP8266::write(char *buf)
	{
		String str;
		uint8_t i=0;
		
		while(buf[i++] != '\0');
		i++;
		
		str = "AT+CIPSEND=0,";
		str = str + i;
		serx->println(str);
		delay.ms(ESP8266_SHORT_DELAY);		
		
		serx->println(buf);
		delay.ms(ESP8266_SHORT_DELAY);		
	}
	
	/***************************************************************************************************/
	
	void ESP8266::write(String str)
	{
		String wstr;
		uint8_t i=0;
		
		i = str.length()+2;
		
		wstr = "AT+CIPSEND=0,";
		wstr = wstr + i;
		serx->println(wstr);
		delay.ms(ESP8266_SHORT_DELAY);
		
		serx->println(str);
		delay.ms(ESP8266_SHORT_DELAY);			
		
	}
	
	/**************************************************************************************************/
	
	void ESP8266::writeln(String str)
	{
		String wstr;
		uint8_t i=0;
		
		str = str + "\r\n";
		
		i = str.length()+2;
		
		wstr = "AT+CIPSEND=0,";
		wstr = wstr + i;
		serx->println(wstr);
		delay.ms(ESP8266_SHORT_DELAY);
		
		serx->println(str);	
		delay.ms(ESP8266_SHORT_DELAY);			
	}	
	
	/***************************************************************************************************/		

	void ESP8266::setTimeout(uint32_t val)
	{
		serx->setTimeout(val);
	}
	
	/***************************************************************************************************/	
	
	String ESP8266::read(void)
	{
		return serx->readString();
	}

	/***************************************************************************************************/	

	uint16_t ESP8266::available(void)
	{
		return serx->available();
	}

