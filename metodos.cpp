#include "metodos.hpp"

//Metodos Nodo

Nodo::Nodo()
{
    dato = 0;
    izq = NULL;
    der = NULL;
}

Nodo::Nodo(float valor)
{
    dato = valor;
    cout << "El dato vale: " << dato << endl;
    izq = NULL;
    der = NULL;
}

Nodo* Nodo::get_izq()
{
    return izq;
}

Nodo* Nodo::get_der()
{
    return der;
}

float Nodo::get_dato()
{
    return dato;
}

void Nodo::set_dato(float data)
{
    dato = data;
}

void Nodo::set_izq(Nodo* p)
{
    izq = p;
}

void Nodo::set_der(Nodo* d)
{
    der = d;
}

//Metodos Arbol

Arbol::Arbol()
{
    Raiz = NULL;
}

bool Arbol::Es_Hoja(Nodo* h)
{
    return !h -> get_izq() && !h -> get_der();
}

bool Arbol::Esta_vacio()
{
    return (Raiz == 0);
}

Nodo* Arbol::BuscarRama(Nodo* inicio, float clave)
{
    if(inicio == NULL)
        return NULL;
    if(clave == inicio -> get_dato())
        return inicio;
    if(clave < inicio -> get_dato())
        return BuscarRama(inicio -> get_izq(), clave);
    else
    return BuscarRama(inicio -> get_der(), clave);
}

Nodo* Arbol::Buscar(float valor)
{
    return BuscarRama(Raiz, valor);
}

Nodo* Arbol::Buscar_Padre(Nodo* busqueda, Nodo* Inicio)
{
    Nodo* Sig_i = Inicio -> get_izq();
    Nodo* Sig_d = Inicio -> get_der();
    if(Sig_d != NULL && busqueda -> get_dato() == Sig_d -> get_dato())
        return Inicio;

    else if(Sig_i != NULL && busqueda -> get_dato() == Sig_i -> get_dato())
        return Inicio;

    else if(busqueda -> get_dato() < Inicio -> get_dato())
        return Buscar_Padre(busqueda, Inicio -> get_izq());

    else if (busqueda -> get_dato() > Inicio -> get_dato())
        return Buscar_Padre(busqueda, Inicio -> get_der());
    return NULL;
}

void Arbol::Insertar_Rec(Nodo* n_insertar, float num, Nodo* n_principio)
{
    Nodo* Siguiente_izq = n_insertar -> get_izq();
    Nodo* Siguiente_der = n_insertar -> get_der();
    if(num < n_insertar -> get_dato())
    {
        if(Siguiente_izq == 0)
            n_insertar -> set_izq(n_principio);
        else
            Insertar_Rec(n_insertar -> get_izq(), num, n_principio);
    }
    else if(num > n_insertar -> get_dato())
    {
        if(Siguiente_der == 0)
            n_insertar -> set_der(n_principio);
        else
            Insertar_Rec(n_insertar -> get_der(), num, n_principio);
    }
}

void Arbol::Insertar(float n, Nodo* nodo, Nodo* N_insert)
{
    if(Esta_vacio())
        Raiz = nodo;
    else
        Insertar_Rec(Raiz, n, N_insert);
}

void Arbol::Borrar_Hoja(Nodo* borra)
{
    Nodo* Padre = NULL;
    Padre = Buscar_Padre(borra, Raiz);
    if(Padre -> get_izq() == borra)
        Padre -> set_izq(NULL);
    else
        Padre -> set_der(NULL);
    delete borra;
}

void Arbol::Borrar_1hijo(Nodo* eliminar)
{
    Nodo* Padre = NULL;
    Padre = Buscar_Padre(eliminar, Raiz);
    if(eliminar -> get_izq())
    {
        if(Padre -> get_izq() == eliminar)
            Padre -> set_izq(eliminar -> get_izq());
        else
            Padre -> set_der(eliminar -> get_izq());
    }
    else if(eliminar -> get_der())
    {
        if(Padre -> get_izq() == eliminar)
            Padre -> set_izq(eliminar -> get_der());
        else
            Padre -> set_der(eliminar -> get_der());
    }
    delete eliminar;
}

void Arbol::Borrar(Nodo* eliminar)
{
    if(Es_Hoja(eliminar))                   //Si el nodo a borrar es una hoja
        Borrar_Hoja(eliminar);

    else if((!eliminar -> get_izq() && eliminar -> get_der()) || (eliminar -> get_izq() && !eliminar -> get_der()))
    {
        Borrar_1hijo(eliminar);
    }
    else
    {
        cout << "El caso mas dificil" << endl;
    }
}

void Arbol::Imprimir()
{
    cout << "Impresion in-order" << endl;
    imprimeN(Raiz,1);
}

void Arbol::imprimeN(Nodo* nodo, int margen)           //Imprime in-order
{
    if (nodo != NULL)
    {
        imprimeN(nodo -> get_izq(), margen + 1);
        for (int m = 0; m < margen; m++)
            cout << ' ' ;
        cout << nodo -> get_dato();
        imprimeN(nodo -> get_der(), margen + 1);
    }
}

