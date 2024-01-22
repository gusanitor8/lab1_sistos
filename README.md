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
  Actualmente al estar ejecutando una maquina virtual en docker, mi process id 1 corresponde a `tail`, que sirve para que el contenedor no se detenga al momento de que el proceso de bash se detenga.
  Sin embargo, comunmente suele ser el `init` process que es el que inicia el kernel cuando se está booteando y sirve como predecesor de todos los demás procesos.
  Tiene un papel especial en el sistema y es responsable de inicializar el sistema y generar otros procesos.

## Ejercicio 2
* Observe el resultado desplegado. ¿Por qué la primera llamada que aparece es `execve`?
  La llamada de sistema execve es la primera llamada en aparecer porque es la que inicia el proceso. La llamada execve carga el programa específico en el proceso actual.

* Ubique las llamadas de sistema realizadas por usted. ¿Qué significan los resultados (números que están luego del signo ‘=’)?
  Son los bytes que fueron escritos o leídos por la llamada.

* ¿Por qué entre las llamadas realizadas por usted hay un read vacío?
  <img width="496" alt="Screenshot 2024-01-21 at 10 13 59 PM" src="https://github.com/gusanitor8/lab1_sistos/assets/69366895/3bee8f7a-63b6-4f90-9d47-327168e41ded">
  No tengo ningún read vacío

* Identifique tres servicios distintos provistos por el sistema operativo en este strace. Liste y explique brevemente las llamadas a sistema que corresponden a los servicios identificados (puede incluir read, write, open o close que el sistema haga por usted, no los que usted haya producido directamente con su programa).

** Ejecución de procesos: **
``` bash
execve("./eje2", ["./eje2", "source.txt", "destination.txt"], 0x7fff477b2d90 /* 9 vars */) = 0
```
Esta llamada del sistema es responsable de ejecutar un programa. La ejecución de procesos es fundamental y es un servicio dado por el sistema operativo.

** Input y output **
Cuando hacemos un print el sistema maneja el standard output para desplegar esa información. 
``` bash
write(1, "bytes escritos: 19\n", 19bytes escritos: 19
)    = 19
```

** Manejo de memoria **
``` bash
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f991a8c4000
```
La llamada al sistema mmap se utiliza para asignar memoria en el adress space del proceso.
