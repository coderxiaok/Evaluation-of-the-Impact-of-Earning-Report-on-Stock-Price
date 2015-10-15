//
//  LineGraph.h
//  Final Project
//
//  Created by Alex on 12/12/14.
//  Copyright (c) 2014 MING TIAN. All rights reserved.
//

#ifndef Final_Project_LineGraph_h
#define Final_Project_LineGraph_h

#include "stdafx.h"
#include "BitsAndPieces\StringConversions.hpp"
#include "ExcelDriver.hpp"
#include "ExcelMechanisms.hpp"
#include "VectorsAndMatrices\NumericMatrix.cpp" // Template
#include "ExceptionClasses\DatasimException.hpp"

#include <stdio.h>  
#include <iostream>
#include <string>
#include <sstream>  
#include<vector>
#include<cstring>
#include"Retrieve.h"
#include"ComputeFunc.h"
#include "curl.h"
#include"Item.h"

void LineGraph(vector<double> &vector_1, vector<double> &vector_2, vector<double> &vector_3, string title_);

#endif