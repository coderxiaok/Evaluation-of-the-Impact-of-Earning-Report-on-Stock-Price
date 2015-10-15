//
//  ComputeFunc.cpp
//  Final Project
//
//  Created by Adonis on 12/3/14.
//  Copyright (c) 2014 HAOJIE JING. All rights reserved.
//
#include "stdafx.h"
#include "ComputeFunc.h"

void GetData(istream& source, Item& line)
{
	char temp[1001], *head, *tail;
	source.getline(temp, 1000, '#');
	head = temp + 1;
	tail = strchr(head, ',');
	strncpy(line.stock, head, tail - head);
	head = tail + 1;
	tail = strchr(head, ',');
	strncpy(line.spy, head, tail - head);
	head = tail + 1;
	tail = strchr(head, ',');
	strncpy(line.ticker, head, tail - head);
	head = tail + 1;
	tail = strchr(head, ',');
	strncpy(line.sector, head, tail - head);
	line.group = *(tail + 1);
}

//void GetData(istream& source, Item& line)
//{
//	char temp[1001], *head, *tail;
//	source.getline(temp, 1000, '#');
//	head = temp + 1;
//	tail = strchr(head, ',');
//	strncpy(line.stock, head, tail - head);
//	head = tail + 1;
//	tail = strchr(head, ',');
//	strncpy(line.spy, head, tail - head);
//	head = tail + 1;
//	tail = strchr(head, ',');
//	strncpy(line.ticker, head, tail - head);
//	head = tail + 1;
//	tail = strchr(head, ',');
//	strncpy(line.sector, head, tail - head);
//	line.group = *(tail + 1);
//}

void MeanCalc(vector<vector<double>>& m, int start, int gsize, int tsize, vector<double>& AAR, vector<double>& CAAR)
{
	double sum2 = 0;
	for (int t = 0; t<tsize; t++) {
		double sum1 = 0;
		for (int i = start; i<start + gsize; i++) {
			sum1 += m[i][t];
		}
		AAR[t] = sum1 / gsize;
		sum2 += AAR[t];
		CAAR[t] = sum2;
	}
}

//void OutputResult(const Matrix& m, int nrow, int ncol, string filename)
//{
//	ofstream of_stream(filename);
//	if (of_stream.is_open())
//	{
//		for (int r = 0; r<nrow; r++) {
//			for (int c = 0; c<ncol; c++) {
//				of_stream << m.Row[r].Col[c] << " ";  // space as delimiter
//			}
//			of_stream << endl;
//		}
//	}
//	else
//	{
//		cout << "Unable to open file";
//		exit(1);
//	}
//}
