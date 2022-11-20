#include "header.h"

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

void	inicializar_pessoas(pessoa_tipo pt[], int *qtd2)
{
    strcpy(pt[0].nome,"Cristiano Diniz");
    pt[0].peso=72;
    pt[0].altura=172;
    pt[0].idade=18;
    strcpy(pt[0].sexo,"m");
    strcpy(pt[0].est,"Ativo");
    pt[0].imc=24;

    strcpy(pt[1].nome,"Joel Silva");
    pt[1].peso=72;
    pt[1].altura=176;
    pt[1].idade=18;
    strcpy(pt[1].sexo,"m");
    strcpy(pt[1].est,"ativo");
    pt[1].imc=23;

    strcpy(pt[2].nome,"Cristina Ferreira");
    pt[2].peso=70;
    pt[2].altura=170;
    pt[2].idade=45;
    strcpy(pt[2].sexo,"f");
    strcpy(pt[2].est,"pouco ativo");
    pt[2].imc=24;

    strcpy(pt[3].nome,"Cristiano Ronaldo");
    pt[3].peso=72;
    pt[3].altura=172;
    pt[3].idade=18;
    strcpy(pt[3].sexo,"m");
    strcpy(pt[3].est,"muito ativo");
    pt[3].imc=24;
    *qtd2=4;
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


