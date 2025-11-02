#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define CLEAR "cls"
#define WIDTH 60
#define HEIGHT 20
#define STARS 100


typedef struct{
    int x,y;
    char bright;
}Star;

int main()
{
 Star stars[100];
 srand(time(0));
 for(int i=0;i<STARS;i++)
 {
    stars[i].x=rand()%WIDTH;
    stars[i].y=rand()%HEIGHT;
    stars[i].bright=(rand()%3)?'.':'*';
 }

 while(1)
  {
    system(CLEAR);
    char sky[HEIGHT][WIDTH];
    for(int i=0;i<HEIGHT;i++)
    {
        for(int j=0;j<WIDTH;j++)
        {
            sky[i][j]=' ';    
        }
        sky[i][WIDTH]='\0';
    }
    for(int i=0;i<STARS;i++)
    {
        if(rand()%5==0)
        {
            stars[i].bright=(stars[i].bright=='.')?'*':'.';
            sky[stars[i].y][stars[i].x]=stars[i].bright;
        }
    }
    for(int i=0;i<HEIGHT;i++)
    {
        printf("%s\n",sky[i]);
    }
    printf("ctrl+c for exit");
     Sleep(200);
  }
}