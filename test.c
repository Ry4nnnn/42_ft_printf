// #include <stdarg.h>
// #include <stdio.h>

// int	addNumbers(int n, ...)
// {
// 	va_list mars;
// 	int sum = 0;
// 	int i = 0;

// 	va_start(mars, n);
// 	while (i < n)
// 	{
// 		sum += va_arg(mars, int);
// 		i++;
// 	}
// 	va_end(mars);
// 	return (sum);
// }

// int main(void)
// {
// 	printf("%d\n", addNumbers(5, 2, 2, 2, 2, 2, 2));
// 	printf("a b c d e f asda %d\n asd %d ada", 5, "ädf");
// }

// C program for the above approach
 
#include <stdarg.h>
#include <stdio.h>
 
// Variadic function to add numbers
int AddNumbers(int n, ...)
{
    int Sum = 0;
 
    // Declaring pointer to the
    // argument list
    va_list ptr;
 
    // Initializing argument to the
    // list pointer
    va_start(ptr, n);
 
    for (int i = 0; i < n; i++)
 
        // Accessing current variable
        // and pointing to next one
        Sum += va_arg(ptr, int);
 
    // Ending argument list traversal
    va_end(ptr);
 
    return Sum;
}
 
// Driver Code
int main()
{
    printf("\n\n Variadic functions: \n");
 
    // Variable number of arguments
    printf("\n 1 + 2 = %d ",
           AddNumbers(2, 1, 2));
 
    printf("\n 3 + 4 + 5 = %d ",
           AddNumbers(3, 3, 4, 5));
 
    printf("\n 6 + 7 + 8 + 9 = %d ",
           AddNumbers(4, 6, 7, 8, 9));
 
    printf("\n");
 
    return 0;
}