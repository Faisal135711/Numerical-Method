#include<stdio.h>

int main()
{
    float matrix[100][100], root[100], temp;
    int n = 3, i, j, k;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= n+1; j++){
            scanf("%f", &matrix[i][j]);
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(j > i){
                temp = matrix[j][i]/matrix[i][i];
                for(k = 1; k <= n+1; k++){
                    matrix[j][k] = matrix[j][k]-temp*matrix[i][k];
                }
            }
        }
    }
    root[n] = matrix[n][n+1]/matrix[n][n];

    for(i = n-1; i >= 1; i--){
        float sum = 0;
        for(j = i+1; j <= n; j++){
            sum += matrix[i][j]*root[j];
        }
        root[i] = (matrix[i][n+1]-sum)/matrix[i][i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    for(i = 1; i <= n; i++){
        printf("%f\n", root[i]);
    }

    return 0;
}
