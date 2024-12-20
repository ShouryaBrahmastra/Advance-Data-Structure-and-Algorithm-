/**
 * 
 * Write the implementation of matrix chain multiplication.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
#include <climits>
using namespace std;


int matrixChainMultiplication(int *dims, int n) {
    
    int dp[n][n];

   
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    
    for (int L = 2; L < n; L++) 
    {
        for (int i = 1; i < n - L + 1; i++) 
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    
    return dp[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int dims[n + 1];
    cout << "Enter the dimensions of the matrices:\n";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    }

    int minCost = matrixChainMultiplication(dims, n + 1);
    cout << "Minimum number of multiplications is: " << minCost << endl;

    return 0;
}
