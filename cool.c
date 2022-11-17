#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define  MAX_ALIMENTOS 10

typedef enum
{
    ceriais_derivados_e_tuberculos = 1,
    gorduras_e_oleos,
    fruta,
    laticinios,
    carnes_pescados_e_ovos,
    leguminosas,
    horticulas,
} grupo_tipo;

typedef struct
{
    char nome[26];
    grupo_tipo grupo;
    int	unidade;
    int	peso;
    int	kcal;
} 		alimento_tipo;

void	inicializar_alimentos(alimento_tipo *al, int *qtd)
{
    strcpy(al[0].nome,"Carne de peru");
    al[0].grupo = 5;
    al[0].unidade = 1;
    al[0].peso = 100;
    al[0].kcal = 153;

    strcpy(al[1].nome,"Macarrao");
    al[1].grupo = 1;
    al[1].unidade = 1;
    al[1].peso = 200;
    al[1].kcal = 192;

    strcpy(al[2].nome,"Maça");
    al[2].grupo = 3;
    al[2].unidade = 1;
    al[2].peso = 100;
    al[2].kcal = 64;

    strcpy(al[3].nome,"Ovo inteiro cru");
    al[3].grupo = 5;
    al[3].unidade = 1;
    al[3].peso = 50;
    al[3].kcal = 74;

    strcpy(al[4].nome,"Pao de centeio");
    al[4].grupo = 1;
    al[4].unidade = 1;
    al[4].peso = 30;
    al[4].kcal = 70;

    *qtd = 5;
}

void	mostrar_alimentos(alimento_tipo *al, int qtd)
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

void inserir_alimentos(alimento_tipo *al, int *qtd)
{
    if (*qtd < MAX_ALIMENTOS)
    {
        printf("Alimento %d\n", *qtd);
        printf("Nome=");
        scanf(" %[^t\n]", al[*qtd].nome);
        for(int i = 0; i < *qtd; i++)
        {
            if (strcmp(al[*qtd].nome, al[i].nome) == 0)
            {
                printf("\nAlimento ja existe\n");
                i = *qtd;
            }
            else
            {
                printf("Grupo=");
                scanf("%d", (int *)&al[*qtd].grupo);
                printf("Unidade=");
                scanf("%d", &al[*qtd].unidade);
                printf("Peso=");
                scanf("%d", &al[*qtd].peso);
                printf("Kcal=");
                scanf("%d", &al[*qtd].kcal);
                printf("\n");
                *qtd= *qtd + 1;
                break;
            }

        }
    }
    else
    {
        printf("Numero maximo de alimentos atingido!\n");
    }
    system("Pause");
}


void estimar_valor_kcal(alimento_tipo *al)
{
    int num, somacal=0, i=0, quant;
    int numalim;

    do
    {
        printf("Numero do alimento que ingeriu (999 para parar):");
        scanf("%d",&numalim);
        if(numalim != 999)
        {
            printf("Quantidade do alimento que ingeriu:");
            scanf("%d", &quant);
            somacal = somacal + quant * al[numalim].kcal;
            printf("\n");
        }
    }
    while(numalim != 999);
    if (numalim == 999)
        printf("\nO valor calorífico da sua refeição foi de %d kcal.\n\n", somacal);
    system("Pause");
}

int listar_grupo()
{
    int escolha;
    printf("Qual o grupo que pretende listar?\n\n1 - ceriais derivados e tuberculos\n2 - gorduras e oleos\n3 - fruta\n4 - laticinios\n5 - carnes pescados e ovos\n6 - leguminosas\n7 - horticulas");
    printf("\n\nSelecionar opcao: ");
    scanf("%d",&escolha);
    return (escolha);
}


void sort_structs_by_kcal(alimento_tipo *al, int *len)
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


void mostrar_tabela(alimento_tipo *al, int *qtd, int escolha)
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


void sort_structs(alimento_tipo *al, int *len)//Credito a Tiago Alves
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

void mostrar_kcal_temp(alimento_tipo *al, int qtd)
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

int submenu_2()
{
    int qtd = 0, escolha;
    char op;
    alimento_tipo al[MAX_ALIMENTOS];
    setlocale(LC_ALL, "Portuguese");
    inicializar_alimentos(al,&qtd);

    do
    {
        do
        {
            system ("cls");
            printf("Menu Gestao de Alimentos\n\n");
            printf("1 ... Inserir alimento\n");
            printf("2 ... Estimar o valor calorifico de uma refeicao atraves da escolha dos\n      alimentos da lista (TCA), e indicacao das respetivas quantidades.\n");
            printf("3 ... Listar alimentos de um grupo alimentar\n");
            printf("4 ... Listagem alfabetica dos alimentos\n");
            printf("0 ... Voltar ao Menu Principal\n");
            printf("\nSelecionar opcao: ");
            scanf(" %c", &op);
        }
        while(op!='0' && op!='1' && op!='2' && op!='3' && op!='4');

        switch (op)
        {
        case '1':
        {
            system("cls");
            inserir_alimentos(al,&qtd);
            sort_structs(al,&qtd);
            break;
        }
        case '2':
        {
            system("cls");
            estimar_valor_kcal(al);
            break;
        }
        case '3':
        {
            system("cls");
            sort_structs_by_kcal(al,&qtd);
            escolha = listar_grupo();
            system("cls");
            printf("\n");
            mostrar_tabela(al,&qtd,escolha);
            break;
        }
        case '4':
        {
            system("cls");
            sort_structs(al,&qtd);
            mostrar_alimentos(al,qtd);
            break;
        }
        }
    }
    while(op!='0');
    printf("\n");
    system("PAUSE");
    return 0;
}



int submenu_1()
{
    char op;
    do
    {
        do
        {
            system ("cls");
            printf("           SUBMENU 1 - nivel 1\n");
            printf("-----------------------------------------------\n");
            printf("  1 - ir para submenu nivel 2\n");
            printf("  2 - ir para submenu nuvel 2\n");
            printf("v/V - Voltar ao menu anterior - ir para nivel 0\n");
            printf("-----------------------------------------------\n\n");
            scanf(" %c", &op);
        }
        while(op!='v' && op!='V' && op!='1' && op!='2');

        switch (op)
        {
        case '1':
        {
            submenu_2();
            break;
        }
        case '2':
        {
            break;
        }
        }
    }
    while(op!='v' && op!='V');

    system("PAUSE");
    return 0;
}


int main()
{
    int qtd = 0;
    char op;
    alimento_tipo al[MAX_ALIMENTOS];
    setlocale(LC_ALL, "Portuguese");

    do
    {
        do
        {
            system ("cls");
            printf("MENU PRINCIPAL\n\n");
            printf("1 ... Gestao de Pessoas\n");
            printf("2 ... Gestao de Alimentos\n");
            printf("3 ... Gestao de Dietas\n");
            printf("4 ... Estatisticas\n");
            printf("0 ... Sair\n");
            printf("\nSelecionar opcao: ");
            scanf(" %c", &op);
        }
        while(op!='0' && op!='1' && op!='2' && op!='3' && op!='4');

        switch (op)
        {
        case '1':
                {
                   submenu_1();
                   break;
            }
        case '2':
        {
            submenu_2();
            break;
        }
        }
    }
    while(op!='0');
    printf("\n");
    system("PAUSE");
    return 0;
}

