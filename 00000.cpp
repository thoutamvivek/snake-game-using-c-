using namespace std ;
#include <stdlib.h> 
#include<conio.h> 
#include<windows.h>
#include<iomanip>
bool gameover ; 
const int height=20 ;
const int width=50 ;
int x,y,fruitx,fruity,score ;
int tailx[100],taily[100] ;
int tail,tough=0 ;
enum direction{ 
STOP=0, LEFT,RIGHT,UP,DOWN 
}; 
direction dir ;
void setup()
{
gameover=false ;
dir=UP ; 
x=width/2 ; 
y=height/2 ; 
fruitx=rand()%width ; 
fruity=rand()%height ;
score=0 ;
tail=0 ;
}
void draw()
{
system("cls") ; 
int i,j,k ; 
for(i=0;i<width+1;i++) 
printf("!"); 
printf("\n");
for(i=0;i<height;i++)
{
for(j=0;j<width;j++)
{
if(j==0||j==width-1) 
printf("!" );
if(i==y&&j==x) 
printf("@" );
else if(i==fruity&&j==fruitx) 
printf("$" );
else
{
bool print=false ; 
for(k=0;k<tail;k++)
{
if(tailx[k]==j&&taily[k]==i) 
{
printf("*" );
print=true ;
}
}
if(!print)
printf(" " );
}
}
printf("\n");
}
for(i=0;i<width+1;i++)
printf("!") ;
printf("\n");
printf("YOUR SCORE =%d",score);
printf("\n");
}
void input()
{
char ch ;
if(!kbhit()) 
{ 
switch(ch)
{
case 'w' : dir=UP ;
 break ;
case 'a' : dir=LEFT ;
 break ;
case 's' : dir=DOWN ;
 break ;
case 'd' : dir=RIGHT ;
 break ;
case 'x' : gameover=true ;
 break ;
}
}
else
{
switch(getch()) 
{
case 'w' : dir=UP ;
 ch='w' ;
 break ;
case 'a' : dir=LEFT ;
 ch='a' ;
 break ;
case 's' : dir=DOWN ;
 ch='s' ;
 break ;
case 'd' : dir=RIGHT ;
 ch='d' ;
 break ;
case 'x' : gameover=true ;
 break ;
}
}
}
void logic()
{
int prevx,prevy,prev2x,prev2y,i ; 
prevx=tailx[0] ;
prevy=taily[0] ;
tailx[0]=x ;
taily[0]=y ;
for(i=1;i<tail;i++) 
{
prev2x=tailx[i] ;
prev2y=ta
ily[i] ;
tailx[i]=prevx ;
taily[i]=prevy ;
prevx=prev2x ;
prevy=prev2y ;
}
switch(dir)
{
case UP : y-- ;
 break ;
case DOWN : y++ ;
 break ;
case LEFT : x-- ;
 break ;
case RIGHT : x++ ;
 break ;
default : break ;
}
for(i=0;i<tail;i++) 
{ 
if(tailx[i]==x&&taily[i]==y)
{
gameover=true ;
system("cls") ;
printf("\n GAME OVER : you hit/bite your tail" );
}
}
if(tough==1)
{
if(x<0||x>width||y<0||y>height) 
{ 
 gameover=true ;
 system("cls") ;
printf("\n GAME OVER : you hit the wall ") ;
}
}
else
{
if(x<0) 
x=width-1 ; 
else if(x>width-2) 
x=0 ;
if(y<0)
y=height-1 ;
else if(y>height)
y=0 ;
}
if(x==fruitx&&y==fruity) 
{ 
score+=1 ; 
fruitx=rand()%width ; 
fruity=rand()%height ;
tail++ ; 
}
}
int main()
{
int n,choice ;
printf("\n\n...................WELCOME TO SNAKE GAME................................");
printf("\n\n...................KEYBOARD INSTRUCTIONS................................" );
printf("\n\n\t\tKEYBOARD KEYS\t\t\tOPERATION");
printf("\n-----------------------------------------------------------------------" );
printf("\n\n\t\tw\t\tuppward movement");
printf("\n\n\t\ts\t\tdownward movement");
printf("\n\n\t\ta\t\tleft movement");
printf("\n\n\t\td\t\tright movement");
printf("\n\n\t\tx\t\tquite/exit game");
printf("\n-----------------------------------------------------------------------" );
printf("\n\n\n # all keys should be in lower case only\n ( as game works on ASCII values )") ;
printf("\n\n\n enter level of game you wan to play ");
printf("\n 1. EASY \n 2. MEDIAM \n 3. HARD ");
printf("\n 4. ULTRA TOUGH (if you even hit the wall you will die )") ;
printf("\n\n please enter choice " );
scanf("&d") ;
if(choice==1)
n=100 ;
else if(choice==2)
n=50 ;
else if(choice==3)
n=10 ;
else
{
tough=1 ;
n=70 ;
}
system("cls") ;
setup() ;
while(!gameover) 
{
draw() ;
input() ;
logic() ;
Sleep(n) ; 
}
printf("\n\n...................................................................");
printf("\n YOUR FINAL SCORE =%d",score) ;
printf("\n...................................................................");
getch() ;
getch() ;
return 0;
}

