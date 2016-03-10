#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "CameraThread.h"
class Reflex{
public:
	Reflex();
	void build_conn();
	void run();
	void tryRoutine();
private:
	int *map;
	CameraThread fl; //feel
	CameraThread at;//action
	CameraThread independent_at;//action independent
	CameraThread ps;//pass
};
