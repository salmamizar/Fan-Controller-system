/******************************************************************************
 *
 *
 * File Name: mini_project3.c
 *
 * Description: source file for the ATmega32 main program
 *
 * Author: Salma Mizar
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "lcd.h"
#include "DcMotor.h"
#include "ADC.h"

int main (void)
{
	uint8 Sensor_Reading;
	ADC_ConfigType MyConfig;
	MyConfig.Prescaler=F_CPU8;
	MyConfig.ReferenceVolatge =internal;
	ADC_init(&MyConfig );
	LCD_init();
	DcMotor_Init();

	while(1)
	{

		Sensor_Reading = LM35_getTemperature();

		if(Sensor_Reading<30)
		{
			/*make the motor stop */
			DcMotor_Rotate(OFF,0);
			LCD_moveCursor(0,0);
			LCD_displayString("Fan is OFF");

		}

		else if (Sensor_Reading>=30 && Sensor_Reading<60)
		{
			/*make the motor rotate clock wise with 25% of the max speed*/
			DcMotor_Rotate(CW,25);
			LCD_moveCursor(0,0);
			LCD_displayString("Fan is ON ");

		}

		else if (Sensor_Reading>=60 && Sensor_Reading<90)
		{
			/*make the motor rotate clock wise with 50% of the max speed*/
			DcMotor_Rotate(CW,50);
			LCD_moveCursor(0,0);
			LCD_displayString("Fan is ON ");

		}

		else if (Sensor_Reading>=90 && Sensor_Reading<120)
		{
			/*make the motor rotate clock wise with 75% of the max speed*/
			DcMotor_Rotate(CW,75);
			LCD_moveCursor(0,0);
			LCD_displayString("Fan is ON ");

		}

		else if (Sensor_Reading>=120)
		{
			/*make the motor rotate clock wise with the max speed*/
			DcMotor_Rotate(CW,100);
			LCD_moveCursor(0,0);
			LCD_displayString("Fan is ON ");

		}


		LCD_moveCursor(1,0);
		LCD_displayString("Temp is:");
		LCD_intgerToString(Sensor_Reading);
		if(Sensor_Reading<100 && Sensor_Reading>9)
		{
			LCD_displayCharacter(' ');
		}
		else if (Sensor_Reading<=9)
		{
			LCD_displayString("  ");
		}
		LCD_moveCursor(1,12);
		LCD_displayCharacter('C');

		/*movr cursor to initial position*/
		LCD_moveCursor(0,0);

	}

	return 0;
}
