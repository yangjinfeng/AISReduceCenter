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
	//����֮��������Լ�Ȩ��
	map<string,pair<int,double> > featureWeights;
	//������ϵͳ�������Լ�Ȩ��
	map<string, map<string,pair<int,double> > > subaisWeight;

	//��ʼ�����ĵ������Լ�Ȩ��
	void initLoad();

	//������ϵͳ�������Լ�Ȩ��
	void loadFeatureAndWeight(string path, map<string,pair<int,double> >& fwMap);
};

#endif /* REDUCER_H_ */
