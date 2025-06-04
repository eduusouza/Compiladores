#ifndef _ASSEMBLY_H_
#define _ASSEMBLY_H_

typedef struct
{
    char instruc[6];
    char reg1[5];
    char reg2[5];
    char regD[5];
    char label[11];
} ASSEMBLY;

ASSEMBLY *instrucao;

typedef struct
{
    char name[10];
    int posicao;
} LABEL;

LABEL *posicaoLabel;

char registrador[10];

// ARRUMAR VALORES DOS REGISTRADORES COM O PROCESSADOR/RELATORIO
typedef enum
{
    $zero,
    $at,
    $v0,
    $v1,
    $a0,
    $a1,
    $a2,
    $a3,
    $t0,
    $t1,
    $t2,
    $t3,
    $t4,
    $t5,
    $t6,
    $t7,
    $t8,
    $t9,
    $t10,
    $t11,
    $t12,
    $t13,
    $t14,
    $t15,
    $t16,
    $t17,
    $t18,
    $t19,
    $sp,
    $hi,
    $lo,
    $ra
} banco_regs;

int linhaMain;

void geraAssembly ();

#endif