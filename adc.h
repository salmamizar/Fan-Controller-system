 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Salma Mizar
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                               types declaration                             *
 *******************************************************************************/
typedef enum
{
F_CPU1 ,F_CPU2 ,F_CPU4 ,F_CPU8 ,F_CPU16 ,F_CPU32 ,F_CPU64 ,F_CPU128
}ADC_Prescaler;

typedef enum
{
AREF,AVCC,Reversed,internal
}ADC_ReferenceVolatge;

typedef struct
{
	ADC_Prescaler Prescaler;
	ADC_ReferenceVolatge ReferenceVolatge;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
