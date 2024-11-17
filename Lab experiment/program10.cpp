/**
 * 
 * Write the code for LCS.
 * 
 * Author: Shourya Gupta 
 * Copyright: ShouryaBrahmastra
 * 
 * **/
#include <iostream>
#include <vector>
#include <string>
using namespace std;


int LCS(string str1, string str2) 
{
    int n = str1.length();
    int m = str2.length();

    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}


string findLCS(string str1, string str2) 
{
    int n = str1.length();
    int m = str2.length();

    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else 
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    
    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) 
    {
        if (str1[i - 1] == str2[j - 1]) 
        {
            lcs = str1[i - 1] + lcs;
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        {
            i--;
        } 
        else 
        {
            j--;
        }
    }

    return lcs;
}

int main() 
{
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;

    int length = LCS(str1, str2);
    string lcs = findLCS(str1, str2);

    cout << "Length of Longest Common Subsequence: " << length << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
