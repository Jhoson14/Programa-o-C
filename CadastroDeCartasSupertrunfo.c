#include <stdio.h>
#include <string.h>  //evitar erros de wimplicit-function-declaration devido ao uso da função strcspn para limpar buffer

int main(){
    //parametros para cada País
    //incluido nestes parametros numero de: habitantes,pontos turisticos e o PIB
    //Area da cidade em km²


//carta 01
    char País1[50];
    int Pop1; //Resultado será limitado a numeros inteiros
    float Area1;
    float PIB1;
    int Pontos1;//turisticos
    //código da cidade, nome, população, área, PIB, número de pontos turísticos

//carta 02
    char País2[50];
    int Pop2; //Resultado será limitado a numeros inteiros. Adicionar aviso para não digitar com ponto ou virgula para n gerar erros de leitura do n° inteiro
    float Area2;
    float PIB2;
    int Pontos2;//turisticos


    printf("Desafio Super Trunfo - Países \n");
    printf("\nVamos registrar as cartas para nosso jogo?\n");
  
    //fgets para nomes compostos
    //Carta 01
    printf("\nDados da Primeira Carta \n");

    printf("A qual País pertencerá a carta 01? (Digite o nome de um País. Ex: Costa do Marfim) \n");
    fgets(País1, sizeof(País1), stdin);
    País1[strcspn(País1, "\n")] = '\0'; // Enter após digitar nome gera um comando de espaçamento /N, anulando esse input do entre para não ficar feio o print final
    //assim fazendo com que Ex: Costa do Marfim\n não seja impresso e sim Costa do Marfim apenas

    printf("Há quantos Habitantes neste País? (Não use pontos ou vírgulas ao digitar o valor) \n"); //população
    scanf ("%d", &Pop1);

    printf("Qual a Área do País? (Em km²) \n"); //erros no print, adicionar &area para armazenar variavel
    scanf("%f", &Area1);

    printf ("Qual o valor do Produto Interno Bruto (PIB) do País? \n");
    scanf ("%f", &PIB1);

    printf ("Quantos pontos Túristicos há no País?\n");
    scanf ("%d", &Pontos1);

// Limpeza do Buffer do Fgets para não pular a inserção do nome segunda carta. Não conseguia fazer isso funcionar até descobrir sobre buffers
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // codigo parecido com um exemplo do google

// Explicação Extraida do google:
//fgets(linha, sizeof(linha), stdin);: Lê uma linha de texto da entrada padrão (stdin) e armazena no buffer linha. fgets inclui o caractere de nova linha (\n) no buffer se ele couber na linha. 
//while ((c = getchar()) != '\n' && c != EOF) { }: Este loop lê caracteres do buffer de entrada, um por vez, até encontrar o caractere de nova linha (\n) ou o fim do arquivo (EOF). 
//c != EOF: Verifica se o final do arquivo foi atingido. Isso é importante para evitar erros se a entrada for redirecionada ou se houver um problema na entrada.
//getchar(): Lê o próximo caractere do buffer de entrada. 
//fgets(linha, sizeof(linha), stdin);: Lê a próxima linha de texto após a limpeza do buffer. 

//Carta 2

    printf("\n\nA qual País pertencerá a carta 02? (Digite o nome de outro País) \n");
    fgets(País2, sizeof(País2), stdin);
    País2[strcspn(País2, "\n")] = '\0';

    printf("Há quantos Habitantes neste País? \n"); //população
    scanf ("%d", &Pop2);

    printf("Qual a Área do País? (Em km²) \n"); //erros no print, adicionar &area para armazenar variavel
    scanf("%f", &Area2);

    printf ("Qual o valor do Produto Interno Bruto (PIB) do País? \n");
    scanf ("%f", &PIB2);

    printf ("Quantos pontos Túristicos há no País?\n");
    scanf ("%d", &Pontos2);

//impressão dos Dados digitados para ambas as cartas
   
    //carta 01
    printf("\nCarta 01\n");  // adicionar /n no inicio para pular linhas e deixar mais limpo o print das informações
    printf("País: %s\n", País1);
    printf("Área: %.0f Km²\n", Area1);
    printf("Habitantes: %d\n", Pop1);
    printf("PIB: %.f\n", PIB1);
    printf("Pontos Turísticos: %d\n", Pontos1);

    //carta 2
    printf("\n\nCarta 02\n");  // adicionar /n no inicio para pular linhas e deixar mais limpo o print das informações
    printf("País: %s\n", País2);
    printf("Área: %.0f Km²\n", Area2);  // caso necessário usar %.0,2,2,3f imprimir com menos casas decimais com 0 sendo numero real digitado. Print mais limpo com 0 :D
    printf("Habitantes: %d\n", Pop2);
    printf("PIB: %.f\n", PIB2);
    printf("Pontos Turísticos: %d\n", Pontos2);

    return 0;
    
}
