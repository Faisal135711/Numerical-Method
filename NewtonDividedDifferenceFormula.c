#include<stdio.h>

double x[] = {5, 7, 11, 13, 21};
double y[] = {150, 392, 1452, 2366, 9702};
int cnt = 1;

int main()
{
    double givenX = 6, temp, res1 = 0.0, res2 = 0.0, prod = 1;

    int n = 4;
    int i;
    res2 = y[0];
    do{
        for(i = 0; i < n; i++){
            temp = (y[i+1]-y[i])/(x[cnt+i]-x[i]);
            y[i] = temp;
        }

        prod = 1;
        for(i = 0; i < cnt; i++){
            prod *= (givenX-x[i]);
        }

        res1 += prod*y[0];

        n--;
        cnt++;
    }while(n != 0);

    res2 += res1;

    printf("%f\n", res2);

    return 0;
}
