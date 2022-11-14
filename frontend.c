#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[])
{
    char comando[6][256]; //Array para ler os comandos (máximo de palavras = 6, tamanho maximo cada palavra = 256)
    char *comandosconhecidos[] = {"sell","list","licat","lisel","lival",
    "litime","time","buy","cash","add"}; //Array para os tipos de comandos válidos para os utilizadores
    
    if(argc < 3 || argc > 3){
        printf("Dados inválidos!\n");
        exit(1);
    }
    printf("Bem-vindo Sr. %s!\n",argv[1]);
    do{
        printf("Introduza o comando: ");
        scanf("%s",comando);
        for(int i = 0; i < 10; i++){
                if(strcmp(comando[0],comandosconhecidos[i]) == 0){
                    printf("Comando validado!\n");
                    break;
                }if(strcmp(comando[0],comandosconhecidos[i]) != 0){
                   
                    if(strcmp(comando[0],"exit") == 0){
                    printf("Ate a proxima!\n");
                    break;
                }
                printf("Comando invalido!\n");
                    break;
                    
                }
               
        }

    }while (strcmp(comando[0],"exit") != 0);
    
    
    

    return 0;
} 