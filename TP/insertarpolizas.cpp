#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO1 "polizas"
#define NOMBREARCHIVO2 "incidentes"

using namespace std;

struct persona
{
    int nropoliza;
    char DNI[10];
    char nombre[20];
    char apellido[20];
    bool cuota = true;
    char patente[10];
    bool activa = true;
    int incidentes = 0;

};


bool guardarregistro(void)
{
    FILE *f;
    persona p;
    int num;
    if (f=fopen(NOMBREARCHIVO1,"wb"))
    {

       cout<<"ingrese un numero"<<endl;
       cin>>num;
        while(num!=0)
       {
        cout << "Ingrese el numero de poliza:" << endl;
        cin >> p.nropoliza;
        cout << "Ingrese DNI:" << endl;
        cin >>  p.DNI;
        cout << "Ingrese nombre:" << endl;
        cin >> p.nombre;
        cout << "Ingrese apellido:" << endl;
        cin >> p.apellido;
        cout << "Ingrese si la cuota esta al dia(1/0):" << endl;
        cin >> p.cuota;
        cout << "Ingrese si la poliza esta activa(1/0):" << endl;
        cin >> p.activa;
        cout << "Ingrese patente:" << endl;
        cin >> p.patente;

        fwrite(&p, sizeof(persona),1,f);
        cout<<"ingrese un numero"<<endl;
        cin>>num;
       }

        fclose(f);
        return true;

    }
    return false;
}




int mostrartodo(void)
{
    FILE *f;
    persona p;
    if (f=fopen(NOMBREARCHIVO1,"rb"))
    {
        fread(&p,sizeof(persona),1,f);
        while(!feof(f))
        {
            cout << "****** Datos de la persona *******" << endl;
            cout << "Numero de poliza: " << p.nropoliza << endl;
            cout << "DNI " << p.DNI << endl;
            cout << "Nombre: " << p.nombre << endl;
            cout << "Apellido: " << p.apellido << endl;
            cout << "Cuota al dia: " << p.cuota << endl;
            cout << "Patente: " << p.patente << endl;
            cout << "Activa: " << p.activa << endl;
            cout << "Numero de incidentes: " << p.incidentes << endl;
            fread(&p,sizeof(struct persona),1,f);
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
       persona p;

       f=fopen(NOMBREARCHIVO1,"wb");

      guardarregistro();
      mostrartodo();

      fclose(f);



  return 0;
}

