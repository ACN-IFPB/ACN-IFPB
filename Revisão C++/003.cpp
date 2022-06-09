#include <iostream>

int main () {
	
	short int num1, num2, soma;

	std::cout << "Entre com dois numeros inteiros e obtenha a soma\n";
	std::cin >> num1;
	std::cout << "\n";
	std::cin >> num2;
	
	soma = num1 +num2;
	
	std::cout << soma << std::endl;
	
	return 0;
	
}
