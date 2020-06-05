#include<iostream>

using namespace std;


class Libro : public Material
{
    private:
        int numPag;
        string Autor;
    public:
        Libro();
        Libro(int _idMaterial,string _titulo,int _numPag,string _Autor);
        //Metodos Get
        int getNumPag(){return numPag;};
        string getAutor(){return Autor;};
        //Metodos Set
        void setNumPag(int _numPag){numPag=_numPag;};
        void setAutor(string _Autor){Autor=_Autor;};
        //Metodos abstractos
        void muestraDatos();
        int cantidadDiasPrestamo();
};

Libro::Libro():Material()
{
    numPag=1;
    Autor="Unknown";
}

Libro::Libro(int _idMaterial,string _titulo,int _numPag,string _Autor):Material( _idMaterial, _titulo)
{
    numPag=_numPag;
    Autor=_Autor;
}

void Libro::muestraDatos()
{
    cout<< "--------Datos del Libro---------\n\n";
    cout<< "ID: "<<Material::idMaterial<<endl;
    cout<< "Titulo: "<<Material::titulo<<endl;
    cout<< "Número de Páginas: " << numPag<<endl;
    cout<< "Autor: " << Autor << endl;
}

int Libro::cantidadDiasPrestamo()
{
    return 7;
}
