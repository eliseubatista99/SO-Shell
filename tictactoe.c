#include "shell.h"

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
    printf("\n");
}

void menu_principal()
{
    printf("%s%sEscolha uma opcao:%s\n %s%s1%s- Jogar\n %s%s2%s- Consultar Regras\n %s%s3%s- Sair\n",MAGENTA,BOLD,NORMAL,MAGENTA,BOLD,NORMAL,MAGENTA,BOLD,NORMAL,MAGENTA,BOLD,NORMAL);
}

void consultar_regras()
{
    printf("%s%sRegras:%s\n\n",MAGENTA,BOLD,NORMAL);
    printf(" - %sO jogador 1 usa o símbolo X e o jogador 2 usa o símbolo O%s\n",BOLD,NORMAL);
    printf(" - %sGanha o jogador que conseguir colocar 3 dos seus símbolos em linha (horizontal, vertical ou diagonal)%s\n\n",BOLD,NORMAL);
}

void make_board(char tabuleiro[9])
{
    int i;
    for(i=0;i<9;i++)
    {
        tabuleiro[i]=49+i;
    }
}

void change_board(char tabuleiro[9],char simbolo, char posicao)
{
    int i;
    for(i=0;i<9;i++)
    {
        if(tabuleiro[i]==posicao)
        {
            tabuleiro[i]=simbolo;
        }
    }
}

void display_colored(char tabuleiro[9],int pos)
{
    if(tabuleiro[pos]=='X')
    {
        printf("%s%s%c%s",BLUE,BOLD,tabuleiro[pos],NORMAL);
    }
    else if(tabuleiro[pos]=='O')
    {
        printf("%s%s%c%s",YELLOW,BOLD,tabuleiro[pos],NORMAL);
    }
    else
    {
        printf("%c",tabuleiro[pos]);
    }
    

               
            
}

void display_board(char tabuleiro[9])
{
    printf("       |       |       \n");   
    printf("   ");
    display_colored(tabuleiro,0); 
    printf("   |   ");
    display_colored(tabuleiro,1); 
    printf("   |   ");
    display_colored(tabuleiro,2);
    printf("   \n"); 
    printf("       |       |       \n");
    printf("------------------------\n");
    printf("       |       |       \n");   
    printf("   ");
    display_colored(tabuleiro,3); 
    printf("   |   ");
    display_colored(tabuleiro,4); 
    printf("   |   ");
    display_colored(tabuleiro,5);
    printf("   \n"); 
    printf("       |       |       \n");
    printf("------------------------\n");
        printf("       |       |       \n");   
    printf("   ");
    display_colored(tabuleiro,6); 
    printf("   |   ");
    display_colored(tabuleiro,7); 
    printf("   |   ");
    display_colored(tabuleiro,8);
    printf("   \n"); 
    printf("       |       |       \n");
    printf("------------------------\n");

}

int check_vencedor(char tabuleiro[9],char simbolo)
{
    if(tabuleiro[0]==simbolo && tabuleiro[1]==simbolo && tabuleiro[2]==simbolo)
        return 1;
    else if(tabuleiro[3]==simbolo && tabuleiro[4]==simbolo && tabuleiro[5]==simbolo)
        return 1;
    else if(tabuleiro[6]==simbolo && tabuleiro[7]==simbolo && tabuleiro[8]==simbolo)
        return 1;
    else if(tabuleiro[0]==simbolo && tabuleiro[3]==simbolo && tabuleiro[6]==simbolo)
        return 1;
    else if(tabuleiro[1]==simbolo && tabuleiro[4]==simbolo && tabuleiro[7]==simbolo)
        return 1;
    else if(tabuleiro[2]==simbolo && tabuleiro[5]==simbolo && tabuleiro[8]==simbolo)
        return 1;
    else if(tabuleiro[0]==simbolo && tabuleiro[4]==simbolo && tabuleiro[8]==simbolo)
        return 1;
    else if(tabuleiro[2]==simbolo && tabuleiro[4]==simbolo && tabuleiro[6]==simbolo)
        return 1;
    else
        return 0;
}

int check_board(char tabuleiro[9])
{
    if(tabuleiro[0]!='1' && tabuleiro[1]!='2' && tabuleiro[2]!='3' && tabuleiro[3]!='4' && tabuleiro[4]!='5' && tabuleiro[5]!='6' && tabuleiro[6]!='7' && tabuleiro[7]!='8' && tabuleiro[8]!='9')
        return 1;
    return 0;
}

int jogar_tictactoe(char tabuleiro[9], char jogador1[20],char jogador2[20])
{
    char jogada1,jogada2;
    int win1=0,win2=0,draw=0,parar=0;
    do
    {
        clearScreen();
        display_board(tabuleiro);
        printf("%s%s%s%s faça a sua jogada\n",BLUE,BOLD,NORMAL,jogador1);
        scanf(" %c",&jogada1);
        while (jogada1!='1' && jogada1!='2' && jogada1!='3' && jogada1!='4' && jogada1!='5' && jogada1!='6' && jogada1!='7' && jogada1!='8' && jogada1!='9'){
            printf("%s%sPosição inválida%s\n",RED,BOLD,NORMAL);
            scanf(" %c",&jogada1);
        }
        change_board(tabuleiro,'X',jogada1);
        win1=check_vencedor(tabuleiro,'X');
        if(win1==1)
        {
            return 1;
        }
        parar=check_board(tabuleiro);
        if(parar==1)
        {
            return 3;
        }
        clearScreen();
        display_board(tabuleiro);
        printf("%s%s%s%s faça a sua jogada\n",YELLOW,BOLD,NORMAL,jogador2);
        scanf(" %c",&jogada2);
        while (jogada2!='1' && jogada2!='2' && jogada2!='3' && jogada2!='4' && jogada2!='5' && jogada2!='6' && jogada2!='7' && jogada2!='8' && jogada2!='9'){
            printf("%s%sPosição inválida%s\n",RED,BOLD,NORMAL);
            scanf(" %c",&jogada2);
        }
        change_board(tabuleiro,'O',jogada2);
        win2=check_vencedor(tabuleiro,'O');
        if(win2==1)
        {
            return 2;
        }
        parar=check_board(tabuleiro);
        if(parar==1)
        {
            return 3;
        }
        draw=check_board(tabuleiro);
        if(draw==1)
        {
            return 3;
        }
    } while (win1!=1 && win2!=1);
    return 0;
}

void tictactoe()
{
    int menu=0,win=0,sair=0;
    char tabuleiro[9],jogador1[20],jogador2[20];
    printf("%s%sBem vindo ao Tic Tac Toe%s\n",MAGENTA,BOLD,NORMAL);
    do
    {
        menu_principal();
        scanf("%d",&menu);
        switch (menu)
        {
        case 1:
            make_board(tabuleiro);
            printf("%sIntroduza o nome do jogador 1%s\n",BOLD,NORMAL);
            scanf("%s",jogador1);
            printf("%sIntroduza o nome do jogador 2%s\n",BOLD,NORMAL);
            scanf("%s",jogador2);
            win=jogar_tictactoe(tabuleiro,jogador1,jogador2);
            if(win==1)
            {
                printf("\n%sO vencedor e: %s%s%s\n",BOLD,BLUE,jogador1,NORMAL);
                sair=1;
            }
            if(win==2)
            {
                printf("\n%sO vencedor e: %s%s%s\n",BOLD,YELLOW,jogador2,NORMAL);
                sair=1;
            }
            if(win==3)
            {
                printf("\n%sEmpate%s\n",BOLD,NORMAL);
                sair=1;
            }
            break;
        case 2:
            consultar_regras();
            break;
        case 3:
            sair=1;
            break;
        default:
            printf("\n%s%sOpcao invalida%s\n",RED,BOLD,NORMAL);
            break;
        }
    } while (sair!=1);
    
    
    
}