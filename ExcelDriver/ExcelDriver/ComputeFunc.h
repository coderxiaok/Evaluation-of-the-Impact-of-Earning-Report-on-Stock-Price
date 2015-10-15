//
//  ComputeFunc.h
//  Final Project
//
//  Created by Adonis on 12/3/14.
//  Copyright (c) 2014 HAOJIE JING. All rights reserved.
//

#ifndef Final_Project_ComputeFunc_h
#define Final_Project_ComputeFunc_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "Matrix.h"
#include "Item.h"
using namespace std;

void GetData(istream& source, Item& line);

void MeanCalc(vector<vector<double>>& m, int start, int gsize, int tsize, vector<double>& AAR, vector<double>& CAAR);

//void OutputResult(const Matrix& m, int nrow, int ncol, string filename);

#endif
