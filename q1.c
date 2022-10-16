#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5
#define Garfo_Esquerdo (i + N - 1) % N 
#define Garfo_Direito (i + N + 1) % N 
#define LIVRE 0
#define USANDO 1

int estado_garfos[N]; // Semáforo
pthread_mutex_t garfos[N];
pthread_mutex_t filo[N];
pthread_mutex_t mutex;
int segundos_dormindo = 0

void *filosofo(void *num) {
    int * id = (int*) (num)

    while(1){
        pensar(*(id));
        pegar_garfo(*(id));
        comer(*(id));
        devolver_garfo(*(id));
    }
    
    pthread_exit((void*) 0);
}

void pegar_garfo(int id_filo){
    int aux = id_filo + 1;

    printf("Filosofo %d esta com fome\n", id_filo);

    pthread_mutex_lock(&(mutex));

    if ((aux) % 2 == 0){
        printf("Filosofo %d pega o garfo esquerdo", id_filo);

        if(estado_garfos[id_filo] == LIVRE)
            estado_garfos[id_filo] = USANDO;

        if(estado_garfos[aux] == LIVRE)
            estado_garfos[aux] = USANDO;

    }else{
        if ((aux) % 2 == 1){
            printf("Filosofo %d pega o garfo esquerdo", id_filo);

            if(estado_garfos[aux] == LIVRE)
                estado_garfos[aux] = USANDO;
            
            if(estado_garfos[id_filo] == LIVRE)
                estado_garfos[id_filo] = USANDO;
            
        }
    }
    pthread_mutex_unlock(&(mutex));
    phtread_mutex_lock(&(mux_filo(id_filo)));
}