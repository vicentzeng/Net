#include "CameraThread.h"
	CameraThread::CameraThread(){
		mNode.action_strength = 0;
		void  *arg;
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, arg );
		int ret1;
		ret1 = pthread_create( &cmd_thread, NULL, procEvolRoutine, arg );
		//ref_num = 0;
		ref_num ++;
		printf("\b\b\b\b\b\b%06d", ref_num);
	}
	CameraThread::~CameraThread(){
	}

	void *CameraThread::procRoutine( void  *arg){
		bool is_run = true;
		while(is_run){
			return 0;
		}
		usleep(1000*1000);
		ref_num--;
		printf("\b\b\b\b\b\b%06d", ref_num);
		return 0;
	}

	void *CameraThread::procEvolRoutine( void  *arg){
		bool is_run = true;
		while(is_run){
			usleep(1000*1000);
		}
		return 0;
	}

	void CameraThread::initNode( int type){
		mNode.type = type;
		mNode.nrlTh_belong_to = this;
	}
