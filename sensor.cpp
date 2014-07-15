#include "sensor.h"
robot_status robo;


/*sensor class*/

void sensor :: sensor(void){
	
	unsigned short psdR;
	unsigned short pedL;
	
	int enR = 0;
	int enL = 0;
	
	psdR = psd1.read_u16 >> 4;
	psdL = psd2.read_u16 >> 4;
	
	lnR = line1.read_u16 >> 4;
	lnL = line2.read_u16 >> 4;
	
	enR = rightWheel.getPulses();
	enL = leftWheel.getPulses();
	
	wall(psdR,psdL);
	values(enR,enL);
}


void sensor :: wall(short r,short l){
	wallR = (10138 / (r - 911)) + 6;//cm
	wallR = wallR * cos(PI / 4.0) * 10;//mm
	wallL = (10138 / (l - 911)) + 6;//cm
	wallL = wallL  * cos(PI / 4.0) * 10;//mm
	
}

void sensor :: values(int r,int l){
	
	
	LR = ((r / 1673) / robo.gear) * PI * wheel;//mm
	LL = ((l / 1673) / robo.gear) * PI * wheel;//mm
	
	L0 = length0();//mm
	
	L = length();//mm
	
	theta = theta();//rad
	
}

void sensor :: length0(void){
	
	L0 = (LL + LR) / 2;
}

void sensor :: length(void){
	float _L;
	_L = sqrt(pow((float)L0,2.0) + pow((float)robo.height * (float)theta,2.0));
	
	L = (int)_L;

void sensor :: theta(void){
	
	theta = (LL - LR) / robo.width;
}

