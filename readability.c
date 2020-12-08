#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    float c =0, w =1, s=0;
    string n = get_string("text :");
    
    for (int i =0;i<strlen(n); i++)
    {
        if(isalpha(n[i]))  {c++; }
        if(isspace(n[i]))  {w++; }
        if(n[i]== '?'|| n[i]== '.'|| n[i]== '!') {s++; }
    }
    float C = (c/w)*100.0;
    float S = (s/w)*100.0;
    float index = 0.0588 * C - 0.296 * S - 15.8;
    int f = round(index);
    if (f >= 16) {printf("Grade 16+\n"); }
    else if (f < 1) {printf("Before Grade 1\n"); }
    else  printf("Grade %i\n",f);
}