/*
 * testa.h
 *
 *  Created on: Feb 13, 2016
 *      Author: danilo
 */

#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include <stdio.h>
#include <string.h>

class example{
	public:
		example();
		~example();
		int getNumero();
		void printArguments();
	private:
		int numero;

};

#endif /* EXAMPLE_H_ */