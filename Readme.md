# Sistema de Gestión del Terminal Portuario Turístico de Buenaventura

## Descripción

Este proyecto consiste en el desarrollo de un sistema en lenguaje **C** para gestionar el funcionamiento del **Terminal Portuario Turístico de Buenaventura**.

El sistema administra de forma dinámica los destinos turísticos, las empresas de transporte marítimo, los pasajeros mediante colas **FIFO** y los viajes programados utilizando un **Árbol Rojo-Negro**, garantizando un balance automático del árbol después de cada inserción.

El proyecto fue desarrollado como parte de la asignatura **Estructuras de Datos**, aplicando el uso de apuntadores, memoria dinámica y estructuras de datos lineales y no lineales.

---

# Objetivo General

Diseñar e implementar un sistema que permita gestionar el funcionamiento básico del Terminal Portuario Turístico de Buenaventura mediante estructuras dinámicas en lenguaje C.

---

# Objetivos Específicos

* Registrar destinos de manera dinámica.
* Administrar pasajeros mediante colas FIFO.
* Gestionar viajes programados utilizando un Árbol Rojo-Negro.
* Evitar el registro duplicado de pasajeros.
* Consultar información de destinos, pasajeros y viajes.
* Generar estadísticas del sistema.
* Aplicar memoria dinámica mediante `malloc()` y `free()`.
* Organizar el proyecto de forma modular utilizando archivos `.h` y `.c`.

---

# Funcionalidades

El sistema permite:

* Registrar nuevos destinos.
* Buscar un destino por código.
* Mostrar todos los destinos registrados.
* Modificar la información de un destino.
* Consultar la cantidad de pasajeros en espera.
* Registrar pasajeros.
* Validar el tipo de documento del pasajero.
* Evitar pasajeros duplicados en cualquier destino.
* Mostrar todos los pasajeros de un destino.
* Consultar el primer pasajero de la cola.
* Embarcar pasajeros respetando el orden FIFO.
* Registrar viajes programados.
* Buscar viajes por código.
* Mostrar el Árbol Rojo-Negro de viajes.
* Consultar el estado de un pasajero.
* Generar estadísticas generales del sistema.

---

# Estructuras de Datos Implementadas

## Cola FIFO

Cada destino posee una cola independiente de pasajeros.

Las operaciones implementadas son:

* Registrar pasajero.
* Consultar el primer pasajero.
* Embarcar al primer pasajero.
* Mostrar pasajeros de un destino.
* Buscar pasajero por documento.
* Contar pasajeros en espera.
* Verificar si la cola está vacía.

La estructura FIFO garantiza que el primer pasajero registrado sea el primero en embarcar.

---

## Árbol Binario de Búsqueda (ABB)

El sistema utiliza un Árbol Binario de Búsqueda para organizar los registros históricos de los viajes mediante su código único.

Esto permite realizar búsquedas eficientes y mantener los viajes ordenados.

---

## Árbol Balanceado Rojo-Negro

Cada destino administra sus viajes programados mediante un **Árbol Rojo-Negro**.

Cada nodo del árbol almacena:

* Código único del viaje.
* Capacidad máxima del viaje.
* Color del nodo (Rojo o Negro).
* Apuntador al padre.
* Apuntador al hijo izquierdo.
* Apuntador al hijo derecho.

Después de insertar un nuevo viaje, el árbol realiza automáticamente las rotaciones y recoloraciones necesarias para conservar las propiedades del Árbol Rojo-Negro, garantizando una altura balanceada y un mejor rendimiento que un Árbol Binario de Búsqueda sin balancear.

---

# Relación entre las Estructuras

Cada destino almacena:

* Su información general.
* Una cola FIFO con los pasajeros en espera.
* La raíz del Árbol Rojo-Negro de viajes programados.

Gracias al uso de apuntadores, el sistema puede administrar dinámicamente cualquier cantidad de destinos sin utilizar arreglos de tamaño fijo.

---

# Menú Principal

El programa presenta el siguiente menú:

```text
1. Registrar destino
2. Registrar pasajero
3. Mostrar pasajeros por destino
4. Registrar viaje programado
5. Buscar viaje
6. Mostrar árbol de viajes
7. Realizar embarque
8. Consultar pasajero (en espera / embarcado)
9. Salir
```

El menú permanece activo hasta que el usuario seleccione la opción de salida.

---

# Tipos de Documento Permitidos

El sistema únicamente acepta los siguientes tipos de documento:

* Cédula de Ciudadanía
* Pasaporte
* Tarjeta de Identidad

Si se intenta registrar un tipo diferente, el sistema rechazará el registro.

---

# Estadísticas Implementadas

El sistema genera automáticamente:

* Promedio de pasajeros en espera por destino.
* Promedio de pasajeros embarcados por viaje.
* Destino con mayor cantidad de pasajeros en espera.
* Destino con menor cantidad de pasajeros en espera.
* Cantidad total de pasajeros registrados.
* Cantidad total de pasajeros embarcados.

---

# Estructura del Proyecto

```text
ProyectoTerminal/
│
├── include/
│   ├── destino.h
│   ├── pasajero.h
│   ├── viaje.h
│   ├── cola.h
│   ├── arbolRN.h
│   ├── estadisticas.h
│   └── menu.h
│
├── src/
│   ├── destino.c
│   ├── pasajero.c
│   ├── viaje.c
│   ├── cola.c
│   ├── arbolRN.c
│   ├── estadisticas.c
│   ├── menu.c
│   └── main.c
│
├── README.md
├── Makefile
└── informe.pdf
```

---

# Requisitos

* Lenguaje C
* Compilador GCC
* Make (opcional)
* Sistema operativo Windows, Linux o macOS

---

# Compilación

Compilar utilizando GCC:

```bash
gcc src/*.c -Iinclude -o terminal
```

O utilizando Makefile:

```bash
make
```

---

# Ejecución

En Linux o macOS:

```bash
./terminal
```

En Windows:

```bash
terminal.exe
```

---

# Gestión de Memoria

El proyecto utiliza memoria dinámica mediante las funciones:

* `malloc()`
* `calloc()`
* `free()`

Toda la memoria reservada durante la ejecución es liberada correctamente antes de finalizar el programa.

---

# Conceptos Aplicados

* Programación en C.
* Apuntadores.
* Memoria dinámica.
* Listas enlazadas.
* Colas FIFO.
* Árbol Binario de Búsqueda (ABB).
* Árbol Balanceado Rojo-Negro.
* Rotaciones.
* Recoloraciones.
* Modularidad.
* Archivos `.h` y `.c`.
* Compilación con GCC.

---

# Integrantes

# Loren Dayana Quintero Ramos  
# Yair Andrés Tapiero Gil
# Juan Manuel Cortes Paniagua

---

# Repositorio

El proyecto se desarrolla utilizando GitHub como sistema de control de versiones.

Todos los integrantes del grupo participan mediante commits propios y significativos, permitiendo evidenciar su aporte al desarrollo del sistema.

---



Proyecto desarrollado para la asignatura **Estructuras de Datos**.

**Universidad del Pacífico**
**Programa de Ingeniería de Sistemas**

