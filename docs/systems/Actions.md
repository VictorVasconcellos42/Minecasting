<!--- Header --->
# GitHub Actions
---

Documentação sobre introdução e funcionamento do [GitHub Actions][doc]

> Anotações feitas de forma independente e amadora, informações mais completas e precisas encontram-se no link da documentação.

<!--- Sumary --->
## Sumary

* [O que é GitHub Actions](#o-que-%C3%A9-github-actions)
* [Como funciona o CI/CD](#como-funciona-o-cicd)
* [O que é um fluxo de trabalho](#o-que-%C3%A9-um-fluxo-de-trabalho)
* [Introdução ao YAML](#introdu%C3%A7%C3%A3o-ao-yaml)
	* [Introdução](#introdu%C3%A7%C3%A3o)
	* [Syntax](#syntax)
* [Montagem dos fluxos de trabalho](#montagem-dos-fluxos-de-trabalho-cicd)
	* [Nome](#nome)
	* [Captura de Eventos](#captura-de-eventos)
	* [Trabalhos](#trabalhos)
	* [Rotinas](#rotinas)

## O que é GitHub Actions
---

GitHub Actins é uma plataforma de integração contínua (_CI - Continuous Integration_)
e entrega contínua (_CD - Continuous Delivery_) entre o git e o seu repositório.   
Ele permite, automatizar compilação, testar e montar pipelines de implantação. através
de fluxos de trabalhos

## Como funciona o CI/CD
---

A integração/entrega contínua da plataforma do GitHub é uma rotina configurada pelo desenvolvedor
ativada quando captura um evento como um `pull request`,`push` ou até `merge`.

## O que é um fluxo de trabalho
---

O fluxo de trabalho é um arquivo de configuração YAML `file.yml` ou `file.yaml` localizado no diretório `.github/workflows/`.

Nele conterá as rotinas executadas no Actions:

- Cada fluxo de trabalho possuirá um ou mais _trabalhos_ (**jobs**);
- Cada _trabalho_  possuirá uma série de taréfas a serem executadas, sendo elas, inclusão de fluxos pré-montados ou comandos bash;
- Os _trabalhos_ podem serexecutados de forma sequencial ou paralela;
- Cada _trabalho_ terá sua instancia rodada em uma máquina virtual ou container a parte. 

## Introdução ao YAML
---

### Introdução
YAML é um _formato de serialização_.
YAML é um **arquivo de texto** formatado para estruturar dados de forma _humanamente legível_, embora também possa ser considerado uma linguagem 
de marcação rápida.

### Syntax
Seus blocos são definidos por identação, assim como em [Python]. Além disso, suas tabublações são compostas de espaços em branco e não o caractere 'TAB' em si.   
Os membros das listas são encabeçados por traços `-`, ou seja, seu primeiro elemento deve conter um traço em seu inicio e os membros em cada linha.

```YAML
- name:
  element1: value 1
  elementn: 'value n'
  ...

- key2:
  ...
```

Ou entre colchetes e separados por `,`

```YAML
name: [ value1, value 2, 'value 3' ]
```

> Os vetores associativos se representam usando os dois pontos `:` seguido por um espaço. No seguinte formato (`Chave: Valor`) 

Seus comentários são formados com `#`

```YAML
# This is a comment
```

## Montagem dos fluxos de trabalho CI/CD
---

### Nome
Os fluxos de trabalho podem começar adicionando um nome para aquele arquivo de configuração [opcional]:

```yaml
name: 'My First Workflow Script'
```

### Captura de eventos
A captura de evento é relacionada ao acionamento do action quando o GitHub capturar uma atividade especificada.

Ela começa com a palavra-chave `on`, com a lista dos eventos requeridos:

```YAML
name: 'My First Workflow Script'

on: [ push, pull_request, dispatch_workflow ]
```

> * `workflow_dispatch` é uma flag que é relacionada ao acionamento manual do fluxo de trabalho
> * Se você quiser adicionar uma configuração específica à esses eventos (como filtrar uma branch específica por exemplo), você deve utilizar um modo diferente de criar essa lista de "Hooks"

```YAML
name: 'My First Workflow Script'

on:
  push:
  pull_request:
    branches:
      main:
      develop:
  dispatch_workflow:

# Se você não possui configurações especificas
# para a sub-lista "branches", você pode encurta-la dessa forma

on:
  push:
  pull_request:
    branches: [ main, develop ]
  dispatch_workflow:
```

### Trabalhos

As Rotinas de execução _"Trabalhos"_, começam com a palavra-chave `job`, e então, todo sub-item dentro dessa palavra equivalerá a um trabalho próprio.

> Os trabalhos não podem ter nomes repetidos

```YAML
name: 'My First Workflow Script'

on:
  push:
  pull_request:
    branches: [ main, develop ]
  dispatch_workflow:

jobs:
  job-1:
    ...
  job-2:
    ...
  job-n:
    ...
  .
  .
  .
```

Como dito antes, cada _Trabalho_ irá rodar em sua própria máquina virtual/container zerado.

### Rotinas
Cada rotina deve conter como requisito a sua VM/Container a se rodar usando a palavra-chave `runs-on` e a palavra-chave `steps` que irá iniciar os passos, os comandos de execução da rotina.   
sua syntax segue dessa forma:

```YAML
name: 'My First Workflow Script'

on:
  push:
  pull_request:
    branches: [ main, develop ]
  dispatch_workflow:

jobs:
  job-1:
    runs-on: ubuntu-latest
    steps:
      - run: echo job 1
  job-2:
    runs-on: macos-latest
    steps:
      - run: echo "job 2"
  job-n:
    runs-on: ubuntu-latest
    steps:
      - run: 'echo job 3'
```

> É possível atribuir configurações as palavras-chave, você pode encontrar essas possiveis alterações na documentação.

```YAML
name: 'My First Workflow Script'

on:
  push:
  pull_request:
    branches: [ main, develop ]
  dispatch_workflow:

jobs:
  job-1:
    name: 'Job 1 Title'
    runs-on: ubuntu-latest
    steps:
      - name: 'Running first task'
        run: echo job 1

  job-2:
    name: 'Job 2 Title'
    runs-on: macos-latest
    steps:
      - name: 'Running inline command'
        run: echo "job 2"
      - name: 'Running multi-line command'
        run: |
          echo "This is a multi-line command"
          ls -al
          if [ -f "Makefile" ]; then { make; } fi
  job-n:
    runs-on: ubuntu-latest
    steps:
      - name: 'Running first task'
        run: 'echo job 3'

      - name: 'Running second task'
        run: 'echo "Hello" && echo "$USER" ; cat $(ls)'
```

Veja explicações mais detalhadas sobre o fluxo de trabalho do GitHub Actions na página de documentação.   

Vá para [Página de documentação][doc].

<!--- Footer --->
---
**Author**: _Thiago Firmino dos S. (Thfirmin)_   
**Institution**: _42 | Rio_   
**Source**: _Markdown_   

> **_Keep Swimming!_**

##### _cub3D 42|Rio (2023) - Thiago Firmino dos S. (Thfirmin)_

<!--- Links --->
[doc]:<https://docs.github.com/pt/actions>
