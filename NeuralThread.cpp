#include "NeuralThread.h"
	NeuralThread::NeuralThread(){
		void  *arg;
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, arg );
		//ref_num = 0;
		ref_num ++;
		printf("\b\b\b\b\b\b%06d", ref_num);
	}
	NeuralThread::~NeuralThread(){
	}

	void *NeuralThread::procRoutine( void  *arg){
		while(0){
			return 0;
		}
		usleep(1000*1000);
		ref_num--;
		printf("\b\b\b\b\b\b%06d", ref_num);
		return 0;
	}

	void NeuralThread::initNode( int type){
		mNode.type = type;
		mNode.nrlTh_belong_to = this;
	}