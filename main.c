# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_ALIMENTOS 10
# define MAX_PESSOAS 10
# define MAX_DIETAS 10
# define MAX_REFEICOES 10

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

typedef enum //varievel grupo tipo enumerado
{
    pequeno_almoco=0,
    almoco,
    lanche,
    jantar,
    seia,
} numref_tipo;

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
    char 	sexo[30];
    char 	nome[100];
    float 	imc;
    estilo_tipo estilo;
} pessoa_tipo;


typedef struct dieta
{
    char nomed[26];
    int data[3];
    int numref;
    int quantali;
    
    int somakcal;
} dieta_tipo;


void	inicializar_alimentos(alimento_tipo *al, int *qtd) //adiciona os alimentos base ao programa
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

void	inicializar_pessoas(pessoa_tipo pt[], int *qtd2) //adiciona as pessoas base ao programa
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
    strcpy(pt[1].est,"Ativo");
    pt[1].imc=23;

    strcpy(pt[2].nome,"Cristina Ferreira");
    pt[2].peso=70;
    pt[2].altura=170;
    pt[2].idade=45;
    strcpy(pt[2].sexo,"f");
    strcpy(pt[2].est,"Pouco ativo");
    pt[2].imc=24;

    strcpy(pt[3].nome,"Cristiano Ronaldo");
    pt[3].peso=72;
    pt[3].altura=172;
    pt[3].idade=18;
    strcpy(pt[3].sexo,"m");
    strcpy(pt[3].est,"Muito ativo");
    pt[3].imc=24;
    *qtd2=4;
}
int validar_grupo(int *num)
{
    int flag;

    if ((*num = 1) || (*num = 2) || (*num = 3) || (*num = 4) || (*num = 5) || (*num = 6) || (*num = 7))
        flag = 1;
    else
        flag = 0;

    return (flag);
}

void inserir_alimentos(alimento_tipo *al, int *qtd)  //permite adicionar um novo alimento que ainda não exista
{
    if (*qtd < MAX_ALIMENTOS)
    {
        printf("Alimento %d\n", *qtd);
        printf("Nome=");
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

void inserir_pessoas(pessoa_tipo *pt, int *qtd2)// inserir novas pessoas
{
    char f[]="f";
    char m[]="m";
    printf("Insira o nome da pessoa:");
    scanf(" %[^\n]", pt[*qtd2].nome);
    printf("Insira o peso da pessoa:");
    scanf("%d", &pt[*qtd2].peso);
    printf("Insira a altura da pessoa em cm:");
    scanf("%d", &pt[*qtd2].altura);
    printf("Insira a idade da pessoa:");
    scanf("%d", &pt[*qtd2].idade);
    pt[*qtd2].imc = pt[*qtd2].peso / ((pt[*qtd2].altura*(0.01)) * (pt[*qtd2].altura*(0.01)));
    do
    {
        printf("Insira o sexo da pessoa(m ou f):");
        scanf("%s", (char *)&pt[*qtd2].sexo);
    }
    while (((strcmp((char *)&pt[*qtd2].sexo, m)) != 0 ) && ((strcmp((char *)&pt[*qtd2].sexo, f ))!= 0));  //verifica se o sexo é valido
    printf("Insira o estilo de vida da pessoa: \n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo\n");
    scanf("%d", (int *)&pt[*qtd2].estilo);
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

void inserir_dietas(dieta_tipo *dt, refeicao_tipo *rt, alimento_tipo *at, int *qtd3)
{

    int i;

    printf("Nome: ");
    scanf(" %[^\n]", dt[i].nomed);
    //verificação se o nome existe
    printf("Data da refeicao(dd mm aa): ");
    scanf("%d %d %d",&dt[i].data.dia,&dt[i].data.mes,&dt[i].data.ano);
    system("cls");
    printf("Pequeno Almoco\n");
    printf("Quantidade de alimentos que ingeriu: ");
    scanf("%d",&dt[*qtd3].quantali);
    do
    {
        printf("Nome do alimento que ingeriu:");
        scanf("")
    }



        system("Pause");
}


void estimar_valor_kcal(alimento_tipo *al)  //calcula as calorias de uma refeição atraves de alimentos ingeridos e as respetivas quantidades (TD)
{
    int num, somacal=0, i=0, quant, numalim; //variáveis necessarias para o cálculo

    do
    {
        printf("Numero do alimento que ingeriu (-1 para parar):"); //inserir -1 acaba o ciclo e calcula a kcal dos alimentos introduzidos
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


void sort_structs_pessoas(pessoa_tipo *pt, int len)//ordena os nomes por ordem alfabetica
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


void eliminar_pessoas(pessoa_tipo *pt, int *qtd2)// eliminar pessoas
{
    int t=0, flag = 0, max;
    char z[]="zzzzzzz"; //string com valor zzzzzzz
    char *eli;
    eli = (char *)malloc(sizeof(char) * 80 + 1); //aloca espaço para a string dependendo da quantidade de caracteres inseridos
    printf("Insira o nome da pessoa que quer eliminar:");
    scanf(" %[^\n]", eli); //lê o inserido ate a mudança de linha
    max = *qtd2;
    do
    {
        if( strcmp( pt[t].nome, eli ) == 0 )//compara o nome escrito pelo utilizador com todos os nomes no programa
        {
            system ("cls");
            strcpy(pt[t].nome,z);
            sort_structs_pessoas(pt,*qtd2); //passa a pessoa com o nome inserido para ultimo pois agora chama-se zzzzz
            *qtd2 = (*qtd2) - 1;//apaga o ultimo elemento da lista de nomes
            system("PAUSE");
            flag = 1;
            break;
        }
        t++;
    }
    while( t < max );
    if (flag == 0)
        printf("Nao esta na lista\n\n"); //caso o nome introduzido não esteja na lista, a flag continua em 0 e faz o print
    system("Pause");
}

void    calc_imc_male(pessoa_tipo pt, char *str) //calcula o imc da pessoa baseado no sexo
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

void    calc_imc_female(pessoa_tipo pt, char *str) //calcula o imc da pessoa baseado no sexo
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


void ordenar_pessoas(pessoa_tipo pt[], int *qtd2) // ordenar as pessoas pelo sexo pedido pelo utilizador
{
    int i;//variavel numerica
    char gen[2];//variavel pedida ao utilizador para comparar com o sexo das pessoas no sistema
    char pool[100];
    i=0;

    printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
    scanf(" %s", gen);
    if (gen[0] == 'm' || gen[0] == 'f') //verifica se o genero é valido
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
        printf("Sexo invalido!");
}

void sort_structs_by_kcal(alimento_tipo *al, int *len) //ordena as structs por ordem decrescente das kcal dos alimentos (TD)
{
    int         i, changed; //variavel numerica e variavel que funciona como uma flag
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

void sort_structs(alimento_tipo *al, int *len) //Organiza as structs por ordem alfabética (Creditos a Scheneizer do 1º ano de informática)
{
    int 		i, changed; //variavel numerica e variavel que funciona como uma flag
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



void	mostrar_alimentos(alimento_tipo *al, int qtd)  //mostra todos os alimentos e os respetivos atributos
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

void mostrar_pessoas(pessoa_tipo *pt, int qtd2)//mostra todas as pessoas ja inseridas no sistema
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

int listar_grupo(void) //escolher o numero do grupo que sera listado
{
    int escolha;
    printf("Qual o grupo que pretende listar?\n\n1 - ceriais derivados e tuberculos\n2 - gorduras e oleos\n3 - fruta\n4 - laticinios\n5 - carnes pescados e ovos\n6 - leguminosas\n7 - horticulas");
    printf("\n\nSelecionar opcao: ");
    scanf("%d",&escolha);
    return (escolha);
}

void mostrar_tabela(alimento_tipo *al, int *qtd, int escolha)  //mostra a tabela com os alimentos do grupo escolhido e kcal por ordem decrescente
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

void necessidade_energetica(int somakcaltot)
{

    system("Pause");
}


/*void listar_dietas_fora_do_padrao(dieta_tipo *dt, refeicao_tipo *rt, pessoa_dieta_tipo *pdt, int *qtd3)
{
    int i = 0, somakcaltot = 0;

    for (i; i < *qtd3; i++)
    {
        somakcaltot = pdt[i].dieta.somakcal + somakcaltot;
        necessidade_energetica(somakcaltot);
    }





    //for (i; i < dt[i].numdieta)
    system("Pause");
}*/

/*int validar_nome_alimento(alimento_tipo at, int *qtd, alimento_tipo *nomealim)
{
    int flag = 0, i = 0;
    do
    {
        if (strcmp((at[i].nome,*nomealim)) == 0)
            flag = 1;
        else
            flag = 0;

    }while( i < *qtd );

  return flag;
}*/

int	submenu_3(int *qtd2, int *qtd, pessoa_tipo *pl,alimento_tipo *at,dieta_tipo *dt,refeicao_tipo *rt)
{
    char    op;
    int qtd3 = 0;
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
            inserir_dietas(dt,rt,at,&qtd3);
            break;

        /*case '2':

            system("cls");
            listar_dietas_fora_do_padrao(dt,rt,&qtd3);
            break;*/

            /*case '3':

                system("cls");
                ordenar_pessoas(pt,qtd2);
                system("PAUSE");
                break;

            case '4':

                system("cls");
                listar_dietas_fora_do_padrao(dt,rt,pdt,&qtd3);
                break;*/

        }
    }
    while (op != '0');
    system("PAUSE");
    return 0;

}


int	submenu_2(int *qtd, alimento_tipo *al)
{
    int		escolha;
    char 		op;

    inicializar_alimentos(al,qtd);
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
            estimar_valor_kcal(al);
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


int	submenu_1(int *qtd2, pessoa_tipo *pt)
{
    char		op;

    inicializar_pessoas(pt, qtd2);
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




int	main(void)
{
    int		qtd = 0, qtd2 = 0; //variáveis utilizadas ao longo de todo o programa
    char		op;
    pessoa_tipo	    pt[MAX_PESSOAS];
    alimento_tipo	al[MAX_ALIMENTOS];
    dieta_tipo      dt[MAX_DIETAS];
    refeicao_tipo   rt[MAX_REFEICOES];

    do
    {
        do
        {
            system ("cls");
            printf("MENU PRINCIPAL\n\n");
            printf("1 ... Gestao de Pessoas\n");
            printf("2 ... Gestao de Alimentos\n");
            printf("3 ... Gestao de Dietas\n");
            printf("0 ... Sair\n");
            printf("\nSelecionar opcao: ");
            scanf(" %c", &op);
        }
        while (op != '0' && op != '1' && op != '2' && op != '3' /*&& op != '4'*/);

        switch (op)
        {
        case '1':
            submenu_1(&qtd2,pt);
            break;

        case '2':
            submenu_2(&qtd,al);
            break;

        case '3':
            submenu_3(&qtd2,&qtd,pt,al,dt,rt);
            break;
        }
    }
    while (op != '0');

    printf("\n");
    system("PAUSE");
    return 0;
}
