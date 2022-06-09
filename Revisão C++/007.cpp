//treinando classes e orientação a objetos

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//classe anotacao

class Anotacao {
	public:
		void DisplayMessage () {
			cout << "Seja bem vindo! " << endl;
		}
};




int main (void) {
	Anotacao minhasnotas; //cria um objeto Anotacao chamado minhasnotas
	minhasnotas.DisplayMessage(); //chama a funcao displayMessage do objeto Anotacao
	
	return 0;
}
