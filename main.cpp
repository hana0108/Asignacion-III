
#include <iostream>
#include <queue>

using namespace std;

// Clase Producto
class Producto {

public:

    string nombre;
    int cantidad;

    // Constructor
    Producto(string n, int c) {

        nombre = n;
        cantidad = c;
    }
};

// Clase Carrito
class Carrito {

private:

    queue<Producto> carrito;

public:

    // Agregar producto
    void agregarProducto(string nombre, int cantidad) {

        carrito.push(Producto(nombre, cantidad));

        cout << "Producto agregado: "
             << cantidad
             << " "
             << nombre
             << endl;
    }

    // Procesar pago
    void pagar() {

        if (carrito.empty()) {

            cout << "El carrito esta vacio."
                 << endl;

            return;
        }

        Producto p = carrito.front();

        cout << "Procesando pago de "
             << p.cantidad
             << " "
             << p.nombre
             << endl;

        carrito.pop();
    }

    // Mostrar carrito
    void mostrarCarrito() {

        if (carrito.empty()) {

            cout << "Carrito vacio."
                 << endl;

            return;
        }

        queue<Producto> temp = carrito;

        cout << "\nProductos en carrito:\n";

        while (!temp.empty()) {

            Producto p = temp.front();

            cout << p.cantidad
                 << " "
                 << p.nombre
                 << endl;

            temp.pop();
        }
    }
};

int main() {

    Carrito carrito;

    carrito.agregarProducto("Leches", 2);
    carrito.agregarProducto("Pan", 1);
    carrito.agregarProducto("Huevos", 12);

    cout << endl;

    carrito.mostrarCarrito();

    cout << endl;

    carrito.pagar();

    cout << endl;

    carrito.mostrarCarrito();

    return 0;
}

