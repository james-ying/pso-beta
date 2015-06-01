//============================================================================
// Name        : psocopy.cpp
// Author      : Jamesy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * main.cpp
 *
 *  Created on: 2015��4��14��
 *      Author: lenovo
 */
#include "PSO.h"
#include "LPSO.h"
#include "GPSO.h"
#include "SFPSO.h"
#include "CLPSO.h"
#include "SFCLPSO.h"
#include "FIPSO.h"
#include "HCLPSO.h"
#include "GraphOperation.h"
#include <ctime>
#include<iostream>
#include<cmath>
#include "Function.h"
using namespace std;
int main()
{
	srand((unsigned)time(NULL));

	int N, DIM, GEN, index = 0, times;
	int m0, m, t;

	m0=4; m=4; t=36;
	N=m0+t; DIM=30; GEN=8000; times=50;
	clock_t start,stop;
	int time;
//==================================
//components
//==================================
//	cout<<"Now LPSO"<<endl;
//	start=clock();
//	LPSO lpso(N, DIM, GEN, index, times);
//	for(int index=1; index<=6; index+=5){
//		start=clock();
//		lpso.index = index;
//		lpso.Run();
////		pso->index=index;
////		pso->Run();
//		lpso.LearnMat.OutputIG(index, "LPSO");
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}

//	cout<<"Now FIPSO"<<endl;
//	start=clock();
//	FIPSO fipso(N, DIM, GEN, index, times);
//	for(int index=1; index<=6; index+=5){
//		start=clock();
//		fipso.index = index;
//		fipso.Run();
////		pso->index=index;
////		pso->Run();
////		sfclpso.LearnMat.OutputIG(index, "CLPSO");
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}

//	cout<<"Now CLPSO"<<endl;
//	start=clock();
//	CLPSO clpso(N, DIM, GEN, index, times);
//	for(int index=1; index<=6; index+=5){
//		start=clock();
//		clpso.index = index;
//		clpso.Run();
////		pso->index=index;
////		pso->Run();
//		clpso.LearnMat.OutputIG(index, "CLPSO");
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
//
//	cout<<"Now SFPSO"<<endl;
//	start=clock();
//	SFPSO sfpso(m0, m, t, DIM, GEN, index, times, "SFPSO");
////	SFCLPSO sfclpso(m0, m, t, DIM, GEN, index, times);
//	for(int index=1; index<=6; index+=5){
//		start=clock();
//		sfpso.index = index;
//		sfpso.Run();
////		pso->index=index;
////		pso->Run();
//		sfpso.LearnMat.OutputIG(index, "SFPSO");
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
//
//	cout<<"Now SFCLPSO"<<endl;
//	start=clock();
//	SFCLPSO sfclpso(m0, m, t, DIM, GEN, index, times);
//	for(int index=1; index<=6; index+=5){
//		start=clock();
//		sfclpso.index = index;
//		sfclpso.Run();
////		pso->index=index;
////		pso->Run();
//		sfclpso.LearnMat.OutputIG(index, "SFCLPSO");
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
//==================================
//fitness
//==================================
//	cout<<"Now GPSO"<<endl;
////	start=clock();
//	GPSO gpso(N, DIM, GEN, index, times);
//	InitCompoFunc(DIM);
//	for(int index=6; index<=7; index++){
//		start=clock();
//		gpso.index=index;
//		gpso.Run();
//		stop=clock();
//		time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
//	stop=clock();
//	time=(stop-start)/CLOCKS_PER_SEC;
//	std::cout<<"Total used "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//
//	cout<<"Now LPSO"<<endl;
//	LPSO lpso(N, DIM, GEN, index, times);
//	InitCompoFunc(DIM);
//	for(int index=12; index<=14; index++){
//		start=clock();
//		lpso.index=index;
//		lpso.Run();
//		stop=clock();
//		time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}

//	cout<<"Now FIPSO"<<endl;
//	FIPSO fipso(N, DIM, GEN, index, times);
//	InitCompoFunc(DIM);
//	for(int index=14; index<=14; index++){
//		start=clock();
//		fipso.index = index;
//		fipso.Run();
//		stop=clock();
//		time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}

//	cout<<"Now SFPSO"<<endl;
//	start=clock();
//	SFPSO sfpso(m0, m, t, DIM, GEN, index, times, "SFPSO");
//	InitCompoFunc(DIM);
//	for(int index=12; index<=14; index++){
//		start=clock();
//		sfpso.index=index;
//		sfpso.Run();
//		stop=clock();
//		time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
////
//	cout<<"Now CLPSO"<<endl;
//	start=clock();
//	CLPSO clpso(N, DIM, GEN, index, times);
//	InitCompoFunc(DIM);
//	for(int index=17; index<=17; index++){
//		start=clock();
//		clpso.index=index;
//		clpso.Run();
//		stop=clock();
//		int time=(stop-start)/CLOCKS_PER_SEC;
//		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
//	}
//
	cout<<"Now SFCLPSO"<<endl;
	start=clock();
	SFCLPSO sfclpso(m0, m, t, DIM, GEN, index, times);
//	PSO *pso = &sfclpso;
	InitCompoFunc(DIM);
	for(int index=12; index<=14; index++){
		start=clock();
		sfclpso.index = index;
		sfclpso.Run();
//		pso->index=index;
//		pso->Run();
//		sfclpso.LearnMat.OutputIG(index, "CLPSO");
		stop=clock();
		int time=(stop-start)/CLOCKS_PER_SEC;
		cout<<"f("<<index<<") use "<<(time/60)<<"min "<<time%60<<"s"<<endl;
	}
	return 0;
}
