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

using namespace std;

class Reducer {
public:
	Reducer();
	virtual ~Reducer();

private:
	map<String,double> featureWeights;

	void initLoad();
};

#endif /* REDUCER_H_ */
