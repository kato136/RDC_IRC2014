#include "mbed.h"
#include "QEI.h"


/*DELTA_T used to calculation velosity*/
#define DELTA_T 0.1
#define PI 3.141526
#define course_NUM 1
#define plan_NUM 1

/*put pins*/
/*motor drivers*/
DigitalOut motorR1(p21);
DigitalOut motorR2(p22);
PwmOut motorRpwm(p23);
DigitalOut motorL1(p24);
DigitalOut motorL2(p25);
PwmOut motorLpwm(p26);
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
AnalogIn line1(p15);
AnalogIn line2(p16);
/*PSD sensor*/
AnalogIn PSD1(p17);
AnalogIn PSD2(p18);
/*PSD to check the ball*///not use yet
//AnalogIn PSD3(P19);
//AnalogIn PSD4(P20);
/*led on mbed*/
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);


class robot_status{
	
	private:
		robot_status();
	
	public:
		int width;
		int height;
		int high;
		int weight;
		int wheelwidth;
		int wheel;
		float sensorwidth;
		int gear;
		
		int max_v;
		int max_omega;
		
};