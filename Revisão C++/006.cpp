// Calcula o produto de tr�s inteiros
#include <iostream> // permite ao programa realizar entrada e sa�da
using std::cout; // o programa utiliza cout
using std::cin; // o programa utiliza cin
using std::endl; // o programa utiliza endl

// a fun��o main inicia a execu��o do programa
int main() {
	int x; // primeiro inteiro a multiplicar
	int y; // segundo inteiro a multiplicar
	int z; // terceiro inteiro a multiplicar
	int resultado; // o produto dos tr�s inteiros
	
	cout << "Entre com tres inteiros:"; // solicita dados ao usu�rio
	cin >> x >> y >> z; // l� tr�s inteiros de usu�rio
	
	resultado = x * y * z; // multiplica os tr�s inteiros; resultado de armazenamento
	
	cout << "A multiplicacao sera: " << resultado << endl; // imprime resultado; termina a linha
	
	return 0; // indica que o programa executou com sucesso
} // fim da fun��o main
