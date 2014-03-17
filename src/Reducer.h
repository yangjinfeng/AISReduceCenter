/*
 * Reducer.h
 *
 *  Created on: 2014-3-17
 *      Author: hp
 */

#ifndef REDUCER_H_
#define REDUCER_H_
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <pair.h>

using namespace std;

class Reducer {
public:
	Reducer();
	virtual ~Reducer();

private:
	//汇总之后的特征以及权重
	map<string,pair<int,double> > featureWeights;
	//各个子系统的特征以及权重
	map<string, map<string,pair<int,double> > > subaisWeight;

	//初始化中心的特征以及权重
	void initLoad();

	//加载子系统的特征以及权重
	void loadFeatureAndWeight(string path, map<string,pair<int,double> >& fwMap);
};

#endif /* REDUCER_H_ */
