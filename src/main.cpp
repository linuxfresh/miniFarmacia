/*
 * main.cpp
 *
 * Punto de entrada de la aplicación de farmacia/almacén.
 * Aquí se inicializan los módulos principales, se abre la base de datos,
 * se carga el inventario y se controla el flujo principal del programa
 * mediante menús y opciones de usuario. 
 * Es el archivo donde se enlazan todas las demás unidades (clases) y se ejecuta la lógica de negocio.
 */

#include <iostream>
#include <string>
#include "../modules/DBConnector.h"
#include "../modules/Producto.h"
#include "../modules/Cliente.h"
#include "../modules/Usuario.h"
#include "../modules/Venta.h"
#include "../modules/Inventario.h"

using namespace std;

/**
 * Programa principal: mini sistema de farmacia/almacén.
 * Permite CRUD de productos utilizando SQLite como persistencia.
 */

void mostrarMenu() {
    cout << "\n===== MENU MINI FARMACIA =====\n";
    cout << "1. Agregar producto\n";
    cout << "2. Listar productos\n";
    cout << "3. Actualizar producto\n";
    cout << "4. Eliminar producto\n";
    cout << "5. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {
    // Inicializar conexión con SQLite
    DBConnector db("farmacia.db");

    if (!db.isOpen()) {
        cerr << "No se pudo abrir la base de datos.\n";
        return 1;
    }

    // Crear tabla productos si no existe
    string sqlCreate =
        "CREATE TABLE IF NOT EXISTS productos ("
        "id INTEGER PRIMARY KEY, "
        "nombre TEXT NOT NULL, "
        "categoria TEXT NOT NULL, "
        "precio REAL NOT NULL, "
        "stock INTEGER NOT NULL);";
    db.execute(sqlCreate);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        if (opcion == 1) {
            int id, stock;
            double precio;
            string nombre, categoria;

            cout << "Ingrese ID: ";
            cin >> id;
            cout << "Ingrese nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese categoría: ";
            getline(cin, categoria);
            cout << "Ingrese precio: ";
            cin >> precio;
            cout << "Ingrese stock: ";
            cin >> stock;

            Producto p(id, nombre, categoria, precio, stock);
            p.guardar(db);

        } else if (opcion == 2) {
            Producto::listar(db);

        } else if (opcion == 3) {
            int id, stock;
            double precio;
            string nombre, categoria;

            cout << "Ingrese ID del producto a actualizar: ";
            cin >> id;
            cout << "Ingrese nuevo nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Ingrese nueva categoría: ";
            getline(cin, categoria);
            cout << "Ingrese nuevo precio: ";
            cin >> precio;
            cout << "Ingrese nuevo stock: ";
            cin >> stock;

            Producto p(id, nombre, categoria, precio, stock);
            p.actualizar(db);

        } else if (opcion == 4) {
            int id;
            cout << "Ingrese ID del producto a eliminar: ";
            cin >> id;

            Producto p(id, "", "", 0.0, 0);
            p.eliminar(db);

        } else if (opcion == 5) {
            cout << "Saliendo...\n";
        } else {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 5);

    return 0;
}
