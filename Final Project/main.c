/*
 * Final Project.c
 *
 * Created: 7/30/2019 12:58:05 PM
 * Author : Anuththara
 */ 

#define F_CPU 1000000UL


#define D0 eS_PORTD0
#define D1 eS_PORTD1
#define D2 eS_PORTD2
#define D3 eS_PORTD3
#define D4 eS_PORTD4
#define D5 eS_PORTD5
#define D6 eS_PORTD6
#define D7 eS_PORTD7
#define RS eS_PORTC6
#define EN eS_PORTC7

#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

char numberpressed();
void startBlender();
void stopBlender();
void startWaterPump();
void stopWaterPump();
void startOilPump();
void stopOilPump();
void startMixturePump();
void stopMixturePump();
void coilheat();
void coilcool();
void servoUp();
void servoDown();
void coilTwoheat();
void coilTwocool();
void motorUp();
void motorDown();
void delay(int n);

int main(void)
{
    DDRB = 0xF0;
	DDRD = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;
	
	stopBlender();
	stopOilPump();
	stopWaterPump();
	//PORTA |= (1<<PA1);

	
	char c;
	//int i;
	
	Lcd8_Init();
	Lcd8_Clear();
	Lcd8_Set_Cursor(1,0);
	Lcd8_Write_String(" Welcome.... ");
	Lcd8_Set_Cursor(1,17);
	Lcd8_Write_String(" -Level 1- ");
	Lcd8_Set_Cursor(2,0);
	Lcd8_Write_String("Hardware Project ");
	Lcd8_Set_Cursor(2,17);
	Lcd8_Write_String(" Group No.09 ");
	delay(10);
	
	
    while (1) 
    {
		Lcd8_Clear();
		Lcd8_Set_Cursor(1,0);
		Lcd8_Write_String("Press 1 to start");
		delay(2);
		
		while(1){
			c = numberpressed();
			if(c == '1'){
				Lcd8_Clear();
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Start blender");
				startBlender();
				delay(30);
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("Stop blender");
				stopBlender();
				delay(5);
				Lcd8_Set_Cursor(1,16);
				Lcd8_Write_String("Start water pump");
				startWaterPump();
				delay(10);
				Lcd8_Set_Cursor(1,16);
				Lcd8_Write_String("Stop water pump");
				stopWaterPump();
				delay(20);
				Lcd8_Set_Cursor(2,0);
				Lcd8_Write_String("Start oil pump");
				startOilPump();
				delay(10);
				Lcd8_Set_Cursor(2,0);
				Lcd8_Write_String("Stop oil pump");
				stopOilPump();
				delay(20);
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("mixture to h.p:1");
				startMixturePump();
				delay(10);
				Lcd8_Set_Cursor(1,0);
				Lcd8_Write_String("mixture to h.p:1");
				stopMixturePump();
				delay(5);
				Lcd8_Set_Cursor(2,17);
				Lcd8_Write_String("h.p-1 heat");
				coilheat();
				delay(20);
				Lcd8_Set_Cursor(2,17);
				Lcd8_Write_String("h.p-1 cool");
				coilcool();
				delay(20);
				Lcd8_Set_Cursor(1,16);
				Lcd8_Write_String("Servo:1 Up");
				servoUp();
				delay(5);
				Lcd8_Set_Cursor(1,16);
				Lcd8_Write_String("Servo:1 Down");
				servoDown();
				delay(5);
	            Lcd8_Set_Cursor(2,0);
	            Lcd8_Write_String("h.p-2 heat");
	            coilTwoheat();
	            delay(20);		
				Lcd8_Set_Cursor(2,0);
				Lcd8_Write_String("h.p-2 cool");
				coilTwocool();
				delay(20);
				Lcd8_Set_Cursor(2,17);
				Lcd8_Write_String("Servo:2 up");
				motorUp();
				delay(5);
				Lcd8_Set_Cursor(2,17);
				Lcd8_Write_String("Servo:2 Down");
				motorDown();
				delay(5);
				break;
			}
		}
    }
}

void delay(int n){
	int i;
	for(i = 0; i < n ; i++){
		_delay_ms(1000);
	}
}


void startBlender(){
	PORTA &= ~(1<<PA2);
	_delay_ms(1000);
	
}


void stopBlender(){
	PORTA |= (1<<PA2);
	_delay_ms(100);
	
}


void startWaterPump(){
	PORTA &= ~(1<<PA3);
	_delay_ms(10);
	
}

void stopWaterPump(){
	PORTA |= (1<<PA3);
	_delay_ms(100);
	
}


void startOilPump(){
	PORTA &= ~(1<<PA4);
	_delay_ms(2);
}

void stopOilPump(){
	PORTA |= (1<<PA4);
	_delay_ms(10);
	
}

void startMixturePump(){
	PORTA &= ~(1<<PA5);
	_delay_ms(10);
	
}

void stopMixturePump(){
	PORTA |= (1<<PA5);
	_delay_ms(1000);
	
}
void coilheat(){
	PORTA &= ~(1<<PA6);
	_delay_ms(50000);
	
}


void coilcool(){
	PORTA |= (1<<PA6);
	_delay_ms(100);
	
	
}



void servoUp(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0x01;
		_delay_ms(2);
		PORTA = 0x00;
		_delay_ms(18);
	}
}


void servoDown(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0x01;
		_delay_ms(1);
		PORTA = 0x00;
		_delay_ms(19);
	
	}
}

void coilTwoheat(){
	PORTA &= ~(1<<PA7);
	_delay_ms(10000);
	
}


void coilTwocool(){
	PORTA |= (1<<PA7);
	_delay_ms(1000);
	
}

void motorUp(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0x02;
		_delay_ms(2);
		PORTA = 0x00;
		_delay_ms(18);
	}
}


void motorDown(){
	int i;
	for(i=0;i<40;i++){
		PORTA = 0x02;
		_delay_ms(1);
		PORTA = 0x00;
		_delay_ms(19);
	}
}



char numberpressed()
{
	PORTB = 0b10000000;
	if(PINB & (1<<PB0))
	{
		return 'a';
	}
	if(PINB & (1<<PB1))
	{
		return '3';
	}
	if(PINB & (1<<PB2))
	{
		return '2';
	}
	if(PINB & (1<<PB3))
	{
		return '1';
	}
	
	PORTB = 0b01000000;
	if(PINB & (1<<PB0))
	{
		return 'b';
	}
	if(PINB & (1<<PB1))
	{
		return '6';
	}
	if(PINB & (1<<PB2))
	{
		return '5';
	}
	if(PINB & (1<<PB3))
	{
		return '4';
	}
	PORTB = 0b00100000;
	if(PINB & (1<<PB0))
	{
		return 'c';
	}
	if(PINB & (1<<PB1))
	{
		return '9';
	}
	if(PINB & (1<<PB2))
	{
		return '8';
	}
	if(PINB & (1<<PB3))
	{
		return '7';
	}
	PORTB = 0b00010000;
	if(PINB & (1<<PB0))
	{
		return 'd';
	}
	if(PINB & (1<<PB1))
	{
		return '#';
	}
	if(PINB & (1<<PB2))
	{
		return '0';
	}
	if(PINB & (1<<PB3))
	{
		return '*';
	}
}



