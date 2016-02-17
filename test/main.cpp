/* --------------------------------------------------------------------------
*author: Danilo Assis, Felipe Alves
*date: 16/02/2016
* --------------------------------------------------------------------------
*/

#include <stdio.h>
#include "mainController.h"


int main (int argc, char* argv[]){

	MainController:: *ptr = new MainController();
	ptr->sumarizeContent(argv[1]); //Sumarizar conteudo passado por parametro

	return 1;
}
