#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
        char medicine[10][20];
        char search[20], temp[20];
        char ch;
        int len = 0;
        
        puts("Enter 10 medicine names:");
        for(int i = 0; i < 10; i++)
                scanf("%s", &(medicine[i]));   
        getch(); // flushing keyboard buffer
        
        while(1)
        {
            printf("Search: %s", search);
            ch = getch();
            if(ch == '\n')
                break;
            clrscr();
            if(ch == 127)
            {
                if(len > 0)
                {
                    len--;
                    search[len] = '\0';
                }
            }
            else
            {
                search[len] = ch;
                len++;
                search[len] = '\0';
            }
            
            for(int i = 0; i < 10; i++)
            {
                strncpy(temp, &(medicine[i]), len);
                temp[len] = '\0';
                if(strcmp(search, temp) == 0)
                    puts(&(medicine[i]));
            }
        }

        return 0;
}
