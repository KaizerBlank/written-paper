#include<stdio.h>
int main()
{
    long int cpf;
    scanf("%ld", &cpf); // gets the cpf from the user
    char digitos[10];
    sprintf(digitos, "%09ld", cpf); // save each cpf number in a char
    int digito1 = digitos[0] - '0';
    int digito2 = digitos[1] - '0';
    int digito3 = digitos[2] - '0';
    int digito4 = digitos[3] - '0';
    int digito5 = digitos[4] - '0';
    int digito6 = digitos[5] - '0';
    int digito7 = digitos[6] - '0';
    int digito8 = digitos[7] - '0';
    int digito9 = digitos[8] - '0';
    long int soma = (digito9 * 2) + (digito8 * 3) + (digito7 * 4) + (digito6 * 5) + (digito5 * 6) + (digito4 * 7) + (digito3 * 8) + (digito2 * 9) + (digito1 * 10); // int soma with cpf calculation criteria
    int verificador1;
    if (soma % 11 == 0 || soma % 11 == 1) // if soma is divisible by 11 or the remainder is 1, the first check digit is 0
    {
        verificador1 = 0;
    }
    else // else the first check digit will be 11 minus the remainder of soma divided by 11
    {
        verificador1 = 11 - (soma % 11); 
    }
    int verificador2;
    verificador2 = (verificador1 * 2) + (digito9 * 3) + (digito8 * 4) + (digito7 * 5) + (digito6 * 6) + (digito5 * 7) + (digito4 * 8) + (digito3 * 9) + (digito2 * 10) + (digito1 * 11); // do the soma based on cpf calculation criteria
    if (verificador2 % 11 == 0 || verificador2 % 11 == 1) // if verificador 2 is divisible by 11 or the remainder is 1, the second check digit is 0
    {
        verificador2 = 0;
    }
    else // else the second check digit will be 11 minus the remainder of soma divided by 11
    {
        verificador2 = 11 - (verificador2 % 11); 
    }
    printf("%d%d\n", verificador1, verificador2); // prints the two check digits on the display
}
