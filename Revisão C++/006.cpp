// Calcula o produto de três inteiros
#include <iostream> // permite ao programa realizar entrada e saída
using std::cout; // o programa utiliza cout
using std::cin; // o programa utiliza cin
using std::endl; // o programa utiliza endl

// a função main inicia a execução do programa
int main() {
	int x; // primeiro inteiro a multiplicar
	int y; // segundo inteiro a multiplicar
	int z; // terceiro inteiro a multiplicar
	int resultado; // o produto dos três inteiros
	
	cout << "Entre com tres inteiros:"; // solicita dados ao usuário
	cin >> x >> y >> z; // lê três inteiros de usuário
	
	resultado = x * y * z; // multiplica os três inteiros; resultado de armazenamento
	
	cout << "A multiplicacao sera: " << resultado << endl; // imprime resultado; termina a linha
	
	return 0; // indica que o programa executou com sucesso
} // fim da função main
