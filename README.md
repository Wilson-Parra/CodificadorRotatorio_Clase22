# CodificadorRotatorio_Clase22

Se definen dos variables enteras, A y B, que representan los pines digitales a los que se conecta el encoder. En este caso, A está en el pin digital 2 y B está en el pin digital 4.

Se definen dos variables enteras, ANTERIOR y POSICION. ANTERIOR almacena el valor anterior de POSICION, y POSICION es una variable global que se utiliza para almacenar la posición actual del encoder.

En la función setup(), se configuran los pines A y B como entradas digitales y se inicia la comunicación serial a una velocidad de 9600 baudios. También se adjunta una interrupción al pin A que ejecutará la función encoder cuando el nivel lógico en el pin A sea bajo (LOW).

El bucle principal (loop()) comprueba si el valor de POSICION ha cambiado en comparación con ANTERIOR. Si ha habido un cambio, se imprime el valor de POSICION en el monitor serial y se actualiza ANTERIOR con el valor actual de POSICION.

La función encoder() se llama cada vez que se produce una interrupción en el pin A. Esta función maneja la lectura del encoder rotativo y actualiza la variable POSICION en consecuencia.

Se declara una variable ultimaInterrupcion para almacenar el tiempo en el que ocurrió la última interrupción. Esto se utiliza para evitar la lectura de múltiples interrupciones muy cercanas en el tiempo.

Se obtiene el tiempo actual en milisegundos con millis() y se almacena en la variable tiempoInterrupcion.

Se verifica si ha transcurrido al menos 5 milisegundos desde la última interrupción para evitar la detección de rebotes o ruido del encoder.

Se lee el estado del pin B del encoder. Si está en alto (HIGH), se incrementa la variable POSICION. Si está en bajo, se decrementa la variable POSICION.

Se asegura de que la variable POSICION esté limitada entre 0 y 100 usando las funciones min() y max().

Este código permite controlar y leer la posición de un encoder rotativo y enviar los cambios de posición a través de la comunicación serial, lo que es útil en aplicaciones donde se necesita medir y registrar la posición de un eje rotativo.

