#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

class CalculadoraPostfija {
private:
    stack<int> pila;

public:
    
    bool esOperador(string token) {
        return token == "+" || token == "-" || 
               token == "*" || token == "/";
    }

    
    int evaluarExpresion(string expresion) {
        stringstream ss(expresion);
        string token;

        while (ss >> token) {

            
            if (!esOperador(token)) {
                pila.push(stoi(token));
            }
            else {
                
                if (pila.size() < 2) {
                    throw runtime_error("Error: expresion invalida");
                }

                int b = pila.top();
                pila.pop();

                int a = pila.top();
                pila.pop();

                
                if (token == "+")
                    pila.push(a + b);

                else if (token == "-")
                    pila.push(a - b);

                else if (token == "*")
                    pila.push(a * b);

                else if (token == "/")
                    pila.push(a / b);
            }
        }

        
        if (pila.size() != 1) {
            throw runtime_error("Error: expresion invalida");
        }

        return pila.top();
    }
};

int main() {

    CalculadoraPostfija calc;
    string expresion;

    cout << "Ingrese la expresion postfija: ";
    getline(cin, expresion);

    try {
        int resultado = calc.evaluarExpresion(expresion);
        cout << "Resultado: " << resultado << endl;
    }
    catch (exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}