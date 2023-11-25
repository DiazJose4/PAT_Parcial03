#include "Ejercicio03.h"
#include <unordered_map>
#include <map>

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
	//Metodo de almacenamiento
	claves[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp)
{
    //Comprovbacion de key
    if (claves.find(key) == claves.end()) {
        return "";
    }

    auto& timestampMap = claves[key];
    auto it = timestampMap.upper_bound(timestamp);

    return (it != timestampMap.begin()) ? (--it)->second : "";

    /* std::map<int, std::string>& timestampMap = claves[key];
    // instante de tiempo previo menor
    std::map<int, std::string>::iterator it = timestampMap.upper_bound(timestamp);
    if (it != timestampMap.begin()) {
        --it;
        // retorna el valor asociado al instante de tiempo previo (timestamp_prev) más cercano que sea menor que el instante de tiempo dado.
        return it->second;
    }
    //Si no existen valores retorna "".
    return "";*/

   
}
