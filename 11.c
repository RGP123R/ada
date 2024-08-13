#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
void fnGenRandInput(int [], int);
void fnDispArray(int [], int);
void fnMerge(int [], int, int, int);
void fnMergeSort(int [], int, int);
int main() {
FILE *fp;
struct timeval tv;
double dStart, dEnd;
int iaArr[500000], iNum, i, iChoice;
do {
printf("\n1. Plot the Graph\n2. Merge Sort\n3. Exit\n");
printf("Enter your choice: ");
scanf("%d", &iChoice);
switch (iChoice) {
case 1:
printf("\nBefore file creation\n");
fp = fopen("MergePlot.dat", "w");
if (fp == NULL) {
perror("Error opening file MergePlot.dat");
printf("Error: Unable to create MergePlot.dat file for writing.\n");
exit(1);
}
printf("File created successfully\n");
printf("\nGenerating data...\n");
for (i = 100; i < 100000; i += 100) {
fnGenRandInput(iaArr, i);
gettimeofday(&tv, NULL);
dStart = tv.tv_sec + (tv.tv_usec / 1000000.0);
fnMergeSort(iaArr, 0, i - 1);
gettimeofday(&tv, NULL);
dEnd = tv.tv_sec + (tv.tv_usec / 1000000.0);
fprintf(fp, "%d\t%lf\n", i, dEnd - dStart);
}
fclose(fp);
printf("\nData File generated and stored in file <MergePlot.dat>.\nUse a plotting utility\n");
break;
case 2:
printf("\nEnter the number of elements to sort: ");
scanf("%d", &iNum);
printf("\nUnsorted Array:\n");
fnGenRandInput(iaArr, iNum);
fnDispArray(iaArr, iNum);
fnMergeSort(iaArr, 0, iNum - 1);
printf("\nSorted Array:\n");
fnDispArray(iaArr, iNum);
printf("\nSorting completed.\n");
break;
case 3:
printf("\nExiting the program...\n");
exit(0);
default:
printf("\nInvalid choice! Please enter a valid option.\n");
}
} while (iChoice != 3);
return 0;
}
void fnMerge(int a[], int l, int m, int r) {
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
int *L = (int *)malloc(n1 * sizeof(int));
int *R = (int *)malloc(n2 * sizeof(int));
for (i = 0; i < n1; i++)
L[i] = a[l + i];
for (j = 0; j < n2; j++)
R[j] = a[m + 1 + j];
i = 0;
j = 0;
k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
a[k] = L[i];
i++;
} else {
a[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
a[k] = L[i];
i++;
k++;
}
while (j < n2) {
a[k] = R[j];
j++;
k++;
}
free(L);
free(R);
}
void fnMergeSort(int a[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
fnMergeSort(a, l, m);
fnMergeSort(a, m + 1, r);
fnMerge(a, l, m, r);
}
}
void fnGenRandInput(int X[], int n) {
int i;
srand(time(NULL));
for (i = 0; i < n; i++) {
X[i] = rand() % 10000;
}
}
void fnDispArray(int X[], int n) {
int i;
for (i = 0; i < n; i++) {
printf("%5d", X[i]);
}
printf("\n");
}
