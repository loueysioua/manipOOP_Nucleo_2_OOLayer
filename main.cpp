#include "stm32f10x.h"
#include "Serial.h"

using namespace OOlayer;

char* buffer;

void delay(int count) {
    for (volatile int i = 0; i < count; ++i);
}

int main ()
{	
	Serial MyPortCom;
	
	const char msg[]= "Hello World";
	MyPortCom.printChaine(msg, sizeof(msg));
	
	while(1) {
		buffer = MyPortCom.readChaine(8);
	}
	
	return 0;
}

