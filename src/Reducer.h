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

	void reduceAndDistribute();



private:
	//汇总之前的特征以及权重
	map<string,pair<int,double> > featureWeights;
	//汇总之后的特征以及权重
	map<string,pair<int,double> > newfeatureWeights;
	//各个子系统的特征以及权重
	map<string, map<string,pair<int,double> > > subaisWeight;

	//初始化中心的特征以及权重
	void initLoad();

	//加载子系统的特征以及权重
	void loadFeatureAndWeight(string path, map<string,pair<int,double> >& fwMap);
	//保存子系统的特征
	void saveFeature(string path,map<string,pair<int,double> >& fwMap);
	//保存子系统的权重
	void saveWeight(string path,map<string,pair<int,double> >& fwMap);
	//加载各子系统的特征以及权重
	void loadSubAIS();
	//汇总各子系统的特征以及权重
	void reduce();
	//分发并更新个子系统的权重
	void distribute();

	void clear();


};

#endif /* REDUCER_H_ */
