#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "NeuralThread.h"
class Reflex{
public:
	Reflex();
private:
	NeuralThread fl; //feel
	NeuralThread at;//action
	NeuralThread independent_at;//action independent
	NeuralThread ps;//pass
};