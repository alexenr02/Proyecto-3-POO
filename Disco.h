#include<iostream>

using namespace std;


class Disco : public Material
{
    private:
        int duracion;
        string Genero;
    public:
        Disco();
        Disco(int _idMaterial,string _titulo,int _duracion,string _Genero);
        //Metodos Get
        int getDuracion(){return duracion;};
        string getGenero(){return Genero;};
        //Metodos Set
        void setDuracion(int _duracion){duracion=_duracion;};
        void setGenero(string _Genero){Genero=_Genero;};
        //Metodos abstractos
        void muestraDatos();
        int cantidadDiasPrestamo();
};

Disco::Disco():Material()
{
    duracion=1;
    Genero="Unknown";
}

Disco::Disco(int _idMaterial,string _titulo,int _duracion,string _Genero):Material( _idMaterial, _titulo)
{
    duracion=_duracion;
    Genero=_Genero;
}

void Disco::muestraDatos()
{
    cout<< "\n--------Datos del Disco---------\n\n";
    cout<< "ID: "<<Material::idMaterial<<endl;
    cout<< "Título: "<<Material::titulo<<endl;
    cout<< "Duración: " << duracion <<endl;
    cout<< "Género: " << Genero << endl;
}

int Disco::cantidadDiasPrestamo()
{
    return 2;
}
