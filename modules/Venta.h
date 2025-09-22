/*
 * Venta.h
 *
 * Declaración de la clase Venta.
 * Representa una transacción de venta de productos.
 * Contiene información sobre el cliente que compra, los productos involucrados,
 * cantidades, precio total, fecha de la venta y métodos para mostrar
 * y calcular el total de la venta.
 */

#ifndef VENTA_H
#define VENTA_H

#include <vector>
#include <string>
#include "Producto.h"

/*
 * Venta.h
 *
 * Representa una venta de productos a un cliente.
 * Métodos para agregar productos, calcular total y mostrar info.
 */

class Venta {
private:
    int id;
    int clienteId;
    std::vector<Producto> productos;
    double total;
    std::string fecha;

public:
    Venta(int i = 0, int cId = 0, std::string f = "");
    void agregarProducto(const Producto& prod);
    void calcularTotal();
    void mostrarVenta() const;

    // Getters
    int getId() const { return id; }
    int getClienteId() const { return clienteId; }
    double getTotal() const { return total; }
};

#endif
