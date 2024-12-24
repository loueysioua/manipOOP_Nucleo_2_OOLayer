
#include "stm32_wrapper_usart.h"
#include <stdlib.h>

/*===============================================================*/
/*       INITIALLIZATION FUNCTION for Serial Objects :      */
/*      - Translates OO config Represetation to ST FWL       */
/*      - And Calls ST FWLibrary Functions                       */
/*================================================================*/

USART_TypeDef* Get_Usart(COMPORT portNum) {
	switch(portNum){
			case 0x01: return USART1; 
			case 0x02: return USART2; 
			case 0x03: return USART3; 
			default: return USART2;
	};
}

void Enable_Usart_Clock(COMPORT portNum) {
	switch(portNum){
			case 0x01: RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); break;
			case 0x02: RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); break;
			case 0x03: RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); break;
			default: RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); break;
	};
}

void Usart_HAL_Init(COMPORT portNum,PortSpeed speed ,PortConfig config, PortMode mode){
	USART_TypeDef* USARTx;
	
	//to ensure better performance i made the get and enable usart in one switch
	switch(portNum){
			case 0x01: USARTx= USART1; RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); break;
			case 0x02: USARTx= USART2;  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); break;
			case 0x03: USARTx= USART3;  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE); break;
			default: USARTx= USART2; RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); break;
	};
	
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = speed;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	
	
	// setting the mode
	switch (mode) {
        case MODE_TX:
            USART_InitStructure.USART_Mode = USART_Mode_Tx;
            break;
        case MODE_RX:
            USART_InitStructure.USART_Mode = USART_Mode_Rx;
            break;
        case MODE_TX_RX:
            USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
            break;
    }
	
		
		// setting the wordlength , parity and stop bits : 
		switch (config) {
        case CONFIG_8N1:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_8N2:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
        case CONFIG_8E1:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_Even;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_8E2:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_Even;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
        case CONFIG_8O1:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_Odd;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_8O2:
            USART_InitStructure.USART_WordLength = USART_WordLength_8b;
            USART_InitStructure.USART_Parity = USART_Parity_Odd;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
        case CONFIG_9N1:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_9N2:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_No;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
				case CONFIG_9E1:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_Even;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_9E2:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_Even;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
				case CONFIG_9O1:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_Odd;
            USART_InitStructure.USART_StopBits = USART_StopBits_1;
            break;
        case CONFIG_9O2:
            USART_InitStructure.USART_WordLength = USART_WordLength_9b;
            USART_InitStructure.USART_Parity = USART_Parity_Odd;
            USART_InitStructure.USART_StopBits = USART_StopBits_2;
            break;
    }
		
		//Initialize USART
		USART_Init(USARTx,&USART_InitStructure);
		
		//Enable USART
		USART_Cmd(USARTx, ENABLE);
		
		NVIC_InitTypeDef NVIC_InitStructure;
    NVIC_InitStructure.NVIC_IRQChannel = USARTx_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    USART_ITConfig(USARTx, USART_IT_RXNE, ENABLE); // Enable RXNE interrupt
}


void Serial_HAL_PrintByte(USART_TypeDef* USARTx, uint8_t data){
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE)==RESET);
	USART_SendData(USARTx,data);
	
}
uint8_t Serial_HAL_ReadByte(USART_TypeDef* USARTx){
	while(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE)==RESET);
	return (uint8_t) USART_ReceiveData(USARTx); 
}
void Serial_HAL_PrintString(COMPORT comPort, const char* msg , int length){
	USART_TypeDef* USARTx = Get_Usart(comPort);
	for (int i=0; i<length ; i++){
		Serial_HAL_PrintByte(USARTx,msg[i]);
	}
}
char* Serial_HAL_ReadString(COMPORT comPort, int length){
	USART_TypeDef* USARTx = Get_Usart(comPort);	
	char* receiveBuffer = (char*)malloc(length * sizeof(char));
	for (int i=0; i< length; i++){
		receiveBuffer[i] = Serial_HAL_ReadByte(USARTx);
	}
	return receiveBuffer;
}
#define TX_BUFFER_SIZE 128
#define RX_BUFFER_SIZE 128

volatile uint8_t txBuffer[TX_BUFFER_SIZE];
volatile uint8_t rxBuffer[RX_BUFFER_SIZE];
volatile int txHead = 0, txTail = 0;
volatile int rxHead = 0, rxTail = 0;
volatile int txLength = 0, rxLength = 0;
volatile int txBusy = 0;

void Serial_HAL_ITPrintString(COMPORT comPort, const char* msg, int length) {
    USART_TypeDef* USARTx = Get_Usart(comPort);
    for (int i = 0; i < length; i++) {
        while (txLength >= TX_BUFFER_SIZE); // Wait if the buffer is full
        txBuffer[txHead] = msg[i];
        txHead = (txHead + 1) % TX_BUFFER_SIZE;
        txLength++;
    }

    if (!txBusy) {
        txBusy = 1;
        USART_ITConfig(USARTx, USART_IT_TXE, ENABLE); // Enable TXE interrupt
    }
}


void USARTx_IRQHandler(void) {
    if (USART_GetITStatus(USART1, USART_IT_TXE) != RESET) {
        if (txLength > 0) {
            USART_SendData(USART1, txBuffer[txTail]);
            txTail = (txTail + 1) % TX_BUFFER_SIZE;
            txLength--;
        } else {
            USART_ITConfig(USART1, USART_IT_TXE, DISABLE); // Disable TXE interrupt
            txBusy = 0;
        }
    }

    if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) {
        uint8_t data = USART_ReceiveData(USART1);
        rxBuffer[rxHead] = data;
        rxHead = (rxHead + 1) % RX_BUFFER_SIZE;
        if (rxLength < RX_BUFFER_SIZE) {
            rxLength++;
        }
    }
}


char* Serial_HAL_ITReadString(COMPORT comPort, int length) {
    USART_TypeDef* USARTx = Get_Usart(comPort);
    char* receiveBuffer = (char*)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        while (rxLength <= 0); // attendre s'il n y a pas de donnees disponibles
        receiveBuffer[i] = rxBuffer[rxTail];
        rxTail = (rxTail + 1) % RX_BUFFER_SIZE;
        rxLength--;
    }
    return receiveBuffer;
}
