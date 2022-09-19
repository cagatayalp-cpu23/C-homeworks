#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int Board[5][5]={{-10,5,30,-20,40},{20,0,10,5,50},{5,50,-40,15,60},{10,-10,0,-5,70},{15,20,30,-20,0}};
	int N=5,startx=1,starty=1,endx=4,endy=4,controlx,controly,minpath=0;
	int x=startx;
	int y=starty;
	while((x!=endx||y!=endy))
	{
		if(endx-x>0)
		{
			printf("1");
			x++;
			controlx=1;
		}
		else if(endx-x<0)
		{
			printf("2");
			x--;
			controlx=2;
		}
		else if(endy-y>0)
		{
			printf("4");
			y++;
			controly=4;
		}
		else if(endy-y<0)
		{
			printf("3");
			y--;
			controly=3;
		}
		
	}
	printf("\n");
	x=startx;
	y=starty;
	while(x!=endx||y!=endy)
	{
		if(controlx==1&&controly==4)
		{
			if(Board[x+1][y]>Board[x][y+1])
			{
				minpath=minpath+Board[x][y+1];
				printf("min path:%d\n",minpath);
				y++;
				printf("1\n");
			}
			else
			{
				minpath=minpath+Board[x+1][y];
				printf("min path:%d\n",minpath);
				x++;
				printf("4\n");
			}
			
		}
		else if(controlx==1&&controly==3)
		{
			if(Board[x+1][y]>Board[x][y-1])
			{
				minpath=minpath+Board[x][y-1];
				printf("min path:%d\n",minpath);
				y--;
				printf("2\n");
			}
			else
			{
				minpath=minpath+Board[x+1][y];
				printf("min path:%d\n",minpath);
				x++;
				printf("4\n");
			}
		}
		else if(controlx==2&&controly==4)
		{
			if(Board[x-1][y]>Board[x][y+1])
			{
				minpath=minpath+Board[x][y+1];
				printf("min path:%d\n",minpath);
				y++;
				printf("1\n");
			}
			else
			{
				minpath=minpath+Board[x-1][y];
				printf("min path:%d\n",minpath);
				x--;
				printf("3\n");
			}
		}
		else if(controlx==2&&controly==3)
		{
			if(Board[x-1][y]>Board[x][y-1])
			{
				minpath=minpath+Board[x][y-1];
				printf("min path:%d\n",minpath);
				y--;
				printf("2\n");
			}
			else
			{
				minpath=minpath+Board[x-1][y];
				printf("min path:%d\n",minpath);
				x--;
				printf("3\n");
			}
		}
	}
	return 0;
}
