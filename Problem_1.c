/* Subject: 
** If we list all the natural numbers below 10 that are multiples of 3 or 5,
** we get 3, 5, 6 and 9. The sum of these multiples is 23.
**
** Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

/* My solution */

int suma(int max)
{
	int a = 1;
	int res = 0;
	while (a < max)
	{
		if (a%3 == 0 || a%5 == 0)
		{
			res += a;
		}
		a++;
	}
	return (res);	
}

int main(void)
{
	int num =  suma(1000);
	printf("El resultado es: %d\n", num);
	return (0);	
}

/* more efficient solution 

** To get a more efficient solution you could also calculate the sum of the numbers less
** than1000 that are divisible by 3, plus the sum of the numbers less than1000 that are divisible
** by 5. But as you have summed numbers divisible by 15 twice you would have to subtract the
** sum of the numbers divisible by 15.
**
** Let’s look at the details of our function and take as example n=3.
** We would have to add:
** 3+6+9+12+......+999=3*(1+2+3+4+...+333)
** For n=5 we would get:
** 5+10+15+...+995=5*(1+2+....+199)
** Now note that 199=995/5 but also 999/5 rounded down to the nearest integer.
** If we now also note that 1+2+3+...+p=½*p*(p+1) our program becomes:
** 		target=999
** 		Function SumDivisibleBy(n)
** 			p=target div n
** 			return n*(p*(p+1)) div 2
**		EndFunction
**		Output SumDivisibleBy(3)+SumDivisibleBy(5)-SumDivisibleBy(15)
**
** See Partial sums: https://en.wikipedia.org/wiki/1_%2B_2_%2B_3_%2B_4_%2B_%E2%8B%AF
*/

// int sumDivisibleBy(int n)
// {
// 	int target = 999;
// 	int res;

// 	res = target/n;
// 	return ((n*(res*(res+1)))/2);
// }

// int main(void)
// {
// 	int num = sumDivisibleBy(3) + sumDivisibleBy(5) - sumDivisibleBy(15);
// 	printf("Answer is: %d\n", num);
// 	return (0);
// }