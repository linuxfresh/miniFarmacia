/*
 * Cliente.h
 *
 * Declaración de la clase Cliente.
 * Representa un cliente del almacén o farmacia.
 * Contiene información personal, historial de compras y métodos
 * para registrar compras y mostrar datos del cliente.
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
class Venta; // Forward declaration

/*
 * Cliente.h
 *
 * Representa un cliente con historial de compras.
 * Métodos para mostrar info, actualizar datos y registrar compras.
 */

class Cliente {
private:
    int id;
    std::string nombre;
    std::string direccion;
    std::string telefono;
    std::vector<Venta> historialCompras;

public:
    Cliente(int i = 0, std::string n = "", std::string d = "", std::string t = "");
    void registrarCompra(const Venta& venta);
    void mostrarInfo() const;
    void actualizarDatos(std::string nombre, std::string direccion, std::string telefono);

    // Getters
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getDireccion() const { return direccion; }
    std::string getTelefono() const { return telefono; }

    // Setters
    void setNombre(const std::string& n) { nombre = n; }
    void setDireccion(const std::string& d) { direccion = d; }
    void setTelefono(const std::string& t) { telefono = t; }
};

#endif
