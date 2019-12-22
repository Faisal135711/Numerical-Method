#include<stdio.h>

int main()
{
    double x[] = {5, 6, 9, 11};
    double y[] = {12, 13, 14, 16};
    double X = 10;
    double fx = 0;
    int i, j, n = 4;

    for(i = 0; i < n; i++){
        double den = 1;
        double num = 1;

        for(j = 0; j < n; j++){
            if(i != j){
                num *= (X-x[j]);
                den *= (x[i]-x[j]);
            }
        }
        fx += (num/den)*y[i];
    }
    printf("f(x) = %f\n", fx);

    return 0;
}
