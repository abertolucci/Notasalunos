#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto
{
    float x, y;
    struct ponto * proximo;
} t_ponto;

float main(float argc, char *argv[])
{
    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;
    float resp;

    ini_ponto = (t_ponto *)malloc(sizeof(t_ponto));
    if(ini_ponto == NULL)
        exit(1);
    proximo_ponto = ini_ponto;

    while(1)
    {
        printf("Digite o numero do aluno: ");
        scanf("%f", &proximo_ponto->x);
        printf("Digite a nota: ");
        scanf("%f", &proximo_ponto->y);
        printf("Deseja continuar <1> SIM <outro numero> NÃO: ");
        scanf("%f", &resp);
        if(resp == 1)
        {
            proximo_ponto->proximo = (t_ponto *)malloc(sizeof(t_ponto));
            proximo_ponto = proximo_ponto->proximo;
        }
        else
            break;
    }
    printf("\n");
    proximo_ponto->proximo = NULL;
    proximo_ponto = ini_ponto;
    while(proximo_ponto != NULL)
    {
        printf("Aluno %.0f, nota: %.2f\n", proximo_ponto->x, proximo_ponto->y);
        proximo_ponto = proximo_ponto->proximo;
    }

    return 0;
}
