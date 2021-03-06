/* Subject: 
** Find the sum of all the even-valued terms in the Fibonacci sequence
** which do not exceed four million.
*/

/* My solution */

#include <stdio.h>

int even_fibonacci(int max)
{
	int n1 = 1; 
    int n2 = 2; 
    int temp;
    int res = 2;

//displays the first two terms, in this case 1 and 2
    printf("Whole Fibonacci Series: %d, %d, ", n1, n2);
    temp = n1 + n2;
    while (temp < max) 
    {
		printf("%d, ", temp);
	    n1 = n2;
	    n2 = temp;
	    temp = n1 + n2;
	    if(temp%2 == 0)
	    	res += temp;
    }
    printf("\nAnswer is: %d\n", res);
    return (res);
}

int main(void) 
{
	even_fibonacci(4000000);
    return (0);
}


/* Other solution */

// int main (void)
// {
//     int max = 4000000;
//     int res = 0;
//     int a = 1;
//     int b = 1;
//     int temp = 0;
//     while (b < max)
//     {
//         if (b%2 == 0)
//             res += b;
//         temp = a + b;
//         a = b;
//         b = temp;
//     }
//     printf("La respuesta es: %d\n", res);
//     return (0);
// }

/*
** Now let us see if we can get rid of the testing for even values.
** Here is the beginning of the Fibonacci sequence with even numbers in c:
** 1 1 2 3 5 8 13  21  34  55  89  144 ...
** a b c a b c a   b   c   a   b   c
** It is easy to prove that every third Fibonacci number is even.
** Here, only every third number is added
*/

// int main (void)
// {
//     int max = 4000000;
//     int res = 0;
//     int a = 1;
//     int b = 1;
//     int c = a + b;
//     while (c < max)
//     {
//         res += c;
//         a = b + c;
//         b = c + a;
//         c = a + b;
//     }
//     printf("The answer is: %d\n", res);
//     return (0);
// }