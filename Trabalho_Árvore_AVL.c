#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int valor;
  struct no *direito, *esquerdo;
  short altura;
}No;

No* criando_No(int x)
{
  No *novo = malloc(sizeof(No));

  if(novo)
  {
    novo->valor = x;
    novo->esquerdo = NULL;
    novo->direito = NULL;
    novo->altura = 0;
  }
  else
    printf("\nErro na alocação de nó!");

  return novo;
}

short maior(short a, short b)
{
  return (a>b)? a: b;
}

short Altura_No(No *no)
{
  if(no == NULL)
    return -1;
  else
    return no->altura;
}

short fator_balanceamento(No *no)
{
  if(no)
    return(Altura_No(no->esquerdo) - Altura_No(no->direito));
  else
    return 0;
}

No* rotacao_esquerda(No *r)
{
  No *y, *f;

  y = r->direito;
  f = y-> esquerdo;

  y->esquerdo = r;
  r->direito = f;

  r->altura = maior(Altura_No(r->esquerdo), Altura_No(r->direito)) + 1;
  y->altura = maior(Altura_No(y->esquerdo), Altura_No(y->direito)) + 1;

  return y;
}

No* rotacao_direita(No *r)
{
  No *y, *f;

  y = r->esquerdo;
  f = y-> direito;

  y->direito = r;
  r->esquerdo = f;

  r->altura = maior(Altura_No(r->esquerdo), Altura_No(r->direito)) + 1;
  y->altura = maior(Altura_No(y->esquerdo), Altura_No(y->direito)) + 1;

  return y;
}

No* rotacao_dupla_D_E(No *r)
{
  r->direito = rotacao_direita(r->direito);
  return rotacao_esquerda(r);
}

No* rotacao_dupla_E_D(No *r)
{
  r->esquerdo = rotacao_esquerda(r->esquerdo);
  return rotacao_direita(r);
}

No* insercao(No *raiz, int x)
{
  if(raiz = NULL)
    return criando_No(x);
  else
  {
    if(x < raiz->valor)
      raiz->esquerdo = insercao(raiz->esquerdo, x);
    else if(x > raiz->valor)
      raiz->direito = insercao(raiz->direito, x);
    else
      printf("\nErro na inserção realizada!\nO elemento %d a existe!\n");
  }
  raiz->altura = maior(Altura_No(raiz->esquerdo), Altura_No(raiz->direito) + 1);
  raiz = balancear(raiz);

  return raiz;
}

No* balancear(No *raiz)
{

}

int main(){
  return 0;
}
