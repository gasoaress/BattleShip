# BattleShip:
O jogo BattleShip desenvolvido em C é uma releitura moderna e gráfica do clássico jogo de batalha naval. Utilizando a biblioteca Raylib, oferece uma experiência interativa e visualmente atraente. O código é estruturado de forma clara, incorporando elementos como matriz, texturas e música para criar uma dinâmica envolvente. As diferentes telas proporcionam uma transição suave entre as fases do jogo, enquanto a lógica de interação por cliques do mouse adiciona um componente estratégico. Em resumo, o BattleShip representa uma implementação bem elaborada que combina a nostalgia do jogo original com recursos modernos de programação.

# Autores: 
Jogo desenvolvido no período de 2023 por Gabriel Leite Soares Ramos && Luis Otavio Albergoni Santos, alunos do Curso de Ciência da Computação da PUC MINAS de Poços de Caldas.

# Estrutura Geral:
O código em C desenvolve um jogo baseado no clássico jogo de batalha naval (Battleship), utilizando a biblioteca externa Raylib para gráficos e funcionalidades de jogo. Abaixo está uma descrição detalhada da estrutura geral do código:

# Comentários Iniciais:
No início do código, há comentários que fornecem informações sobre o propósito do projeto, os membros do grupo, o objetivo do jogo e as mudanças feitas ao longo do tempo.

# Definição de Estruturas:
Há a definição de uma estrutura embarcacao para representar as informações de cada tipo de embarcação no jogo, como tamanho e quantidade de acertos.

# Matriz e Variáveis:
Uma matriz 5x5 (matriz) é declarada para representar o campo de jogo. Além disso, várias variáveis, como coordenadas (i e j), uma variável de controle de tela (tela), munição (ammo), pontuação (pontos), e outras, são declaradas.

# Inicialização do Jogo:
As configurações iniciais do jogo são feitas, como a inicialização da janela usando Raylib, a definição de FPS, e o carregamento de texturas e músicas.

# Estrutura do Loop Principal:
O jogo é controlado por um loop principal que é executado enquanto a janela não for fechada (WindowShouldClose()). Dentro deste loop, há seções distintas para diferentes telas do jogo (tela inicial, tela de jogo, tela de regras, tela de derrota, tela de vitória).

# Tela Inicial (tela==0):
Nesta seção, são desenhados elementos da tela inicial, como o título "BattleShip" e instruções para começar ou ver as regras. A transição para a tela de jogo ocorre ao pressionar Enter, e para a tela de regras ao pressionar R.

# Tela de Jogo (tela==1):
Aqui, a lógica do jogo é atualizada e elementos gráficos são desenhados. A matriz é exibida com coordenadas, e as interações do jogador são detectadas por cliques do mouse para atirar. Informações sobre munição, pontuação e embarcações afundadas são exibidas.

# Verificação de Condições de Vitória/Derrota:
O código verifica se o jogador ganhou ou perdeu com base na pontuação e na munição.

# Tela de Regras (tela==2):
Se o jogador pressionar a tecla F, a tela de regras é exibida, explicando como jogar.

# Telas de Derrota (tela==3) e Vitória (tela==4):
Nestas seções, são exibidas as telas de derrota ou vitória, respectivamente. O jogador pode reiniciar o jogo pressionando Enter.

# Encerramento e Descarregamento:
No final do código, as músicas são descarregadas, o dispositivo de áudio é fechado, e a janela é fechada.

# Função Adicional (retornadados):
Há uma função adicional chamada retornadados que reseta a pontuação e a munição se o jogador ganhar ou perder.

# Texturas e Músicas:
Texturas representando diferentes tipos de embarcações e músicas para diferentes momentos do jogo são carregadas.

# Desenho de Elementos Gráficos:
O desenho de elementos gráficos, como texturas de embarcações, é feito com base nas interações do jogador.

# Controle de Música:
O código utiliza a biblioteca Raylib para carregar e reproduzir músicas durante diferentes fases do jogo.

#Liberação de Recursos:
No final, todas as músicas são descarregadas e o dispositivo de áudio é fechado antes de encerrar o programa.
