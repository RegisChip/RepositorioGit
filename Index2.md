# ACTIVIDAD FINAL

## SISTEMAS DE ARCHIVO

### EJERCICIO 1: Concepto y noción de archivo real y virtual.

**Descripción**
Define los conceptos de archivo real y archivo virtual y explica sus diferencias.
Identifica ejemplos prácticos de cada tipo en sistemas operativos actuales.

**Tareas**

* Define el concepto de archivo real y archivo virtual. ✔️

Un **archivo virtual** es un archivo de uso temporal que se utilizado por los procesos del sistema mientras se están ejecutando dichos procesos.
Estos archivos se crean durante la ejecución de un sistema y los utiliza para el almacenamiento de información, intercambio y organización mientras se ejecuta el sistema, su tamaño es muy variable y terminan al detener la ejecución del sistema, muchos de ellos son borrados, por ejemplo, los archivos *.tmp.
Se le conoce como archivo virtual, aquel que contiene los datos generados por el usuario.

Por otra parte, un **archivo real** es un objeto que contiene programas, datos o cualquier otro elemento. 
Un archivo se muestra de manera real, en la información del espacio que ocupa en un disco duro o sistema de almacenamiento, en otras palabras, su tamaño es en bytes.


* Proporciona ejemplos de cómo los sistemas operativos manejan archivos reales y virtuales. ✔️

En un sistema operativo como Windows, cuando guardas un documento de texto, el archivo se almacena físicamente en el disco duro. Por ejemplo, al escribir y guardar un archivo llamado informe.txt, el sistema operativo busca espacio libre en el disco, lo divide en pequeños bloques, y almacena fragmentos del archivo en esos bloques. Luego crea una entrada en una tabla especial del sistema de archivos (como la tabla MFT en NTFS) para registrar la ubicación de esos bloques y otros datos como el nombre, tamaño, y permisos del archivo. Cuando abres informe.txt más tarde, el sistema usa esa información para localizar y reconstruir el archivo completo desde los bloques físicos, mostrándotelo en el editor de texto.

Por otro lado, en Linux, si consultas el archivo /proc/cpuinfo, no estás accediendo a algo almacenado físicamente en el disco. Este archivo es virtual y existe únicamente en memoria. Cuando pides leerlo, el sistema operativo genera su contenido en tiempo real, recopilando información del procesador directamente del kernel. Esto significa que cada vez que lo consultas, obtienes una respuesta actualizada sin ocupar espacio en el almacenamiento físico.

* Explica un caso práctico donde un archivo virtual sea más útil que un archivo real. ✔️

Un ejemplo práctico de un archivo virtual más útil que uno real es ajustar el brillo de la pantalla en Linux mediante /sys/class/backlight/intel_backlight/brightness. Este archivo virtual permite cambiar el brillo en tiempo real escribiendo un valor, por ejemplo:

```bash

echo 500 > /sys/class/backlight/intel_backlight/brightness

```

El sistema interpreta este valor y ajusta el hardware sin escribir en el disco ni reiniciar. Es rápido, seguro y eficiente, mientras que usar un archivo real sería más lento y propenso a errores.

### EJERCICIO 2: Componentes de un sistema de archivos.

**Descripción**
Investiga los componentes principales de un sistema de archivos y compáralos entre dos sistemas operativos, como Linux y Windows.

**Tareas**

* Identifica los componentes clave de un sistema de archivos (por ejemplo, metadatos, tabla de asignación, etc.). ✔️

**Métodos de acceso** relacionados con la manera de acceder a los datos almacenados en archivos.

**Administración de archivo** referida a la provisión de mecanismos para que los archivos sean almacenados, referenciados, compartidos y asegurados.

**Administración del almacenamiento auxiliar** para la asignación de espacio a los archivos en los dispositivos de almacenamiento secundario.

**Integridad del archivo** para garantizar la integridad de la información del archivo.

* Crea un cuadro comparativo de cómo estos componentes funcionan en sistemas como EXT4 y NTFS. ✔️

| Componentes | EXT4 (Linux) | NTFS (Windows) |
|----------|----------|----------|
| Métodos de acceso    | Usa inodos para almacenar metadatos y acceder a los archivos de manera eficiente.  | Usa la MFT para gestionar metadatos y permitir un acceso rápido a los archivos.   |
| Admnistración de archivos    | Los archivos se gestionan mediante inodos, permitiendo enlaces duros y simbólicos para compartirlos.   | Utiliza la MFT para almacenar metadatos y permite compartir archivos con control detallado de acceso.   |
| Aministración del almacenamiento auxiliar    | Organiza el espacio en grupos de bloques para una distribución eficiente del espacio en disco.  | Utiliza clusters y una tabla para gestionar el espacio, con opciones de compresión y control de fragmentación.   |
| Integridad del archivo    | Implementa journaling para registrar cambios y usar checksums para verificar la integridad.   | Usa journaling y una estructura de metadatos para garantizar la consistencia y recuperación en caso de fallos.   |


* Describe las ventajas y desventajas de cada sistema basado en sus componentes. ✔️

EXT4 usa un sistema basado en inodos, lo que permite un acceso rápido y eficiente a los archivos, pero no ofrece tanta flexibilidad como NTFS, que utiliza la MFT para manejar más metadatos y un control más detallado de los archivos. En cuanto a la administración de archivos, EXT4 es más simple y adecuado para compartir archivos mediante enlaces, mientras que NTFS ofrece un control granular de permisos mediante ACLs, lo que lo hace ideal para entornos con altas necesidades de seguridad.

Para la administración del almacenamiento, EXT4 organiza el espacio en bloques y grupos, lo que lo hace eficiente, aunque puede fragmentarse con el tiempo. NTFS, en cambio, utiliza una tabla de asignación de espacio libre y ofrece compresión de archivos, lo que mejora el uso del espacio y reduce la fragmentación, pero puede consumir más recursos.

Ambos sistemas implementan journaling para asegurar la integridad de los archivos, pero NTFS proporciona una recuperación más robusta debido a su estructura de MFT y comprobación de integridad. Aunque EXT4 es más sencillo y eficiente, NTFS destaca en entornos donde se requiere un mayor control de los permisos y la recuperación ante fallos.

### EJERCICIO 3: Organización lógica y física de archivos.

**Descripción**
Crea un esquema que muestre la organización lógica y física de un sistema de archivos.
Explica cómo se relacionan las estructuras lógicas con las físicas en el disco.

**Tareas**

* Diseña un árbol jerárquico que represente la organización lógica de directorios y subdirectorios. ⭕

* Explica cómo se traduce la dirección lógica a la dirección física en el disco. ⭕

* Proporciona un ejemplo práctico de cómo un archivo se almacena físicamente. ⭕

### EJERCICIO 4: Mecanismos de accedo a los archivos.

**Descripción**
Simula diferentes mecanismos de acceso a archivos (secuencial, directo e indexado) en un entorno práctico.

**Tareas**

* Define los diferentes mecanismos de acceso. ✔️

Existen varios mecanismos para acceder los archivos: Directorios, descriptores de archivos, mecanismos de control de acceso y procedimientos para abrir y cerrar archivos.

**Directorios** Generalmente son utilizados por los S. O. para llevar un registro de los archivos. En muchos sistemas son a su vez también archivos.

**Descriptores de archivos** El descriptor de archivos o bloque de control de archivos es un bloque de control que contiene información que el sistema necesita para administrar un archivo. Es una estructura muy dependiente del sistema.

**Mecanismos de control de acceso** Control de un sistema de información especializado en detectar los intectos de acceso, permitiendo el paso de las entidades autorizadas, y denegando el paso a todas las demás. Involucra medios técnicos y procedimientos operativos. Mecanismo que en función de la identificación ya autenticada permite acceder a datos o recursos.

**Procedimientos para abrir y cerrar archivos**

Open (abrir): antes de utilizar un archivo, un proceso debe abrirlo. La finalidad es permitir que el sistema traslade los atributos y la lista de direcciones en disco a la memoria principal para un rápido acceso en llamadas posteriores.

Close (cerrar): cuando concluyen los accesos, los atributos y direcciones del disco ya no son necesarios, por lo que el archivo debe cerrarse y liberar la tabla de espacio interno.

* Escribe un pseudocódigo que muestre cómo acceder a: ⭕

1. Un archivo secuencialmente.

2. Un archivo directamente mediante su posición.

3. Un archivo utilizando un índice.

* Compara las ventajas de cada mecanismo dependiendo del caso de uso. ⭕

### EJERCICIO 5: Modelo jerárquico y mecanismos de recuperación en caso de falla.

**Descripción**
Diseña una estructura jerárquica para un sistema de archivos y simula un escenario de falla en el sistema.
Describe cómo recuperar los datos utilizando mecanismos de recuperación.

**Tareas**

* Diseña un modelo jerárquico para un sistema de archivos con al menos tres niveles de directorios. ⭕

* Simula una falla en un directorio específico y describe los pasos necesarios para recuperarlo. ⭕

* Explica qué herramientas o técnicas de respaldo (backup) utilizarías para evitar pérdida de datos. ⭕

---

## PROTECCIÓN Y SEGURIDAD

### EJERCICIO 1: Concepto y objetivos de protección y seguridad.

**Descripción**
Investiga los conceptos de protección y seguridad en sistemas operativos.
Analiza los objetivos principales que deben cumplir estos mecanismos.

**Tareas**

* Define los conceptos de protección y seguridad en el contexto de sistemas operativos. ✔️

La **seguridad** en los sistemas operativos se refiere a proteger los recursos y datos del sistema frente a amenazas externas e internas, garantizando la confidencialidad, integridad y disponibilidad de la información. Esto involucra prevenir accesos no autorizados, ataques de malware y otros riesgos.
La **protección**, por otro lado, se enfoca en controlar el acceso de usuarios, programas y procesos a los recursos del sistema, evitando que se realicen acciones no autorizadas.

* Identifica los objetivos principales de un sistema de protección y seguridad, como confidencialidad, integridad y disponibilidad. ✔️

**Confidencialidad** Garantizar que la información solo sea accesible por personas o procesos autorizados. Esto previene el acceso no autorizado a datos sensibles o privados.

**Integridad** Asegurar que los datos no sean alterados de manera no autorizada o accidental. Esto implica verificar que la información se mantenga precisa y completa durante su almacenamiento y transmisión.

**Disponibilidad** Asegurar que los recursos y servicios estén disponibles y accesibles cuando se necesiten, protegiendo el sistema de interrupciones o ataques que puedan afectar su funcionamiento.

* Da un ejemplo práctico de cómo se aplican estos objetivos en un sistema operativo. ✔️

Bajo el ejemplo de un sistema operativo de un banco que gestiona cuentas de clientes:

*Confidencialidad:* Se asegura de que solo empleados y clientes autorizados puedan acceder a la información de cuentas mediante credenciales y cifrado de datos.

*Integridad:* Protege los datos de transacciones usando controles como checksums y journaling para evitar alteraciones no autorizadas.

*Disponibilidad:* Garantiza que los servicios bancarios estén siempre disponibles mediante copias de seguridad y recuperación ante fallos.

### EJERCICIO 2: Clasificación aplicada a la seguridad.

**Descripción**
Clasifica los mecanismos de seguridad en un sistema operativo y explica cómo cada tipo contribuye a la proteccion del sistema.

**Tareas**

* Investiga las clasificaciones comunes de la seguridad, como física, lógica y de red.

* Explica el papel de cada clasificación en la protección de un sistema operativo.

* Proporciona ejemplos prácticos de herramientas o técnicas utilizadas en cada clasificación.

### EJERCICIO 3: Funciones del sistema de protección.

**Descripción**
Analiza las funciones que cumple un sistema de protección en un entorno multiusuario.

**Tareas**

* Describe cómo un sistema de protección controla el acceso a los recursos.

* Explica las funciones principales como autentificación, autorización y auditoría.

* Diseña un caso práctico donde se muestren las funciones de un sistema de protección en acción.

### EJERCICIO 4: Implantación de matrices de acceso.

**Descripción**
Crea e implementa una matriz de acceso para un sistema que contiene usuarios y recursos con diferentes niveles de permisos.

**Tareas**

* Diseña una matriz de acceso para un sistema con al menos 3 usuarios y 4 recursos.

* Explica cómo esta matriz se utiliza para controlar el acceso en un sistema operativo.

* Simula un escenario donde un usuario intenta acceder a un recurso no permitido y cómo la matriz lo bloquea.

### EJERCICIO 5: Protección basada en el lenguaje.

**Descripción**
Investiga cómo los lenguajes de programación pueden implementar mecanismos de protección.

**Tareas**

* Explica el concepto de protección basada en el lenguaje.

* Proporciona un ejemplo de cómo un lenguaje como Java o Rust asegura la memoria y evita accesos no autorizados.

* Compara este enfoque con otros mecanismos de protección en sistemas operativos.

### EJERCICIO 6: Validación y amenazas al sistema.

**Descripción**
Analiza las principales amenazas a un sistema operativo y los mecanismos de validación utilizados para prevenirlas.

**Tareas**

* Investiga y describe al menos tres tipos de amenazas comunes (por ejemplo, malware, ataques de fuerza bruta, inyección de código).

* Explica los mecanismos de validación como autenticación multifactor y control de integridad.

* Diseña un esquema de validación para un sistema operativo con múltiples usuarios.

### EJERCICIO 7: Cifrado.

**Descripción**
Explora cómo los mecanismos de cifrado protegen la información en un sistema operativo.

**Tareas**

* Define los conceptos de cifrado simétrico y asimétrico.

* Proporciona un ejemplo práctico de cada tipo de cifrado aplicado en sistemas operativos.

* Simula el proceso de cifrado y descifrado de un archivo con una calve dada.