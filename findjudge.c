#include <stdlib.h>

int findJudge(int n, int** trust, int trustSize, int* trustColSize) {
    int *count = (int*)calloc(n + 1, sizeof(int));
    int *trustedBy = (int*)calloc(n + 1, sizeof(int));
    
    // Step 2: Update count and trustedBy arrays
    for (int i = 0; i < trustSize; i++) {
        int a = trust[i][0];
        int b = trust[i][1];
        
        count[a]--;
        count[b]++;
        trustedBy[b]++;
    }
    
    // Step 3: Check for town judge
    for (int i = 1; i <= n; i++) {
        if (count[i] == n - 1 && trustedBy[i] == n - 1) {
            free(count);
            free(trustedBy);
            return i; // town judge found
        }
    }
    
    // Step 4: No town judge found
    free(count);
    free(trustedBy);
    return -1;
}
