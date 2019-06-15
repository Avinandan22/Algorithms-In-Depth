#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define long long long 
int main()
{
	long n,h,w;
	cin >> n >> h >> w;
	long h1,w1;
	vector <pair <long,pair<long,pair<long,long>  > > >   dp; 
	for(long i = 0;i < n;i++)
	{
		cin >> h1 >> w1;
		if(h1 > h  && w1 > w)
			dp.push_back(make_pair(h1 * w1,make_pair(i , make_pair(h1,w1))));
	}
	n = dp.size();
	if(n)
	{
		sort(dp.begin(),dp.end());
		long max[n] = {0};
		vector <pair <int,int> > prev;
		long temp = 0,last,index;
		for(long i = n - 1;i >= 0;i--)
		{
			temp = 0,index = -1,last =  (dp[i].second).first;
			for(long j = i + 1;j < n;j++)
			{
				if(((dp[j].second).second).first > ((dp[i].second).second).first && ((dp[j].second).second).second > ((dp[i].second).second).second && max[j] > temp)
					temp = max[j],index = n - 1 - j;
			}
			prev.push_back(make_pair(index,last));
			max[i] = temp + 1;
		}
		long high = 0,idx;
		for(long i = 0;i < n;i++)
		{
			if(max[i] > high)
				high = max[i],idx = n - 1 - i;
		}
		cout << high << endl << prev[idx].second + 1;
		while(prev[idx].first + 1)
		{
			idx = prev[idx].first;
			cout << " " << prev[idx].second + 1;
		}
	}
	else
		cout << 0;
	return 0;
}