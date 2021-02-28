#include <stdio.h>
#include <time.h>

int fib(int n)
{
    long int i = 0;
    long int j = 1;
  for(int k = 1; k < n; k++){
    j = i+j;
    i = j-i;
  }
  return j;
}

int main()
{
    //num = Posição final desejada da sequência de Fibonnaci
    int num = 48;

    //ticks = Vetor da estrutura clock_t
    clock_t ticks[2];
    /*
        A função clock devolve o tempo de CPU decorrido desde o
        início da execução. O tempo é medido em
        ciclos do relógio interno. Cada  CLOCKS_PER_SEC ciclos
        correspondem aproximadamente a 1 segundo. Uso típico:
    */

    ticks[0] = clock(); //Início do cronômetro

    long int result = fib(num); //Chamada da função fib

    ticks[1] = clock();//Fim do cronômetro
    double tempoGasto = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; // (Tempo final - Tempo inicial)* 1000.0 / 1000000

    printf("Tempo gasto: %g ms.", tempoGasto);
    printf("\nO %d termo de Fibonacci é %ld", num, result);
    return 0;
}
