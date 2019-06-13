#include "shell.h"

void help()
{
    printf("%s------------------------------%sCOMANDOS EMBUTIDOS NA SHELL%s----------------------------------%s\n\n",BOLD,BLUE,WHITE,NORMAL);
    printf("%s%shelp%s\n",BOLD,MAGENTA,NORMAL);
    printf("%s  Comando de Ajuda %s(Apresenta Todos Os Comandos Embutidos Na Shell)\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s help\n\n",BOLD,NORMAL);
    printf("%s%saviso%s\n",BOLD,MAGENTA,NORMAL);
    printf("  Envia uma %smensagem de aviso%s ao fim de um tempo especificado\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s aviso mensagem tempo\n\n",BOLD,NORMAL);
    printf("%s%savisoth%s\n",BOLD,MAGENTA,NORMAL);
    printf("  Envia uma %smensagem de aviso%s ao fim de um tempo especificado, fazendo uso de %sThreads%s\n",BOLD,NORMAL,BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s avisoth mensagem tempo\n\n",BOLD,NORMAL);
    printf("%s%sPS1%s\n",BOLD,MAGENTA,NORMAL);
    printf("  Altera O %sNome Do PROMPT%s (PROMPT Padrão: \"[SOSHELL]> \")\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s PS1=NOME\n\n",BOLD,NORMAL);
    printf("%s%scd%s\n",BOLD,MAGENTA,NORMAL);
    printf("%s  Altera A Diretoria%s Para Um Determinado Path\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s cd PATH\n\n",BOLD,NORMAL);
    printf("%s%scalc%s\n",BOLD,MAGENTA,NORMAL);
    printf("Realiza O %sCálcuclo De Uma Operação Entre Dois Números Reais%s\n\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s calc operando1 operacao operando2\n\n",BOLD,NORMAL);
    printf("%s%sbits%s\n",BOLD,MAGENTA,NORMAL);
    printf("Realiza O %sCálculo De Uma Operação Binária (Lógica) Entre Dois Números Inteiros%s\n\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s bits operando1 operacao operando2\n\n",BOLD,NORMAL);
    printf("%s%sredirects%s\n",BOLD,MAGENTA,NORMAL);
    printf("%sRedireccionamento%s\n\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s comando file1 file2 \n\n",BOLD,NORMAL);
    printf("%s%ssair%s/%squit%s/%sexit%s/%sleave%s\n",BOLD,MAGENTA,WHITE,MAGENTA,WHITE,MAGENTA,WHITE,MAGENTA,NORMAL);
    printf("A Shell É %sEncerrada Automaticamente%s, Após Um Countdown De 3 Segundos (Se nenhum tempo for passado como argumento)\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s sair tempo (note-se que o sair pode ser substituido por 'quit'/'exit'/'leave'\n\n",BOLD,NORMAL);
    printf("%s%squemsoueu%s\n",BOLD,MAGENTA,NORMAL);
    printf("Irá Ser Imprimido Um %sID Do Utilizador%s\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s quemsoueu\n\n",BOLD,NORMAL);
    printf("%s%sobterinfo%s\n",BOLD,MAGENTA,NORMAL);
    printf("Irá Ser Imprimido %sinformações sobre a versão da shell%s\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s obterinfo\n\n",BOLD,NORMAL);
    printf("%s%s42%s\n",BOLD,MAGENTA,NORMAL);
    printf("Apresenta o significado do %sNúmero 42%s\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s 42\n\n",BOLD,NORMAL);
    printf("%s%ssocp%s\n",BOLD,MAGENTA,NORMAL);
    printf("%sCopia%s Os Dados De Um Ficheiro Para Outro\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s socp fonte destino\n\n",BOLD,NORMAL);
    printf("%s%ssocpth%s\n",BOLD,MAGENTA,NORMAL);
    printf("%sCopia%s Os Dados De Um Ficheiro Para Outro, fazendo uso de Threads\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s socpth fonte destino\n\n",BOLD,NORMAL);
    printf("%s%sblackjack%s\n",BOLD,MAGENTA,NORMAL);
    printf("  Inicia Um Jogo De %sBlackjack%s (Para Fins De Entretenimento)\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s blackjack\n\n",BOLD,NORMAL);
    printf("%s%stictactoe%s\n",BOLD,MAGENTA,NORMAL);
    printf("  Inicia Um Jogo De %sTicTacToe%s (Para Fins De Entretenimento)\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s blackjack\n\n",BOLD,NORMAL);
    printf("%s%sisjpg%s ou %s%sisjpeg%s\n",BOLD,MAGENTA,NORMAL,BOLD,MAGENTA,NORMAL);
    printf("  Verifica Se Um Ficheiro É Um %sFicheiro JPEG%s\n",BOLD,NORMAL);
    printf("%s  Chamada ao comando: %s isjpg filename (note-se que o isjpg pode ser substituido por 'isjpeg'\n\n",BOLD,NORMAL);
    printf("%s--------------------------------------------------------------%s\n",BOLD,NORMAL);
}