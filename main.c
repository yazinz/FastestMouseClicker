#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <winuser.h>
void open_browser(char *url) /* a simple function for oppening the browser in Windows! */
{
    printf("enter the site you want to open\n");
    scanf("%s",url);
   ShellExecute(NULL, "open", url, NULL, NULL, SW_SHOWNORMAL);
   system("exit");
}

void mouse_movement(int x,int y) /* mouse mover */
{    
    SetCursorPos(x,y);
}
void mouse_clicker()    /* click the rightbutton */
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
    Sleep(100);
    mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
}
void currentpos() /* show current mouse position for debugging */
{
    POINT xypos;
    GetCursorPos(&xypos);
    printf("the mouse position is\nX:%i\nY:%i\n",xypos.x,xypos.y);
}

int main(int argc,char * argv)
{
    char *url;
    int posx1,posy1;
    int posx2,posy2;
    posx1=545;
    posy1=404;
    posx2=545;
    posy2=404;
    start:
    printf("\033[0;31m");
    printf("Here are the choices:\n1- Type 'o' to open the browser\n2- Type 'c' to see the current postion\n3- Type 's' to start the mouse clicker\n");
    printf("\033[0m");
    char input=getch();
    while(1)
  {
    if(input == 'o'||input == 'O')
    {
    open_browser(&url);
    goto start;
    }
  else if(input == 'c' || input == 'C')
    {
    currentpos();
    goto start;
    }
  else if(input == 's' || input == 'S')
   {
    while(1)
    {
        mouse_movement(posx1,posy1);
        Sleep(1000);
        mouse_clicker();
        Sleep(5000);
        mouse_movement(posx2,posy2);
        Sleep(1000);
        mouse_clicker();
    }
   }
   }
 
    return 0;
}
