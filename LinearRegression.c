#include<stdio.h>

int main()
{
    double points[100][100], sumX, sumY, sumXY, sqrX, sqrY, a, b;
    int n, i, j;

    sumX = sumY = sumXY = sqrX = sqrY = 0;

    printf("Enter the number of points: ");
    scanf("%d", &n);
    printf("Enter the points:\n");
    for(i = 0; i < n; i++){
        scanf("%lf", &points[0][i]);
        scanf("%lf", &points[1][i]);
        sumX += points[0][i];
        sumY += points[1][i];
        sumXY += (points[0][i]*points[1][i]);
        sqrX += (points[0][i]*points[0][i]);
    }

    double den = n*sqrX-(sumX)*(sumX);
    if(den != 0){
        b = (n*(sumXY)-(sumX*sumY))/den;
        a = (sumY/n)-b*(sumX/n);
        printf("y = %0.2f + %0.2fx\n", a, b);
    }


    return 0;
}
