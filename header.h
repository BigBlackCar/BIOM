#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define MAX_ALIMENTOS 10
# define MAX_PESSOAS 10

typedef enum
{
	sedentario=1,
	pouco_ativo,
	ativo,
	muito_ativo,
} estilo_tipo;

typedef enum
{
	ceriais_derivados_e_tuberculos=1,
	gorduras_e_oleos,
	fruta,
	laticinios,
	carnes_pescados_e_ovos,
	leguminosas,
	horticulas,
} grupo_tipo;

typedef struct  alimentos
{
	int	kcal;
	int	peso;
	int	unidade;
	char	nome[26];
	grupo_tipo grupo;
} alimento_tipo;

typedef struct pessoas
{
	int 	peso;
	int 	idade;
	int 	altura;
	char 	est[30];
	char 	sexo[20];
	char 	nome[100];
	float 	imc;
	estilo_tipo estilo;
} pessoa_tipo;

//info.c
void	inicializar_alimentos(alimento_tipo *al, int *qtd);
void	inicializar_pessoas(pessoa_tipo pt[], int *qtd2);
void 	inserir_alimentos(alimento_tipo *al, int *qtd);
void 	inserir_pessoas(pessoa_tipo *pt, int *qtd2);
void 	estimar_valor_kcal(alimento_tipo *al);
void 	eliminar_pessoas(pessoa_tipo *pt, int *qtd2);

//sort.c
void	ordenar_pessoas(pessoa_tipo pt[], int *qtd2);
void	sort_structs_by_kcal(alimento_tipo *al, int *len);
void	sort_structs(alimento_tipo *al, int *len);
void	sort_structs_pessoas(pessoa_tipo *pt, int len);

//print.c
int 	listar_grupo(void);
void	mostrar_alimentos(alimento_tipo *al, int qtd);
void 	mostrar_pessoas(pessoa_tipo *pt, int qtd2);
void 	mostrar_tabela(alimento_tipo *al, int *qtd, int escolha);

#endif
