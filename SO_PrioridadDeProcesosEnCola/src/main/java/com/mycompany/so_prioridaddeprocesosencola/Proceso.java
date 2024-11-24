/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.so_prioridaddeprocesosencola;

import java.util.concurrent.PriorityBlockingQueue;

/**
 *
 * @author pirof
 */
public class Proceso implements Comparable<Proceso> {
    
    private int prioridad;
    private String nombre;
    //private PriorityBlockingQueue<ColaPrioridad> cola;

    public Proceso() {
    }

    public Proceso(int prioridad, String nombre) {
        this.prioridad = prioridad;
        this.nombre = nombre;
        //this.cola = cola;
    }

    public int getPrioridad() {
        return prioridad;
    }

    public void setPrioridad(int prioridad) {
        this.prioridad = prioridad;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    @Override
    public String toString() {
        return "Proceso{" + "prioridad=" + prioridad + ", nombre=" + nombre + '}';
    }


    @Override
    public int compareTo(Proceso o) {
        return Integer.compare(o.prioridad, this.prioridad);
    }
    
    
    
}
