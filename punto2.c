#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea {

        int TareaID; //Numerado en ciclo iterativo
        char *Descripcion; //
        int Duracion; // entre 10 – 100

}typedef Tarea;

void solicitaCantidadTareas(int * cantidad); 
Tarea ** cargarTareas(int cantidadTareas);
Tarea ** cargaTareasRealizadas(Tarea ** tareasPendientes, int cantidadTareas);
Tarea * solicitarTareaPorID(Tarea ** tareas ,int cantidadTareas, int id);

int main()
{
    srand(time(NULL));  
    int cantidadTareas;
    solicitaCantidadTareas(&cantidadTareas);
    
    Tarea ** arregloTareas  = cargarTareas (cantidadTareas);
    Tarea ** tareasRealizadas = cargaTareasRealizadas(arregloTareas,cantidadTareas);  

    return 0;
}

void solicitaCantidadTareas(int * cantidad)
{
    puts("Ingrese la cantidad de tareas a cargar : ");
    int cant ;
    scanf("%d",&cant);
    *cantidad = cant; 
}

Tarea ** cargarTareas(int cantidadTareas)
{
    Tarea ** arregloTareas = (Tarea **) malloc(sizeof (Tarea *) * cantidadTareas );
    char * Buff = (char *) malloc(sizeof(char)*50);
    
    for (int i = 0; i < cantidadTareas; i++)
    {
        arregloTareas[i] = (Tarea*) malloc (sizeof(Tarea));
        
        printf("\n Ingrese descripcion de la tarea [%d] \n ",i+1);
        gets(Buff);
        fflush(stdin);
        arregloTareas[i]->Descripcion = (char *)malloc((strlen(Buff)+1));
        strcpy(arregloTareas[i]->Descripcion,Buff);
        free(Buff);
        arregloTareas[i]->Descripcion = "estoy probando por ahora";
        arregloTareas[i]->Duracion = rand() % 90 + 10 ;
        arregloTareas[i]->TareaID = i+1;                
    }

    return arregloTareas;
}

Tarea ** cargaTareasRealizadas(Tarea ** tareasPendientes, int cantidadTareas)
{
    Tarea ** tareasRealizadas = (Tarea **) malloc(sizeof (Tarea *) * cantidadTareas );
    int realizada;
    printf("------------------Tareas Pendiente--------------\n");

    for (int i = 0; i < cantidadTareas; i++)
    {   
        printf("¿ La tarea -Numero [%d]- esta realizada ? \n", i+1); 
        printf("\n %d \n",tareasPendientes[i]->TareaID);
        printf("\n%s\n",tareasPendientes[i]->Descripcion);
        printf("\n%d\n",tareasPendientes[i]->Duracion);
        printf("\n 1:si ,0: no \n");

        scanf("%d",&realizada);

        if (realizada == 1)
        {
            tareasRealizadas[i] = tareasPendientes[i];
            tareasPendientes[i] = NULL;

        }else
        {
            tareasRealizadas[i] = NULL;
        }

    }
    
        return tareasRealizadas;
}

Tarea * solicitarTareaPorID(Tarea ** tareas ,int cantidadTareas, int id)
{
     for (int i = 0; i < cantidadTareas; i++)
     {
        if (tareas[i]->TareaID == id)
        {
            return tareas[i];
        }   
     }

     return NULL;    
}