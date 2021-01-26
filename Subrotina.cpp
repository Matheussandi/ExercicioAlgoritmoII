#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

float RC(float N1) {
	float resultado;
	resultado = cbrt(N1); // ou pow(N1, (float)1/3)
	return (resultado);
}

float AT(float BASEMAI, float BASEMEN, float ALT) {
	float AREA;		
	AREA =((BASEMAI + BASEMEN)*ALT)/2;
	return (AREA);
}

float VC (float R, float ALT,float PI) {
	float V;
	V = PI*pow(R,2)*ALT;
	return (V);
}

float AE (float R, float PI) {
	float AREA;
	AREA = 4*PI*pow(R,2);
	return (AREA);
}

float VE (float R, float PI) {
	float V;
	V = (4*PI*pow(R,3))/3;
	return (V);
}

main ()

{
	setlocale (LC_ALL, "Portuguese");
	
	int ESCOLHA;
	float BASEMAI, BASEMEN, AREA, ALT, V1, RESULTADO, PI,R,V;
	
	printf ("Raiz Cúbida        [digite 1]\n");
	printf ("Área do Trapézio   [digite 2]\n");
	printf ("Volume do Cilindro [digite 3]\n");
	printf ("Área da Esfera     [digite 4]\n");
	printf ("Volume da Esfera   [digite 5]\n");
	printf ("Sair               [digite 6]\n");
	printf ("\nEntre com a opção desejada: ");
	scanf ("%i", & ESCOLHA);
	
	if (ESCOLHA > 6 || ESCOLHA < 1) {
		printf ("\nValor inválido, tente novamente mais tarde");
	}
	
	switch (ESCOLHA) {
	
	case 1:
		printf ("\nEntre com o primeiro valor: ");
		scanf ("%f", & V1);
		
		RESULTADO = RC(V1);
		
		printf("Resultado = %.2f", RESULTADO);
		break;
	
	case 2:
		
		printf ("\nEntre com a base maior do trapézio: ");
		
		do {
			scanf ("%f", & BASEMAI);
			if (BASEMAI <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n");
				printf ("\nEntre com a base maior do trapézio: ");
			} 
		} while (BASEMAI <= 0);
		
		printf ("Entre com a base menor do trapézio: ");
		
		do {
			scanf ("%f", & BASEMEN); 	
			if (BASEMEN > BASEMAI || BASEMEN == BASEMAI) { 
				printf ("Valor inválido ! A base menor deve possuir um valor menor que a base maior.\n\n");
				printf ("Entre com a base menor do trapézio: ");
			}
			
			if (BASEMEN <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n\n");
				printf ("Entre com a base menor do trapézio: ");
			}
		} while (BASEMEN > BASEMAI || BASEMEN <= 0 || BASEMEN == BASEMAI);
		
		do {	
			if (BASEMEN < BASEMAI && BASEMEN > 0) {
				printf ("Entre com a altura: "); //colocar um repita caso seja <=0
				scanf("%f", & ALT);
			} 
		} while (ALT <= 0);
		
		AREA = AT(BASEMAI, BASEMEN, ALT);
		
		printf ("\nA área do trapézio é: %.2f ", AREA);
		
		break;
		
	case 3:
		printf ("\nEntre com valor do raio: ");
	
		do {
			scanf("%f", & R);
			if (R <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n");
				printf ("\nEntre com valor do raio: ");
			} 
		} while (R <= 0);
		
		
		printf ("Entre com valor da altura: ");
		
		do {
			scanf ("%f", & ALT);
			if (ALT <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n");
				printf ("\nEntre com valor da altura: ");
			}
		} while (ALT <= 0);
		
		
		V = VC(R, ALT, PI=3.14);
		
		printf ("O volume será = %.2f", V);
		
		break;
		
	case 4:
		printf ("\nEntre com valor do raio: ");
		
		do {
			scanf("%f", & R);
			if (R <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n");
				printf ("\nEntre com valor do raio: ");
			} 
		} while (R <= 0);
			
			AREA = AE(R, PI=3.14);
			
			printf ("A área da esfera será: 4*%.2f*%.0f = %.2f", PI, R, AREA);
		
		break;
		
	case 5:
		printf ("\nEntre com valor do raio: ");
		
		do {
			scanf("%f", & R);
			if (R <= 0) {
				printf ("Valor inválido ! Deve ser um valor maior que 0.\n");
				printf ("\nEntre com valor do raio: ");
			} 
		} while (R <= 0);
		
		V = VE(R,PI=3.14);
		
		printf ("O volume da esfera (4*%.2f*%.0f)/3 = %.2f", PI, R, V);
		
		break;
		
	case 6:
		printf ("\nSaindo...");
		break;
	}
	
	getch();
}
