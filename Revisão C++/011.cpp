#include <iostream>
#include <string>
#include <algorithm>
//#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::reverse;

/*O m�todo std::reverse � da <algorithm> biblioteca STL, e inverte a ordem dos elementos da gama. 
* O m�todo opera sobre objetos passados como argumentos e n�o devolve uma nova c�pia dos dados,
* portanto, precisamos declarar outra vari�vel para preservar a seq��ncia original.
* Note que a fun��o reverse lan�a a exce��o std::bad_alloc se o algoritmo n�o alocar mem�ria.
*/

//The Target define a interface espec�fica do dom�nio usada pelo c�digo do cliente.
 
class Target {
	public:
		virtual ~Target() = default;
	virtual std::string Request() const {
		return "Target: The default target's behavior.";
	}
};

/**
 * The Adaptado cont�m algum comportamento �til, mas sua interface � incompat�vel
 * com o c�digo do cliente existente. O Adaptee precisa de alguma adapta��o antes do
 * o c�digo do cliente pode us�-lo.
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
		Adaptee *adaptee_; //declara��o de objeto ponteiro

	public:
		Adapter(Adaptee *adaptee) : adaptee_(adaptee) {}
		std::string Request() const override {
		std::string to_reverse = this->adaptee_->SpecificRequest();
		std::reverse(to_reverse.begin(), to_reverse.end());
	return "Adapter: (TRANSLATED) " + to_reverse;
	}
};

/**
 * O c�digo cliente suporta todas as classes que seguem a interface Target.
 */
void ClientCode(const Target *target) {
	std::cout << target->Request();
}

int main() {
  
	std::cout << "Client: I can work just fine with the Target objects:\n";
	Target *target = new Target; //declara��o de objeto ponteiro
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
