#include "Reflex.h"
Reflex::Reflex(){
	fl.initNode(IN); //feel
	at.initNode(OUT);//action
	independent_at.initNode(OUT);//action independent
	ps.initNode(DOUBLE);//pass
}
