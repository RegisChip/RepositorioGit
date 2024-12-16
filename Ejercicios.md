# ACTIVIDADES Y EJERCICIOS

---
---

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

### ACTIVIDAD 2

### ACTIVIDAD 3

### ACTIVIDAD 4

### ACTIVIDAD 5

---
---

## EJERCICIOS