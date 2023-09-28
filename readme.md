# UNIDAD 3 - Archivos Secuenciales

### Ejercicio 3.1

Los datos de los alumnos de una comisión de Computación Transversal son:
- Número de DNI (entero)
- Nombre y Apellido (80 caracteres)
- Nota1, Nota2 (entero)
- Nota Promedio (real, calculado según Nota1 y Nota2)

a. Declarar un tipo de dato que contenga la información del alumno.

b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta
información de grabación finaliza con DNI cero.

c. Leer los datos del archivo, mediante la Función LECTURA.

----

### Ejercicio 3.2

Tomando como base el archivo __ALUMNO.DAT__ creado en el ejercicio anterior se desea desarrollar un programa que, basado en la informacion del archivo, genere 3 archivos:
 - Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
 - Otro archivo con los alumnos en condicion CURSADO (ambas notas mayores o igual a 4 pero no promocionados).
 - Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).

Para comprobar los datos guardados realizar una funcion que reciba por parámetro el nombre del archivo a mostrar, lo abre y muestre su contenido. Se debe incovar a la funcion 3 veces para mostrar todos los archivos generados.