#include <stdio.h>
#include <cs50.h>
#include <math.h>


float get_po_float(void);
int main(void)
{
    
    float c = get_po_float();int s =0;
    int x =round(c*100);
 while (x>=25){x=x-25; s++;}
 while (x>=10){x=x-10;s++;}
 while (x>=5){x=x-5;s++;}
 while (x>=1){x=x-1;s++;}
 printf("%i\n",s);
}


float get_po_float(void)
{
    float m ;
    do
    {
      m= get_float("Enter Cash:");  
    }
    while(m<0);
    return m;
}





    