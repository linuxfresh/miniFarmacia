/*
 * Venta.cpp
 *
 * Implementación de los métodos de la clase Venta.
 * Permite agregar productos a la venta, calcular el total
 * y mostrar la información completa de la transacción.
 */

#include "Venta.h"
#include <iostream>

Venta::Venta(int i, int cId, std::string f)
    : id(i), clienteId(cId), total(0.0), fecha(f) {}

void Venta::agregarProducto(const Producto& prod) {
    productos.push_back(prod);
    total += prod.getPrecio();
}

void Venta::calcularTotal() {
    total = 0;
    for (const auto& p : productos)
        total += p.getPrecio();
}

void Venta::mostrarVenta() const {
    std::cout << "Venta ID: " << id << " | Cliente ID: " << clienteId
              << " | Fecha: " << fecha << " | Total: " << total << std::endl;
    for (const auto& p : productos)
        p.mostrarInfo();
}

