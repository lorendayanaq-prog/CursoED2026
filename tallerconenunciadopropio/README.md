## Integrantes:
- Loren Dayana Quintero Ramos
- Karol Nicol díaz Silva
- Mery Daniela Angulo Sinisterra

## Enunciado del problema

## Sistema de gestión de oyentes en radio en vivo

En una estación de radio en vivo, se requiere desarrollar un sistema para gestionar la participación de los oyentes durante un programa.
Los oyentes que desean participar se registran en una cola de llamadas (FIFO), respetando el orden de llegada. Cada oyente cuenta con la siguiente información: 

- Nombre 
- Ciudad
- Tema de participación

Cuando el presentador lo decide, los oyentes son retirados de la cola y clasificados según el tipo de intervención.

## Cola de llamadas

- Almacena los oyentes en espera.
- Se atienden en orden de llegada (FIFO).

## Pila

- Registra los participantes (oyentes) que decidieron participar o inscribirse en el sorteo del programa. 
- Funciona bajo el principio LIFO (Last In, First Out), donde el último oyente registrado en la pila es el primero en ser consultado o procesado.