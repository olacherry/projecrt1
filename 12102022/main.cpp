#include <iostream>
//Greatest common divisor
int gcd(int a, int b)
{

	while (a!=b)
	{
		if (a>b)
		{
			a = a-b;
		}
		else 
		{
			b = b-a;
		}
	}
	return a;
}

// наименьшее общее кратное
int lcm(int a, int b)
{
	int max = a;
	int div =1;
	if (b < max)
	{
		max = b;
	}
	for (int i = 2;; i++ )
	{
		if (i % a == 0 && i % b == 0)
		
		{
			div = i;
			break;
		}
	}
	return div;
}

int a[] = {
	4,
	3,
	2,
	1,
	1
};

float average_a()
{
	//возвращает размер переменной в бйтах
	const int el_count = sizeof(a) / sizeof(int);
	
	float avg =0.f;
	
	for (int i =0; i<el_count; i++)
	{
		avg += static_cast<float>(a[i]) / static_cast<float>(el_count);
	}
	return avg;
}

int factorials[11];
void fill_factorials()
{
	const int el_count = sizeof(factorials) / sizeof(int);
	factorials[0] =1;
	
	for (int i =1; i< el_count; i++)
	{
		factorials[i] = factorials[i-1] * i;
	}
}
int factorial(int n)
{
	return factorials[n];
}
int bin(int n, int k)
{
	return factorial(n)/factorial(n-k)/factorial(k);
}

int bin_sum (int n) 
{
	int sum =0;
	for (int i =0; i<=n; i++)
	{
		sum += bin(n,i);
		
	}
	return sum;
}

int main()
{
	int a;
	int m;
	int n;
	std::cin >> m;
	std::cin >> n;
	std::cout << "GCD("<< m <<"," << n << ") = " << gcd(m,n) << std::endl;
	std::cout << "LCM("<< m <<"," << n << ") = " << lcm(m,n) << std::endl;
	std::cout << "AVG = "<< average_a() << std :: endl;
	
	fill_factorials();
	std::cout << "SUM BIN(10,k) = "<< bin_sum(10)<< std::endl;
	
	std::cin >> a;
	
	
	return 0;
	
}