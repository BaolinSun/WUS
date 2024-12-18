#include <stdio.h>
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpiops.h"
#include "xstatus.h"

#define GPIO_DEVICE_ID	XPAR_XGPIOPS_0_DEVICE_ID

#define LED0 	54
#define LED1 	55
#define LED2 	56

XGpioPs Gpio;

int main(void)
{
	int status = 0;
	XGpioPs_Config *ConfigPtr;

	xil_printf("Hello World!\n");

	ConfigPtr = XGpioPs_LookupConfig(GPIO_DEVICE_ID);
	status = XGpioPs_CfgInitialize(&Gpio, ConfigPtr, ConfigPtr->BaseAddr);
	if(status != XST_SUCCESS){
		return XST_FAILURE;
	}

	XGpioPs_SetDirectionPin(&Gpio, LED0, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, LED0, 1);
	XGpioPs_SetDirectionPin(&Gpio, LED1, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, LED1, 1);
	XGpioPs_SetDirectionPin(&Gpio, LED2, 1);
	XGpioPs_SetOutputEnablePin(&Gpio, LED2, 1);

	while(1)
	{
		XGpioPs_WritePin(&Gpio, LED0, 0);
		XGpioPs_WritePin(&Gpio, LED1, 0);
		XGpioPs_WritePin(&Gpio, LED2, 0);
		sleep(1);
		XGpioPs_WritePin(&Gpio, LED0, 1);
		XGpioPs_WritePin(&Gpio, LED1, 1);
		XGpioPs_WritePin(&Gpio, LED2, 1);
		sleep(1);

	}


	return 0;
}
