#include "globals.h"
#include "symtab.h"
#include "cgen.h"
#define MAX_ARGS 4

static int temporario = 0;
static int label = 0;
static int nextSibling = 1;
static int labelEscopoActual = 0;
static int nparams = 0;

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
   TreeNode *auxTree;

   switch (no->kind.stmt){
      case While_StmtK:
         startWhile = label;

         printf("(LABEL,L%d,-,-)\n", startWhile); // Começo do while
         fprintf(arquivoIntermediario, "(LABEL,L%d,-,-)\n", startWhile);    // Começo do while

         label++;
         finishWhile = label;
         label++;

         op = analyzeNode(no->child[0]); // checa condição oposta

         printf("(BNE,$t%d,$zero,L%d)\n", op, finishWhile); // fim do while
         fprintf(arquivoIntermediario, "(BNE,$t%d,$zero,L%d)\n", op, finishWhile);    // fim do while

         ret = analyzeNode(no->child[1]); // executa a parte de dentro do while

         printf("(JUMP,L%d,-,-)\n", startWhile); // volta para o inicio para checar a condição de novo
         fprintf(arquivoIntermediario, "(JUMP,L%d,-,-)\n", startWhile);    // volta para o inicio para checar a condição de novo

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
         printf("(BNE,$t%d,$zero,L%d)\n", ret, label);
         fprintf(arquivoIntermediario, "(BNE,$t%d,$zero,L%d)\n", ret, label);

         // entra no bloco if
         analyzeNode(no->child[1]);
         // Define fim da função (return ou não)
         printf("(JUMP,L%d,-,-)\n", label + 1);
         fprintf(arquivoIntermediario, "(JUMP,L%d,-,-)\n", label + 1);

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
               printf("(NOP,%s,-,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(NOP,%s,-,-)\n", no->attr.name);
               break;

            case Void_ExpT:
               printf("(NOP,%s,-,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(NOP,%s,-,-)\n", no->attr.name);
               break;

            case Boolean_ExpT:
               printf("(NOP,%s,-,-)\n", no->attr.name);
               fprintf(arquivoIntermediario, "(NOP,%s,-,-)\n", no->attr.name);
               break;

            default:
               break;
            }

         analyzeNode(no->child[0]); // args
         analyzeNode(no->child[1]); // interior da função

         if (strcmp(no->attr.name, "main") != 0) {
            temporario++;
            printf("(LOAD,$t%d,0,$ra)\n", temporario);
            fprintf(arquivoIntermediario, "(LOAD,$t%d,0,$ra)\n", temporario);
            printf("(SUBI,$ra,1,$ra)\n");
            fprintf(arquivoIntermediario, "(SUBI,$ra,1,$ra)\n");
            printf("(JUMP_REG,$t%d,-,-)\n", temporario);
            fprintf(arquivoIntermediario, "(JUMP_REG,$t%d,-,-)\n", temporario);
         }
         
         break;

      case Parametro_StmtK:
         // controla o tipo do nó
         switch (no->type){
            case Integer_ExpT:
               printf("(STORE,$a%d,%s,$zero)\n", nparams, no->attr.name);
               fprintf(arquivoIntermediario, "(STORE,$a%d,%s,$zero)\n", nparams, no->attr.name);
               nparams++;
               break;

            case Boolean_ExpT:
               printf("(STORE,$a%d,%s,$zero)\n", nparams, no->attr.name);
               fprintf(arquivoIntermediario, "(STORE,$a%d,%s,$zero)\n", nparams, no->attr.name);
               nparams++;
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
               fprintf(arquivoIntermediario, "(CALL_OUT,$t%d,%s,-)\n", param, no->attr.name); 
            }
         } else {
            if (no->child[0] != NULL){

               printf("\n analyzeNodeCall A SEGUIR \n");
               param = analyzeNodeCall(no->child[0]);
               printf("\n Depois analyzeNodeCall \n");
               printf("(MOVE,$t%d,$a%d,-)\n", param, cont);
               fprintf(arquivoIntermediario, "(MOVE,$t%d,$a%d,-)\n", param, cont);
               
               if (isRecursive){
                  printf("(STORE,$t%d,0,$sp)\n", param);
                  printf("(LI,$sp,1,$sp)\n");
                  fprintf(arquivoIntermediario, "(STORE,$t%d,0,$sp)\n", param);
                  fprintf(arquivoIntermediario, "(LI,$sp,1,$sp)\n");
               }

               cont++;
               irmao = no->child[0]->sibling;
               while (irmao != NULL){
                  param = analyzeNodeCall(irmao);
                  printf("(MOVE,$t%d,$a%d,-)\n", param, cont);
                  fprintf(arquivoIntermediario, "(MOVE,$t%d,$a%d,-)\n", param,cont);
                  
                  if (isRecursive){
                     printf("(STORE,$t%d,0,$sp)\n", param);
                     printf("(LI,$sp,1,$sp)\n");
                     fprintf(arquivoIntermediario, "(STORE,$t%d,0,$sp)\n", param);
                     fprintf(arquivoIntermediario, "(LI,$sp,1,$sp)\n");
                  } 

                  cont++;
                  irmao = irmao->sibling;
               }
            }
            if (strcmp(no->attr.name, "input") == 0){
               printf("(CALL_IN,$t%d,-,-)\n", temporario);
               fprintf(arquivoIntermediario, "(CALL_IN,$t%d,-,-)\n", temporario);
            } else {
               printf("(CALL,$t%d,%s,%d)\n", temporario, name, cont);
               fprintf(arquivoIntermediario, "(CALL,$t%d,%s,%d)\n", temporario, name, cont);
               printf("(STORE,$t%d,0,$ra)\n", temporario);
               fprintf(arquivoIntermediario, "(STORE,$t%d,0,$ra)\n", temporario);
               printf("(LI,$ra,1,$ra)\n");
               fprintf(arquivoIntermediario, "(LI,$ra,1,$ra)\n");
               printf("(JUMP_FUNC,%s,-,-)\n", name);
               fprintf(arquivoIntermediario, "(JUMP_FUNC,%s,-,-)\n", name);

               if (isRecursive) {
                  auxTree = no->child[0];
                  for (int i = cont - 1; i >= 0; i--) {
                     printf("(POP,$sp,%s,-)\n", auxTree->attr.name);
                     fprintf(arquivoIntermediario, "(POP,$sp,%s,-)\n", auxTree->attr.name);
                     if (auxTree->sibling != NULL) {
                        auxTree = auxTree->sibling;
                     }
                  }
               }

               printf("(MOVE,$v0,$t%d,-)\n", temporario);
               fprintf(arquivoIntermediario, "(MOVE,$v0,$t%d,-)\n", temporario);
            }   
            nextSibling = 1;
         }

         return temporario++;

         break;

      case Return_StmtK:
         ret = analyzeNode(no->child[0]);

         temporario--;

         printf("(ADD,$t%d,-,$v0)\n", temporario);
         fprintf(arquivoIntermediario, "(ADD,$t%d,-,$v0)\n", temporario);

         temporario = 0;
         nparams = 0;
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
            printf("(IGUAL,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
            fprintf(arquivoIntermediario, "(IGUAL,$t%d,$t%d,$t%d)\n", param1, param2, temporario);
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
         printf("(LI,$t%d,%d,-)\n", temporario, no->attr.val);
         fprintf(arquivoIntermediario, "(LI,$t%d,%d,-)\n", temporario, no->attr.val);
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
                     fprintf(arquivoIntermediario, "(LI,$t%d,%s,-)\n", temporario, no->attr.name);
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

   fprintf(arquivoIntermediario, "(LI,$ra,50,-)\n");
   fprintf(arquivoIntermediario, "(LI,$sp,100,-)\n");
   fprintf(arquivoIntermediario, "(JUMP_FUNC,main,-,-)\n");
   
   analyzeNode(no);
   
   fprintf(arquivoIntermediario, "(HALT,-,-,-)\n");
}
