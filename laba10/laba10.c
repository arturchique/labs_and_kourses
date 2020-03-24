#include <stdio.h>

long long mod(long long a,int b)

{

long long c = a/b;

if (a < 0 && b < 0 && a%b!=0)

{

c += 1;

}

if (a < 0 && b > 0)

{

c -= 1;

}

return a - c * b;

}

int main()

{

long long a,b;

int c;

long long d = 0;

scanf("%lli %lli %d",&a,&b,&c);

d = mod(a*b,c);

printf("%lli\n",d);

}