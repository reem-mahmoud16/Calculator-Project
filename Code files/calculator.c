/*
 * calculator.c
 *
 * Created: 9/29/2022 12:06:27 AM
 *  Author: HP.SXH08
 */ 


#include <avr/io.h>
#include "LCD.h"
#include "LCD_config.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <avr/delay.h>

unsigned char num1,num2,x;
int result;
char op;
int main(void)
{
	LCD_vInit();
	keypad_vInit();
    while(1)
    {
		LCD_clearscreen();
		 
         while(keypad_u8check_press()==NOTPRESSED);
		 LCD_vSend_char(keypad_u8check_press());
		 num1= (keypad_u8check_press()-48)*10;
		 _delay_ms(1000);
		 while(keypad_u8check_press()==NOTPRESSED);
		 num1 += keypad_u8check_press() -48;
		 LCD_vSend_char(keypad_u8check_press());
		 _delay_ms(1000);
		 
		 
		 
		 while(keypad_u8check_press()==NOTPRESSED);
		 op= keypad_u8check_press();
		 LCD_vSend_char(keypad_u8check_press());
		 _delay_ms(1000);
		 
		 if(op !='+' && op!= '-' && op!='*' && op!='/')
		 {
			 LCD_clearscreen();
			 LCD_vSend_string("wrong operation");
			 LCD_movecursor(2,3);
			 LCD_vSend_string("selected!");
			 
			 while(keypad_u8check_press() != 'A')
			 {
				 while(keypad_u8check_press()==NOTPRESSED);
			 }
			 _delay_ms(500);
		 }
		 else
		 {
			 while(keypad_u8check_press()==NOTPRESSED);
			 LCD_vSend_char(keypad_u8check_press());
			 num2= (keypad_u8check_press()-48)*10;
			 _delay_ms(1000);
			 while(keypad_u8check_press()==NOTPRESSED);
			 num2 += keypad_u8check_press() -48;
			 LCD_vSend_char(keypad_u8check_press());
			 _delay_ms(1000);
			 
			 if(op == '+')
			 {
				 result = num1 + num2;
				 while(keypad_u8check_press() != '=')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 LCD_vSend_char('=');
				 LCD_vSend_char(((char)result/100)+48);
				 result %= 100;
				 LCD_vSend_char(((char)result/10)+48);
				 LCD_vSend_char(((char)result%10)+48);
				 
				 while(keypad_u8check_press() != 'A')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 _delay_ms(500);
				 
			 }
			 else if(op == '-')
			 {
				 if(num1>=num2)
				 {
					 result = num1 - num2;
					 while(keypad_u8check_press() != '=')
					 {
						 while(keypad_u8check_press()==NOTPRESSED);
					 }
					 LCD_vSend_char('=');
					 LCD_vSend_char((result/100)+48);
					 result %= 100;
					 LCD_vSend_char((result/10)+48);
					 LCD_vSend_char((result%10)+48);
					 
					 while(keypad_u8check_press() != 'A')
					 {
						 while(keypad_u8check_press()==NOTPRESSED);
					 }
					 _delay_ms(500);
				 }
				 else
				 {
					 result = num2 - num1;
					 while(keypad_u8check_press() != '=')
					 {
						 while(keypad_u8check_press()==NOTPRESSED);
					 }
					 LCD_vSend_char('=');
					 LCD_vSend_char('-');
					 LCD_vSend_char((result/100)+48);
					 result %= 100;
					 LCD_vSend_char((result/10)+48);
					 LCD_vSend_char((result%10)+48);
					 
					 while(keypad_u8check_press() != 'A')
					 {
						 while(keypad_u8check_press()==NOTPRESSED);
					 }
					 _delay_ms(500);
				 }
				 
			 }
			 else if(op == '*')
			 {
				 result = num1 * num2;
				 while(keypad_u8check_press() != '=')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 LCD_vSend_char('=');
				 LCD_vSend_char((result/1000)+48);
				 result %= 1000;
				 LCD_vSend_char((result/100)+48);
				 result %= 100;
				 LCD_vSend_char((result/10)+48);
				 LCD_vSend_char((result%10)+48);
				 
				 while(keypad_u8check_press() != 'A')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 _delay_ms(500);
			 }
			 else if(op == '/')
			 {
				 result = num2 / num1;
				 while(keypad_u8check_press() != '=')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 LCD_vSend_char('=');
				 LCD_vSend_char((result/10)+48);
				 LCD_vSend_char((result%10)+48);
				 
				 while(keypad_u8check_press() != 'A')
				 {
					 while(keypad_u8check_press()==NOTPRESSED);
				 }
				 _delay_ms(500);
			 }
			 
		 }
		 
		 
    }
}