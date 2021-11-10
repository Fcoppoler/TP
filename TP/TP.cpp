#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#define NOMBREARCHIVO "polizas"
#define NOMBREARCHIVO2 "incidentes"
#define NOMBREARCHIVO3 "asegurados.BAK"
#define NOMBREARCHIVO4 "actualizacionprueba"


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

struct Nodo
{
    persona info;
    Nodo *sgte;
};

bool guardarregistro(void) /////Agregar una poliza
{
    FILE *f;
    persona p;
    if (f=fopen(NOMBREARCHIVO,"ab"))
    {
        cout << "Ingrese el numero de poliza:" << endl;
        cin >> p.nropoliza;
        cout << "Ingrese DNI:" << endl;
        cin >>  p.DNI;
        cout << "Ingrese nombre:" << endl;
        cin >> p.nombre;
        cout << "Ingrese apellido:" << endl;
        cin >> p.apellido;
        cout << "Ingrese patente:" << endl;
        cin >> p.patente;

        fwrite(&p, sizeof(persona),1,f);
        fclose(f);
        return true;
    }
    return false;
}


void mostrar(Nodo *&lista) ///// mostrar polizas en lista
{
    Nodo *aux;
    aux = lista;
    while (aux->sgte)
    {
      if(aux->info.activa == true)
      {
        cout << "================" << endl;
                cout << "Numero de poliza: " << aux->info.nropoliza << endl;
                cout << "DNI " << aux->info.DNI << endl;
                cout << "Nombre: " << aux->info.nombre << endl;
                cout << "Apellido: " << aux->info.apellido << endl;
                cout << "Cuota al dia: " << aux->info.cuota << endl;
                cout << "Patente: " << aux->info.patente << endl;
                cout << "Activa: " << aux->info.activa << endl;
                cout << "Numero de incidentes: " << aux->info.incidentes << endl;
                cout<<endl<<endl;

        }
     aux = aux->sgte;
    }

    if(aux->info.activa == true)
    {

  cout << "================" << endl;
                cout << "Numero de poliza: " << aux->info.nropoliza << endl;
                cout << "DNI " << aux->info.DNI << endl;
                cout << "Nombre: " << aux->info.nombre << endl;
                cout << "Apellido: " << aux->info.apellido << endl;
                cout << "Cuota al dia: " << aux->info.cuota << endl;
                cout << "Patente: " << aux->info.patente << endl;
                cout << "Activa: " << aux->info.activa << endl;
                cout << "Numero de incidentes: " << aux->info.incidentes << endl;
                cout<<endl<<endl;

     }

return;
}

/*int mostrartodo(void) //////mostrar archivo de polizas
{
    FILE *f;
    persona p;

    if (f=fopen(NOMBREARCHIVO,"rb"))
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
*/
int buscar(char DNI[]) ///// buscar DNI
{
    FILE *f;
    int encontrado =0;
    struct persona p;
    if (f=fopen(NOMBREARCHIVO,"rb"))
    {
        while(fread(&p,sizeof(struct persona),1,f) && !encontrado)
        {
            if (strcmp(DNI, p.DNI)==0)
            {
                encontrado = 1;
                cout << "****** Datos de la persona *******" << endl;
                cout << "Numero de poliza: " << p.nropoliza << endl;
                cout << "DNI " << p.DNI << endl;
                cout << "Nombre: " << p.nombre << endl;
                cout << "Apellido: " << p.apellido << endl;
                cout << "Cuota al dia: " << p.cuota << endl;
                cout << "Patente: " << p.patente << endl;
                cout << "Activa: " << p.activa << endl;
                cout << "Numero de incidentes: " << p.incidentes << endl;
            }
        }
        if (!encontrado)
            printf("No se encontro la persona buscada.\n");
        fclose(f);
        return 1;
    }
    return 0;
}

int borrar (int nropoliza, Nodo *inicio) ///// desactivar una poliza
{
        Nodo *aux = inicio;
        while (aux->sgte)
          {
         if(aux->info.nropoliza == nropoliza)
            {
         aux->info.activa = false;
         cout<<aux->info.nropoliza<<"="<< nropoliza<<endl;
         cout<<"se encontro un parecido"<<endl;
            }
          cout<<aux->info.nropoliza<<"="<< nropoliza<<endl;
          aux = aux->sgte;
          }
}

void insertarOrdenado(Nodo *&lista, persona ainsertar)//// insertar ordenado
{
    Nodo *paux = lista;
    Nodo *anterior =NULL;
    while (paux && paux->info.incidentes < ainsertar.incidentes)
    {
        anterior = paux;
        paux = paux->sgte;
    }
    if ( paux!= lista)
    {
        anterior->sgte = new Nodo();
        anterior->sgte->info = ainsertar;
        anterior->sgte->sgte = paux;

    }
    else
    {
        lista= new Nodo();
        lista->sgte = paux;
        lista->info = ainsertar;
    }

    return;
}

void cargarincidentes()///// Cargar los incidentes a asegurados.BAK
{
    FILE *f;
    FILE *i;
      incidente p;
      if (f=fopen(NOMBREARCHIVO2,"rb"))
        {
          if(i = fopen(NOMBREARCHIVO3,"ab+"))
        {
        while(!feof(f))
          {
        fread(&p,sizeof(incidente),1,f);
        cout<<"codigo incidente: "<<p.codinc<<endl;
        cout << "poliza: "<<p.polizainc<< endl;
        fwrite(&p,sizeof(incidente),1,i);
          }
        }
        fclose(i);
         }
        fclose(f);
}


void finalizarjornada(Nodo *&inicio)///// Finalizar jornada
{
      FILE *f;
      persona p;
      if (f=fopen(NOMBREARCHIVO,"wb"))
           {
        Nodo *aux;
        aux = inicio;
     while (aux->sgte)
      {
        if(aux->info.activa == true)

        {
           p = aux->info;
           fwrite(&p,sizeof(persona),1,f);
           aux = aux->sgte;

        }
      }
           }
        fclose(f);

}

void mostrarHTML(Nodo *&lista) ///// mostrar sin cuota al dia HTML
{
    FILE *f;
    f=fopen("salidahtml.html","wt");
    Nodo *aux;
    aux = lista;
    fprintf(f,"<html><body>\n");
    fprintf(f,"<h1> Polizas sin cuota al dia </h1>\n");
    fprintf(f,"<table border=1>\n");
    fprintf(f,"<th>DNI</th><th>Nombre</th><th>Apellido</th><th>Patente</th><th>Numero de incidentes</th>\n");
    cout<<"Tabla cargada correctamente"<<endl;
    cout<<endl<<endl;
    while (aux->sgte)
    {
      if(aux->info.cuota == false)
      {
          fprintf(f,"<tr><\n");
          fprintf(f,"<td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%i</td><\n", aux->info.DNI, aux->info.nombre, aux->info.apellido, aux->info.patente, aux->info.incidentes);
          fprintf(f,"</tr><\n");
        }
    aux = aux->sgte;
    }
    fclose(f);
}

void mostrarCSV(Nodo *&lista) ///// mostrar sin cuota al dia CSV
{
    FILE *f;
    f=fopen("salidaCSV.csv","wt");
    Nodo *aux;
    aux = lista;
    fprintf(f,"DNI;Nombre;Apellido;Patente;Numero de incidentes\n");
    cout<<"Tabla cargada correctamente"<<endl;
    cout<<endl<<endl;

    while (aux->sgte)
    {
      if(aux->info.cuota == false)
      {
          fprintf(f,"%s;%s;%s;%s;%i\n", aux->info.DNI, aux->info.nombre, aux->info.apellido, aux->info.patente, aux->info.incidentes);
        }
    aux = aux->sgte;
    }
    fclose(f);
}

char menu(Nodo *&inicio) ///// Mostrar menu
{
    char opcion;
    cout << "Seleccione una opcion:" << endl;
    cout << "1 - Ingresar un nuevo registro" << endl;
    cout << "2 - Mostrar cuotas que no estan al dia en formato CSV"<< endl;
    cout << "3 - Buscar un registro por DNI"<< endl;
    cout << "4 - Dar de baja poliza por DNI"<< endl;
    cout << "5 - Cargar lote de incidentes"<< endl;
    cout << "6 - Ordenar y mostrar lista"<< endl;
    cout << "7 - Cargar incidentes a asegurados.BAK"<< endl;
    cout << "8 - Finalizar jornada"<< endl;
    cout << "9 - Mostrar cuotas que no estan al dia en formato HTML"<< endl;

    cout << "Esc - Salir" << endl;
    cout<<endl<<endl;
    do
        opcion = getch();
    while (!(opcion > '0' && opcion < '10') && (opcion != 27));
    char dnibuscado[10];
    int nropoliza;
    switch (opcion)
    {
        case '1':
        {
        persona n;
        cout << "Ingrese el numero de poliza:" << endl;
        cin >> n.nropoliza;
        cout << "Ingrese DNI:" << endl;
        cin >>  n.DNI;
        cout << "Ingrese nombre:" << endl;
        cin >> n.nombre;
        cout << "Ingrese si la poliza esta activa(1/0):" << endl;
        cin >> n.activa;
        cout << "Ingrese apellido:" << endl;
        cin >> n.apellido;
        cout << "Ingrese patente:" << endl;
        cin >> n.patente;
        insertarOrdenado(inicio, n);
        break;
        }


        case '2':
            {
            mostrarCSV(inicio);
            /*
            if (!mostrartodo())
                printf("Error al intentar abrir el archivo.\n");
        */
        break;
            }

        case '3':
            {

            printf("Ingrese el DNI de la persona buscada\n");
            scanf("%s", dnibuscado);
            if (!buscar(dnibuscado))
                printf("Error al intentar abrir el archivo.\n");
        break;
            }

        case '4':
            {
            cout << "Ingrese la poliza a dar de baja" << endl;
            cin >> nropoliza;
            borrar(nropoliza, inicio);
        break;

            }

  case '5':
      {
      FILE *f;
      incidente p;
      if (f=fopen(NOMBREARCHIVO2,"rb"))
        {

        while(!feof(f))
          {
        fread(&p,sizeof(incidente),1,f);
        cout<<"codigo incidente: "<<p.codinc<<endl;
        cout << "poliza: "<<p.polizainc<< endl;

        Nodo *aux = inicio;
        while (aux->sgte)
          {
          cout<<"el numero es: "<<aux->info.nropoliza<<endl;
         if(p.polizainc == aux->info.nropoliza)
          {
         cout<<"se encontro un parecido"<<endl;
         aux->info.incidentes += 1;
          }
          aux = aux->sgte;
          }
         }
        fclose(f);
      break;
         }
       }

case '6':
    {
        mostrar(inicio);
    break;
    }

case '7':
    {
        cargarincidentes();

    break;
    }

case '8':
    {
         finalizarjornada(inicio);
         cout<<"La jornada finalizo con exito"<<endl;
    break;
    }

    case '9':
    {
         mostrarHTML(inicio);
    break;
    }

           }
    return opcion;
 }

int main()
{

FILE *f;
       persona p;
       if (f=fopen(NOMBREARCHIVO,"rb"))
       {
        fread(&p,sizeof(persona),1,f);
        Nodo *inicio = NULL;
        inicio= new Nodo();
        inicio->info=p;
        inicio->sgte =NULL;

       while(!feof(f))
        {
        fread(&p,sizeof(persona),1,f);
        insertarOrdenado(inicio, p);
        }
        fclose(f);



char out;
    do
        out = menu(inicio);
    while (out != 27);
  return 0;
     }
}

