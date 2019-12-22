#include<stdio.h>
#include<math.h>

#define E 0.001

double a, b, x1, x2, x0, dx = 0.02, f1, f2, f0;
double arr[] = {1, -7, 10};
int n = 2;
double func_value(double x)
{
    int i;
    double res = arr[0];
    for(i = 1; i <= n; i++){
        res = res*x+arr[i];
    }
    return res;
}
int main()
{
    a = -2;
    b = 10;

    while(1){
        x1 = a;
        x2 = x1+dx;

        if(x2 > b) break;
        f1 = func_value(x1);
        f2 = func_value(x2);
        //printf("aj\n");
        if(f1*f2 > 0){
            a = x2;
            continue;
        }
    //    printf("y2j\n");
        while(1){
            x0 = (x1+x2)/2;
            f0 = func_value(x0);

            if(f0 == 0){
                printf("Root = %f\n", x0);
                break;
            }
            if(f0*f1 < 0){
                x2 = x0;
                f2 = f0;
            }
            else{
                x1 = x0;
                f1 = f0;
            }
            if(fabs((x2-x1)/x2) < E){
                double root = (x1+x2)/2;
                printf("Root = %f\n", root);
                break;
            }
        }
        if(x2 < b){
            a = x2;
            continue;
        }
        else break;
    }

    return 0;
}
