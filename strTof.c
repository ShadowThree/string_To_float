#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

float strTof(const char*);

int main(void)
{
    float f = atof("-.35");
    printf("%.2f\n", f);

    char *a = "-.35";
    f = strTof(a);
    printf("%.2f\n", f);

    return 0;
}

float strTof(const char *args)
{
    float result = 0.0;
    unsigned int i, quan = 1;
    unsigned char afterP = 0;
    int sign = 1;

    for(i = 0; args[i] != '\0'; i++)
    {
//        printf("%c\n", args[i]);
        if(i == 0)
        {
            if((args[0] == '-') || (args[0] == '+'))
            {
                continue;
            }
        }
        if(args[i] == '.')
        {
            if(++afterP > 1)
                printf("The str's format is NOT correct! 1\n");

        }
        else if(args[i] <= '9' && args[i] >= '0')
        {
           if(afterP == 0)
           {
               result = result * 10 + args[i] - '0';
           }
           else
           {
               quan *= 10;
               if(quan > UINT_MAX/10)
               {
                   printf("jing du you xian\n");
                   return result;
               }
               result = result + (float)(args[i] - '0') / quan;
           }
        }
        else
        {
            printf("The str's format is NOT correct!\n");
            return 0.0;
        }
    }

    sign = (args[0] == '-')? -1 : 1;
    return (sign * result);
}
