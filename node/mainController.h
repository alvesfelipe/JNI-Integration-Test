/*
 * testa.h
 *
 *  Created on: Feb 13, 2016
 *      Author: danilo
 */

#ifndef MAINCONTROLLER_H_
#define MAINCONTROLLER_H_

#include <stdio.h>
#include <string.h>

class mainController{
	public:
		mainController();
		~mainController();
		int getNumero();
		void printArguments();
	private:
		int numero;

};

#endif /* MAINCONTROLLER_H_ */
