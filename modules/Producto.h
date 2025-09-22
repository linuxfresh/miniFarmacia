#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "DBConnector.h"
using namespace std;

/**
 * Clase Producto:
 * Representa un producto en la farmacia con sus datos básicos como id, nombre,
 * categoría, precio y stock.
 * Además incluye métodos CRUD que interactúan con SQLite mediante DBConnector.
 */
class Producto {
private:
    int id;
    string nombre;
    string categoria;
    double precio;
    int stock;

public:
    Producto();
    Producto(int id, string nombre, string categoria, double precio, int stock);

    // Getters
    int getId() const;
    string getNombre() const;
    string getCategoria() const;
    double getPrecio() const;
    int getStock() const;

    // Setters
    void setId(int id);
    void setNombre(string nombre);
    void setCategoria(string categoria);
    void setPrecio(double precio);
    void setStock(int stock);

    // Mostrar datos en consola
    void mostrarInfo() const;

    // Métodos CRUD
    bool guardar(DBConnector& db);
    static void listar(DBConnector& db);
    bool actualizar(DBConnector& db);
    bool eliminar(DBConnector& db);
};

#endif
