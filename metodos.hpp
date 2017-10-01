#ifndef METODOS_HPP_INCLUDED
#define METODOS_HPP_INCLUDED

#include <iostream>
#include <cstdlib>

using namespace std;

typedef float TDato;

class Nodo
{
    private:
        TDato dato;
        Nodo *izq, *der;
    public:
        Nodo();
        Nodo(float valor);

        //gets y sets
        Nodo* get_izq();
        Nodo* get_der();
        float get_dato();
        void set_izq(Nodo* n);
        void set_der(Nodo* d);
        void set_dato(float data);
};

class Arbol
{
    private:
        Nodo *Raiz;           //Apunta al primer elemento del arbol
    public:
        Arbol();

        bool Esta_vacio();
        bool Es_Hoja(Nodo* h);

        Nodo* BuscarRama(Nodo* inicio, float clave);
        Nodo* Buscar(float valor);
        Nodo* Buscar_Padre(Nodo* busqueda, Nodo* Inicio);
        void Insertar_Rec(Nodo* n_insertar, float num, Nodo* n_principio);
        void Insertar(float n, Nodo* nodo, Nodo* N_insert);

        void Borrar_Hoja(Nodo* borra);
        void Borrar_1hijo(Nodo* borra);
        void Borrar(Nodo* eliminar);

        void imprimeN(Nodo* nodo, int margen);
        void Imprimir();

};

#endif // METODOS_HPP_INCLUDED
