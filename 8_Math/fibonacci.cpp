#include<bits/stdc++.h>
using namespace std;
long long pow_two[30];
long long num,two;
void multiply(long long F[2][2], long long M[2][2]); 
  
void power(long long F[2][2], long long n); 
  
/* function that returns nth Fibonacci number */
int fib(long long n) 
{ 
  long long F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
    return 0; 
  power(F, n-1); 
  return F[0][0]%pow_two[two]; 
} 
/* Optimized version of power() in method 4 */
void power(long long F[2][2], long long n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  long long M[2][2] = {{1,1},{1,0}}; 
  
  power(F, n/2); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
void multiply(long long F[2][2], long long M[2][2]) 
{ 
  long long x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  long long y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  long long z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  long long w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x%pow_two[two]; 
  F[0][1] = y%pow_two[two]; 
  F[1][0] = z%pow_two[two]; 
  F[1][1] = w%pow_two[two]; 
} 
  
  
int main () 
{ 
	pow_two[0] = 1;
	for(int i=1;i<=21;i++){
		pow_two[i] = 2*pow_two[i-1];
	}
	while(scanf("%lld %lld",&num,&two) != EOF){
  		printf("%lld\n", fib(num)%pow_two[two]); 
  	}
} 
