/*
 * Producto.cpp
 *
 * Implementación de los métodos de la clase Producto.
 * Cada método realiza acciones sobre el producto, como mostrar información,
 * actualizar stock o aplicar descuentos.
 */

#include "Producto.h"
#include <iostream>
#include <sstream>
using namespace std;

// Constructor por defecto
Producto::Producto() : id(0), nombre(""), categoria(""), precio(0.0), stock(0) {}

// Constructor con parámetros
Producto::Producto(int id, string nombre, string categoria, double precio, int stock) {
    this->id = id;
    this->nombre = nombre;
    this->categoria = categoria;
    this->precio = precio;
    this->stock = stock;
}

// Getters
int Producto::getId() const { return id; }
string Producto::getNombre() const { return nombre; }
string Producto::getCategoria() const { return categoria; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

// Setters
void Producto::setId(int id) { this->id = id; }
void Producto::setNombre(string nombre) { this->nombre = nombre; }
void Producto::setCategoria(string categoria) { this->categoria = categoria; }
void Producto::setPrecio(double precio) { this->precio = precio; }
void Producto::setStock(int stock) { this->stock = stock; }

// Mostrar datos
void Producto::mostrarInfo() const {
    cout << "ID: " << id 
         << " | Nombre: " << nombre 
         << " | Categoria: " << categoria 
         << " | Precio: " << precio 
         << " | Stock: " << stock << endl;
}

// Guardar producto en la BD
bool Producto::guardar(DBConnector& db) {
    stringstream ss;
    ss << "INSERT INTO productos (id, nombre, categoria, precio, stock) VALUES ("
       << id << ", '" << nombre << "', '" << categoria << "', " 
       << precio << ", " << stock << ");";
    return db.execute(ss.str());
}

// Listar productos

/*
void Producto::listar(DBConnector& db) {
    string sql = "SELECT id, nombre, categoria, precio, stock FROM productos;";
    db.query(sql, [](int argc, char** argv, char** colNames) -> int {
        cout << "ID: " << argv[0] 
             << " | Nombre: " << argv[1]
             << " | Categoria: " << argv[2]
             << " | Precio: " << argv[3]
             << " | Stock: " << argv[4] << endl;
        return 0;
    });
}

*/

// Listar productos
void Producto::listar(DBConnector& db) {
    string sql = "SELECT id, nombre, categoria, precio, stock FROM productos;";

    bool headerPrinted = false;

    db.query(sql, [&headerPrinted](int argc, char** argv, char** colNames) -> int {
        // Imprimir cabecera solo una vez
        if (!headerPrinted) {
            for (int i = 0; i < argc; i++) {
                cout << colNames[i] << "\t";
            }
            cout << endl;
            cout << string(60, '-') << endl;
            headerPrinted = true;
        }

        // Imprimir los valores de cada fila
        for (int i = 0; i < argc; i++) {
            cout << (argv[i] ? argv[i] : "NULL") << "\t";
        }
        cout << endl;

        return 0;
    });
}


// Actualizar producto
bool Producto::actualizar(DBConnector& db) {
    stringstream ss;
    ss << "UPDATE productos SET nombre='" << nombre
       << "', categoria='" << categoria
       << "', precio=" << precio
       << ", stock=" << stock
       << " WHERE id=" << id << ";";
    return db.execute(ss.str());
}

// Eliminar producto
bool Producto::eliminar(DBConnector& db) {
    stringstream ss;
    ss << "DELETE FROM productos WHERE id=" << id << ";";
    return db.execute(ss.str());
}
