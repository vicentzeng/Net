#include "NeuralThread.h"
	NeuralThread::NeuralThread(){
		void  *arg;
		int ret;
		printf("New NeuralThread\n");
		ret = pthread_create( &cmd_thread, NULL, procRoutine, arg );
	}
	NeuralThread::~NeuralThread(){
	}

	void *NeuralThread::procRoutine( void  *arg){
		while(0){
			return 0;
		}
		usleep(100*1000);
		printf("NeuralThread exit\n");
		return 0;
	}
