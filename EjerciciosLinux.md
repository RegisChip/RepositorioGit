# ACTIVIDADES Y EJERCICIOS

## ACTIVIDADES

#### ACTIVIDAD 1 🌐

1. Abra una terminal en su entorno Linux.

2. Ejecute los siguientes comandos y anote sus observaciones:

* `lsblk`: Enumera los dispositivos de bloque.

* `lsusb`: Lista los dispositivos conectados a los puertos USB.

* `lspci`: Muestra los dispositivos conectados al bus PCI.

* `dmesg | grep usb`: Muestra los mensajes del kernel relacionados con dispositivos USB.

```bash

┌───────────────────>
│~ 
└─> lsblk
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  10.8M  1 loop /snap/snap-store/1244
loop2    7:2    0  73.9M  1 loop /snap/core22/1663
loop3    7:3    0 269.8M  1 loop /snap/firefox/4793
loop4    7:4    0  11.1M  1 loop /snap/firmware-updater/147
loop5    7:5    0  10.7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  91.7M  1 loop /snap/gtk-common-themes/1535
loop7    7:7    0 505.1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  38.8M  1 loop /snap/snapd/21759
loop9    7:9    0  10.5M  1 loop /snap/snap-store/1173
loop10   7:10   0  44.3M  1 loop /snap/snapd/23258
loop11   7:11   0   568K  1 loop /snap/snapd-desktop-integration/253
loop12   7:12   0   500K  1 loop /snap/snapd-desktop-integration/178
loop13   7:13   0  73.9M  1 loop /snap/core22/1722
sda      8:0    0    40G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    40G  0 part /
sr0     11:0    1  1024M  0 rom  

┌───────────────────>
│~ 
└─> lsusb
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 80ee:0021 VirtualBox USB Tablet
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub

┌───────────────────>
│~ 
└─> lspci
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)

┌───────────────────>
│~ 
└─> sudo dmesg | grep usb
[sudo] password for quetzal: 
[    1.075123] usbcore: registered new interface driver usbfs
[    1.075161] usbcore: registered new interface driver hub
[    1.075177] usbcore: registered new device driver usb
[    1.557613] usb usb1: New USB device found, idVendor=1d6b, idProduct=0001, bcdDevice= 6.08
[    1.557624] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    1.557628] usb usb1: Product: OHCI PCI host controller
[    1.557631] usb usb1: Manufacturer: Linux 6.8.0-49-generic ohci_hcd
[    1.557634] usb usb1: SerialNumber: 0000:00:06.0
[    1.629708] usb usb2: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.08
[    1.629717] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    1.629722] usb usb2: Product: EHCI Host Controller
[    1.629726] usb usb2: Manufacturer: Linux 6.8.0-49-generic ehci_hcd
[    1.629730] usb usb2: SerialNumber: 0000:00:0b.0
[    1.945108] usb 1-1: new full-speed USB device number 2 using ohci-pci
[    2.246308] usb 1-1: New USB device found, idVendor=80ee, idProduct=0021, bcdDevice= 1.00
[    2.246320] usb 1-1: New USB device strings: Mfr=1, Product=3, SerialNumber=0
[    2.246325] usb 1-1: Product: USB Tablet
[    2.246329] usb 1-1: Manufacturer: VirtualBox
[    2.679262] usbcore: registered new interface driver usbhid
[    2.679268] usbhid: USB HID core driver
[    2.986547] input: VirtualBox USB Tablet as /devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
[    2.989659] hid-generic 0003:80EE:0021.0001: input,hidraw0: USB HID v1.10 Mouse [VirtualBox USB Tablet] on usb-0000:00:06.0-1/input0

```
3. Conteste:

* ¿Qué tipos de dispositivos se muestran en la salida de `lsblk`?

En `lsblk` muestra los dispositivos de almacenamiento. Por ejemplo, el dico principal `sda`, sus particiones y dispositivos en bucle. También aparece una unidad de CD/DVD virtual.

* ¿Cuál es la diferencia entre `lsusb` y `lspci`?

`lsusb` te dice qué dispositivos USB están conectados, como un mouse o teclado. En cambio, `lspci` muestra hardware más general conectado al bus PCI, como la tarjeta de red, el audio o la tarjeta gráfica.

* ¿Qué información adicional proporciona `dmesg | grep usb`?

El comando `dmesg | grep usb` da más detalles sobre cómo se detectaron los dispositivos USB al arrancar el sistema. Dice quién fabricó el dispositivo, su modelo y si el sistema lo reconoció correctamente.

---

### ACTIVIDAD 2 🌐

1. Use el comando `fdisk -l` para listar todos los discos y particiones.

2. Utilice `blkid` para ver los identificadores UUID y los tipos de sistema de archivos.

3. Use `df -h` para listar los dispositivos montados y su espacio disponible.

```bash

┌───────────────────>
│~ 
└─> fdisk -l
fdisk: cannot open /dev/loop0: Permission denied
fdisk: cannot open /dev/loop1: Permission denied
fdisk: cannot open /dev/loop2: Permission denied
fdisk: cannot open /dev/loop3: Permission denied
fdisk: cannot open /dev/loop4: Permission denied
fdisk: cannot open /dev/loop5: Permission denied
fdisk: cannot open /dev/loop6: Permission denied
fdisk: cannot open /dev/loop7: Permission denied
fdisk: cannot open /dev/sda: Permission denied
fdisk: cannot open /dev/loop8: Permission denied
fdisk: cannot open /dev/loop9: Permission denied
fdisk: cannot open /dev/loop10: Permission denied
fdisk: cannot open /dev/loop11: Permission denied
fdisk: cannot open /dev/loop12: Permission denied
fdisk: cannot open /dev/loop13: Permission denied

┌───────────────────>
│~ 
└─> blkid
/dev/sda2: UUID="b0b0fbfb-5cbb-4874-ba95-1eb98194ab09" BLOCK_SIZE="4096" TYPE="ext4" PARTUUID="2a996434-e229-43f4-a90b-35a157ae37cf"

┌───────────────────>
│~ 
└─> df -h
Filesystem      Size  Used Avail Use% Mounted on
tmpfs           392M  1.6M  391M   1% /run
/dev/sda2        40G  6.7G   31G  18% /
tmpfs           2.0G     0  2.0G   0% /dev/shm
tmpfs           5.0M  8.0K  5.0M   1% /run/lock
tmpfs           392M  148K  392M   1% /run/user/1000

```

4. Conteste:

* ¿Qué dispositivos de almacenamiento están conectados a su sistema?

El disco principal es `/dev/sda`, que tiene una partición activa `/dev/sda2` de 40 GB. También aparecen varios dispositivos en bucle, que se usan para aplicaciones empaquetadas o imágenes montadas, aunque no están accesibles directamente debido a restricciones de permisos.

* ¿Qué particiones están montadas actualmente?

La partición `/dev/sda2` está montada como el sistema de archivos raíz. Además, hay sistemas temporales montados como tmpfs, que son usados para la memoria RAM y tareas temporales del sistema.

* ¿Qué tipo de sistemas de archivos se usan en las particiones?

El sistema de archivos principal es `ext4`, que está en `/dev/sda2`. Los sistemas `tmpfs` son basados en RAM y se usan para directorios temporales como `/run`, ``/dev/shm``, y ``/run/lock``.

---

### ACTIVIDAD 3

1. Ejecute `cat /proc/bus/input/devices` para listar los dispositivos de entrada.

2. Use `evtest` para monitorear eventos de dispositivos de entrada (requiere permisos de superusuario).

3. Investigue los siguientes dispositivos:

* Teclado

* Mouse

* Controladores USB adicionales

```bash

┌───────────────────>
│/🔒 
└─> cat /proc/bus/input/devices
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0000
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input7
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=b
B: KEY=10000 0 0 0 0
B: ABS=3

```

4. Conteste:

* ¿Qué eventos genera cada dispositivo al interactuar con ellos?

* ¿Cómo se identifican los dispositivos en `/proc/bus/input/devices`?

---

### ACTIVIDAD 4 🌐

1. Use `xrandr` para listar las pantallas conectadas y sus resoluciones.

2. Ejecute `aplay -l` para listar las tarjetas de sonido disponibles.

3. Use `lsof /dev/snd/*` para ver qué procesos están utilizando la tarjeta de sonido.

```bash

┌───────────────────>
│~ 
└─> xrandr
Screen 0: minimum 16 x 16, current 1280 x 800, maximum 32767 x 32767
Virtual-1 connected primary 1280x800+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1280x800      59.81*+
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1152x720      59.97  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  

┌───────────────────>
│~ 
└─> aplay -l
**** List of PLAYBACK Hardware Devices ****
card 0: I82801AAICH [Intel 82801AA-ICH], device 0: Intel ICH [Intel 82801AA-ICH]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

┌───────────────────>
│/🔒 
└─> lsof /dev/snd/*
COMMAND    PID    USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
pipewire  1752 quetzal   59u   CHR  116,1      0t0  417 /dev/snd/seq
pipewire  1752 quetzal   60u   CHR  116,1      0t0  417 /dev/snd/seq
wireplumb 1765 quetzal   35u   CHR  116,5      0t0  682 /dev/snd/controlC0

```

4. Conteste:

* ¿Qué salidas de video están disponibles en su sistema?

El sistema tiene una salida de video virtual llamada ``Virtual-1``, configurada actualmente a una resolución de 1280x800 píxeles. También están disponibles otras resoluciones, como 1024x768, 800x600 y 640x480, entre otras.

* ¿Qué dispositivos de sonido se detectaron?`

El sistema detectó un dispositivo de sonido Intel 82801AA-ICH con un subdispositivo disponible para reproducción.

* ¿Qué procesos están usando la tarjeta de sonido?

Los procesos ``pipewire`` (PID 1752) y ``wireplumber`` (PID 1765) están accediendo a la tarjeta de sonido. Estos son servicios relacionados con la gestión de audio en sistemas Linux modernos.

---

### ACTIVIDAD 5 🌐

1. Cree un archivo llamado `dispositivos.sh` y agregue el siguiente contenido: ```bash #!/bin/bash echo "Dispositivos de bloque:" lsblk echo "Dispositivos USB:" lsusb echo "Dispositivos PCI:" lspci echo "Dispositivos de entrada:" cat /proc/bus/input/devices echo "Salidas de video:" xrandr echo "Tarjetas de sonido:" aplay -l ```

2. Ejecute el script usando `bash dispositivos.sh`.

3. Modifique el script para guardar la salida en un archivo llamado `resumendispositivos.txt`.

```bash

┌───────────────────>
│~ 
└─> nano dispositivos.sh 

...


#!/bin/bash

echo "Dispositivos de bloque:"

lsblk

echo "Dispositivos USB:"

lsusb

echo "Dispositivos PCI:"

lspci

echo "Dispositivos de entrada:"

cat /proc/bus/input/devices

echo "Salidas de video:"

xrandr

echo "Tarjetas de sonido:"

aplay -l

...

┌───────────────────>
│~ 
└─> bash dispositivos.sh
Dispositivos de bloque:
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  10.8M  1 loop /snap/snap-store/1244
loop2    7:2    0  73.9M  1 loop /snap/core22/1663
loop3    7:3    0 269.8M  1 loop /snap/firefox/4793
loop4    7:4    0  11.1M  1 loop /snap/firmware-updater/147
loop5    7:5    0  10.7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  91.7M  1 loop /snap/gtk-common-themes/1535
loop7    7:7    0 505.1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  38.8M  1 loop /snap/snapd/21759
loop9    7:9    0  10.5M  1 loop /snap/snap-store/1173
loop10   7:10   0  44.3M  1 loop /snap/snapd/23258
loop11   7:11   0   568K  1 loop /snap/snapd-desktop-integration/253
loop12   7:12   0   500K  1 loop /snap/snapd-desktop-integration/178
loop13   7:13   0  73.9M  1 loop /snap/core22/1722
sda      8:0    0    40G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    40G  0 part /
sr0     11:0    1  1024M  0 rom  
Dispositivos USB:
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 002: ID 80ee:0021 VirtualBox USB Tablet
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Dispositivos PCI:
00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: VMware SVGA II Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)
Dispositivos de entrada:
I: Bus=0019 Vendor=0000 Product=0001 Version=0000
N: Name="Power Button"
P: Phys=LNXPWRBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXPWRBN:00/input/input0
U: Uniq=
H: Handlers=kbd event0 
B: PROP=0
B: EV=3
B: KEY=8000 10000000000000 0

I: Bus=0019 Vendor=0000 Product=0003 Version=0000
N: Name="Sleep Button"
P: Phys=LNXSLPBN/button/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSLPBN:00/input/input1
U: Uniq=
H: Handlers=kbd event1 
B: PROP=0
B: EV=3
B: KEY=4000 0 0

I: Bus=0011 Vendor=0001 Product=0001 Version=ab41
N: Name="AT Translated Set 2 keyboard"
P: Phys=isa0060/serio0/input0
S: Sysfs=/devices/platform/i8042/serio0/input/input2
U: Uniq=
H: Handlers=sysrq kbd event2 leds 
B: PROP=0
B: EV=120013
B: KEY=402000000 3803078f800d001 feffffdfffefffff fffffffffffffffe
B: MSC=10
B: LED=7

I: Bus=0019 Vendor=0000 Product=0006 Version=0000
N: Name="Video Bus"
P: Phys=LNXVIDEO/video/input0
S: Sysfs=/devices/LNXSYSTM:00/LNXSYBUS:00/PNP0A03:00/LNXVIDEO:00/input/input4
U: Uniq=
H: Handlers=kbd event3 
B: PROP=0
B: EV=3
B: KEY=3e000b00000000 0 0 0

I: Bus=0011 Vendor=0002 Product=0006 Version=0000
N: Name="ImExPS/2 Generic Explorer Mouse"
P: Phys=isa0060/serio1/input0
S: Sysfs=/devices/platform/i8042/serio1/input/input5
U: Uniq=
H: Handlers=mouse0 event4 
B: PROP=1
B: EV=7
B: KEY=1f0000 0 0 0 0
B: REL=143

I: Bus=0003 Vendor=80ee Product=0021 Version=0110
N: Name="VirtualBox USB Tablet"
P: Phys=usb-0000:00:06.0-1/input0
S: Sysfs=/devices/pci0000:00/0000:00:06.0/usb1/1-1/1-1:1.0/0003:80EE:0021.0001/input/input6
U: Uniq=
H: Handlers=mouse1 event5 js0 
B: PROP=0
B: EV=1f
B: KEY=1f0000 0 0 0 0
B: REL=1940
B: ABS=3
B: MSC=10

I: Bus=0001 Vendor=80ee Product=cafe Version=0000
N: Name="VirtualBox mouse integration"
P: Phys=
S: Sysfs=/devices/pci0000:00/0000:00:04.0/input/input7
U: Uniq=
H: Handlers=mouse2 event6 js1 
B: PROP=0
B: EV=b
B: KEY=10000 0 0 0 0
B: ABS=3

Salidas de video:
Screen 0: minimum 16 x 16, current 1280 x 800, maximum 32767 x 32767
Virtual-1 connected primary 1280x800+0+0 (normal left inverted right x axis y axis) 0mm x 0mm
   1280x800      59.81*+
   1024x768      59.92  
   800x600       59.86  
   640x480       59.38  
   320x240       59.52  
   1152x720      59.97  
   960x600       59.63  
   928x580       59.88  
   800x500       59.50  
   768x480       59.90  
   720x480       59.71  
   640x400       59.95  
   320x200       58.96  
   1280x720      59.86  
   1024x576      59.90  
   864x486       59.92  
   720x400       59.55  
   640x350       59.77  
Tarjetas de sonido:
**** List of PLAYBACK Hardware Devices ****
card 0: I82801AAICH [Intel 82801AA-ICH], device 0: Intel ICH [Intel 82801AA-ICH]
  Subdevices: 0/1
  Subdevice #0: subdevice #0

...

#!/bin/bash

output_file="resumendispositivos.txt"


echo "Dispositivos de bloque:" >> "$output_file"
lsblk >> "$output_file"
echo >> "$output_file"

echo "Dispositivos USB:" >> "$output_file"
lsusb >> "$output_file"
echo >> "$output_file"

echo "Dispositivos PCI:" >> "$output_file"
lspci >> "$output_file"
echo >> "$output_file"

echo "Dispositivos de entrada:" >> "$output_file"
cat /proc/bus/input/devices >> "$output_file"
echo >> "$output_file"

echo "Salidas de video:" >> "$output_file"
xrandr >> "$output_file"
echo >> "$output_file"

echo "Tarjetas de sonido:" >> "$output_file"
aplay -l >> "$output_file"
echo >> "$output_file"

echo "La información se ha guardado en $output_file"


```

4. Conteste:

* ¿Qué ventajas tiene usar un script para recopilar esta información?

Usar un script para recopilar información automatiza el proceso, ahorrando tiempo y esfuerzo. Garantiza consistencia en los datos y facilita su almacenamiento o compartición, eliminando la necesidad de ejecutar comandos manualmente cada vez.

* ¿Qué cambios realizaría para personalizar el script?

Para personalizarlo, lo mejor sería adaptar el script a las necesidades específicas, como elegir qué dispositivos o información te interesa más, o cómo prefieres que se guarde la salida.

También se podría añadir una opción para ejecutar ciertos comandos solo bajo condiciones específicas, como filtrar por tipo de dispositivo o por directorios específicos, haciendo el script aún más útil según el contexto.

---
---

## EJERCICIOS

### EJERCICIO 1

* **Objetivo:** Aprender a montar y desmontar un dispositivo externo.

* Inserta una memoria USB en el sistema.

* Encuentra el dispositivo usando el comando:


      lsblk o fdisk -l
* Monta la memoria USB en un directorio, por ejemplo, `/mnt/usb`:

      sudo mount /dev/sdX1 /mnt/usb
* Verifica que esté montado correctamente:

      df -h
* Copia un archivo desde tu directorio personal al dispositivo USB:

      cp archivo.txt /mnt/usb/
* Desmonta la memoria USB:

      sudo umount /mnt/usb

```bash

```

---

### EJERCICIO 2 🌐

* **Objetivo:** Usar redirección para guardar la salida de comandos en archivos.

* Lista los archivos de tu directorio actual y guarda el resultado en un archivo `listado.txt`:

      ls -l > listado.txt

* Muestra el contenido del archivo en la terminal:

      cat listado.txt
* Añade la fecha actual al final del archivo:

      date >> listado.txt
* Muestra todo el contenido del archivo nuevamente:

      cat listado.txt

```bash

┌───────────────────>
│~ 
└─> ls -l > listado.txt

┌───────────────────>
│~ 
└─> cat listado.txt
total 404
drwxrwxr-x 2 quetzal quetzal   4096 Nov 26 17:52 central
-rw-rw-r-- 1 quetzal quetzal    114 Nov 26 18:18 coco.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Desktop
-rw-rw-r-- 1 quetzal quetzal    251 Dec 16 16:31 dispositivos.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Documents
drwxr-xr-x 3 quetzal quetzal   4096 Nov 27 18:52 Downloads
-rwxr-xr-x 1 quetzal quetzal    274 Nov 26 18:07 foqui.sh
-rw-rw-r-- 1 quetzal quetzal    387 Nov 26 19:19 Hollywood.sh
-rw-rw-r-- 1 quetzal quetzal     26 Nov 26 19:21 hora.sh
-rw-rw-r-- 1 quetzal quetzal 323060 Nov 27 16:35 ima2.png
-rwxr-xr-x 1 quetzal quetzal    573 Nov 28 19:34 install.sh
-rw-rw-r-- 1 quetzal quetzal      0 Dec 16 16:35 listado.txt
drwxrwxr-x 3 quetzal quetzal   4096 Nov 28 19:14 miku
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Music
-rw-rw-r-- 1 quetzal quetzal    126 Nov 26 18:23 panda.sh
-rw-rw-r-- 1 quetzal quetzal    163 Nov 26 17:52 parker.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Pictures
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Public
drwx------ 5 quetzal quetzal   4096 Nov 26 19:47 snap
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Templates
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Videos
-rw-rw-r-- 1 quetzal quetzal    761 Nov 28 17:17 wget-log
-rw-rw-r-- 1 quetzal quetzal    761 Nov 28 17:19 wget-log.1
-rw-rw-r-- 1 quetzal quetzal    763 Nov 28 18:52 wget-log.2

┌───────────────────>
│~ 
└─> date >> listado.txt 

┌───────────────────>
│~ 
└─> cat listado.txt 
total 404
drwxrwxr-x 2 quetzal quetzal   4096 Nov 26 17:52 central
-rw-rw-r-- 1 quetzal quetzal    114 Nov 26 18:18 coco.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Desktop
-rw-rw-r-- 1 quetzal quetzal    251 Dec 16 16:31 dispositivos.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Documents
drwxr-xr-x 3 quetzal quetzal   4096 Nov 27 18:52 Downloads
-rwxr-xr-x 1 quetzal quetzal    274 Nov 26 18:07 foqui.sh
-rw-rw-r-- 1 quetzal quetzal    387 Nov 26 19:19 Hollywood.sh
-rw-rw-r-- 1 quetzal quetzal     26 Nov 26 19:21 hora.sh
-rw-rw-r-- 1 quetzal quetzal 323060 Nov 27 16:35 ima2.png
-rwxr-xr-x 1 quetzal quetzal    573 Nov 28 19:34 install.sh
-rw-rw-r-- 1 quetzal quetzal      0 Dec 16 16:35 listado.txt
drwxrwxr-x 3 quetzal quetzal   4096 Nov 28 19:14 miku
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Music
-rw-rw-r-- 1 quetzal quetzal    126 Nov 26 18:23 panda.sh
-rw-rw-r-- 1 quetzal quetzal    163 Nov 26 17:52 parker.sh
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Pictures
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Public
drwx------ 5 quetzal quetzal   4096 Nov 26 19:47 snap
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Templates
drwxr-xr-x 2 quetzal quetzal   4096 Nov 26 02:42 Videos
-rw-rw-r-- 1 quetzal quetzal    761 Nov 28 17:17 wget-log
-rw-rw-r-- 1 quetzal quetzal    761 Nov 28 17:19 wget-log.1
-rw-rw-r-- 1 quetzal quetzal    763 Nov 28 18:52 wget-log.2
Mon Dec 16 04:37:14 PM UTC 2024

```

---

### EJERCICIO 3 🌐

* **Objetivo:** Practicar copiar y mover archivos y directorios.

* Crea un archivo de texto llamado `archivo1.txt`:

      echo "Este es un archivo de prueba" > archivo1.txt
* Copia este archivo a otro directorio, por ejemplo, `/tmp`:

      cp archivo1.txt /tmp/
* Renombra el archivo copiado a `archivo2.txt` en `/tmp`:

      mv /tmp/archivo1.txt /tmp/archivo2.txt
* Mueve el archivo `archivo2.txt` de vuelta a tu directorio actual:

      mv /tmp/archivo2.txt .

```bash

┌───────────────────>
│~ 
└─> touch archivo1.txt

┌───────────────────>
│~ 
└─> echo "Hola profe ggg" > archivo1.txt 

┌───────────────────>
│~ 
└─> cp archivo1.txt /tmp/

┌───────────────────>
│~/tmp 
└─> ls
archivo1.txt

┌───────────────────>
│~/tmp 
└─> mv archivo1.txt archivo2.txt

┌───────────────────>
│~/tmp 
└─> mv /tmp/archivo2.txt .

┌───────────────────>
│~ 
└─> ls
archivo1.txt  Desktop          foqui.sh      install.sh   panda.sh   snap       wget-log
archivo2.txt  dispositivos.sh  Hollywood.sh  listado.txt  parker.sh  Templates  wget-log.1
central       Documents        hora.sh       miku         Pictures   tmp        wget-log.2
coco.sh       Downloads        ima2.png      Music        Public     Videos

```

---

### EJERCICIO 4 🌐

* **Objetivo:** Aprender a trabajar con compresión de archivos.

* Crea un directorio llamado `backup` y copia algunos archivos en él.

* Comprime el directorio `backup` en un archivo `.tar.gz`:

      tar -czvf backup.tar.gz backup/
* Borra el directorio original y extrae el contenido del archivo comprimido:

      tar -xzvf backup.tar.gz

```bash

┌───────────────────>
│~ 
└─> mkdir backup

┌───────────────────>
│~ 
└─> tar -czvf backup.tar.gz backup/

backup/
backup/archivo1.txt
backup/archivo2.txt

┌───────────────────>
│~ 
└─> tar -xzvf backup.tar.gz

backup/
backup/archivo1.txt
backup/archivo2.txt

```

---

### EJERCICIO 5 🌐

* **Objetivo:** Aprender a modificar permisos y propietarios de archivos.

* Crea un archivo llamado `privado.txt`:

      touch privado.txt
* Cambia los permisos del archivo para que solo el propietario pueda leer y escribir:

      chmod 600 privado.txt
* Cambia el propietario del archivo a otro usuario (si tienes privilegios):

      sudo chown usuario privado.txt

```bash

┌───────────────────>
│~ 
└─> touch privado.txt

┌───────────────────>
│~ 
└─> chmod 600 privado.txt

-rw-------  1 quetzal quetzal      0 Dec 16 17:28 privado.txt

┌───────────────────>
│~ 
└─> chmod 644 privado.txt

```

---

### EJERCICIO 6 🌐

* **Objetivo:** Identificar discos y particiones en el sistema.

* Usa `lsblk` para listar los discos y particiones:

      lsblk
* Usa `du -sh` para ver el tamaño del contenido en un directorio de tu elección:

      du -sh /ruta/directorio
* Verifica el uso de disco con `df -h`:

      df -h

```bash

┌───────────────────>
│~ 
└─> lsblk
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINTS
loop0    7:0    0     4K  1 loop /snap/bare/5
loop1    7:1    0  10.8M  1 loop /snap/snap-store/1244
loop2    7:2    0  73.9M  1 loop /snap/core22/1663
loop3    7:3    0 269.8M  1 loop /snap/firefox/4793
loop4    7:4    0  11.1M  1 loop /snap/firmware-updater/147
loop5    7:5    0  10.7M  1 loop /snap/firmware-updater/127
loop6    7:6    0  91.7M  1 loop /snap/gtk-common-themes/1535
loop7    7:7    0 505.1M  1 loop /snap/gnome-42-2204/176
loop8    7:8    0  38.8M  1 loop /snap/snapd/21759
loop9    7:9    0  10.5M  1 loop /snap/snap-store/1173
loop10   7:10   0  44.3M  1 loop /snap/snapd/23258
loop11   7:11   0   568K  1 loop /snap/snapd-desktop-integration/253
loop12   7:12   0   500K  1 loop /snap/snapd-desktop-integration/178
loop13   7:13   0  73.9M  1 loop /snap/core22/1722
sda      8:0    0    40G  0 disk 
├─sda1   8:1    0     1M  0 part 
└─sda2   8:2    0    40G  0 part /
sr0     11:0    1  1024M  0 rom  

┌───────────────────>
│~ 
└─> du -sh /snap/bare/5
512	/snap/bare/5

┌───────────────────>
│~ 
└─> du -sh /snap/firmware-updater/147
34M	/snap/firmware-updater/147

┌───────────────────>
│~ 
└─> df -h
Filesystem      Size  Used Avail Use% Mounted on
tmpfs           392M  1.6M  391M   1% /run
/dev/sda2        40G  6.7G   31G  19% /
tmpfs           2.0G     0  2.0G   0% /dev/shm
tmpfs           5.0M  8.0K  5.0M   1% /run/lock
tmpfs           392M  148K  392M   1% /run/user/1000

```

---

### EJERCICIO 7

* **Objetivo:** Crear y formatear una nueva partición (Usar disco de práctica o máquina virtual).

* Identifica un disco no particionado:

      sudo fdisk -l
* Usa `fdisk` para crear una nueva partición:

      sudo fdisk /dev/sdX
* Formatea la partición como `ext4`:

      sudo mkfs.ext4 /dev/sdX1
* Monta la partición en un directorio y prueba escribiendo archivos en ella:

      sudo mount /dev/sdX1 /mnt/nueva_particion
      echo "Prueba de escritura" > /mnt/nueva_particion/test.txt

```bash

┌───────────────────>
│~ 
└─> sudo fdisk -l
Disk /dev/loop0: 4 KiB, 4096 bytes, 8 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop1: 10.76 MiB, 11280384 bytes, 22032 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop2: 73.88 MiB, 77463552 bytes, 151296 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop3: 269.77 MiB, 282873856 bytes, 552488 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop4: 11.11 MiB, 11649024 bytes, 22752 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop5: 10.72 MiB, 11239424 bytes, 21952 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop6: 91.69 MiB, 96141312 bytes, 187776 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop7: 505.09 MiB, 529625088 bytes, 1034424 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/sda: 40 GiB, 42949672960 bytes, 83886080 sectors
Disk model: VBOX HARDDISK   
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes
Disklabel type: gpt
Disk identifier: B13DF641-E24D-4D9F-9F9D-7CD2E8736869

Device     Start      End  Sectors Size Type
/dev/sda1   2048     4095     2048   1M BIOS boot
/dev/sda2   4096 83884031 83879936  40G Linux filesystem


Disk /dev/loop8: 38.83 MiB, 40714240 bytes, 79520 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop9: 10.54 MiB, 11051008 bytes, 21584 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop10: 44.3 MiB, 46448640 bytes, 90720 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop11: 568 KiB, 581632 bytes, 1136 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop12: 500 KiB, 512000 bytes, 1000 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes


Disk /dev/loop13: 73.87 MiB, 77459456 bytes, 151288 sectors
Units: sectors of 1 * 512 = 512 bytes
Sector size (logical/physical): 512 bytes / 512 bytes
I/O size (minimum/optimal): 512 bytes / 512 bytes

┌───────────────────>
│~ 
└─> sudo fdisk /dev/sdX

Welcome to fdisk (util-linux 2.39.3).
Changes will remain in memory only, until you decide to write them.
Be careful before using the write command.

fdisk: cannot open /dev/sdX: No such file or directory

```