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
	//����֮ǰ�������Լ�Ȩ��
	map<string,pair<int,double> > featureWeights;
	//����֮��������Լ�Ȩ��
	map<string,pair<int,double> > newfeatureWeights;
	//������ϵͳ�������Լ�Ȩ��
	map<string, map<string,pair<int,double> > > subaisWeight;

	//��ʼ�����ĵ������Լ�Ȩ��
	void initLoad();

	//������ϵͳ�������Լ�Ȩ��
	void loadFeatureAndWeight(string path, map<string,pair<int,double> >& fwMap);
	//������ϵͳ������
	void saveFeature(string path,map<string,pair<int,double> >& fwMap);
	//������ϵͳ��Ȩ��
	void saveWeight(string path,map<string,pair<int,double> >& fwMap);
	//���ظ���ϵͳ�������Լ�Ȩ��
	void loadSubAIS();
	//���ܸ���ϵͳ�������Լ�Ȩ��
	void reduce();
	//�ַ������¸���ϵͳ��Ȩ��
	void distribute();

	void clear();


};

#endif /* REDUCER_H_ */
