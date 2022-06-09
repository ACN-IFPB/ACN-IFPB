/* UM PEQUENO CONVERSOR DE TEMPERATURAS
PARA MOSTRAR QUE EXISTE UM ADAPTADOR 
ENTRE A TEMPERATURA °C E °F
*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

//A classe alvo vai receber o valor em K do adaptador e retornar o valor em °F
class Alvo {
	public:
		float K, F;
		K_to_F (){
			F = (1,8 * (K-273) + 32);
			return F ;
		}
};

//A classe adaptador vai receber o valor em °C e retornar o valor em K
class Adaptador {
	public:
		float C, K;
		C_to_K (){
			K = C + 273;
		return K;
		}
};

class MostraTemp {
	public:
		float temp;
		void exibeValor () {
			cout << "O valor da temperatura eh:   " << temp << endl;
		}
};

int main (void) {
	float valor = 0;
	
	Adaptador temperatura;
	
	cout << "Entre com o valor da Temperatura ambiente: \n" << endl;
	cin >> temperatura.C_to_K(valor);
	
	cout << temperatura.exibeValor() << endl;
	return 0;
}
