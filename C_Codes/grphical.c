#include <graphics.h>
void main()
{
int gd=EGA,gm=EGALO,errorcode;
int maxx,maxy,x,y;
initgraph(&gd,&gm,"C:\\TC\\BGI");
errorcode=graphresult();
if(errorcode!=grOk)
	{
	printf("\nGraphics Initialization Failed!!!");
	exit();
	}
setcolor(GREEN);
maxx=getmaxx();
maxy=getmaxy();
x=maxx/2;
y=maxy/2;
circle(x,y,50);
circle(x,y,75);
outtextxy(x,y,".");
getch();
closegraph();
