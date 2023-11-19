#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int r;

void gestion_alarme() {
    printf("Fin d'alarme !\n");
    exit(0);
}

void three_numbers(){
    printf("somme de %d %d %d \n", rand()%30, rand()%30, rand()%30);
    alarm(5);
    printf("Entrez la somme : ");
    scanf("%d", &r);
    if (r != 0){
        printf("Bravo !\n");
    }

}

int main() {
    
    printf("Debut du programme\n");
    signal(SIGALRM, gestion_alarme);
    while (1){
         /*2*/
         three_numbers();
         
    }
    return 0;
}

