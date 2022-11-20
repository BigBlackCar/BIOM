#include "header.h"

int	submenu_2(void)
{
	int		qtd = 0, escolha;
	char 		op;
	alimento_tipo 	al[MAX_ALIMENTOS];

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
			
			    system("cls");
			    inserir_alimentos(al,&qtd);
			    sort_structs(al,&qtd);
			    break;
			
			case '2':
			
			    system("cls");
			    estimar_valor_kcal(al);
			    break;
			
			case '3':
			
			    system("cls");
			    sort_structs_by_kcal(al,&qtd);
			    escolha = listar_grupo();
			    system("cls");
			    printf("\n");
			    mostrar_tabela(al,&qtd,escolha);
			    break;
			
			case '4':
			
			    system("cls");
			    sort_structs(al,&qtd);
			    mostrar_alimentos(al,qtd);
			    break;
			
		}
	}
	while(op!='0');
	printf("\n");
	system("PAUSE");
	return 0;
}



int	submenu_1(void)
{
	int		qtd2 = 0;
	char		op;
	pessoa_tipo 	pt[MAX_PESSOAS];

	inicializar_pessoas(pt,&qtd2);
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
			inserir_pessoas(pt,&qtd2);
		    break;

		case '2':

		    system("cls");
		    eliminar_pessoas(pt,&qtd2);
		    break;

		/*case '3':

		    system("cls");
		    ordenar_pessoas(pt,&qtd2);
		*/
		case '4':

		    system("cls");
		    sort_structs_pessoas(pt,qtd2);
		    mostrar_pessoas(pt,qtd2);

		}
	}
	while (op != '0');
	system("PAUSE");
	return 0;
}


int	main(void)
{
	char		op;
	pessoa_tipo	al[MAX_PESSOAS];
	alimento_tipo	pt[MAX_ALIMENTOS];

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
		while (op != '0' && op != '1' && op != '2' && op != '3' && op != '4');

		switch (op)
		{
			case '1':
				submenu_1();
				break;

			case '2':
				submenu_2();
				break;
		}
	}
	while (op != '0');
	printf("\n");
	system("PAUSE");
	return 0;
}
