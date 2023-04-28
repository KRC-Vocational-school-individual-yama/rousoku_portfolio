#pragma once

#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>

class CsvSave {
public:
	CsvSave();
	~CsvSave();
	static std::vector<std::string> Load(std::string _pass);
	static void Save(std::string _pass, std::vector<std::string>_str,int _num=10);

private:
	
};