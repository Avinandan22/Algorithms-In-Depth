#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int W,N;
	cin >> W >> N;
	int val[N],weight[N];
	for(int i = 0;i < N;i++)
		cin >> weight[i] >> val[i];
	int dp[W + 1][N + 1];
	for(int i = 0;i < W + 1;i++)
	{
		for(int j = 0;j < N + 1;j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else
			{
				if(i - weight[j - 1] >= 0)
				{
					dp[i][j] = ((dp[i - weight[j - 1]][j -1] + val[j - 1]) > dp[i][j - 1] ? (dp[i - weight[j - 1]][j -1] + val[j - 1]) : dp[i][j - 1]);
				}
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	}
	cout << dp[W][N];
	return 0;
	
}