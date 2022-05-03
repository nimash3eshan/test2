/*
* main.c
*
* Created: 11/20/2021 11:23:38 p. m.
* Author : Group 30
*/


//Libraries used in the Project
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#define F_CPU 1600000UL

//-----------------------------Custom Header Files---------------------------------

//Keypad
#include "keypad.h"
//Tray Pusher
#include "Stepper_motors.h"
//Mixer
#include "dc.h"
//pH Sensor
#include "adc.h"
//AC Motor
#include "ToRelay.h"
//Ultrasonic Sensor
#include "sensor.h"
//IR Sensor
#include "IRSensor.h"
//Flow Sensor
#include "flowsensor.h"
//Display
#include "lcd_func.h"

//Global Variables
float   w_vol;
float	l_vol;
float	a_vol;

int main(void)
{
		
	//Main Program Loop
	
	while(1){
		//------------------------------display on-----------------------------------
		wlcm_msg();
		int num_trays = num_tray();
		int vol = tray_vol();
		

		//------------------------------ultrasonic-----------------------(In progress)
		ultrasonic1();	//activate ultrasonic sensor in the water tank
		if (!depth())	// Display a message if the liquid is empty
		{
		}
		
		
		ultrasonic2();	//activate ultrasonic sensor in the acid tank
		if (!depth())	// Display a message if the liquid is empty
		{
		}
		
		
		ultrasonic3();	//activate ultrasonic sensor in the latex tank
		if (!depth())	// Display a message if the liquid is empty
		{
		}
		
		
		//----------------------------------ph sensor--------------------------(in progress)
		
		ADC_Init();
		
		ADC_Read('B');
		//calculate the volume of water,latex and acid needed
		
		//----------------------------calculation for ph value------------------------
		
		//--------------------------------conveyor start------------------------------
		
		switchOn();	//activate the relay switch to the AC motor
		
		//---------------------------------stepper push-------------------------------
		
		stprTrayPsh_init();	// initialize the stepper motors
		stprTrayPsh_clk(2);	// rotate the stepper motors to push the tray onto the conveyor
		
		//--------------------------------Ir detector---------------------------------
		
		while(1){
			if (act_IR())		//if the IR function returns a true value the conveyor will stop
			{
				switchOff();
				break;
			}
		}
		
		//--------------------------------stepper pull--------------------------------
		
		stprTrayPsh_init();	// initialize the stepper motors
		stprTrayPsh_aclk(2);// rotate the stepper motors to pull the handle

		
		//----------------------------tray holder down (mixer)----------------------------
		
		stprMix_init(); //initiate the stepper motor
		stprMix_clk(2);	// rotate the stepper motor to lower the mixer
		
		//----------------------------liquid pumps {flow sensor}--------------------------
		pump_w(w_vol);
		pump_l(l_vol);
		pump_a(a_vol);
		
		//---------------------------------DC motor (Mixer)-------------------------------
		acvt_mixer();
		
		//------------------------------tray holder up (mixer)----------------------------
		
		stprMix_init();//initiate the stepper motor
		stprMix_aclk(2);// rotate the stepper motor to lower the mixer;
		
		//------------------------------conveyor belt start-------------------------------
		switchOn();
	}
	
}



