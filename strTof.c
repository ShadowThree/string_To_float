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
        if(i == 0)				// 只有第一个字符可能是符号位
        {
            if((args[0] == '-') || (args[0] == '+')) 		// 如果第一个字符是符号位，跳过
            {
                continue;
            }
        }
        if(args[i] == '.') 			// 对于每一个字符，先判断是否为小数点
        {
            if(++afterP > 1)      // 如果出现多个小数点，说明数据错误
                printf("The str's format is NOT correct! 1\n");

        }
        else if(args[i] <= '9' && args[i] >= '0')		// 如果不是小数点，再判断是否为数字
        {
           if(afterP == 0)			// 小数点之前的数处理方法
           {
               result = result * 10 + args[i] - '0';
           }
           else 					// 小数点之后的数处理方法
           {
               quan *= 10;
               if(quan > UINT_MAX/10) 		// 只是为了quan不超过unsigned int数据类型的范围
               {
                   printf("jing du you xian\n");
                   return result;
               }
               result = result + (float)(args[i] - '0') / quan;
           }
        }
        else 			// 如果一个字符不是数字也不是小数点，说明数据格式错误（第一个字符可能是符号位的情况前面已经判断过了）
        {
            printf("The str's format is NOT correct!\n");
            return 0.0;
        }
    }

    sign = (args[0] == '-')? -1 : 1; 		// 根据符号位判断结果的符号
    return (sign * result);
}
