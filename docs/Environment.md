# Environment
--------------------

## Introduce
--------------
Documentação sobre como o nosso ambiente de desenvolvimento estar organizado.

## Library

A libft do projeto foi alterada por motivos de que a do thiago estavam dando alguns invalid read e algumas funções teriam que ser alteradas para conseguirmos usa-las da maneira mais efetiva para o projeto. Coloquei a minha libft no lugar pois a forma que usariamos ela esta bem de acordo do jeito que a minha foi construida.

- Vantagens: sem necessidade de criar funções de manipulação de string novas.

- Desvatagens: perda do carbage collector do firmino, que ainda esta imcompleto.

* Uso das funções padrões de alocação de memoria requerido, então tome cuidado com vazamentos!!

## Tests:
------------
Para o projeto ficar mais simples, recomendo a todos que utilizem a tática de TDD, que consiste voce criar os testes primeiro, antes da realização do código em si. Isso facilita na hora de saber exatamente o que voce vai fazer. Os testes ficaram na pasta test, e eles podem se escritos na linguagem que voce mais sentir confiança.

## Model:
-------------

Todas as implementacoes em relação a modelagem do projeto estarão dentro desse diretorio. Os topicos de modelagem são:

* Normalização de Dados
* Leitura de Mapa
* Validação de arquivo
* Validação de conteudo de arquivo

## Raycasting:
--------------

Todas as implemetanções em relação a engine de raycasting, mlx e etc, estarão dentro desse diretorio. Os topicos de Raycasting são:

* Algoritmo de Raycasting
* Funções de ações: criar linha, cubos e etc.

## Docs:
----------------

Nesse diretorio, ficarão todas as documentações sobre o nosso projeto. Se quiserem, podem separar em pastas por cada macro grupo como um diretorio só para as docs de model ou engine, mas isso é opcional.
