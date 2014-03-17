/*
 * Reducer.cpp
 *
 *  Created on: 2014-3-17
 *      Author: hp
 */

#include "Reducer.h"
#include "RunParameter.h"
#include <vector>
#include <string>
#include <iostream>
#include "Tools.h"

Reducer::Reducer() {
	// TODO Auto-generated constructor stub

}

Reducer::~Reducer() {
	// TODO Auto-generated destructor stub
}


void Reducer::initLoad(){
	loadFeatureAndWeight(".", featureWeights);
}

void Reducer::loadFeatureAndWeight(string path, map<string,double>& fwMap){
	map<string,int> fMap;
	string featureFile = path +"/feature.txt";
	if(Tools::fileExists(featureFile.c_str())){//如果特征文件存在，则特征权重文件也存在
		ifstream fin(featureFile.c_str());
		string line;
		while(getline(fin, line)){
			istringstream sin(line);
			string featurename;
			sin >> featurename;
			string id;
			sin >> id;
			fMap[featurename] = atoi(id.c_str());
		}
		fin.close();
	}

	std::vector<double> fWeight;
	string weightFile = path +"/weight.txt";
	if(Tools::fileExists(weightFile.c_str())){
		ifstream fin(weightFile.c_str());
		string line;
		string lastLine;
		while(getline(fin, line)){
			lastLine = line;
		}
		fin.close();
		istringstream sin(lastLine);
		string value;
		while(sin >> value){
			fWeight.push_back(atof(value.c_str()));
		}
	}
	for(map<string,int>::iterator it = fMap.begin();it != fMap.end();it ++){
		fwMap[it->first] = fWeight[it->second];
	}
}



