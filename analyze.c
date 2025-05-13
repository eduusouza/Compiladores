
#include "globals.h"
#include "symtab.h"
#include "analyze.h"

/* counter for variable memory locations */
static int location = 0;

/* Procedure traverse is a generic recursive 
 * syntax tree traversal routine:
 * it applies preProc in preorder and postProc 
 * in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t, void (* preProc) (TreeNode *), void (* postProc) (TreeNode *) ){ 
  if (t != NULL){
    preProc(t);
    int i;
    for (i=0; i < MAXCHILDREN; i++){
      traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/* nullProc is a do-nothing procedure to 
 * generate preorder-only or postorder-only
 * traversals from traverse
 */
static void nullProc(TreeNode * t)
{ if (t==NULL) return;
  else return;
}

/* Procedure insertNode inserts 
 * identifiers stored in t into 
 * the symbol table 
 */
static void insertNode(TreeNode *t)
{

	switch (t->nodekind){
    case statementK:
      switch (t->kind.stmt){
        case variableK:
          if (st_lookup(t->attr.name, t->attr.scope, "variable") == -1 && st_lookup(t->attr.name, "global", "variable") == -1)
            st_insert(t->attr.name, t->lineno, location++, t->attr.scope, "variable", "integer", t->attr.len);
          else
            printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Declaração inválida: Variável já foi declarada.");
	          Error = TRUE;
          break;
        case vectorStmtK:
          if (st_lookup(t->attr.name, t->attr.scope, "vector") == -1 && st_lookup(t->attr.name, "global", "vector") == -1)
            st_insert(t->attr.name, t->lineno, location++, t->attr.scope, "vector", "integer", t->attr.len);
          else
            printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Declaração inválida: Vetor já foi declarado.");
            Error = TRUE;
          break;
        case functionK:
          if (st_lookup(t->attr.name, t->attr.scope, "function") == -1 && st_lookup(t->attr.name, "global", "function") == -1){
            if (t->type == integerK)
              st_insert(t->attr.name, t->lineno, location++, t->attr.scope, "function", "integer", t->attr.len);
            else
              st_insert(t->attr.name, t->lineno, location++, t->attr.scope, "function", "void", t->attr.len);
          }
          else{
            printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Declaração inválida: Função já foi declarada.");
	          Error = TRUE;
          }
          break;
        case callK:
          if (st_lookup(t->attr.name, t->attr.scope, "call") == -1 && 
          st_lookup(t->attr.name, "global", "call") == -1 && 
          st_lookup(t->attr.name, "input", "call") != -1 &&
          st_lookup(t->attr.name, "output", "call") != -1
          ){
            printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Chamada de função inválida.");
	          Error = TRUE;
          }else{
            st_insert(t->attr.name, t->lineno, location++, t->attr.scope, "call", "-", t->attr.len);
          }
          break;
        case returnK:
          break;
        default:
          break;
      }
      break;
    case expressionK:
      switch (t->kind.exp){
      case idK:
        //caso o id nao esteja
        if (st_lookup(t->attr.name, t->attr.scope, "variable") == -1 && st_lookup(t->attr.name, "global", "variable") == -1){
          printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Expressão de variavel não declarada.");
	        Error = TRUE;
        }else{
          st_insert(t->attr.name, t->lineno, 0, t->attr.scope, "variable", "integer", t->attr.len);
        }
        break;
      case vectorK:
        if (st_lookup(t->attr.name, t->attr.scope, "vector") == -1 && st_lookup(t->attr.name, "global", "vector") == -1){
          printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Expressão de vetor não declarada.");
	        Error = TRUE;
        }else{
          st_insert(t->attr.name, t->lineno, 0, t->attr.scope, "vector", "integer", t->attr.len);
        }
        break;
      case vectorIdK:
        if (st_lookup(t->attr.name, t->attr.scope, "vector index") == -1 && st_lookup(t->attr.name, "global", "vector index") == -1){
          printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Expressão com index de vetor não declarada.");
	        Error = TRUE;
        }else{
          st_insert(t->attr.name, t->lineno, 0, t->attr.scope, "vector index", "integer", t->attr.len);
        }
        break;
      case typeK:
        break;
      default:
        break;
      }
      break;
    default:
      break;
	}
}


/* Function buildSymtab constructs the symbol 
 * table by preorder traversal of the syntax tree
 */
void buildSymtab(TreeNode * syntaxTree){ 
  
  traverse(syntaxTree,insertNode,nullProc);

  if (st_lookup("main", "global", "function") == -1)
	{
		printf("ERRO SEMÂNTICO: Função main não foi declarada.");
		Error = TRUE;
	}

  if (TraceAnalyze)
  { printf("\nSymbol table:\n\n");
    printSymTab();
  }
}

static void checkNode(TreeNode *t)
{
	switch (t->nodekind)
	{
	case expressionK:
		switch (t->kind.exp){
		case operationK:
			break;
		default:
			break;
		}
		break;
	case statementK:
		switch (t->kind.stmt)
		{
		case ifK:
			if (t->child[0]->type == integerK && t->child[1]->type == integerK){
        printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Expressão do IF inválida.");
	      Error = TRUE;
      }
			break;
		case assignK:
			if (t->child[0]->type == voidK || t->child[1]->type == voidK){
        printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->attr.name, t->lineno, "Atribuição inválida: Atribuição de valor não inteiro");
	      Error = TRUE;
      }
			else if (t->child[1]->kind.stmt == callK){
        if (!(strcmp(findFunType(t->child[1]->attr.name, "global"), "void")))
          printf("ERRO SEMÂNTICO: %s LINHA %d: MENSAGEM: %s\n", t->child[0]->attr.name, t->lineno, "Atribuição inválida: Atribuição de função VOID.");
	        Error = TRUE;
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

void typeCheck(TreeNode *syntaxTree)
{
	traverse(syntaxTree, nullProc, checkNode);
}