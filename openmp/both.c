#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define SIZE 10000000

int main() {
double *l;
double avg;
unsigned int i;//, n = 10000000;
double startp, endp;
clock_t starts, ends;

l = (double*) malloc(SIZE * sizeof(double));


for(i = 0; i < SIZE; i++) *(l + i) = i;

starts = clock();
for(i = 0; i < SIZE; i++) {
avg += *(l +i);
}
avg /= SIZE;
ends = clock();

printf("\n%2.lf est la moyenne.\n",avg);
printf("Sequentielle %f seconds.\n", (double)(ends - starts) / CLOCKS_PER_SEC);

avg = 0;
omp_set_num_threads(16);
startp = omp_get_wtime();
#pragma omp parallel for reduction (+:avg)
for(i = 0; i < SIZE; i++) {
avg += *(l +i);
}
avg /= SIZE;
endp = omp_get_wtime();

printf("\n%2.lf est la moyenne.\n",avg);
printf("Parallele %f seconds.\n\n", (endp - startp));

free(l);
return 0; 
}

