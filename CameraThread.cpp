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
				MyMsg msg = pme->infoqueue.front();
				pme->infoqueue.pop();
				switch(pme->mNode.type){
					case DOUBLE: pme->handleDoubleInfo(&msg); break;
					case IN: pme->handleInInfo(&msg); break;
					case OUT: pme->handleOutInfo(&msg); break;
					default: printf("erro Node Type!"); break;
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

	bool CameraThread::handleDoubleInfo(MyMsg *msg){
		switch (msg->type){
			case 0: {printf("cmd proc:pass msg to all conn\n");
			dispatchInfo(msg->str);} break;
			default:break;
			}
		if (msg->str > mNode.action_strength)
			return true;
		else
			return false;
		}
	bool CameraThread::handleInInfo(MyMsg *msg){
		switch (msg->type){
					case 0: {printf("cmd proc: create and pass msg to all conn\n");
					dispatchInfo(msg->str);} break;
					default:break;
				}
		if (msg->str > mNode.action_strength)
			return true;
		else
			return false;
		}

	bool CameraThread::handleOutInfo(MyMsg *msg){
		switch (msg->type){
					case 0: {
						printf("cmd proc:action\n");
						} break;
					default:break;
				}
		if (msg->str > mNode.action_strength)
			return true;
		else
			return false;
		}
	bool CameraThread::dispatchInfo(int info){
	    for (list<CameraThread*>::iterator it = connqueue.begin(); it != connqueue.end(); ++it)
	    {
			sendInfoTo((CameraThread*)*it, 10);
	    }
		return true;
		}
	bool CameraThread::sendInfoTo(CameraThread *trg, int str){
		MyMsg *msg = new MyMsg();
		msg->type = 0;
		msg->from = NULL;
		msg->str = str;
		trg->infoqueue.push(*msg);
		return true;
		}