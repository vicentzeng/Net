#include <iostream>

struct NrlInput
{
	
};

struct NrlOutput
{
	
};

struct NrlCel
{
	
};

struct NrlRoute
{

};

struct NrlNode
{
	
};

struct NrlBranch
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