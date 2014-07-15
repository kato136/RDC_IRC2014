#include "robot_status.h"



/*get encorder signal*/
QEI rightWheel(p5 , p6 , NC , 100);
QEI leftWheel(p7 , p8 , NC , 100);

class sensor{
	
	
	public:
	unsigned short wallR;//length from right wall
	unsigned short wallL;//length from left wall
	
	unsigned short lnR;
	unsigned short lnL;
	
	int LR;		//length ran right wheel([0])(mm)
	int LL;		//length ran left wheel([0])(mm)
	int L0;		//length ran center between wheels([0])(mm)
	int L;		//length ran the top of robot([0])(mm)
	int theta;	//turn angle([0])(rad)
	
	public:
		void sonsor(void);     //get the sensor values
	
	private:
		void wall(short,short);	//transform the PSD values to physical values
		void values(int,int); //transform the encorder values to physical values
		void length0(void);		//get L0 from LR&LL
		void length(void);		//get L from L0&theta
		void theta(void);		//get theta from LR&LL
	
};


