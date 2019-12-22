#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define E 0.001
float* arr;

float function_value(int n, float x)
{
    float result = arr[0];
    int i;
    for(i = 1; i <= n; i++){
        result = result*x + arr[i];
    }
    return result;
}
float derivative_value(float x)
{
    return 2*x-3;
}
void NewtonRaphsonMethod(int n, float x0)
{
    float x1, f1, f2;
    int i = 0;
    while(1){
        f1 = function_value(n, x0);
        f2 = derivative_value(x0);
        x1 = x0-(f1/f2);

    //    printf("error = %f\n", fabs((x1-x0)/x1));
        if(fabs((x1-x0)/x1) < E){
            printf("The root of the equation: %f\n", x1);
            break;
        }
        x0 = x1;
    }
}
void input()
{
  //  float* arr;
    int n, i;
    float x0;

    printf("Enter the degree of the equation: ");
    scanf("%d", &n);

    arr = (float*)malloc(sizeof(float)*n);

    printf("Enter co-efficients of the equation: ");
    for(i = 0; i <= n; i++){
        scanf("%f", &arr[i]);
    }
    printf("Enter the initial value ");
    scanf("%f", &x0);

    NewtonRaphsonMethod(n, x0);

    free(arr);
}
int main()
{
    input();

    return 0;
}
