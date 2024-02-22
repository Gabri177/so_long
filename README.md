# so_long
## un proyecto sobre un breve videojuego de 2D usando minilibx de la escuala 42
![so_long](https://github.com/Gabri177/so_long/assets/152025617/507ddca0-33f5-42e7-a118-0f4834dbaeb9)

## Tecnicas usadas
* Leer archivo de mapa en nombre terminado con '.ber'
* Verificar si es valido el mapa leido.
  > Un mapa legal tiene que tener al menos una salida 'E', una moneda 'C', un espacio '0' y una posicion inicial 'P'
  > Tiene que ser rodeado por la pared '1'
  > No hay que aparecer otra caracter
  > El mapa tiene que ser rectángulo
* Deep first reserch algorithem para verificar si hay una solucion del mapa
* En el archivo H, vuelvo a definir un nuevo tipo de variable que era un matriz con un puntero de 3 dimenciones. Vuelvo a definir una variable de estructura , el cual lo uso como el elemento del matriz que había definido antes.
* Escribí mi propia función para detectar cada elemento en la matriz
* Usé minilibx para crear una ventana, hacer reacción según el key del teclado (movemos la persona, volver a dibujar el background y la pared.)
* Solisitar los eventos de hook para cerrar con éxito la ventana, mover el personaje etc.
* Control de errores incluso:
    * no leer con éxito los gráficos
    * error de leer mapa
    * error de los cretitos del mapa leido
    * ilegal caracter de la mapa
    * error con la establecimiento de la matriz
    * error de la memoria
    * etc.
