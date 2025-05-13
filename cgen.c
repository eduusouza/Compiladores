#include "globals.h"
#include "cgen.h"
#include "symtab.h"

#define MAX_ARGS 4

static int temporario = 0;
static int label = 0;
static int nextSibling = 1;
static int labelEscopoActual = 0;

int returnLabel(){
   return label;
}

static int generateStmt(TreeNode *no){
   switch (no->kind.stmt){
      case ifK:
         fprintf(arquivoIntermediario, "(IF,%d,-,-)\n", no->lineno);
         break;
      case whileK:
         fprintf(arquivoIntermediario, "(WHILE,%d,-,-)\n", no->lineno);
         break;
      case assignK:
         fprintf(arquivoIntermediario, "(ASSIGN,%s,-,-)\n", no->attr.name);
         break;
      case variableK:
         fprintf(arquivoIntermediario, "(VAR,%s,-,-)\n", no->attr.name);
         break;
      case functionK:
         fprintf(arquivoIntermediario, "(FUNC,%s,-,-)\n", no->attr.name);
         break;
      case callK:
         fprintf(arquivoIntermediario, "(CALL,%s,-,-)\n", no->attr.name);
         break;
      case returnK:
         fprintf(arquivoIntermediario, "(RETURN,%d,-,-)\n", no->lineno);
         break;
      case numberK:
         fprintf(arquivoIntermediario, "(NUM,%d,-,-)\n", no->attr.val);
         break;
      case vectorStmtK:
         fprintf(arquivoIntermediario, "(VECTOR,%s,-,-)\n", no->attr.name);
         break;
      default:
         break;
   }
}

static int generateExp(TreeNode *no){
   switch (no->kind.exp){
      case operationK:
         fprintf(arquivoIntermediario, "(OP,%d,-,-)\n", no->attr.op);
         break;
      case constantK:
         fprintf(arquivoIntermediario, "(CONST,%d,-,-)\n", no->attr.val);
         break;
      case idK:
         fprintf(arquivoIntermediario, "(ID,%s,-,-)\n", no->attr.name);
         break;
      case vectorK:
         fprintf(arquivoIntermediario, "(VECTOR,%s,-,-)\n", no->attr.name);
         break;
      case vectorIdK:
         fprintf(arquivoIntermediario, "(VECTOR_ID,%s,-,-)\n", no->attr.name);
         break;
      case typeK:
         fprintf(arquivoIntermediario, "(TYPE,%s,-,-)\n", no->attr.name);
         break;
      default:
         break;
   }  
}

int analyzeNode(TreeNode *no){
   int auxTemp = -1;
   if (no != NULL){
      switch (no->nodekind){
         case statementK:
            auxTemp = generateStmt(no);
            break;
         
         case expressionK:
            auxTemp = generateExp(no);
            break;
         
         default:
            break;
      }

      if(no->sibling != NULL && nextSibling == 1){
         auxTemp = analyzeNode(no->sibling);
      }
   }

   return auxTemp;      
}

void geraIntermediario(TreeNode *no){

   fprintf(arquivoIntermediario, "(CLEAR,-,-,-)\n");
   fprintf(arquivoIntermediario, "(CONST,$sp,500,-)\n");
   fprintf(arquivoIntermediario, "(JUMP_MAIN,-,-,-)\n");

   analyzeNode(no);
}