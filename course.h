#include "mbed.h"


class course{
	
	float xMax = 0.0;//全体の横幅
	float xMin = 0.0
	float yMax = 0.0;//全体の縦幅
	float yMin = 0.0;
	
	
//	course_NUM = 0;//コースの数を設定
	
	
	
	struct status[course_NUM]{
		
		float xMax = 0.0;
		float xMin = 0.0;
		float yMax = 0.0;
		float yMin = 0.0;
		
		int V = 0;
	}
	
	//コースのステータスを設定{xの範囲(上限,下限),yの範囲(上限,下限),速度}
	status[0] = {0.0,0.0,0.0,0.0,0};
	
}