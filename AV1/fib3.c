/*
    Fib3.c
    O(Log n)
*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX_AMOSTRAS 100

int ehPar(int num) {
    if (num % 2 == 0)
        return 1;
    return 0;
}

long double fib(int num){
    long double t;
    long double i = 1, j = 0, k = 0, h = 1;

    while (num > 0) {       
        if (!ehPar(num)) {
            t = j * h;
            j = i * h + j * k + t;
            i = i * k + t;
        }
        t = pow(h, 2);
        h = 2 * k * h + t;
        k = pow(k, 2) + t;
        num = num / 2;
    }
    return j;
}

int main() {
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
        result = fib(num);
        ticks[1] = clock();//Fim do cronômetro
        tempoTotal += (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC; // (Tempo final - Tempo inicial)* 1000.0 / 1000000
    }

    printf("\nO %d termo de Fibonacci é %.0Lf\n", num, result);
    printf("A médio do tempo é %f ms\n", tempoTotal/MAX_AMOSTRAS);

    return 0;
}
