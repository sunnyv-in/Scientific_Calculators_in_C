/*
========================================================
Program Name : Simple X Calculator
Author       : SUNNY
Description  :
    This program is a menu-driven calculator written in C.
    It performs multiple mathematical operations including:

    - Addition, Subtraction, Multiplication, Division
    - Modulus operation
    - Power (Exponentiation)
    - Even & Odd number check
    - Quadratic Equation Solver (ax^2 + bx + c = 0)

    The program uses:
    - Functions (void and non-void)
    - switch-case for menu selection
    - do-while loop for repeated execution
    - Pointers to return multiple values
    - math.h library for mathematical calculations

    The calculator continues to run until the user
    chooses the EXIT option.

========================================================
*/


#include<stdio.h>
#include<math.h>
    
    /* 
   -----------------------------
   FUNCTION: modulus
   TYPE    : void (action-only function)
   PURPOSE : Takes two integers from user
             and prints the remainder (a % b)
   -----------------------------
   */
    void modulus(void)  /* Function declarations */
    {
        int a, b;
        printf("Enter a and b: ");
        scanf("%d %d", &a, &b);

        if (b != 0)
            printf("Result = %d\n", a % b);
        else
            printf("Modulus by zero not allowed\n");
    }

    /* 
   -----------------------------
   FUNCTION: power
   TYPE    : int-returning function
   PURPOSE : Calculates base^exponent
   RETURNS : Result of base raised to exp
   -----------------------------
   */

    int power(int base, int exp)  /* Function declarations */
    {
        int result = 1;

        for(int i=1;i<=exp;i++)
        {
            result = result * base;
        }
        return result;
    }

    /* 
   -----------------------------
   FUNCTION: EO (Even / Odd)
   TYPE    : void (action-only function)
   PURPOSE : Checks whether a number is
             even or odd and prints result
   -----------------------------
    */

    void EO(void)  /* Function declarations */
    {
        int a;
        printf("Enter a number:- ");
        scanf("%d",&a);
        if(a%2==0)
        {
            printf("%d is a EVEN NUMBER!!\n",a);
        }
        else
        {
            printf("%d is a ODD NUMBER!!\n",a);
        }
    }

    /* 
   -----------------------------
   FUNCTION: quadratic
   TYPE    : int-returning function
   PURPOSE : Solves quadratic equation
             ax^2 + bx + c = 0
   RETURNS :
        2 → two real roots
        1 → one real root
        0 → no real roots
   OUTPUT  : Roots are returned using pointers
   -----------------------------
    */

    int quadratic(float a, float b, float c, float *r1, float *r2)  /* Function declarations */
    {
        float D;  // Discriminant
        D = (b*b)-(4*a*c);

        /* Validation: a must not be zero */
        if (a == 0)
        {
            return -1;   // Not a quadratic equation
        }
        
        if (D>0)
        {
            *r1 = (-b+sqrt(D))/(2*a);
            *r2 = (-b-sqrt(D))/(2*a);
            return 2; //two real roots
        }
        else if (D==0)
        {
            *r1 =-b/(2*a);
            *r2 =*r1;
            return 1; // one real root
        }
        else
        {
            return 0; // no real roots
        }
    }

/* 
   -----------------------------
   FUNCTION: main
   TYPE    : Driver function
   PURPOSE : Displays menu, takes user choice,
             and calls appropriate functions
   -----------------------------    
*/
int main()
{
   
   
        int a,b,sum,sub,mul,div,D,base,exp;
        int choice;

        do
        {
            /* Menu Display */
            printf("\n\n---------------------------------------------\n\n");
            printf("==== ***** SIMPLE X CALCULATOR ***** ====\n\n");
            printf("==** CHOOSE THE FOLLOWING OPERATION **==\n");
            printf("1. ADDITIONS\n");
            printf("2. SUBSTRACTION\n");
            printf("3. MULTIPLICATION\n");
            printf("4. DIVIDE\n");
            printf("5. MODULUS\n");
            printf("6. POWER\n");
            printf("7. EVEN & ODD\n");
            printf("8. QUADRATIC Eqn..\n");
            printf("9. EXIT!!!\n\n");

            printf("Now enter your choice:- ");
            scanf("%d",&choice);

            switch (choice)
            {
                case 1:
                {
                printf("\nEnter two number a, b:- ");
                scanf("%d%d",&a,&b);
                printf("%d + %d = %d\n",a,b,a+b);
                break;
                }
                case 2:
                {
                    printf("Enter two number a, b:- ");
                    scanf("%d%d",&a,&b);
                    printf("%d - %d = %d\n",a,b,a-b);
                    break;
                }
                case 3:
                {
                    printf("Enter two number a, b:- ");
                    scanf("%d%d",&a,&b);
                    printf("%d x %d = %d\n",a,b,a*b);
                    break;
                }
                case 4:
                {
                    printf("Enter two number a, b:- ");
                    scanf("%d%d",&a,&b);
                    if (b!=0)
                    {
                        printf("%d/%d = %d\n",a,b,a/b);
                    }
                    else
                    {
                        printf("INVALID AGRUMENT FOR DIVISION\n");
                    }
                    break;
                }
                case 5:
                {
                    modulus();  // Call modulus function
                    break;
                }
                case 6:
                {
                    printf("Enter exponential base and power:- ");
                    scanf("%d%d",&base,&exp);
                    printf("%d^%d = %d\n", base, exp, power(base, exp));
                    break;
                }
                case 7:
                {
                    EO();  // Call even/odd function
                    break;
                }
                case 8:
                {
                    float a,b,c,r1,r2;
                    int res;
                    printf("Enter coefficients a, b, c: ");
                    scanf("%f%f%f",&a,&b,&c);

                    res = quadratic(a,b,c,&r1,&r2);
                    res = quadratic(a, b, c, &r1, &r2);

                    if (res == -1)
                    {
                        printf("Not a quadratic equation (a must not be 0)\n");
                    }
                    else if (res == 2)
                    {
                        printf("%.2fx^2 + %.2fx + %.2f have r1 = %.2f , r2 = %.2f\n",a, b, c, r1, r2);
                    }
                    else if (res == 1)
                    {
                        printf("%.2fx^2 + %.2fx + %.2f have one root r = %.2f\n",a, b, c, r1);
                    }
                    else
                    {
                        printf("%.2fx^2 + %.2fx + %.2f have imaginary roots\n",a, b, c);
                    }
                
                }
                default:
                {
                    printf("Invalid choice\n");
                }

                
            }

        } while (choice != 9);
        printf("Thanks for Using Calculator\n\n");
        printf("Developed by verma_Sunny!!!\n");

    return 0; 

}   
    


