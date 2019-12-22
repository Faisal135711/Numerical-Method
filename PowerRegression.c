#include<stdio.h>
#include<math.h>

int main()
{
    double points[2][100], a, b, sum_lnX, sum_lnY, sum_lnXY, sqr_lnX;
    int i, j, n;

    sum_lnX = sum_lnY = sum_lnXY = sqr_lnX = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the points:\n");
    for(i = 0; i < n; i++){
        scanf("%lf", &points[0][i]);
        scanf("%lf", &points[1][i]);
        sum_lnX += log(points[0][i]);
        sum_lnY += log(points[1][i]);
        sum_lnXY += log(points[0][i])*log(points[1][i]);
        sqr_lnX += pow(log(points[0][i]), 2);
    }
    double den = n*sqr_lnX - (sum_lnX*sum_lnX);
    if(den != 0){
        b = (n*sum_lnXY-(sum_lnX*sum_lnY))/den;
        double R = (sum_lnY-b*sum_lnX)/n;
        a = exp(R);
        printf("y = %0.2fx^%0.2f\n", a, b);
    }

    return 0;
}
