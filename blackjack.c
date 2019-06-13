#include "shell.h"

void limparScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO,CLEAR_SCREEN_ANSI,12);
    printf("\n");
}

void menu()
{
    printf("\n%s%sBem vindo ao BlackJack\n%s\n Escolha uma opção:\n",MAGENTA,BOLD,NORMAL);
    printf("\t%s%s1%s - Jogar\n",MAGENTA,BOLD,NORMAL);
    printf("\t%s%s2%s - Consultar Regras\n",MAGENTA,BOLD,NORMAL);
    printf("\t%s%s3%s - Sair\n",MAGENTA,BOLD,NORMAL);
}

void regras()
{
    int opcao;
    int sair=0;
    do
    {
        printf("%s%s\nQue informações deseja consultar?%s\nEscolha uma opcao:\n",MAGENTA,BOLD,NORMAL);
        printf("%s%s1%s - Como vencer\n",MAGENTA,BOLD,NORMAL);
        printf("%s%s2%s - Como jogar\n",MAGENTA,BOLD,NORMAL);
        printf("%s%s3%s - Valores das cartas\n",MAGENTA,BOLD,NORMAL);
        printf("%s%s4%s - Sair\n",MAGENTA,BOLD,NORMAL);
        
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                printf("%s%s\nComo vencer:%s\n",MAGENTA,BOLD,NORMAL);
                printf(" - O objetivo em qualquer mão de blackjack é %sganhar ao dealer%s\n",BOLD,NORMAL);
                printf(" - Ganha o jogador que conseguir uma mão %smais alta%s, sem ultrapassar %sos 21 pontos%s\n",BOLD,NORMAL,BOLD,NORMAL);
                break;
            case 2:
                printf("%s%s\nComo jogar:%s\n",MAGENTA,BOLD,NORMAL);
                printf(" - Quando solicitado, pode %spedir cartas%s para a sua mão para %saumentar o seu valor total%s\n",BOLD,NORMAL,BOLD,NORMAL);
                printf(" - Quando %sparar%s de pedir cartas, o %sdealer completa a sua mão%s\n",BOLD,NORMAL,BOLD,NORMAL);
                break;
            case 3:
                printf("%s%s\nValores das cartas:%s\n",MAGENTA,BOLD,NORMAL);
                printf(" - %sDois%s: 2 pontos\n",BOLD,NORMAL);
                printf(" - %sTres%s: 3 pontos\n",BOLD,NORMAL);
                printf(" - %sQuatro%s: 4 pontos\n",BOLD,NORMAL);
                printf(" - %sCinco%s: 5 pontos\n",BOLD,NORMAL);
                printf(" - %sSeis%s: 6 pontos\n",BOLD,NORMAL);
                printf(" - %sSete%s: 7 pontos\n",BOLD,NORMAL);
                printf(" - %sOito%s: 8 pontos\n",BOLD,NORMAL);
                printf(" - %sNove%s: 9 pontos\n",BOLD,NORMAL);
                printf(" - %sDez%s: 10 pontos\n",BOLD,NORMAL);
                printf(" - %sDama%s: 10 pontos\n",BOLD,NORMAL);
                printf(" - %sValete%s: 10 pontos\n",BOLD,NORMAL);
                printf(" - %sRei%s: 10 pontos\n",BOLD,NORMAL);
                printf(" - %sAs%s: 11 pontos\n",BOLD,NORMAL);
                break;
            case 4:
                sair=1;
                break;
            default:
                break;
        }
    } while (sair!=1);
    
}

void all_values(int carta)
{
 switch (carta)
 {
        case 1:
            printf("Dois de Copas\n");
        break;
        case 2:
            printf("Tres de Copas\n");
        break;
        case 3:
            printf("Quatro de Copas\n");
        break;
        case 4:
            printf("Cinco de Copas\n");
        break;
        case 5:
            printf("Seis de Copas\n");
        break;
        case 6:
            printf("Sete de Copas\n");
        break;
        case 7:
            printf("Oito de Copas\n");
        break;
        case 8:
            printf("Nove de Copas\n");
        break;
        case 9:
            printf("Dez de Copas\n");
        break;
        case 10:
            printf("Dama de Copas\n");
        break;
        case 11:
            printf("Valete de Copas\n");
        break;
        case 12:
            printf("Rei de Copas\n");
        break;
        case 13:
            printf("As de Copas\n");
        break;
        case 14:
            printf("Dois de Espadas\n");
        break;
        case 15:
            printf("Tres de Espadas\n");
        break;
        case 16:
            printf("Quatro de Espadas\n");
        break;
        case 17:
            printf("Cinco de Espadas\n");
        break;
        case 18:
            printf("Seis de Espadas\n");
        break;
        case 19:
            printf("Sete de Espadas\n");
        break;
        case 20:
            printf("Oito de Espadas\n");
        break;
        case 21:
            printf("Nove de Espadas\n");
        break;
        case 22:
            printf("Dez de Espadas\n");
        break;
        case 23:
            printf("Dama de Espadas\n");
        break;
        case 24:
            printf("Valete de Espadas\n");
        break;
        case 25:
            printf("Rei de Espadas\n");
        break;
        case 26:
            printf("As de Espadas\n");
        break;
        case 27:
            printf("Dois de Paus\n");
        break;
        case 28:
            printf("Tres de Paus\n");
        break;
        case 29:
            printf("Quatro de Paus\n");
        break;
        case 30:
            printf("Cinco de Paus\n");
        break;
        case 31:
            printf("Seis de Paus\n");
        break;
        case 32:
            printf("Sete de Paus\n");
        break;
        case 33:
            printf("Oito de Paus\n");
        break;
        case 34:
            printf("Nove de Paus\n");
        break;
        case 35:
            printf("Dez de Paus\n");
        break;
        case 36:
            printf("Dama de Paus\n");
        break;
        case 37:
            printf("Valete de Paus\n");
        break;
        case 38:
            printf("Rei de Paus\n");
        break;
        case 39:
            printf("As de Paus\n");
        break;
        case 40:
            printf("Dois de Ouros\n");
        break;
        case 41:
            printf("Tres de Ouros\n");
        break;
        case 42:
            printf("Quatro de Ouros\n");
        break;
        case 43:
            printf("Cinco de Ouros\n");
        break;
        case 44:
            printf("Seis de Ouros\n");
        break;
        case 45:
            printf("Sete de Ouros\n");
        break;
        case 46:
            printf("Oito de Ouros\n");
        break;
        case 47:
            printf("Nove de Ouros\n");
        break;
        case 48:
            printf("Dez de Ouros\n");
        break;
        case 49:
            printf("Dama de Ouros\n");
        break;
        case 50:
            printf("Valete de Ouros\n");
        break;
        case 51:
            printf("Rei de Ouros\n");
        break;
        case 52:
            printf("As de Ouros\n");
        break;
        default:
        break;
 }   
}

int match_pontos(int carta)
{
    if(carta==1 || carta==14 || carta==27 || carta==40)
    {
        return 2;
    }
    if(carta==2 || carta==15 || carta==28 || carta==41)
    {
        return 3;
    }
    if(carta==3 || carta==16 || carta==29 || carta==42)
    {
        return 4;
    }
    if(carta==4 || carta==17 || carta==30 || carta==43)
    {
        return 5;
    }
    if(carta==5 || carta==18 || carta==31 || carta==44)
    {
        return 6;
    }
    if(carta==6 || carta==19 || carta==32 || carta==45)
    {
        return 7;
    }
    if(carta==7 || carta==20 || carta==33 || carta==46)
    {
        return 8;
    }
    if(carta==8 || carta==21 || carta==34 || carta==47)
    {
        return 9;
    }
    if(carta==9 || carta==22 || carta==35 || carta==48)
    {
        return 10;
    }
    if(carta==10 || carta==23 || carta==36 || carta==49)
    {
        return 10;
    }
    if(carta==11 || carta==24 || carta==37 || carta==50)
    {
        return 10;
    }
    if(carta==12 || carta==25 || carta==38 || carta==51)
    {
        return 10;
    }
    if(carta==13 || carta==26 || carta==39 || carta==52)
    {
        return 11;
    }
    else{
        return 1;
    }
}

void criardeck(int deck[52])
{
    int i;
    for(i=1;i<=52;i++){
        deck[i]=i;
    }
}

void baralhar_deck(int *deck)
{
    int i,index,aux;
    for(i=0;i<52;i++)
    {
        index=(rand() % 51);
        aux=deck[index];
        deck[index]=deck[i];
        deck[i]=aux;
    }
}

void distribuir_cartas(int *deck,int *jogador,int tam_deck, int tam_jogador)
{
    tam_deck--;
    jogador[0]=deck[tam_deck];
    tam_deck--;
    jogador[1]=deck[tam_deck];
}

int conta_pontos(int *jogador,int tam_jogador)
{
    int pontos=0,i;
    for(i=0;i<tam_jogador;i++)
    {
        pontos=pontos+match_pontos(jogador[i]);
    }
    return pontos;
}

void mostra_detalhes(int *jogador, int tam_jogador,int pontos)
{
    int i;
    printf("\t%sMão:%s\n",BOLD,NORMAL);
    for(i=0;i<tam_jogador;i++)
    {
        printf("\t");
        all_values(jogador[i]);
        printf("\n");
    }
    printf("\t%sPontos: %s%d\n",BOLD,NORMAL,pontos);
    printf("\n");
}

int check_end_game(int pontos_jogador,int pontos_dealer)
{
    if(pontos_jogador>21)
    {
        return 1;
    }
    if(pontos_dealer>21)
    {
        return 2;
    }
    return 0;
}

void proxima_carta(int *deck,int *jogador,int tam_deck,int tam_jogador)
{
    jogador=(int *) realloc (jogador,(tam_jogador+1)*sizeof(int));
    jogador[tam_jogador]=deck[tam_deck-1];
    deck=(int *) realloc (deck,(tam_deck-1)*sizeof(int));
}

int dealer_moves(int *deck, int *dealer,int tam_deck, int tam_dealer,int pontos_dealer,int pontos_jogador)
{

    if(pontos_dealer<21 && pontos_dealer<pontos_jogador){
        proxima_carta(deck,dealer,tam_deck,tam_dealer);
    }
    if(pontos_dealer<21 && pontos_dealer>pontos_jogador){
        return 1;
    }
    return 0;
}

void jogar()
{
    int sair=0,win=0,fim=0,opcao=0,cont=0,*deck,*jogador,*dealer,finale=0;
    int tam_deck=52;
    int tam_jogador=0;
    int tam_dealer=0;
    int pontos_jogador=0;
    int pontos_dealer=0;
    deck=(int *) malloc (52*sizeof(int));
    criardeck(deck);
    baralhar_deck(deck);
    jogador=(int *) malloc (2*sizeof(int));
    dealer=(int *) malloc (2*sizeof(int));
    distribuir_cartas(deck,jogador,tam_deck,tam_jogador);
    tam_deck=tam_deck-2;
    tam_jogador=tam_jogador+2;
    distribuir_cartas(deck,dealer,tam_deck,tam_dealer);
    tam_deck=tam_deck-2;
    tam_dealer=tam_dealer+2;
    limparScreen();
    printf("%s%sDealer%s:\n",MAGENTA,BOLD,NORMAL);
    pontos_dealer=conta_pontos(dealer,tam_dealer);
    mostra_detalhes(dealer,tam_dealer,pontos_dealer);
    printf("\n%s%sJogador:%s\n",MAGENTA,BOLD,NORMAL);
    pontos_jogador=conta_pontos(jogador,tam_jogador);
    mostra_detalhes(jogador,tam_jogador,pontos_jogador);
    do
    {
        if(cont>0)
        {
            printf("%s%sDealer%s:\n",MAGENTA,BOLD,NORMAL);
            pontos_dealer=conta_pontos(dealer,tam_dealer);
            mostra_detalhes(dealer,tam_dealer,pontos_dealer);
            printf("\n%s%sJogador:%s\n",MAGENTA,BOLD,NORMAL);
            pontos_jogador=conta_pontos(jogador,tam_jogador);
            mostra_detalhes(jogador,tam_jogador,pontos_jogador);
             

        }
        pontos_jogador=conta_pontos(jogador,tam_jogador);
        pontos_dealer=conta_pontos(dealer,tam_dealer);
        win=check_end_game(pontos_jogador,pontos_dealer);
        if(win==1)
        {
            printf("%s%sO dealer venceu%s\n",RED,BOLD,NORMAL);
            return;
        }
        if(win==2)
        {
            printf("%s%sO Jogador venceu%s\n",BOLD,GREEN,NORMAL);
            return;
        }
        if(fim==0)
        {
            printf("\n\tEscolha o seu próximo movimento:\n");
            printf("\t%s%s1%s-Hit\t%s%s2%s-Stay\t%s%s3%s-Desistir\n",MAGENTA,BOLD,NORMAL,MAGENTA,BOLD,NORMAL,MAGENTA,BOLD,NORMAL);
            scanf("%d",&opcao);
            limparScreen();
        }
        if(fim==1)
        {
            opcao=2;
        }
        if(finale==1)
        {
            printf("%s%sO dealer venceu%s\n",RED,BOLD,NORMAL);
            return;
        }
        switch (opcao)
        {
            case 1:
                proxima_carta(deck,jogador,tam_deck,tam_jogador);
                tam_deck--;
                tam_jogador++;
                break;
            case 2:
                fim=1;
                pontos_dealer=conta_pontos(dealer,tam_dealer);
                finale=dealer_moves(deck,dealer,tam_deck,tam_dealer,pontos_dealer,pontos_jogador);
                tam_deck--;
                tam_dealer++;
                break;
            case 3:
                sair=1;
                printf("\n\n");
                break;
            default:
                printf("%sOpção inválida%s\n",RED,NORMAL);
                break;
        }
        cont++;
    } while (sair!=1);
    
}

void blackjack()
{
    int opcao=0;
    int sair=0;
    do
    {
        menu();
        scanf("%d",&opcao);
        switch (opcao)
        {
            case 1:
                jogar();
                break;
            case 2:
                regras();
                break;
            case 3:
                sair=1;
                break;
            default: 
                printf("%sOpção inválida%s\n",RED,NORMAL);
                break;
        }
    }while(sair!=1);
}