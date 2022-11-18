#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_PESSOAS 10
#include <locale.h>

//typedef enum
//{
// sedentario=1,
//pouco ativo=2,
// ativo=3,
// muito ativo=4,//

//}estilo_tipo;//

typedef struct
{
    char nome[26];
    int peso;
    char sexo[20];
    int altura;
    int estilo;

    char est[30];
    int idade;
    float imc;
} pessoa_tipo;

void ordenar_pessoas(pessoa_tipo al[], int *qtd){
int i;
char genero[2];

i=0;

   do{
    printf("Insira de que sexo sao as pessoas que quer apresentar(m ou f):");
scanf("%s", &genero);

        if( strcmp( al[i].sexo, genero )==0 )
        {

        printf("\nNome:%s",al[i].nome);
        printf("\nIdade:%d",al[i].idade);
        printf("\nAltura:%dcm",al[i].altura);
        printf("\nEstilo de vida:%s",al[i].est);
        printf("\nPeso:%dkg",al[i].peso);
        printf("\nIMC=%.2f",al[i].imc);
        printf("\n");

 i++;

        } while( i<*qtd );


        }while(genero!='m' && genero!='f');


}

void sort_structs(pessoa_tipo *al, int *len)
{
    int         w=0, changed;
    pessoa_tipo    temp;
    do
    {
        changed = 0;
        for (w=0; w < (*len) - 1; w++)
        {
            if (strcmp(al[w].nome, al[w+1].nome) > 0)
            {
                memcpy(&temp, al + w, sizeof (pessoa_tipo));
                memcpy(al + w, al + w + 1, sizeof (pessoa_tipo));
                memcpy(al + w + 1, &temp, sizeof (pessoa_tipo));
                changed = 1;
            }
        }
    }
    while (changed != 0);
}
void inicializar_pessoas(pessoa_tipo al[], int *qtd)
{
    strcpy(al[0].nome,"cristiano diniz");
    al[0].peso=72;  ///deve ser um enumerado
    al[0].altura=172;
    al[0].idade=18;
    strcpy(al[0].sexo,"M");
    strcpy(al[0].est,"ativo");
    al[0].imc=24;

    strcpy(al[1].nome,"joel silva");
    al[1].peso=72;  ///deve ser um enumerado
    al[1].altura=176;
    al[1].idade=18;
    strcpy(al[1].sexo,"M");
    strcpy(al[1].est,"ativo");
    al[1].imc=23;

    strcpy(al[2].nome,"cristina ferreira ");
    al[2].peso=70;  ///deve ser um enumerado
    al[2].altura=170;
    al[2].idade=45;
    strcpy(al[2].sexo,"F");
    strcpy(al[2].est,"pouco ativo");
    al[2].imc=24;

    strcpy(al[3].nome,"cristiano ronaldo");
    al[3].peso=72;  ///deve ser um enumerado
    al[3].altura=172;
    al[3].idade=18;
    strcpy(al[3].sexo,"M");
    strcpy(al[3].est,"muito ativo");
    al[3].imc=24;
    *qtd=4;
}
void eliminar_pessoas(pessoa_tipo al[], int *qtd)
{
    int t;
    char eli[50];

    printf("Insira o nome da pessoa que quer eliminar:");
    scanf("%s", &eli);

    t=0;
    while( t<*qtd )
    {
        if( strcmp( al[t].nome, eli )==0 )
        {



            system ("cls");
            printf("Encontrado!\n\n");

            memset(al[t].nome,'\0',50);
            memset(al[t].estilo,'\0',50);
            memset(al[t].sexo,'\0',50);
            al[t].estilo=0;
            al[t].idade=0;
            al[t].imc=0;
            al[t].peso=0;

            system("Pause");

            break;
        }
        else if( t == *qtd )
        {
            printf("Não está na lista\n\n");
        }
        t++;
    }

}
void inserir_pessoas(pessoa_tipo al[], int *qtd)
{

    printf("Insira o nome da pessoa:");
    scanf("%s", &al[*qtd].nome);
    printf("Insira o peso da pessoa:");
    scanf("%d", &al[*qtd].peso);
    printf("Insira a altura da pessoa em cm:");
    scanf("%d", &al[*qtd].altura);
    printf("Insira a idade da pessoa:");
    scanf("%d", &al[*qtd].idade);
    al[*qtd].imc=al[*qtd].peso/((al[*qtd].altura*0,01)*(al[*qtd].altura*0,01));
    printf("Insira o sexo da pessoa(m ou f):");
    scanf("%s", &al[*qtd].sexo);
    printf("Insira o estilo de vida da pessoa: \n1-Sedentario\n2-Pouco ativo\n3-Ativo\n4-Muito ativo");
    scanf("%d", &al[*qtd].estilo);
    switch (al[*qtd].estilo)
    {
    case '1':
    {
        strcpy(al[*qtd].est,"Sedentario");
        break;
    }
    case '2':
    {
        strcpy(al[*qtd].est,"Pouco ativo");
        break;
    }
    case '3':
    {
        strcpy(al[*qtd].est,"Ativo");
        break;
    }
    case '4':
    {
        strcpy(al[*qtd].est,"Muito ativo");
        break;
    }

    }
    *qtd=*qtd+1;
}

void mostrar_pessoas(pessoa_tipo al[], int qtd)
{
    int i;
    float imc;
    for(i=0; i<qtd; i++)
    {

        printf("\nNome:%s",al[i].nome);
        printf("\nIdade:%d",al[i].idade);
        printf("\nAltura:%dcm",al[i].altura);
        printf("\nSexo:%s",al[i].sexo);
        printf("\nEstilo de vida:%s",al[i].est);
        printf("\nPeso:%dkg",al[i].peso);
        printf("\nIMC=%.2f",al[i].imc);
        printf("\n");
    }

    system("Pause");
}

int main()
{
    pessoa_tipo al[MAX_PESSOAS];
    int qtd=0;

    inicializar_pessoas(al, &qtd);


    char op;
    do
    {
        do
        {
            system ("cls");
            printf("           Menu - Pessoas\n");
            printf("-----------------------------------------------\n");
            printf("Insira a opçao que deseja:\n");
            printf(" 1 - Inserir pessoa\n");
            printf(" 2 - Remover pessoa\n");
            printf(" 3 - Mostrar pessoas ordenadas por sexo e estilo de vida\n");
            printf(" 4 - Listar todas as pessoas por ordem alfabetica\n");
            printf(" 0 - Voltar ao menu principal\n");
            op=getch();
        }
        while(op!='s' && op!='S' && op!='1' && op!='2' && op!='3' && op!='4' && op!='0');

        switch (op)
        {
        case '1':
        {
            system ("cls");
            inserir_pessoas(&al,&qtd);
            break;
        }
        case '2':
        {
            system ("cls");
            eliminar_pessoas(&al,&qtd);
            break;
        }
        case '3':
        {
            system ("cls");
            ordenar_pessoas(&al,&qtd);
            break;
        }
        case '4':
        {
            system ("cls");
            sort_structs(al,&qtd);
            mostrar_pessoas(al,qtd);
            break;
        }
        case '0':
        {
            sort_structs(al,&qtd);
            mostrar_pessoas(al,qtd);
            break;
        }
        }
    }
    while(op!='s' && op!='S');

    system("PAUSE");
    return 0;
}
