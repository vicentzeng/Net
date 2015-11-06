#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <list>
#include <time.h>
using namespace std;

class CameraThread;
struct NrlCel;
struct NrlAxonNode;
struct NrlAxon;
struct NrlDendrite;
struct NrlRoute;
static int ref_num = 0;
enum NODETYPE{
	IN,
	OUT,
	DOUBLE,
	};
//InPut
struct NrlBranch
{
	NrlAxonNode *belong_to;
	CameraThread *nrlTh;
};

struct NrlAxonNode
{
	NrlAxon *belong_to;
	NrlBranch branch[100];
};

struct NrlAxon
{
	NrlCel *belong_to;
	NrlAxonNode node[100];	//shu
};


//OutPut 100-10000 Synapses per Cell
struct NrlSynapse
{
	unsigned char self_strength;
	CameraThread * nrlTh;
	NrlDendrite *belong_to;
};
struct NrlRoute
{
	unsigned char self_strength;
	NrlDendrite *belong_to;
};
struct NrlDendrite
{
	NrlRoute route;
	NrlSynapse snp[10000];	//zhou
	struct  NrlCel *belong_to;
};


struct NrlCel
{
	CameraThread *nrlTh_belong_to;
	struct NrlAxon nrlaxon;
	struct NrlDendrite nrldendrite;
	NODETYPE type;
	unsigned char action_strength;
	int index;
};

struct TaskNode{
	int time;
	int action;
};

struct MyMsg{
	NrlSynapse *from;
	int type;
	int str;
	};

class CameraThread
{
public:
	CameraThread();
	~CameraThread();
	void initNode( NODETYPE type = DOUBLE);
	bool handleDoubleInfo(MyMsg* msg);
	bool handleInInfo(MyMsg* msg);
	bool handleOutInfo(MyMsg* msg);
	bool dispatchInfo(int info);
	bool sendInfoTo(CameraThread *trg, int str);
	bool tryActiveNode(int str);
	static  void * procRoutine(void *arg);
	static  void * procEvolRoutine(void *arg);
public:
	NrlCel mNode;
	time_t start_time;
	queue <TaskNode> taskqueue;
	queue <MyMsg> infoqueue;
	list <CameraThread*> connqueue;
private:
	pthread_mutex_t th_mtx;
	pthread_cond_t th_cond;
	pthread_t  cmd_thread;
	pthread_t data_thread;
	pthread_t  selfEvol_thread;
};
