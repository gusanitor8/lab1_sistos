# Lab1 Sistemas Operativos
## Ejercicio 1

* Compile el primer programa y ejecútelo varias veces. Responda: ¿por qué aparecen números diferentes cada vez?
  Porque se le asigna un número de proceso difernte al programa cada vez que se ejecuta.
  
* Proceda a compilar el segundo programa y ejecútelo una vez. ¿Por qué aparecen dos números distintos a pesar de que estamos ejecutando un único programa?
  Porque uno es el proces id del proceso padre y otro es el proceso hijo
  
* ¿Por qué el primer y el segundo números son iguales?
  Porque es el proceso padre, cuando verificamos si el valor de `f` es 0 realmente estamos verificando si es el proceso hijo.
  Por esta razón el proceso padre entra al `else` donde se ejecuta el primer programa e imprime el número de proceso,
  posteriormente el número del proceso se vuelve a imprimir.
  
* En la terminal, ejecute el comando top (que despliega el top de procesos en cuanto a consumo de CPU) y note cuál es el primer proceso en la lista (con identificador 1). ¿Para qué sirve este proceso?
  <img width="536" alt="Screenshot 2024-01-21 at 6 19 31 PM" src="https://github.com/gusanitor8/lab1_sistos/assets/69366895/4af77022-5b35-41a9-a857-0d374858ba13">  
  Actualmente al estar ejecutando una maquina virtual en docker, mi process id 1 corresponde a tail, que sirve para que el contenedor no se detenga al momento de que el proceso de bash se detenga.
  Sin embargo, comunmente suele ser el `init` process que es el que inicia el kernel cuando se está booteando y sirve como predecesor de todos los demás procesos.
  Tiene un papel especial en el sistema y es responsable de inicializar el sistema y generar otros procesos.
