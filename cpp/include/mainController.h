/* --------------------------------------------------------------------------
*author: Danilo Assis, Felipe Alves
*date: 16/02/2016
* --------------------------------------------------------------------------
*/

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sumarize.h"

namespace main_controller{

	class MainController{
	public:
		MainController(); 		
 		virtual ~MainController();
		void sumarizeContent(char* content);		

	};
}

#endif /* MAINCONTROLLER_H */