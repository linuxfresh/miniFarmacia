/*
 * Usuario.cpp
 *
 * Implementación de los métodos de la clase Usuario.
 * Permite validar login, mostrar información y administrar roles.
 */

#include "Usuario.h"
#include <iostream>

Usuario::Usuario(int i, std::string n, std::string u, std::string p, std::string r)
    : id(i), nombre(n), username(u), password(p), rol(r) {}

bool Usuario::validarLogin(const std::string& u, const std::string& p) const {
    return username == u && password == p;
}

void Usuario::mostrarInfo() const {
    std::cout << "ID: " << id << " | Nombre: " << nombre
              << " | Username: " << username
              << " | Rol: " << rol << std::endl;
}
