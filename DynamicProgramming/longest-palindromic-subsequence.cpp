#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int dp[n][n];
	for(int len = 0;len < n;len++)
	{
		int sta = 0,fin = len;
		for(sta = 0;sta + len < n;sta++)
		{
			if(sta == fin)
				dp[sta][fin] = 1;
			else if(s[sta] == s[fin] && (fin - sta) > 1)
				dp[sta][fin] = dp[sta + 1][fin - 1] + 2;
			else if(s[sta] == s[fin])
				dp[sta][fin] = 2;
			else
				dp[sta][fin] = ((dp[sta + 1][fin] > dp[sta][fin - 1]) ? dp[sta + 1][fin] : dp[sta][fin - 1]);
			fin++;
		}
	}
	cout << dp[0][n - 1];
	return 0;
}