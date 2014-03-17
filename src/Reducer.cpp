/*
 * Reducer.cpp
 *
 *  Created on: 2014-3-17
 *      Author: hp
 */

#include "Reducer.h"
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

void Reducer::reduceAndDistribute(){
//	cout<<"initload"<<endl;
	initLoad();
//	cout<<"finish initload"<<endl;
	loadSubAIS();
//	cout<<"finish loadSubAIS"<<endl;
	reduce();
//	cout<<"finish reduce"<<endl;
	distribute();
//	cout<<"finish distribute"<<endl;
	clear();
}


void Reducer::initLoad(){
	cout<<"begin initload"<<endl;
	loadFeatureAndWeight(".", featureWeights);
	newfeatureWeights = featureWeights;

}

void Reducer::loadSubAIS(){
	string path = "subaispath.txt";
	if(Tools::fileExists(path.c_str())){
		ifstream fin(path.c_str());
		string line;
		while(getline(fin, line)){
			map<string,pair<int,double> > fwMap;
			loadFeatureAndWeight(line,fwMap);
			subaisWeight[line] = fwMap;
		}
		fin.close();
	}

}

void Reducer::reduce(){
	//循环每一个子系统
	for(map<string, map<string,pair<int,double> > >::iterator it = subaisWeight.begin();it != subaisWeight.end();it ++){
		//循环每一个特征
		for(map<string,pair<int,double> >::iterator itt = it->second.begin();itt != it->second.end();itt ++){
			double delta = 0;
			if(featureWeights.find(itt->first) != featureWeights.end()){//如果存在该特征
				delta = itt->second.second - featureWeights[itt->first].second;
			}else{
				delta = itt->second.second;
			}

			if(newfeatureWeights.find(itt->first) != newfeatureWeights.end()){
				newfeatureWeights[itt->first].second = newfeatureWeights[itt->first].second + delta;
			}else{
				newfeatureWeights[itt->first] = make_pair(newfeatureWeights.size()-1,delta);
			}

		}
	}
}

void Reducer::distribute(){
	//存储共享中心的特征以及权重
	saveFeature(".",newfeatureWeights);
	saveWeight(".",newfeatureWeights);

	//循环每一个子系统
	for(map<string, map<string,pair<int,double> > >::iterator it = subaisWeight.begin();it != subaisWeight.end();it ++){
		//循环每一个特征
		for(map<string,pair<int,double> >::iterator itt = it->second.begin();itt != it->second.end();itt ++){
			itt->second.second = newfeatureWeights[itt->first].second;
		}

		saveWeight(it->first,it->second);
	}
}

void Reducer::saveFeature(string path,map<string,pair<int,double> >& fwMap){
	string featureFile = path +"/feature.txt";
//	if(!Tools::fileExists(featureFile.c_str())){//如果特征文件存在，则特征权重文件也存在
		ofstream fout(featureFile.c_str(),ios::out);
		for(map<string,pair<int,double> >::iterator it = fwMap.begin();it != fwMap.end();it ++){
			fout<<it->first<<"\t"<<it->second.first<<endl;
		}
		fout.close();
//	}
}

void Reducer::saveWeight(string path,map<string,pair<int,double> >& fwMap){
	map<int,double> wmap;
	for(map<string,pair<int,double> >::iterator it = fwMap.begin();it != fwMap.end();it ++){
		wmap[it->second.first] = it->second.second;
	}

	string weightFile = path +"/weight.txt";
	ofstream fout(weightFile.c_str(), ios::out|ios::app);

	for(map<int,double>::iterator it = wmap.begin();it != wmap.end();it ++){
		fout<<it->second<<"\t";
	}
	fout<<endl;
	fout.close();
}

void Reducer::loadFeatureAndWeight(string path, map<string,pair<int,double> >& fwMap){
	cout<<"begin load"<<endl;
	map<string,int> fMap;
	string featureFile = path +"/feature.txt";
	if(Tools::fileExists(featureFile.c_str())){//如果特征文件存在，则特征权重文件也存在
		cout<<"begin load feature"<<endl;
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
		fwMap[it->first] = make_pair(it->second,fWeight[it->second]);
	}

//	for(map<string, map<string,pair<int,double> > >::iterator it = subaisWeight.begin();it != subaisWeight.end();it ++){
//			cout<<it->first<<"\t";
//			for(map<string,pair<int,double> >::iterator itt = fwMap.begin();itt != fwMap.end();itt ++){
//				cout<<itt->first<<"("<<itt->second.first<<")"<<itt->second.second<<"\t";
//			}
//			cout<<endl;
//		}
}

void Reducer::clear(){
	featureWeights.clear();
	newfeatureWeights.clear();
	subaisWeight.clear();
}



