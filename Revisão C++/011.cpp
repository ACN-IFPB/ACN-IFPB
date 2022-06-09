#include <iostream>
#include <string>
#include <algorithm>
//#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::reverse;

/*O método std::reverse é da <algorithm> biblioteca STL, e inverte a ordem dos elementos da gama. 
* O método opera sobre objetos passados como argumentos e não devolve uma nova cópia dos dados,
* portanto, precisamos declarar outra variável para preservar a seqüência original.
* Note que a função reverse lança a exceção std::bad_alloc se o algoritmo não alocar memória.
*/

//The Target define a interface específica do domínio usada pelo código do cliente.
 
class Target {
	public:
		virtual ~Target() = default;
	virtual std::string Request() const {
		return "Target: The default target's behavior.";
	}
};

/**
 * The Adaptado contém algum comportamento útil, mas sua interface é incompatível
 * com o código do cliente existente. O Adaptee precisa de alguma adaptação antes do
 * o código do cliente pode usá-lo.
 */
class Adaptee {
	public:
		std::string SpecificRequest() const {
			return ".eetpadA eht fo roivaheb laicepS";
		}
};

// O Adaptador faz a interface Adaptee compativel com Target's
class Adapter : public Target {
	private:
		Adaptee *adaptee_; //declaração de objeto ponteiro

	public:
		Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
		std::string Request() const override {
		std::string to_reverse = this->adaptee_->SpecificRequest();
		std::reverse(to_reverse.begin(), to_reverse.end());
	return "Adapter: (TRANSLATED) " + to_reverse;
	}
};

/**
 * O código cliente suporta todas as classes que seguem a interface Target.
 */
void ClientCode(const Target *target) {
	std::cout << target->Request();
}

int main() {
  
	std::cout << "Client: I can work just fine with the Target objects:\n";
	Target *target = new Target; //declaração de objeto ponteiro
	ClientCode(target);
	std::cout << "\n\n";
	
	Adaptee *adaptee = new Adaptee;
	std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
	std::cout << "Adaptee: " << adaptee->SpecificRequest();
	std::cout << "\n\n";
	std::cout << "Client: But I can work with it via the Adapter:\n";
	
	Adapter *adapter = new Adapter(adaptee);
	ClientCode(adapter);
	std::cout << "\n\n\n";

	delete target;
	delete adaptee;
	delete adapter;
	
	system ("pause");
	system ("cls");
	
	return 0;
}
