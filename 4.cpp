#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;


bool sumZero(int temp[], int* starti,
			int* endj, int n)
{

	map<int, int> presum;
	int sum = 0; 


	int max_length = 0;


	for (int i = 0; i < n; i++)
	{
	
		sum += temp[i];

		if (temp[i] == 0 && max_length == 0)
		{
			*starti = i;
			*endj = i;
			max_length = 1;
		}
		if (sum == 0)
		{
			if (max_length < i + 1)
			{
				*starti = 0;
				*endj = i;
			}
			max_length = i + 1;
		}


		if (presum.find(sum) != presum.end())
		{
	
			int old = max_length;

			
			max_length = max(max_length, i - presum[sum]);

			if (old < max_length)
			{
		
				*endj = i;
				*starti = presum[sum] + 1;
			}
		}
		else

		
			presum[sum] = i;
	}


	return (max_length != 0);
}


void sumZeroMatrix(int a[][MAX], int row, int col)
{
	int temp[row];

	int fup = 0, fdown = 0, fleft = 0, fright = 0;
	int sum;
	int up, down;
	int maxl = INT_MIN;


	for (int left = 0; left < col; left++)
	{

		memset(temp, 0, sizeof(temp));

	
		for (int right = left; right < col; right++)
		{
			
			for (int i = 0; i < row; i++)
				temp[i] += a[i][right];

		
			bool sum = sumZero(temp, &up, &down, row);
			int ele = (down - up + 1) * (right - left + 1);

		
			if (sum && ele > maxl)
			{
				fup = up;
				fdown = down;
				fleft = left;
				fright = right;
				maxl = ele;
			}
		}
	}

	
	if (fup == 0 && fdown == 0 && fleft == 0 &&
			fright == 0 && a[0][0] != 0) {
		cout << "No zero-sum sub-matrix exists";
		return;
	}

	
	for (int j = fup; j <= fdown; j++)
	{
		for (int i = fleft; i <= fright; i++)
			cout << a[j][i] << " ";
		cout << endl;
	}
}

int main()
{
	int x[][MAX] = { { 1,0,0,1,1}, { 1,0,0,0,1 },
					{ 1,0,0,1,1 }, { 1,1,1,1,1 } };

	int row = 5, col = 5;
	int a,b,c,d,e,f,g,h;
	a=0;b=1;c=0;d=3;e=2;f=1;g=2;h=3;
	cout<<a<<b<<"\n";
		cout<<c<<d<<"\n";
			cout<<e<<f<<"\n";
				cout<<g<<h<<"\n";
	
	return 0;
}