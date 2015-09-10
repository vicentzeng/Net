#include "NeuralThread.h"
	NeuralThread::NeuralThread(){
		void  *arg;
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, arg );
		if(ret)
		printf("thread create id:%d", ret);
	}
	NeuralThread::~NeuralThread(){
	}

	void *NeuralThread::procRoutine( void  *arg){
		while(0){
			return 0;
		}
		printf("cmd_thread exit\n");
		usleep(1000);
		return 0;
	}
