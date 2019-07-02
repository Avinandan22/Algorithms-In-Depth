#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void constructTree(int * tree, int * open, int * close, int low, int high, int pos)
{
	if(low == high)
	{
		tree[pos] = 0;
	}
	else
	{
		int mid = (low + high) / 2;
		constructTree(tree, open, close, low, mid, 2 * pos + 1);
		constructTree(tree, open, close, mid + 1, high, 2 * pos + 2);
		int left,right,min;
		if(low == 0)
			left = open[mid];
		else
			left = open[mid] - open[low - 1];
		right = close[high] - close[mid];
		min = ((-tree[2 * pos + 1] + left) < (-tree[2 * pos + 2]  + right) ? (-tree[2 * pos + 1] + left) : (-tree[2 * pos + 2]  + right));
		tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2] + min;
	}
}
int f(int * tree, int * open, int * close, int sta, int fin, int high, int low, int pos)
{
	if(sta > high || fin < low)
		return -1;
	else if(sta == fin)
		return 0;
	else if(sta == low && fin == high)
		return tree[pos];
	
	int mid = (high + low) / 2;
	if(sta <= mid && fin >= mid)
	{
		int A = f(tree,open,close,sta,mid,mid ,low,2 * pos + 1);
		int B = f(tree,open,close,mid + 1,fin,high, mid + 1, 2 * pos + 2);
		int left,right,min;
		if(sta == 0)
			left = open[mid];
		else
			left = open[mid] - open[sta - 1];
		right = close[fin] - close[mid];
		min = ((left - A) < (right - B) ? (left - A) : (right - B));
		int val;
		if(A == -1)
			val =  B;
		else if(B == -1)
			val = A;
		else val = (A + B + min);
		//cout << val << " " << sta << " " << fin << endl;
		return val;
	}
	else if(sta < mid)
	{
		return f(tree,open,close,sta,fin,mid,low,2 * pos + 1);
	}
	else if(sta > mid)
	{
		return f(tree,open,close,sta,fin,high,mid + 1,2 * pos + 2);
	}	
}
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int open[n];
	int close[n];
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(' && i != 0)
			open[i] = open[i - 1] + 1,close[i] = close[i - 1];
		else if(s[i] == '(' && i == 0)
			open[i] = 1,close[i] = 0;
		else if(s[i] == ')' && i != 0)
			close[i] = close[i - 1] + 1,open[i] = open[i - 1];
		else if(s[i] == ')' && i == 0)
			close[i] == 1,open[i] = 0;
	}
	int len = 2 * pow(2,ceil(log2(n))) - 1;
	int tree[len] = {0};
	constructTree(tree,open,close,0,n - 1, 0);
	//cout << f(tree,open,close,1,2,n - 1,0,0) << endl;
	int q;
	cin >> q;
	int x,y;
	for(int i = 0;i < q;i++)
	{
		cin >> x >> y;
		cout << 2 * f(tree,open,close,x - 1,y - 1,n - 1,0,0) << endl;
	}
	return 0;
}