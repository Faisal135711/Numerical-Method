#include<stdio.h>
#include<math.h>

float x[100], y[100], c[100][100], a[100], b[100];
int n, mp, m;

void Normal()
{
    int i, j, k, l1, l2;

    for(j = 1; j <= m; j++){
        for(k = 1; k <= m; k++){
            c[j][k] = 0.0;
            l1 = k+j-2;
            for(i = 1; i <= n; i++){
                c[j][k] = c[j][k] + pow(x[i], l1);
            }
        }
    }
    for(j = 1; j <= m; j++){
        b[j] = 0.0;
        l2 = j-1;
        for(i = 1; i <= n; i++){
            b[j] = b[j] + y[i]*pow(x[i], l2);
        }
    }
}
void Gauss_Elimination(int n)
{
    int i, j, k;
    float pivot, factor, sum;

    ///b = b // a = c // x = a
    for(k = 1; k <= n-1; k++){
        pivot = c[k][k];
        for(i = k+1; i <= n; i++){
            factor = c[i][k]/pivot;
            for(j = k+1; j <= n; j++){
                c[i][j] = c[i][j]-factor*c[k][j];
            }
            b[i] = b[i]-factor*b[k];
        }
    }
    a[n] = b[n]/c[n][n];
    for(k = n-1; k >= 1; k--){
        sum = 0.0;
        for(j = k+1; j <= n; j++){
            sum = sum+c[k][j]*a[j];
        }
        a[k] = (b[k]-sum)/c[k][k];
    }
}
int main()
{
    int i, j, k;

    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter order: ");
    scanf("%d", &mp);

    m = mp+1;

    for(i = 1; i <= n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }

    Normal();
    Gauss_Elimination(m);

    for(i = 1; i <= m; i++){
        printf("%f\n", a[i]);
    }

    return 0;
}
