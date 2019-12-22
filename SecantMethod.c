#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define E 0.001

float* arr;
float x1, x2, f1, f2;
int n, iteration = 0, root = 0;

float function_value(float x)
{
    float result = arr[0];
    int i;
    for(i = 1; i <= n; i++){
        result = result*x + arr[i];
    }
    return result;
}
void SecantMethod(float x1, float x2)
{
    float x3, f3;
    int i = 0;
    while(1){
        f1 = function_value(x1);
        f2 = function_value(x2);
        x3 = x2-(f2*(x2-x1)/(f2-f1));

        printf("%d\t\t", ++iteration);
        if(x1>=0){
            printf("+\t");
        }
        else{
            printf("-\t");
        }
        if(x2 >= 0){
            printf("+\t");
        }
        else{
            printf("-\t");
        }
        if(x3 >= 0){
            printf("+\t");
        }
        else{
            printf("-\t");
        }
        printf("%f\t", f1);
        printf("%f\n", f2);
        if(fabs((x3-x2)/x3) < E){
            printf("root #%d: %f\n", ++root, x3);
            break;
        }
        f3 = function_value(x3);
        x1 = x2;
        x2 = x3;
        f1 = f2;
        f2 = f3;
    }
}
void input()
{
    int i;
    n = 4;

    arr = (float*)malloc(sizeof(float)*n);
    arr[0] = 1;
    arr[1] = -22;
    arr[2] = 21;
    arr[3] = 0;
    printf("Iteration\tx1\tx2\tx3\tf1\t\tf2\n");
    x1 = -2, x2 = 2;
    iteration = 0;
    SecantMethod(x1, x2);
    x1 = -0.4, x2 = 0.5;
    iteration = 0;
    SecantMethod(x1, x2);
    x1 = 25, x2 = 19;
    iteration = 0;
    SecantMethod(x1, x2);

    free(arr);
}
int main()
{
    input();

    return 0;
}
