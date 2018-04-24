  As funções utilizadas no trabalho foram implementadas em x bibliotecas, a fim de que possam ser reaproveitadas posteriormente. As bibliotecas foram dividas em arquivos .h que contém a declaração de funções, structs e constantes; e arquivos .c que contém a definição das funções. Para facilitar o processo de compilação, foi criado o executável "build", que contém os comandos para gerar os arquivos-objetos das bibliotecas.
  
  Para compilar os arquivos de teste ou o arquivo main.c com o gcc, basta rodar o comando:
    
    ./build $1
  substituindo $1 pelo nome do arquivo que deseja-se compilar.
  
  Para executar o programa com a interface gráfica, basta compilar o arquivo main.c e em seguida rodar o comando:
  
    ./Calculadora
