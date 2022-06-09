//treinando classes e orientação a objetos

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include <string>
using std::string;
using std::getline;

//classe anotacao
class anotacao {
	public:
		void exibirMensagem (string nomeCurso) {
			cout << "Bem vindo ao curso   " << nomeCurso << "!" << endl;
		}
};

int main(void) {
	string nomeCurso; // strings de caracteres para armazenar o nome do curso
	anotacao minhasNotas;
	 
	getline (cin, nomeCurso);//pegando o nome do curso
	cout << endl;
	
	minhasNotas.exibirMensagem(nomeCurso);
	return 0;
	
}
