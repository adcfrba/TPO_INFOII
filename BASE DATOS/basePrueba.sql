-- CREAR Y ELIMINAR BASE DE DATOS
CREATE DATABASE basePrueba; 
DROP DATABASE basePrueba;

CREATE DATABASE DBOne;
show databases;

-- CREAMOS TABLAS EN LAS BASE DE DATOS

use DBOne;

create table usuarios (
id_df int not null auto_increment,
nombre varchar (255),
apellido varchar (255),
primary key (id_df)
);

select * from usuarios;

-- MODIFICAR TABLAS DE BASE DE DATOS

ALTER TABLE usuarios RENAME TO users;
ALTER TABLE users ADD email varchar(255);

SHOW CREATE TABLE users;

CREATE TABLE `users` (
  `id_df` int NOT NULL AUTO_INCREMENT,
  `nombre` varchar(255) DEFAULT NULL,
  `apellido` varchar(255) DEFAULT NULL,
  `email` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id_df`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- INSERTAR DATOS DENTRO DE TABLA

INSERT INTO users (nombre, apellido, email) values ('Santiago', 'Carballo', 'scarballo@gmail.com');
select * from users;
INSERT INTO users (nombre, apellido, email) values ('Olivia', 'Vella', 'ovella@gmail.com');
select * from users;
INSERT INTO users (nombre, apellido, email) values ('Antonella', 'De Cia', 'adecia@gmail.com');

select * from users;

INSERT INTO users (nombre, apellido, email)
values
	('Santiago', 'Carballo', 'scarballo@gmail.com'),
	('Olivia', 'Vella', 'ovella@gmail.com'),
    ('Antonella', 'De Cia', 'adecia@gmail.com');
    
select apellido, email from users; -- mostrar solo el atributo que te digo

-- ELIMINAR TABLAS

SET SQL_SAFE_UPDATES = 0; 
DELETE FROM users WHERE nombre='Antonella';
SET SQL_SAFE_UPDATES = 1;
select * from users;


-- MODIFICAR REGISTROS DE UNA TABLA

update users set nombre = 'Gaston' WHERE id_df = 2;
select * FROM users;
   
   
-- VINCULAR TABLAS CON FOREING KEY

CREATE TABLE compras (
id_c int not null auto_increment,
comprador int,
producto varchar(50),
cantidad int,
primary key (id_c),
foreign key (comprador) references users (id_df)
);

INSERT INTO compras (comprador, producto, cantidad)
values
	(1, 'leche', 2),
    (4, 'arroz', 4),
    (2, 'yerba', 1);
    
select *from compras;