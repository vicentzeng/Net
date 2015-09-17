#include "MemManager.h"
int64_t MemManager::getMachMemSize(){
	int64_t memsize = 0;
	for (int64_t i = 0;;i+=10){
		int *pt = (int *)malloc(1024 * 1024 *i);
		if(pt != NULL){
			memsize = 1024 * 1024 *i;
			free(pt);
		}else
			break;
	}
	return memsize;
	}
