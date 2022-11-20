#include "header.h"

void ordenar_pessoas(pessoa_tipo pt[], int *qtd2) //procedimento para ordenar as pessoas pelo sexo pedido pelo utilizador
{
    int i;//variavel numerica
    char genero[1];//variavel pedida ao utilizador para comparar com o sexo das pessoas no sistema

    i=0;

    do
    {
        printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
        scanf("%c", &genero[0]);

        if( strcmp( pt[i].sexo, genero )==0 )//se o sexo das pessoas for igual ao pedido pelo utilizador irá aparecer as informaçoes todas da pessoa
        {

            printf("\nNome:%s",pt[i].nome);
            printf("\nIdade:%d",pt[i].idade);
            printf("\nAltura:%dcm",pt[i].altura);
            printf("\nEstilo de vida:%s",pt[i].est);
            printf("\nPeso:%dkg",pt[i].peso);
            printf("\nIMC=%.2f",pt[i].imc);
            printf("\n");

            i++;

        }
        while( i<*qtd2 );


    }
    while(genero[0] != 'm' && genero[0] != 'f');


}

void sort_structs_by_kcal(alimento_tipo *al, int *len) //ordena as structs por ordem decrescente das kcal dos alimentos (TD)
{
    int         i, changed;
    alimento_tipo    temp;
    do
    {
        changed = 0;
        for (i=0; i < (*len) - 1; i++)
        {
            if ((al[i].kcal - al[i+1].kcal) < 0)
            {
                memcpy(&temp, al + i, sizeof (alimento_tipo));
                memcpy(al + i, al + i + 1, sizeof (alimento_tipo));
                memcpy(al + i + 1, &temp, sizeof (alimento_tipo));
                changed = 1;
            }
        }
    }
    while (changed != 0);
}

void sort_structs(alimento_tipo *al, int *len) //Organiza as structs por ordem alfabética (Credito a Scheneizer)
{
    int 		i, changed;
    alimento_tipo	temp;
    do
    {
        changed = 0;
        for (i=0; i < (*len) - 1; i++)
        {
            if (strcmp(al[i].nome, al[i+1].nome) > 0)
            {
                memcpy(&temp, al + i, sizeof (alimento_tipo));
                memcpy(al + i, al + i + 1, sizeof (alimento_tipo));
                memcpy(al + i + 1, &temp, sizeof (alimento_tipo));
                changed = 1;
            }
        }
    }
    while (changed != 0);
}

void sort_structs_pessoas(pessoa_tipo *pt, int len)//ordena os nomes por ordem alfabetica
{
    int         w, changed;
    pessoa_tipo    temp;
    do
    {
        changed = 0;
        for (w=0; w < (len) - 1; w++)
        {
            if (strcmp(pt[w].nome, pt[w+1].nome) > 0)
            {
                memcpy(&temp, pt + w, sizeof (pessoa_tipo));
                memcpy(pt + w, pt + w + 1, sizeof (pessoa_tipo));
                memcpy(pt + w + 1, &temp, sizeof (pessoa_tipo));
                changed = 1;
            }
        }
    }
    while (changed != 0);
}

