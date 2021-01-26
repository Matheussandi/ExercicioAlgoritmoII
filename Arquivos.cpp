#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>

struct pessoa {
		
		char NOME[300], EMAIL[300], TEL[300];
		
	};

main ()

{
	setlocale (LC_ALL, "Portuguese");
	
	struct pessoa lista;
	
	int OP,CONT;
	
	do {
	
	printf ("\nIncluir novos registros		[Digite - 1]\n");
	printf ("Listar todos registros  	[Digite - 2]\n");
	printf ("Remover o Arquivo  		[Digite - 3]\n");
	printf ("\nEscolha uma operação: ");
	scanf ("%i", & OP);
	
		if (OP > 3 || OP <= 0) {
		printf ("\nValor inválido, tente novamente mais tarde");
		return 0;
	}
	
	switch (OP) {
	
	case 1:
		
		FILE *ARQ;	
		
		if ((ARQ=fopen ("cadastro.txt", "w")) != NULL) {
			for (int i=0; i<300; i++) {
				
				printf ("\nEntre com o nome: ");
				scanf("%s", & lista.NOME);
				fprintf(ARQ,"Nome %d: %s\n", i+1,lista.NOME);
				
				printf ("Entre com o telefone: ");
				scanf("%s", & lista.TEL);
				fprintf(ARQ,"Telefone %i: %s\n", i+1,lista.TEL);
				
				printf ("Entre com o email: ");
				scanf("%s", & lista.EMAIL);
				fprintf(ARQ,"Email %d: %s\n", i+1,lista.EMAIL);
				
				printf ("Adicionar mais um registro (0 - sai)?");
				scanf ("%i", & CONT);
				
			if (CONT == 0) {
				break;
			}
			
			}
			
		}
		
		printf ("\nArquivo criado com sucesso\n");
		
		fclose(ARQ);
		
		break;
		
	case 2:
		printf ("\n");
		
		ARQ = fopen("cadastro.txt","r");
		
		while (fgets(lista.NOME, 10, ARQ) != NULL)
			printf ("%s", lista.NOME);
			
		fclose(ARQ);
		break;
		
	case 3:
		remove ("cadastro.txt");
		printf ("\nArquivo excluído\n");
		
		break;
		
	}	
	
	do {
	
	printf ("\nDeseja voltar ao menu [1 - sim e 2 - não] ?");
	scanf ("%i", & CONT);
	
	} while (CONT != 2 && CONT != 1);
		
	} while (CONT == 1);
	
	getch();
}
