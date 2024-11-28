# Algoritmo de Busca em Profundidade (DFS)

Este projeto implementa um algoritmo de Busca em Profundidade (DFS) em C, utilizando um grafo representado por uma lista de adjacências.

## Visão Geral

O algoritmo DFS é usado para explorar todos os vértices e arestas de um grafo. Este algoritmo marca cada vértice com um tempo de descoberta e término para ajudar a entender a estrutura do grafo, identificando caminhos e ciclos.

## Estruturas de Dados

- `cor[qtd]`: Array que armazena a cor de cada vértice (BRANCO, CINZA, PRETO).
- `pred[qtd]`: Array que armazena o predecessor de cada vértice.
- `d[qtd]`: Array que armazena o tempo de descoberta de cada vértice.
- `f[qtd]`: Array que armazena o tempo de término de cada vértice.
- `grafo`: Estrutura que representa a lista de adjacências do grafo.

## Funções

- **iniciarGrafo**: Inicializa a lista de adjacências do grafo.
- **inserirGrafo**: Insere uma aresta de um vértice `u` para um vértice `v`.
- **DFS_visit**: Visita um vértice `u`, marcando-o como CINZA e chamando recursivamente para seus vértices adjacentes.
- **DFS**: Inicializa as cores dos vértices e executa a busca em profundidade para cada vértice ainda não visitado.
