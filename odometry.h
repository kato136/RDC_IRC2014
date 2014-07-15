#include "course.h"
#include "sensor.h"

/*******************************************************************

プログラム中の数値に関しては現実の物理量へ変換して計算するものとする

********************************************************************/



class odometry{
	
	course cou;
	sensor sen;
	robot_status robo;
	
	/*values*/
	public:
		
		float x = 0.0;
		float y = 0.0;
		float theta = 0.0;
		int area = 0;		//スタート地点を0とする
		
		
	private:
		
		void Mapping(void);		//自己位置と姿勢を取得する
		void moveArea(void);	//エリアの移動を確認する
		
		
}



/*control class*/
class control extends odometry{
	
	public:
		
		float xTarget = 0.0;
		float yTarget = 0.0;
		float thetaTarget = 0.0;
		
		int VR = 0;
		int VL = 0;
		int V0 = 0;
		int V = 0;
		int omega = 0;
		
	
	private:
		
		float xTargetAreaMax = 0.0;
		float xTargetAreaMin = 0.0;
		float yTargetAreaMax = 0.0;
		float yTargetAreaMin = 0.0;
		
		bool xFlg[cou.course_NUM];
		bool yFlg[cou.course_NUM];
		
	
	public:
		
		void control(void);				//直接mainで動かす関数
		
	
	private:
		
		void setTargetAreaStatus(void);	//目標エリアの座標を取得
		void areaControl(void);			//エリアの経路を実行する
		void turn(void);				//旋回する
		void avoid(void);				//壁を回避する
		void drive(void);				//ToDo:速度をpwm信号に変換、出力する
	
}