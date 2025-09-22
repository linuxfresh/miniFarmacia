/*
 * Usuario.h
 *
 * Declaración de la clase Usuario.
 * Representa un empleado o usuario del sistema.
 * Contiene información de login, rol y métodos para validar acceso.
 */

#ifndef USUARIO_H
#define USUARIO_H

#include <string>

/*
 * Usuario.h
 *
 * Representa un empleado/usuario del sistema.
 * Métodos para login y mostrar información.
 */

class Usuario {
private:
    int id;
    std::string nombre;
    std::string username;
    std::string password;
    std::string rol;

public:
    Usuario(int i = 0, std::string n = "", std::string u = "", std::string p = "", std::string r = "");
    bool validarLogin(const std::string& u, const std::string& p) const;
    void mostrarInfo() const;

    // Getters
    int getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getUsername() const { return username; }
    std::string getRol() const { return rol; }

    // Setters
    void setNombre(const std::string& n) { nombre = n; }
    void setUsername(const std::string& u) { username = u; }
    void setPassword(const std::string& p) { password = p; }
    void setRol(const std::string& r) { rol = r; }
};

#endif
