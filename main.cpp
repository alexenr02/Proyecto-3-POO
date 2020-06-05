#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include "Reserva.h"
//#include "Libro.h"
//#include "Disco.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

using namespace std;

void mostrarMenu()
{

        cout << "\n\n------------Menú---------------" << endl << endl;
        cout << "a. Consultar la lista de Materiales. " << endl;
        cout << "b. Consultar la lista de reservaciones. " << endl;
        cout << "c. Consultar las reservaciones de un material dado. " << endl;
        cout << "d. Consultar las reservaciones de una fecha dada. " << endl;
        cout << "e. Hacer una reservación. " << endl;
        cout << "f. Terminar. " << endl;

}


    Material *MaterialArray[30];
    Reserva  ReservacionesArray[60];


int main()
{
    //mostrarMenu();
    //Fecha f1,f2;



    setlocale(LC_CTYPE,"Spanish");
    ifstream archivoMaterial;
    archivoMaterial.open("Material.txt");
    ifstream archivoReservas;
    archivoReservas.open("Reserva.txt");

    int idMaterial,numPag,x=0,duracion,version;
    string titulo,autor,genero,SO;
    char tipo;
    Libro *l1;

    while(archivoMaterial >> idMaterial>>titulo>>tipo)
    {
        if(tipo== 'L')
        {
            archivoMaterial>>numPag>>autor;
            MaterialArray[x]= new Libro(idMaterial,titulo,numPag,autor);

        }
        else if(tipo== 'D')
        {
            archivoMaterial>>duracion>>genero;
            MaterialArray[x]= new Disco(idMaterial,titulo,duracion,genero);

        }
        else if(tipo== 'S')
        {
            archivoMaterial>>version>>SO;
            MaterialArray[x]= new Software(idMaterial,titulo,version,SO);

        }
        //else if(tipo=='S')
        x++;
    }
    archivoMaterial.close();

    int dd,mm,aa,idCliente,y=0;
    Fecha f1;
    Reserva r1;

    while(archivoReservas>>dd>>mm>>aa>>idMaterial>>idCliente)
    {
        f1.setFecha(dd,mm,aa);
        ReservacionesArray[y].setCliente(idCliente);
        ReservacionesArray[y].setMaterial(idMaterial);
        ReservacionesArray[y].setFecha(f1);
        y++;
    }
    archivoReservas.close();
    char opcionDeseada;
    bool terminar=false;
    //cout << ReservacionesArray[2].getMaterial();
    do
    {
        mostrarMenu();
        cout << "\nTu opción es:(A,B,C,D,E o F ) --->  ";
        cin >> opcionDeseada;
        cout<< endl;
        opcionDeseada=toupper(opcionDeseada);
        //k=0;
        //int f=-1;
        switch(opcionDeseada)
        {
            case 'A':
                for(int z=0;z<x;z++)
                {
                    MaterialArray[z]->muestraDatos();
                }

                break;
            case 'B':
            {
                int aux=0,aux2=0,aux3=0,cantDias2=0;
                Fecha fechafinal2;
                for(int z=0;z<y;z++)
                {
                    cout << "Fecha de reservación: \t\t\t";
                    cout << ReservacionesArray[z].getFecha();
                    //cout << endl;
                    cout << "Fecha en que termina la reservación: \t";
                    aux=ReservacionesArray[z].getMaterial(); //id del material
                    for(int a=0; a<x;a++)
                    {
                        aux2=MaterialArray[a]->getIdMaterial();

                        if(aux==aux2)
                        {
                           aux3=a; //aux3 guarda el id para reconocer el titulo del articulo
                           cantDias2=MaterialArray[a]->cantidadDiasPrestamo();
                        }
                    }

                    fechafinal2=ReservacionesArray[z].getFecha()+cantDias2;
                    cout <<  fechafinal2;

                    cout << "Titulo: ";
                    cout <<MaterialArray[aux3]->getTitulo();
                    cout << endl;
                    cout << "ID: ";
                    cout <<aux;
                    cout << endl<<endl;
                }

                break;
            }
            case 'C':
             {
                int DiasPrestamo;
                int queMaterialEs;
                char answer1;

                bool existe;
                int idMat;
                existe=false;
                answer1='N';
                do{
                    cout << "Ingresa el ID del material que quieras verificar: ";
                    cin >> idMat;
                    cout << endl;
                for (int a=0; a<x; a++)
                {
                    if(idMat==MaterialArray[a]->getIdMaterial())
                        {
                            existe=true;
                            queMaterialEs=a; //en el arreglo de materiales
                        }
                }
                    if(existe==false)
                        {
                        cout << "El id del material no existe, ¿Deseas intentar de nuevo?(Y/N) " ;
                        cin >> answer1;
                        cout << endl;
                        answer1=toupper(answer1);
                        if(answer1!='Y')
                                {
                                    goto continuar3;
                                }
                        }
                }while (existe==false && answer1=='Y');

                existe=false;
                for(int z=0; z<y;z++) //z for Reservaciones array
                    {
                        if(MaterialArray[queMaterialEs]->getIdMaterial()==ReservacionesArray[z].getMaterial())
                        {
                            existe=true;
                            DiasPrestamo=MaterialArray[queMaterialEs]->cantidadDiasPrestamo();
                            cout <<"Título: ";
                            cout <<MaterialArray[queMaterialEs]->getTitulo();
                            cout << endl;
                            cout <<"Fecha de Reservación: ";
                            cout <<ReservacionesArray[z].getFecha();
                            cout <<"Fecha de devolución: ";
                            cout <<ReservacionesArray[z].getFecha()+DiasPrestamo;
                            cout << endl;

                        }
                    }
                    if(existe==false)
                    cout << "Lo siento, no hay reservaciones de ese artículo. \n" << endl;
continuar3:         break;
            }
            case 'D':
            {
                bool reserved;
                bool comprobar=false;
                int aux,aux2,aux3,cantDias;
                Fecha fechafinal,f6,fechainicio;
                cout << "Ingresa una fecha que quieras verificar: " << endl;
                cin >>f6;

                for(int a=0; a<x;a++)// a for Material array
                {
                    for(int z=0; z<y;z++) //z for Reservaciones array
                     {
                         if(MaterialArray[a]->getIdMaterial()==ReservacionesArray[z].getMaterial())
                         {
                             aux3=z;
                             cantDias=MaterialArray[a]->cantidadDiasPrestamo();
                             fechainicio= ReservacionesArray[z].getFecha();
                             fechafinal= ReservacionesArray[z].getFecha()+cantDias;
                             if((f6>=fechainicio) && (f6<=fechafinal))
                             {
                                    comprobar=true;
                                    cout << "Título: ";
                                    cout << MaterialArray[a]->getTitulo()<<endl;
                                    cout << "Id del cliente: ";
                                    cout << ReservacionesArray[z].getCliente() << endl;
                                    cout << "Fecha de inicio de reservación: ";
                                    cout << fechainicio ;
                                    cout << "Fecha de devolución: ";
                                    cout << fechafinal;
                                    cout << endl;

                             }
                             //fechafinal.setFecha(1,1,1);
                         }
                     }

                }
                if(comprobar==false)
                    cout <<"No hay reservaciones en esa fecha, intenta con otra. \n";

                break;
            }
            case 'E':
                {
                    int aux,aux2,aux3,cantDias,auxiliar;
                    Fecha fechafinal,f5,fechainicio;
                    Fecha reservacion;
                    int idCliente,idMat,contador=0;
                    char answer;
                    bool ok=false,notokay=false,noexist;
                    bool encontro=false;
                    do
                    {
                        cout << "Ingrese la ID del cliente: " << endl;
                        cin >> idCliente;
                        for(int q=0;q<y;q++)
                        {
                            if(ReservacionesArray[q].getCliente()==idCliente)
                            {
                                encontro=true;
                            }
                        }
                        if(encontro==false)
                            {
                                cout <<"El ID del cliente no existe, ¿Intentar de nuevo (Y/N)? ";
                                cin>>answer;
                                answer=toupper(answer);
                                if(answer!='Y')
                                {
                                    goto continuar;
                                }
                            }
                    }while(answer=='Y'&&encontro==false);

                    encontro=false;
                    do
                    {
                        cout << "Ingrese el ID del material: " << endl;
                        cin >> idMat;
                        for(int q=0;q<x;q++)
                        {
                            if(MaterialArray[q]->getIdMaterial()==idMat)
                            {
                                encontro=true;
                            }
                        }
                        if(encontro==false)
                            {
                                cout <<"El ID del material no existe, ¿Intentar de nuevo (Y/N)? ";
                                cin>>answer;
                                answer=toupper(answer);
                                if(answer!='Y')
                                    {
                                        goto continuar;
                                    }
                            }
                    }while(answer=='Y'&&encontro==false);
                    int cantDias2;
                    //Fecha fStart,fEnd;

                    //ya tengo una ID del material y del cliente.

                    bool sePuede;

                    for(int a=0; a<x;a++)
                                {
                                   // idMat=MaterialArray[a]->getIdMaterial();

                                    if(idMat==MaterialArray[a]->getIdMaterial())
                                        {
                                            cantDias2=MaterialArray[a]->cantidadDiasPrestamo();
                                        }
                                }

                    do{
                        cout << "¿En qué fecha desea reservar?\n";
                        cin>> f5;
                        encontro=false;
                        sePuede=true;
                        answer='N';
                        for(int b=0; b<y;b++)
                        {
                            if(ReservacionesArray[b].getMaterial()==idMat)
                                {

                                    encontro=true;
                                    if(f5>=(ReservacionesArray[b].getFecha()-cantDias2) && f5<=(ReservacionesArray[b].getFecha()+cantDias2))
                                        {
                                            sePuede=false;

                                            //aux=b;
                                        }
                                }
                        }
                        if(sePuede==false)
                            {

                                cout <<"Ya hay una reservación en esa fecha, ¿Intentar de nuevo (Y/N)? ";
                                cin>>answer;
                                answer=toupper(answer);
                                if(answer!='Y')
                                    {
                                        //encontro=false;
                                        goto continuar;
                                    }


                            }

                    }while(answer=='Y');
                    if((sePuede==true || encontro==false))
                    {
                        ReservacionesArray[y].setMaterial(idMat);
                        ReservacionesArray[y].setFecha(f5);
                        ReservacionesArray[y].setCliente(idCliente);
                        cout << "La reservación se hizo con éxito. ";
                        ReservacionesArray[y].muestraReservacion();
                        cout << "La fecha de devolución es: ";
                        cout <<ReservacionesArray[y].getFecha()+cantDias2;
                        y+=1;
                        encontro=false;
                        sePuede=true;
                    }
                }
continuar:  break;
            case 'F':
                {
                Fecha fechanueva;
                ofstream archivoReservasGuardar;
                archivoReservasGuardar.open("Reserva.txt");
                for(int v=0;v<y;v++)
                {
                    fechanueva=ReservacionesArray[v].getFecha();
                    archivoReservasGuardar << fechanueva.getDia()<< " " << fechanueva.getMes()<< " " << fechanueva.getAnio()<< " " << ReservacionesArray[v].getMaterial()<< " " << ReservacionesArray[v].getCliente();
                    archivoReservasGuardar << endl;
                }
                archivoReservasGuardar.close();
                cout << "Gracias, hasta luego" << endl;
                return 0;
                break;
                }
            default:
                cout<< "\nNo es una opción correcta, ingresa A,B,C,D,E o F según desees.\n" << endl;


        }
        if(opcionDeseada=='F')
        {
            terminar=true;
        }

    }while(terminar==false);
}
