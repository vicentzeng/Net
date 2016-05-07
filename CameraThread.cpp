#include "CameraThread.h"
	CameraThread::CameraThread(){
		mNode.action_strength = 100;
		mNode.nrldendrite.route.self_strength = 100;
		start_time = time(NULL);
		int ret;
		ret = pthread_create( &cmd_thread, NULL, procRoutine, this );
		int ret1;
		ret1 = pthread_create( &cmd_thread, NULL, procEvolRoutine, this );
		//ref_num = 0;
		mNode.index = ref_num;
		ref_num ++;
		//printf("\b\b\b\b\b\b%06d", ref_num);
		printf("Thread create%d", ref_num);
	}
	CameraThread::~CameraThread(){
	}

//process

	void *CameraThread::procRoutine( void  *arg){
		bool is_run = true;
		TaskNode n1;
		time_t cur_time = time(NULL);
		CameraThread *pme = (CameraThread *)arg;
		while(is_run){
			//printf("Thread%d loop\n", pme->mNode.index);
			while(!pme->infoqueue.empty()){
				MyMsg msg = pme->infoqueue.front();
				pme->infoqueue.pop();
				switch(pme->mNode.type){
					case DOUBLE: pme->handleDoubleInfo(&msg); break;
					case IN: pme->handleInInfo(&msg); break;
					case OUT: pme->handleOutInfo(&msg); break;
					default: printf("erro Node Type!\n"); break;
					}
			}
			usleep(20*1000);
			//return 0;
		}
		ref_num--;
		printf("\b\b\b\b\b\b%06d", ref_num);
		return 0;
	}

//process Event
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
			usleep(20*1000);
		}
		return 0;
	}

	void CameraThread::initNode( NODETYPE type){
		mNode.type = type;
		mNode.nrlTh_belong_to = this;
	}

	bool CameraThread::handleDoubleInfo(MyMsg *msg){
		switch (msg->type){
			case 0: {
				if (msg->str > mNode.action_strength){
					unsigned char tri_val = msg->str * 125 /100;
					printf("cel:%d trigger tri_val:%d msgval:%d create and pass msg to all conn\n", mNode.index, tri_val, msg->str);
					dispatchInfo(tri_val);
				}
			} break;
			default:break;
			}
		if (msg->str > mNode.action_strength)
			return true;
		else
			return false;
		}
	bool CameraThread::handleInInfo(MyMsg *msg){
		switch (msg->type){
			case 0: {
				if (msg->str > mNode.action_strength){
					unsigned char tri_val = msg->str * 125 /100;
					printf("cel trigger tri_val:%d msgval:%d create and pass msg to all conn\n", tri_val, msg->str);
					dispatchInfo(msg->str);
				}
			} break;
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
		unsigned char cal_str;
		cal_str = info * (mNode.nrldendrite.route.self_strength/2 + 50)/100;	//50+-50
	    for (list<CameraThread*>::iterator it = connqueue.begin(); it != connqueue.end(); ++it)
	    {
			sendInfoTo((CameraThread*)*it, cal_str);
			printf("dispatchInfo cal_str:%d\n", cal_str);
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
	bool CameraThread::tryActiveNode(int str){
		MyMsg *msg = new MyMsg();
		msg->type = 0;
		msg->from = NULL;
		msg->str = str;
		infoqueue.push(*msg);
		return true;
		}