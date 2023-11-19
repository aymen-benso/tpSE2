#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void wait_handler(int signum) {
    kill(getpid(), SIGKILL);
}

int main() {
    pid_t pid;

    /* Appel à la fonction fork() */
    pid = fork();

    if (pid > 0) { 
        for (int i = 1; i <= 100; i++) {
            if (!(i % 2 == 0)) {
                printf("%d\n", i);
                wait_handler;
            }
        }
        /* Code exécuté par le processus enfant */
    } else if (pid == 0) { 
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                printf("%d\n", i);
                pause();
            }
        }
    } else {
        printf("Erreur lors de la création du processus\n");
    }

    return 0;
}