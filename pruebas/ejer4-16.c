#include <stdio.h>

int main()
{
    char var1 = 1, var2 = 1 << (sizeof(var2) * 8 - 1), res = 0, temp = 0; // var1 : ...00001, var2: 1000...
    int iteraciones = 20; 


    for (size_t i = 0; i < iteraciones; i++)
    {
        
        var1 <<= i;
        var2 >>= i;
        if (i >= sizeof(res) * 8)
        {
            temp = var1; // Intercambio de lado los 1
            var1 = var2;
            var2 = temp;
        }
        res = var1 | var2;

        for (size_t i = 0; i < (sizeof(res) * 8); i++)
        {
            if ((res >> i) & 1)
            {
                printf("1");
            } else {
                printf("0");
            }
            
        }
        printf("\n");
        

    }
    
    
    return 0;
}
