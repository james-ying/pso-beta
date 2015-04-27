/*
 * LearningMatrix.cpp
 *
 *  Created on: 2015Äê4ÔÂ21ÈÕ
 *      Author: lenovo
 */

#include "LearningMatrix.h"
#include<sstream>
#include<fstream>
#include<iostream>
#include<string>
#include<queue>
using namespace std;
LearningMatrix::LearningMatrix() {
	// TODO Auto-generated constructor stub

}

LearningMatrix::LearningMatrix(int N):
	IG(new int *[N]),
	IGF(new int *[N]),
	IGL(new int *[N]),
	IGW(new int *[N]),
	IGsingle(new int *[N]),
	N(N),
	cnt(0)
{
	for(int i=0; i<N; i++){
		IG[i] = new int [N];
		IGF[i] = new int [N];
		IGL[i] = new int [N];
		IGW[i] = new int [N];
		IGsingle[i] = new int [N];
		for(int j=0; j<N; j++){
			IG[i][j] = 0;
			IGF[i][j] = 0;
			IGL[i][j] = 0;
			IGW[i][j] = 0;
			IGsingle[i][j] = 0;
		}
	}
	component.clear();//TODO:test
}

void LearningMatrix::ClearLearningMatrix(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			IG[i][j] = 0;
			IGF[i][j] = 0;
			IGL[i][j] = 0;
			IGW[i][j] = 0;
			IGsingle[i][j]=0;
		}
	}
	component.clear();//TODO:test
}

void LearningMatrix::ClearIG(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			IG[i][j]=0;
			IGsingle[i][j]=0;
		}
	}
	component.clear();//TODO:test
}

void LearningMatrix::SetInfo(int i, int fi, int g){
	if(i != fi){
		IGW[i][fi]+=1;
		IGW[fi][i]+=1;
		if(!(g%200)){
			IG[i][fi]+=1;
			IG[fi][i]+=1;
		}
		if(g<1000){
			IGF[i][fi]+=1;
			IGF[fi][i]+=1;
		}
		if(g>4000){
			IGL[i][fi]+=1;
			IGL[fi][i]+=1;
		}
	}
}

void LearningMatrix::Result(int dc){//TODO:test
//	int dc=2;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(IG[i][j]>=dc){
				IGsingle[i][j]=1;
			}else{
				IGsingle[i][j]=0;
			}
		}
	}
//BFS
	int *visited = new int [N];
	for(int i=0; i<N; i++){
		visited[i] = 0;
	}
	queue<int> q;
	int cmpnt=1;
	for(int i=0; i<N; i++){
		if(!visited[i]){
			Temp temp;
			q.push(i);
			visited[i] = 1;
			temp.component_number = cmpnt++;
			while(!q.empty()){
				temp.particle_idx.push_back(q.front());//int temp = q.front();
				q.pop();
//				cout<<temp<<"\t";
				for(int j=0; j<N; j++){
					if(IGsingle[temp.particle_idx.back()][j] && !visited[j]){
						q.push(j);
						visited[j] = 1;
						temp.component_number = cmpnt++;
					}
				}
			}
			component.push_back(temp);//cout<<endl;
		}
	}
	delete visited;
//	La=De-IGu;
//	cnt=0;
//	eivals = La.eigenvalues();
//	for(int i=0; i<N; i++){
//		if(abs(*eivals.row(i).real().data())<1e-8){
//			cnt++;
//		}
//	}
//	OutputN(index,g,dc,cnt,gbestFitness);
}

void LearningMatrix::OutputIG(int index, int **G, string name)//IGF,IGL,IGW
{
	ofstream outfile;
	string title1="outputN\\",title2="[",title3="].txt",title,number;
	title=title1;
	stringstream stream;
	stream<<index;
	number=stream.str();
	title.append(name);
	title.append(title2);
	title.append(number);
	title.append(title3);
	outfile.open(title.data());
	if(outfile.is_open()){
		outfile<<"IG:"<<endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
//				outfile<<La(i,j)<<'\t';
			}
			outfile<<endl;
		}
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
}
vector<Temp> component;
void OutputN(int index,int g,int dc, int cnt, double gbestFitness, string str)//TODO:test
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<str<<"-component["<<index<<"]-dc="<<dc<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		outfile<<"g ="<<g<<'\t'<<"component number ="<< component.size()<<"gbestFitness ="<<gbestFitness<<endl;
//		outfile<<g<<'\t'<<gbestFitness<<'\t'<<cnt<<endl;
		for(int i=0; i!=component.size(); i++){
			outfile << component[i].particle_idx.size()<<":";
//			if(component[i].particle_idx.size()>1){
				for(int j=0; j!=component[i].particle_idx.size(); j++){
					outfile<< "\t" << component[i].particle_idx[j] ;
				}
//			}
			outfile << "\t;"<<endl;
		}
		outfile<<endl;
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
}

LearningMatrix::~LearningMatrix() {
	// TODO Auto-generated destructor stub
	for(int i=0; i<N; i++){
		delete IG[i];
		delete IGF[i];
		delete IGL[i];
		delete IGW[i];
		delete IGsingle[i];
	}
}

