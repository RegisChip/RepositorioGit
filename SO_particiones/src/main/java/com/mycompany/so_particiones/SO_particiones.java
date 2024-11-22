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
        ArrayList<Proceso> procesos = new ArrayList<>();
        //Proceso proceso;
        
        int tamanioMemoria;
        int tamanioParticion;
        int numParticiones = 0;
        
        
        System.out.print("Tamaño de memoria (KB): ");
        tamanioMemoria = scanner.nextInt();
        
        System.out.print("Numero de particiones: ");
        numParticiones = scanner.nextInt();
        
        int[] particiones = new int[numParticiones];
        int particion;
        
        try {
            
            for (int i = 0; i < particiones.length; i++) {
                
                System.out.println("Tamaño de la particion " + (i + 1) + ":" );
                particion = scanner.nextInt();
                particiones[i] = particion;
                
            }
            
            int suma = 0;
            
                    
            for (int i = 0; i < particiones.length; i++) {
                
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
        
        boolean programa = true;
        while(programa = true){
            
            int menu = 0;
            System.out.println(" - Menu - ");
            System.out.println("1. Asignar Proceso");
            System.out.println("2. Liberar Proceso");
            System.out.println("3. Moatrar Proceso");
            System.out.println("4. Salir");
            
            switch(menu){
                case 1: 
                    System.out.println("Ingrese el ID del proceso: ");
                    int id = scanner.nextInt();
                    
                    
                    
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    System.out.println("Bye bye");
                    programa = false;
            }
        }
*/
    }
    
    //public static void asignar(ArrayList<Proceso> procesos){
        
    //}
}
