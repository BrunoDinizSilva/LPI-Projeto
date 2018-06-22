# LPI-Projeto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct {
	int codigo, idade, numero;
	char nome[100], cpf[30], rua[100], bairro[30], cep[30], complemento[10], cidade[50], estado[30];

}CADASTRO_PACIENTE;

typedef struct {
	int matricula, idade;
	char nome[100],cpf[30],curso[30];

}CADASTRO_ALUNO;

typedef struct {
	int codigo;
	char curso[30], nome[100];

}CADASTRO_PROFESSOR;

typedef struct {
	int cod_agendamento, cod_paciente, dia, mes, ano;
	char area_atendimento[50], nome_cliente[100];

}AGENDAMENTO;

typedef struct {
	int cod_atendimento, dia_atendimento, mes_atendimento, ano_atendimento;
	int cod_agendamento, data_agendamento, cod_paciente, cod_aluno, cod_professor;
	char nome_paciente, nome_aluno, nome_professor, area_atendimento;

}ATENDIMENTO;




/* Função criar o cadastro do paciente*/
void cadastrar_paciente(){
	FILE *arquivo_paciente;
	char op;
	CADASTRO_PACIENTE cad;
	arquivo_paciente = fopen("arquivo_paciente.txt", "ab");

		if (arquivo_paciente == NULL){
			printf("Problemas ao criar arquivo!!!\n");
		}
		else {
				do{
					printf("************************************************************************************************************************\n");
					printf("============================================ CADASTRAR PACIENTE ========================================================");
					printf("************************************************************************************************************************\n\n\n\n");

					fflush(stdin);
					printf("DIGITAR NOME DO PACIENTE: \n");
					scanf(" %[^\n]s", cad.nome);

					fflush(stdin);
					printf("DIGITAR NOME DA RUA:  \n");
					scanf(" %[^\n]", cad.rua);

					fflush(stdin);
					printf("DIGITE O NÚMERO DA CASA: \n");
					scanf("%d", &cad.numero);

					fflush(stdin);
					printf("DIGITE O COMPLEMENTO: \n");
					scanf(" %[^\n]", cad.complemento);

					fflush(stdin);
					printf("DIGITE O BAIRRO: \n");
					scanf(" %[^\n]", cad.bairro);

					fflush(stdin);
					printf("DIGITE O CEP \n");
					scanf(" %[^\n]", cad.cep);

					fflush(stdin);
					printf("DIGITE A CIDADE: \n");
					scanf(" %[^\n]", cad.cidade);

					fflush(stdin);
					printf("DIGITE O ESTADO: \n");
					scanf(" %[^\n]", cad.estado);

					printf("DIGITE O CPF: \n");
					scanf(" %[^\n]", cad.cpf);

					printf("DIGITE SUA IDADE: \n");
					scanf("%d", &cad.idade);

					printf("DIGITE O CÓDIGO PARA CADASTRO: \n");
					scanf("%d", &cad.codigo);
					
					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n");

					fwrite(&cad, sizeof(CADASTRO_PACIENTE), 1, arquivo_paciente);
					printf("INCLUIR NOVO CADASTRO (s/n)? ");
					scanf(" %c", &op);

				}while(op == 's');
			fclose(arquivo_paciente);
		}

		system("cls");
}

/* Função lista o cadastro do paciente*/
void listar_paciente(){
	FILE *arquivo_paciente;
	CADASTRO_PACIENTE cad;
	arquivo_paciente = fopen("arquivo_paciente.txt", "rb");
				
				printf("************************************************************************************************************************\n");
				printf("========================================= LISTAR CADASTROS PACIENTES ===================================================");
				printf("************************************************************************************************************************\n\n\n\n");
				
		if (arquivo_paciente == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}
		else{

			while (fread(&cad, sizeof(CADASTRO_PACIENTE), 1, arquivo_paciente ) == 1){
				printf("NOME: %s\n", cad.nome);
				printf("RUA: %s\n", cad.rua);
				printf("NÚMERO DA CASA: %d\n", cad.numero);
				printf("COMPLEMENTO: %s\n", cad.complemento);
				printf("CEP: %s\n", cad.cep);
				printf("CIDADE: %s\n", cad.cidade);
				printf("ESTADO: %s\n", cad.estado);
				printf("CPF: %s\n", cad.cpf);
				printf("IDADE: %d\n", cad.idade);
				printf("CÓDIGO: %d\n", cad.codigo);
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n\n\n\n");

			}
		}
		fclose(arquivo_paciente);
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");
}
/*Função remover cadastro do paciente */
void remover_paciente() {
	CADASTRO_PACIENTE p;
	int codigo;
	FILE *arquivo_paciente = fopen("arquivo_paciente.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");

		printf("======================================= REMOVER CADASTRO PACIENTE=======================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_paciente == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe o Código de cadastro do paciente.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(CADASTRO_PACIENTE), 1, arquivo_paciente) == 1){
			if(codigo != p.codigo){
				fwrite(&p, sizeof(CADASTRO_PACIENTE), 1,  arquivo_aux);
			}

		}

	}


	fclose(arquivo_paciente);
	fclose(arquivo_aux);
	system("del arquivo_paciente.txt");
	system("ren arquivo_aux.txt arquivo_paciente.txt");
	printf("CADASTRO REMOVIDO COM SUCESSO.\n");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n\n\n\n");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");

}
// Função Editar

void editar_paciente() {
	CADASTRO_PACIENTE p;
	CADASTRO_PACIENTE q;
	int codigo;
	FILE *arquivo_paciente = fopen("arquivo_paciente.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");

		printf("======================================= EDITAR CADASTRO PACIENTE =======================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_paciente == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe o Código do paciente para Editar.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(CADASTRO_PACIENTE), 1, arquivo_paciente) == 1){

			if(codigo == p.codigo){

				fflush(stdin);
					printf("DIGITE O NOME DO PACIENTE: \n");
					scanf(" %[^\n]s", p.nome);

					fflush(stdin);
					printf("DIGITE O NOME DA RUA: \n");
					scanf(" %[^\n]", p.rua);

					fflush(stdin);
					printf("DIGITE O NÚMERO DA CASA: \n");
					scanf("%d", &p.numero);

					fflush(stdin);
					printf("DIGITE O COMPLEMENTO: \n");
					scanf(" %[^\n]", p.complemento);

					fflush(stdin);
					printf("DIGITE O BAIRRO: \n");
					scanf(" %[^\n]", p.bairro);

					fflush(stdin);
					printf("DIGITE O CEP: \n");
					scanf(" %[^\n]", p.cep);

					fflush(stdin);
					printf("DIGITE CIDADE: \n");
					scanf(" %[^\n]", p.cidade);

					fflush(stdin);
					printf("DIGITE O ESTADO: \n");
					scanf(" %[^\n]", p.estado);

					printf("DIGITE O CPF: \n");
					scanf(" %[^\n]", p.cpf);

					printf("DIGITE IDADE: \n");
					scanf("%d", &p.idade);

					printf("DIGITE O NOVO CÓDIGO: \n");
					scanf("%d", &p.codigo);
				
					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n");
				
				   fwrite(&p, sizeof(CADASTRO_PACIENTE), 1,  arquivo_aux);
			} else {

				fwrite(&p, sizeof(CADASTRO_PACIENTE), 1,  arquivo_aux);
			}
		}

	}


	fclose(arquivo_paciente);
	fclose(arquivo_aux);
	system("del arquivo_paciente.txt");
	system("ren arquivo_aux.txt arquivo_paciente.txt");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");
}
//###########################################################################################################################################


/* Função criar o cadastro do Aluno*/

void cadastrar_aluno(){
	FILE *arquivo_aluno;
	char op;
	CADASTRO_ALUNO cad;
	arquivo_aluno = fopen("arquivo_aluno.txt", "ab");
		if (arquivo_aluno == NULL){
			printf("Problemas ao criar arquivo!!!\n");
		}
		else {
				do{
					printf("============================================= CADASTRAR ALUNO ==========================================================");
					printf("************************************************************************************************************************\n\n\n\n");

					fflush(stdin);
					printf("DIGITE NOME DO ALUNO: \n");
					scanf(" %[^\n]s", cad.nome);

					fflush(stdin);
					printf("DIGITE O CURSO: \n");
					scanf(" %[^\n]", cad.curso);

					printf("DIGITE O CPF: \n");
					scanf(" %[^\n]", cad.cpf);

					printf("DIGITE A IDADE: \n");
					scanf("%d", &cad.idade);

					printf("DIGITE A MATRICULA: \n");
					scanf("%d", &cad.matricula);
					
					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n\n\n\n");
				
					fwrite(&cad, sizeof(CADASTRO_ALUNO), 1, arquivo_aluno);
					printf("INCLUIR NOVO CADASTRO (s/n)? ");
					scanf(" %c", &op);
					system("cls");

				}while(op == 's');
			fclose(arquivo_aluno);
		}
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");
}

/* Função lista o cadastro do aluno*/
void listar_aluno(){
	FILE *arquivo_aluno;
	CADASTRO_ALUNO cad;
	arquivo_aluno = fopen("arquivo_aluno.txt", "rb");

			printf("========================================= LISTAR CADASTROS ALUNOS ======================================================");
			printf("************************************************************************************************************************\n\n\n\n");

		if (arquivo_aluno == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}
		else{

			while (fread(&cad, sizeof(CADASTRO_ALUNO), 1, arquivo_aluno ) == 1){
				printf("NOME: %s\n", cad.nome);
				printf("CURSO: %s\n", cad.curso);
				printf("CPF: %s\n", cad.cpf);
				printf("IDADE: %d\n", cad.idade);
				printf("MATRICULA: %d\n", cad.matricula);
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n\n\n\n");

			}
		}
		fclose(arquivo_aluno);
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");

}
/*Função remover cadastro do aluno*/
void remover_aluno() {
	CADASTRO_ALUNO p;
	int matricula;
	FILE *arquivo_aluno = fopen("arquivo_aluno.txt", "rb");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "ab");
		
		printf("========================================= REMOVER CADASTRO ALUNO =======================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_aluno == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe a matricula do aluno.\n");
		scanf("%d", &matricula);


		while(fread(&p, sizeof(CADASTRO_ALUNO), 1, arquivo_aluno) == 1){
			if(matricula != p.matricula){
				fwrite(&p, sizeof(CADASTRO_ALUNO), 1,  arquivo_aux);
			}

		}

	}


	fclose(arquivo_aluno);
	fclose(arquivo_aux);
	system("del arquivo_aluno.txt");
	system("ren arquivo_aux.txt arquivo_aluno.txt");
	printf("CADASTRO REMOVIDO COM SUCESSO.\n");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n\n\n\n");
	printf("\n\nPARA VOLTAR TECLE ENTRE\n");
	system("pause>>NULL");
	system("cls");


}
// Função Editar cadastro do aluno

void editar_aluno() {
	CADASTRO_ALUNO p;
	CADASTRO_ALUNO q;
	int matricula;
	FILE *arquivo_aluno = fopen("arquivo_aluno.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");

		printf("======================================= EDITAR CADASTRO ALUNO ==========================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_aluno == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe a matricula do aluno.\n");
		scanf("%d", &matricula);


		while(fread(&p, sizeof(CADASTRO_ALUNO), 1, arquivo_aluno) == 1){

			if(matricula == p.matricula){

				fflush(stdin);
					printf("DIGITE NOME DO ALUNO: \n");
					scanf(" %[^\n]s", p.nome);

					fflush(stdin);
					printf("DIGITE O CURSO: \n");
					scanf(" %[^\n]", p.curso);

					printf("DIGITE O CPF: \n");
					scanf(" %[^\n]", p.cpf);

					printf("DIGITE A IDADE: \n");
					scanf("%d", &p.idade);

					printf("DIGITE A MATRICULA: \n");
					scanf("%d", &p.matricula);
					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n\n\n\n");

				   fwrite(&p, sizeof(CADASTRO_ALUNO), 1,  arquivo_aux);
			} else {

				fwrite(&p, sizeof(CADASTRO_ALUNO), 1,  arquivo_aux);
			}
		}

	}
	printf("\n\nPARA VOLTAR TECLE ENTRE\n");
	system("pause>>NULL");
	system("cls");


	fclose(arquivo_aluno);
	fclose(arquivo_aux);
	system("del arquivo_aluno.txt");
	system("ren arquivo_aux.txt arquivo_aluno.txt");

}
//###################################################################################################################################################
/* Função criar o cadastro do Professor*/

void cadastrar_professor(){
	FILE *arquivo_professor;
	char op;
	CADASTRO_PROFESSOR cad;
	arquivo_professor = fopen("arquivo_professor.txt", "ab");
		if (arquivo_professor == NULL){
			printf("Problemas ao criar arquivo!!!\n");
		}
		else {
				
				do {
					
				
					printf("======================================= CADASTRAR PROFESSOR ============================================================");
					printf("************************************************************************************************************************\n\n\n\n");
					
					fflush(stdin);
					printf("Digite o Código Professor: \n");
					scanf("%d", &cad.codigo);

					fflush(stdin);
					printf("Digite o nome do Professor: \n");
					scanf(" %[^\n]s", cad.nome);

					fflush(stdin);
					printf("Digite o seu Curso: \n");
					scanf(" %[^\n]", cad.curso);

					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n\n\n\n");
				
					fwrite(&cad, sizeof(CADASTRO_PROFESSOR), 1, arquivo_professor);
					printf("INCLUIR NOVO CADASTRO (s/n)? ");
					scanf(" %c", &op);

				}while(op == 's');
			fclose(arquivo_professor);
		}
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");
}

/* Função lista o cadastro do professor*/
void listar_professor(){
	FILE *arquivo_professor;
	CADASTRO_PROFESSOR cad;
	arquivo_professor = fopen("arquivo_professor.txt", "rb");

		printf("================================== LISTAR CADASTROS PROFESSORES ========================================================");
		printf("************************************************************************************************************************\n\n\n\n");

		if (arquivo_professor == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}
		else{

			while (fread(&cad, sizeof(CADASTRO_PROFESSOR), 1, arquivo_professor ) == 1){
				printf("Código:  %d\n", cad.codigo);
				printf("Nome: %s\n", cad.nome);
				printf("Curso: %s\n", cad.curso);
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n\n\n\n");

			}
		}
		fclose(arquivo_professor);
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");
}
/*Função remover cadastro do professor*/
void remover_professor() {
	CADASTRO_PROFESSOR p;
	int codigo;
	FILE *arquivo_professor = fopen("arquivo_professor.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");
		
		printf("===================================== REMOVER CADASTRO PROFESSOR =======================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_professor == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe o código do Professor.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(CADASTRO_PROFESSOR), 1, arquivo_professor) == 1){
			if(codigo != p.codigo){
				fwrite(&p, sizeof(CADASTRO_PROFESSOR), 1,  arquivo_aux);
			}

		}

	}


	fclose(arquivo_professor);
	fclose(arquivo_aux);
	system("del arquivo_professor.txt");
	system("ren arquivo_aux.txt arquivo_professor.txt");
	printf("CADASTRO REMOVIDO COM SUCESSO.\n");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n\n\n\n");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");

}
// Função Editar cadastro do professor

void editar_professor() {
	CADASTRO_PROFESSOR p;
	CADASTRO_PROFESSOR q;
	int codigo;
	FILE *arquivo_professor = fopen("arquivo_professor.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");

				printf("======================================== EDITAR CADASTRO ================================================================");
				printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_professor == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("INFORME O CÓDIGO DO PROFESSOR.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(CADASTRO_PROFESSOR), 1, arquivo_professor) == 1){

			if(codigo == p.codigo){

				fflush(stdin);

					printf("Digite o novo Código\n");
					scanf("%d", &p.codigo);

					fflush(stdin);
					printf("Digite novo nome do Professor: \n");
					scanf(" %[^\n]s", p.nome);

					fflush(stdin);
					printf("Digite o novo curso do professor: \n");
					scanf(" %[^\n]", p.curso);


				   fwrite(&p, sizeof(CADASTRO_PROFESSOR), 1,  arquivo_aux);
			} else {

				fwrite(&p, sizeof(CADASTRO_PROFESSOR), 1,  arquivo_aux);
			}
		}

	}


	fclose(arquivo_professor);
	fclose(arquivo_aux);
	system("del arquivo_professor.txt");
	system("ren arquivo_aux.txt arquivo_professor.txt");
	printf("CADASTRO ALTERADO COM SUCESSO.");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n\n\n\n");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");
}
// ######################################################################################################################################
//Função criar agendamento

void criar_agendamento(){
	FILE *arquivo_paciente;
	FILE *arquivo_agendamento;
	AGENDAMENTO cad;
	CADASTRO_PACIENTE p;
	int codigo;
	arquivo_agendamento = fopen("arquivo_agendamento.txt", "ab");
	arquivo_paciente = fopen("arquivo_paciente.txt", "rb");


		if (arquivo_agendamento == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}

		fflush (stdin);
		printf("Informe o Código Paciente .\n");
		scanf("%d", &codigo);

		while (fread(&p, sizeof(CADASTRO_PACIENTE), 1, arquivo_paciente ) == 1){

			if(codigo == p.codigo) {
				cad.cod_paciente = p.codigo;
				strcpy (cad.nome_cliente, p.nome);
					printf("************************************************************************************************************************\n");
					printf("======================================REALIZAR AGENDAMENTO =============================================================");
					printf("************************************************************************************************************************\n\n\n\n");

					fflush(stdin);
					printf("Informe o Código do agendamento.\n");
					scanf("%d", &cad.cod_agendamento);

					fflush(stdin);
					printf("Informe a ária de Atendimento:\n");
					scanf(" %[^\n]", &cad.area_atendimento);

					fflush(stdin);
					printf("Informe o Dia. \n");
					scanf("%d", &cad.dia);

				  	fflush(stdin);
					printf("Informe o Mês. \n");
					scanf("%d", &cad.mes);

					fflush(stdin);
					printf("Informe o Ano. \n");
					scanf("%d", &cad.ano);

					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n");

					fwrite(&cad, sizeof(AGENDAMENTO), 1,  arquivo_agendamento);
					fclose(arquivo_agendamento);

		}
			else

				printf("Paciente não Cadastrado\n");


	}
		printf("\n\nPARA VOLTAR TECLE ENTER\n");
		system("pause>>NULL");
		system("cls");
}

//Função Lista Agendamento //
void listar_agendamento(){

	FILE *arquivo_agendamento;
	AGENDAMENTO cad;
	arquivo_agendamento = fopen("arquivo_agendamento.txt", "rb");
			
			printf("************************************************************************************************************************\n");
			printf("============================================ LISTAR AGENDAMENTO ========================================================");
			printf("************************************************************************************************************************\n");

		if (arquivo_agendamento == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}
		else{

			while (fread(&cad, sizeof(AGENDAMENTO), 1, arquivo_agendamento ) == 1){
				printf("Código do Agendamento:  %d\n", cad.cod_agendamento);
				printf("Nome: %s\n", cad.nome_cliente);
				printf("Área de Atendimento: %s\n", cad.area_atendimento);
				printf("Data do Agendamento: %d / %d / %d \n", cad.dia, cad.mes, cad.ano );
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n");

			}
		}
			fclose(arquivo_agendamento);
			printf("\n\nPARA VOLTAR TECLE ENTER\n");
			system("pause>>NULL");
			system("cls");
    }

//Função Remover Agendamento //

void remover_agendamento() {
	AGENDAMENTO p;
	int codigo;
	FILE *arquivo_agendamento = fopen("arquivo_agendamento.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");
	
		printf("=================================================REMOVER AGENDAMENTO =======================================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_agendamento == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe o código do Agendamento.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(AGENDAMENTO), 1, arquivo_agendamento) == 1){
			if(codigo != p.cod_agendamento){
				fwrite(&p, sizeof(AGENDAMENTO), 1,  arquivo_aux);
			}

		}

	}

	fclose(arquivo_agendamento);
	fclose(arquivo_aux);
	system("del arquivo_agendamento.txt");
	system("ren arquivo_aux.txt arquivo_agendamento.txt");
	printf("AGENDAMENTO REMOVIDO COM SUCESS0.\n");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");
}
//##################################################################################################################################
//Função Criar Atendimento //
void criar_atendimento(){
	int aux;
	AGENDAMENTO p;
	FILE *arquivo_atendimento;
	ATENDIMENTO cad;	
	int codigo;
	char area [50];
	int op;
	arquivo_atendimento = fopen("arquivo_atendimento.txt", "ab");
	

		if (arquivo_atendimento == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
		}
		else {
		
				do {
				
					printf("====================================== REALIZAR ATENDIMENTO ============================================================");
					printf("************************************************************************************************************************\n\n\n\n");

					fflush(stdin);
					printf("INFORME O CODIGO DO ATENDIMENTO\n");
					scanf("%d", &cad.cod_atendimento);

					fflush(stdin);
					printf("INFORME O DIA DO ATENDIMENTO \n");
					scanf("%d", &cad.dia_atendimento);

				  	fflush(stdin);
					printf("INFORME O MÊS DO ATENDIMENTO \n");
					scanf("%d", &cad.mes_atendimento);
					
					fflush(stdin);
					printf("INFORME O ANO DO ATENDIMENTO \n");
					scanf("%d", &cad.ano_atendimento);
					
					fflush(stdin);
					printf("INFORME A ÁREA DE ATENDIMENTO:\n");
					scanf(" %[^\n]", &cad.area_atendimento);
					
					fflush(stdin);
					printf("INFORME O CÓDIGO DO AGENDAMENTO \n");
					scanf("%d", &codigo);
					aux = acharagen(codigo);
					if(aux==0){
						printf("\n\nATENDIMENTO N REALIZADO POIS N FOI AGENDADO!!\n\n");
						goto aqui1;
					}
					
					
					printf("========================================================================================================================");
					printf("************************************************************************************************************************\n");

					fwrite(&cad, sizeof(ATENDIMENTO), 1,  arquivo_atendimento);
					fclose(arquivo_atendimento);
					aqui1:
					printf("REALIZAR NOVO ATENDIMENTO (s/n)\n");
					scanf(" %c", &op);
					system("cls");
				}
				while(op == 's');
				fclose(arquivo_atendimento);
			}
	}
// Verificar codigo agendamento //
int acharagen(int codigo){
    AGENDAMENTO cad;
     FILE *arquivo_agendamento = fopen("arquivo_agendamento.txt","r+b");
     while(fread(&cad,sizeof(AGENDAMENTO),1,arquivo_agendamento)){
        if(codigo==cad.cod_agendamento)
        {
            fclose(arquivo_agendamento);
            return 1;
        }
     }
     fclose(arquivo_agendamento);
     return 0;
}

//Verificar codigo paciente //
int achar_paciente(int codigo){
    CADASTRO_PACIENTE cad;
     FILE *arquivo_paciente = fopen("arquivo_paciente.txt","rb");
     while(fread(&cad,sizeof(CADASTRO_PACIENTE),1,arquivo_paciente)){
        if(codigo == cad.codigo )
        {
            fclose(arquivo_paciente);
            return 1;
        }
     }
     fclose(arquivo_paciente);
     return 0;
}
//Verificar codigo Aluno//
int achar_aluno(int codigo){
    CADASTRO_ALUNO cad;
     FILE *arquivo_aluno = fopen("arquivo_aluno.txt","rb");
     while(fread(&cad,sizeof(CADASTRO_ALUNO),1,arquivo_aluno)){
        if(codigo == cad.matricula )
        {
            fclose(arquivo_aluno);
            return 1;
        }
     }
     fclose(arquivo_aluno);
     return 0;
}
//Verificar cadastro do Professor

int achar_professor(int codigo){
    CADASTRO_PROFESSOR cad;
     FILE *arquivo_professor = fopen("arquivo_professor.txt","rb");
     while(fread(&cad,sizeof(CADASTRO_PROFESSOR),1,arquivo_professor)){
        if(codigo == cad.codigo )
        {
            fclose(arquivo_professor);
            return 1;
        }
     }
     fclose(arquivo_professor);
     return 0;
}

//Função total Lista Atendimento //
void listar_atendimento(){

	FILE *arquivo_atendimento;
	ATENDIMENTO cad;
	arquivo_atendimento = fopen("arquivo_atendimento.txt", "rb");

				printf("===========================================LISTA DE ATENDIMENTO ========================================================");
				printf("************************************************************************************************************************\n\n\n\n");

		if (arquivo_atendimento == NULL){
			printf("Problemas ao abrir arquivo!!!\n");
	}
		else{

			while (fread(&cad, sizeof(ATENDIMENTO), 1, arquivo_atendimento ) == 1){
				printf("CÓDICO DE ATENDIMENTO:  %d\n", cad.cod_atendimento);
				printf("ÁREA DE ATENDIMENTO: %s\n", cad.area_atendimento);
				printf("DATA DO AGENDAMENTO: %d / %d / %d \n", cad.dia_atendimento, cad.mes_atendimento, cad.ano_atendimento );
				printf("NOME \n%s",cad.nome_paciente);
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n");

			}
		}
			fclose(arquivo_atendimento);
			printf("\n\nPARA VOLTAR TECLE ENTER\n");
			system("pause>>NULL");
			system("cls");
    }

//Listar atendimento por Area //
void listar_atendimento_area(){
    int l=1,d;
	char area[20];

    printf("================================= ATENDIMENTO(S) REALIZADO(S) POR AREA ================================================\n");
    printf("************************************************************************************************************************\n\n\n\n");
    ATENDIMENTO p;
    FILE *arquivo_atendimento;
    arquivo_atendimento = fopen("arquivo_atendimento.txt","rb");
    printf("DIGITE A AREA: ");
    scanf(" %[^\n]s",area);
    printf("\n\n");
    
	while(fread(&p, sizeof(ATENDIMENTO), 1, arquivo_atendimento) == 1){
    	if(strcmp(area,p.area_atendimento)==0){
    	
		printf("%dº ATENDIMENTO REALIZADO\n\n",l);
    	printf("- CÓDIGO DO ATENDIMENTO: %d \n",p.cod_atendimento);
    	printf("- CÓDIGO DO AGENDAMENTO: %d\n",p.cod_agendamento);
     	printf("- DATA DO AGENDAMENTO: %d/%d/%d",p.data_agendamento);
    	printf("- NOME DO ALUNO: %s",p.nome_aluno);
   		printf("- MATRICULA DO ALUNO: %d",p.cod_aluno);
    	printf("- NOME DO PACIENTE: %s",p.nome_paciente);
    	printf("- CÓDIGO DO PACIENTE: %d",p.cod_paciente);
    	printf("- DATA DO ATENDIMENTO: %d/%d/%d",p.cod_agendamento);
   		printf("- AREA DO ATENDIMENTO: %s",p.area_atendimento);
    	printf("- NOME DO PROFESSOR: %s",p.nome_professor);
    	printf("- CÓDIGO DO PROFESSOR: %d",p.cod_professor);
   
    printf("========================================================================================================================");
	printf("************************************************************************************************************************\n");
    
    l++;

}

else{
    printf("* NAO HA ATENDIMENTOS REALIZADOS NA AREA *\n\n");
    printf("\n\n");
    }   

   }
 

printf("PARA VOLTAR TECLE ENTER\n\n");
system("pause>>NULL");
system("cls");
fclose(arquivo_atendimento);

}
//Função listar por aluno //
void listar_atendimento_aluno(){
    int l=1,d;
    int cod_matricula;

    printf("\n====================================== ATENDIMENTOS REALIZADOS POR ALUNO =============================================\n");
    printf("************************************************************************************************************************\n\n\n\n");
    
    ATENDIMENTO p;
    FILE *arquivo_atendimento;
    arquivo_atendimento = fopen("arquivo_atendimento.txt","rb");
    printf("DIGITE A MATRICULA: ");
    scanf("%d",&cod_matricula);
    
    while(fread(&p, sizeof(ATENDIMENTO), 1, arquivo_atendimento) == 1){
    
	if(cod_matricula == p.cod_aluno){
    printf("%dº ATENDIMENTO REALIZADO\n\n",l);
    printf("- CÓDIGO DO ATENDIMENTO: %d",p.cod_atendimento);
    printf("- CÓDIGO DO AGENDAMENTO: %d",p.cod_agendamento);
    printf("- DATA DO AGENDAMENTO: %d/%d/%d",p.data_agendamento);
    printf("- NOME DO ALUNO: %s",p.nome_aluno);
    printf("- MATRICULA DO ALUNO: %d",p.cod_aluno);
    printf("========================================================================================================================");
	printf("************************************************************************************************************************\n");
    l++;

}
else{
    printf("* NAO HA ATENDIMENTOS REALIZADOS PELO ALUNO *\n\n");
    printf("\n\n");
}
}
printf("PARA VOLTAR TECLE ENTER\n\n");
system("pause>>NULL");
system("cls");
fclose(arquivo_atendimento);
}
//Função listar atendimento por paciente//
void listar_atendimento_paciente(){
    int l=1,d;
    int codigo;

    printf("\n========================================= ATENDIMENTOS REALIZADOS NO PACIENTE ==============================================\n");
    
    ATENDIMENTO p;
    FILE *arquivo_atendimento;
    arquivo_atendimento = fopen("arquivo_atendimento.txt","rb");
    printf("DIGITE O CODIGO: ");
    scanf("%d",&codigo);
    
    while(fread(&p, sizeof(ATENDIMENTO), 1, arquivo_atendimento) == 1){
    	
		if(codigo == p.nome_paciente){
    	printf("- NOME DO PACIENTE: %s",p.nome_paciente);
    	printf("- CÓDIGO DO PACIENTE: %d",p.cod_paciente);
    	printf("- DATA DO ATENDIMENTO: %d/%d/%d",p.dia_atendimento,p.mes_atendimento,p.ano_atendimento);
    	printf("- AREA DO ATENDIMENTO: %s",p.area_atendimento);
   
    l++;

}

else{
    printf("* NAO ATENDIMENTOS REALIZADOS NO PACIENTE *\n\n");
    printf("\n\n");
 }
}


printf("PARA VOLTAR TECLE ENTER\n\n");
system("pause>>NULL");
system("cls");
fclose(arquivo_atendimento);


}

//Função Remover Atendimento //

void remover_atendimento() {
	ATENDIMENTO p;
	int codigo;
	FILE *arquivo_atendimento = fopen("arquivo_atendimento.txt", "r+b");
	FILE *arquivo_aux = fopen("arquivo_aux.txt", "a+b");
		
		printf("===============================================REMOVER ATENDIMENTO =====================================================");
		printf("************************************************************************************************************************\n\n\n\n");

	if (arquivo_atendimento == NULL){
		printf("Problemas ao abrir arquivo!!!\n");

	}

	else{


		fflush (stdin);
		printf("Informe o código do Aatendimento.\n");
		scanf("%d", &codigo);


		while(fread(&p, sizeof(ATENDIMENTO), 1, arquivo_atendimento) == 1){
			
			if(codigo != p.cod_atendimento){
				fwrite(&p, sizeof(ATENDIMENTO), 1,  arquivo_aux);
				system("cls");
			}

		}

	}

	fclose(arquivo_atendimento);
	fclose(arquivo_aux);
	system("del arquivo_atendimento.txt");
	system("ren arquivo_aux.txt arquivo_atendimento.txt");
	printf("ATENDIMENTO REMOVIDO COM SUCESSO.\n");
	printf("========================================================================================================================");
	printf("************************************************************************************************************************\n\n\n\n");
	printf("\n\nPARA VOLTAR TECLE ENTER\n");
	system("pause>>NULL");
	system("cls");
}

// Funções de Menu(s) //


void menu_paciente() {

	int op;

		do{

			printf("================================================ MENU PACIENTE ========================================================\n");
			printf("************************************************************************************************************************\n\n\n\n");
			printf("\t\t\t 1 - CADASTRAR PACIENTE       \t\t 2 - EDITAR PACIENTE\n\n\n\n\n");
			printf("\t\t\t 3 - EXCLUIR CADASTRO         \t\t 4 - LISTAR CADASTROS\n\n\n\n\n");
            printf("\t\t\t\t\t\t 5 - MENU PRINCIPAL.\n\n\n\n");
            printf("========================================================================================================================");
			printf("************************************************************************************************************************\n\n\n\n");
			scanf("%d",&op);
			system("cls");
			
		switch	(op) {

				  case 1: cadastrar_paciente(),system("cls"); break;
				  case 2: editar_paciente(),system("cls"); break;
				  case 3: remover_paciente(),system("cls"); break;
				  case 4: listar_paciente(),system("cls"); break;
				  case 5: system("cls"); break;
				 default: printf("OPÇÃO INVALIDA\n");

		}
	}
		while (op != 5);
}

void menu_aluno(){
	int op;

		do{

			printf("================================================ MENU ALUNO ========================================================");
			printf("************************************************************************************************************************\n\n\n\n");
			printf("\t\t\t 1 - CADASTRAR ALUNO       \t\t 2 - EDITAR ALUNO\n\n\n\n\n");
			printf("\t\t\t 3 - EXCLUIR CADASTRO      \t\t 4 - LISTAR CADASTROS\n\n\n\n\n");
            printf("\t\t\t\t\t\t 5 - MENU PRINCIPAL\n\n\n\n");
            printf("========================================================================================================================");
			printf("************************************************************************************************************************\n\n\n\n");
			scanf("%d", &op);
			system("cls");

		switch	(op) {

				  case 1: cadastrar_aluno(); break;
				  case 2: editar_aluno(); break;
				  case 3: remover_aluno(); break;
				  case 4: listar_aluno(); break;
				  case 5: system("cls"); break;
				 default: printf("OPÇÃO INVALIDA\n");

		}
	}while (op != 5);

}

void menu_professor(){
	int op;

		do{
			printf("================================================ MENU PROFESSOR ========================================================");
			printf("************************************************************************************************************************\n\n\n\n");
			printf("\t\t\t 1 - CADASTRAR PROFESSOR        \t\t 2 - EDITAR CADASTRO\n\n\n\n\n");
			printf("\t\t\t 3 - EXCLUIR CADASTRO           \t\t 4 - LISTAR CADASTROS\n\n\n\n\n");
            printf("\t\t\t\t\t\t 5 - MENU PRINCIPAL.\n\n\n\n\n\n\n\n");
            printf("========================================================================================================================");
			printf("************************************************************************************************************************\n\n\n\n");
			scanf("%d", &op);
			system("cls");

		switch	(op) {

				  case 1: cadastrar_professor(); break;
				  case 2: editar_professor(); break;
				  case 3: remover_professor(); break;
				  case 4: listar_professor(); break;
				  case 5: system("cls"); break;
				 default: printf("OPÇÃO INVALIDA\n");

		}

	}
	while (op != 5);
}

void menu_agendamento(){
	int op;

		do{
				printf("================================================ MENU AGENDAMENTO ======================================================");
				printf("************************************************************************************************************************\n\n\n\n");
				printf("\t\t\t 1 - REALIZAR AGENDAMENTO            \t\t 2 - EXCLUIR AGENDAMENTO\n\n\n\n\n");
				printf("\t\t\t 3 - LISTAR AGENDAMENTO              \t\t 4 - MENU PRINCIPAL\n\n\n\n\n\n");
				printf("========================================================================================================================");
				printf("************************************************************************************************************************\n\n\n\n");
				scanf("%d", &op);
				system("cls");

		switch	(op) {

				  case 1: criar_agendamento(); break;
				  case 2: remover_agendamento(); break;
				  case 3: listar_agendamento(); break;
				  case 4: system("cls"); break;
				 default: printf("OPÇÃO INVALIDA\n");

		}
	}while (op != 4 );

}


void menu_atendimento(){
	int op;

		do{
				printf("================================================ MENU ATENDIMENTO ======================================================\n");
				printf("************************************************************************************************************************\n\n\n\n");
				printf("\t 1 - REALIZAR ATENDIMENTO                 \t\t 2 - EXCLUIR ATENDIMENTO\n\n\n\n\n");
				printf("\t 3 - LISTAR ATENDIMENTO                   \t\t 4 - LISTAR ATENDIMENTO POR ÁREA\n\n\n\n");
				printf("\t 5 - LISTAR ATENDIMENTO POR ALUNO         \t\t 6 - LISTAR ATENDIMENTO POR PACIENTE\n\n\n\n");
				printf("\t\t                         7 - MENU PRINCIPAL\n\n\n\n");
				printf("************************************************************************************************************************");
				printf("========================================================================================================================\n");
				scanf("%d", &op);
				system("cls");

			switch	(op) {

				 	  case 1: criar_atendimento(); break;
					  case 2: remover_atendimento(); break;
					  case 3: listar_atendimento(); break;
					  case 4: listar_atendimento_area(); break;
					  case 5: listar_atendimento_aluno(); break;
					  case 6: listar_atendimento_area(); break;
					  case 7: system("cls"); break;
					 default: printf("OPÇÃO INVALIDA\n");

			}
		}

		while (op != 7);
}
void menu_principal() {
				printf("************************************************************************************************************************");
				printf("=============================|       UNIVERSIDADE ESTADUAL DA PARAÍBA       |===========================================");
				printf("=============================| RUA: BARAÚNAS, N: 351, BAIRRO: UNIVERSITÁRIO |===========================================");
				printf("=============================|      CAMPINA GRANDE -PB, CEP:58429-500       |===========================================");
				printf("=============================|              CLÍNICA ESCOLA                  |===========================================");	
				printf("=============================|              MENU PRINCIPAL                  |===========================================");
				printf("************************************************************************************************************************\n\n\n\n");
				printf("\t\t\t 1 - PACIENTE                \t\t 2 - ALUNO\n\n\n");
				printf("\t\t\t 3 - PROFESSOR               \t\t 4 - AGENDAMENTO\n\n\n");
				printf("\t\t\t 5 - ATENDIMENTO             \t\t 6 - SAIR\n\n\n\n\n\n\n\n");
				printf("************************************************************************************************************************");
				printf("========================================================================================================================\n");
}


/*Programa principal*/
int main () {

	setlocale(LC_ALL, "Portuguese");

	int op;


		do{
			menu_principal();
			scanf("%d",&op);
			system("cls");
			if(op==1){
				menu_paciente();
			}
			if(op==2){
				menu_aluno();
			}
			if(op==3){
				menu_professor();
			}
			if(op==4){
				menu_agendamento();
			}
			if(op==5){
				menu_atendimento();
			}


	}
		while (op != 6);
}
