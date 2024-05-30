/*
** Função : Classifica os elementos de um vetor em ordem crescente
** Autor : João Victor Barbosa Perazzo
** Data : 25/05/2024
** Observações:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int *alocaVetor(int n);
int *gerarVetor(int n);
void exibirVetor(int *vetor, int n);
void Selecao(int m, int *x);

int main()
{
  setlocale(LC_ALL, "Portugese");

  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  printf("\n");

  int *vetor = gerarVetor(n);
  printf("Vetor gerado: ");
  exibirVetor(vetor, n);

  Selecao(n, vetor);
  printf("Vetor ordenado: ");
  exibirVetor(vetor, n);

  return 0;
}

int *alocaVetor(int n)
{
  int *vetor = (int *)malloc(n * sizeof(int));
  if (vetor == NULL)
  {
    printf("Erro ao alocar memória\n");
    exit(1);
  }

  return vetor;
}

int *gerarVetor(int n)
{
  srand(time(NULL));
  int *vetor = alocaVetor(n);
  for (int i = 0; i < n; i++)
  {
    vetor[i] = rand() % 100;
  }

  return vetor;
}

void exibirVetor(int *vetor, int n)
{
  printf("[ ");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf(" ]\n");
}

void Selecao(int m, int *x)
{
  int aux, j, i, maior;
  for (i = 0; i < m - 1; i++)
  {
    maior = 0;
    for (j = 0; j < m - i; j++)
      if (x[j] > x[maior])
        maior = j;

    aux = x[m - i - 1];
    x[m - i - 1] = x[maior];
    x[maior] = aux;
  }
}