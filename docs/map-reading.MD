# Documentação da Feature: Scene Reading

## Descrição

Esta documentação descreve a feature "Scene Reading", que foi implementada no projeto MineCasting. A feature adiciona funcionalidade ao projeto, permitindo que a equipe de engine tenha acesso a todas as informações do cenário montado de forma padronizada.

## Detalhes da Feature

### Funcionalidades Principais
- Input Reading: Na Input Reading é feito o tratamento do número de argumentos e também a verificação da existência de um path válido e acessível.
- Map Reading: No Map Reading é realizado as funções de obtenção de dados do cenário, como as texturas, as cores e os mapas. E também é realizado algumas pré-validações.
- Standard Data: No Standard Data foi garantido que os dados lidos de um cenário cheguem em único padrão, independente da ordem lida dentro de uma determinada struct.

### Funcionalidades Extras: 
- Resolution Reading: Obtenção das informações a cerca da resolução do cenário.
- Sprites Reading: Obtenção das informações a cerca dos sprites que serão utilizados.

## Padrão Adotado

O padrão definido na funcionalidade Standard Data é o seguinte:

- Resolução (Caso Houver)
- Texturas: NO, SO, WE, EA.
- Sprites (Caso Houver)
- Cores: Floor e Ceiling.
- Mapa
