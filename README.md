# Sistema de Control de Ventas en C++

## Descripción

Este proyecto consiste en un sistema básico de control de ventas desarrollado en C++, que permite registrar ventas, almacenarlas en un archivo de texto, mostrar las ventas registradas, generar reportes generales y buscar ventas por monto.

El programa fue elaborado aplicando los temas vistos en clase, como estructuras de control, funciones, procedimientos y manejo de archivos con `fstream`.

---

## Funcionalidades

El sistema incluye las siguientes opciones:

1. **Registrar una venta**

   * Solicita:

     * Nombre del cliente
     * Nombre del producto
     * Cantidad
     * Precio unitario
     * Tipo de pago
   * Calcula:

     * Subtotal
     * Descuento
     * Total a pagar
   * Guarda la información en un archivo de texto.

2. **Mostrar todas las ventas**

   * Lee el archivo de ventas y muestra los registros guardados.

3. **Generar reporte general**

   * Muestra:

     * Total de ventas registradas
     * Suma total vendida
     * Promedio de ventas
     * Cantidad de ventas por tipo de pago
     * Cantidad de ventas con descuento

4. **Buscar ventas por monto**

   * Permite buscar ventas cuyo total sea mayor o igual a una cantidad ingresada.

---

## Archivos incluidos en el repositorio

* `main.cpp` → código fuente del programa
* `Registro de ventas.txt` → archivo donde se almacenan las ventas registradas
* `PRUEBA DE PROGRAMA` → capturas del funcionamiento del programa

---

**Bertha Leon**

