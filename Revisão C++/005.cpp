#include <iostream>

//declarações da biblioteca 

using std::cout;
using std::cin;
using std::endl;

int main (void) {
	short int n1, n2, n3;
	
	std::cout << "entre com N1: \n";
	std::cin >> n1;
	
	std::cout << "entre com N2: " << std::endl;
	std::cin >> n2;
	
	std::cout << "Entre com N3: " << std::endl;
	std::cin >> n3;
	
	if (n1 == n2 && n2 == n3)
		cout << "Os numeros sao iguais" << std::endl;
	if (n1 > n2)
		cout << "N1 eh maior!" << endl;
		
	return 0;
}
