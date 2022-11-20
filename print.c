#include "header.h"

void	mostrar_alimentos(alimento_tipo *al, int qtd)  //mostra todos os alimentos e os respetivos atributos (TD)
{
    for(int i = 0; i < qtd; i++)
    {
        printf("\nAlimento %d", i);
        printf("\nNome=%s", al[i].nome);
        printf("\nGrupo=%d", al[i].grupo);
        printf("\nUnidade=%d", al[i].unidade);
        printf("\nPeso=%d", al[i].peso);
        printf("\nKcal=%d", al[i].kcal);
        printf("\n");
    }
    system("Pause");
}

void mostrar_pessoas(pessoa_tipo *pt, int qtd2)//procedimento para mostrar todas as pessoas ja inseridas no sistema
{
    int i;
    for(i=0; i < qtd2; i++)
    {

        printf("\nNome:%s", pt[i].nome);
        printf("\nIdade:%d", pt[i].idade);
        printf("\nAltura:%dcm", pt[i].altura);
        printf("\nSexo:%s", pt[i].sexo);
        printf("\nEstilo de vida:%s", pt[i].est);
        printf("\nPeso:%dkg", pt[i].peso);
        printf("\nIMC=%.2f", pt[i].imc);
        printf("\n");
    }

    system("Pause");
}

int listar_grupo(void) //escolher o numero do grupo que sera listado (TD)
{
    int escolha;
    printf("Qual o grupo que pretende listar?\n\n1 - ceriais derivados e tuberculos\n2 - gorduras e oleos\n3 - fruta\n4 - laticinios\n5 - carnes pescados e ovos\n6 - leguminosas\n7 - horticulas");
    printf("\n\nSelecionar opcao: ");
    scanf("%d",&escolha);
    return (escolha);
}

void mostrar_tabela(alimento_tipo *al, int *qtd, int escolha)  //mostra a tabela com os alimentos do grupo escolhido e kcal por ordem decrescente (TD)
{
    printf("_________________________________\n");
    printf("|Grupo %d                        |\n",escolha);
    printf("_________________________________\n");
    printf("|Alimento               |Kcal   |\n");
    printf("_________________________________\n");
    for(int i = 0; i < *qtd; i++)
    {
        if ((al[i].grupo) == (escolha))
        {
            printf("|%-23s|%-7d|\n",al[i].nome,al[i].kcal);
            printf("_________________________________\n");
        }

    }
    printf("\n\n");
    system("Pause");
}






