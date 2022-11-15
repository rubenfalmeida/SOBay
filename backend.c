#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "utils.h"

char *comandosconhecidos[] = {"users", "list", "kick", "prom"
, "reprom", "cancel", "close"}; //Array para os tipos de comandos válidos para o administrador

void ComparaComandos(char *comando)
{
    char palavras[2][20]; //Array onde serão guardadas as palavras dos comandos
    int n = 0, //numero de palavras em cada comando
    flag = 0; //Flag auxiliar na validação do comando (se a flag sair do ciclo = 0, comando é inválido)

    for(comando = strtok(comando," ");comando != NULL;comando = strtok(NULL," "))
    {
        strcpy(palavras[n],comando);
        n++;
    }

    for(int i = 0; i < 7; i++)
    {
        if(strcmp(palavras[0],comandosconhecidos[i]) == 0)
        {
            printf("Comando Validado!\n");
            flag = 1;
            break;
        }
    }

    if(flag == 0)
    {
        printf("Comando Invalido!\n");
    }
}

void IntroduzirComando()
{
    char comando[100];
    while(1)
    {
        printf("Introduza o comando: ");
        fgets(comando,100,stdin);
        comando[strlen(comando) - 1] = '\0';
        if(strcmp(comando,"close") == 0)
        {
            printf("Ate breve!\n");
            exit(1);
        }

        ComparaComandos(comando);
    }
}

int main()
{   
    FILE *FUSERS;

    FUSERS = fopen("utilizadores.txt", "r+");

    if(FUSERS == NULL){
        printf("erro de abertura utilizadores"); // debug caso o ficheiro não funcione

        exit(1);
    }
     FILE *FPROMOTORS;

    FUSERS = fopen("promotors.txt", "r+"); //Ruben: Aqui não será FPROMOTORS em vez de FUSERS?

    if(FUSERS == NULL){
        printf("erro de abertura promotores"); // debug caso o ficheiro não funcione

        exit(1);
    }
     FILE *FITEMS;

    FUSERS = fopen("items.txt", "r+"); //Ruben: Aqui não será FITEMS em vez de FUSERS?

    if(FUSERS == NULL){
        printf("erro de abertura items"); // debug caso o ficheiro não funcione

        exit(1);
    }

    int escolha;
    char confirm;

    printf("Escolha a opcao:\n1 - Comando\n2 - Executar Promotor\n3 - Utilizadores\n4 - Itens\n");
    scanf("%d",&escolha);
    switch (escolha)
    {
        case 1:
            printf("Tem a certeza (s/n)?: ");
            scanf(" %c",&confirm);
            if(confirm == 's')
            {
                IntroduzirComando();
            }
            else if(confirm == 'n')
            {
                break;
            }
            else
            {
                printf("Escolha Invalida! (sintaxe: s/n)\n");
                break;
            }
        case 2:
        case 3:
        case 4:
        default:
            break;
    }
}
