#pragma once

#include <string>
#include <unordered_map>
#include <map>

using std::string;

class TimeMap
{
public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);

	//Estructura de almacenamiento de datos clave, timestamps
private:
	std::unordered_map<std::string, std::map<int, std::string>> claves;
};

