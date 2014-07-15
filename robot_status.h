#include "mbed.h"
#include "QEI.h"


/*DELTA_T used to calculation velosity*/
#define DELTA_T 0.1
#define PI 3.141526
#define course_NUM 0
#define plan_NUM 0

/*put pins*/
/*motor drivers*/
DigitalOut motorR1(P21);
DigitalOut motorR2(P22);
PmwOut motorRpwm(P23);
DigitalOut motorL1(P24);
DigitalOut motorL2(P25);
PmwOut motorLpwm(P26);
/*servo motor*///not use yet
//Serial servo1(P27);
//Serial servo2(P28);
/*gear motor*///not use yet
//DigitalOut motorG1(P29);
//DigitalOut motorG2(P30);
/*encorder*/
/*use
	right:p5,p6
	left:p7,p8
*/
/*fan motor*///not use yet
//DigitalOut motorF1(P9);
//DigitalOut motorF2(P10);
/*coloe sensor*///not use yet
//DigitalIn color1(P11);
//DigitalIn color2(P12);
//DigitalIn color3(P13);
//DigitalIn color4(P14);
/*line sensor*/
AnalogIn line1(P15);
AnalogIn line2(P16);
/*PSD sensor*/
AnalogIn PSD1(P17);
AnalogIn PSD2(P18);
/*PSD to check the ball*///not use yet
//AnalogIn PSD3(P19);
//AnalogIn PSD4(P20);
/*led on mbed*/
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


class robot_status{
	
	
	int width = 260;//mm
	int height = 320;//mm
	int high = 0;//mm
	int weight = 0;//kg
	int wheelwidth = 200;//mm
	int wheel = 50;//mm
	float sensorwidth = 4.5;//mm
	int gear = 18;
	
	int max_v = 0;//mm/s
	int max_omega = 0;//rad/s
}