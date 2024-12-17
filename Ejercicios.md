# ACTIVIDADES Y EJERCICIOS

## ACTIVIDADES

#### ACTIVIDAD 1

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

* ¿Cuál es la diferencia entre `lsusb` y `lspci`?

* ¿Qué información adicional proporciona `dmesg | grep usb`?

---

### ACTIVIDAD 2

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

* ¿Qué particiones están montadas actualmente?

* ¿Qué tipo de sistemas de archivos se usan en las particiones?

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

### ACTIVIDAD 4

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

* ¿Qué dispositivos de sonido se detectaron?

* ¿Qué procesos están usando la tarjeta de sonido?

---

### ACTIVIDAD 5

1. Cree un archivo llamado `dispositivos.sh` y agregue el siguiente contenido: ```bash #!/bin/bash echo "Dispositivos de bloque:" lsblk echo "Dispositivos USB:" lsusb echo "Dispositivos PCI:" lspci echo "Dispositivos de entrada:" cat /proc/bus/input/devices echo "Salidas de video:" xrandr echo "Tarjetas de sonido:" aplay -l ```

2. Ejecute el script usando `bash dispositivos.sh`.

3. Modifique el script para guardar la salida en un archivo llamado `resumendispositivos.txt`.

```bash

┌───────────────────>
│~ 
└─> nano dispositivos.sh 



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


```

4. Conteste:

* ¿Qué ventajas tiene usar un script para recopilar esta información?

* ¿Qué cambios realizaría para personalizar el script?

---
---

## EJERCICIOS