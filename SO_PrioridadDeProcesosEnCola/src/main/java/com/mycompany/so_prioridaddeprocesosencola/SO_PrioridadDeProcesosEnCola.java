/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.so_prioridaddeprocesosencola;

import java.util.Collections;
import static java.util.Collections.reverseOrder;
import java.util.Comparator;
import static java.util.Comparator.reverseOrder;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.concurrent.PriorityBlockingQueue;

/**
 *
 * @author pirof
 */
public class SO_PrioridadDeProcesosEnCola {

    public static void main(String[] args) {
        
        PriorityQueue<Proceso> colaDeProcesos = new PriorityQueue<>();
        Scanner scanner = new Scanner(System.in);
        
        int opcion;
        int contador = 1;
        
        boolean si = true;
        while(si){
            
            System.out.println("1. Crear proceso\n"
                + "2. Atender proceso\n"
                + "3. Mostrar lista de procesos\n"
                + "4. Salir\n"
                + "-------------------------");
            opcion = scanner.nextInt();

            switch(opcion){
                
                case 1:{
                    int prioridad = numeroAleatorio();
                    Proceso proceso = new Proceso(prioridad, "proceso(" + (contador++) + ")");
                    //colaDeProcesos.offer(proceso);
                    boolean agregado = colaDeProcesos.offer(proceso);
                    if (agregado) {
                        System.out.println("Proceso agregado exitosamente.");
                        System.out.println("Proceso generado: " + proceso.getNombre());
                    } else System.out.println("No se pudo agregar el proceso.");
                    
                    break;
                }
                case 2:{
                    
                    if (colaDeProcesos.isEmpty()) {
                        System.out.println("No existe ningun proceso");
                    } else {
                        Proceso procesoAtendido = colaDeProcesos.poll();
                        //Devuelve el elemento con la mayor prioridad, el primero en la cola
                        System.out.println("Atendiendo al " + procesoAtendido + "...");
                        System.out.println("Proceso atendido");
                    }
                    
                    break;
                }
                case 3:{
                    
                    if (colaDeProcesos.isEmpty()) {
                        System.out.println("No existe procesos en la cola");
                    } else {
                        System.out.println("Cola de procesos:");
                        for (Proceso p : colaDeProcesos) {
                            System.out.println(p);
                        }
                    }
                    
                    break;
                }
                case 4:{
                    System.out.println("Saliendo...");
                    si = false;
                    break;
                }

            }
        }
        
    }
    
    public static int numeroAleatorio() {
        return (int) (Math.random() * 4) + 1;
    }
    
}
