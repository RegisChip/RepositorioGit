/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.so_particiones;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author pirof
 */
public class SO_particiones {

    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        //ArrayList<Proceso> procesos = new ArrayList<>();
        //Proceso proceso;
        
        int tamanioMemoria = 0;
        int tamanioParticion = 0;
        int numParticiones = 0;
        
        
        System.out.print("Tamaño de memoria (KB): ");
        tamanioMemoria = scanner.nextInt();
        
        System.out.print("Numero de particiones: ");
        numParticiones = scanner.nextInt();
        
        Proceso[] particiones = new Proceso[numParticiones];
        int particion;
        int totalParticiones = 0;
        int suma = 0;
        try {
            
            if (numParticiones > 100){
                System.out.println("Número de particiones máximo (100)");
                return;
            }
            
            for (int i = 0; i < numParticiones; i++) {
                
                System.out.println("Tamaño de la particion " + (i + 1) + ":" );
                particion = scanner.nextInt();
                particiones[i] = new Proceso(particion);
                totalParticiones += particion;
            }
            
            if(totalParticiones > tamanioMemoria){
                System.out.println("El tamaño de las particiones excede la memoria");
                return;
                
            }
            
            boolean programa = true;
            
            while(programa = true){

                int menu = 0;
                System.out.println(" - Menu - ");
                System.out.println("1. Asignar Proceso");
                System.out.println("2. Liberar Proceso");
                System.out.println("3. Moatrar Proceso");
                System.out.println("4. Salir");
                
                menu = scanner.nextInt();
                
                int id = 0;
                int tamanio = 0;

                switch(menu){
                    
                    case 1: {
                        
                        System.out.println("Ingrese el ID del proceso: ");
                        id = scanner.nextInt();
                        System.out.println("Ingrese el tamaño del proceso (KB): ");
                        tamanio = scanner.nextInt();

                        boolean asignado = false;
                        
                        for (int i = 0; i < tamanioParticion; i++) {
                            if (particiones[i].getNumeroProceso() == -1 && particiones[i].getTamanioProceso() >= tamanio){
                                particiones[i].setNumeroProceso(id);
                                asignado = true;
                                System.out.println("Proceso " + id + " asignado a la particion " + (i + 1));
                                break;
                            }
                        }
                        
                        if(!asignado){
                            System.out.println("No se encontró particion disponible para el proceso " + id);
                            
                        }

                        break;
                        
                    }
                    case 2:{
                        
                        System.out.println("Ingrese el numero del proceso a liberar:");
                        int opcion = scanner.nextInt();
                        
                        boolean liberar = false;
                        for (int i = 0; i < tamanioParticion; i++) {
                            if (particiones[i].getNumeroProceso() == id){
                                particiones[i].setNumeroProceso(-1);
                                liberar = true;
                                System.out.println("Proceso " + id + " liberado de la particion " + (i + 1));
                            }
                            
                        }
                           
                        if(!liberar){
                            System.out.println("No se encontró el proceso " + id + " en ninguna particion");
                            
                        }
                            
                        break;
                    }
                    case 3:{
                        
                        imprimir(particiones);
                        break;
                        
                    }
                    case 4:{
                        
                        System.out.println("Bye bye");
                        programa = false;
                        break;
                    }
                    
                    default: {
                        
                        System.out.println("Escriba una opcion valida");
                        
                    }  
                }
            }
            
            
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        
        /*
        int numeroParticiones = tamanioMemoria/tamanioParticion;
        
        for (int i = 0; i < numeroParticiones; i++) {
            //proceso = new Proceso(tamanioParticion);
            procesos.add(new Proceso(tamanioParticion));
            
        }
        
        */

    }
    
    //public static void asignar(ArrayList<Proceso> procesos){
        
    //}
    
    public static void imprimir(Proceso[] procesos){
        
        System.out.println("Estado de la memoria: ");
        
        for (int i = 0; i < procesos.length; i++) {
            if (procesos[i].getNumeroProceso() == -1){
                System.out.println("Particion " + (i + 1) + ": " + procesos[i].getTamanioProceso() + " KB libre");
            }
            if (procesos[i].getNumeroProceso() == -1){
                System.out.println("Particion " + (i + 1) + ": " + procesos[i].getTamanioProceso() + " KB proceso " + procesos[i].getNumeroProceso());
            }
            
        }
        
        System.out.println("");
    }
    
    
}
