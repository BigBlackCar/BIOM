# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_ALIMENTOS 10
# define MAX_PESSOAS 10
# define MAX_DIETAS 10

typedef enum //varievel grupo tipo enumerado
{
    sedentario=1,
    pouco_ativo,
    ativo,
    muito_ativo,
} estilo_tipo;

typedef enum //variavel grupo tipo enumerado
{
    ceriais_derivados_e_tuberculos=1,
    gorduras_e_oleos,
    fruta,
    laticinios,
    carnes_pescados_e_ovos,
    leguminosas,
    horticulas,
} grupo_tipo;


typedef struct  alimentos //struct que armazena informações sobre os alimentos
{
    int	kcal;
    int	peso;
    int	unidade;
    char	nome[26];
    grupo_tipo grupo;
} alimento_tipo;

typedef struct pessoas //struct que armazena informações sobre as pessoas
{
    int 	peso;
    int 	idade;
    int 	altura;
    char 	est[30];
    char 	sexo;
    char 	nome[26];
    float 	imc;
    estilo_tipo estilo;
} pessoa_tipo;



typedef struct dieta
{
    char nomed[26];
    int data[3];
    int quantalim[5];
    char limao[5][MAX_DIETAS][26];
    int dietakcal;
    char sexo;
    char estilovida[30];
    int tabela;
    double datasecs;
    int balanca;
    int grupo_kcal[7];

} dieta_tipo;


void	inicializar_alimentos(alimento_tipo *al, int *qtd) //adiciona os alimentos base ao programa (Professora)
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

    strcpy(al[2].nome,"Maca");
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

void	inicializar_pessoas(pessoa_tipo pt[], int *qtd2) //adiciona as pessoas base ao programa (Tomas Coelho 7/11)
{
    strcpy(pt[0].nome,"a");//"Cristiano Diniz");
    pt[0].peso=72;
    pt[0].altura=172;
    pt[0].idade=18;
    pt[0].sexo = 'm';
    strcpy(pt[0].est,"Ativo");
    pt[0].imc=24;

    strcpy(pt[1].nome,"Joel Silva");
    pt[1].peso=72;
    pt[1].altura=176;
    pt[1].idade=18;
    pt[1].sexo= 'm';
    strcpy(pt[1].est,"Ativo");
    pt[1].imc=23;

    strcpy(pt[2].nome,"Cristina Ferreira");
    pt[2].peso=70;
    pt[2].altura=170;
    pt[2].idade=45;
    pt[2].sexo= 'f';
    strcpy(pt[2].est,"Pouco ativo");
    pt[2].imc=24;

    strcpy(pt[3].nome,"Cristiano Ronaldo");
    pt[3].peso=72;
    pt[3].altura=172;
    pt[3].idade=18;
    pt[3].sexo = 'm';
    strcpy(pt[3].est,"Muito ativo");
    pt[3].imc=24;

    *qtd2=4;
}

int verificar_grupo(alimento_tipo *al, int *qtd) //Tiago Duarte 7/11
{
    int flag = 0;

    if ((al[*qtd].grupo == 1) || (al[*qtd].grupo == 2) || (al[*qtd].grupo == 3) || (al[*qtd].grupo == 4) || (al[*qtd].grupo == 5) || (al[*qtd].grupo == 6) || (al[*qtd].grupo == 7))
        flag = 1;
    else
        flag = 0;

    return flag;
}

void inserir_alimentos(alimento_tipo *al, int *qtd)  //permite adicionar um novo alimento que ainda não exista (Tomás Coelho 7/11)
{
    int flag = 0;

    if (*qtd < MAX_ALIMENTOS)
    {
        printf("Alimento %d\n", *qtd);
        printf("\n");
        printf("Nome: ");
        scanf(" %[^\n]", al[*qtd].nome);
        for(int i = 0; i < *qtd; i++)
        {
            if (strcmp(al[*qtd].nome, al[i].nome) == 0)  //verifica se o alimento ja existe
            {
                printf("\nAlimento ja existe\n");
                i = *qtd;
            }
            else
            {
                do
                {
                    printf("\nInsira o Grupo\n\n");
                    printf("1- Ceriais derivados e tuberculos");
                    printf("\n2- Gorduras e oleos");
                    printf("\n3- Fruta");
                    printf("\n4- Laticinios");
                    printf("\n5- Carnes pescados e ovos");
                    printf("\n6- Leguminosas");
                    printf("\n7- Horticulas");
                    printf("\n\nOpcao: ");
                    scanf(" %d", (int *)&al[*qtd].grupo);
                    flag = verificar_grupo(al,qtd);
                    if (flag == 0)
                    {
                        system("cls");
                        printf("Grupo Invalido!!\n\n");
                        system("Pause");
                        system("cls");
                        printf("Alimento %d\n", *qtd);
                        printf("\nNome: %s\n",al[*qtd].nome);
                    }
                }
                while (flag != 1);

                do
                {
                    printf("\nUnidade: ");
                    scanf(" %d", &al[*qtd].unidade);
                }
                while (al[*qtd].unidade <= 0);

                do
                {
                    printf("\nPeso(em gramas): ");
                    scanf(" %d", &al[*qtd].peso);
                }
                while ( al[*qtd].peso < 0);

                do
                {
                    printf("\nKcal: ");
                    scanf(" %d", &al[*qtd].kcal);
                }
                while (al[*qtd].kcal < 0);

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

void verficar_sexo(pessoa_tipo *pt, int *qtd2) //Tiago Duarte 14/11
{
    do
    {
        printf("Insira o sexo da pessoa(m ou f):");
        scanf(" %c",&pt[*qtd2].sexo);
    }
    while ( (pt[*qtd2].sexo != 'm' ) && ( pt[*qtd2].sexo != 'f'));


}

int validar_nome(pessoa_tipo *pt, char nome[], int *qtd2)//Tiago Duarte 14/11
{
    int flag = 0, i = 0, b;

    while (i < *qtd2)
    {

        b = strcmp(pt[i].nome,nome);

        if (b == 0)
        {

            flag = 1;
            break;
        }
        i++;
    }

    return flag;
}

void inserir_pessoas(pessoa_tipo *pt, int *qtd2)// inserir novas pessoas (Tomás Coelho 7/11)
{
    int flag = 0;
    char nome[26];
    char f[]="f";
    char m[]="m";
    printf("Insira o nome da pessoa: ");
    scanf(" %[^\n]", &nome);
    system("cls");
    do
    {
        flag = validar_nome(pt,nome,qtd2);

        if (flag == 1)
        {
            printf("Nome ja existe no sistema, insira um novo nome: ");
            scanf(" %[^\n]", &nome);
            system("cls");
        }
        else
        {
            strcpy(pt[*qtd2].nome,nome);
            printf("Nome: %s\n",pt[*qtd2].nome);
        }
    }
    while (flag != 0);
    printf("\n");
    printf("Insira o peso da pessoa: ");
    scanf("%d", &pt[*qtd2].peso);
    printf("\n");
    printf("Insira a altura da pessoa em cm: ");
    scanf("%d", &pt[*qtd2].altura);
    printf("\n");
    printf("Insira a idade da pessoa: ");
    scanf("%d", &pt[*qtd2].idade);
    printf("\n");
    pt[*qtd2].imc = pt[*qtd2].peso / ((pt[*qtd2].altura*(0.01)) * (pt[*qtd2].altura*(0.01)));

    verficar_sexo(pt,qtd2);
    printf("\n");

    printf("Insira o estilo de vida da pessoa: \n\n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo\n");
    printf("\n");

    do
    {
        printf("Opcao: ");
        scanf("%d", (int *)&pt[*qtd2].estilo);
    }
    while((pt[*qtd2].estilo != 1) && (pt[*qtd2].estilo != 2) && (pt[*qtd2].estilo != 3) && (pt[*qtd2].estilo != 4));

    switch (pt[*qtd2].estilo)
    {
    case 1:
        strcpy(pt[*qtd2].est,"Sedentario");
        break;
    case 2:
        strcpy(pt[*qtd2].est,"Pouco ativo");
        break;
    case 3:
        strcpy(pt[*qtd2].est,"Ativo");
        break;
    case 4:
        strcpy(pt[*qtd2].est,"Muito ativo");
        break;
    }
    *qtd2 = *qtd2 + 1;
}

void validar_data(dieta_tipo *dt, alimento_tipo *at, int *qtd3, int *qtd)//Tomas Coelho 25/11
{

    if(dt[*qtd3].data[0] > 31 || dt[*qtd3].data[0] < 1)
    {
        do
        {
            printf("Data da refeicao(dd mm aa): ");
            scanf("%d %d %d",&dt[*qtd3].data[0],&dt[*qtd3].data[1],&dt[*qtd3].data[2]);
        }
        while(dt[*qtd3].data[0]>31 || dt[*qtd3].data[0]<1);
    }

    if(dt[*qtd3].data[1] >12 || dt[*qtd3].data[1] < 1)
    {
        do
        {
            printf("Data da refeicao(dd mm aa): ");
            scanf("%d %d %d",&dt[*qtd3].data[0],&dt[*qtd3].data[1],&dt[*qtd3].data[2]);
        }
        while(dt[*qtd3].data[1] > 12 || dt[*qtd3].data[0] < 1);
    }

    if(dt[*qtd3].data[2]>2022 || dt[*qtd3].data[2]<1)
    {
        do
        {
            printf("Data da refeicao(dd mm aa): ");
            scanf("%d %d %d",&dt[*qtd3].data[0],&dt[*qtd3].data[1],&dt[*qtd3].data[2]);
        }
        while(dt[*qtd3].data[2]>2022 || dt[*qtd3].data[2]<1);
    }

}


int validar_nome_procura(pessoa_tipo *pt, int *qtd2, char nomeproc[])//Tiago Duarte 22/11
{
    int flag = 0, a, i = 0;

    while ( (i < *qtd2) && (flag != 1))
    {
        a = strcmp(pt[i].nome, nomeproc);
        if (a == 0)
            flag = 1;

        i++;

    }

    return flag;
}

void mostrar_dietas(pessoa_tipo *pt, dieta_tipo *dt, alimento_tipo *at, int *qtd3, int *qtd, int *qtd2)//Tiago Duarte e Tomás Coelho 5/12
{
    int flag = 0, flag2 = 0, i = 0, a = 0, j = 0;
    char nomeproc[26];

    if ( *qtd3 > 0)
    {

        do
        {
            printf("Nome da pessoa a procurar: ");
            scanf(" %[^\n]", &nomeproc);

            flag = validar_nome_procura(pt,qtd2,nomeproc);
            if (flag == 0)
                printf("Nome invalido! Introduza um nome existente");

        }
        while (flag != 1);


        while ((i < *qtd3) && (flag2 != 1))
        {
            a = strcmp(nomeproc,dt[i].nomed);
            if (a == 0)
                flag2 = 1;
        }

        printf("\n\nNome: %s", dt[i].nomed);
        printf("\nData: %d %d %d \n", dt[i].data[0], dt[i].data[1], dt[i].data[2]);

        printf("\nPequeno Almoco");
        printf("\nAlimentos: ");

        if( dt[*qtd3 - 1].quantalim[0] != 0)
        {

            do
            {
                printf("%s, ", dt[i].limao[0][j]);
                j++;

            }
            while(j < dt[*qtd3 - 1].quantalim[0]);
        }


        printf("\n\nAlmoco");
        printf("\nAlimentos:");
        j=0;

        if(dt[*qtd3 - 1].quantalim[1]  != 0)
        {
            do
            {

                printf("%s, ", dt[i].limao[1][j]);
                j++;

            }
            while(j < dt[*qtd3 - 1].quantalim[1]);
        }

        printf("\n\nLanche");
        printf("\nAlimentos:");
        j=0;

        if(dt[*qtd3 - 1].quantalim[2]  != 0)
        {
            do
            {
                j=0;
                printf("%s, ", dt[i].limao[2][j]);
                j++;

            }
            while(j < dt[*qtd3 - 1].quantalim[2]);
        }

        printf("\n\nJantar");
        printf("\nAlimentos:");

        if(dt[*qtd3 - 1].quantalim[3]  != 0)
        {
            j=0;
            do
            {
                j=0;
                printf("%s, ", dt[i].limao[3][j]);
                j++;

            }
            while(j < dt[*qtd3 - 1].quantalim[3]);
        }

        printf("\n\nSeia");
        printf("\nAlimentos:");
        j=0;
        if(dt[*qtd3 - 1].quantalim[4]  != 0)
        {

            do
            {
                j=0;
                printf("%s, ", dt[i].limao[4][j]);
                j++;

            }
            while(j < dt[*qtd3 - 1].quantalim[4]);
        }


        i++;


        printf("\n\n");
    }
    else
        printf("Nao foram encontradas dietas no sistema!\n\n");


    system("Pause");

}


void verificar_estilo(pessoa_tipo *pt, int *qtd2) //Tomás Coelho 25/11
{
    if(pt[*qtd2].estilo> 4)
    {
        do
        {

            printf("Insira o estilo de vida da pessoa: \n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo\n");
            scanf("%d", (int *)&pt[*qtd2].estilo);
            printf("%d", pt[*qtd2].estilo);
        }
        while((pt[*qtd2].estilo)>4);
        switch (pt[*qtd2].estilo)
        {
        case 1:
            strcpy(pt[*qtd2].est,"Sedentario");
            break;
        case 2:
            strcpy(pt[*qtd2].est,"Pouco ativo");
            break;
        case 3:
            strcpy(pt[*qtd2].est,"Ativo");
            break;
        case 4:
            strcpy(pt[*qtd2].est,"Muito ativo");
            break;
        }
    }
    else
        system("Pause");
}

void inserir_dietas(dieta_tipo *dt, alimento_tipo *at, int *qtd3, int *qtd, pessoa_tipo *pt, int *qtd2) //Tiago Duarte 22/11
{

    int i, j, k, l, m, n, somakcal = 0, a = 1, b = 0, flag = 0;



    while (a != 0)
    {

        printf("Nome: ");
        scanf(" %[^\n]", dt[*qtd3].nomed);

        l = 0;

        while (l < *qtd2)
        {
            a = strcmp(dt[*qtd3].nomed,pt[l].nome);

            if ( a == 0)
                break;

            l++;
        }
    }

    dt[*qtd3].sexo = pt[l].sexo;
    strcpy(dt[*qtd3].estilovida, pt[l].est);

    printf("Data da refeicao(dd mm aa): ");
    scanf("%d %d %d",&dt[*qtd3].data[0], &dt[*qtd3].data[1], &dt[*qtd3].data[2]);
    validar_data(dt,at,qtd3,qtd);
    system("pause");
    system("cls");

    printf("Pequeno Almoco\n\n");
    i = 0;
    n = 0;

    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantalim[0]);

    if( dt[*qtd3].quantalim[0] != 0)
    {

        while (i < dt[*qtd3].quantalim[0])
        {

            do
            {
                m = 0;

                printf("Nome do alimento que ingeriu: ");
                scanf(" %[^\n]",&dt[*qtd3].limao[0][n]);
                do
                {
                    b =  strcmp(dt[*qtd3].limao[0][n], at[m].nome);

                    if (b == 0)
                    {
                        flag = 1;
                        break;
                    }

                    m++;

                }
                while(m < *qtd);

                if (flag == 0)
                    printf("Nome invalido!\n");



            }
            while (flag != 1);

            j = 0;
            flag = 0;

            while (j < *qtd)
            {
                if (strcmp(dt[*qtd3].limao[0][i],at[j].nome) == 0)
                {
                    k = j;
                    somakcal = somakcal + at[k].kcal;
                    if (at[k].grupo == 1)
                        dt[*qtd3].grupo_kcal[0] = dt[*qtd3].grupo_kcal[0] + at[k].kcal;
                    else if (at[k].grupo == 2)
                        dt[*qtd3].grupo_kcal[1] = dt[*qtd3].grupo_kcal[1] + at[k].kcal;
                    else if (at[k].grupo == 3)
                        dt[*qtd3].grupo_kcal[2] = dt[*qtd3].grupo_kcal[2] + at[k].kcal;
                    else if (at[k].grupo == 4)
                        dt[*qtd3].grupo_kcal[3] = dt[*qtd3].grupo_kcal[3] + at[k].kcal;
                    else if (at[k].grupo == 5)
                        dt[*qtd3].grupo_kcal[4] = dt[*qtd3].grupo_kcal[4] + at[k].kcal;
                    else if (at[k].grupo == 6)
                        dt[*qtd3].grupo_kcal[5] = dt[*qtd3].grupo_kcal[5] + at[k].kcal;
                    else if (at[k].grupo == 7)
                        dt[*qtd3].grupo_kcal[6] = dt[*qtd3].grupo_kcal[6] + at[k].kcal;

                }
                j++;

            }
            i++;
            n++;

        }

    }


    system("cls");

    printf("Almoco\n\n");
    i = 0;
    n = 0;

    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantalim[1]);

    if( dt[*qtd3].quantalim[1] != 0)
    {

        while (i < dt[*qtd3].quantalim[1])
        {
            do
            {
                m = 0;

                printf("Nome do alimento que ingeriu: ");
                scanf(" %[^\n]",&dt[*qtd3].limao[1][n]);
                do
                {
                    b =  strcmp(dt[*qtd3].limao[1][n], at[m].nome);

                    if (b == 0)
                    {
                        flag = 1;
                        break;
                    }

                    m++;

                }
                while(m < *qtd);

                if (flag == 0)
                    printf("Nome invalido!\n");



            }
            while (flag != 1);

            j = 0;
            flag = 0;

            while (j < *qtd)
            {
                if (strcmp(dt[*qtd3].limao[0][i],at[j].nome) == 0)
                {
                    k = j;
                    somakcal = somakcal + at[k].kcal;
                    if (at[k].grupo == 1)
                        dt[*qtd3].grupo_kcal[0] = dt[*qtd3].grupo_kcal[0] + at[k].kcal;
                    else if (at[k].grupo == 2)
                        dt[*qtd3].grupo_kcal[1] = dt[*qtd3].grupo_kcal[1] + at[k].kcal;
                    else if (at[k].grupo == 3)
                        dt[*qtd3].grupo_kcal[2] = dt[*qtd3].grupo_kcal[2] + at[k].kcal;
                    else if (at[k].grupo == 4)
                        dt[*qtd3].grupo_kcal[3] = dt[*qtd3].grupo_kcal[3] + at[k].kcal;
                    else if (at[k].grupo == 5)
                        dt[*qtd3].grupo_kcal[4] = dt[*qtd3].grupo_kcal[4] + at[k].kcal;
                    else if (at[k].grupo == 6)
                        dt[*qtd3].grupo_kcal[5] = dt[*qtd3].grupo_kcal[5] + at[k].kcal;
                    else if (at[k].grupo == 7)
                        dt[*qtd3].grupo_kcal[6] = dt[*qtd3].grupo_kcal[6] + at[k].kcal;
                }
                j++;

            }
            i++;
            n++;

        }

    }
    system("cls");

    printf("Lanche\n\n");
    i = 0;
    n = 0;

    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantalim[2]);

    if( dt[*qtd3].quantalim[2] != 0)
    {

        while (i < dt[*qtd3].quantalim[2])
        {
            do
            {
                m = 0;

                printf("Nome do alimento que ingeriu: ");
                scanf(" %[^\n]",&dt[*qtd3].limao[2][n]);
                do
                {
                    b =  strcmp(dt[*qtd3].limao[2][n], at[m].nome);

                    if (b == 0)
                    {
                        flag = 1;
                        break;
                    }

                    m++;

                }
                while(m < *qtd);

                if (flag == 0)
                    printf("Nome invalido!\n");



            }
            while (flag != 1);

            j = 0;
            flag = 0;

            while (j < *qtd)
            {
                if (strcmp(dt[*qtd3].limao[0][i],at[j].nome) == 0)
                {
                    k = j;
                    somakcal = somakcal + at[k].kcal;
                    if (at[k].grupo == 1)
                        dt[*qtd3].grupo_kcal[0] = dt[*qtd3].grupo_kcal[0] + at[k].kcal;
                    else if (at[k].grupo == 2)
                        dt[*qtd3].grupo_kcal[1] = dt[*qtd3].grupo_kcal[1] + at[k].kcal;
                    else if (at[k].grupo == 3)
                        dt[*qtd3].grupo_kcal[2] = dt[*qtd3].grupo_kcal[2] + at[k].kcal;
                    else if (at[k].grupo == 4)
                        dt[*qtd3].grupo_kcal[3] = dt[*qtd3].grupo_kcal[3] + at[k].kcal;
                    else if (at[k].grupo == 5)
                        dt[*qtd3].grupo_kcal[4] = dt[*qtd3].grupo_kcal[4] + at[k].kcal;
                    else if (at[k].grupo == 6)
                        dt[*qtd3].grupo_kcal[5] = dt[*qtd3].grupo_kcal[5] + at[k].kcal;
                    else if (at[k].grupo == 7)
                        dt[*qtd3].grupo_kcal[6] = dt[*qtd3].grupo_kcal[6] + at[k].kcal;
                }
                j++;

            }
            i++;
            n++;

        }
    }


    system("cls");

    printf("Jantar\n\n");
    i = 0;
    n = 0;

    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantalim[3]);

    if( dt[*qtd3].quantalim[3] != 0)
    {

        while (i < dt[*qtd3].quantalim[3])
        {
            do
            {
                m = 0;

                printf("Nome do alimento que ingeriu: ");
                scanf(" %[^\n]",&dt[*qtd3].limao[3][n]);
                do
                {
                    b =  strcmp(dt[*qtd3].limao[3][n], at[m].nome);

                    if (b == 0)
                    {
                        flag = 1;
                        break;
                    }

                    m++;

                }
                while(m < *qtd);

                if (flag == 0)
                    printf("Nome invalido!\n");



            }
            while (flag != 1);

            j = 0;
            flag = 0;

            while (j < *qtd)
            {
                if (strcmp(dt[*qtd3].limao[0][i],at[j].nome) == 0)
                {
                    k = j;
                    somakcal = somakcal + at[k].kcal;
                    if (at[k].grupo == 1)
                        dt[*qtd3].grupo_kcal[0] = dt[*qtd3].grupo_kcal[0] + at[k].kcal;
                    else if (at[k].grupo == 2)
                        dt[*qtd3].grupo_kcal[1] = dt[*qtd3].grupo_kcal[1] + at[k].kcal;
                    else if (at[k].grupo == 3)
                        dt[*qtd3].grupo_kcal[2] = dt[*qtd3].grupo_kcal[2] + at[k].kcal;
                    else if (at[k].grupo == 4)
                        dt[*qtd3].grupo_kcal[3] = dt[*qtd3].grupo_kcal[3] + at[k].kcal;
                    else if (at[k].grupo == 5)
                        dt[*qtd3].grupo_kcal[4] = dt[*qtd3].grupo_kcal[4] + at[k].kcal;
                    else if (at[k].grupo == 6)
                        dt[*qtd3].grupo_kcal[5] = dt[*qtd3].grupo_kcal[5] + at[k].kcal;
                    else if (at[k].grupo == 7)
                        dt[*qtd3].grupo_kcal[6] = dt[*qtd3].grupo_kcal[6] + at[k].kcal;
                }
                j++;

            }
            i++;
            n++;

        }

    }

    system("cls");

    printf("Seia\n\n");
    i = 0;
    n = 0;

    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantalim[4]);

    if( dt[*qtd3].quantalim[4] != 0)
    {

        while (i < dt[*qtd3].quantalim[4])
        {
            do
            {
                m = 0;

                printf("Nome do alimento que ingeriu: ");
                scanf(" %[^\n]",&dt[*qtd3].limao[4][n]);
                do
                {
                    b =  strcmp(dt[*qtd3].limao[4][n], at[m].nome);

                    if (b == 0)
                    {
                        flag = 1;
                        break;
                    }

                    m++;

                }
                while(m < *qtd);

                if (flag == 0)
                    printf("Nome invalido!\n");



            }
            while (flag != 1);

            j = 0;
            flag = 0;

            while (j < *qtd)
            {
                if (strcmp(dt[*qtd3].limao[0][i],at[j].nome) == 0)
                {
                    k = j;
                    somakcal = somakcal + at[k].kcal;
                    if (at[k].grupo == 1)
                        dt[*qtd3].grupo_kcal[0] = dt[*qtd3].grupo_kcal[0] + at[k].kcal;
                    else if (at[k].grupo == 2)
                        dt[*qtd3].grupo_kcal[1] = dt[*qtd3].grupo_kcal[1] + at[k].kcal;
                    else if (at[k].grupo == 3)
                        dt[*qtd3].grupo_kcal[2] = dt[*qtd3].grupo_kcal[2] + at[k].kcal;
                    else if (at[k].grupo == 4)
                        dt[*qtd3].grupo_kcal[3] = dt[*qtd3].grupo_kcal[3] + at[k].kcal;
                    else if (at[k].grupo == 5)
                        dt[*qtd3].grupo_kcal[4] = dt[*qtd3].grupo_kcal[4] + at[k].kcal;
                    else if (at[k].grupo == 6)
                        dt[*qtd3].grupo_kcal[5] = dt[*qtd3].grupo_kcal[5] + at[k].kcal;
                    else if (at[k].grupo == 7)
                        dt[*qtd3].grupo_kcal[6] = dt[*qtd3].grupo_kcal[6] + at[k].kcal;
                }
                j++;

            }
            i++;
            n++;

        }

    }

    dt[*qtd3].dietakcal = somakcal;

    *qtd3+= 1;

    system("Pause");
}


void estimar_valor_kcal(alimento_tipo *al, int *qtd)  //calcula as calorias de uma refeição atraves de alimentos ingeridos e as respetivas quantidades (Tiago Duarte 14/11)
{
    int somacal=0, i=0, quant, a, b, c, flag = 0, round = 0; //variáveis necessarias para o cálculo
    char nomealim[26];
    char s[]="s";
    char S[]="S";

    do
    {
        do
        {
            printf("Nome do alimento que ingeriu (s/S para parar): "); //inserir s/S acaba o ciclo e calcula a kcal dos alimentos introduzidos
            scanf(" %[^\n]",&nomealim);
            round = round + 1;
            do
            {
                a = strcmp(nomealim,al[i].nome);
                b = strcmp(nomealim,s);
                c = strcmp(nomealim,S);
                if (a == 0)
                {
                    flag = 1;
                    break;
                }
                else
                    flag = 0;
                i++;
            }
            while (i < *qtd);
            if ((b == 0) || (c == 0))
                break;
            if (flag == 0)
            {
                printf("\nNome invalido!!\n\n");
                i = 0;
            }


        }
        while (flag != 1);
        if((strcmp(nomealim,s) != 0) && (strcmp(nomealim,S) != 0))
        {
            printf("\nQuantidade do alimento que ingeriu: ");
            scanf(" %d", &quant);
            somacal = somacal + quant * al[i].kcal;
            printf("\n");
        }
    }
    while((strcmp(nomealim,s) != 0) && (strcmp(nomealim,S) != 0));

    if ((round == 1) && ((strcmp(nomealim,s) == 0) || (strcmp(nomealim,S) == 0)))
        i = 0;
    else
        printf("\nO valor calorifico da sua refeicao foi de %d kcal.\n\n", somacal);
    system("Pause");
}


void sort_structs_pessoas(pessoa_tipo *pt, int len)//ordena os nomes por ordem alfabetica (Tiago de eng.inf 14/11)
{
    int         w, changed;//variavel numerica e variavel que funciona como uma flag
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


void eliminar_pessoas(pessoa_tipo *pt, int *qtd2)// eliminar pessoas (Tomas Coelho 14/11)
{
    int t=0, flag = 0, max;
    char z[]="~~~~~~";
    char eli[26];

    printf("Insira o nome da pessoa que quer eliminar: ");
    scanf(" %[^\n]", eli);
    max = *qtd2;
    do
    {
        if( strcmp( pt[t].nome, eli ) == 0 )
        {
            system ("cls");
            strcpy(pt[t].nome,z);
            sort_structs_pessoas(pt,*qtd2);
            *qtd2 = (*qtd2) - 1;
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

void    calc_imc_male(pessoa_tipo pt, char *str) //calcula o imc da pessoa baseado no sexo (Tiago Duarte 22/11)
{

    if (pt.imc > 40)
        strcpy(str, "Obesidade Morbida");
    else if (pt.imc > 30)
        strcpy(str, "Obesidade Moderada");
    else if (pt.imc > 25)
        strcpy(str, "Obesidade Leve");
    else if (pt.imc > 20)
        strcpy(str, "Normal");
    else if (pt.imc > 0)
        strcpy(str, "Abaixo do Normal");
    else
        strcpy(str, "IMC Invalido");

}

void    calc_imc_female(pessoa_tipo pt, char *str) //calcula o imc da pessoa baseado no sexo (Tiago Duarte 22/11)
{
    if (pt.imc > 39)
        strcpy(str, "Obesidade Morbida");
    else if (pt.imc > 29)
        strcpy(str, "Obesidade Moderada");
    else if (pt.imc > 24)
        strcpy(str, "Obesidade Leve");
    else if (pt.imc > 19)
        strcpy(str, "Normal");
    else if (pt.imc > 0)
        strcpy(str, "Abaixo do Normal");
    else
        strcpy(str, "IMC Invalido");

}


void ordenar_pessoas(pessoa_tipo *pt, int *qtd2) // ordenar as pessoas pelo sexo pedido pelo utilizador (Tiago Duarte 14/11)
{
    int i = 0, j = 0, a, l = 0;
    char gen;
    char pool[100];

    printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
    scanf(" %c", &gen);
    system("cls");

    printf("_____________________________________________________________________\n");
    printf("|Sexo %c                                                             |\n",gen);
    printf("_____________________________________________________________________\n");
    printf("|Nome                      |Estilo de Vida  |Imc   |Designacao      |\n");
    printf("_____________________________________________________________________\n");

    while (i < *qtd2)
    {

        if (gen == pt[i].sexo)
        {


            for(j; j < *qtd2; j++)
            {

                if (gen == 'm')
                    calc_imc_male(pt[j],pool);
                else
                    calc_imc_female(pt[j],pool);

                if (pt[j].sexo == gen)
                {
                    printf("|%-26s|%-16s|%-6.2f|%-16s|\n",pt[j].nome, pt[j].est, pt[j].imc, pool);
                    printf("_____________________________________________________________________\n");
                }

            }
        }

        i++;
    }
}

void sort_structs_by_kcal(alimento_tipo *al, int *len) //ordena as structs por ordem decrescente das kcal dos alimentos
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

void sort_structs(alimento_tipo *al, int *len) //Organiza as structs por ordem alfabética
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



void	mostrar_alimentos(alimento_tipo *al, int qtd)  //mostra todos os alimentos e os respetivos atributos (Tiago Duarte 7/11)
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

void mostrar_pessoas(pessoa_tipo *pt, int qtd2)//mostra todas as pessoas ja inseridas no sistema(Tomás Coelho 7/11)
{
    int i;
    for(i=0; i < qtd2; i++)
    {

        printf("\nNome:%s", pt[i].nome);
        printf("\nIdade:%d", pt[i].idade);
        printf("\nAltura:%dcm", pt[i].altura);
        printf("\nSexo:%c", pt[i].sexo);
        printf("\nEstilo de vida:%s", pt[i].est);
        printf("\nPeso:%dkg", pt[i].peso);
        printf("\nIMC=%.2f", pt[i].imc);
        printf("\n");
    }

    system("Pause");
}

int listar_grupo(void) //escolher o numero do grupo que sera listado (Tiago Duarte 14/11)
{
    int flag = 0, escolha;

    do
    {
        printf("Qual o grupo que pretende listar?\n\n1 - ceriais derivados e tuberculos\n2 - gorduras e oleos\n3 - fruta\n4 - laticinios\n5 - carnes pescados e ovos\n6 - leguminosas\n7 - horticulas");
        printf("\n\nSelecionar opcao: ");
        scanf("%d",&escolha);
        if((escolha == 1) || (escolha == 2) || (escolha == 3) || (escolha == 4) || (escolha == 5) || (escolha == 6) || (escolha == 7))
            flag = 1;
        if ( flag == 0)
        {
            printf("\nGrupo invalido!!\n");
            system("Pause");
            system("cls");
        }
    }
    while (flag != 1);

    return (escolha);
}

void listar_dieta_fora_padrao(dieta_tipo *dt, alimento_tipo *at, int *qtd3, int *qtd, pessoa_tipo *pt, int *qtd2)//Tiago Duarte 22/11
{
    int i = 0, j = 0;
    char m[] ="m";
    char f[]="f";
    char se[]="Sedentario";
    char pa[]="Pouco ativo";
    char ati[]="Ativo";
    char ma[]="Muito ativo";


    while ( i < *qtd3 )
    {
        if (dt[i].sexo == 'm' )
        {
            if (strcmp(dt[i].estilovida,se) == 0)
                dt[i].tabela = 5;
            if (strcmp(dt[i].estilovida,pa) == 0)
                dt[i].tabela = 6;
            if (strcmp(dt[i].estilovida,ati) == 0)
                dt[i].tabela = 7;
            if (strcmp(dt[i].estilovida,ma) == 0)
                dt[i].tabela = 8;
        }

        if (dt[i].sexo == 'f')
        {
            if (strcmp(dt[i].estilovida,se) == 0)
                dt[i].tabela = 1;
            if (strcmp(dt[i].estilovida,pa) == 0)
                dt[i].tabela = 2;
            if (strcmp(dt[i].estilovida,ati) == 0)
                dt[i].tabela = 3;
            if (strcmp(dt[i].estilovida,ma) == 0)
                dt[i].tabela = 4;
        }

        i++;
    }



    printf("POR EXCESSO\n\n");

    while ( j < *qtd3)
    {
        if ( (dt[j].dietakcal > 2683) && (dt[j].tabela == 4) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 2683 );
        }
        if ( (dt[j].dietakcal > 2415) && (dt[j].tabela == 3) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 2415 );
        }
        if ( (dt[j].dietakcal > 2147) && (dt[j].tabela == 2) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 2147 );
        }
        if ( (dt[j].dietakcal > 1878) && (dt[j].tabela == 1) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 1878 );
        }
        if ( (dt[j].dietakcal > 3340) && (dt[j].tabela == 8) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 3340 );
        }
        if ( (dt[j].dietakcal > 3006) && (dt[j].tabela == 7) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 3006 );
        }
        if ( (dt[j].dietakcal > 2672) && (dt[j].tabela == 6) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 2672 );
        }
        if ( (dt[j].dietakcal > 2338) && (dt[j].tabela == 5) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Excesso de calorias: %d\n\n", dt[j].dietakcal - 2338 );
        }


        j++;
    }

    j = 0;

    printf("POR DEFEITO\n\n");

    while ( j < *qtd3)
    {
        if ( (dt[j].dietakcal < 2683) && (dt[j].tabela == 4) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 2683 );
        }
        if ( (dt[j].dietakcal < 2415) && (dt[j].tabela == 3) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 2415 );
        }
        if ( (dt[j].dietakcal < 2147) && (dt[j].tabela == 1) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 2147 );
        }
        if ( (dt[j].dietakcal < 1878) && (dt[j].tabela == 1) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 1878 );
        }
        if ( (dt[j].dietakcal < 3340) && (dt[j].tabela == 8) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 3340 );
        }
        if ( (dt[j].dietakcal < 3006) && (dt[j].tabela == 7) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 3006 );
        }
        if ( (dt[j].dietakcal < 2672) && (dt[j].tabela == 6) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 2672 );
        }
        if ( (dt[j].dietakcal < 2338) && (dt[j].tabela == 5) )
        {
            printf("Nome: %s\n",dt[j].nomed);
            printf("Data %d/%d/%d\n",dt[j].data[0],dt[j].data[1],dt[j].data[2]);
            printf("Kcal da dieta: %d\n",dt[j].dietakcal);
            printf("Estilo de vida: %s\n",dt[j].estilovida);
            printf("Defeito de calorias: %d\n\n", dt[j].dietakcal - 2338 );
        }


        j++;
    }

    printf("\n\n");

    system("Pause");
}

void mostrar_tabela(alimento_tipo *al, int *qtd, int escolha) //mostra a tabela com os alimentos do grupo escolhido e kcal por ordem decrescente (Tiago Duarte 22/11)
{
    int i = 0;
    printf("_________________________________\n");
    printf("|Grupo %d                        |\n",escolha);
    printf("_________________________________\n");
    printf("|Alimento               |Kcal   |\n");
    printf("_________________________________\n");
    for(i; i < *qtd; i++)
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


int validar_datas_procura(int d1, int d2, int m1, int m2, int a1, int a2) //Tiago Duarte 25/11
{
    int flag = 0;

    if (a1 < a2)
        flag = 1;
    if ((a1 == a2) && (m1 < m2))
        flag = 1;
    if( (a1 == a2) && (m1 == m2) && (d1 < d2))
        flag = 1;
    if (flag == 0)
    {
        printf("\nDatas Invalidas!\n");
        system("Pause");
        system("cls");
    }

    return flag;
}

void listar_dietas_iguais(dieta_tipo *dt, pessoa_tipo *pt, int *qtd3)//Tiago Duarte 25/11
{
    int d1, d2, m1, m2, a1, a2, i = 0, flag = 0, j = 0, k = 0, maior, menor;

    do
    {
        printf("Procurar dietas iguais entre a data 1 dd/mm/aa/ e  a data 2 dd/mm/aa\n\n");
        printf("Data 1: ");
        scanf("%d %d %d",&d1,&m1,&a1);
        printf("\nData 2: ");
        scanf("%d %d %d",&d2,&m2,&a2);

        flag = validar_datas_procura(d1,d2,m1,m2,a1,a2);
    }
    while (flag != 1);

    menor = a1 * 8766 + m1 * 730.5 + d1 * 24;
    maior = a2 * 8766 + m2 * 730.5 + d2 * 24;


    while ( i < *qtd3)
    {
        dt[i].datasecs = dt[i].data[2] * 8766 + dt[i].data[1] * 730.5 + dt[i].data[0] * 24;

        i++;
    }


    while ( j < *qtd3)
    {

        if ((dt[j].datasecs > menor) && (dt[j].datasecs < maior))
        {

            while (k < *qtd3)
            {

                if ((( dt[k].datasecs > menor) && (dt[k].datasecs < maior) && (dt[k].dietakcal == dt[j].dietakcal) && (k != j)))
                {
                    printf("\nNome: %s",dt[j].nomed);
                    printf("\nSexo: %c",dt[j].sexo);
                    printf("\nEstilo de vida: %s",dt[j].estilovida);
                    printf("\nData da dieta: %d/%d/%d",dt[j].data[0],dt[i].data[1],dt[i].data[2]);
                    printf("\nCalorias ingeridas: %d",dt[j].dietakcal);

                    printf("\n\nDieta semelhante a...\n");

                    printf("\nNome: %s",dt[k].nomed);
                    printf("\nSexo: %c",dt[k].sexo);
                    printf("\nEstilo de vida: %s",dt[k].estilovida);
                    printf("\nData da dieta: %d/%d/%d",dt[k].data[0],dt[j].data[1],dt[j].data[2]);
                    printf("\nCalorias ingeridas: %d\n",dt[k].dietakcal);
                }
                k++;
            }
        }
        j++;
    }

    system("Pause");
}


void balanca_alimentar(dieta_tipo *dt, int *qtd3)//Tiago Duarte 25/11
{
    int i = 0, p1, p2, p3, p4, p5, p6, p7;


    printf("Panorama Alimentar da Populacao");

    while (i < *qtd3)
    {

        p1 = dt[i].grupo_kcal[0] / dt[i].dietakcal * 100;
        p2 = dt[i].grupo_kcal[1] / dt[i].dietakcal * 100;
        p3 = dt[i].grupo_kcal[2] / dt[i].dietakcal * 100;
        p4 = dt[i].grupo_kcal[3] / dt[i].dietakcal * 100;
        p5 = dt[i].grupo_kcal[4] / dt[i].dietakcal * 100;
        p6 = dt[i].grupo_kcal[5] / dt[i].dietakcal * 100;
        p7 = dt[i].grupo_kcal[6] / dt[i].dietakcal * 100;

        printf("\n\n> > > Nome: %s < < <\n", dt[i].nomed);
        printf("Data: %d/%d/%d\n\n",dt[i].data[0],dt[i].data[1],dt[i].data[2]);
        printf("Grupo dos ceriais derivados e tuberculos\n");
        printf("Recomendado: 28% | Real: %d% |", p1);
        if ( p1 <= 28)
            printf("Defice: %d\n\n", 28 - p1);
        else
            printf("Excesso: %d\n\n", p1 - 28);

        printf("Grupo das gorduras e oleos\n");
        printf("Recomendado: 2% | Real: %d% |", p2);
        if ( p2 <= 2)
            printf("Defice: %d\n\n", 2 - p2);
        else
            printf("Excesso: %d\n\n", p2 - 2);

        printf("Grupo das frutas\n");
        printf("Recomendado: 20% | Real: %d% |", p3);
        if ( p3 <= 20)
            printf("Defice: %d\n\n", 20 - p3);
        else
            printf("Excesso: %d\n\n", p3 - 20);

        printf("Grupo dos laticinios\n");
        printf("Recomendado: 18% | Real: %d% |", p4);
        if ( p4 <= 18)
            printf("Defice: %d\n\n", 18 - p4);
        else
            printf("Excesso: %d\n\n", p4 - 18);

        printf("Grupo das carnes pescados e ovos\n");
        printf("Recomendado: 5% | Real: %d% |", p5);
        if ( p5 <= 5)
            printf("Defice: %d\n\n", 5 - p5);
        else
            printf("Excesso: %d\n\n", p5 - 5);

        printf("Grupo das leguminosas\n");
        printf("Recomendado: 4% | Real: %d% |", p6);
        if ( p6 <= 4)
            printf("Defice: %d\n\n", 4 - p6);
        else
            printf("Excesso: %d\n\n", p6 - 4);

        printf("Grupo das horticulas\n");
        printf("Recomendado: 23% | Real: %d% |", p7);
        if ( p7 <= 23)
            printf("Defice: %d\n\n", 23 - p7);
        else
            printf("Excesso: %d\n\n", p7 - 23);

        i++;

    }

    system("Pause");
}



void grafico_barras(dieta_tipo *dt, int *qtd3)//Tiago Duarte 5/12
{
    int i = 0, calmale = 0, calfemale = 0, mediamale, mediafemale, grafmale, graffemale, j = 1, k = 1;

    while (i < *qtd3)
    {
        if (dt[i].sexo == 'm')
        {
            calmale = calmale + dt[i].dietakcal;

            j++;
        }
        else if(dt[i].sexo == 'f')
        {
            calfemale = calfemale + dt[i].dietakcal;
            k++;
        }
        i++;
    }

    i = 0;
    mediamale = calmale / j;
    mediafemale = calfemale / k;



    if(mediafemale < 1980)
        graffemale = 1;
    else if(mediafemale < 2180)
        graffemale = 2;
    else if(mediafemale < 2380)
        graffemale = 3;
    else if(mediafemale < 2580)
        graffemale = 4;
    else if(mediafemale < 2780)
        graffemale = 5;

    if(mediamale < 2240)
        grafmale = 1;
    else if(mediamale < 2440)
        grafmale = 2;
    else if(mediamale < 2840)
        grafmale = 3;
    else if(mediamale < 3040)
        grafmale = 4;
    else if(mediamale < 3240)
        grafmale = 5;


    printf("\n          |");
    printf("\n");
    printf("Masculino |");

    while(i < grafmale * 4 )
    {
        printf("O");
        i++;
    }
    i = 0;

    printf("\n");
    printf("          |");
    printf("\n");
    printf("          |");
    printf("\n");
    printf("Feminino  |");
    while(i < graffemale * 4)
    {
        printf("O");
        i++;
    }
    printf("\n");
    printf("          |");
    printf("\n");
    printf("          |");
    printf("\n");
    printf("          |___|___|___|___|___|__");
    printf("\n");
    printf("              1   2   3   4   5");
    printf("\n");

    printf("\n");
    printf("\nLegenda\n\n1- A populacao nao tem energia\n2- A populacao tem pouca energia\n3- A populacao apresenta energia suficiente\n4- A populacao tem bastante energia\n5- A populacao apresenta muita energia\n\n");
    system("Pause");
}
void listar_ali(dieta_tipo *dt, alimento_tipo *al, int *qtd3, int *qtd, pessoa_tipo *pt, int *qtd2) //Tomás Coelho 5/11
{
    int a;
    char gen;
    char h[20];
    int i;
    int k;
    int m;
    int j;
    int c;
    int t;
    int d;
    float e;
    float f;
    float g;
    a=0;
    c=0;
    d=0;
    e=0;
    f=0;
    g=0;
    int b[i];
    i=0;
    int alitotal;
    alitotal=0;

    do
    {
        printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f): ");
        scanf(" %c",&gen);
    }
    while ( (gen != 'm' ) && ( gen != 'f'));
    if ( *qtd3 != 0)
    {
    printf("_____________________________________________________________________\n");
    printf("|Sexo: %c                                                             |\n",gen);



    for(i=0; i<*qtd3; i++)
    {
        if(dt[i].sexo!=gen) {}

        for(k=0; k<=4; k++)
        {

            for(m=0; m<dt[i].quantalim[k]; m++)
            {

                alitotal++;
                if(dt[i].quantalim[k]==0) {}

                for(j=0; j<=*qtd; j++)
                {
                    a=strcmp(dt[i].limao[k][m],al[j].nome);

                    if(a==0)
                    {
                        b[j]++;
                    }
                }


            }
        }
    }


    for(t=0; t <= *qtd; t++)
    {

        if(b[t] < b[t+1])
        {


            d=b[t+1];
            b[t+1]=b[t];
            b[t]=d;
            strcpy(h, al[t+1].nome);
            strcpy(al[t+1].nome, al[t].nome);
            strcpy(al[t].nome, h);
        }
    }



    e=((b[0]*100)/alitotal);
    f=((b[1]*100)/alitotal);
    g=((b[2]*100)/alitotal);

    printf(" %.1f", e);
    printf(" %s", al[0].nome);
    printf("\n %.1f", f);
    printf(" %s", al[1].nome);
    printf("\n %.1f", g);
    printf(" %s", al[2].nome);
    }
    else
        system("cls");
        printf("Nao ha dietas no sistema!");
        printf("\n\n");

    system("Pause");
}

void ordenar_data(dieta_tipo *dt, alimento_tipo *at, int *qtd3, int *qtd) //Tomás Coelho 5/12
{

    int i;
    int a;
    a=0;
    for(i=0; i < *qtd3; i++)
    {

        if(dt[i].data[2] > dt[i+1].data[2])
        {

            a = dt[i+1].data[2];
            dt[i+1].data[2] = dt[i].data[2];
            dt[i].data[2] = a;
        }
        if(dt[i].data[2] == dt[i+1].data[2] && dt[i].data[1] > dt[i+1].data[1])
        {

            a = dt[i+1].data[1];
            dt[i+1].data[1] = dt[i].data[1];
            dt[i].data[1] = a;

        }
        if(dt[i].data[2] == dt[i+1].data[2] && dt[i].data[1] == dt[i+1].data[1] && dt[i].data[0] > dt[i+1].data[0])
        {
            a = dt[i+1].data[0];
            dt[i+1].data[0] = dt[i].data[0];
            dt[i].data[0] = a;
        }
    }
}

int	submenu_4(int *qtd2, int *qtd, pessoa_tipo *pt, alimento_tipo *at, dieta_tipo *dt, int *qtd3)//Tiago Duarte e Tomas Coelho 5/11
{
    char    op;
    do
    {
        do
        {
            system ("cls");
            printf("Menu Estatisticas\n\n");
            printf("1 ... Balança alimentar da populacao registada\n");
            printf("2 ... Listagem dos alimentos mais consumidos por pessoa em funcao do sexo\n");
            printf("3 ... Grafico com o nivel de Kcal Total e por sexo da populacao registada\n");
            printf("0 ... Voltar ao menu principal\n\n");
            printf("Selecionar opcao: ");
            scanf(" %c", &op);
        }
        while(op!='0' && op!='1' && op!='2' && op!='3');

        switch (op)
        {
        case '1':

            system("cls");
            balanca_alimentar(dt,qtd3);
            break;

        case '2':
            system("cls");
            listar_ali(dt,at,qtd3,qtd,pt,qtd2);
            break;

        case '3':

            system("cls");
            grafico_barras(dt,qtd3);
            break;

        }
    }
    while (op != '0');
    system("PAUSE");
    return 0;

}

int	submenu_3(int *qtd2, int *qtd, pessoa_tipo *pt, alimento_tipo *at,dieta_tipo *dt, int *qtd3)//Tomas Coelho e Tiago Duarte 22/11
{
    char    op;
    do
    {
        do
        {
            system ("cls");
            printf("Menu Gestao de Dietas\n\n");;
            printf("1 ... Registar Dieta de uma pessoa\n");
            printf("2 ... Listar Pessoas com dietas fora do padrao\n");
            printf("3 ... Listar Pessoas com dietas iguais\n");
            printf("4 ... Consultar dieta de determinada Pessoa\n");
            printf("0 ... Voltar ao menu principal\n\n");
            printf("Selecionar opcao: ");
            scanf(" %c", &op);
        }
        while(op!='0' && op!='1' && op!='2' && op!='3' && op!='4');

        switch (op)
        {
        case '1':

            system("cls");
            inserir_dietas(dt,at,qtd3,qtd,pt,qtd2);
            break;

        case '2':

            system("cls");
            listar_dieta_fora_padrao(dt,at,qtd3,qtd,pt,qtd2);
            break;

        case '3':

            system("cls");
            listar_dietas_iguais(dt,pt,qtd3);
            break;

        case '4':

            system("cls");
            ordenar_data(dt,at,qtd3,qtd);
            mostrar_dietas(pt,dt,at,qtd3,qtd,qtd2);
            break;

        }
    }
    while (op != '0');
    system("PAUSE");
    return 0;

}


int	submenu_2(int *qtd, alimento_tipo *al)//Tomas Coelho e Tiago Duarte 7/11
{
    int		escolha;
    char 		op;


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

            system("cls");
            inserir_alimentos(al, qtd);
            sort_structs(al, qtd);
            break;

        case '2':

            system("cls");
            estimar_valor_kcal(al,qtd);
            break;

        case '3':

            system("cls");
            sort_structs_by_kcal(al, qtd);
            escolha = listar_grupo();
            system("cls");
            printf("\n");
            mostrar_tabela(al, qtd,escolha);
            break;

        case '4':

            system("cls");
            sort_structs(al, qtd);
            mostrar_alimentos(al,*qtd);
            break;

        }
    }
    while(op!='0');
    printf("\n");
    system("PAUSE");
    return 0;
}


int	submenu_1(int *qtd2, pessoa_tipo *pt)//Tomas Coelho e Tiago Duarte 7/11
{
    char		op;

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

            system("cls");
            inserir_pessoas(pt,qtd2);
            break;

        case '2':

            system("cls");
            eliminar_pessoas(pt,qtd2);
            break;

        case '3':

            system("cls");
            ordenar_pessoas(pt,qtd2);
            system("PAUSE");
            break;

        case '4':

            system("cls");
            sort_structs_pessoas(pt,*qtd2);
            mostrar_pessoas(pt,*qtd2);
            break;

        }
    }
    while (op != '0');
    system("PAUSE");
    return 0;
}




int	main(void) //Tomas Coelho e Tiago Duarte 5/12
{
    int		qtd = 0, qtd2 = 0, qtd3 = 0; //variáveis utilizadas ao longo de todo o programa
    char		op;
    pessoa_tipo	    pt[MAX_PESSOAS];
    alimento_tipo	al[MAX_ALIMENTOS];
    dieta_tipo      dt[MAX_DIETAS];

    inicializar_alimentos(al,&qtd);
    inicializar_pessoas(pt, &qtd2);


    do
    {
        do
        {
            system ("cls");
            printf("MENU PRINCIPAL\n\n");
            printf("1 ... Gestao de Pessoas\n");
            printf("2 ... Gestao de Alimentos\n");
            printf("3 ... Gestao de Dietas\n");
            printf("4 ... Estatistica\n");
            printf("0 ... Sair\n");
            printf("\nSelecionar opcao: ");
            scanf(" %c", &op);
        }
        while (op != '0' && op != '1' && op != '2' && op != '3' && op != '4');

        switch (op)
        {
        case '1':
            submenu_1(&qtd2,pt);
            break;

        case '2':
            submenu_2(&qtd,al);
            break;

        case '3':
            submenu_3(&qtd2,&qtd,pt,al,dt,&qtd3);
            break;

        case '4':
            submenu_4(&qtd2,&qtd,pt,al,dt,&qtd3);
            break;
        }
    }
    while (op != '0');

    printf("\n");
    system("PAUSE");
    return 0;
}
