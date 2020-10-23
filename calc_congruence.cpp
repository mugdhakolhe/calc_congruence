#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int calc_congruence(int a[], int b[], int n)
{
	int c = 1;
	int k;
	for(k = 0; k < n; k++){
		c*= b[k];
	}
	int gcd = 0;
	for(k = 0; k < n; k++){
		gcd = GCD(gcd, b[k]);
	}
	for(k = 0; k < n; k++)
	{
		if ((a[k] % 2 == 1) && (b[k] % 2 == 0))
		{
			int j;
			for (j = k + 1; j < n; j++)
				if ((a[j] % 2 == 0) && (b[j] % 2 == 0))
					return -1;
		}
	}
	int lcm = c/gcd;
	for(k = 0; k < lcm; k++)
	{
		int j;
		for (j = 0; j < n; j++)
			if (k % b[j] != a[j])
				break;

		if (j == n)
		{
			return k;
		}
	}

	return -1;
}

int main()
{
	int n,i;
	cin>>n;
	int a[n], b[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	int ret = calc_congruence(a, b, n);

	if (ret == -1)
		cout<<"0";
	else 
		cout<<ret;	
}
