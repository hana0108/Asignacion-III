
#include <iostream>
#include <queue>

using namespace std;

// Clase Caja
class Caja {

public:

    string id;
    string descripcion;

    // Constructor
    Caja(string i, string d) {

        id = i;
        descripcion = d;
    }
};

// Clase Almacen
class Almacen {

private:

    queue<Caja> cola;

public:

    // Agregar caja
    void agregarCaja(string id, string descripcion) {

        cola.push(Caja(id, descripcion));

        cout << "Caja agregada: "
             << id
             << endl;
    }

    // Procesar caja
    void procesarCaja() {

        if (cola.empty()) {

            cout << "No hay cajas en la cola."
                 << endl;

            return;
        }

        Caja actual = cola.front();

        cout << "Procesando caja "
             << actual.id
             << ": "
             << actual.descripcion
             << endl;

        cola.pop();
    }

    // Ver cola
    void verCola() {

        if (cola.empty()) {

            cout << "La cola esta vacia."
                 << endl;

            return;
        }

        queue<Caja> temp = cola;

        cout << "\nCajas en espera:\n";

        while (!temp.empty()) {

            Caja c = temp.front();

            cout << c.id
                 << " - "
                 << c.descripcion
                 << endl;

            temp.pop();
        }
    }
};

int main() {

    Almacen almacen;

    almacen.agregarCaja("C001", "Ropa");
    almacen.agregarCaja("C002", "Articulos electronicos");
    almacen.agregarCaja("C003", "Zapatos");

    cout << endl;

    almacen.verCola();

    cout << endl;

    almacen.procesarCaja();

    cout << endl;

    almacen.verCola();

    return 0;
}

