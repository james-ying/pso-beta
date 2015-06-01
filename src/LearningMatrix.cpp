/*
 * LearningMatrix.cpp
 *
 *  Created on: 2015年4月21日
 *      Author: lenovo
 */

#include "LearningMatrix.h"
#include<sstream>
#include<fstream>
#include<iostream>
#include<string>
#include<queue>
using namespace std;

vector<Temp> component;
extern int GAP;
LearningMatrix::LearningMatrix() {
	// TODO Auto-generated constructor stub

}

LearningMatrix::LearningMatrix(int N, int GEN):
	IG(new int *[N]),
	IGF(new int *[N]),
	IGM(new int *[N]),
	IGL(new int *[N]),
	IGW(new int *[N]),
	IGsingle(new int *[N]),
	CompoDistri(new int * [GEN+1]),
	CompoDistriGbest(new int * [GEN+1]),
	N(N),
	cnt(0),
	GEN(GEN)
{
	for(int i=0; i<N; i++){
		IG[i] = new int [N];
		IGF[i] = new int [N];
		IGM[i] = new int [N];
		IGL[i] = new int [N];
		IGW[i] = new int [N];
		IGsingle[i] = new int [N];
		for(int j=0; j<N; j++){
			IG[i][j] = 0;
			IGF[i][j] = 0;
			IGM[i][j] = 0;
			IGL[i][j] = 0;
			IGW[i][j] = 0;
			IGsingle[i][j] = 0;
		}
		CompoDistri[i] = 0;
	}
	for(int g=0; g<=GEN; g++){
		CompoDistri[g] = new int [N];
		CompoDistriGbest[g] = new int [N];
		for(int i=0; i<N; i++){
			CompoDistri[g][i] = 0;
			CompoDistriGbest[g][i] = 0;
		}
	}
	component.clear();//TODO:test
}

void LearningMatrix::ClearLearningMatrix(){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			IG[i][j] = 0;
			IGF[i][j] = 0;
			IGM[i][j] = 0;
			IGL[i][j] = 0;
			IGW[i][j] = 0;
			IGsingle[i][j]=0;
		}
	}
	for(int g=0; g<=GEN; g++){
		for(int i=0; i<N; i++){
			CompoDistri[g][i] = 0;
			CompoDistriGbest[g][i] = 0;
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
//		CompoDistri[i] = 0;
	}
	component.clear();//TODO:test
}

void LearningMatrix::SetInfo(int i, int fi, int g){
//	if(i != fi){
		IGW[i][fi]+=1;
//		IGW[fi][i]+=1;
		if(!(g%GAP)){
			IG[i][fi]+=1;
//			IG[fi][i]+=1;
		}
		if(g<500){
			IGF[i][fi]+=1;
//			IGF[fi][i]+=1;
		}
		if(g>1500 && g<2000){
			IGM[i][fi]+=1;
//			IGM[fi][i]+=1;
		}
		if(g>4500){
			IGL[i][fi]+=1;
//			IGL[fi][i]+=1;
		}
//	}
}

void LearningMatrix::Result(int dc, int g, int gbest_id){//TODO:test
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
//	for(int i=gbest_id; i<gbest_id+N; i++){//from gbest, follow the idx
	int i =gbest_id;
	do{
		if(!visited[i]){
			Temp temp;
			temp.includeGbest = 0;
			q.push(i);
			if(i == gbest_id){
				temp.includeGbest = 1;
				temp.gbestID = gbest_id;
			}
			visited[i] = 1;
			temp.component_number = cmpnt++;
			while(!q.empty()){
				temp.particle_idx.push_back(q.front());//int temp = q.front();
				q.pop();
				for(int j=0; j<N; j++){
					if(IGsingle[temp.particle_idx.back()][j] && !visited[j]){
						q.push(j);
						if(j == gbest_id){
							temp.includeGbest = 1;
							temp.gbestID = gbest_id;
						}
						visited[j] = 1;
						temp.component_number = cmpnt++;
					}
				}
			}
			if(temp.includeGbest){//包含gbest的连通片放在最前面一个
				component.insert(component.begin(), temp);
			}else{
				component.push_back(temp);
			}
		}
		i = (i+1)%N;
	}while(i!=gbest_id);
	delete visited;

	for(int i=0; i!=component.size(); i++){
		CompoDistri[g][component[i].particle_idx.size()-1]++;
	}

	CompoDistriGbest[g][component[0].particle_idx.size()-1]++;
}

void LearningMatrix::OutputIG(int index, string name)//IGF,IGL,IGW
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<name<<"-component["<<index<<"]-IGF"<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
//				outfile<<La(i,j)<<'\t';
				outfile<<IGF[i][j]<<'\t';

			}
			outfile<<endl;
		}
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
	stream.str("");
	stream<<"outputN\\"<<name<<"-component["<<index<<"]-IGM"<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
//				outfile<<La(i,j)<<'\t';
				outfile<<IGM[i][j]<<'\t';

			}
			outfile<<endl;
		}
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}

	stream.str("");
	stream<<"outputN\\"<<name<<"-component["<<index<<"]-IGL"<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
//				outfile<<La(i,j)<<'\t';
				outfile<<IGL[i][j]<<'\t';

			}
			outfile<<endl;
		}
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}

	stream.str("");
	stream<<"outputN\\"<<name<<"-component["<<index<<"]-IGW"<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
//				outfile<<La(i,j)<<'\t';
				outfile<<IGW[i][j]<<'\t';

			}
			outfile<<endl;
		}
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
}

void LearningMatrix::OutputDistribution(int index, int g, string str)
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<str<<"-component distribution["<<index<<"].txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		for(int i=0; i!=N; i++){
			outfile << CompoDistri[g][i] << "\t" ;
		}
		outfile<<endl;
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
}

void LearningMatrix::OutputDistributionGbest(int index, int g, string str)
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<str<<"-component distribution gbest["<<index<<"].txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		outfile << component[0].gbestID <<'\t';
		for(int i=0; i!=N; i++){
			outfile << CompoDistriGbest[g][i] << "\t" ;
		}
		outfile<<endl;
		outfile.close();
	}else{
		cout<<"Can't open file:" << title << endl;
	}
}

void OutputN(int index,int g,int dc, int cnt, double gbestFitness, string str)//TODO:test
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<str<<"-component["<<index<<"]-dc="<<dc<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
		outfile<<"g ="<<g<<'\t'<<"component number ="<< component.size()<<"\tgbestFitness ="<<gbestFitness<<"\tThe gbest is particle:"<< component[0].gbestID << endl;
//		outfile<<g<<'\t'<<gbestFitness<<'\t'<<cnt<<endl;
//		outfile << "The gbest is particle:"<< component[0].gbestID <<endl;
		for(int i=0; i!=component.size(); i++){
			outfile << component[i].particle_idx.size()<<" particle(s) in this component :";
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
void OutputComponentStatistic(int index,int g,int dc, int cnt, double gbestFitness, string str)//TODO:test
{
	ofstream outfile;
	string title;
	stringstream stream;
	stream<<"outputN\\"<<str<<"-component["<<index<<"]-dc="<<dc<<".txt";
	title=stream.str();
	outfile.open(title.data(),ios::app);//
	if(outfile.is_open()){
//	component number, the size of pice include gbest, the size of the gaint pice, gbest is in the gaint pice		// large-degree particles' number
		int gaintIdx=0, isInGaint = 0;
		for(int i=0; i!=component.size(); i++){
			 if(component[i].particle_idx.size()>component[gaintIdx].particle_idx.size()){
				 gaintIdx = i;
			 }
		}
		if(component[gaintIdx].includeGbest){
			isInGaint = 1;
		}
		outfile << component.size() << "\t"
				<< component[0].particle_idx.size() << "\t"
				<< component[gaintIdx].particle_idx.size()<< "\t"
				<< isInGaint <<endl;
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
		delete IGM[i];
		delete IGL[i];
		delete IGW[i];
		delete IGsingle[i];
	}
}

