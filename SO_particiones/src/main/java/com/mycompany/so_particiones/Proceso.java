/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.so_particiones;

/**
 *
 * @author pirof
 */
public class Proceso {
    private int numeroProceso;
    private int tamanioProceso;
    boolean ocupado;

    public Proceso() {
    }

    public Proceso(int tamanioProces) {
        this.numeroProceso = -1;
        this.tamanioProceso = tamanioProceso;
        this.ocupado = false;
    }

    public int getNumeroProceso() {
        return numeroProceso;
    }

    public void setNumeroProceso(int numeroProceso) {
        this.numeroProceso = numeroProceso;
    }

    public int getTamanioProceso() {
        return tamanioProceso;
    }

    public void setTamanioProceso(int tamanioProceso) {
        this.tamanioProceso = tamanioProceso;
    }

    public boolean isOcupado() {
        return ocupado;
    }

    public void setOcupado(boolean ocupado) {
        this.ocupado = ocupado;
    }
    
    
    
}
