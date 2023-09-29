# PROGRAMACION ESTRUCTURADA BASICA - EJERCICIOS

Indice:
- [Unidad 3](#unidad-3---archivos-secuenciales)
  - [Ejercicio 3.1](#ejercicio-31)
  - [Ejercicio 3.2](#ejercicio-32)
  - [Ejercicio 3.3](#ejercicio-33)
  - [Ejercicio 3.4](#ejercicio-34)
  - [Ejercicio 3.5](#ejercicio-35)


## UNIDAD 3 - Archivos Secuenciales

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

---

### Ejercicio 3.3

Se desea reliazar un programa que permita actualizar la lista de precios de una empresa en forma individual a cada uno de sus productos. \
La empresa trabaja con a lo sumo 100 productos que están guardados en el archivo __*productos.dat*__ con la siguiente estructura:
  - Código (entero)
  - Precio (float)
  - Descripcion (de hasta 50 caracteres)

Para modificar un precio se ingresa por teclado el código del producto y el nuevo precio. La modificación de precios finaliza con un código de producto igual a 0.

Al finalizar:
  1. Actualizar el archivo de productos con los nuevos precios.
  2. Exportar a un archivo con formato de texto (.csv) para que la lista de precios pueda ser visualizada directamente utilizando un programa de planillas de cálculo como por ejemplo el Excel.

---

### Ejercicio 3.4

Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje
de incremento. El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:
- Código (entero)
- Precio (float)
- Descripción (de hasta 50 caracteres)

No se sabe la cantidad de registros del archivo.
Se solicita generar un nuevo archivo llamado __*Precios_actualizados.dat.*__

### Ejercicio 3.5

Se dispone de un archivo llamado Stock.dat que contiene la informacion de los 10 productos que vende una fábrica. En el archivo se guarda:
- Código de artículo (entero)
- Descripción (50 caracteres máximo)
- Stock (entero)

Luego se ingresan por teclado las ventas a realizar indicando:
- Código de artículo
- Cantidad

La carga por teclado de las ventas finaliza con un código de artículo igual a 0.

Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar el stck de dicho producto, sino hay stock se debe vender lo que quede disponible y grabar un registro en un archivo Faltantes.dat con la cantidad que no pudo venderse, dicho registro debe contener:
- Código de artículo
- Cantidad

Se genera un registro por cada venta que no pudo concretarse, pudiendo quedar en el archivo varios registros faltantes del mismo producto.

Al finalizar actualizar el archivo Stock.dat con el stock actualizando luego de procesar las ventas.