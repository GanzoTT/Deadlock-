# Deadlock en Ejecución de Hilos: Ejemplo de Solución

Este repositorio contiene un ejemplo de código en C que resuelve el problema clásico de deadlock en un programa con múltiples hilos, mediante el uso de un semáforo para sincronización controlada. El ejemplo simula una situación en la que dos personas deben coordinarse para pedir y aceptar disculpas sin caer en un estado de bloqueo mutuo.
Introducción

El deadlock ocurre cuando dos o más hilos quedan esperando indefinidamente la liberación de recursos que otro hilo posee, creando una espera circular y un bloqueo en la ejecución. Este ejemplo simplifica la lógica del programa para eliminar la posibilidad de espera circular, haciendo que los hilos actúen de forma secuencial y sin bloquearse entre sí.
Estrategia de Solución

Para resolver el problema del deadlock, se aplican las siguientes modificaciones:

    Uso de una variable de estado: se establece quién debe pedir disculpas y quién debe aceptar el error.
    Un solo semáforo: se reduce el uso de semáforos a solo uno (semaforo) para sincronizar ambos hilos, garantizando la secuencia correcta.
    
Descripción de los Cambios al Código base

    Eliminación de múltiples semáforos: Se utiliza un solo semáforo (semaforo) para coordinar la secuencia entre los hilos.
    Ejecución secuencial: El hilo que pide perdón notifica al otro hilo cuando ha realizado su acción, eliminando la posibilidad de espera circular.

Ejecución del Código

Sigue estos pasos para compilar y ejecutar el programa:  
  Requisitos previos

    - Asegúrate de tener gcc (compilador de C) y la biblioteca de pthread instalada.

Compilación y Ejecución

  Guardar el archivo: Guarda el código en un archivo llamado discusion.c.

  Compilar: Abre una terminal y navega hasta el directorio donde guardaste el archivo. Luego, ejecuta el siguiente comando para compilarlo:
  
    gcc discusion.c -o discusion -lpthread

    -lpthread: enlaza la biblioteca de hilos de POSIX (pthread).

Ejecutar: Para ejecutar el archivo compilado, usa el siguiente comando:

    ./discusion

Ejemplo de Salida

Cada vez que se ejecuta el programa, el resultado puede variar, ya que el orden de los hilos es aleatorio. Una salida típica podría verse de esta manera:
