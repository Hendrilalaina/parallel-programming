#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
double *l, avg;
int i, n = 10000000;
clock_t start, end;

l = (double*) malloc(n * sizeof(double));

for(i = 0; i < n; i++) *(l + i) = i;

start = clock();
for(i = 0; i < n; i++) {
avg += *(l +i);
}
avg /= n;

end = clock();
printf("%lf est la moyenne.\n",avg);
printf("Sequentielle %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
free(l);
return 0; 
}

