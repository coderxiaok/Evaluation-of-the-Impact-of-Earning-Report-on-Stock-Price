//
//  LineGraph.h
//  Final Project
//
//  Created by Alex on 12/12/14.
//  Copyright (c) 2014 MING TIAN. All rights reserved.
//

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

#include "LineGraph.h"

void LineGraph(vector<double> &vector_1, vector<double> &vector_2, vector<double> &vector_3, string title_)
{
	//EXCEL DRIVER PART
	long N = vector_1.size(); //long M = 30;
	//NumericMatrix<double, long> matrix(N+1, M+1);

	Vector<double, long> xarr(N);
	Vector<double, long> yarr1(N);
	Vector<double, long> yarr2(N);
	Vector<double, long> yarr3(N);

	//cout << "Min" << Zarr.MinIndex() << "Max" << Zarr.MaxIndex() << "Size" <<Zarr.Size() << endl;

	double h1 = 1.0;
	xarr[xarr.MinIndex()] = 1.0;
	for (long j = xarr.MinIndex() + 1; j <= xarr.MaxIndex(); j++)
	{
		xarr[j] = xarr[j - 1] + h1;
	}

	yarr1[yarr1.MinIndex()] = vector_1[0];
	yarr2[yarr2.MinIndex()] = vector_2[0];
	yarr3[yarr3.MinIndex()] = vector_3[0];
	for (long j = yarr1.MinIndex() + 1; j <= yarr1.MaxIndex(); j++)
	{
		yarr1[j] = vector_1[j - 1];
		yarr2[j] = vector_2[j - 1];
		yarr3[j] = vector_3[j - 1];
	}

	//new part
	list<std::string> ylables = { "Beat_CAAR", "Meet_CAAR", "Miss_CAAR" };
	list<Vector<double, long> > ylist = { yarr1, yarr2, yarr3 };

	list<std::string> rowlabels = convertToString(xarr);
	list<std::string> columnlabels = convertToString(yarr1);

	std::string sheetName("CAAR Line Graph");

	ExcelDriver& excel = ExcelDriver::Instance();
	excel.MakeVisible(true);		// Default is INVISIBLE!

	//excel.AddMatrix(sheetName, matrix, rowlabels, columnlabels);

	try
	{
		// Difference of vectors
		//printDifferenceInExcel(xarr, yarr2, yarr);
		printInExcel(xarr, ylables, ylist, title_);
	}
	catch (DatasimException& e)
	{
		e.print();
	}
	catch (...)
	{
		// Catches everything else
	}
	getchar();
}