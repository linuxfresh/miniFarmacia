/*
 * Inventario.h
 *
 * Declaración de la clase Inventario.
 * Administra todos los productos del almacén/farmacia.
 * Permite agregar, eliminar, buscar productos y actualizar stock.
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include "Producto.h"

/*
 * Inventario.h
 *
 * Administra todos los productos del almacén.
 * Métodos para agregar, eliminar, buscar y mostrar productos.
 */

class Inventario {
private:
    std::vector<Producto> productos;

public:
    Inventario() = default;
    void agregarProducto(const Producto& prod);
    void eliminarProducto(int id);
    Producto* buscarProducto(int id);
    void mostrarTodos() const;
};

#endif
