#include <iostream>
#include "Fecha.h"

using namespace std;

class Reserva
{
    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;

    public:
        Reserva();
        Reserva(int _idMaterial, int _idCliente, Fecha _fechaReservacion);

        //Metodos get
        int getMaterial(){return idMaterial;};
        int getCliente(){return idCliente;};
        Fecha getFecha(){return fechaReservacion;};
        //Metodos Set
        void setMaterial(int _idMaterial){idMaterial=_idMaterial;};
        void setCliente(int _idCliente){idCliente= _idCliente;};
        void setFecha(Fecha _fechaReservacion){fechaReservacion=_fechaReservacion;};
        Fecha calculaFechaFinReserva(int _cantDias){return fechaReservacion+_cantDias;};

        void muestraReservacion();


};


void Reserva::muestraReservacion()
{
    cout<< "\n--------Datos de la reservación---------\n\n";
    cout<< "ID del material: "<<idMaterial<<endl;
    cout<< "ID del cliente: " << idCliente<<endl;
    cout<< "Fecha de reservación: "<<fechaReservacion;
}


Reserva::Reserva()
{
    idMaterial=0;
    idCliente=0;
    fechaReservacion=Fecha();
}

Reserva::Reserva(int _idMaterial,int _idCliente,Fecha _fechaReservacion)
{
    idMaterial=_idMaterial;
    idCliente=_idCliente;
    fechaReservacion=_fechaReservacion;
}
