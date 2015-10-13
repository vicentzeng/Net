#include "CameraThread.h"
	CameraThread::CameraThread(){
		mNode.action_strength = 0;
		start_time = time(NULL);
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, this );
		int ret1;
		ret1 = pthread_create( &cmd_thread, NULL, procEvolRoutine, this );
		//ref_num = 0;
		ref_num ++;
		printf("\b\b\b\b\b\b%06d", ref_num);
	}
	CameraThread::~CameraThread(){
	}

	void *CameraThread::procRoutine( void  *arg){
		bool is_run = true;
		TaskNode n1;
		time_t cur_time = time(NULL);
		CameraThread *pme = (CameraThread *)arg;
		while(is_run){
			while(!pme->infoqueue.empty()){
				int cmd = pme->infoqueue.front();
				pme->infoqueue.pop();
				switch (cmd){
					case 0: {printf("cmd proc:pass msg to all conn\n");} break;
					default:break;
				}
			}
			return 0;
		}
		usleep(1000*1000);
		ref_num--;
		printf("\b\b\b\b\b\b%06d", ref_num);
		return 0;
	}

	void *CameraThread::procEvolRoutine( void  *arg){
		bool is_run = true;
		TaskNode n1;
		time_t cur_time = time(NULL);
		CameraThread *pme = (CameraThread *)arg;
		while(is_run){
			cur_time = time(NULL);
			while(!pme->taskqueue.empty() && cur_time >= pme->taskqueue.front().time){
				n1 = pme->taskqueue.front();
				pme->taskqueue.pop();
				switch (n1.action){
					case 0:{ printf("task evol\n");};break;
					default :break;
					}
				}
			usleep(1000*1000);
		}
		return 0;
	}

	void CameraThread::initNode( int type){
		mNode.type = type;
		mNode.nrlTh_belong_to = this;
	}

	void CameraThread::handleInfo(){
		
		}