#include <iostream>


class Material
{
    public:
        Material();
        Material(int _idMaterial,string _titulo);

        //Metodos Get
        int getIdMaterial(){return idMaterial;};
        string getTitulo(){return titulo;};

        //Metodos Set
        void setIdMaterial(int _idMaterial){idMaterial=_idMaterial;};
        void setTitulo(string _titulo){titulo=_titulo;};

        virtual void muestraDatos()=0;
        virtual int cantidadDiasPrestamo()=0;

    protected:
        int idMaterial;
        string titulo;

};

Material::Material()
{
    idMaterial=1;
    titulo="Unknown";
}
Material::Material(int _idMaterial,string _titulo)
{
    idMaterial=_idMaterial;
    titulo=_titulo;
}
