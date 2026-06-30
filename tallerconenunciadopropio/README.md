## Integrantes:
- Loren Dayana Quintero Ramos
- Karol Nicol díaz Silva
- Mery Daniela Angulo Sinisterra

## Enunciado del problema

## SISTEMA DE GESTIÓN DE OYENTES EN RADIO EN VIVO

Desarrollar en lenguaje C una aplicación para gestionar la participación de los oyentes durante un programa de radio en vivo. Cada oyente que desee intervenir deberá registrarse con su nombre, ciudad y tema de participación, ingresando a una cola de llamadas. Los participantes serán atendidos por el presentador en el mismo orden en que realizaron su inscripción, aplicando el principio FIFO. Al finalizar cada llamada, el sistema deberá permitir registrar si el oyente desea participar en el sorteo organizado por la emisora.

Los oyentes que acepten participar en el sorteo deberán almacenarse en una pila, respetando en todo momento el principio LIFO. Por lo tanto, el último oyente inscrito será el primero en ser consultado, retirado o seleccionado durante el procesamiento del sorteo. La aplicación deberá integrar ambas estructuras dentro de un mismo flujo: los oyentes ingresan inicialmente a la cola de llamadas, son atendidos según su orden de llegada y, dependiendo de su decisión, pueden pasar posteriormente a la pila de participantes del sorteo.