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


void inserir_alimentos(alimento_tipo *al, int *qtd)  //permite adicionar um novo alimento que ainda não exista (TD)
{
    if (*qtd < MAX_ALIMENTOS)
    {
        printf("Alimento %d\n", *qtd);
        printf("Nome=");
        scanf(" %[^\n]", al[*qtd].nome);
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

void inserir_pessoas(pessoa_tipo *pt, int *qtd2)//procedimento para inserir pessoas
{
    printf("Insira o nome da pessoa:");
    scanf(" %[^\n]", pt[*qtd2].nome);
    printf("Insira o peso da pessoa:");
    scanf("%d", &pt[*qtd2].peso);
    printf("Insira a altura da pessoa em cm:");
    scanf("%d", &pt[*qtd2].altura);
    printf("Insira a idade da pessoa:");
    scanf("%d", &pt[*qtd2].idade);
    pt[*qtd2].imc = pt[*qtd2].peso / ((pt[*qtd2].altura*0,01) * (pt[*qtd2].altura*0,01));
    printf("Insira o sexo da pessoa(m ou f):");
    scanf("%s", (char *)&pt[*qtd2].sexo);
    printf("Insira o estilo de vida da pessoa: \n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo");
    scanf("%d", (int *)&pt[*qtd2].estilo);
    switch (pt[*qtd2].estilo)
    {
    case '1':
    {
        strcpy(pt[*qtd2].est,"Sedentario");
        break;
    }
    case '2':
    {
        strcpy(pt[*qtd2].est,"Pouco ativo");
        break;
    }
    case '3':
    {
        strcpy(pt[*qtd2].est,"Ativo");
        break;
    }
    case '4':
    {
        strcpy(pt[*qtd2].est,"Muito ativo");
        break;
    }

    }
    *qtd2 = *qtd2 + 1;
}


void estimar_valor_kcal(alimento_tipo *al)  //calcula as calorias de uma refeição atraves de alimentos ingeridos e as respetivas quantidades (TD)
{
    int num, somacal=0, i=0, quant;
    int numalim;

    do
    {
        printf("Numero do alimento que ingeriu (-1 para parar):");
        scanf("%d",&numalim);
        if(numalim != -1)
        {
            printf("Quantidade do alimento que ingeriu:");
            scanf("%d", &quant);
            somacal = somacal + quant * al[numalim].kcal;
            printf("\n");
        }
    }
    while(numalim != -1);
    if (numalim == -1)
        printf("\nO valor calorifico da sua refeicao foi de %d kcal.\n\n", somacal);
    system("Pause");
}

int listar_grupo() //escolher o numero do grupo que sera listado (TD)
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


void eliminar_pessoas(pessoa_tipo *pt, int *qtd2)//procedimento para eliminar pessoas
{
    int t=0, flag = 0, max;
    char z[]="zzzzzzz";
    char *eli;
    eli = (char *)malloc(sizeof(char) * 80 + 1);
    printf("Insira o nome da pessoa que quer eliminar:");
    scanf(" %[^\n]", eli);
    printf("%s\n",eli);
    max = *qtd2;
    do
    {
        if( strcmp( pt[t].nome, eli ) == 0 )//compara o nome escrito pelo utilizador com todos os nomes no programa
        {
            system ("cls");
            strcpy(pt[t].nome,z);
            sort_structs_pessoas(pt,*qtd2);
            *qtd2 = (*qtd2) - 1;//apaga o ultimo elemento da lista de nomes
            system("PAUSE");
            flag = 1;
            break;
        }
        t++;
    }
    while( t < max );
    if (flag == 0)
        printf("Nao esta na lista\n\n");
    system("Pause");
}

int submenu_2()
{
    int qtd = 0, escolha;
    char op;
    alimento_tipo al[MAX_ALIMENTOS];
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
    int qtd2 = 0;
    pessoa_tipo pt[MAX_PESSOAS];
    inicializar_pessoas(pt,&qtd2);
    char op;
    do
    {
        do
        {
            system ("cls");
            printf("Menu Gestao de Pessoas\n\n");;
            printf("1 ... Inserir Pessoa\n");
            printf("2 ... Eliminar Pessoa\n");
            printf("3 ... Mostrar Pessoas agrupadas por sexo e estilo de vida\n");
            printf("4 ... Listar Todas as Pessoas\n");
            printf("0 ... Voltar ao menu principal\n\n");
            printf("Selecionar opcao: ");
            scanf(" %c", &op);
        }
        while(op!='0' && op!='1' && op!='2' && op!='3' && op!='4');

        switch (op)
        {
        case '1':
        {
            system("cls");
            inserir_pessoas(pt,&qtd2);
            break;
        }
        case '2':
        {
            system("cls");
            eliminar_pessoas(pt,&qtd2);
            break;
        }
        /*case '3':
        {
            system("cls");
            ordenar_pessoas(pt,&qtd2);
        }*/
        case '4':
        {
            system("cls");
            sort_structs_pessoas(pt,qtd2);
            mostrar_pessoas(pt,qtd2);
        }
        }
    }
    while(op!='0');

    system("PAUSE");
    return 0;
}


int main()
{
    char op;
    pessoa_tipo al[MAX_PESSOAS];
    alimento_tipo pt[MAX_ALIMENTOS];

    do
    {
        do
        {
            system ("cls");
            printf("MENU PRINCIPAL\n\n");
            printf("1 ... Gestao de Pessoas\n");
            printf("2 ... Gestao de Alimentos\n");
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
