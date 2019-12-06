#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UPPPER 100
#define LOWER 10

typedef int (*Conditional) (int a, int b);

/* IMPLEMENT ME: Declare your functions here */
int add (int a, int b);
int subtract (int a, int b);
int multiply (int a, int b);
int divide (int a, int b);

int main (void)
{
	// Conditional functions kept in array
	Conditional condition_functions[5];
	char option[20];
	
	condition_functions[0] = &add;
	condition_functions[1] = &subtract;
	condition_functions[2] = &multiply;
	condition_functions[3] = &divide;
	
	
	
	while(1){
    // Generate two random numbers 
    srand(time(NULL));
    int num1 = rand()%(UPPPER - LOWER + 1) + LOWER;
    int num2 = rand()%(UPPPER - LOWER + 1) + LOWER;
    
		printf("First number is : %d and second number is : %d. Please select the operation to perform"
					 "(0 : Add, 1 : Subtract, 2 : Multiply, 3: Divide,  4 : Exit):", num1, num2);
		scanf("%s", option);
		
		if (atoi(option) == 4){
			printf("Bye now.\n");
			break;
		}
		
		// Call the required function based on user input
		int ans = (*condition_functions[atoi(option)])(num1, num2);
		printf("The result is: %d\n", ans);
	}
	return 0;
}

/* IMPLEMENT ME: Define your functions here */
int add (int a, int b) { printf ("Adding the numbers\n"); return a + b; }

int subtract (int a, int b) { printf ("Subtracting the numbers\n"); return a - b; }

int multiply (int a, int b) { printf ("Multiplying the numbers\n"); return a * b; }

int divide (int a, int b) { printf ("Dividing the numbers\n"); return a / b; }