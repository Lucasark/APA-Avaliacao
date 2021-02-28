#include <stdio.h>
#include <math.h>

int ehPar(int num)
{
    if (num % 2 == 0)
        return 1;
    return 0;
}

int main()
{
    int n = 49;
    long t;
    long i = 1, j = 0, k = 0, h = 1;

    while (n > 0)
    {
        //printf("===========init loop %i\n", n);
        if (!ehPar(n))
        {
            //printf("===init impar\n");
            t = j * h;
            //printf("t:%li\n", t);
            j = i * h + j * k + t;
            //printf("j:%li\n", j);
            i = i * k + t;
            //printf("i:%li\n", i);
            // printf("===fim impar\n");
        }
        t = pow(h, 2);
        //printf("t:%li\n", t);
        h = 2 * k * h + t;
        //printf("h:%li\n", h);
        k = pow(k, 2) + t;
        //printf("k:%li\n", k);
        //printf("===========end loop %i\n", n);
        n = n / 2;
    }

    printf("%li", j);
    //Esperado 433494437

    return j;
}
