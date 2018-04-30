#include<iostream>
using namespace std;
int numOfDiviso(int num)
{
	int temp = 0;
	int i;
	for (i = 1; i*i < num; ++i)
	{
		if (num%i == 0)
			temp += 2;
	}
	if (i*i == num) temp++;
	return temp;
}
int main()
{
	int n; int p;
	while (cin >> n)
	{
		for (int i = 0; i<n; i++)
		{
			cin >> p;
			cout << numOfDiviso(p) << endl;
		}
	}
	return 0;
}
