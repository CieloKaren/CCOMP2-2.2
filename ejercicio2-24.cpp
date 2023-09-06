#include <iostream>
using namespace std; 
 
int main(){
    int num1, num2;
    cout << "Ingresa el primer número: ";
    cin >> num1;
    cout << "Ingresa el segundo número: ";
    cin >> num2;

    if (num1 % 2 == 1){
        cout << num1 << "Es un número impar" << endl;

    }
    else {
        cout << num1 << "No es un número impar" << endl;
    }

    if (num2 % 2 == 1){
        cout << num2 << "Es un número impar" << endl;
    }
    else{
        cout << num2 << "No es un número impar << endl;"
    }

    return 0;
}