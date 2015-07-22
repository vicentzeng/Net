#include "NeuralThread.h"
	NeuralThread::NeuralThread(){
		void  *arg;
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, arg );
	}
	NeuralThread::~NeuralThread(){
	}

	void *NeuralThread::procRoutine( void  *arg){
		while(0){
			return 0;
		}
		printf("cmd_thread exit\n");
		return 0;
	}