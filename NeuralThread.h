#include <iostream>
#include <stdio.h>
#include <pthread.h>
class NeuralThread;
struct NrlCel;
struct  NrlAxonNode;
struct  NrlAxon;
struct NrlDendrite;
struct NrlRoute;

//InPut
struct NrlBranch
{
	NrlAxonNode *belong_to;
	NeuralThread *nrlTh;
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
	int self_strength;
	NeuralThread * nrlTh;
	NrlDendrite *belong_to;
};
struct NrlRoute
{
	int self_strength;
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
	NeuralThread *nrlTh_belong_to;
	struct NrlAxon nrlaxon;
	struct NrlDendrite nrldendrite;
};

class NeuralThread
{
public:
	NeuralThread();
	~NeuralThread();
	static  void * procRoutine(void *arg);
public:
	NrlCel cell;
	pthread_t  cmd_thread;
	pthread_t data_thread;
};