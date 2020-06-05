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
                int aux,aux2,aux3,cantDias;
                Fecha fechafinal;
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
                           cantDias=MaterialArray[a]->cantidadDiasPrestamo();
                        }
                    }
                    fechafinal=ReservacionesArray[z].calculaFechaFinReserva(cantDias);
                    cout <<  fechafinal;

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
                int aux,aux2,aux3,cantDias;
                Fecha fechafinal;
                for(int z=0;z<y;z++)
                {
                    cout << "Reservación: " << z+1 << endl;
                    aux=ReservacionesArray[z].getMaterial(); //id del material

                    for(int a=0; a<x;a++)
                    {
                        aux2=MaterialArray[a]->getIdMaterial();

                        if(aux==aux2)
                        {
                           aux3=a; //aux3 guarda el id para reconocer el titulo del articulo
                           cantDias=MaterialArray[a]->cantidadDiasPrestamo();
                        }
                    }
                    cout << "Titulo: ";
                    cout <<MaterialArray[aux3]->getTitulo();
                    cout << endl;
                    cout << "Fecha de reservación: \t\t\t";
                    cout << ReservacionesArray[z].getFecha();
                    //cout << endl;
                    fechafinal=ReservacionesArray[z].calculaFechaFinReserva(cantDias);
                    cout << "Fecha en que termina la reservación: \t";
                    cout <<  fechafinal;
                    cout << endl;
                }

                break;
            }
            case 'D':
            {
                int aux,aux2,aux3,cantDias;
                Fecha fechafinal,f5,fechainicio;
                cout << "Ingresa una fecha que quieras verificar: " << endl;
                cin >>f5;
                for(int z=0;z<y;z++)
                {
                    aux=ReservacionesArray[z].getMaterial(); //id del material
                    for(int a=0; a<x;a++)
                    {
                        aux2=MaterialArray[a]->getIdMaterial();

                        if(aux==aux2)
                        {
                           aux3=a; //aux3 guarda el id para reconocer el titulo del articulo
                           cantDias=MaterialArray[a]->cantidadDiasPrestamo();
                        }
                    }
                    //cout << endl;
                    fechainicio= ReservacionesArray[z].getFecha();
                    fechafinal=ReservacionesArray[z].calculaFechaFinReserva(cantDias);
                    if(f5>=fechainicio&&f5<=fechafinal)
                    {
                        cout << "\nFecha de reservación: \t\t\t";
                        cout << fechainicio;
                        cout << "Fecha en que termina la reservación: \t";
                        cout <<  fechafinal;
                        cout << "Titulo: ";
                        cout <<MaterialArray[aux3]->getTitulo();
                        cout << "\nId de cliente: ";
                        cout << ReservacionesArray[z].getCliente();
                        cout << endl;
                    }
                    else
                        cout <<"No hay reservaciones en esa fecha, intenta con otra. \n";

                }

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
