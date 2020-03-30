class Solution {
public:
    int numTrees(int n) {
        int ret;

        if (n == 0 || n == 1) {
            return 1;
        }

        if (n == 2) {
            return 2;
        }

        int* partial = new int[n+1];
        
        partial[0] = 1;
        partial[1] = 1;
        partial[2] = 2;

        for (int i = 3; i <= n; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                for (int k = i-1-j; j + k < i; k++) {
                    tmp += (partial[j] * partial[k]);
                }
            }
            partial[i] = tmp;
        }

        ret = partial[n];
        delete[] partial;

        return ret; 
    }
};
