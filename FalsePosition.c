#include<stdio.h>
#include<math.h>

#define E 0.001

int a, b, c;
double x1, x2;

double function_value(double x)
{
    return a*x*x+b*x+c;
}
void set_initial_value()
{
    double f1, f2;
    do{
        printf("Enter x1 and x2: \n");
        scanf("%lf%lf", &x1, &x2);
        f1 = function_value(x1);
        f2 = function_value(x2);
    }while(f1*f2 > 0);
}
void false_position_method()
{
    set_initial_value();
   // printf("aj\n");
    double f1, f2, x0, f0, d, r, g, r1, r2;
 //   f1 = function_value(x1);
   // f2 = function_value(x2);
    do{
        f1 = function_value(x1);
        f2 = function_value(x2);
        r=(x2-x1)*f1;
        r1=f2-f1;
        r2=r/r1;
        x0=x1-r2;
        f0 = function_value(x0);

        if(f0 == 0){
            printf("The root is: %lf\n", x0);
            break;
        }
     //   f1 = function_value(x1);
       // f2 = function_value(x2);
        if(f1*f0 < 0){
          //  printf("y2j\n");
            x2 = x0;
            f2 = f0;
        }
        else{
            printf("ko\n");
            x1 = x0;
            f1 = f0;
        }
        if(fabs((x2-x1)/x2) < E){
            double root = (x1+x2)/2;
            printf("The root is: %lf\n", root);
            break;
        }
      //  printf("%lf\n", fabs((x2-x1)/x2));
    }while(fabs((x2-x1)/x2) >= E);
}
int main()
{
    printf("Enter a, b and c: \n");
    scanf("%d%d%d", &a, &b, &c);

    false_position_method();

    return 0;
}
