// TestMatrixExcel.cpp
//
// Test output of a matrix in Excel. Here we 
// use the Excel Driver object directly.
//
// (C) Datasim Education BV 2006
//

//these include is for excel driver
#include "stdafx.h"
#include "BitsAndPieces\StringConversions.hpp"
#include "ExcelDriver.hpp"
#include "ExcelMechanisms.hpp"
#include "VectorsAndMatrices\NumericMatrix.cpp" // Template
#include "ExceptionClasses\DatasimException.hpp"

//these include is for download historical price
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

//this include is for our own graphing function
#include "LineGraph.h"
#include"Demo.h"

using namespace std;

int main()
{
	Demo();
	return 0;
}
