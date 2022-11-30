# Trabalho Prático da Disciplina de Programação e Desenvolvimento de Software 2 (UFMG): Jogo de Uno

*### DISCLAIMER: ESSE README N TÁ COMPLETAMENTE PRONTO, GALERA DO GRUPO. TEM MT COISA PRA ALTERAR*

### Integrantes:
- Bruno Lima
- Gustavo Lima
- Maria Eduarda Sampaio
- Pedro Kalil
- Raissa Diniz
- Raphael Amaral
### Professora: Camila Laranjeiras
### Em que consiste esse trabalho?
O objetivo deste trabalho é construir um projeto de software de pequeno porte. Nosso grupo escolheu construir um jogo de cartas do tipo UNO, realizando todo o processo de desenvolvimento necessário para um sistema desse porte (análise, projeto e implementação), e aplicando os conceitos e técnicas vistos durante o curso (modelagem, POO, testes unitários, etc). O programa é baseado na linguagem C++, mas também expõe uma API em C para poder ser acessado em dart, no flutter, por meio do dart:ffi (foreign function interface), que provê uma maneira de linkar dinamicamente bibliotecas compartilhadas de C e usa-las como funções nativas em dart.

O jogo Uno é um jogo de cartas lançado pela Mattel e Gameloft no qual o jogador relaciona os números com as cores. O objetivo é ser o primeiro jogador a ficar sem cartas na mão, utilizando-se de todas as regras possíveis para impedir que os outros jogadores façam a mesma coisa.

### REGRAS E INFORMAÇÕES GERAIS SOBRE COMO FUNCIONA A NOSSA VERSÃO DO UNO:
1.  O jogo consiste em 4 jogadores, com 7 cartas cada;
    
2.  Além das clássicas cartas numéricas (0-9) de cores variadas (amarelo, azul, vermelho e verde), essa versão apresenta três tipos de carta especial (em detrimento às cinco do jogo padrão):
    
		1.  Reverso: muda o sentindo da partida, podendo ser horário ou anti-horário;
		    
		2.  Bloqueio: impede o jogador seguinte ao que lançou a carta de participar nessa rodada;
		    
		3.  “Come 2”: faz com que o próximo àquele que jogou adicione mais 2 cartas à sua mão. É importante ressaltar que, nesse jogo, essas cartas não são acumulativas, ou seja, um outro “come 2” não pode ser jogado em cima de um previamente lançado de modo a “formar um come 4”;
	    

4.  O jogador não possui a possibilidade de falar “Uno” enquanto joga sua penúltima carta (uma vez que isso implicaria na necessidade da criação de todo um sistema de denúncia para quando isso não acontece, trazendo mais complexidade ao projeto);
    
5.  A interface em que o jogo será jogado será feita no framework flutter, feito pela Google para criar aplicações nativas e usando o pacote de gerenciamento de estado [Value Notifier](https://github.com/kalildev/value_notifier) e o renderizador de vetores [Vector Drawable.dart](https://github.com/KalilDev/vector_drawable.dart), feito pelo aluno Pedro Morato Kalil.
    
6.  O jogo não possui bots. Dessa maneira, todas as opções discutidas no tópico anterior serão apresentadas no mesmo ambiente e consecutivamente, isto é, logo após um jogador ter feito sua jogada, a vez será dada ao próximo.


### NOSSO USER STORIES:
~~• Como jogador eu quero acessar meu histórico de partidas para saber como me sai e acompanhar meus resultados e minha evolução no jogo.~~

~~• Como jogador eu quero incrementar a quantidade de jogadores com os quais iniciarei uma partida para tornar a experiência de jogo mais fidedigna.~~

~~• Como jogador eu quero incrementar o nível dos bots com os quais jogarei, para testar a extensão das minhas habilidades.~~

~~• Como jogador eu quero delimitar o tempo para um jogador lançar
 uma carta para que a partida seja fluida e não seja prejudicada por
um usuário “away from the keyboard”.~~

~~• Como jogador eu quero poder alterar os estilos dos elementos visuais, como cartas e plano de fundo, para tornar o jogo mais envolvente e diversificar minhas opções de customização~~

- Como jogador, eu quero poder utilizar de pelo menos 3 das cartas especiais do UNO, para tornar o jogo mais parecido com o real;
- Como jogador, eu quero poder acessar um menu durante a partida, para ter opções como sair, reiniciar, ou ler as regras do jogo sem precisar de quitar a rodada;    
- Como jogador, eu quero poder jogar com bots, para tornar a minha experiencia mais divertida, dinâmica e competitiva, de modo a testar minhas habilidades;
- Como jogador, eu quero poder escolher qual carta jogar, para pode traçar minha estratégia de jogo;
- Como jogador, eu quero poder visualizar as cartas da minha mão, para poder escolher melhor qual jogar;
- Como jogador, eu quero poder jogar com mais de um jogador/bot, para que seja mais divertido.

### VERSÃO INICIAL DO DIAGRAMA DE CLASSES:
[Link para o Draw.io](https://drive.google.com/file/d/1K9YqTVlmx7d_rlcXPRvTbVA9xhbsPNxW/view?usp=sharing)
![Foto do Diagrama](https://github.com/KalilDev/uno.cpp/blob/master/diagrama%202.PNG)

