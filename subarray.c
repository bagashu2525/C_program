//CREATE A PROGRAM TO FIND THE LONGEST SUBARRAY WITH A SUM LESS THAN OR EQUAL TO A GIVEN VALUE.
#include <stdio.h>

int maxLength(int arr[], int n, int k) {
	int i;
    int subarrayStart = 0;
    int subarrayEnd = 0;
    int subarraySum = 0;
    int maxLength = -1; // Returns -1 if there is no subarray that adds up to k.

    for ( i = 0; i < n; i++) {
        subarraySum += arr[i];
        subarrayEnd++;

        while (subarraySum > k) {
            // Shrink the array from the left until the sum is <= k.
            subarraySum -= arr[subarrayStart];
            subarrayStart++;
        }

        // After the previous while loop, subarraySum is guaranteed to be
        // smaller than or equal to k.
        maxLength = (maxLength > subarrayEnd - subarrayStart) ? maxLength : subarrayEnd - subarrayStart;
    }

    return maxLength;
}

int main() {
    int s1[] = {1, 2, 3};
    int n1 = sizeof(s1) / sizeof(s1[0]);
    int k1 = 4;
    printf("Input1: s = {1, 2, 3}, k = %d\n", k1);
    printf("Output1: %d\n", maxLength(s1, n1, k1)); // Output1: 2

    int s2[] = {3, 1, 2, 0, 1, 1, 3,1};
    int n2 = sizeof(s2) / sizeof(s2[0]);
    int k2 = 4;
    printf("Input2: s = {3, 1, 2,0,1, 1}, k = %d\n", k2);
    printf("Output2: %d\n", maxLength(s2, n2, k2)); // Output2: 3

    return 0;
}

