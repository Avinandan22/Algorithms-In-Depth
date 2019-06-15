#include<bits/stdc++.h>
#include <iterator> 
#include<iostream>
using namespace std;
bool sortbysec(const pair<char,int> &a,const pair<char,int> &b) 
{ 
    return (a.second < b.second); 
} 
struct TrieNode
{
	map<bool,TrieNode> children;
	bool endofword;
};
int main()
{
	string s;
	cin >> s;
	vector <pair<char,int> > count;
	vector <pair<char, int> >::iterator itr; 
	for(int i = 0;i < s.size();i++)
	{
		for(itr = count.begin();itr != count.end();++itr)
		{
			if(itr->first == s[i])
				break;
		}
		if(itr != count.end())
			itr->second = itr->second + 1;
		else
			count.push_back(make_pair(s[i],1));
	}
	sort(count.begin(), count.end(), sortbysec); 
	bool b1 = true;
	cout << b1;
	return 0;
}