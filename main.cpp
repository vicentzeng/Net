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
 #include "NeuralThread.h"
using namespace std;
int main(int argc, char **argv)
{
	cout<<"hello world!"<<endl;
	NeuralThread th;
	for(int i = 0; i< 10; i++){
		cout<<i<<th.cell.nrldendrite.snp[i].self_strength<<endl;
	}
	return 0;
}

