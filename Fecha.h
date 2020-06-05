#include <iostream>

using namespace std;

class Fecha
{
    private:
        int dd,mm,aa;

    public:
        Fecha();
        Fecha(int _dd,int _mm,int _aa);
        //metodos get
        int getDia(){return dd;};
        int getMes(){return mm;};
        int getAnio(){return aa;};
        string nombreMes();
        //setFecha
        void setFecha(int _dd,int _mm, int _aa);
        //sobrecargas
        Fecha operator+(int dias);
        Fecha operator-(int dias);
        bool operator >=(Fecha);
        bool operator <=(Fecha);
        bool operator >(Fecha);
        bool operator <(Fecha);
        bool operator ==(Fecha);

        friend ostream &operator << (ostream &os, Fecha _fecha);
        friend istream &operator >> (istream &os, Fecha &_fecha);

};


Fecha::Fecha()
{
    dd=1;
    mm=1;
    aa=1;
}

Fecha::Fecha(int _dd,int _mm,int _aa)
{   if(_dd==0 || _mm ==0 ||_aa == 0)
    {
        dd=_dd+1;
        mm=_mm+1;
        aa=_aa+1;
    }
    else{
        dd=_dd;
        mm=_mm;
        aa=_aa;
    }

}

string Fecha::nombreMes()
{
    switch (mm)
    {
        case 0: return "Ene";break;
        case 1: return "Ene";break;
        case 2: return "Feb";break;
        case 3: return "Mar";break;
        case 4: return "Abr";break;
        case 5: return "May";break;
        case 6: return "Jun";break;
        case 7: return "Jul";break;
        case 8: return "Ago";break;
        case 9: return "Sep";break;
        case 10: return "Oct";break;
        case 11: return "Nov";break;
        case 12: return "Dic";break;
    }
}
void Fecha::setFecha(int _dd,int _mm, int _aa)
{
    if(_mm==1 || _mm==3  || _mm==5 || _mm==7 || _mm==8 || _mm==10 || _mm==12)
    {
        if(_dd>=0 || _dd <=31 || _mm>=0|| _mm<=12)
            {
                dd=_dd;
                mm=_mm;
                aa=_aa;
            }
            else
            {
                dd=31;
                mm=12;
                aa=_aa;
            }

    }
    else
        if(_mm==4  || _mm==6 || _mm==9 || _mm==11)
        {
            if(_dd>=0 || _dd <=30 || _mm>=0|| _mm<=12)
            {
                dd=_dd;
                mm=_mm;
                aa=_aa;
            }
            else
            {
                dd=30;
                mm=12;
                aa=_aa;
            }

        }
        else
            if(_mm==2)
            {
                if((_aa%4==0) || (_aa%400==0) && (_aa%100!=0))
                    {
                        if(_dd>=0 || _dd <=29 || _mm>=0|| _mm<=12)
                            {
                                dd=_dd;
                                mm=_mm;
                                aa=_aa;
                            }
                        else
                        {
                            dd=29;
                            mm=12;
                            aa=_aa;
                        }

                    }
                    else
                        if(_dd>=0 || _dd <=28 || _mm>=0|| _mm<=12)
                            {
                                dd=_dd;
                                mm=_mm;
                                aa=_aa;
                            }
                        else
                        {
                            dd=28;
                            mm=12;
                            aa=_aa;
                        }
            }
}
// if(mm==1 || mm==3  || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)= 31 dias
Fecha Fecha::operator+(int dias)
{
        for(int x=1;x<=dias;x++)
        {
            if(mm==1 || mm==3  || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
                {
                    if(mm==12 && dd==31)
                    {
                        ++aa;
                        mm=1;
                        dd=1;
                    }
                    else
                        if(dd==31)
                            {
                                ++mm;
                                dd=1;
                            }
                        else
                        {
                            ++dd;
                        }
                }
                else
                    if(mm==4  || mm==6 || mm==9 || mm==11)
                        {
                            if(dd==30)
                            {
                                ++mm;
                                dd=1;
                            }
                            else
                            {
                                ++dd;
                            }
                        }
                        else
                            if(mm==2)
                                {
                                    if((aa%4==0) || (aa%400==0) && (aa%100!=0))
                                        {
                                            if(dd==29)
                                            {
                                                ++mm;
                                                dd=1;
                                            }
                                            else
                                                ++dd;
                                        }
                                        else
                                            if(dd==28)
                                            {
                                                ++mm;
                                                dd=1;
                                            }
                                            else
                                                ++dd;
                                }

        }

    return Fecha(dd,mm,aa);

}
Fecha Fecha::operator-(int dias)
{
        for(int x=1;x<=dias;x++)
        {
            if(mm==1 || mm==2  || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)
                {
                    if(mm==1 && dd==1)
                    {
                        --aa;
                        mm=12;
                        dd=31;
                    }
                    else
                        if(dd==1)
                            {
                                --mm;
                                dd=31;
                            }
                        else
                        {
                            --dd;
                        }
                }
                else
                    if(mm==4  || mm==6 || mm==9 || mm==11)
                        {
                            if(dd==1)
                            {
                                --mm;
                                dd=30;
                            }
                            else
                            {
                                --dd;
                            }
                        }
                        else
                            if(mm==3)
                                {
                                    if((aa%4==0) || (aa%400==0) && (aa%100!=0))
                                        {
                                            if(dd==1)
                                            {
                                                --mm;
                                                dd=29;
                                            }
                                            else
                                                --dd;
                                        }
                                        else
                                            if(dd==1)
                                            {
                                                --mm;
                                                dd=28;
                                            }
                                            else
                                                --dd;
                                }

        }

    return Fecha(dd,mm,aa);

}

bool Fecha::operator>=(Fecha F1)
{
    int total1= aa*12*365 + mm*30+dd;
    int total2= F1.aa*12*365 + F1.mm*30+dd;
    if(total1>=total2)
        return true;
    else
        return false;
}
bool Fecha::operator<=(Fecha F1)
{
    int total1= aa*12*365 + mm*30+dd;
    int total2= F1.aa*12*365 + F1.mm*30+dd;
    if(total1<=total2)
        return true;
    else
        return false;
}
bool Fecha::operator>(Fecha F1)
{
    int total1= aa*12*365 + mm*30+dd;
    int total2= F1.aa*12*365 + F1.mm*30+dd;
    if(total1>total2)
        return true;
    else
        return false;
}
bool Fecha::operator<(Fecha F1)
{
    int total1= aa*12*365 + mm*30+dd;
    int total2= F1.aa*12*365 + F1.mm*30+dd;
    if(total1<total2)
        return true;
    else
        return false;
}
bool Fecha::operator==(Fecha F1)
{
    if(aa==F1.aa && mm==F1.mm && dd==F1.dd)
        return true;
    else
        return false;
}


ostream &operator << (ostream &os, Fecha _fecha)
{
    os << _fecha.dd << "/" << _fecha.nombreMes()<<"/"<<_fecha.aa<<endl;
}

istream &operator >> (istream &os, Fecha &_fecha)
{

        if(_fecha.mm==1 || _fecha.mm==3  || _fecha.mm==5 || _fecha.mm==7 || _fecha.mm==8 || _fecha.mm==10 || _fecha.mm==12){
        do{
            cout << "Día: ";
            os >> _fecha.dd;
            cout <<"\nMes: ";
            os >> _fecha.mm;
            cout <<"\nAño: ";
            os>> _fecha.aa;
        }while(_fecha.dd<=0 || _fecha.dd>31 || _fecha.mm>12);
        }
        else
            if(_fecha.mm==4  || _fecha.mm==6 || _fecha.mm==9 || _fecha.mm==11){
                do{
                    cout << "Día: ";
                    os >> _fecha.dd;
                    cout <<"\nMes: ";
                    os >> _fecha.mm;
                    cout <<"\nAño: ";
                    os>> _fecha.aa;
                }while(_fecha.dd<=0 || _fecha.dd>30 || _fecha.mm>12);
                }else
                if(_fecha.mm==2){
                    if((_fecha.aa%4==0) || (_fecha.aa%400==0) && (_fecha.aa%100!=0))
                        {
                            if(_fecha.dd==29)
                                {
                                    do{
                                        cout << "Día: ";
                                        os >> _fecha.dd;
                                        cout <<"\nMes: ";
                                        os >> _fecha.mm;
                                        cout <<"\nAño: ";
                                        os>> _fecha.aa;


                                        }while(_fecha.dd<=0 || _fecha.dd>29 || _fecha.mm>12);
                                }

                                }
                                else
                                    if(_fecha.dd==28)
                                        {
                                            do{
                                                cout << "Día: ";
                                                os >> _fecha.dd;
                                                cout <<"\nMes: ";
                                                os >> _fecha.mm;
                                                cout <<"\nAño: ";
                                                os>> _fecha.aa;
                                                }while(_fecha.dd<=0 || _fecha.dd>28 || _fecha.mm>12);
                                            }
                }
    cout << endl;
    return os;


}

