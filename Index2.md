# ACTIVIDAD FINAL

## SISTEMAS DE ARCHIVO

### ❇️ EJERCICIO 1: Concepto y noción de archivo real y virtual.

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

### ❇️ EJERCICIO 2: Componentes de un sistema de archivos.

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

### ❇️ EJERCICIO 3: Organización lógica y física de archivos.

**Descripción**
Crea un esquema que muestre la organización lógica y física de un sistema de archivos.
Explica cómo se relacionan las estructuras lógicas con las físicas en el disco.

**Tareas**

* Diseña un árbol jerárquico que represente la organización lógica de directorios y subdirectorios. ✔️

```
/archivos
├── /documentos
│   ├── /informes
│   ├── /facturas
│   └── /contratos
├── /imágenes
│   ├── /fotos_personales
│   ├── /fotos_trabajo
│   └── /fotos_publicidad
├── /música
│   ├── /rock
│   ├── /pop
│   └── /clasica
├── /videos
│   ├── /peliculas
│   ├── /tutoriales
│   └── /documentales
└── /almacenamiento_físico
    ├── /disco_duro_1
    ├── /disco_duro_2
    └── /copia_respaldo
        ├── /documentos_backup
        ├── /imágenes_backup
        └── /videos_backup
```

* Explica cómo se traduce la dirección lógica a la dirección física en el disco. ✔️

Cuando un sistema operativo necesita acceder a un archivo, utiliza direcciones lógicas. Estas son las direcciones que ve el sistema de archivos, y son usadas por los usuarios y aplicaciones para identificar archivos o bloques de datos. Estas direcciones son abstractas y no tienen relación directa con la ubicación física en el disco.
Las direcciones físicas, corresponden a las ubicaciones reales de los bloques de datos en el hardware del disco (por ejemplo, en el disco duro o SSD). Estas direcciones son específicas para cada dispositivo de almacenamiento y dependen de la estructura interna de este.

La traducción de una dirección lógica a una física es gestionada por el sistema de gestión de archivos (FMS) y un componente llamado gestor de almacenamiento. Este proceso involucra varios pasos: Sistemas de Archivos y Bloques de Datos, Tabla de Asignación de Archivos, Controlador de Disco y Traducción, Acceso al Hardware.

* Proporciona un ejemplo práctico de cómo un archivo se almacena físicamente. ✔️

Cuando guardas un archivo como "documento.txt", el sistema operativo lo divide en bloques lógicos, que son direcciones abstractas que el sistema utiliza para organizar los datos. Estos bloques se asocian a un inodo, que guarda información sobre el archivo y la ubicación de esos bloques. Luego, el sistema mapea estos bloques lógicos a direcciones físicas en el disco a través de una tabla interna. Finalmente, los datos se escriben en los sectores físicos del disco, donde el controlador del dispositivo asegura que los datos se guarden en las ubicaciones correctas.

### ❇️ EJERCICIO 4: Mecanismos de accedo a los archivos.

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

* Escribe un pseudocódigo que muestre cómo acceder a: ✔️

1. Un archivo secuencialmente.

2. Un archivo directamente mediante su posición.

3. Un archivo utilizando un índice.

```pseudocódigo

Mostrar "Selecciona un método de acceso al archivo:"
Mostrar "1. Acceso Secuencial"
Mostrar "2. Acceso Directo Mediante Posición"
Mostrar "3. Acceso Usando un Índice"

Leer opción_usuario

Si opción_usuario == 1:
    Mostrar "Acceso Secuencial seleccionado"
    Abrir archivo para lectura
    Mientras no se llegue al final del archivo:
        Leer siguiente línea o bloque
        Procesar la línea o bloque leída
    Cerrar archivo

Si opción_usuario == 2:
    Mostrar "Acceso Directo Mediante Posición seleccionado"
    Abrir archivo en modo lectura
    Posición = Leer("Introduce la posición en bytes:")
    Mover el cursor a la posición deseada
    Leer los datos desde esa posición
    Procesar los datos leídos
    Cerrar archivo

Si opción_usuario == 3:
    Mostrar "Acceso Usando un Índice seleccionado"
    Abrir archivo de índice
    Abrir archivo de datos
    Leer índice de archivo
    Para cada entrada del índice:
        Buscar la posición correspondiente en el archivo de datos
        Leer datos desde la posición indicada por el índice
        Procesar los datos leídos
    Cerrar archivo de datos
    Cerrar archivo de índice

```

* Compara las ventajas de cada mecanismo dependiendo del caso de uso. ✔️

Los **Directorios** permiten organizar archivos de manera jerárquica, facilitando la búsqueda y gestión eficiente. Son ideales para sistemas con muchos archivos, ayudando a mantener un orden claro y rápido acceso.

Los **Descriptores de archivos** contienen la información necesaria para gestionar archivos de forma eficiente. Son esenciales en entornos multitarea donde varios procesos interactúan con archivos, ya que permiten un acceso rápido y eficaz.

Los **Mecanismos de control de acceso** aseguran que solo usuarios autorizados puedan acceder a datos o recursos. Son cruciales en sistemas sensibles, como los bancarios o de salud, para proteger la confidencialidad e integridad de la información.

Los **Procedimientos para abrir y cerrar archivos** gestionan eficientemente los recursos del sistema, asegurando que los archivos se accedan solo cuando sea necesario y liberando memoria al cerrarlos. Son útiles en sistemas con limitaciones de recursos o que manejan grandes volúmenes de datos.

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

### ❇️ EJERCICIO 1: Concepto y objetivos de protección y seguridad.

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

* Investiga las clasificaciones comunes de la seguridad, como física, lógica y de red. ✔️

**Seguridad Física** Se refiere a la protección de los activos físicos de una organización, como servidores y dispositivos. Incluye medidas como el control de acceso, cámaras de vigilancia y sistemas de alarmas para evitar robos y daños.

**Seguridad Lógica** Está relacionada con la protección de los sistemas informáticos y la información almacenada en ellos. Esto abarca el uso de firewalls, antivirus y sistemas de detección de intrusos para prevenir accesos no autorizados y ciberataques.

**Seguridad de Red** Se enfoca en proteger la infraestructura de la red, implementando encriptación, segmentación y monitoreo constante para mitigar riesgos como ataques de hackers o malware​.

* Explica el papel de cada clasificación en la protección de un sistema operativo. ✔️

**Seguridad física** protege los elementos tangibles, como los servidores, dispositivos de almacenamiento y las infraestructuras en las que el sistema operativo se ejecuta. Por ejemplo, el acceso físico restringido al hardware a través de cerraduras, cámaras de vigilancia y controles de acceso impide que personas no autorizadas manipulen o roben equipos. Sin seguridad física, incluso un sistema operativo bien protegido a nivel lógico sería vulnerable a ataques de tipo físico, como el robo de discos duros que contienen datos sensibles.

**Seguridad lógica** se enfoca en las medidas de protección que impiden accesos no autorizados a los recursos dentro del sistema operativo, como archivos, aplicaciones y configuraciones. Esto se logra mediante el uso de contraseñas, autenticación multifactor, permisos de acceso y herramientas de cifrado. Un sistema operativo emplea estas estrategias para asegurar que solo los usuarios y procesos autorizados puedan realizar ciertas acciones, como modificar archivos críticos o ejecutar aplicaciones privilegiadas. Sin esta capa, incluso si un sistema es físicamente seguro, un atacante podría acceder fácilmente a la información y recursos dentro del sistema.

**Seguridad de red** protege los datos mientras se transmiten entre dispositivos a través de la red. A través del uso de protocolos como SSL/TLS para encriptar el tráfico, firewalls para filtrar el tráfico no deseado, y sistemas de detección de intrusos para identificar actividades sospechosas, se protege la integridad y confidencialidad de los datos mientras se comunican entre máquinas. Si bien las amenazas físicas o locales pueden ser gestionadas con seguridad física y lógica, los ataques de red pueden ocurrir de forma remota, y sin una red segura, un sistema operativo quedaría expuesto a intrusos a través de internet o redes locales.

* Proporciona ejemplos prácticos de herramientas o técnicas utilizadas en cada clasificación. ⭕

### EJERCICIO 3: Funciones del sistema de protección.

**Descripción**
Analiza las funciones que cumple un sistema de protección en un entorno multiusuario.

**Tareas**

* Describe cómo un sistema de protección controla el acceso a los recursos. ✔️

Un **sistema de protección** controla el acceso a los recursos verificando la identidad del usuario o proceso y asegurándose de que tenga los permisos adecuados para acceder o modificar los recursos. Utiliza mecanismos de autenticación para validar a los usuarios, y luego verifica si tienen autorización para realizar las acciones solicitadas. Además, aisla los recursos entre procesos para evitar interferencias y aplica políticas que definen cómo se asignan y gestionan los permisos. Todo esto se complementa con un monitoreo constante para detectar accesos no autorizados y garantizar la seguridad del sistema.

* Explica las funciones principales como autentificación, autorización y auditoría. ✔️

La **autenticación** es el proceso mediante el cual un sistema verifica la identidad de un usuario o entidad que intenta acceder a un recurso. Generalmente, esto se realiza a través de credenciales como nombres de usuario y contraseñas, aunque también puede involucrar métodos más seguros como la autenticación multifactor (combinación de contraseñas, códigos enviados al móvil, huellas dactilares, etc.). El objetivo de la autenticación es garantizar que la persona o proceso que solicita acceso es quien dice ser.

La **autorización** ocurre una vez que la autenticación ha tenido éxito. Se trata del proceso en el que el sistema determina qué recursos o acciones un usuario o proceso tiene permiso de acceder o realizar. Esto se controla mediante permisos y políticas de acceso, que definen qué puede hacer cada usuario con los recursos disponibles. Por ejemplo, un usuario podría tener permiso para leer un archivo pero no para modificarlo. La autorización asegura que solo los usuarios o procesos adecuados realicen operaciones sobre los recursos.

La **auditoría** implica el registro y monitoreo de las actividades de acceso a los recursos del sistema. A través de registros de auditoría, se mantienen trazas detalladas de las acciones realizadas, como qué usuario accedió a qué recursos y qué operaciones ejecutó. Este proceso es crucial para detectar y analizar actividades sospechosas o no autorizadas, facilitando la investigación de incidentes de seguridad y ayudando a garantizar el cumplimiento de políticas de seguridad y normativas regulatorias.

* Diseña un caso práctico donde se muestren las funciones de un sistema de protección en acción. ⭕

### EJERCICIO 4: Implantación de matrices de acceso.

**Descripción**
Crea e implementa una matriz de acceso para un sistema que contiene usuarios y recursos con diferentes niveles de permisos.

**Tareas**

* Diseña una matriz de acceso para un sistema con al menos 3 usuarios y 4 recursos. ⭕

* Explica cómo esta matriz se utiliza para controlar el acceso en un sistema operativo. ⭕

* Simula un escenario donde un usuario intenta acceder a un recurso no permitido y cómo la matriz lo bloquea. ⭕

### EJERCICIO 5: Protección basada en el lenguaje.

**Descripción**
Investiga cómo los lenguajes de programación pueden implementar mecanismos de protección.

**Tareas**

* Explica el concepto de protección basada en el lenguaje. ✔️

La **protección basada en el lenguaje** se refiere a la integración de medidas de seguridad directamente en los lenguajes de programación, para prevenir errores y vulnerabilidades en el software. El objetivo es hacer que los lenguajes de programación sean más seguros al facilitar que los desarrolladores eviten prácticas riesgosas o errores que podrían comprometer la seguridad del sistema. *Java* maneja automáticamente la memoria, lo que elimina problemas comunes como los desbordamientos de búfer (donde el programa escribe más allá del espacio de memoria asignado, lo que puede permitir ataques). Además, algunos lenguajes imponen restricciones sobre cómo se pueden manipular los datos, asegurando que solo se realicen operaciones seguras.

* Proporciona un ejemplo de cómo un lenguaje como Java o Rust asegura la memoria y evita accesos no autorizados. ✔️

En **Java**, la seguridad de la memoria se maneja de manera automática mediante varias características que ayudan a prevenir accesos no autorizados y errores comunes. Un ejemplo clave es la gestión automática de memoria y el uso de referencias en lugar de punteros directos.

* Compara este enfoque con otros mecanismos de protección en sistemas operativos. ⭕

### EJERCICIO 6: Validación y amenazas al sistema.

**Descripción**
Analiza las principales amenazas a un sistema operativo y los mecanismos de validación utilizados para prevenirlas.

**Tareas**

* Investiga y describe al menos tres tipos de amenazas comunes (por ejemplo, malware, ataques de fuerza bruta, inyección de código). ✔️

**Malware** Malware es un término que abarca cualquier tipo de software malicioso diseñado para dañar o explotar cualquier dispositivo, servicio o red programable. Los delincuentes cibernéticos generalmente lo usan para extraer datos que pueden utilizar como chantaje hacia las víctimas para obtener ganancias financieras. Dichos datos pueden variar desde datos financieros, hasta registros de atención médica, correos electrónicos personales y contraseñas. La variedad de información que puede verse comprometida se ha vuelto ilimitada.

**Ataques de fuerza bruta** Un ataque de fuerza bruta es un método de piratería informática que utiliza pruebas y errores para descifrar contraseñas, credenciales de inicio de sesión y claves de cifrado. Es una táctica simple pero confiable para obtener acceso no autorizado a cuentas individuales y sistemas y redes de organizaciones. El pirata informático intenta varios nombres de usuario y contraseñas, a menudo utilizando una computadora para probar una amplia gama de combinaciones, hasta que encuentra la información de inicio de sesión correcta.
El nombre "fuerza bruta" proviene de atacantes que utilizan intentos excesivamente forzados para obtener acceso a las cuentas de usuario. A pesar de ser un antiguo método de ciberataque, los ataques de fuerza bruta se prueban y examinan y siguen siendo una táctica popular entre los piratas informáticos.

**Inyección de código** Un ataque cibernético de inyección de código es una técnica de ataque informático que se utiliza para explotar vulnerabilidades en un sitio web o aplicación. En este tipo de ataque, un hacker aprovecha las debilidades de la aplicación para insertar código malicioso en el servidor y así poder robar información confidencial, tomar el control del sistema o realizar otras acciones dañinas.

* Explica los mecanismos de validación como autenticación multifactor y control de integridad. ✔️

Los **mecanismos de validación** en son herramientas utilizadas para asegurar que solo usuarios o procesos autorizados tengan acceso a los recursos del sistema y que los datos se mantengan íntegros. Dos ejemplos comunes son la autenticación *multifactor* y el *control de integridad*.

**Autenticación multifactor (MFA)** 
Cuando inicias sesión en una cuenta en línea, normalmente usas un nombre de usuario y una contraseña. Sin embargo, estas son opciones inseguras, ya que los nombres de usuario pueden ser fáciles de adivinar y las contraseñas a menudo son débiles o se reutilizan en varios sitios. Para mejorar la seguridad, muchos servicios han implementado autenticación multifactor o verificación en dos pasos. Este proceso agrega una capa extra de protección, solicitando un segundo factor de autenticación, como un código enviado a tu teléfono, además de tu contraseña. Esto hace más difícil que los atacantes accedan a tus cuentas.

**Control de integridad**
Es un mecanismo que asegura que los datos no han sido modificados de manera no autorizada. Se utiliza para verificar que la información almacenada (archivos, configuraciones, etc.) esté intacta. Un ejemplo común es el uso de sumas de verificación (checksums) o códigos de autenticación de mensajes (MAC), que generan un valor único para cada conjunto de datos. Si los datos se modifican, el valor cambia, lo que permite detectar alteraciones.

* Diseña un esquema de validación para un sistema operativo con múltiples usuarios. ⭕

### EJERCICIO 7: Cifrado.

**Descripción**
Explora cómo los mecanismos de cifrado protegen la información en un sistema operativo.

**Tareas**

* Define los conceptos de cifrado simétrico y asimétrico. ✔️

En el **cifrado simétrico**, sólo hay una clave, y todas las partes implicadas utilizan la misma clave para cifrar y descifrar la información. Al utilizar una única clave, el proceso es sencillo, como en el siguiente ejemplo: encriptas un correo electrónico con una clave única, envías ese correo a tu amigo David, y él utilizará la misma clave simétrica para desbloquear/desencriptar el correo.

El **cifrado asimétrico**, por otro lado, se creó para resolver el problema inherente al cifrado simétrico: la necesidad de compartir una única clave de cifrado alrededor que se utiliza tanto para cifrar como para descifrar datos.

* Proporciona un ejemplo práctico de cada tipo de cifrado aplicado en sistemas operativos. ✔️

**Cifrado simétrico** 

El cifrado simétrico es estupendo cuando se trabaja con datos sensibles a gran escala, o en tareas de cifrado que pretenden ocultar permanentemente la información sin necesidad de descifrarla. Por ejemplo, cuando se activa BitLocker en un ordenador con Windows para cifrar todos los discos duros. Al desbloquear el PC con su código de acceso, el usuario descifrará los datos sin riesgo de exponer su clave secreta de cifrado. Otro ejemplo son las VPN, que cifran su tráfico de red con una clave local y no tienen la necesidad de compartirla fuera de su propio uso.

**Cifrado asimétrico:**

Un buen ejemplo es el cifrado del correo electrónico. Con el cifrado asimétrico, cualquiera puede utilizar tu clave pública para enviarte un correo electrónico cifrado que sólo puedes descifrar con tu clave privada.
Naturalmente, el asimétrico es un estándar de cifrado más avanzado y, por lo tanto, es más lento y consume más recursos. Por ello, suele utilizarse en transacciones más pequeñas, normalmente para establecer canales de comunicación seguros o autenticar usuarios.

* Simula el proceso de cifrado y descifrado de un archivo con una calve dada. ⭕