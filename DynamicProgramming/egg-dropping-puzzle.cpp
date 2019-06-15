#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin >> n >> k;
	int dp[k + 1][n + 1];
	dp[0][0] = 0;
	for(int i = 0;i < k + 1;i++)
	{
		for(int j = 1;j < n + 1;j++)
		{ 
			if(i == 0)
				dp[i][j] = 0;
			else if(i == 1)
				dp[i][j] == 1;
			else if(j == 1)
				dp[i][j] = i;
			else
			{
				int min = 100000;
				for(int x = 1;x <= i;x++)
				{
					if (min > ((dp[x - 1][j - 1] > dp[i - x][j]) ? dp[x - 1][j - 1] + 1 : dp[i - x][j] + 1))
						min = ((dp[x - 1][j - 1] > dp[i - x][j]) ? dp[x - 1][j - 1] + 1 : dp[i - x][j] + 1);
				}
				dp[i][j] = min;
			}
		}
	}
	cout << dp[k][n];
	return 0;
}