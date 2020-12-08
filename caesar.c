#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
       
    }
    
    int k = atoi(argv[1]);
    
    string t = get_string("plaintext: ");
    printf("ciphertext: ");
    
    int c;
    
    for (int n = 0; n < strlen(t); n++)
    {
        if (isupper(t[n]))
        {
            c = ((t[n] - 65) + k) % 26;
            printf("%c", c + 65);
        }
        else if (islower(t[n]))
        {
            c = ((t[n] - 97) + k) % 26;
            printf("%c", c + 97);
        }
        else
        {
            printf("%c", t[n]);
        }
    }
    printf("\n");
    return 0;
}