/*
    Fib4.c
    O(1)
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAX_AMOSTRAS 100

long double fib(int n){
  return (pow((1 + sqrt(5)), n) - pow((1 - sqrt(5)), n))/(pow(2,n)*sqrt(5)); //Formula fechada da recorrência
}

int main()
{
    //num = Posição final desejada da sequência de Fibonnaci
    int num = 40;
    double tempoTotal = 0;
    clock_t ticks[2];
    long double result;

    for(int i = 0; i < MAX_AMOSTRAS; i++){
      ticks[0] = clock(); //Início do cronômetro
      /*
        A função clock devolve o tempo de CPU decorrido desde o
        início da execução. O tempo é medido em
        ciclos do relógio interno. Cada  CLOCKS_PER_SEC ciclos
        correspondem aproximadamente a 1 segundo. Uso típico:
      */
      result = fib(num); //Chamada da função fib

      ticks[1] = clock();//Fim do cronômetro
      tempoTotal += (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; // (Tempo final - Tempo inicial)* 1000.0 / 1000000
    }    

    printf("\nO %d termo de Fibonacci é %.0Lf\n", num, result);
    printf("A médio do tempo é %f ms\n", tempoTotal/MAX_AMOSTRAS);
    return 0;
}
