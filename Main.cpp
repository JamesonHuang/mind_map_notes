
/*********************************************************************
	@ Title:			高效素数+欧几里得+随机数	

	@ Description:		1、测试生成随机数

						2、欧几里得算法

						3、判断素数

						4、输出程序运行时间
	@ Conclusion:			

	@ Author:			rh_Jameson

	@ Date:				2014/08/09
**********************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

#define MAX 10000
//-----------------------1、测试生成随机数---------------------------//
//测试伪随机数，伪随机：每次运行都是一样的
void testRand()
{
	for(int i = 0; i < 10; ++i )
	{
		cout << rand() << endl;					//生成10个不限定范围的随机数
	}
	for( int j = 0; j < 10; ++j )
	{
		cout <<( rand() % 100 ) << endl;			//生成10个100以内的随机数
	}

}
//测试真随机数
void TestSRand()
{
	cout << "真随机数：" << endl;
	srand( (int)time(NULL) );
	for( int k = 0; k < 10; ++k)
	{		
		cout << ( rand() % 100 ) << endl;			
	}
}

//------------------------2、欧几里得算法----------------------------//
//又称辗转相除法，求两数的最大公约数
int gcdByRecursion( int x, int y )
{

	//递归法
	if( y == 0)								//除数为0的话，返回被除数
	{
		return x;
	}
	if( x < y )								//如果x<y,交换x，y的值
	{
		int tmp = x;
		x = y;
		y = tmp;
	}
	
	/*if( x % y == 0 )						//方式一
	{
		return y;
	}
	else
	{
		return gcdByRecursion( y, x % y );
	}*/
	return x % y == 0 ? y : gcdByRecursion( y, x % y ); 

	/*if( y == 0 )							//方式二							
	{
		return x;
	}
	else
	{
		return gcdByRecursion(y, (x % y) ) ;
	}*/
	//return y == 0 ? x : gcdByRecursion( y, x % y );
}
int gcd(int x,int y)
{
	int tmp = 0;
	if(x < y)
	{
		tmp = x;
		x = y;
		y = tmp;
	}

	if( y == 0 )
	{
		return x;
	}	
	
	while( x % y != 0 )
	{
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return y;
}
void testGcd()
{
	int res = gcd(10,20);
	cout << res << endl;
}

//------------------------3、判断素数--------------------------------//
bool isPrime(int n)
{
	if( n < 2 )			//小于2的数，不是素数
	{
		return 0;
	}

	if( n == 2)			//2为素数
	{
		return 1;
	}
	
	for(int i = 3; (i * i) <= n; i += 2 )		//1、偶数除2以外，均非素数
	{											//2、素数除以任何偶数，均不能整除，so i += 2
		if( n % i == 0 )
		{
			return 0;
		}
	}
	return 1;
}
//简单的筛选法
void isPrimeByEra(const int n)
{
	int flag =0;
	bool isPrime[MAX];
	isPrime[0] = false;
	isPrime[1] = false;	

	for(int i = 2; i < n; i++ )
	{
		isPrime[i] = true;
	}

	for(int j = 2; j < n; j++)
	{
		if( isPrime[j] )
		{
			for(int k = j + j; k < n; k += j)
			{
				isPrime[k] = false;
			}
		}
	}
	while( flag < n )
	{
		if( isPrime[flag] == true )
		{
			cout << flag << "\t";
		}
		
		flag++;
	}
	
}

//最优筛选法，看不懂
#define MAX 1000 
bool isprime[MAX]; 
int p[MAX]; 
void primeHigh(int n) 
{   
	memset(isprime, 0, sizeof(isprime));   
	memset(p, 0, sizeof(p));  
	int np = 0, i, j;  
	for(i = 2; i <= n; i++)  
	{    
		if(!isprime[i]) p[np++] = i;    
		for(j = 0; j < np && p[j]*i <= n; j++)   
		{     
			isprime[p[j]*i] = 1;    
			if(i % p[j] == 0) 
				break;   
		}  
	} 
}    

int IsPrimeHigh(int n) 
{   
	if(n < 2) 
		return 0;	
	for(int i = 0; p[i]*p[i]<= n; i++)  
		if(n%p[i] == 0)    
			return 0;  
	return 1; 
} 




//-------------4、输出程序运行时间-----------------//
int recursion(int x)
{
	
	if( x == 1 )
	{
		return 1;
	}
	else
	{
		return x + recursion( x - 1 );
	}
}
void testRecursionTime()
{
	double res = recursion( 60 );	
	cout << res << endl;
	
	cout << clock() / CLOCKS_PER_SEC << endl;

}
//-------------2、实现每输出10个元素，就换行，再输出-----------------//
//-------------2、实现每输出10个元素，就换行，再输出-----------------//
//-------------2、实现每输出10个元素，就换行，再输出-----------------//


int main()
{
	//testRand();
	//TestSRand();
	//testGcd();
	//cout << isPrimer( 99 ) << endl;
	//primeHigh(19);
	//cout << IsPrimeHigh( 19 ) << endl;
	
	//testRecursionTime();
	isPrimeByEra(100);
	return 0;
}