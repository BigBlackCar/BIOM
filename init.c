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
