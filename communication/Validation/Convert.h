#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Convert
{
public:
	vector<uint8_t> convertCharToUint8(char c);
	vector<uint8_t> convertCharVecToUint8(vector<char> c);
	vector<char> convertUint8ToChar(vector<uint8_t> c);
	
};
