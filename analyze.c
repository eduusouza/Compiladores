#include "globals.h"
#include "symtab.h"
#include "analyze.h"
#include "util_analyze.h"
#include <string.h>

static int indice = 0;

char *escopoAtual;

static void traverse(TreeNode *noArvore, void (*preProc)(TreeNode *), void (*postProc)(TreeNode *)){
	if (noArvore != NULL){
		preProc(noArvore);
		{
			int i;
			for (i = 0; i < MAXCHILDREN; i++){
				traverse(noArvore->child[i], preProc, postProc);
			}
		}
		// nullProc
		postProc(noArvore);
		{
			traverse(noArvore->sibling, preProc, postProc);
		}
	}
}

static void insertTreeNode(TreeNode *no){
	TreeNode *aux;

	int contaQtdArgumentos = 0;
	switch (no->nodekind){
		case Declaracao_NodeK:
			switch (no->kind.stmt){
			case Variavel_StmtK:
				if (nameDontExistInHashTable(no)){
					if (no->type == Void_ExpT){
						DeclaracaoDeErro(no, "Variavel declarada como tipo void");
					}
					st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "nao", "nao", -1);
				} else {
					if (IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo) == 1){
						DeclaracaoDeErro(no, "Variavel já foi declarada anteriormente como função");
					} else if (IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo) == -1){
						// está em escopo diferente
						st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "nao", "nao", -1);
					} else {
						// já está na tabela, então não pode tentar declara-la outra vez
						DeclaracaoDeErro(no, "Variavel já declarada");
					}
				}
				break;

			case Vetor_StmtK:
				if (nameDontExistInHashTable(no)){
					if (no->type == Void_ExpT){
						DeclaracaoDeErro(no, "Variavel declarada como void");
					}
					st_insert(no->attr.name, no->lineno, indice, 3, no->type, no->attr.escopo, "nao", "sim", -1);
					indice += no->attr.len;
				} else {
					if (IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo) == 1){
						DeclaracaoDeErro(no, "Variavel já foi declarada anteriormente como função");
					} else if (IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo) == -1){
						// escopo diferente
						st_insert(no->attr.name, no->lineno, indice, 3, no->type, no->attr.escopo, "nao", "sim", -1);
						indice += no->attr.len;
					} else {
						// já está na tabela, entao está declarando de novo
						DeclaracaoDeErro(no, "Variavel já declarada");
					}
				}
				break;

			case Parametro_StmtK:
				if (nameDontExistInHashTable(no)){
					if (no->type == Void_ExpT){
						DeclaracaoDeErro(no, "Variavel declarada como void");
					}					
					if (CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoVetor") == "sim"){
						st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "sim", "sim", -1);
					} else {
						st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "sim", ".", -1);
					}
				} else {
					if (IntVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo) == -1){ // escopo diferente
						// verifico se está no global
						if (existInGlobalEscope(no)){
							DeclaracaoDeErro(no, "Nome de variavel já usado");
						} else {	
							if (CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoVetor") == "sim"){
								st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "sim", "sim", -1);
							} else {
								st_insert(no->attr.name, no->lineno, indice++, 3, no->type, no->attr.escopo, "sim", ".", -1);
							}
						}
					} else {
						// já está na tabela, entao está declarando de novo
						DeclaracaoDeErro(no, "Variavel já declarada");
					}
				}
				break;

			case Funcao_StmtK:
				
				// escopo nas declarações
				aux = no->child[1];
				while (aux != NULL){
					aux->attr.escopo = no->attr.name;					
					aux = aux->sibling;
				}

				// escopo no parametro
				aux = no->child[0];
				while (aux != NULL){
					if (aux->nodekind == EXP_NodeK && aux->kind.exp == Tipo_ExpK){
						aux->attr.escopo = no->attr.name;
						contaQtdArgumentos++;
					}
					aux = aux->sibling;
				}

				if (nameDontExistInHashTable(no))
					/* não está na tabela */
					st_insert(no->attr.name, no->lineno, 0, 4, no->type, no->attr.escopo, ".", ".", contaQtdArgumentos);
				else
					// nome inválido
					DeclaracaoDeErro(no, "Nome já utilizado");
				break;

			case Call_StmtK:	
				aux = no->child[0];

				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
					contaQtdArgumentos++;
				}

				if ((strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoDeclaracao"), " ") == 0) && ((strcmp(no->attr.name, "input") != 0 && strcmp(no->attr.name, "output") != 0))){
					// Não existe a função na tabela
					DeclaracaoDeErro(no, "A funcao chamada nao existe ou foi declarada erroneamente");
					break;
				} else {
					// Verifica se é recursiva
					if (strcmp(no->attr.name, no->attr.escopo) == 0){
						isRecursive = 1;
					}
				}
				if(VerificaEquivalenciaParametrosDaFuncao(no->attr.name, contaQtdArgumentos) != 1  && ((strcmp(no->attr.name, "input") != 0 && strcmp(no->attr.name, "output") != 0))){
					DeclaracaoDeErro(no, "A quantidade de parametros passado para a função é diferente da quantidade de argumentos que ela necessita.");
				}
				break;

			case While_StmtK:
				// tratar escopo dentro do while
				aux = no->child[0];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				aux = no->child[1];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				break;

			case If_StmtK:
				// tratar escopo dentro do if e do else
				aux = no->child[0];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				aux = no->child[1];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				aux = no->child[2];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				break;

			case Igual_StmtK:
				// tratar escopo dos dois filhos
				aux = no->child[0];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				aux = no->child[1];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				break;

			case Return_StmtK:
				// tratar escopo do filho
				aux = no->child[0];
				while (aux != NULL){
					aux->attr.escopo = no->attr.escopo;
					aux = aux->sibling;
				}

				break;

			default:
				break;
			}
			break;

		case EXP_NodeK:
			switch (no->kind.exp){
				case ID_ExpK:
					if (nameDontExistInHashTable(no)){
						/* não está na tabela, então não foi declarada */
						DeclaracaoDeErro(no, "Variavel nao declarada");
					} else {
						// verifico se está no global
						if (existInGlobalEscope(no)){
							st_insert(no->attr.name, no->lineno, 0, 3, no->type, "Global", ".", "nao", -1);
						} else {
							st_insert(no->attr.name, no->lineno, 0, 3, no->type, no->attr.escopo, ".", "nao", -1);
						}
						if (CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoVetor") == "sim"){
							no->kind.exp = Vetor_ExpK;
						} else if (CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoVetor") == "sim"){
							no->kind.exp = Vetor_ExpK;
						}
					}
					break;

				case Tipo_ExpK:
					no->child[0]->attr.escopo = no->attr.escopo;
					break;

				case Vetor_ExpK:
					aux = no->child[0];
					while (aux != NULL){
						aux->attr.escopo = no->attr.escopo;
						aux = aux->sibling;
					}

					if (nameDontExistInHashTable(no))
						/* não está na tabela, então não foi declarada */
						DeclaracaoDeErro(no, "Variavel nao declarada");
					else {
						// verifico se está no global
						if (existInGlobalEscope(no)){
							st_insert(no->attr.name, no->lineno, 0, 3, no->type, "Global", ".", "sim", -1);
						} else {
							st_insert(no->attr.name, no->lineno, 0, 3, no->type, no->attr.escopo, ".", "sim", -1);
						}
					}
					break;

				case Operacao_ExpK:
					// tratar escopo dos dois filhos
					aux = no->child[0];
					while (aux != NULL){
						aux->attr.escopo = no->attr.escopo;
						aux = aux->sibling;
					}

					aux = no->child[1];
					while (aux != NULL){
						aux->attr.escopo = no->attr.escopo;
						aux = aux->sibling;
					}
					break;

				default:
					break;
				}
				break;

		default:
			break;
		}
}

void implementaTabela(TreeNode *syntaxTree){

	TreeNode *aux = syntaxTree->sibling;
	syntaxTree->attr.escopo = "Global";

	while (aux != NULL){
		if (aux->nodekind == EXP_NodeK && aux->kind.exp == Tipo_ExpK){
			aux->attr.escopo = "Global";
		}
		aux = aux->sibling;
	}

	traverse(syntaxTree, insertTreeNode, nullProc);
	if (TraceAnalyze){
		printf("\nTabela de Simbolos:\n\n");
		imprimeTabela();
	}
}

static void checkNode(TreeNode *no){

	if (no->attr.escopo != NULL)
		escopoAtual = no->attr.escopo;

	switch (no->nodekind){
		case EXP_NodeK:
			switch (no->kind.exp){
				case Operacao_ExpK:
					if ((no->child[0]->type != Integer_ExpT) || (no->child[1]->type != Integer_ExpT))
						erroTipo(no, "Operador utilizado para variável não inteira");
					if ((no->attr.op == COMP) || (no->attr.op == MENORIG) || (no->attr.op == MAIOR) || (no->attr.op == MAIORIG) || (no->attr.op == MENOR) || (no->attr.op == DIF))
						no->type = Boolean_ExpT;
					else
						no->type = Integer_ExpT;
					break;

				case Constante_ExpK:
					no->type = Integer_ExpT;
					break;

				case ID_ExpK:
					if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, escopoAtual, "tipoExpressao"), "int") == 0) // se existe nesse escopo como int
						no->type = Integer_ExpT;
					else if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoExpressao"), "int") == 0) // se existe no global como int
						no->type = Integer_ExpT;
					else if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, escopoAtual, "tipoExpressao"), " ") == 0 || strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoExpressao"), " ") == 0){ // se existe no escopo atual ou global como outro tipo
						no->type = Void_ExpT;
					} else
						erroTipo(no, "Variável não declarada");
					break;

				case Vetor_ExpK:
					if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, escopoAtual, "tipoExpressao"), "int") == 0) // se existe nesse escopo como int
						no->type = Integer_ExpT;
					else if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoExpressao"), "int") == 0) // se existe no global como int
						no->type = Integer_ExpT;
					else if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, escopoAtual, "tipoExpressao"), " ") == 0 || strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoExpressao"), " ") == 0) // se existe no escopo atual ou global como outro tipo
						no->type = Void_ExpT;
					else
						erroTipo(no, "Variável não declarada");
					break;

				default:
					break;
				}
			break;

		case Declaracao_NodeK:
			switch (no->kind.stmt){
				case If_StmtK:
					if (no->child[0]->type == Integer_ExpT)
						erroTipo(no->child[0], "A condição não é booleana");
					break;

				case Igual_StmtK:
					if (no->child[0]->type != Integer_ExpT)
						erroTipo(no->child[0], "Atribuição para um não inteiro");
					break;

				default:
					break;
				}
			break;

		default:
			break;
		}
}

void checaTipoDoNo(TreeNode *syntaxTree){
	st_insert("input", 0, 0, 4, 1, "Escopo Global", ".", ".", 1);
 	st_insert("output", 0, 0, 4, 1, "Escopo Global", ".", ".", 1);

	VerificaExistenciaDaFuncaoMain();
	
	traverse(syntaxTree, nullProc, checkNode);
}
