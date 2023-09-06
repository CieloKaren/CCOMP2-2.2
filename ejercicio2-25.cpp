#include <iostream>
using namespace std;

int main(){
    int num1, num2, num3;
    cout << "Ingrese el primer número: ";
    cin >> num1;
    cout << "Ingrese el segundo número: ";
    cin >> num2;
    cout << "Ingrese el tercer número: ";
    cin >> num3;

    if (num3 % num1 == 0 && num3 % num2 == 0){
        cout << num1 << "y" << num3 << "Es factor de " << num2 << endl;
    }
    else{
        cout << num1 << "y" << num3 << "No es factor de " << num2 << endl;
    }

    return 0;
}