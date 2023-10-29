/*
 * CALLBACK.cpp
 *
 *  Created on: 23 ago. 2023
 *      Author: gusta
 */

#include "Defines.h"
bool CALLBACK::add(FuncPtr func){
	callback.push_back(func);
	return true;
}

uint32_t CALLBACK::size(void){
	return callback.size();
}

bool CALLBACK::del(FuncPtr func){
    auto it = find(callback.begin(), callback.end(), func);

    if (it != callback.end()) {
    	callback.erase(it);

    	return true;
    }
    return false;
}

void CALLBACK::run(void){
    for (const auto& funcPtr : callback) {
        funcPtr();
    }
}
