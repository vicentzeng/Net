#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <queue>

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
	NrlAxonNode node[100];
};


//OutPut 100-10000 Synapses per Cell
struct NrlSynapse
{
	char self_strength;
	CameraThread * nrlTh;
	NrlDendrite *belong_to;
};
struct NrlRoute
{
	char self_strength;
	NrlDendrite *belong_to;
};
struct NrlDendrite
{
	NrlRoute route;
	NrlSynapse snp[10000];
	struct  NrlCel *belong_to;
};


struct NrlCel
{
	CameraThread *nrlTh_belong_to;
	struct NrlAxon nrlaxon;
	struct NrlDendrite nrldendrite;
	unsigned char type;
	unsigned char action_strength;
};

class CameraThread
{
public:
	CameraThread();
	~CameraThread();
	void initNode( int type = DOUBLE);
	static  void * procRoutine(void *arg);
	static  void * procEvolRoutine(void *arg);
public:
	NrlCel mNode;
private:
	pthread_mutex_t th_mtx;
	pthread_cond_t th_cond;
	pthread_t  cmd_thread;
	pthread_t data_thread;
	pthread_t  selfEvol_thread;
};
