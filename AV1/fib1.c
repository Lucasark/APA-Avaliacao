#include <stdio.h>
#include <time.h>

long double fib(long double n)
{
    if (n < 2)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    //num = Posição final desejada da sequência de Fibonnaci
    int num = 47;

    //ticks = Vetor da estrutura clock_t
    clock_t ticks[2];
    /*
        A função clock devolve o tempo de CPU decorrido desde o
        início da execução. O tempo é medido em
        ciclos do relógio interno. Cada  CLOCKS_PER_SEC ciclos
        correspondem aproximadamente a 1 segundo. Uso típico:
    */

    ticks[0] = clock(); //Início do cronômetro

    long double result = fib(num); //Chamada da função fib

    ticks[1] = clock();//Fim do cronômetro
    double tempoGasto = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; // (Tempo final - Tempo inicial)* 1000.0 / 1000000

    printf("Tempo gasto: %g ms.", tempoGasto);
    printf("\nO %d termo de Fibonacci é %Lf\n", num, result);
    return 0;
}
