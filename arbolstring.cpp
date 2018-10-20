///PROGRAMA MODIFICADO POR BRAYAN GUADALUPE HERNANDEZ
#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<windows.h>
#include <iomanip>
using namespace std;
int auxX=0;
string arreglo[]= {   "BRAYAN","Guadalupe","Hernadez","Ico","22","Estructuras Dtos"};
struct Nodo
{
    string dato;
    Nodo *der;
    Nodo *izq;

};
void gotoxy(int x, int y);
Nodo *arbol =NULL;
///prototipos
///void funcion de menu
void menu();

Nodo *crearNodo(int);
int posicion=0;
void insertarNodo(Nodo *&, string);
void mostrarArbol(Nodo *, int,int);
void mostrarArbol2(Nodo *, int);

void niveles(Nodo *,int);

int main()
{

    menu();


    getch();
    return 0;
}
///FUNCION PARA CREAR UN NUEVO NODO
Nodo *crearNodo(string n)
{

    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, string n)
{
    if(arbol==NULL)
    {
        ///si el arbol esta vacio crear nuevo nodo
        Nodo *nuevo_nodo =crearNodo(n);
        arbol=nuevo_nodo;
    }
    else
    {
///si el arbol tiene un nodo o mas
        string valorRaiz= arbol->dato;///obtenemos el valor de la raiz
        if (n==valorRaiz)
        {
            return;
        }
        if(n< valorRaiz) ///SI EL ELEMTO ES MENOS A LA RAIZ insertar a izq
        {
            insertarNodo(arbol->izq,n);
        }
        else
        {
            ///si el elemento es mayor ala raiz inserata a la derecha
            insertarNodo(arbol->der,n);
        }


    }


}

void niveles(Nodo *arbol, int cont)
{
    if(arbol==NULL)
    {
        return;
    }
    else
    {
        niveles(arbol->der, cont+1);
        if(posicion<cont)
        {
            posicion=cont;
        }
        niveles(arbol->izq, cont+1);
    }
}

void menu()
{
    int  opcion, contador=1;
	string masdatos,dato;
    do
    {
        cout<<"\t._ _ _ _ _ _ _ _ _MENU:_ _ _ _ _ _ _ _ _ _ "<<endl;
        cout<<"\n1 Insertar los datos del arreglo que son: arreglo[]= {   BRAYAN,Guadalupe,Hernadez,Ico,22,EstructurasDtos};\n2 Mostrar arbol de dos formas\n3 Insertar mas datos\n4 salir"<<endl;
        cout<<"_ _ _ _ _ _ _ _  _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _";
        cout<<"\nOpcion ----->";
        cin>>opcion;
        switch(opcion)
        {
        case 1:
            cout<<"\nNUMEROS DEL ARREGLO INSERTANDOS CORECTAMENTE:\n ";
            for(int i=0; i<6; i++)
            {
                dato= arreglo[i];
                insertarNodo(arbol,dato); ///insertar un nuevo nodo
            }

            cout<<"\n";
            ;
            break;
        case 2:
            cout<<"\nMOSTRANDO EL ARBOL COMPLETO\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";

            auxX=0;

            mostrarArbol2(arbol,auxX);

            cout << "\nMostrar el arbol:\n\n";
            niveles(arbol,contador);

            for(int i=1; i<posicion+1; i++)
            {
                mostrarArbol(arbol,contador, i);
                cout << endl;
            }

            break;
        case 3:
            int cantidad;
            cout<<"\nINSERTAR MAS DATOS\n";
            cout<<"¿CUANTOS DATOS MAS QUIERES?\n";
            cin>>cantidad;
            for (int i=0; i<cantidad; i++)
            {
                cout<<"Inserta dato "<<i+1<<".....";
                cin>>masdatos;
                cout<<endl;
                insertarNodo(arbol,masdatos); ///insertqar un nuevo nodo
            }
            break;

        }
        cout<<"\n\n\n\n";
        system("pause");
        system("cls");
    }
    while (opcion !=4);
    cout<<"\n\tPROGRAMA MODIFICADO POR BRAYAN GUADALUPE HERNANDEZ (con fines estudiantiles)\n\n\n";
    cout<<"\t          ****             ****\n";
    cout<<"\t          *(0)*             *(0)*\n";
    cout<<"\t          ****             ****\n";
    cout<<"\t                               \n";
    cout<<"\t                   **             \n";
    cout<<"\t                  ****             \n";
    cout<<"\t    ++         <<<< >>>>>           ++\n";
    cout<<"\t     ++                            ++\n";
    cout<<"\t      ++  ++++++++++++++++++++++++ +                        \n";
    cout<<"\t       ++ ++++++++++++++++++++++ +                      \n";
    cout<<"\t          ++ +++++++++++++++++ +                     \n";
    cout<<"\t           ++ ++++++++++++ +                     \n";

}

///funcion para mostrar arbol
void mostrarArbol(Nodo *arbol, int cont, int posicionactual)
{
    if(arbol==NULL)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->izq, cont+1, posicionactual);
        if(cont==posicionactual)
        {

            cout << arbol->dato;
        }
        else
        {
            cout << "~~~";
        }
        mostrarArbol(arbol->der, cont+1, posicionactual);
    }
}


void mostrarArbol2(Nodo *arbol, int auxY)
{
    if (arbol==NULL)
    {
        return;
    }
    auxX +=5;
    mostrarArbol2(arbol->izq,auxY+2);
    gotoxy (10+auxX-auxY, 15+auxY);
    cout << arbol -> dato << endl << endl;
    mostrarArbol2(arbol->der,auxY+2);

}
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);

}









