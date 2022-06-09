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

class Calculo {
	public:
		int x,y;
		soma(){
			cout << "entre com dois numeros: " << endl;
			cin >> x >> y;
			return x+y;			
		}
		subtracao (){
			cout << "entre com dois numeros: " << endl;
			cin >> x >> y;
			return x-y;
		}
		multiplicacao (){
			cout << "entre com dois numeros: " << endl;
			cin >> x >> y;
			return x*y;
		}
		potenciacao (){
			cout << "entre com dois numeros: " << endl;
			cin >> x >> y;
			return x^y;
		}
};


int main (void) {
	Anotacao minhasnotas; //cria um objeto Anotacao chamado minhasnotas
	minhasnotas.DisplayMessage(); //chama a funcao displayMessage do objeto Anotacao
	
	Calculo simplescalculadora;
	
	cout << "A soma eh:"  << simplescalculadora.soma() << endl;
	cout << "A subtracao de x -y eh: " << simplescalculadora.subtracao() << endl;
	cout << "A multiplicacao de x * y eh: " << simplescalculadora.multiplicacao() << endl;
	cout << "A potenciacao de x ^ y eh: " << simplescalculadora. potenciacao() << endl;
	
	return 0;
}
