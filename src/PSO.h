/*
 * PSO.h
 *
 *  Created on: 2015��4��14��
 *      Author: lenovo
 */

#ifndef PSO_H_
#define PSO_H_
#include "Particle.h"
#include <string>
#include "LearningMatrix.h"
using namespace std;
class PSO {
public:
	double w; //����Ȩ��
	double c;
	double *gbest;
	double gbestFitness;
	int **G; //���˽ṹ
	double **M; //rotate Matrix for function
	int index; //�������
	int gbest_id;//gbest�������
	string name;
	LearningMatrix LearnMat;
public:
	PSO();
	PSO(int N, int DIM, int GEN, int index, int times, string name);//vector�汾
	void Initialize();
	void InitNeighbor();
	virtual void SetG();
	virtual void Run();
	virtual void UpdateVelocity(int i, int g);//overload
	virtual void UpdatePosition(int i);
	void Iterate(int g, int t);
	virtual void UpdateExamplar();//overload
	inline double Randf(){
		return ((double)rand()/(double)RAND_MAX);
	};
	virtual ~PSO();
protected:
	int N;
	int DIM;
	int GEN;
	int times;
	double goal;
	Particle *p;
};
void OutputGHead(int index, int GEN, string str);
void OutputG(int g, int index, int times, double gbestFitness, int GEN, string str);
#endif /* PSO_H_ */
