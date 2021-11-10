#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO1 "incidentes"


using namespace std;

struct incidente
{
    int codinc;
    int fechahora;
    char DNI[10];
    char DNIoc[10];
    int polizainc;
    char calle[20];
    int altura;
};



bool guardarregistro(void)
{
    FILE *f;
    incidente p;
    if (f=fopen(NOMBREARCHIVO1,"a+"))
    {
        cout << "Ingrese el codigo de incidente:" << endl;
        cin >> p.codinc;
         cout << "Ingrese la fecha y la hora: " << endl;
        cin >> p.fechahora;
         cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.DNI;
         cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.DNIoc;
        cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.polizainc;
         cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.calle;
         cout << "Ingrese el numero de poliza: " << endl;
        cin >> p.altura;
        fwrite(&p, sizeof(incidente),1,f);
        fclose(f);
        return true;
    }
    return false;
}




int mostrartodo(void)
{
    FILE *f;
    incidente p;
    if (f=fopen(NOMBREARCHIVO1,"rb"))
    {
        fread(&p,sizeof(incidente),1,f);
        while(!feof(f))
        {
            cout << "****** Datos de la persona *******" << endl;
            cout << "Codigo de incidente: " << p.codinc << endl;
            cout << "Numero de poliza " << p.polizainc << endl;
            fread(&p,sizeof(struct incidente),1,f);
            cout<<endl<<endl;
        }
        fclose(f);
        return 1;
    }
    return 0;
}

int main()
{

FILE *f;
       int num;
       incidente p;

       f=fopen(NOMBREARCHIVO1,"wb");
       cout<<"ingrese un numero"<<endl;
       cin>>num;

       while(num!=0)
       {
       guardarregistro();
       cout<<"ingrese un numero"<<endl;
       cin>>num;

       }
      mostrartodo();
      fclose(f);



  return 0;
}

