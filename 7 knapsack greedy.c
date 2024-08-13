#include<stdio.h>
void knapsack(int n, float c, float p[], float w[], float ratio[]);
int main(){
    float ratio[10], p[10], w[10];
    int c, n;
	printf("Enter the capacity of the bag: ");
    scanf("%d", &c);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights and profits: ");
    for(int i = 0; i < n; i++){
        scanf("%f", &w[i]);
        scanf("%f", &p[i]);
    }
    for(int i = 0; i < n; i++){
        ratio[i] = p[i] / w[i];
    }
    knapsack(n, c, p, w, ratio);
	return 0;
}
void knapsack(int n, float c, float p[], float w[], float ratio[]){
    float tp = 0;
    float x[10] = {0};  
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(ratio[j] < ratio[j + 1]){
                float t = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = t;
                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
                t = w[j];
                w[j] = w[j + 1];
                w[j + 1] = t;
            }
        }
    }
    int i;
    for(i = 0; i < n; i++){
        if(w[i] > c)
            break;
        else{
            x[i] = 1;
            tp = tp + p[i];
            c = c - w[i];
        }
    }
    if(i < n){
        x[i] = c / w[i];
        tp = tp + (x[i] * p[i]);
    }
    printf("Items selected are: ");
    for(int j = 0; j < n; j++){
        if(x[j] != 0)
            printf("Item %d ", j + 1);
    }
    printf("\nTotal Profit is: %f\n",tp);
}
