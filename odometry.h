#include "course.h"
#include "sensor.h"

/*******************************************************************

�v���O�������̐��l�Ɋւ��Ă͌����̕����ʂ֕ϊ����Čv�Z������̂Ƃ���

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
		int area = 0;		//�X�^�[�g�n�_��0�Ƃ���
		
		
	private:
		
		void Mapping(void);		//���Ȉʒu�Ǝp�����擾����
		void moveArea(void);	//�G���A�̈ړ����m�F����
		
		
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
		
		void control(void);				//����main�œ������֐�
		
	
	private:
		
		void setTargetAreaStatus(void);	//�ڕW�G���A�̍��W���擾
		void areaControl(void);			//�G���A�̌o�H�����s����
		void turn(void);				//���񂷂�
		void avoid(void);				//�ǂ��������
		void drive(void);				//ToDo:���x��pwm�M���ɕϊ��A�o�͂���
	
}