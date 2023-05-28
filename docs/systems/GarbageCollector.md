<!--- Header --->
# Garbage Collector
---

Documentação sobre mini garbage collector: introdução, implementação, usos, bugs, retornos, etc...

> Anotações feitas de forma independente e amadora, informações podem faltar ou não terem sido observadas. Caso observe uma informação a mais, por favor, enviar comunicado e/ou criar issue sobre.

<!--- Sumary --->
## Sumary

* [O que é um garbage collector](#o-que-é-um-garbage-collector)
* [Implementação do garbage collector](#implementação-do-garbage-collector)
* [Usos sobre biblioteca e escopo](#usos-sobre-biblioteca-e-escopo)
* [Bugs, avisos e retornos](#bugs-avisos-e-retornos)
* [Library](#library)
	* [gc_meminit](#)
	* [gc_alloc](#)
	* [gc_free](#)
	* [gc_memdelete](#)
	* [gc_memsumary](#)

<!--- Body --->
## O que é um garbage collector
---
<!--- Explicar direta e claramente o que é um garbage collector --->

Quando programamos usando a parte da memória na stack, a linguagem automaticamente gerencia aquela memória e a libera por nós, mas quando precisamos de mais memória e alocamos ela, se torna nossa responsabilidade descobrir onde ela se torna inutilizada e a desaloca.

O _Garbage collector_ é um sistema gerenciador de memória que controla a alocação, movimentação e desalocação das memória pelo desenvolvedor.

## Implementação do garbage collector
---
<!--- Expicar como foi gerado a ideia de implementação e como ela trabalha (funciona) --->

A sua implementação segue fundamentalmente em capturar alocação, e mantê-la até o seu desalocamento ou o final do programa.

Como esse protótipo de _garbage collector_ foi feito para ser usado no projeto da 42 Rio (cub3D), ele foi construído sob normas.

### Estrutura

A sua estrutura foi montada em torno da estrutura de dados ___[Lista encadeada (linked list)]([O que é uma lista encadeada e como implementá-la (usp.br)](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html))___. Sua implementação em C foi feita com _typedef_ e _structs_. 

Uma célula ou nó (_node_) representa um bloco de endereço alocado, onde ela recebe um endereçamento da memória alocada, em conjunto com o contexto do uso daquela memória, e um apontamento para o próximo bloco

```C
typedef struct s_mem
{
	void            *ptr;
	char            *ctx;
	struct s_block  *next;
}                   t_mem;
```

### Funcionamento

* Ao alocar um bloco de memória, um nó será criado, e será inserido ao final de uma lista que será usada como um sumário de referência. Essa lista será criada e entregue pelo desenvolvedor, tendo ele a responsabilidade de inicializar essa lista seja ela com 0 (`NULL` ou `(void *)0`) ou utilizar a função de inicialização do garbage collector (diferenças descritas mais a frente).

* Ao liberar memória, a lista de sumário deve ser entregue, haverá uma busca linear nessa lista pelo endereço desejado. em caso de sucesso e ele for encontrado, esse endereço será liberado e o nó que representa-o será apagado da lista. Em caso de falha, será considerado que o endereço não está alocado, logo, não haverá nenhuma liberação de endereçmento. 

### Sumário do garbage collector

O sumário é uma variável ponteiro do mesmo tipo do dado utilizado no garbage collector (`t_mem *sumary`), onde o desenvolvedor deverá inicializar dentro do próprio programa e utiliza-lo como sumário das memória alocadas.

Para inicialização, você poderá utilizar duas rotas, que alteram na forma de uso:
- O sumário pode ser inicializado com 0, `NULL` ou `(void *)0`;
	Ao realizar esse método o endereço do sumário deve ser entregue nas funções que pedem seu uso, logo um conhecimento um pouco mais que básico de ponteiro se faz necessário:
	
``` C
int   main(void)
{
	t_mem   *mem;
	void    *ptr;

	mem = 0;
	ptr = gc_alloc(ft_callo(8, 1), &mem);
	gc_free(ptr, &mem);
	return (0);
}
```

* O sumário pode ser inicializado pela função de inicialização, logo seu ponteiro já é o suficiente para o funcionamento (exceto pela função de liberação `gc_free` que permanece recebendo o endereço da lista).
```C
int   main(void)
{
	t_mem   *mem;
	void    *ptr;

	mem = gc_meminit();
	ptr = gc_alloc(ft_callo(8, 1), mem);
	gc_free(ptr, &mem);
	return (0);
}
```

## Usos sobre biblioteca e escopo
---
<!--- Exemplificar para que serve e como usar --->

* Ao alocar uma memória, utilize a função do garbage collector `gc_alloc`
	* Por "alocar", diz se funções que retornem memória alocada como `malloc`, `ft_calloc`, `ft_strdup`, `ft_strjoin`, etc...
* Ao liberar uma memória, utilize a função do garbage collector `gc_free` 
	* Ao liberar uma memória, certifique-se que de utilizou a `gc_alloc` nesse endereço.

## Bugs, avisos, e retornos
---
<!--- Avisar sobre possíveis erros e mal uso dela, possiveis bugs e como ela retorna em casos de sucesso e erro --->

- Evite utilizar diretamente funções de alocação sem o uso em conjunto do garbage collector;
- O endereçamento de uma memória vem em conjunto com um contexto, ao entregar NULL, o endereço virá sem contexto;
- Ao utilizar uma função de biblioteca que aloque mais de uma memória, se torna responsabilidade da biblioteca que lide com o leak da memória excedente alocada.
- Ao utilizar a função `free` diretamente em uma alocação rastreada pela `gc_alloc`, não tente utilizar a função `gc_free` nesse endereço, ou receberá um alerta de _double free_.

## Library
---
<!--- 
	> Introdução as funções auxiliares e funções principais acessadas durante o projeto
	> Montar sumário das funções principais disponibilizadas pela biblioteca.
--->
---
### gc_meminit

	 Inicializa um sumário utilizado pela implementação do garbage collector ao longo do programa

Synopsis: `t_mem   *gc_meminit(void);`

Return: Em caso de sucesso, o sumário inicializado será retornado. Em caso de falha, NULL será retornado e `errno` será cnfigurado.

---
### gc_alloc

	 Recebe uma memória alocada, a indexa e a monitora.

Synopsis: `void   *gc_alloc(void *ptr, char *context, t_mem *mem);`

Return: Em caso de sucesso, o bloco de memória alocado será retornado e o sumário será alterado com um novo indexamento inserido, em caso de falha, nenhuma NULL será retornado, nenhum indexamento será inserido e `errno` será configurado.

---
### gc_free
	Libera a memoria e apaga a indexação correspondente a ela

Synopsis: `void   gc_free(void *ptr, t_mem **mem);`

! Essa função não foi programada para haver erro de execução.

Return: Essa função não possui retorno.

---
### gc_memdelete
	Libera todas as memórias indexadas e apaga o sumário inteiro

Synopsis: `void   gc_memdelete(t_mem **mem);`

Return: Essa função não possui retorno.

Bug:
	* Se um endereço for liberado diretamente pela função `free` e não for apagada do sumário, o programa irá inserir um sinal de _double free_.

<!--- Footer --->

---
**Author**: _Thiago Firmino dos S. (Thfirmin)_   
**Institution**: _42 | Rio_   
**Source**: _Markdown_   

> This repository's under ___MIT license___, read more about [here][license].   
> **_Keep Swimming!_**

##### _cub3D 42|Rio (2023) - Thiago Firmino dos S. (Thfirmin)_

<!--- Links --->
[license]:<../LICENSE>
---
