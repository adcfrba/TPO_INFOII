/*
 * CALLBACK.h
 *
 *  Created on: 23 ago. 2023
 *      Author: gusta
 */

#ifndef UTILS_CALLBACK_CALLBACK_H_
#define UTILS_CALLBACK_CALLBACK_H_

// Definición de un tipo de puntero a función
typedef void (*FuncPtr)(void);

class CALLBACK {
public:
    // Creación de un vector de punteros a función
	std::vector<FuncPtr> callback;

    bool add(FuncPtr);
    bool del(FuncPtr);
    void run(void);
    uint32_t size(void);
};

#endif /* UTILS_CALLBACK_CALLBACK_H_ */
