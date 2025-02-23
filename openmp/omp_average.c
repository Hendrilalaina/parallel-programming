#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define SIZE 10000000

int main() {
double *l;
long long avg;
unsigned int i;//, n = 10000000;
double start, end;
l = (double*) malloc(SIZE * sizeof(double));

//#pragma omp parallel for
for(i = 0; i < SIZE; i++) *(l + i) = i;
start = omp_get_wtime();
#pragma omp parallel for reduction (+:avg)
for(i = 0; i < SIZE; i++) {
avg += *(l +i);
}
end = omp_get_wtime();
avg /= SIZE;
printf("%lld est la moyenne.\n",avg);
printf("Parallele %f seconds.\n", (end - start));
free(l);
return 0; 
}

