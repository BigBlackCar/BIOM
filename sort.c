#include "header.h"

void ordenar_pessoas(pessoa_tipo pt[], int *qtd2) //procedimento para ordenar as pessoas pelo sexo pedido pelo utilizador
{
    int i;//variavel numerica
    char gen[2];//variavel pedida ao utilizador para comparar com o sexo das pessoas no sistema
    char pool[100];
    i=0;

	printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
	scanf(" %s", gen);
	if (gen[0] == 'm' || gen[0] == 'f')
	{
	    while (i < *qtd2)
	    {
	
	    	if (gen[0] == pt[i].sexo[0])
		{
		    if (gen[0] == 'm')
			calc_imc_male(pt[i],pool);
		    else
			calc_imc_female(pt[i],pool);
		    printf("\nNome:%s",pt[i].nome);
		    printf("\nEstilo de vida:%s",pt[i].est);
		    printf("\nIMC=%.2f",pt[i].imc);
		    printf("\n%s",pool);
		    printf("\n");
		}
		    i++;
	    }
	}
	else
		printf("Invalid gender!");
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

