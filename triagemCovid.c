#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


void cadastroPaciente();
int questionarioSintomas();

int idade = 0;
char sexo[10];
char nome[20];
char sobrenome[20];
char cpf[15];


int main() {
	setlocale(LC_ALL, "Portuguese");
	int retornoSomatorio = 0;
	char ala[15];
	
	char url[] = "Registro_Pacientes.txt";
	FILE *arq;
	
	cadastroPaciente();  
	retornoSomatorio = questionarioSintomas();
	
	if(retornoSomatorio >= 0 && retornoSomatorio <= 9){
    	strcpy ( ala, "Risco Baixo" );
	} else if(retornoSomatorio >= 10 && retornoSomatorio <= 19){
		strcpy ( ala, "Risco Médio" );
	} else if(retornoSomatorio >= 20){
		strcpy ( ala, "Risco Alto" );	
	}
	
	system("Cls");
	printf("\tPara exibir o resultado ");
	system("Pause");
	
	arq = fopen(url, "a");
	if(arq == NULL){
		printf("Erro, nao foi possivel abrir o arquivo\n");
	}else{
		fprintf(arq, "\n\t\tPaciente:");
    	fprintf(arq, "\n\tNome: %s %s", nome, sobrenome);
    	fprintf(arq, "\n\tIdade: %d anos", idade);
    	fprintf(arq, "\n\tSexo: %s", sexo);
    	fprintf(arq, "\n\tCPF: %s", cpf);
		fprintf(arq, "\n\tDirecionado para a ala: %s", ala);
		fprintf(arq, "\n##################################################\n");
	}
	
	fclose(arq);	
	printf("\n\t\tPaciente:");
    printf("\n\tNome: %s %s", nome, sobrenome);
    printf("\n\tIdade: %d anos", idade);
    printf("\n\tSexo: %s", sexo);
    printf("\n\tCPF: %s", cpf);
	printf("\n\tSe dirigir para a ala: %s", ala);
    
	return 0;
}

void cadastroPaciente(){
	int c;
	
	printf("Informe os dados do paciente:\n");
	printf("Digite o Nome:\n");
	scanf("%s", &nome);
	fflush(stdin);
	
	printf("Digite o Sobrenome:\n");
	scanf("%s", &sobrenome);
	fflush(stdin);
	
	printf("Digite o CPF:\n");
	scanf("%s", &cpf);
	fflush(stdin);
	
	printf("Digite o sexo:\n");
	scanf("%s", &sexo);
	fflush(stdin);

	printf("Digite a idade:\n");
	scanf("%d", &idade);
	fflush(stdin);
}

int questionarioSintomas(){
	char op[2];
	int somatorio = 0;
	
	printf("Questionário de Sintomas");
	printf("\nDigite S para SIM e N para NÃO");
	
	printf("\nTem febre?\n");
	scanf("%s", &op);
	fflush(stdin);
	
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 5;
	}
	
	printf("\nTem dor de cabeça?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 1;
	}
		
	printf("\nTem secreção nasal ou espirros?\n"); 
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 1;
	}
	
	printf("\nTem dor/irritação na garganta?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 1;
	}

	printf("\nTem tosse seca?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 3;
	}
	
	printf("\nTem dificuldade respiratória?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 10;
	}	
	
	printf("\nTem dores no corpo?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 1;
	}	
	
	printf("\nTem diarréia?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 1;
	}	
	
	printf("\nEsteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 10;
	}	
	
	printf("\nEsteve em locais com grande aglomeração?\n");
	scanf("%s", &op);
	fflush(stdin);
	if (strcmp(op, "s") == 0 || strcmp(op, "S") == 0){
		somatorio += 3;
	}	
	
	return somatorio;
}



   


