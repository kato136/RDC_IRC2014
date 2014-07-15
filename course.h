#include "robot_status.h"


class course{
	
	float xMax;//�S�̂̉���
	float xMin;
	float yMax;//�S�̂̏c��
	float yMin;
	
	course();
	
	
//	course_NUM = 0;//�R�[�X�̐����ݒ�
	
	
	
	struct course_status{
		
		float xMax;
		float xMin;
		float yMax;
		float yMin;
		
		int V;
	};
	
	//�R�[�X�̃X�e�[�^�X���ݒ�{x�͈̔�(����,����),y�͈̔�(����,����),���x}
	struct course_status status[course_NUM];
	
};
