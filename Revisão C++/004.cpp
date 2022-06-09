#include <iostream>

//teste ponteiros
int main (void) {
	int num1;
	
	std::cout << "entre com um valor \n";
	
	std::cin >> num1;
	
	std::cout << "Valor eh: " << num1 << std::endl;
	
	//std::cout << "O ponteiro:" << *num1 <<"\n";
	
	std::cout << "posicao do valor na memoria  " << &num1 << std::endl;
	
	return 0;
	
	
}
