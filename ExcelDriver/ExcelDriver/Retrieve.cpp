#include "stdafx.h"
#include"curl.h"
#include"Retrieve.h"
#include <stdio.h>  
#include <iostream>
#include <string>
#include <sstream>  
#include<vector>
#include<cstring>
using namespace std;

struct MemoryStruct {
	char *memory;
	size_t size;
};

void *myrealloc(void *ptr, size_t size)
{
	/* There might be a realloc() out there that doesn't like reallocing
	NULL pointers, so we take care of it here */
	if (ptr)
		return realloc(ptr, size);
	else
		return malloc(size);
}


int write_data2(void *ptr, size_t size, size_t nmemb, void *data)
{
	size_t realsize = size * nmemb;
	struct MemoryStruct *mem = (struct MemoryStruct *)data;

	mem->memory = (char *)myrealloc(mem->memory, mem->size + realsize + 1);
	if (mem->memory) {
		memcpy(&(mem->memory[mem->size]), ptr, realsize);
		mem->size += realsize;
		mem->memory[mem->size] = 0;
	}
	return realsize;
}

void Retrieve_Data(char *StockUrl, char *SPYUrl, vector<double>& V)
{
	vector<double>Stock;
	vector<double>Spy;
	struct MemoryStruct data;
	data.memory = NULL;
	data.size = 0;
	struct MemoryStruct spydata;
	spydata.memory = NULL;
	spydata.size = 0;
	//Stock!!!!!
	CURL *curl;
	curl_global_init(CURL_GLOBAL_ALL);
	CURLcode res;
	//const char *url1="http://real-chart.finance.yahoo.com/table.csv?s=LEN&d=8&e=11&f=2014&g=d&a=5&b=15&c=2014&ignore=.csv"; 
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, StockUrl);
		curl_easy_setopt(curl, CURLOPT_ENCODING, "");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data2);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
		res = curl_easy_perform(curl);

		stringstream sData;
		sData.str(data.memory);
		string sValue;
		double dValue = 0;
		sData.ignore(1000, '\n');
		for (string line; getline(sData, line);) {
			sValue = line.substr(line.find_last_of(',') + 1);
			dValue = strtod(sValue.c_str(), NULL);
			Stock.push_back(dValue);
		}
		//cout<<"Stock price is "<<endl;
		//for(int i=0;i<Stock.size();i++)
		//{
		//	cout<<Stock[i]<<endl;
		//   }
	}
	if (res == CURLE_OK)
	{
		curl_easy_cleanup(curl);
		curl_global_cleanup();
	}

	//Spy!!!!
	CURL *spycurl;
	curl_global_init(CURL_GLOBAL_ALL);
	CURLcode spyres;
	//const char *url2="http://real-chart.finance.yahoo.com/table.csv?s=SPY&d=8&e=11&f=2014&g=d&a=5&b=15&c=2014&ignore=.csv"; 
	spycurl = curl_easy_init();
	if (spycurl)
	{
		curl_easy_setopt(spycurl, CURLOPT_URL, SPYUrl);
		curl_easy_setopt(spycurl, CURLOPT_ENCODING, "");
		curl_easy_setopt(spycurl, CURLOPT_WRITEFUNCTION, write_data2);
		curl_easy_setopt(spycurl, CURLOPT_WRITEDATA, (void *)&spydata);
		spyres = curl_easy_perform(spycurl);

		stringstream spyData;
		spyData.str(spydata.memory);
		string spyValue;
		double dValue = 0;
		spyData.ignore(1000, '\n');
		for (string line; getline(spyData, line);) {
			spyValue = line.substr(line.find_last_of(',') + 1);
			dValue = strtod(spyValue.c_str(), NULL);
			Spy.push_back(dValue);
		}
		//cout<<"Spy price is "<<endl;
		//for(int i=0;i<Spy.size();i++)
		//{
		//	cout<<Spy[i]<<endl;
		//   }
	}
	if (spyres == CURLE_OK)
	{
		curl_easy_cleanup(spycurl);
		curl_global_cleanup();
	}
	V.resize(Stock.size() - 1);
	for (int i = 0; i<Stock.size() - 1; i++)
	{
		Stock[i] = (Stock[i] - Stock[i + 1]) / Stock[i + 1];
		Spy[i] = (Spy[i] - Spy[i + 1]) / Spy[i + 1];
		V[i] = Stock[i] - Spy[i];
		//cout<<V[i]<<endl;
	}
}