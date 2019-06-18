#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int G[15][15];
	for(int k = 0;k < 15;k++)
	{
		int i = 0;
		for(int j = k;j >= 0;j--)
		{
			int val;
			vector <int> arr;;
			if(i > 1 && j < 14)
				arr.push_back(G[i - 2][j + 1]);
			if(i > 1 && j > 0)
				arr.push_back(G[i - 2][j - 1]);
			if(i < 14 && j > 1)
				arr.push_back(G[i + 1][j - 2]);
			if(i > 0 && j > 1)
				arr.push_back(G[i - 1][j - 2]);
			if(arr.size() == 0)
				G[i][j] = 0;
			else
			{
				std::vector<int>::iterator it; 
				for(val = 0;val < 5;val++)
				{
					it = std::find (arr.begin(), arr.end(), val);
					if(it == arr.end())
						break;
				}
				G[i][j] = val;
			}
			i++;
		}
	}
	for(int k = 15;k < 29;k++)
	{
		for(int l = 1;l < 15;l++)
		{ 
			int i = l;
			for(int j = 14;j >= l;j--)
			{
				int val;
				vector <int> arr;;
				if(i > 1 && j < 14)
					arr.push_back(G[i - 2][j + 1]);
				if(i > 1 && j > 0)
					arr.push_back(G[i - 2][j - 1]);
				if(i < 14 && j > 1)
					arr.push_back(G[i + 1][j - 2]);
				if(i > 0 && j > 1)
					arr.push_back(G[i - 1][j - 2]);
				if(arr.size() == 0)
					G[i][j] = 0;
				else
				{
					std::vector<int>::iterator it; 
					for(val = 0;val < 5;val++)
					{
						it = std::find (arr.begin(), arr.end(), val);
						if(it == arr.end())
							break;
					}
					G[i][j] = val;
				}
				i++;
			}

		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int x,y,result = 0;
		for(int i = 0;i < k;i++)
		{
			cin >> x >> y;
			result = result ^ G[x - 1][y - 1];
		}
		if(result)
			cout << "First" << endl;
		else
			cout << "Second" << endl;		
	}
	return 0;
}