#include "mbed.h"


class course{
	
	float xMax = 0.0;//�S�̂̉���
	float xMin = 0.0
	float yMax = 0.0;//�S�̂̏c��
	float yMin = 0.0;
	
	
//	course_NUM = 0;//�R�[�X�̐���ݒ�
	
	
	
	struct status[course_NUM]{
		
		float xMax = 0.0;
		float xMin = 0.0;
		float yMax = 0.0;
		float yMin = 0.0;
		
		int V = 0;
	}
	
	//�R�[�X�̃X�e�[�^�X��ݒ�{x�͈̔�(���,����),y�͈̔�(���,����),���x}
	status[0] = {0.0,0.0,0.0,0.0,0};
	
}