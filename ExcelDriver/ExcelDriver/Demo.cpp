#include "stdafx.h"
#include"Demo.h"
void Demo()
{
	int gsize = 31, isize = 93, tsize = 60; // gsize: group size; isize: stock number, tsize: day number
	int i = 0, index = 0;
	vector<Item> data;


	data.reserve(isize);
	data.resize(isize);
	ifstream source;
	source.open("Data.csv");
	if (!source.is_open()) {
		cout << "fail to open in file!\n";
		exit(1);
	}
	source.ignore(1000, '#');
	while (!source.eof() && i < isize) {
		GetData(source, data[i]);
		i++;
	}
	source.close();

	vector<double>AAR1(tsize);
	vector<double>CAAR1(tsize);
	vector<double>AAR2(tsize);
	vector<double>CAAR2(tsize);
	vector<double>AAR3(tsize);
	vector<double>CAAR3(tsize);

	vector<vector<double>>RReturn(isize, vector<double>(tsize));
	for (int stockind = 0; stockind < isize; stockind++)
	{
		Retrieve_Data(data[stockind].stock, data[stockind].spy, RReturn[stockind]);
		cout << stockind + 1 << endl;
	}
	cout << "Data retrieve succeeded!!!!!" << endl;


	char command;
	do
	{
		cout << "Are you gonna continue? y/n" << endl;
		cin >> command;
		cout << endl;
		if (command == 'n')
		{
			cout << "Thanks for watching!!" << endl;
			break;
		}
		else if (command == 'y')
		{
			int startp;
			cout << "Please enter which point you want to start: (0 for whole group; 1 for consumer discretionary sector ; 2 for financials sector; 3 for industrials sector; 4 for IT sector)" << endl;
			int s;
			cin >> s;
			int grsize;
			cout << "Please enter the name of file you want to save the result:" << endl;
			string name;
			cin >> name;
			string title_graph;
			if (s == 0)
			{
				startp = 0; grsize = 31; title_graph = "Groups";
			}
			else if (s == 1)
			{
				startp = 0; grsize = 7; title_graph = "Consumer Descretionary";
			}
			else if (s == 2)
			{
				startp = 8; grsize = 7; title_graph = "Financial";
			}
			else if (s == 3)
			{
				startp = 15; grsize = 10; title_graph = "Industrials";
			}
			else if (s == 4)
			{
				startp = 25; grsize = 6; title_graph = "Information Technology";
			}
			else{ cout << "Invalid value!!!" << endl; break; }

			ofstream Result;
			Result.open(name);
			MeanCalc(RReturn, startp, grsize, tsize, AAR1, CAAR1);
			MeanCalc(RReturn, startp + 31, grsize, tsize, AAR2, CAAR2);
			MeanCalc(RReturn, startp + 62, grsize, tsize, AAR3, CAAR3);
			for (int i = 0; i < CAAR3.size(); i++){ Result << CAAR1[i] << "," << CAAR2[i] << "," << CAAR3[i] << endl; }
			cout << "fout succeeded!!!" << endl;
			LineGraph(CAAR1, CAAR2, CAAR3, title_graph);
		}
	} while (command == 'y');

}
