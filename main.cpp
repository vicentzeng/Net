/*
 * main.cxx
 * 
 * Copyright 2015 vicent <vicent@vicent-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include "CameraThread.h"
#include "MemManager.h"
#include "Reflex.h"

using namespace std;
int main(int argc, char **argv)
{
	cout<<"hello world!"<<endl;
	//mem detect
	//int64_t memsize = 0;
	//MemManager mgr;
	//memsize = mgr.getMachMemSize();
	//cout << "Total memsize:"<<memsize/1024/1024<<"M"<<endl;
	//alloc
	//int64_t NUM = memsize/3/sizeof(NrlCel);
	//NrlCel *cells = new NrlCel[NUM];
	//memsize = sizeof(NrlCel) * NUM;
	//cout << "size:" << sizeof(NrlCel) << "  "<<memsize/1024/1024<< "M" << endl;
	//alloc th
	//CameraThread *th = new CameraThread[NUM];
	//memsize = sizeof(CameraThread) * NUM;
	//cout << "\nUsed size:" << sizeof(CameraThread) << "  "<<memsize/1024/1024<< "M" << endl;
	//cout << "thread num:" << NUM << endl;
	//usleep(10*1000*1000);
	//Reflex
	Reflex fl;
	fl.build_conn();
	fl.run();
	usleep(10*1000*1000);
	return 0;
}

