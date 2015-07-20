#include <iostream>
struct NrlCel
{
};
//InPut
struct NrlAxon
{	
};
struct NrlNode
{
};
struct NrlBranch
{
};
//OutPut 100-10000 Synapses per Cell
struct NrlDendrite
{
};
struct NrlRoute
{
};
struct NrlSynapse
{
};
class NeuralThread
{
public:

	NeuralThread();
	~NeuralThread();
private:
	NrlInput input;
	NrlOutput output;
	NrlCel cell;
	NrlRoute route;
};