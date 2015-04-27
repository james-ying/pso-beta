/*
 * LearningMatrix.h
 *
 *  Created on: 2015年4月21日
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
	int **IGF; //front 1000 iteration
	int **IGL; //last 1000 iteration
	int **IGW;
	int **IGsingle;
	LearningMatrix();
	LearningMatrix(int N);
	void ClearLearningMatrix();
	void ClearIG();
	void SetInfo(int i, int fi, int g);
	void Result(int dc, int gbest_id);
	void OutputIG(int index, int **G, std::string name);
	virtual ~LearningMatrix();
	int N;
	int cnt;//连通片数
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

#endif /* LEARNINGMATRIX_H_ */
