/*
 * DBConnector.cpp
 *
 * Implementación de los métodos de la clase DBConnector.
 * Permite abrir y cerrar la conexión SQLite, y ejecutar consultas.
 * Todos los módulos de la aplicación pueden usar esta clase para interactuar con la base de datos.
 */

#include "DBConnector.h"
#include <iostream>
using namespace std;

DBConnector::DBConnector(const string& nombreBD) {
    if (sqlite3_open(nombreBD.c_str(), &db)) {
        cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        db = nullptr;
    }
}

DBConnector::~DBConnector() {
    if (db) {
        sqlite3_close(db);
    }
}

bool DBConnector::isOpen() const {
    return db != nullptr;
}

// Ejecutar SQL (INSERT, UPDATE, DELETE, CREATE, DROP)
bool DBConnector::execute(const string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "Error en SQL: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

// Ejecutar SELECT con callback
bool DBConnector::query(const string& sql, function<int(int, char**, char**)> callback) {
    char* errMsg = nullptr;

    // Adaptar std::function a C callback
    struct CallbackData {
        function<int(int, char**, char**)> func;
    } cbData{callback};

    auto c_callback = [](void* data, int argc, char** argv, char** colNames) -> int {
        CallbackData* cb = static_cast<CallbackData*>(data);
        return cb->func(argc, argv, colNames);
    };

    int rc = sqlite3_exec(db, sql.c_str(), c_callback, &cbData, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "Error en query: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
