/*
 * LearningMatrix.h
 *
 *  Created on: 2015��4��21��
 *      Author: lenovo
 */

#ifndef LEARNINGMATRIX_H_
#define LEARNINGMATRIX_H_
#include <string>
#include<vector>
using namespace std;
class LearningMatrix {
public:
	int **IG;
	int **IGF; //front 500 iteration
	int **IGM; //middle 500 iteration
	int **IGL; //last 500 iteration
	int **IGW; //whole iteration
	int **IGsingle;//��Ϣ��������
	int **CompoDistri;//CompoDisti[g][i]��g����������Ϊi����ͨƬ������
	int **CompoDistriGbest;
	LearningMatrix();
	LearningMatrix(int N, int GEN);
	void ClearLearningMatrix();
	void ClearIG();
	void SetInfo(int i, int fi, int g);
	void Result(int dc, int g, int gbest_id);
	void OutputIG(int index, std::string name);
	void OutputDistribution(int index, int g, string str);
	void OutputDistributionGbest(int index, int g, string str);
	virtual ~LearningMatrix();
	int N;
	int cnt;//��ͨƬ��
	int GEN;
};
//TODO:test
struct Temp{
	vector<int> particle_idx;
	int component_number;
	int includeGbest;
	int gbestID;
};
extern vector<Temp> component;
void OutputN(int index,int g,int dc, int cnt, double gbestFitness, std::string str);
void OutputComponentStatistic(int index,int g,int dc, int cnt, double gbestFitness, string str);

#endif /* LEARNINGMATRIX_H_ */
