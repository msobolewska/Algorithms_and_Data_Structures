#include <stdio.h>
#include <stdlib.h>

long int Find_Ways(int *coins, int m, int n, int j, int poziom, long int **MemCoins);
int main(){
    FILE* input;
    input = fopen("Coin_Change.txt", "r");

    if(!input){
        return 0;
    }

    int n,m;

    fscanf(input, "%d", &n);// Expected_sum
    fscanf(input, "%d", &m);//Number_of_coins

    if(m==0 || n==0){
        printf("0\n");
        return 0;
    }

    int *coins = (int*)malloc(m*sizeof(int));
    long int **MemCoins= (long int**)malloc((n+1)*sizeof(long int*));
    for(int i = 0; i < n+1; i++)
    {
        MemCoins[i] = (long int*)malloc(m*sizeof(long int));
        for(int j=0;j<m;j++){
        MemCoins[i][j] = -1;
        }
    }

    for(int i = 0; i < m; i++)
    {
        fscanf(input, "%d", &coins[i]);
        if(coins[i] == 0){
            i--;
            m--;
        }
    }

    printf("%ld\n", Find_Ways(coins, m, n, 0,0, MemCoins));

    for(int i = 0; i < n+1; i++)
        {
            for(int j=0;j<m;j++){
            //printf("%ld ", MemCoins[i][j]);
            }
            //printf("\n");
    }

    free(coins);
    for(int i = 0; i < n+1; i++)
    {
        free(MemCoins[i]);
    }
    free(MemCoins);

    return 0;
}

long int Find_Ways(int *coins, int m, int n, int j, int poziom, long int **MemCoins){
    if(poziom == n){
        return 1;
    }
    else if(j>m-1 || poziom>n){
        return 0;
    }
    else if(MemCoins[poziom][j] > -1){
        return MemCoins[poziom][j];
    }
    else{
        MemCoins[poziom][j]=Find_Ways(coins, m, n, j+1, poziom, MemCoins)+Find_Ways(coins, m, n, j, poziom+coins[j], MemCoins);
        return MemCoins[poziom][j];
    }
}
