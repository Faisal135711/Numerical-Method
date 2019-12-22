#include<stdio.h>

int main()
{
    int i, j, k, n = 3, p;
    double arr[100][100];
    double s[100], pivot, temp;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%lf", &arr[i][j]);
        }
        scanf("%lf", &s[i]);
    }

    for(p = 0; p < n; p++){
        pivot = arr[p][p];
        for(j = 0; j < n; j++){
            arr[p][j] = arr[p][j]/pivot;
        }
        s[p] = s[p]/pivot;
        for(i = p+1; i < n; i++){
            temp = arr[i][p];
            for(j = 0; j < n; j++){
                arr[i][j] = arr[i][j]-temp*arr[p][j];
            }
            s[i] = s[i]-temp*s[p];
        }
        for(i = p-1; i >= 0; i--){
            temp = arr[i][p];
            for(j = 0; j < n; j++){
                arr[i][j] = arr[i][j]-temp*arr[p][j];
            }
            s[i] = s[i]-temp*s[p];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < n; i++){
        printf("%f\n", s[i]);
    }

    return 0;
}
