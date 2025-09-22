/*
 * Inventario.cpp
 *
 * Implementación de los métodos de la clase Inventario.
 * Permite administrar el stock de productos de forma centralizada.
 */

#include "Inventario.h"
#include <iostream>

void Inventario::agregarProducto(const Producto& prod) {
    productos.push_back(prod);
}

void Inventario::eliminarProducto(int id) {
    for(auto it = productos.begin(); it != productos.end(); ++it) {
        if(it->getId() == id) {
            productos.erase(it);
            break;
        }
    }
}

Producto* Inventario::buscarProducto(int id) {
    for(auto& p : productos)
        if(p.getId() == id) return &p;
    return nullptr;
}

void Inventario::mostrarTodos() const {
    for(const auto& p : productos)
        p.mostrarInfo();
}
