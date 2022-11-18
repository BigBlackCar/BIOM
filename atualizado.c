#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX_ALIMENTOS 10
#define MAX_PESSOAS 10

typedef enum //estilo de vido tipo enumerado(TC)
{
    sedentario=1,
    pouco_ativo,
    ativo,
    muito_ativo,
} estilo_tipo;

typedef enum  //grupo tipo enumerado (TD)
{
    ceriais_derivados_e_tuberculos = 1,
    gorduras_e_oleos,
    fruta,
    laticinios,
    carnes_pescados_e_ovos,
    leguminosas,
    horticulas,
} grupo_tipo;

typedef struct  //struct dos alimentos (professora)
{
    char nome[26];
    grupo_tipo grupo;
    int	unidade;
    int	peso;
    int	kcal;
} 		alimento_tipo;

typedef struct
{
    char nome[26];//nome da pessoas
    int peso;//peso da pessoas
    char sexo[20];//sexo da pessoas
    int altura;//altura da pessoas
    int estilo;//variavel numerica estilo das pessoas
    char est[30];//variavel
    int idade;//idade das pessoas
    float imc;//indice de massa corporal das pessoas
} pessoa_tipo;

void	inicializar_alimentos(alimento_tipo *al, int *qtd)  //adiciona os alimentos base (professora)
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

void inicializar_pessoas(pessoa_tipo pt[], int *qtd2)//pessoas ja adicionadas ao sistema
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

    strcpy(pt[2].nome,"Cristina Ferreira ");
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
/*void ordenar_pessoas(pessoa_tipo pt[], int *qtd2) //procedimento para ordenar as pessoas pelo sexo pedido pelo utilizador
{
    int i;//variavel numerica
    char genero[2];//variavel pedida ao utilizador para comparar com o sexo das pessoas no sistema

    i=0;

    do
    {
        printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
        scanf("%s", &genero);

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
    while(genero!='m' && genero!='f');


}*/


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


void eliminar_pessoas(pessoa_tipo *pt, int *qtd2)//procedimento para eliminar pessoas
{
    int t;
    char eli[80];
    printf("Insira o nome da pessoa que quer eliminar:");
    scanf(" %[^t\n]", eli);
    //fgets(eli, sizeof(eli), stdin);
    printf(" %s\n",eli);
    t=0;
    do
    {
        if( strcmp( pt[t].nome, eli ) == 0 )//compara o nome escrito pelo utilizador com todos os nomes no programa
        {
            system ("cls");
            strcpy(pt[t].nome,"zzzz");//se for igual muda o nome desse utilizador para "zzzz"
            *qtd2 = *qtd2 - 1;//apaga o ultimo elemento da lista de nomes
            system("PAUSE");
            break;
        }
        else if( t == *qtd2 )
        {
            printf("Não está na lista\n\n");
        }
        t++;
    }
    while( t < *qtd2 );
    system("Pause");
}

void inserir_alimentos(alimento_tipo *al, int *qtd)  //permite adicionar um novo alimento que ainda não exista (TD)
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
                scanf("%d", &al[*qtd].grupo);
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
    scanf(" %[^t\n]", pt[*qtd2].nome);
    printf("Insira o peso da pessoa:");
    scanf("%d", &pt[*qtd2].peso);
    printf("Insira a altura da pessoa em cm:");
    scanf("%d", &pt[*qtd2].altura);
    printf("Insira a idade da pessoa:");
    scanf("%d", &pt[*qtd2].idade);
    pt[*qtd2].imc = pt[*qtd2].peso / ((pt[*qtd2].altura*0,01) * (pt[*qtd2].altura*0,01));
    printf("Insira o sexo da pessoa(m ou f):");
    scanf("%s", &pt[*qtd2].sexo);
    printf("Insira o estilo de vida da pessoa: \n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo");
    scanf("%d", &pt[*qtd2].estilo);
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


void sort_structs(alimento_tipo *al, int *len) //Organiza as structs por ordem alfabética (Credito a Tiago Alves)
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

void sort_structs_pessoas(pessoa_tipo *pt, int *lon)//ordena os nomes por ordem alfabetica
{
    int         w=0, changed;
    pessoa_tipo    temp;
    do
    {
        changed = 0;
        for (w=0; w < (*lon) - 1; w++)
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
            sort_structs_pessoas(pt,&qtd2);
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
            sort_structs_pessoas(pt,&qtd2);
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
    int qtd = 0, qtd2 = 0;
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
