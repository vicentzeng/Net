#include "Reflex.h"
Reflex::Reflex(){
	map = new int[25]{0};

	fl.initNode(IN); //feel
	at.initNode(OUT);//action
	independent_at.initNode(OUT);//action independent
	ps.initNode(DOUBLE);//pass
}
void Reflex::build_conn(){
	fl.connqueue.push_back(&ps);
	//at.connqueue.push_back(&ps);
	//independent_at.connqueue.push_back(&ps);
	//ps.connqueue.push_back(&fl);
	ps.connqueue.push_back(&at);
	ps.connqueue.push_back(&independent_at);
}

void Reflex::run(){
	fl.tryActiveNode(101);
	}
void Reflex::tryRoutine(){
	
	}