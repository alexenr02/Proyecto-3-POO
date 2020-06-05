#include<iostream>

using namespace std;


class Software : public Material
{
    private:
        int Version;
        string SO;
    public:
        Software();
        Software(int _idMaterial,string _titulo,int _Version,string _SO);
        //Metodos Get
        int getVersion(){return Version;};
        string getSO(){return SO;};
        //Metodos Set
        void setVersion(int _Version){Version=_Version;};
        void setSO(string _SO){SO=_SO;};
        //Metodos abstractos
        void muestraDatos();
        int cantidadDiasPrestamo();
};

Software::Software():Material()
{
    Version=1;
    SO="Unknown";
}

Software::Software(int _idMaterial,string _titulo,int _Version,string _SO):Material( _idMaterial, _titulo)
{
    Version=_Version;
    SO=_SO;
}

void Software::muestraDatos()
{
    cout<< "\n--------Datos del Software---------\n\n";
    cout<< "ID: "<<Material::idMaterial<<endl;
    cout<< "Titulo: "<<Material::titulo<<endl;
    cout<< "Versión: " << Version <<endl;
    cout<< "Sistema Operativo: " << SO<< endl;
}

int Software::cantidadDiasPrestamo()
{
    return 1;
}
