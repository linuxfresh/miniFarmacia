/*
 * Cliente.cpp
 *
 * Implementación de los métodos de la clase Cliente.
 * Permite registrar nuevas compras, actualizar datos del cliente
 * y mostrar información por consola.
 */

#include "Cliente.h"
#include "Venta.h"
#include <iostream>

Cliente::Cliente(int i, std::string n, std::string d, std::string t)
    : id(i), nombre(n), direccion(d), telefono(t) {}

void Cliente::registrarCompra(const Venta& venta) {
    historialCompras.push_back(venta);
}

void Cliente::mostrarInfo() const {
    std::cout << "ID: " << id << " | Nombre: " << nombre
              << " | Direccion: " << direccion
              << " | Telefono: " << telefono
              << " | Compras realizadas: " << historialCompras.size() << std::endl;
}

void Cliente::actualizarDatos(std::string n, std::string d, std::string t) {
    nombre = n;
    direccion = d;
    telefono = t;
}
