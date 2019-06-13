#include "shell.h"

/* calc.c efetuará a operação dum calculador simples e imprimirá o resultado no ecrã
   Os operandos são floats e o operador é um carcater (+,-,*,/ e exponenciação ^)
*/

void calc (char *operando1, char *operacao, char *operando2)
{
    float op1 = atof(operando1); //converte o argumento para um apontador float
    float op2 = atof(operando2);
    float resultado;

    if(0 == strcmp(operacao,"+")){
        resultado = op1 + op2;
    }
    else
    if(0 == strcmp(operacao,"-")){
        resultado = op1 - op2;
    }
    else
    if(0 == strcmp(operacao,"*")){
        resultado = op1 * op2;
    }
    else
    if(0 == strcmp(operacao,"/")){
        if (op2 == 0.0){
            printf("%sÉ impossível efetuar a divisão por zero!\n",ERROR_TAG);
            return;
        }
        resultado = op1 / op2;
    }
    else
    if(0 == strcmp(operacao,"^")){
        resultado = powf(op1,op2); //powf é igual a pow mas em vez  de devolver um double devolve um float
    }
    else
    {
        printf("%sOperador inválido\n",ERROR_TAG);
        return;
    } 
    printf("%s%0.1f %s %0.1f = %0.1f\n",RESULTADO_TAG,op1,operacao,op2,resultado);
}

void bits(char *operando1, char *operacao, char *operando2)
{
    int op1= atoi(operando1); //converte o argumento para um apontador inteiro
    int op2= atoi(operando2);
    int resultado;

    if((0==strcmp(operacao,"&")) || (0==strcmp(operacao,"&&"))){
        resultado = op1 & op2;
    }
    else
    if(0==strcmp(operacao,"^")){
        resultado = op1 ^ op2;
    }
    else
    if ((0==strcmp(operacao,"|")) || (0==strcmp(operacao,"||"))){
        resultado = op1 | op2;
    }
    else
    {
        printf("%sOperador inválido\n",ERROR_TAG);
        return;
    } 
    printf("%s%d %s %d = %d\n",RESULTADO_TAG,op1,operacao,op2,resultado);

    
}