#include "globals.h"
#include "symtab.h"
#include "cgen.h"
#define MAX_ARGS 4

static int temporario = 0;
static int label = 0;
static int nextSibling = 1;
static int labelEscopoActual = 0;

int analyzeNode(TreeNode *no);
int analyzeNodeCall(TreeNode *no);

int returnLabel(){
   return label;
}

static int generateStmt(TreeNode *no){
   int ret, op;
   int base, pos;
   int aux;
   int cont, param;
   int startWhile, finishWhile;
   char *name;
   TreeNode *irmao;

   switch (no->kind.stmt){
      case While_StmtK:
         startWhile = label;

         printf("(LABEL,L%d,-,-)\n", startWhile); // Começo do while
         fprintf(arquivoIntermediario, "(LABEL,L%d,-,-)\n", startWhile);    // Começo do while

         label++;
         finishWhile = label;
         label++;

         op = analyzeNode(no->child[0]); // checa condição oposta

         printf("(IF,$t%d,L%d,-)\n", op, finishWhile); // fim do while
         fprintf(arquivoIntermediario, "(IF,$t%d,L%d,-)\n", op, finishWhile);    // fim do while

         ret = analyzeNode(no->child[1]); // executa a parte de dentro do while

         printf("(GOTO,L%d,-,-)\n", startWhile); // volta para o inicio para checar a condição de novo
         fprintf(arquivoIntermediario, "(GOTO,L%d,-,-)\n", startWhile);    // volta para o inicio para checar a condição de novo

         printf("(LABEL,L%d,-,-)\n", finishWhile); // label do fim do while
         fprintf(arquivoIntermediario, "(LABEL,L%d,-,-)\n", finishWhile);    // label do fim do while
         break;

      case Igual_StmtK:
         base = analyzeNode(no->child[1]);

         // verifica se pertence a um vetor
         if (no->child[0]->child[0] != NULL){
            if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->child[0]->attr.name, no->child[0]->attr.escopo, "tipoParametro"), "sim") == 0){
               aux = temporario;
               fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario++, no->child[0]->attr.name); // load com offset

               pos = analyzeNode(no->child[0]->child[0]);
               fprintf(arquivoIntermediario, "(ADD,$t%d,$t%d,$t%d)\n", aux, pos, temporario); // load com offset
               fprintf(arquivoIntermediario, "(STORE,$t%d,0,$t%d)\n", base, temporario);
            } else {
               pos = analyzeNode(no->child[0]->child[0]);

               printf("(STORE,$t%d,%s,$t%d)\n", base, no->child[0]->attr.name, pos);
               fprintf(arquivoIntermediario, "(STORE,$t%d,%s,$t%d)\n", base, no->child[0]->attr.name, pos);
            }
         } else {
            printf("(STORE,$t%d,%s,-)\n", base, no->child[0]->attr.name);
            fprintf(arquivoIntermediario, "(STORE,$t%d,%s,-)\n", base, no->child[0]->attr.name);
         }

         temporario = 0;
         break;

      case If_StmtK:
         // salva em ret o resultado da condição referente ao teste do IF
         ret = analyzeNode(no->child[0]);

         // condição análoga = TRUE, GOTO Else
         printf("(IF,$t%d,L%d,-)\n", ret, label);
         fprintf(arquivoIntermediario, "(IF,$t%d,L%d,-)\n", ret, label);

         // entra no bloco if
         analyzeNode(no->child[1]);
         // Define fim da função (return ou não)
         printf("(GOTO,L%d,-,-)\n", label + 1);
         fprintf(arquivoIntermediario, "(GOTO,L%d,-,-)\n", label + 1);

         // marca o começo do else
         printf("(LABEL,L%d,-,-)\n", label); // bloco else
         fprintf(arquivoIntermediario, "(LABEL,L%d,-,-)\n", label);    // bloco else
         label++;

         analyzeNode(no->child[2]);

         // Define o fim do bloco if-else
         printf("(LABEL,L%d,-,-)\n", label);
         fprintf(arquivoIntermediario, "(LABEL,L%d,-,-)\n", label);
         label++;
         break;

      // declaração de uma variavel, com seu nome e escopo
      case Variavel_StmtK:
         printf("(ALLOC,%s,%s,-)\n", no->attr.name, no->attr.escopo);
         fprintf(arquivoIntermediario, "(ALLOC,%s,%s,-)\n", no->attr.name, no->attr.escopo);
         // temporario++;
         break;

      // declaração de um vetor, com seu nome, escopo e tamanho
      case Vetor_StmtK:
         printf("(ALLOC_V,%s,%s,%d)\n", no->attr.name, no->attr.escopo, no->attr.len);
         fprintf(arquivoIntermediario, "(ALLOC_V,%s,%s,%d)\n", no->attr.name, no->attr.escopo, no->attr.len);
         return -1;
         break;

      case Funcao_StmtK:
         temporario = 0;
         switch (no->type){
            case Integer_ExpT:
               printf("(FUNC,int,%s,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(FUNC,int,%s,-)\n", no->attr.name);
               break;

            case Void_ExpT:
               printf("(FUNC,void,%s,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(FUNC,void,%s,-)\n", no->attr.name);
               break;

            case Boolean_ExpT:
               printf("(FUNC,bool,%s,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(FUNC,bool,%s,-)\n", no->attr.name);
               break;

            default:
               break;
            }

         analyzeNode(no->child[0]); // args
         analyzeNode(no->child[1]); // interior da função

         printf("(END,%s,-,-)\n", no->attr.name);
         fprintf(arquivoIntermediario, "(END,%s,-,-)\n", no->attr.name);
         break;

      case Parametro_StmtK:
         // controla o tipo do nó
         switch (no->type){
            case Integer_ExpT:
               printf("(PARAM,int,%s,%s)\n", no->attr.name, no->attr.escopo);
               fprintf(arquivoIntermediario, "(PARAM,int,%s,%s)\n", no->attr.name, no->attr.escopo);

               printf("(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
               fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
               temporario++;
               break;

            case Boolean_ExpT:
               printf("(PARAM,bool,%s,%s)\n", no->attr.name, no->attr.escopo);
               fprintf(arquivoIntermediario, "(PARAM,bool,%s,%s)\n", no->attr.name, no->attr.escopo);

               printf("(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
               fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
               temporario++;
               break;

            default:
               break;
            }
         break;

      case Call_StmtK:
         nextSibling = 0;
         cont = 0;
         name = no->attr.name;

         if (strcmp(no->attr.name, "output") == 0){
            if (no->child[0] != NULL){
               param = analyzeNodeCall(no->child[0]);

               fprintf(arquivoIntermediario, "(CALL_OUT,$t%d,%s,_)\n", param, no->attr.name);
            }
         } else {
            if (no->child[0] != NULL){
               // empilha o endereço de retorno ($ra)

               fprintf(arquivoIntermediario, "(CONST,$t%d,PC,-)\n", temporario);

               fprintf(arquivoIntermediario, "(STORE,$t%d,0,$sp)\n", temporario++);

               fprintf(arquivoIntermediario, "(CONST,$t%d,1,-)\n", temporario);

               fprintf(arquivoIntermediario, "(ADD,$sp,$t%d,$sp)\n", temporario++);
               printf("\n analyzeNodeCall A SEGUIR \n");
               param = analyzeNodeCall(no->child[0]);
               printf("\n Depois analyzeNodeCall \n");
               printf("(ARG,$t%d,-,-)\n", param);
               fprintf(arquivoIntermediario, "(ARG,$t%d,-,-)\n", param);
               cont++;
               irmao = no->child[0]->sibling;
               while (irmao != NULL){
                  param = analyzeNodeCall(irmao);
                  printf("(ARG,$t%d,-,-)\n", param);
                  fprintf(arquivoIntermediario, "(ARG,$t%d,-,-)\n", param);
                  cont++;
                  irmao = irmao->sibling;
               }
            }
            printf("(CALL,$t%d,%s,%d)\n", temporario, name, cont);
            fprintf(arquivoIntermediario, "(CALL,$t%d,%s,%d)\n", temporario, name, cont);

            nextSibling = 1;

            printf("(ADD,$v0,-,$t%d)\n", temporario);
            fprintf(arquivoIntermediario, "(ADD,$v0,-,$t%d)\n", temporario);
         }

         return temporario++;

         break;

      case Return_StmtK:
         ret = analyzeNode(no->child[0]);
         temporario--;

         printf("(ADD,$t%d,-,$v0)\n", temporario);
         fprintf(arquivoIntermediario, "(ADD,$t%d,-,$v0)\n", temporario);

         temporario++;

         fprintf(arquivoIntermediario, "(CONST,$t%d,1,-)\n", temporario);
         fprintf(arquivoIntermediario, "(SUB,$sp,$t%d,$sp)\n", temporario++);
         fprintf(arquivoIntermediario, "(LOAD,$ra,0,$sp)\n");

         printf("(RETURN,$v0,-,-)\n");
         fprintf(arquivoIntermediario, "(RETURN,$v0,-,-)\n");

         temporario = 0;
         break;

      default:
         break;
      }
}

static int generateExp(TreeNode *no){
   int aux1, aux2;
   int param1, param2;

   switch (no->kind.exp){
      case Operacao_ExpK:
         param1 = analyzeNode(no->child[0]);
         param2 = analyzeNode(no->child[1]);

         switch (no->attr.op){
         case ADD:
            printf("(ADD,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(ADD,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case SUB:
            printf("(SUB,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(SUB,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case MULT:
            printf("(MULT,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(MULT,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case DIV:
            printf("(DIV,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(DIV,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case COMP:
            printf("(DIF,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(DIF,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case DIF:
            printf("(COMP,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(COMP,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case MENOR:
            printf("(MAIORIG,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(MAIORIG,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case MAIOR:
            printf("(MENORIG,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(MENORIG,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case MENORIG:
            printf("(MAIOR,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(MAIOR,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         case MAIORIG:
            printf("(MENOR,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(MENOR,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            break;

         default:
            break;
         }
         return temporario++;
         break;

      case Constante_ExpK:
         printf("(CONST,$t%d,%d,-)\n", temporario, no->attr.val);
         fprintf(arquivoIntermediario, "(CONST,$t%d,%d,-)\n", temporario, no->attr.val);
         return temporario++;
         break;

      case ID_ExpK:
         if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoVetor"), "sim") == 0 || strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoVetor"), "sim") == 0){
            printf("(LOAD_VARG,$t%d,%s,-)\n", temporario, no->attr.name);
            fprintf(arquivoIntermediario, "(LOAD_VARG,$t%d,%s,-)\n", temporario, no->attr.name);
         } else {
            printf("(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
            fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario, no->attr.name);
         }
         return temporario++;
         break;

      case Vetor_ExpK:
         aux1 = analyzeNode(no->child[0]);
         if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoParametro"), "sim") == 0){
            aux2 = temporario;
            fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario++, no->attr.name); // load com offset

            fprintf(arquivoIntermediario, "(ADD,$t%d,$t%d,$t%d)\n", aux1, aux2, temporario++); // load com offset

            printf("(LOAD,$t%d,0,$t%d)\n", temporario, temporario - 1);
            fprintf(arquivoIntermediario, "(LOAD,$t%d,0,$t%d)\n", temporario, temporario - 1);
         } else {
            printf("\n\nAUX1: %d\n\n", aux1);

            printf("(LOAD_V,$t%d,%s,$t%d)\n", temporario, no->attr.name, aux1);
            fprintf(arquivoIntermediario, "(LOAD_V,$t%d,%s,$t%d)\n", temporario, no->attr.name, aux1);
         }

         aux2 = temporario;
         temporario++;
         return aux2;
         break;

      case Tipo_ExpK:
         analyzeNode(no->child[0]);
         break;

      default:
         break;
      }
}

int analyzeNode(TreeNode *no){
   int auxTemp = -1;
   if (no != NULL){
      switch (no->nodekind){
         case Declaracao_NodeK:
            auxTemp = generateStmt(no);
            break;

         case EXP_NodeK:
            auxTemp = generateExp(no);
            break;

         default:
            break;
         }

      if (no->sibling != NULL && nextSibling == 1)
         auxTemp = analyzeNode(no->sibling);
   }
   return auxTemp;
}

int analyzeNodeCall(TreeNode *no){
   int auxTemp = -1;
   if (no != NULL){
      switch (no->nodekind){
         case Declaracao_NodeK:
            auxTemp = generateStmt(no);
            break;

         case EXP_NodeK:
            if (no->kind.exp == Vetor_ExpK){ 
               if (no->child[0] == NULL){
                  printf("\n antes charverifica\n");
                  if (strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, "Global", "tipoParametro"), "nao") == 0 ||
                     strcmp(CharVerificaOcorrenciaNoMesmoEscopo(no->attr.name, no->attr.escopo, "tipoParametro"), "nao") == 0){
                     fprintf(arquivoIntermediario, "(CONST,$t%d,%s,-)\n", temporario, no->attr.name);
                  } else {
                     fprintf(arquivoIntermediario, "(LOAD,$t%d,%s,-)\n", temporario, no->attr.name); // load com offset
                  }
                  auxTemp = temporario;
                  break;
               }
            }
            auxTemp = generateExp(no);
            break;

         default:
            break;
         }

      if (no->sibling != NULL && nextSibling == 1){
         auxTemp = analyzeNode(no->sibling);
      }
   }

   return auxTemp;
}

void geraIntermediario(TreeNode *no){

   fprintf(arquivoIntermediario, "CODIGO INTERMEDIARIO:\n");

   fprintf(arquivoIntermediario, "(NOP,-,-,-)\n");
   fprintf(arquivoIntermediario, "(JUMP_MAIN,-,-,-)\n");

   analyzeNode(no);
   
   fprintf(arquivoIntermediario, "(HALT,-,-,-)\n");
}
