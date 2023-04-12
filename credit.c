#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long a = 100;
    long b = 10;
    int sum1 = 0; //Suma prve grupe
    int sum2 = 0; //Suma druge grupe
    long x, x1, x2; // x = jednocifren broj; x1 = desetice; x2 = jedinica
    long i = 1; //Duzina = broj karaktera u unosu

    //Unos broja kartice
    long input = get_long("Number: ");

    //Suma prve grupe brojeva
    while (input % b < input)
    {
        //Izdvajanje broja pocevsi od pretposlednjeg prema prvom
        x = input % a;
        x = x / b;
        a *= 100;
        b *= 100;

        //Mnozenje izdvojeng broja sa 2
        x *= 2;

        //U koliko je broj dvocifren, radvojiti u 2 broja (npr. 18 u 1 i 8). Jednocifreni brojevi ostatju isti
        if (x >= 10)
        {
            x2 = x % 10;
            x1 = x / 10;
            x = 0;
        }
        else
        {
            x1 = x2 = 0;
        }

        //Sabiranje razdvojenih dvocifrenih i jednocifrenih brojeva
        sum1 += x + x1 + x2;
    }

    //Suma druge grupe brojeva
    a = 10;
    b = 1;
    while (input % b < input)
    {
        //Izdvajanje brojeva pocevsi od poslednjeg prema prvom
        x = input % a;
        x /= b;
        a *= 100;
        b *= 100;

        //Suma izdvojenih brojeva
        sum2 += x;
    }

    //Sabiranje sumi dve grupe brojeva
    int sum3 = sum1 + sum2;

    //Broj karaktera u unosu prikazanim preko duzine broja i
    while (input % i < input)
    {
        i *= 10;
    }

    //Provjeravanje ispravnosti kartice
    if (sum3 % 10 == 0)
    {
        if ((input / (i / 100) == 34 || input / (i / 100) == 37) && i == 1000000000000000)
        {
            printf("AMEX\n");
        }
        else if ((input / (i / 100) == 51 || input / (i / 100) == 52 || input / (i / 100) == 53 || input / (i / 100) == 54
                  || input / (i / 100) == 55) && i == 10000000000000000)
        {
            printf("MASTERCARD\n");
        }
        else if ((input / (i / 10) == 4) && (i >= 10000000000000 &&  i <= 10000000000000000))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
