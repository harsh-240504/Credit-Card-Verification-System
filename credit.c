#include <cs50.h>
#include<math.h>
#include <stdio.h>

int even_alt_digit_sum(long n);
int odd_alternate_digit_sum(long n);
int main(void)
{
    long number = get_long("Number:");
    int a=odd_alternate_digit_sum(number);
    int b=even_alt_digit_sum(number);
    int c=a+b;
    if(c%10 == 0)
    {
        //AMEX
        if((number/(long)pow(10,16) == 0 && number/(long)pow(10,14)==34) )
        {
            printf("AMEX\n");
        }
        else if(number/(long)pow(10,16) == 0 )
        {
            if(number/(long)pow(10,14)==37)
            {
            printf("AMEX\n");
            }
        }
        //MASTERCARD
        else if(number/(long)pow(10,17) == 0 )
        {
            if(number/(long)pow(10,15)==51 || number/(long)pow(10,15)==52 || number/(long)pow(10,15)==53 || number/(long)pow(10,15)==54 || number/(long)pow(10,15)==55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        //VISA
        else if((number/(long)pow(10,14) == 0 && number/(long)pow(10,12)==4) || (number/(long)pow(10,17)== 0 && number/(long)pow(10,15)==4))
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int odd_alternate_digit_sum(long n)
{
    int lastdigit=0;
    int sum = 0;
    for(int i=0; n>0; i++)
    {
        lastdigit = n%10;
        sum = sum + lastdigit;
        n = n / 100;
    }
    return sum;
}

int even_alt_digit_sum(long n)
{
    int lastdigit=0;
    int lastdigit2=0;
    int lastdigit3=0;
    int sum=0;
    n = n/10;
    for(int i=0;n>0;i++)
    {
        lastdigit=n%10;
        lastdigit2=2*lastdigit;
        if(lastdigit2<10)
        {
            lastdigit3=lastdigit2;
        }
        else
        {
            lastdigit3=lastdigit2/10 + lastdigit2%10;
        }
        sum = sum+lastdigit3;
        n=n/100;
    }
    return sum;
}