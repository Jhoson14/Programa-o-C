#include <stdio.h>
#include <string.h>  //evitar erros de wimplicit-function-declaration devido ao uso da função strcspn para limpar buffer


int main(){
    //parametros para cada País
    //incluido nestes parametros numero de: habitantes,pontos turisticos e o PIB
    //Area da cidade em km²


//cartas
//agrupando por tipos para enconomizar espaço no código. Ex:  int: pop1,pop2;

    char Pais1[50],Pais2[50];
    int Pop1,Pop2; //Resultado será limitado a numeros inteiros
    float Area1,Area2;
    float Densi1, Densi2;
    float PIB1, PIB2;  // produto interno bruto normal
    int Pontos1,Pontos2;//turisticos
    float PIBC1, PIBC2; // pib per capitca

    //código da cidade, nome, população, área, PIB, número de pontos turísticos
    //dados adicionais do level aventureiro: Densidade Populacional e Pib per Capita

    //O sistema calculará automaticamente a Densidade Populacional e o PIB per Capita.
    
    //Densidade Populacional: População / Área (float)
    //Para calcular a densidade populacional, basta dividir o número total de habitantes pela área total da região em questão. Então  Densidade = pop/area


    //PIB per Capita: PIB / População (float)
    //Para Calculá-lo dividir PIB do um país pelo total de habitantes P.C= Pib/pop
    
    printf("Desafio Super Trunfo - Países \n");
    printf("\nVamos registrar as cartas para nosso jogo?\n");
  
    //fgets para nomes compostos
    //Carta 01
    printf("\nDados da Primeira Carta \n");

    printf("A qual País pertencerá a carta 01? (Digite o nome de um País. Ex: Costa do Marfim) \n");
    fgets(Pais1, sizeof(Pais1), stdin);
    Pais1[strcspn(Pais1, "\n")] = '\0'; // Enter após digitar nome gera um comando de espaçamento /N, anulando esse input do entre para não ficar feio o print final
    //assim fazendo com que Ex: Costa do Marfim\n não seja impresso e sim Costa do Marfim apenas

    printf("Há quantos Habitantes neste País? (Não use pontos ou vírgulas ao digitar o valor) \n"); //população
    scanf ("%d", &Pop1);

    printf("Qual a Área do País? (Em km²) \n"); //erros no print, adicionar &area para armazenar variavel
    scanf("%f", &Area1);

    printf ("Qual o valor do Produto Interno Bruto (PIB) do País? \n");
    scanf ("%f", &PIB1);

    printf ("Quantos pontos Túristicos há no País?\n");
    scanf ("%d", &Pontos1);

    Densi1 = Pop1 / Area1;  //Densidade= população dividida pela area
    PIBC1 = PIB1 / Pop1; // PIB dividido pela população
   


// Limpeza do Buffer do Fgets para não pular a inserção do nome segunda carta. Não conseguia fazer isso funcionar até descobrir sobre buffers T-T
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // codigo parecido com um exemplo do google

 
//Carta 2

    printf("\n\nA qual País pertencerá a carta 02? (Digite o nome de outro País) \n");
    fgets(Pais2, sizeof(Pais2), stdin);
    Pais2[strcspn(Pais2, "\n")] = '\0';

    printf("Há quantos Habitantes neste País? \n"); //população
    scanf ("%d", &Pop2);

    printf("Qual a Área do País? (Em km²) \n"); //erros no print, adicionar &area para armazenar variavel
    scanf("%f", &Area2);

    printf ("Qual o valor do Produto Interno Bruto (PIB) do País? \n");
    scanf ("%f", &PIB2);

    printf ("Quantos pontos Túristicos há no País?\n");
    scanf ("%d", &Pontos2);
   
   
    Densi2 = Pop2 / Area2;  //Densidade= população dividida pela area 
    PIBC2 = PIB2 / Pop2;
  

 //calcular Densidade e pibC antes da impressão!!   

//impressão dos Dados digitados para ambas as cartas
   
    //carta 01
    printf("\nCarta 01\n");  // adicionar /n no inicio para pular linhas e deixar mais limpo o print das informações
    printf("País: %s\n", Pais1);
    printf("Área: %.0f Km²\n", Area1);
    printf("Habitantes: %d\n", Pop1);
    printf("PIB: %.f\n", PIB1);
    printf("Pontos Turísticos: %d\n", Pontos1);
    printf("Densidade Populacional: %.f habitantes/km²\n", Densi1); // 
    printf("PIB per Capita: %.2f\n", PIBC1); //mostrar 2 casas decimais para clareza

    //carta 2
    printf("\n\nCarta 02\n");  // adicionar /n no inicio para pular linhas e deixar mais limpo o print das informações
    printf("País: %s\n", Pais2);
    printf("Área: %.0f Km²\n", Area2);  // caso necessário usar %.0,2,2,3f imprimir com menos casas decimais com 0 sendo numero real digitado. Print mais limpo com 0 :D
    printf("Habitantes: %d\n", Pop2);
    printf("PIB: %.f\n", PIB2);
    printf("Pontos Turísticos: %d\n", Pontos2);
    printf("Densidade Populacional: %.f habitantes/km²\n", Densi2); // hab/km² para mais clareza, 2 casas decimais para melhor impressão? Testar com e sem
    printf("PIB per Capita: %.2f\n", PIBC2); // 2 casas para melhor impressão

//Switch e comparação de atributos 

//escolha dos parametros a serem comparados
int Comparação;

printf("\nQual atributo gostaria de comparar entre os Países?\n"); // ordem do print das cartas
printf("1- Habitantes\n"); //usar o n para nova linha para impressões espaçadas e mais limpas
printf("2- Área\n");
printf("3- Produto Interno Bruto (PIB)\n");
printf("4- Pontos Turisticos\n");
printf("5- Densidade Populacional\n");
printf("6- PIB per Capta\n");
printf("\nPor favor selecione uma Opção do menu\n");

scanf(" %d", &Comparação); // manter apenas o %d entre aspas para não gerar erro, & para manter variável salva

//hab - Area - PiB- Pontos - Densi - Pp.Capita . Ordem alfabética para melhor impressão
char *resultado; // Asterisco para guardar vários valores e não apenas um. (Estava quebrando cabeça para tentar arrumar isso)


switch(Comparação)
{
case 1:
    printf("\nComparando Populacao...\n");
    resultado = (Pop1 > Pop2) ? Pais1 :
    (Pop2 > Pop1) ? Pais2 : "Empate"; //
    printf("Pais 1: %s -> %d habitantes\n", Pais1, Pop1);  // %s =string 
    printf("Pais 2: %s -> %d habitantes\n", Pais2, Pop2);
    printf("Vencedor: %s\n", resultado);
break;

case 2:
    printf("\nComparando Area...\n");
    resultado = (Area1 > Area2) ? Pais1 :
    (Area2 > Area1) ? Pais2 : "Empate";
    printf("Pais 1: %s -> %.0f km²\n", Pais1, Area1);
    printf("Pais 2: %s -> %.0f km²\n", Pais2, Area2);
    printf("Vencedor: %s\n", resultado);
break;

case 3:
    printf("\nComparando PIB...\n");
    resultado = (PIB1 > PIB2) ? Pais1 :
    (PIB2 > PIB1) ? Pais2 : "Empate";
    printf("Pais 1: %s -> %.0f\n", Pais1, PIB1);
    printf("Pais 2: %s -> %.0f\n", Pais2, PIB2);
    printf("Vencedor: %s\n", resultado);
break;

case 4:
    printf("\nComparando Pontos Turisticos...\n");
    resultado = (Pontos1 > Pontos2) ? Pais1 :
    (Pontos2 > Pontos1) ? Pais2 : "Empate";
    printf("Pais 1: %s -> %d pontos\n", Pais1, Pontos1);
    printf("Pais 2: %s -> %d pontos\n", Pais2, Pontos2);
    printf("Vencedor: %s\n", resultado);
break;

case 5:
    printf("\nComparando Densidade Populacional...\n");
    resultado = (Densi1 > Densi2) ? Pais1 :
    (Densi2 > Densi1) ? Pais2 : "Empate";
    printf("Pais 1: %s -> %.2f hab/km²\n", Pais1, Densi1);
    printf("Pais 2: %s -> %.2f hab/km²\n", Pais2, Densi2);
    printf("Vencedor: %s\n", resultado);
break;

case 6:
   printf("\nComparando PIB per Capita...\n");
    resultado = (PIBC1 > PIBC2) ? Pais1 :
    (PIBC2 > PIBC1) ? Pais2 : "Empate";
    printf("Pais 1: %s -> %.2f\n", Pais1, PIBC1);
    printf("Pais 2: %s -> %.2f\n", Pais2, PIBC2);
    printf("Vencedor: %s\n", resultado);
break;

default:
    printf("\n Você não digitou um número valido,Tente novamente!\n");
break;
}


}
