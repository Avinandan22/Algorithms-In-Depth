#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	long long n = s.size();
	long long l[n][n];
	long long palend[n][n];
	for(long long k = 0;k < n;k++)
	{
		long long j = k;
		for(long long i = 0;i + k < n;i++)
		{
			if(i == j)
				palend[i][j] = 1;
			else if(s[i] != s[j])
				palend[i][j] = 0;
			else if(j - i >= 2 )
				palend[i][j] = palend[i + 1][j - 1];
			else if(j - i == 1)
				palend[i][j] = 1;
			j++;
		}

	}
	long long cumsta[n][n];
	for(long long k = 0;k < n;k++)
	{
		long long j = k;
		for(long long i = 0;i + k < n;i++)
		{
			if(i == j)
				cumsta[i][j] = 1;
			else if(j - i == 1)
				cumsta[i][j] = palend[i][j] + 1;
			else
				cumsta[i][j] = palend[i][j] + cumsta[i][j - 1];
			j++;
		}
	}
	long long cumfin[n][n];
	for(long long k = 0;k < n;k++)
	{
		long long j = n - 1;
		for(long long i = n - k - 1;i >= 0;i--)
		{
			if(i == j)
				cumfin[i][j] = 1;
			else if(j - i == 1)
				cumfin[i][j] = palend[i][j] + 1;
			else
				cumfin[i][j] = palend[i][j] + cumfin[i + 1][j];
			j--;
		}
	}
	long long count = 0;
	long long dp[n][n];
	for(long long k = 1;k < n;k++)
	{
		long long j = k;
		for(long long i = 0;i + k < n;i++)
		{
			if(s[i] != s[j])
				dp[i][j] = 0;
			else if(k == 1)
				dp[i][j] = 1;
			else if(k == 2)
				dp[i][j] = 3;
			else
				dp[i][j] = 1 + dp[i + 1][j - 1] + cumsta[i + 1][j - 1] + cumfin[i + 1][j - 1];
			count += dp[i][j];
			j++;
		}
	}
	cout << count;
	return 0;
}