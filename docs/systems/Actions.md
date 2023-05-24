<!--- Header --->
# GitHub Actions
---

Documentação sobre introdução e funcionamento do [GitHub Actions][doc]

> Anotações feitas de forma independente e amadora, informações mais completas e precisas encontram-se no link da documentação.

<!--- Sumary --->
## Sumary

* [O que é GitHub Actions](Actions.md#o-que-%C3%A9-github-actions)
* [Como funciona o CI/CD](Actions.md#como-funciona-o-cicd)
* [O que é um fluxo de trabalho](Actions.md#o-que-um-fluxo-de-trabalho)
* [Introdução ao YAML](Actions.md#introdu%C3%A7%C3%A3o-ao-yaml)
* [Montagem dos fluxos de trabalho](Actions.md#montagem-dos-fluxos-de-trabalho-cicd)

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

## O que um fluxo de trabalho
---

O fluxo de trabalho é um arquivo de configuração YAML `file.yml` ou `file.yaml` localizado no diretório `.github/workflows/`.

Nele conterá as rotinas executadas no Actions:

- Cada fluxo de trabalho possuirá um ou mais _trabalhos_ (**jobs**);
- Cada _trabalho_  possuirá uma série de taréfas a serem executadas, sendo elas, inclusão de fluxos pré-montados ou comandos bash;
- Os _trabalhos_ podem serexecutados de forma sequencial ou paralela;
- Cada _trabalho_ terá sua instancia rodada em uma máquina virtual ou conteiner a parte. 

## Introdução ao YAML
---

YAML é um _formato de serialização_.
YAML é um arquivo de texto formatado para estruturar configurações e dados de forma humanamente legível.


## Montagem dos fluxos de trabalho CI/CD
---

Os fluxos de trabalho podem começar setando um nome para aquele arquivo de configuração [opcional]:
```yaml
name:
```

Check more detailed explanations of GitHub Actions Workflow in documentation page.   
Go to [Doc page][doc]

<!--- Footer --->
---
**Author**: _Thiago Firmino dos S. (Thfirmin)_   
**Institution**: _42 | Rio_   
**Source**: _Markdown_   

> **_Keep Swimming!_**

##### _cub3D 42|Rio (2023) - Thiago Firmino dos S. (Thfirmin)_

<!--- Links --->
[doc]:<https://docs.github.com/pt/actions>
