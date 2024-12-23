#include <stm32_wrapper_usart.h>
#include "PinAsInput.h"
#include "PinAsOutput.h"

namespace OOlayer {

class Serial {
	private: 
		COMPORT comPort;
		PinAsInput* rxPin;        
    PinAsOutput* txPin;
	public: 	
		Serial(COMPORT portNum= COM2, PinName pinTX= PA_2,
					 PinName pinRX= PA_3,PortSpeed speed= Low, 
					 PortConfig config= CONFIG_8N1, PortMode mode= MODE_TX_RX): comPort(portNum)
			{
				Usart_HAL_Init(portNum, speed, config, mode);
				this->rxPin = new PinAsInput(pinRX, Floating);
				this->txPin = new PinAsOutput(pinTX, AF_PPull);
			}
			
		void printChaine(const char* msg, int length){
				Serial_HAL_PrintString(this->comPort, msg , length);
		}
		char* readChaine(int length){
				return Serial_HAL_ReadString(this->comPort,length);
		}
		
		void ITprintChaine(const char* msg, int length){Serial_HAL_ITPrintString(this->comPort, msg , length);}
		char* ITreadChaine(int length){return Serial_HAL_ITReadString(this->comPort,length);}
	
};
	
}// namespace
