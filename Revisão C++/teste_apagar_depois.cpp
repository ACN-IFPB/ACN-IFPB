#include <iostream>

using namespace std;

class infos {
    public:
        void exibirMensagem () {
            cout << "Oi eu sou o Goku!" << endl;
        }
};

int main (void){
    infos texto;

    texto.exibirMensagem();

    return 0;
}