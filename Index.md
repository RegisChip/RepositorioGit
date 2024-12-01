
# Proyecto - Sistemas Operativos

## Administración de Memoria
### 3.1 Política y Filosofía

1. ¿Cuál es la diferencia entre fragmentación interna y externa? 
Explica como cada una afecta el rendimiento de la memoria ✔️

La **fragmentación interna** ocurre cuando hay espacio interno malgastado debido al hecho de que el bloque de datos cargado es menor que la particion. Basicamente, se utiliza una particion con una memoria asignada grande es malgastada por un proceso de mucho menor.

La **fragmentación interna** afecta al dentimiento de la memoria principalmente por el desperdicio de espacio en la memoria. En un sistema de memoria virtual, tener una mayor fragmentación interna provocará que la tasa de fallos al almacenar datos y estructuras de control de memoria. Y en general, el rendimiento del equipo será más bajo con respiestas lentas y una menor capacidad para cargar trabajos en memoria.

Por otra parte la **fragmentación externa** ocurre cuando hay una cantidad suficiente de área dentro de la memoria para satisfacer la solicitud de memoria, sin embargo, no se puede cumplir la solicitud ya que la memoria libre esta intercala con la memoria usada.

La **fragmentación externa** generará una dificultad al asignar memoria para grandes bloques de datos, debido a lo dispersa que esta aún si en general se tiene memoria suficiente. En caso de una memoria virtual, la fragmentacion externa podría aumentar el uso de la memoria de intercambio (swap), ya que el sistema puede mover bloques de memoria activos a la memoria de intercambio para consolidar la memoria libre, provocando que se más lento acceder a la memoria principal.


2. Investiga y explica las politicas de reemplazo de páginas en sistemas operativos. ¿Cuál consideras más eficiente y por qué?

La politica de reemplazo es un algoritmo que tiene como objetivo reemplazar o eliminar la página que tenga menor posibilidad de ser referenciada en el futuro cercano. Mientras más sofisticado sea el algoritmo, mayor será la sobrecarga de hardware y software utilizada para implementarla.

* **LRU (Least Recently Used)** Algortimno que reemplaza la página que no ha sido utlizada durante más tiempo. Este algoritmo prioriza la carga de trabajos típicos, sin embargo, es costoso en términos de tiempo y espacio, ya que requiere seguimiento continuo del uso de las páginas.
* **FIFO (First In, First Out)**
Algoritmo reemplaza la página más antigua en la memoria (la que ingresó primero), este algoritmo es simple en su implementación, pero, pued egenerar resultados ineficientes como el problema *Belady* (más fallos de página al aumentar el tamaño de memoria).
* **Optimal**
Algoritmo que reemplaza la página que no se necesitará por más tiempo en el fututo. Este algoritmo ofrece el menor número de fallos de página, pero al no poder predecir que página no sé utilizará en el futuro, por lo que es un argoritmo en un sistema ideal.  

<!--

CUAL ES EL MÁS CHIDO

 -->


### 3.2 Memoria Real

1. Escribe un progarama en C o Python que simule la administración de memoria mediante particiones fijas. ✔️

```c

#include <stdio.h>
#include <stdbool.h>

#define maximoParticiones 10

typedef struct{
    int tamanio;
    bool isFree;
} Particion;

void printParticion(Particion particiones[], int particionCont){
    printf("\nEstado de las particiones:\n");
    for (int i = 0; i < particionCont; i++){
        printf("Particion %d: Tamaño = %d, Estado = %s 'n",
        i + 1, particiones[i].tamanio, particiones[i].isFree "Libre" : "Ocupado"
        );
    }
    printf("\n");
}

void asignarProceso(Particion particiones[], int particionCont){
    int procesoSize;
    printf("\nTamaño del proceso a asignar: ");
    scanf("%d", &procesoSize);

    for(int i = 0; i < particionCont; i++){
        if(particiones[i].isFree && particiones[i].tamanio >= procesoSize){
            particiones[i].isFree = false;
            printf("Proceso asignado a la particion %d.\n". i+1):
        }
    }
    printf("No hay partición disponible para el proceso.\n");
}

void realizarParticion(Particion particiones[], int particionCont) {
    int numeroParticion;
    printf("\nNúmero de partición a liberar: ");
    scanf("%d", &numeroParticion);

    if (numeroParticion < 1 || numeroParticion > particionCont) {
        printf("Número de partición inválido.\n");
        return;
    }

    if (!particiones[numeroParticion - 1].isFree) {
        particiones[numeroParticion - 1].isFree = true;
        printf("Partición %d liberada.\n", numeroParticion);
    } else {
        printf("La partición %d ya está libre.\n", numeroParticion);
    }
}

int main(){

    Particion particion[maximoParticiones];
    int particionCount;

    printf("Ingrese el número de particiones: ");
    scanf("%d", &particionCount);

    if (particionCount > maximoParticiones || particionCount <= 0) {
        printf("Número inválido de particiones. Debe estar entre 1 y %d.\n", maximoParticiones);
        return 1;
    }

    for (int i = 0; i < particionCount; i++) {
        printf("Tamaño de la partición %d: ", i + 1);
        scanf("%d", &particion[i].tamanio);
        particion[i].isFree = true;
    }

    int opcion;
    do {
        printf("\n--- Administrador de Memoria ---\n");
        printf("1. Ver particiones\n");
        printf("2. Asignar proceso\n");
        printf("3. Liberar partición\n");
        printf("4. Salir\n");
        printf("Elija una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printParticion(particion, particionCount);
                break;
            case 2:
                asignarProceso(particion, particionCount);
                break;
            case 3:
                realizarParticion(particion, particionCount);
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);

    return 0;
}

```


2. Diseña un algoritmo para calcular qué procesos pueden ser asignados a un sistema con memoria real limitada utilizando el algoritmo de "primera cabida". ✔️

```c

#include <stdio.h>
#include <stdbool.h>

#define maximoParticiones 20
#define maximoProcesos 20

void firstFit(int particiones[], bool isFree[], int particionCount, int proceso[], int procesoCount) {
    for (int i = 0; i < procesoCount; i++) {
        bool asignado = false;
        for (int j = 0; j < particionCount; j++) {
            if (isFree[j] && particiones[j] >= proceso[i]) {
                printf("Proceso %d (tamanio %d) asignado a particion %d (tamanio %d).\n", 
                        i + 1, proceso[i], j + 1, particiones[j]);
                isFree[j] = false;
                asignado = true;
                break;
            }
        }
        if (!asignado) {
            printf("Proceso %d (tamanio %d) no puede ser asignado.\n", i + 1, proceso[i]);
        }
    }
}

int main() {
    int particiones[maximoParticiones], proceso[maximoProcesos];
    bool isFree[maximoParticiones];
    int particionCount, procesoCount;

   
    printf("Ingrese el numero de particiones: ");
    scanf("%d", &particionCount);
    if (particionCount > maximoParticiones || particionCount <= 0) {
        printf("Numero invalido de particiones.\n");
        return 1;
    }

    for (int i = 0; i < particionCount; i++) {
        printf("Tamanio de la particion %d: ", i + 1);
        scanf("%d", &particiones[i]);
        isFree[i] = true;
    }

    
    printf("\nIngrese el numero de procesos: ");
    scanf("%d", &procesoCount);
    if (procesoCount > maximoProcesos || procesoCount <= 0) {
        printf("Numero invalido de procesos.\n");
        return 1;
    }

    for (int i = 0; i < procesoCount; i++) {
        printf("Tamanio del proceso %d: ", i + 1);
        scanf("%d", &proceso[i]);
    }

    
    printf("\n--- Asignacion de procesos ---\n");
    firstFit(particiones, isFree, particionCount, proceso, procesoCount);

    return 0;
}

```

### 3.3 Organización de memoria virtual

1. Investiga y explica el concepto de "paginación" y "segmentación". ¿Cuáles son las ventajas y desventajas de cada tecnica? ✔️

La **paginación** Divide la memoria en bloques de tamaño dijo (páginas). Es un modelo que organiza la memoria fija en el que se divide toda la memoria en porciones del mismo tamaño.

Ventajas:

* Mejora la gestión de la memoria.
* Reduce la probabilidad de errores y fallas de memoria.
* Evita que la memoria se corrompa o sobreescriba.

Desventajas:

* Puede presentar fragmentación interna.
* Puede ser una sobrecarga administrar las tablasm de páginas.

La **segmentación** divide la memoria en bloques de tamaño variable segun las necesidades logicas, es un esquema de manejo de memoria mediante el cual la estructura del programa refleja su división lógica; llevándose a cabo una agrupación lógica de la información en bloques de tamaño variable denominados segmentos.

Ventajas:

* Mejora de la Gestión de memoria.
* Espacio de direccionamiento.
* Protección de la memoria.

Desventajas:

* Fragmentacion Externa.
* Tiempo de Acceso.
* Espacio de direccionamiento limitado.


2. Escribe un programa que simule una tabla de páginas para procesos con acceso aleatorio a memoria virtual. ✔️

```c

#include <stdio.h>
#include <stdlib.h>
#include <tiempo.h>

#define paginas 4
#define marcos 8
#define paginasMax 16

typedef struct {
    int paginaNumero;
    int fragmentoNumero;
} Pagina;

void iniciarPaginaTabla(Pagina paginaTabla[], int paginaCont) {
    for (int i = 0; i < paginaCont; i++) {
        paginaTabla[i].paginaNumero = i;
        paginaTabla[i].fragmentoNumero = -1;
    }
}

void asignarFrames(Pagina paginaTabla[], int paginaCont) {
    int asignarFrame[FRAME_COUNT] = {0};
    for (int i = 0; i < paginaCont; i++) {
        int frame;
        do {
            frame = rand() % FRAME_COUNT;
        } while (asignarFrame[frame] == 1);

        paginaTabla[i].fragmentoNumero = frame;
        asignarFrame[frame] = 1;
    }
}

void imprimirPaginaTabla(Pagina paginaTabla[], int paginaCont) {
    printf("\nTabla de Paginas:\n");
    printf("Pagina\tMarco\n");
    for (int i = 0; i < paginaCont; i++) {
        printf("%d\t%d\n", paginaTabla[i].paginaNumero, paginaTabla[i].fragmentoNumero);
    }
}

void accederMemoria(Pagina paginaTabla[], int paginaCont) {
    int direccionVirtual;
    printf("\nIngrese una direccion virtual (en KB): ");
    scanf("%d", &direccionVirtual);

    int paginaNumero = direccionVirtual / paginas;
    int offset = direccionVirtual % paginas;

    if (paginaNumero >= paginaCont) {
        printf("Direccion virtual fuera de rango. (Pagina %d no existe)\n", paginaNumero);
    } else if (paginaTabla[paginaNumero].fragmentoNumero == -1) {
        printf("Fallo de pagina. Pagina %d no esta cargada en memoria.\n", paginaNumero);
    } else {
        int fragmentoNumero = paginaTabla[paginaNumero].fragmentoNumero;
        int direccionFisica = fragmentoNumero * paginas + offset
        printf("Direccion virtual %d KB -> Direccion fisica %d KB (Pagina %d, Marco %d, Desplazamiento %d)\n",
               direccionVirtual, direccionFisica, paginaNumero, fragmentoNumero, offset);
    }
}

int main() {
    srand(tiempo(NULL));

    Pagina paginaTabla[paginasMax];
    int paginaCont;

    printf("Ingrese el numero de paginas del proceso (maximo %d): ", paginasMax);
    scanf("%d", &paginaCont);
    if (paginaCont <= 0 || paginaCont > paginasMax) {
        printf("Numero de paginas invalido.\n");
        return 1;
    }

    iniciarPaginaTabla(paginaTabla, paginaCont);
    asignarFrames(paginaTabla, paginaCont);
    imprimirPaginaTabla(paginaTabla, paginaCont);

    char opcion;
    do {
        accederMemoria(paginaTabla, paginaCont);
        printf("\n¿Desea acceder a otra direccion? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    printf("Saliendo de la simulacion.\n");
    return 0;
}

```


### 3.4 Administración de memoria virtual

1. Escribe un código que implemente el algoritmo de reemplazo de página "Least Recently Used" (LRU).

```c

#include <stdio.h>
#include <stdbool.h>

#define paginasMaximo 100
#define framesMaximo 10

void imprimirFrames(int frames[], int frameCont) {
    printf("[");
    for (int i = 0; i < frameCont; i++) {
        if (frames[i] != -1)
            printf(" %d ", frames[i]);
        else
            printf(" - ");
    }
    printf("]\n");
}

int encontrarLRU(int accesoTiempo[], int frameCont) {
    int indice = 0;
    for (int i = 1; i < frameCont; i++) {
        if (accesoTiempo[i] < accesoTiempo[indice])
            indice = i;
    }
    return indice;
}

void LRU(int paginas[], int paginaCont, int frameCont) {
    int frames[framesMaximo], accesoTiempo[framesMaximo];
    int falla = 0, tiempo = 0;

    
    for (int i = 0; i < frameCont; i++) {
        frames[i] = -1;
        accesoTiempo[i] = 0;
    }

    printf("\nProceso de reemplazo LRU:\n");
    for (int i = 0; i < paginaCont; i++) {
        bool paginaEncontrada = false;

        for (int j = 0; j < frameCont; j++) {
            if (frames[j] == paginas[i]) {
                paginaEncontrada = true;
                accesoTiempo[j] = tiempo;
                break;
            }
        }

        if (!paginaEncontrada) {
            int remIndice;
            if (frames[frameCont - 1] == -1) {
                for (remIndice = 0; remIndice < frameCont; remIndice++) {
                    if (frames[remIndice] == -1)
                        break;
                }
            } else {
                remIndice = encontrarLRU(accesoTiempo, frameCont);
            }

            frames[remIndice] = paginas[i];
            accesoTiempo[remIndice] = tiempo;
            falla++;
        }

        printf("Acceso a página %d -> ", paginas[i]);
        imprimirFrames(frames, frameCont);
        tiempo++;
    }

    printf("\nNúmero total de fallos de página: %d\n", falla);
}

int main() {
    int paginas[paginasMaximo], paginaCont, frameCont;

    printf("Ingrese el número de accesos a páginas: ");
    scanf("%d", &paginaCont);

    if (paginaCont <= 0 || paginaCont > paginasMaximo) {
        printf("Número de accesos inválido.\n");
        return 1;
    }

    printf("Ingrese las páginas (secuencia de accesos):\n");
    for (int i = 0; i < paginaCont; i++) {
        printf("Página %d: ", i + 1);
        scanf("%d", &paginas[i]);
    }

    printf("Ingrese el número de marcos de página disponibles: ");
    scanf("%d", &frameCont);

    if (frameCont <= 0 || frameCont > framesMaximo) {
        printf("Número de marcos inválido.\n");
        return 1;
    }

    LRU(paginas, paginaCont, frameCont);

    return 0;
}

```


2. `Diseña un diagrama que represente el proceso de traducción de direcciones virtuales a físicas en un sistema con memoria virtual.`

uuuuuu

### Integración

1. `Analiza un sistema operativo moderno (por ejemplo, Linux o Windows) e identifica cómo administra la memoria virtual.`

uuuuuu

2. `Realiza una simulación en cualquier lenguaje de programación que emule el swapping de procesos en memoria virtual.`

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanioRAM 100
#define tamanioSWAP 200
#define procesosMaximo 10

typedef struct {
    int id;
    int tamanio;
    int enMemory;
} Proceso;

void imprimirMemoria(Proceso ram[], int ramCont, Proceso swap[], int swapCont) {
    printf("\n--- Estado de la Memoria ---\n");
    printf("RAM:\n");
    for (int i = 0; i < ramCont; i++) {
        printf("Proceso %d (%d MB)\n", ram[i].id, ram[i].tamanio);
    }
    printf("Espacio libre en RAM: %d MB\n", tamanioRAM - (ramCont ? ram[ramCont - 1].tamanio : 0));

    printf("\nSwap:\n");
    for (int i = 0; i < swapCont; i++) {
        printf("Proceso %d (%d MB)\n", swap[i].id, swap[i].tamanio);
    }
    printf("Espacio libre en Swap: %d MB\n", tamanioSWAP - (swapCont ? swap[swapCont - 1].tamanio :0));

}

int getMemoriaUsada(Proceso ram[], int ramCont) {
    int memoriaUsada = 0;
    for (int i = 0; i < ramCont; i++) {
        memoriaUsada += ram[i].tamanio;
    }
    return memoriaUsada;
}

int getSwapUsado(Proceso swap[], int swapCont) {
    int swapUsado = 0;
    for (int i = 0; i < swapCont; i++) {
        swapUsado += swap[i].tamanio;
    }
    return swapUsado;
}

void hacerSwapping(Proceso ram[], int *ramCont, Proceso swap[], int *swapCont, int espacio) {
    while (getMemoriaUsada(ram, *ramCont) + espacio > tamanioRAM) {
        if (*swapCont >= procesosMaximo) {
            printf("Swap lleno. No se puede realizar más swapping.\n");
            exit(1);
        }

        Proceso procesoSWAP = ram[0];
        printf("Moviendo Proceso %d (%d MB) de RAM a Swap.\n", procesoSWAP.id, procesoSWAP.tamanio);

        swap[(*swapCont)++] = procesoSWAP;

        for (int i = 0; i < *ramCont - 1; i++) {
            ram[i] = ram[i + 1];
        }
        (*ramCont)--;
    }
}

int main() {
    Proceso ram[procesosMaximo];
    Proceso swap[procesosMaximo];
    int ramCont = 0, swapCont = 0;

    int opcion;
    int procesoID = 1;

    printf("Simulación de Swapping de Procesos en Memoria Virtual\n");

    while (1) {
        printf("\n1. Añadir proceso\n2. Mostrar estado de la memoria\n3. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            int tamanioProceso;
            printf("Ingrese el tamaño del proceso (MB): ");
            scanf("%d", &tamanioProceso);

            if (tamanioProceso > tamanioRAM) {
                printf("El proceso es demasiado grande para la RAM. Operación cancelada.\n");
                continue;
            }

            if (getMemoriaUsada(ram, ramCont) + tamanioProceso > tamanioRAM) {
                printf("No hay suficiente espacio en RAM. Realizando swapping...\n");
                hacerSwapping(ram, &ramCont, swap, &swapCont, tamanioProceso);
            }

            if (ramCont < procesosMaximo) {
                ram[ramCont].id = procesoID++;
                ram[ramCont].tamanio = tamanioProceso;
                ram[ramCont].enMemory = 1;
                ramCont++;
                printf("Proceso %d (%d MB) añadido a RAM.\n", procesoID - 1, tamanioProceso);
            } else {
                printf("No se puede añadir el proceso. RAM llena.\n");
            }
        } else if (opcion == 2) {
            imprimirMemoria(ram, ramCont, swap, swapCont);
        } else if (opcion == 3) {
            printf("Saliendo de la simulación.\n");
            break;
        } else {
            printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}


```


---
## Administración de Entrada/Salida

### 4.1 Dispositivos y manejadores de dispositivos

1. Explica la diferencia entre dispositivos de bloque y dispositivos de carácter. Da un ejemplo de cada uno. ✔️

Los **dispositivos de bloque** es un dispositivo de almacenamiento de datos que administra detos en segmentos de tamaño fijo, conocidos como bloques. Estos bloques son la unidad de datos más pequeña que el dispositivo puede leer o escribir.

Los **dispositivos de carácter** son componentes que se comunican con la unidad central de proceso a través de bytes individuales. Se acceden secuencialmente, un carácter a la vez, y se pueden considerar como un flujo de bytes. Algunos ejemplos de dispositivos de carácter son el teclado, el ratón, un terminal de texto o una cinta magnética.

Diferencias entre los dispositivos:

* **Dispositivos de bloque** Estos dispositivos manejan datos en bloques de tamaño fijo y permiten un acceso aleatorio eficiente a los datos. Son ideales para almacenar grandes volúmenes de información.

* **Dispositivos de carácter** Manejan datos como una corriente continua, procesándolos en el orden en que llegan, lo cual es ideal para dispositivos que requieren procesamiento inmediato de datos.



2. `Diseña un progama que implemente un manejador de dispositivos sencillo para un dispositivo virtual de entrada.`

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char buffer[BUFFER_SIZE];
    int head;               
    int tail;   
    int isConnected; 
} VirtualDevice;

void initializeDevice(VirtualDevice *device) {
    memset(device->buffer, 0, BUFFER_SIZE);
    device->head = 0;
    device->tail = 0;
    device->isConnected = 1;
    printf("Dispositivo inicializado y conectado.\n");
}

void receiveData(VirtualDevice *device, const char *data) {
    if (!device->isConnected) {
        printf("El dispositivo no está conectado.\n");
        return;
    }

    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        if ((device->head + 1) % BUFFER_SIZE == device->tail) {
            printf("El búfer está lleno. Datos descartados.\n");
            return;
        }
        device->buffer[device->head] = data[i];
        device->head = (device->head + 1) % BUFFER_SIZE;
    }
    printf("Datos recibidos: %s\n", data);
}

void readData(VirtualDevice *device) {
    if (!device->isConnected) {
        printf("El dispositivo no está conectado.\n");
        return;
    }

    if (device->head == device->tail) {
        printf("El búfer está vacío. No hay datos para leer.\n");
        return;
    }

    printf("Datos leídos: ");
    while (device->head != device->tail) {
        printf("%c", device->buffer[device->tail]);
        device->tail = (device->tail + 1) % BUFFER_SIZE;
    }
    printf("\n");
}

void disconnectDevice(VirtualDevice *device) {
    device->isConnected = 0;
    printf("Dispositivo desconectado.\n");
}

void connectDevice(VirtualDevice *device) {
    device->isConnected = 1;
    printf("Dispositivo conectado.\n");
}

int main() {
    VirtualDevice device;
    initializeDevice(&device);

    int opcion;
    char inputData[BUFFER_SIZE];

    while (1) {
        printf("\n--- Manejador de Dispositivos ---\n");
        printf("1. Recibir datos\n");
        printf("2. Leer datos\n");
        printf("3. Conectar dispositivo\n");
        printf("4. Desconectar dispositivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1:
                printf("Ingrese los datos a recibir: ");
                fgets(inputData, BUFFER_SIZE, stdin);
                inputData[strcspn(inputData, "\n")] = '\0';
                receiveData(&device, inputData);
                break;

            case 2:
                readData(&device);
                break;

            case 3:
                connectDevice(&device);
                break;

            case 4:
                disconnectDevice(&device);
                break;

            case 5:
                printf("Saliendo del programa.\n");
                exit(0);

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}

```


### 4.2 Mecanismos y funciones de los manejadores de dispositivos

1. Investiga qué es la interrupción por E/S y cómo la administra el sistema operativo. Escribe un ejemplo en pseudocódigo para simular este proceso.

Una **interrupción** viene determinada por la ocurrencia de una señal externa que provoca la bifurcación a una dirección especifica de memoria, interrumpiendo temporalmente la ejecución del programa principal. Así que, una **interrupción por entrada y salida (E/S)** es un mecanismo que altera el orden de ejecución de instrucciones en respuesta a un evento externo. Este evento es generado por el *hardware* de entrada y salida de manera asincrónica, es decir, fuera del control del programa que se está ejecutando


<!-- PONER UN PSEUDOCODIGOOOO-->

2. `Escribe un programa que utilice el manejo de interrupciones en un sistema básico de simulación.`

```c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t interruptFlag = 0;

void handleInterrupt(int signal) {
    if (signal == SIGINT) {
        printf("\nInterrupción recibida: SIGINT (Ctrl+C)\n");
        interruptFlag = 1;
    } else if (signal == SIGUSR1) {
        printf("\nInterrupción recibida: SIGUSR1 (personalizada)\n");
    }
}

void simulateTask() {
    printf("Simulando tarea... Presiona Ctrl+C para interrumpir.\n");
    for (int i = 0; i < 10; i++) {
        if (interruptFlag) {
            printf("Tarea interrumpida por SIGINT. Guardando estado y finalizando.\n");
            return;
        }
        printf("Ejecutando paso %d...\n", i + 1);
        sleep(1);
    }
    printf("Tarea completada exitosamente.\n");
}

int main() {
    signal(SIGINT, handleInterrupt);
    signal(SIGUSR1, handleInterrupt);

    while (1) {
        printf("\n--- Sistema Básico de Simulación ---\n");
        printf("1. Ejecutar tarea\n");
        printf("2. Enviar señal SIGUSR1\n");
        printf("3. Salir\n");
        printf("Seleccione una opción: ");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                interruptFlag = 0;
                simulateTask();
                break;
            case 2:
                raise(SIGUSR1);
                break;
            case 3:
                printf("Saliendo del programa.\n");
                exit(0);
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}


```


### 4.3 Estructura de datos para manejo de dispositivos

1. Investiga y explica qué es una cola E/S. Diseña una simulación de una cola con prioridad.

Una **cola de entrada/salida (E/S)** es una estructura de datos utilizada para gestionar las solicitudes de entrada y salida de datos entre el sistema y los dispositivos periféricos. Es una cola (generalmente *FIFO*) en la que se almacenan las solicitudes de E/S a medida que se generan. Las solicitudes se procesan en el orden en que llegan.

<!-- HACER UNA SIMULACION -->
```c

int main(){
    return 0;
}

```


2. `Escribe un programa que simule las operaciones de un manejo de dispositivos utilizando una tabla de estructuras.`

```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 5

typedef struct {
    int id;                     
    char name[20];
    int isConnected; 
    void (*read)(int id);  
    void (*write)(int id); 
} Device;

void readDevice(int id) {
    printf("Leyendo datos del dispositivo %d...\n", id);
    printf("Datos leídos: 'Hola desde el dispositivo %d'.\n", id);
}

void writeDevice(int id) {
    printf("Escribiendo datos al dispositivo %d...\n", id);
    printf("Datos escritos: 'Mensaje enviado al dispositivo %d'.\n", id);
}

void connectDevice(Device* device) {
    if (device->isConnected) {
        printf("El dispositivo %d ya está conectado.\n", device->id);
    } else {
        device->isConnected = 1;
        printf("El dispositivo %d ha sido conectado.\n", device->id);
    }
}

void disconnectDevice(Device* device) {
    if (!device->isConnected) {
        printf("El dispositivo %d ya está desconectado.\n", device->id);
    } else {
        device->isConnected = 0;
        printf("El dispositivo %d ha sido desconectado.\n", device->id);
    }
}

void showDeviceStatus(Device devices[], int numDevices) {
    printf("\nEstado de los dispositivos:\n");
    for (int i = 0; i < numDevices; i++) {
        printf("Dispositivo %d (%s): %s\n", devices[i].id, devices[i].name,
               devices[i].isConnected ? "Conectado" : "Desconectado");
    }
}

int main() {
    Device devices[MAX_DEVICES] = {
        {1, "Dispositivo A", 0, readDevice, writeDevice},
        {2, "Dispositivo B", 0, readDevice, writeDevice},
        {3, "Dispositivo C", 0, readDevice, writeDevice},
        {4, "Dispositivo D", 0, readDevice, writeDevice},
        {5, "Dispositivo E", 0, readDevice, writeDevice}
    };

    int opcion, deviceId;

    while (1) {
        printf("\n--- Menú de Manejo de Dispositivos ---\n");
        printf("1. Conectar dispositivo\n");
        printf("2. Desconectar dispositivo\n");
        printf("3. Leer datos de un dispositivo\n");
        printf("4. Escribir datos en un dispositivo\n");
        printf("5. Ver estado de todos los dispositivos\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el ID del dispositivo a conectar (1-5): ");
                scanf("%d", &deviceId);
                if (deviceId >= 1 && deviceId <= 5) {
                    connectDevice(&devices[deviceId - 1]);
                } else {
                    printf("ID de dispositivo no válido.\n");
                }
                break;

            case 2:
                printf("Ingrese el ID del dispositivo a desconectar (1-5): ");
                scanf("%d", &deviceId);
                if (deviceId >= 1 && deviceId <= 5) {
                    disconnectDevice(&devices[deviceId - 1]);
                } else {
                    printf("ID de dispositivo no válido.\n");
                }
                break;

            case 3:
                printf("Ingrese el ID del dispositivo para leer datos (1-5): ");
                scanf("%d", &deviceId);
                if (deviceId >= 1 && deviceId <= 5) {
                    if (devices[deviceId - 1].isConnected) {
                        devices[deviceId - 1].read(deviceId);
                    } else {
                        printf("El dispositivo %d no está conectado.\n", deviceId);
                    }
                } else {
                    printf("ID de dispositivo no válido.\n");
                }
                break;

            case 4:
                printf("Ingrese el ID del dispositivo para escribir datos (1-5): ");
                scanf("%d", &deviceId);
                if (deviceId >= 1 && deviceId <= 5) {
                    if (devices[deviceId - 1].isConnected) {
                        devices[deviceId - 1].write(deviceId);
                    } else {
                        printf("El dispositivo %d no está conectado.\n", deviceId);
                    }
                } else {
                    printf("ID de dispositivo no válido.\n");
                }
                break;

            case 5:
                showDeviceStatus(devices, MAX_DEVICES);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                exit(0);

            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    }

    return 0;
}


```

### 4.4 Operaciones de Entrada/Salida

1. `Diseña un flujo que describa el proceso de lectura de un archivo desde un disco magnético. Acompáñalo con un programa básico que simule el proceso.`

uuuuuu

2. `Implementa un programa en Python, C o java que realice operaciones de entrada/salida asíncronas usando archivos.`

uuuuuu

### Integración

1. `Escribe un programa que implemente el algoritmo de planificación de discos "Elevator (SCAN)".`

uuuuuu

2. `Diseña un sistema que maneje múltiples dispositivos simulados (disco duro, impresora, teclado) y muestra cómo se realiza la comunicación entre ellos.`

uuuuuu

### Avanzados

1. `Explica cómo los sistemas operativos modernos optimizan las operaciones de entrada/salida con el uso de la memoria caché.`

uuuuuu


