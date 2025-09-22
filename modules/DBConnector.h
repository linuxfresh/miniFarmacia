/*
 * DBConnector.h
 *
 * Declaración de la clase DBConnector.
 * Maneja la conexión con la base de datos SQLite.
 * Permite abrir y cerrar la conexión, ejecutar consultas
 * y abstrae detalles de la base de datos para los demás módulos.
 */
#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H

#include <sqlite3.h>
#include <string>
#include <functional>
using namespace std;

/**
 * Clase DBConnector:
 * Encapsula la conexión a SQLite y provee métodos
 * para ejecutar sentencias SQL y consultas con callbacks.
 */
class DBConnector {
private:
    sqlite3* db;

public:
    DBConnector(const string& nombreBD);
    ~DBConnector();

    bool isOpen() const;

    // Ejecutar INSERT, UPDATE, DELETE (retorna true si tuvo éxito)
    bool execute(const string& sql);

    // Ejecutar SELECT con callback para procesar filas
    bool query(const string& sql, function<int(int, char**, char**)> callback);
};

#endif
