#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

char *comandosconhecidos[] = {"sell","list","licat","lisel","lival",
    "litime","time","buy","cash","add"}; //Array para os tipos de comandos válidos para os utilizadores


void ComparaComando(char *comando)
{
    char palavras[6][20]; //Array onde serão guardadas as palavras dos comandos
    int n = 0; //numero de palavras em cada comando
    int flag = 0; //Flag auxiliar na validação do comando (se a flag sair do ciclo = 0, comando é inválido)
    
    for(comando = strtok(comando," ");comando != NULL;comando = strtok(NULL," "))
    {
        if(n >= 6)
        {
            printf("Limite de palavaras atingido!\n");
            return;
        }
        strcpy(palavras[n], comando);

        n++;
    }

    for(int i = 0; i < 10; i++)
    {
        if(strcmp(palavras[0], comandosconhecidos[i]) == 0)
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

int main(int argc, char *argv[])
{
    
    
    char comando[100]; //String do comando
    
    if(argc < 3 || argc > 3){
        printf("Dados inválidos!\n");
        exit(1);
    }
    printf("Bem-vindo %s!\n",argv[1]);
    while(1)
    {
        printf("Introduza o comando: ");
        fgets(comando,100,stdin);
        comando[strlen(comando) - 1] = '\0';
        if(strcmp(comando,"exit") == 0)
        {
            printf("Ate breve!\n");
            exit(1);
        }

        ComparaComando(comando);
        
    }

    
    

    return 0;
}
