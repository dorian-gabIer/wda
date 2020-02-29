#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[102];
    char ns[205];
    int i,k;
    int java = 0;
    int cpp = 0;
    int flag = 0;

    for(i=0;i<102;i++)
        s[i] = '\0';
    while(scanf("%s",s)!=EOF)
    {
        for(i=0;i<205;i++)
        ns[i] = '\0';

        k=0;
        java = 0;
        cpp = 0;
        flag = 0;
        if(s[0]== '_' || (s[0]>=65 && s[0]<=90) || s[strlen(s)-1] == '_')
            flag = 1;
        for(i=0;i<strlen(s) && !flag;i++)
        {
            if(s[i] == '_')
            cpp = 1;
            if(s[i]>=65 && s[i]<=90)
            java = 1;

            if((s[i] == '_') && java) 
                flag = 1;
            else if((s[i]>=65 && s[i]<=90) && cpp) 
                flag = 1;
            else if(s[i] == '_') 
            {
                i++;
                if(s[i]!='\0' && (s[i]>=97 && s[i]<=122))
                    ns[k++] = s[i]-32;
                else if(s[i]!='\0' || s[i]=='\0')
                    flag = 1;
            }
            else if(s[i]>=65 && s[i]<=90)
            {
                ns[k++] = '_';
                ns[k++] = s[i] + 32;
            }
            else
                ns[k++] = s[i];

            if(flag)
            break;
        }
        if(flag)
            printf("Error!\n");
        else
            printf("%s\n",ns);


        for(i=0;i<102;i++)
            s[i] = '\0';
    }
    return 0;
}
