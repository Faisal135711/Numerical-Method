#include<stdio.h>
#include<math.h>

double x0, x1, error = 0.01;
double a[100] = {1, -16, 65, -50};
double b[100];
double dev[100];
int n;

double f(double x, double ar[], int n){
    int i;
    double res = ar[0];
    for(i = 1; i <= n; i++)
        res = res * x + ar[i];

    return res;
}

double derivate(double ar[], int n){
    int i;
    for(i = 0; i < n; i++){
        int temp = n - i;
        dev[i] = temp * ar[i];
    }

    double val = f(x0, dev, n-1);
    return val;
}

void deflate(int n){
    int i;
    double res = 0;
    for(i = 0; i < n; i++){
        b[i] = a[i] + res * x1;
        res = b[i];
    }

    for(i = 0; i < n; i++) a[i] = b[i];
}

int main()
{
    n = 3;

    int temp = n;
    x0 = 0;

    while(temp > 1){
        while(1){
            x1 = x0 - (f(x0,a,temp)/derivate(a, temp));
            if(fabs((x1-x0)/x1) < error) break;
            x0 = x1;
        }
        printf("Root : %0.2f\n", x1);
        deflate(temp);
        temp--;
        x0 = x1;
    }
    printf("Root = %0.2f\n", (-1)*(a[1]/a[0]));

    return 0;
}
