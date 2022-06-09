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
		void definaNome (string nome) {
			nomeCurso = nome;
		}
		
		string pegarNome (){
			return nomeCurso;
		}
		
		void exibirMensagem (string nomeCurso) {
			cout << "Bem vindo ao curso   " << nomeCurso << "!" << endl;
		}
		
	private:
		string nomeCurso;
};

int main(void) {
	string nomeCurso; // strings de caracteres para armazenar o nome do curso
	anotacao minhasNotas;

	cout << "Nome inicial do curso:  " << minhasNotas.pegarNome() << endl;
	
	 
	getline (cin, nomeCurso);//pegando o nome do curso
	cout << endl;
	
	minhasNotas.exibirMensagem(nomeCurso);
	return 0;
	
}
