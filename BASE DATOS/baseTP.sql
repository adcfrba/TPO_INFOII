CREATE DATABASE sensores;

show databases;

use sensores;
create table mediciones(
id_df int not null auto_increment,
nombre varchar(255),
fecha date,
temperatura float,
pulsaciones int,
oxigenacion float,
gas float,
primary key (id_df)
);

select * from mediciones;

INSERT INTO mediciones(nombre, fecha, temperatura, pulsaciones, oxigenacion, gas) values ('Antonella De Cia', '2023-08-11', '35.5', '99', '120', '0.42');

select *from mediciones;