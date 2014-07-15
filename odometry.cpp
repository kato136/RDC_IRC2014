#include "odometry.h"




void odometry :: Mapping(void){
	
	theta += sen.theta - sen.theta;
	if(theta = 2.0*PI){
		theta = 0.0;
	}else if(theta < 0.0){
		theta += 2.0*PI;
	}
	
	x += (sen.L - sen.L) * cos(theta);
	y += (sen.L - sen.L) * sin(theta);
	
}

void odometry :: moveArea(void){
	
	int i;
	
	//エリアの移動をチェック
	for(i = 0 ; i <= cou.course_NUM ; i++){
		
		if(x > cou.status[i].xMin && x < cou.status[i].xMax){
			xFlg[i] = true;
		}else{
			xFlg[i] = false;
		}
		
		if(y > cou.status[i].yMin && y < cou.status[i].yMax){
			yFlg[i] = true;
		}else{
			yFlg[i] = false;
		}
		
		if(xFlg[i] && yFlg[i]){
			area = i;
		}
	}
}


/*control class*/

void control :: setTargetAreaStatus(void){
	
	xTargetAreaMax = cou.status[targetArea].xMax;
	xTargetAreaMin = cou.status[targetArea].xMin;
	yTargetAreaMax = cou.status[targetArea].yMax;
	yTargetAreaMin = cou.status[targetArea].yMin;
}

//経路計画
void control :: areaControl(void){
	
	int plan[plan_NUM] = {};//移動するエリアの順番を設定
	
	int i = 0;
	int targetArea = plan[i];
	
	setTargetAreaStatus();
	
	//機体が目標区間に入ったらプランを進める
	if(xFlg[targetArea] && yFlg[targetArea]){
		
		i++;
	}
	
	//エリア外の位置にいる場合の機体の目標地点を設定
	if(!xFlg[targetArea]){
		
		if(x > xTargetAreaMax){
			
			xTarget = xTargetAreaMax;
			
		}else if(x < xTargetAreaMin){
			
			xTarget = xTargetAreaMin;
			
		}
		
	}else{
		
		xTarget = x;
		
	}
	
	
	if(!yFlg[targetArea]){
		
		if(y > yTargetAreaMax){
			
			yTarget = yTargetAreaMax;
			
		}else if(y < yTargetAreaMin){
			
			yTarget = yTargetAreaMin;
			
		}
		
	}else{
		
		yTarget = y;
		
	}
	
	thetaTarget = atan(yTarget,xTarget);
	V = cou.status[i].V;
	
	moveArea();
	
}

void control :: turn(void){
	
	if(theta != thetaTarget){
		
		omega = robo.max_omega;
		
	}else{
		
		omega = 0;
		
	}
	
}

void control :: avoid(void){
	
	if(wallR < (robo.width / 2.0)){
		
		if((theta >= 0.0) || (theta < (PI / 2.0))){
			
			thetaTarget = 0.0;
			
		}else if((thea >= (PI / 2.0)) || (theta < PI)){
			
			thetaTarget = PI / 2.0;
			
		}else if((theta >= PI) || (theta < (PI * 3.0 / 2.0))){
			
			thetaTarget = PI;
			
		}else if((theta >= (PI * 3.0 / 2.0))){
			
			thetaTarget = PI * 3.0 / 2.0;
			
		}
	}else if(wallL < (robo.width / 2.0)){
		
		if((theta <= (PI * 2.0)) || (theta > (PI * 3.0 / 2.0))){
			
			thetaTarget = PI * 2.0;
			
		}else if((theta <= (PI * 3.0 / 2.0)) || (theta > PI)){
			
			thetaTarget = PI * 3.0 / 2.0;
			
		}else if((theta <= PI) || (theta > (PI / 2.0))){
			
			thetaTarget = PI;
			
		}else if(theta <= (PI / 2.0)){
			
			thetaTarget = PI / 2.0;
			
		}
	}
}

void control :: control(void){
	
	sen.sensor();
	Mapping();
	areaControl();
	
	V0 = (int)sqrt(pow(V,2.0) - pow(robo.height * omega,2.0));
	
	VR = V0 + ((int)robo.width / 2) * (int)omega;
	VL = V0 - ((int)robo.width / 2) * (int)omega;
	
	avoid();
	turn();
	
}

void drive(void){
	
	
	
}