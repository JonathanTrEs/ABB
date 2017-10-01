#include "metodos.hpp"



int main()
{
    Nodo* Nodito = NULL;
    Arbol A;
    float numero, num_b;
    int opcion = 0;
    bool salir = false;
    Nodo* pos_insertar = NULL;
    Nodo* busqueda = NULL;
    while(!salir)
    {
        cout << "==============----------------MENU----------------==============" << endl;
        cout << "1  Insertar un elemento en el arbol" << endl;
        cout << "2  Eliminar un elemento del arbol" << endl;
        cout << "3  Buscar un elemento en el arbol" << endl;
        cout << "4  Imprimir arbol" << endl;
        cout << "5  Salir" << endl;
        cout << "===============----------------------------------===============" << endl;
        cout << endl;
        cout << "Introduzca opcion: ";
        cin >> opcion;
        switch(opcion)
        {
            case 1:
                do
                {
                    cout << "Introduzca numero a insertar en el arbol: ";
                    cin >> numero;
                }while(numero < 0.0 || numero > 100.00);
                Nodito = new Nodo(numero);
                A.Insertar(numero, Nodito, Nodito);
                break;
            case 2:
                cout << "Introduzca el elemento que quiere eliminar del arbol" << endl;
                cin >> num_b;
                busqueda = A.Buscar(num_b);
                if(busqueda != NULL)
                    A.Borrar(busqueda);
                else
                    cout << "El elemento no se puede eliminar porque no se encuentra en el arbol" << endl;
                break;
            case 3:
                cout << "introduzca numero a buscar: ";
                cin >> num_b;
                pos_insertar = A.Buscar(num_b);
                if(pos_insertar)
                {
                    cout << pos_insertar -> get_dato() << endl;
                    cout << "El numero ha sido econtrado" << endl;
                }
                else
                    cout << "No se ha encontrado el numero en el arbol" << endl;
                    break;
            case 4:
                cout << "=============================ARBOL=============================" << endl;
                A.Imprimir();
                cout << "===============================================================" << endl;
                break;
            case 5:
                salir = true;
                break;
        }
    }
    return 0;
}
