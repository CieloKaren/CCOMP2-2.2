#include <iostream>
using namespace std;

int main (){
    int r;
    const double pi = 3.14159;
    cout << "Ingresa el radio del circulo";
    cin >> radio;

    int diametro = 2 * radio;
    double circunferencia = 2 * pi * radio;
    double area = pi * radio * radio;

    cout << "Diámetro del círculo: " << diametro << endl;
    cout << "Circunferencia del círculo: " << circunferencia << endl;
    cout << "Área del círculo:" << area << endl;

    return 0;

}