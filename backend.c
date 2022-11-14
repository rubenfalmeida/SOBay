#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "utils.h"

int main()
{   
    FILE *FUSERS;

    FUSERS = fopen("utilizadores.txt", "r+");

    if(FUSERS == NULL){
        printf("erro de abertura utilizadores"); // debug caso o ficheiro não funcione

        exit(1);
    }
     FILE *FPROMOTORS;

    FUSERS = fopen("promotors.txt", "r+");

    if(FUSERS == NULL){
        printf("erro de abertura promotores"); // debug caso o ficheiro não funcione

        exit(1);
    }
     FILE *FITEMS;

    FUSERS = fopen("items.txt", "r+");

    if(FUSERS == NULL){
        printf("erro de abertura items"); // debug caso o ficheiro não funcione

        exit(1);
    }

    char comando[6][256];
    char *comandosconhecidos[] = {"users", "list", "kick", "prom", "reprom", "cancel", "close"};
    char *funcionalidades[] = {"comandos", "execucaopromotor", "utilizadores", "itens"};
    char teste[256];

    while (1)
    {
        printf("deseja testar que funcionalidade: ");
        scanf("%s", teste);

        for (int i = 0; i < 11; i++)
        {
            if (strcmp(teste, funcionalidades[i]) == 0)
            {
                if (strlen(teste) == 8)
                {
                    printf("Introduza o comando: ");
                    scanf("%s", comando);
                    for (int i = 0; i < 10; i++)
                    {
                        if (strcmp(comando[0], comandosconhecidos[i]) == 0)
                        {

                            printf("Comando validado!\n");
                            exit(1);
                        }
                        else if (strcmp(comando[0], "exit") == 0)
                        {
                            printf("Ate a proxima!\n");
                            exit(1);
                        }
                    }
                }
            }

            if (strcmp(teste, funcionalidades[i]) == 0)
            {
                if (strlen(teste) == 8)
                {
                    printf("Introduza o comando: ");
                    scanf("%s", comando);
                    for (int i = 0; i < 10; i++)
                    {
                        if (strcmp(comando[0], comandosconhecidos[i]) == 0)
                        {

                            printf("Comando validado!\n");
                            exit(1);
                        }
                        else if (strcmp(comando[0], "exit") == 0)
                        {
                            printf("Ate a proxima!\n");
                            exit(1);
                        }
                    }
                }

                if (strlen(teste) == 16)
                {
                    printf(" A executar o promotor! ");
                    scanf("%s", comando);

                }

                 if (strlen(teste) == 12)
                {
                    printf(" Os utilizadores ");
                    scanf("%s", comando);

                }
                 if (strlen(teste) == 5)
                {
                    printf(" ITENS");
                    scanf("%s", comando);

                }

            }
            
        }

        printf("Comando invalido!\n");
    }
}