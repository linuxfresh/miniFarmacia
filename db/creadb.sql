-- SQLite
CREATE TABLE productos (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre TEXT,
    precio REAL,
    stock INTEGER,
    categoria TEXT
);

CREATE TABLE clientes (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nombre TEXT,
    edad INTEGER
);

CREATE TABLE ventas (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    idCliente INTEGER,
    idProducto INTEGER,
    cantidad INTEGER,
    fecha TEXT,
    FOREIGN KEY(idCliente) REFERENCES clientes(id),
    FOREIGN KEY(idProducto) REFERENCES productos(id)
);
.quit
