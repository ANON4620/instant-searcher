#include <string.h>
#include <ncurses.h>

struct Item
{
	char name[20];
};

int main()
{
        struct Item item[10];
	char search[20], temp[20];
        char ch;
        int len = 0;
       
	initscr();

        addstr("Enter 10 items:\n");
        for(int i = 0; i < 10; i++)
                scanw("%s", item[i].name);

        while(1)
        {
	    erase();
	    printw("Search: %s\n", search);
            for(int i = 0; i < 10; i++)
            {
                strncpy(temp, item[i].name, len);
                temp[len] = '\0';
                if(strcmp(search, temp) == 0)
                    printw("%s\n", item[i].name);
            }

	    move(0, 8 + len);
            ch = getch();
	    addch('\n');

            if(ch == '\n')
                break;
            
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

	    refresh();
        }

	endwin();

        return 0;
}
