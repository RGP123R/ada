#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
void fnGenRandInput(int arr[], int size);
void fnDispArray(int arr[], int size);
int fnPartition(int arr[], int low, int high);
void fnQuickSort(int arr[], int low, int high);
void fnSwap(int* a, int* b);
void fnSwap(int *a, int *b) {
 int t = *a; 
 *a = *b; 
 *b = t;
}
void fnGenRandInput(int arr[], int size) {
 srand(time(NULL)); 
 for (int i = 0; i < size; i++) {
 arr[i] = rand() % 1000; 
 }
}
void fnDispArray(int arr[], int size) {
 for (int i = 0; i < size; i++) {
 printf("%d ", arr[i]);
 }
 printf("\n");
}
int fnPartition(int arr[], int low, int high) {
 int pivot = arr[high]; 
 int i = (low - 1);  
 for (int j = low; j <= high - 1; j++) {
 if (arr[j] < pivot) {
 i++;
 fnSwap(&arr[i], &arr[j]);
 }
 }
 fnSwap(&arr[i + 1], &arr[high]);
 return (i + 1);
}
void fnQuickSort(int arr[], int low, int high) {
 if (low < high) {
 int pi = fnPartition(arr, low, high); fnQuickSort(arr, low, pi - 1);
 fnQuickSort(arr, pi + 1, high);
 }
}
int main() {
 FILE *fp;
 struct timeval tv;
 double dStart, dEnd;
 int iaArr[500000], iNum, iChoice;
 while (1) {
 printf("\n1.Plot the Graph\n2.QuickSort\n3.Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &iChoice);
 switch (iChoice) {
 case 1:
 printf("\nBefore file creation\n");
 fp = fopen("QuickPlot.dat", "w");
 if (fp == NULL) {
 perror("Error opening file QuickPlot.dat");
 printf("Error: Unable to create QuickPlot.dat file for writing.\n");
 exit(1);
 }
 printf("File created successfully\n");
 printf("\nGenerating data...\n");
 for (int i = 100; i <= 100000; i += 100) {
 fnGenRandInput(iaArr, i);
 gettimeofday(&tv, NULL);
 dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
 fnQuickSort(iaArr, 0, i - 1);
 gettimeofday(&tv, NULL);
 dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
 fprintf(fp, "%d\t%lf\n", i, dEnd - dStart);
 }
 
 fclose(fp);
 printf("\nData File generated and stored in file < QuickPlot.dat >.\n Use a plotting utility\n");
 break;
 case 2:
 printf("\nEnter the number of elements to sort: ");
 scanf("%d", &iNum);
 printf("\nUnsorted Array\n");
 fnGenRandInput(iaArr, iNum);
 fnDispArray(iaArr, iNum);
 fnQuickSort(iaArr, 0, iNum - 1);
 printf("\nSorted Array\n");
 fnDispArray(iaArr, iNum);
 break;
 case 3:
 exit(0);
 default:
 printf("\nInvalid choice. Please enter a valid option.\n");
 }
 }
 return 0;
}