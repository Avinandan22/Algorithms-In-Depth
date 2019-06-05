#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void traverse(vector <int> adj[],int path,int *count,int * p,int start)
{
	int len = adj[start].size();
	for(int i = 0;i < len;i++)
	{
		if(*count == path)
			return;
		if(*(p + adj[start][i]) == 0)
		{
			*(p + adj[start][i]) = 1;
			*count = *count + 1;
			traverse(adj,path,count,p,adj[start][i]);
		}
	}
	return;
}
int main()
{
	int row,col,fill,empty = 0;
	cin >> row >> col >> fill;
	int mat[row][col];
	char temp;
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			cin >> temp;
			mat[i][j] = (temp == '.');
			empty += mat[i][j];
		}
	}
	vector<int> adj[row * col];
	for (int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			if(mat[i][j])
			{
				if((i - 1) >= 0 && mat[i - 1][j])
					adj[col * i + j].push_back(col * (i - 1) + j );
				if(i + 1 < row && mat[i + 1][j])
					adj[col * i + j].push_back(col * (i + 1) + j);
				if(j - 1 >=0 && mat[i][j - 1])
					adj[col * i + j].push_back(col * i + j - 1);
				if(j + 1 < col&& mat[i][j + 1])
					adj[col * i + j].push_back(col * i + j + 1);

			}
		}
	}
	int start;
	int *count = (int *)malloc(sizeof(int));
	*count = 0;
	int path = empty - fill;
	int visited[row * col] = {0};
	int *p = visited;
	for(int i = 0;i < row * col;i++)
	{
		if(!adj[i].empty())
		{
			start = i;
			break;
		}
	}
	traverse(adj,path,count,visited,start);
	for(int i = 0;i < row;i++)
	{
		for(int j = 0;j < col;j++)
		{
			if(mat[i][j] == 0)
				cout << '#';
			else if(visited[col * i + j])
				cout << '.';
			else
				cout << 'X';
		}
		cout << endl;
	}
	
	return 0;
}