#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaforo;

void* pedirPerdon(void *arg) {
    char *persona = arg;
    printf("%s: Estoy pidiendo perdón...\n", persona);
    sleep(1);  // Simulación de tiempo de reflexión
    printf("%s: Perdooon\n", persona);
    
    // Señalizar que se ha pedido perdón
    sem_post(&semaforo);
    
    return NULL;
}

void* aceptarError(void *arg) {
    char *persona = arg;
    printf("%s: Estoy esperando que se pida perdón...\n", persona);
    
    // Esperar a que se pida perdón
    sem_wait(&semaforo);
    
    printf("%s: Acepto mi error\n", persona);
    
    return NULL;
}

int main() {
    pthread_t hombre, mujer;

    // Inicializar el semáforo
    sem_init(&semaforo, 0, 0);

    srand(time(NULL));

    printf("@!#?@!\n");
    sleep(1);
    printf("-------------------\n");
    printf("Discusión acabada\n");

    // Crear hilos dependiendo del azar
    if (rand() % 2) {
        pthread_create(&hombre, NULL, pedirPerdon, "👨");
        pthread_create(&mujer, NULL, aceptarError, "👩");
    } else {
        pthread_create(&mujer, NULL, pedirPerdon, "👩");
        pthread_create(&hombre, NULL, aceptarError, "👨");
    }

    pthread_join(hombre, NULL);
    pthread_join(mujer, NULL);

    // Destruir el semáforo
    sem_destroy(&semaforo);
    return 0;
}
