
#include <stdio.h>

unsigned int getJacobsthal(unsigned int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

int main() {
    printf("jacobsthal [0] = %d\n", getJacobsthal(0));
    printf("jacobsthal [1] = %d\n", getJacobsthal(1));
    printf("jacobsthal [2] = %d\n", getJacobsthal(2));
    printf("jacobsthal [3] = %d\n", getJacobsthal(3));
    printf("jacobsthal [4] = %d\n", getJacobsthal(4));
    printf("jacobsthal [5] = %d\n", getJacobsthal(5));
    printf("jacobsthal [6] = %d\n", getJacobsthal(6));
    printf("jacobsthal [7] = %d\n", getJacobsthal(7));
}