#include <iostream>
struct NrlCel
{
	NeuralThread *nrlTh_belong_to;
	NrlAxon nrlaxon;
	NrlDendrite nrldendrite;
};
//InPut
struct NrlAxon
{
	NrlCel *belong_to;
	NrlBranch[100];
};
struct NrlAxonNode
{
	NrlBranch[100];
	NrlAxon *belong_to;
};
struct NrlBranch
{
	NrlAxonNode *belong_to;
	NeuralThread *nrlTh;
};
//OutPut 100-10000 Synapses per Cell
struct NrlDendrite
{
	NrlCel *belong_to;
};
struct NrlRoute
{
	NrlDendrite *belong_to;
	NrlSynapse[10000];
};
struct NrlSynapse
{
	int self_strength;
	NeuralThread * nrlTh;
	NrlRoute *belong_to;
};

class NeuralThread
{
public:
	NeuralThread();
	~NeuralThread();
private:
	NrlCel cell;
};