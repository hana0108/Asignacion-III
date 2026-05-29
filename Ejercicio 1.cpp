/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Navegador {

private:
    stack<string> historialAtras;
    stack<string> historialAdelante;
    string paginaActual;

public:

    void visitar(string pagina) {

        if (paginaActual != "") {
            historialAtras.push(paginaActual);
        }

        while (!historialAdelante.empty()) {
            historialAdelante.pop();
        }

        paginaActual = pagina;

        cout << "Visitando: " << paginaActual << endl;
    }

    void atras() {

        if (historialAtras.empty()) {
            cout << "No hay paginas anteriores" << endl;
            return;
        }

        historialAdelante.push(paginaActual);

        paginaActual = historialAtras.top();
        historialAtras.pop();

        cout << "Pagina actual: " << paginaActual << endl;
    }

    void adelante() {

        if (historialAdelante.empty()) {
            cout << "No hay paginas siguientes" << endl;
            return;
        }

        historialAtras.push(paginaActual);

        paginaActual = historialAdelante.top();
        historialAdelante.pop();

        cout << "Pagina actual: " << paginaActual << endl;
    }

    void mostrar() {

        cout << "\nPagina actual: " << paginaActual << endl;

        stack<string> tempAtras = historialAtras;

        cout << "Historial atras: [";

        while (!tempAtras.empty()) {

            cout << tempAtras.top();

            tempAtras.pop();

            if (!tempAtras.empty()) {
                cout << ", ";
            }
        }

        cout << "]" << endl;

        stack<string> tempAdelante = historialAdelante;

        cout << "Historial adelante: [";

        while (!tempAdelante.empty()) {

            cout << tempAdelante.top();

            tempAdelante.pop();

            if (!tempAdelante.empty()) {
                cout << ", ";
            }
        }

        cout << "]" << endl;
    }
};

int main() {

    Navegador nav;

    int opcion;
    string pagina;

    do {

        cout << "\n1. Visitar pagina" << endl;
        cout << "2. Ir atras" << endl;
        cout << "3. Ir adelante" << endl;
        cout << "4. Mostrar historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {

        case 1:

            cout << "Ingrese la pagina: ";
            cin >> pagina;

            nav.visitar(pagina);

            break;

        case 2:

            nav.atras();

            break;

        case 3:

            nav.adelante();

            break;

        case 4:

            nav.mostrar();

            break;

        case 5:

            cout << "Saliendo..." << endl;

            break;

        default:

            cout << "Opcion no valida" << endl;
        }

    } while (opcion != 5);

    return 0;
}