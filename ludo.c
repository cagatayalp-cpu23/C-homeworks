#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
void moveforred(char *ch[100][100],char **copych[100],int *dice,int t,int i);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(char *ch[100][100]);
void copy(char *ch[100][100],char **copych[100],int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9,int n10,int n11,int n12,int n13,int n14,int n15,int n16,int n17,int n18,int n19,int n20,int n21,int n22,int n23,int n24,int n25,int n26,int n27,int n28,int n29,int n30,int n31,int n32,int n33,int n34,int n35,int n36,int n37,int n38,int n39,int n40,int n41,int n42,int n43,int n44);
void print(char *ch[100][100]);
void move(char *ch[100][100],int *count1,char **copych[100],int bldc,int grdc,int yldc,int rddc,int *count2,int *count3,int *count4,char pawn[10]);
void baslangicdegisim(char *pawn,char *str,int *index,int *index2,char **copych[100],char *ch[100][100]);
void tasyeme(char *str,int *index3,char **copych[100],char *ch[100][100],int *t,int *i,int *count10);
void sonuc(char **copych[100],char *ch1,char *ch2,char *ch3,char *ch4,char ch5[10]);
void moveforblue(char *ch[100][100],char **copych[100],int *dice,int t,int i);
void moveforgreen(char *ch[100][100],char **copych[100],int *dice,int t,int i);
void moveforyellow(char *ch[100][100],char **copych[100],int *dice,int t,int i);
void welcome();

int main(int argc, char *argv[]) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),    BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
	welcome();
	system("cls");
	char *ch[100][100];
	char **copych[100];
	int bldc;
	int grdc;
	int yldc;
	int rddc;
	menu(ch);
	char pawn[10];
	print(ch);
	int ilk=0;
	int ilkk=0;
	move(ch,&ilk,copych,bldc,grdc,yldc,rddc,&ilkk,&ilk,&ilk,pawn);//baþlangýç için zarlara rastgele deðerler verdim
	return 0;
}

void menu(char *ch[100][100])
{
    
	ch[0][0]="B1";
	ch[0][1]="B2";
	ch[0][2]="00";
	ch[0][3]="__";
	ch[0][4]="__";
	ch[0][5]="__";
	ch[0][6]="00";
	ch[0][7]="R1";
	ch[0][8]="R2";
	ch[1][0]="B3";
	ch[1][1]="B4";
	ch[1][2]="00";
	ch[1][3]="__";
	ch[1][4]="__";
	ch[1][5]="__";
	ch[1][6]="00";
	ch[1][7]="R3";
    ch[1][8]="R4";
	ch[2][0]="00";
    ch[2][1]="00";
	ch[2][2]="00";
	ch[2][3]="__";
	ch[2][4]="__";
	ch[2][5]="__";
	ch[2][6]="00";
	ch[2][7]="00";
	ch[2][8]="00";
	int i,j;
	for(i=3;i<6;i++)
	{
		for(j=0;j<9;j++)
		{
			ch[i][j]="__";
		}
	}
	ch[6][0]="00";
    ch[6][1]="00";
	ch[6][2]="00";
	ch[6][3]="__";
	ch[6][4]="__";
	ch[6][5]="__";
	ch[6][6]="00";
	ch[6][7]="00";
	ch[6][8]="00";
	ch[7][0]="G1";
	ch[7][1]="G2";
	ch[7][2]="00";
	ch[7][3]="__";
	ch[7][4]="__";
	ch[7][5]="__";
	ch[7][6]="00";
	ch[7][7]="Y1";
	ch[7][8]="Y2";
	ch[8][0]="G3";
	ch[8][1]="G4";
	ch[8][2]="00";
	ch[8][3]="__";
	ch[8][4]="__";
	ch[8][5]="__";
	ch[8][6]="00";
	ch[8][7]="Y3";
	ch[8][8]="Y4";



}
void copy(char *ch[100][100],char **copych[100],int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9,int n10,int n11,int n12,int n13,int n14,int n15,int n16,int n17,int n18,int n19,int n20,int n21,int n22,int n23,int n24,int n25,int n26,int n27,int n28,int n29,int n30,int n31,int n32,int n33,int n34,int n35,int n36,int n37,int n38,int n39,int n40,int n41,int n42,int n43,int n44)
{
	copych[n1]=&ch[0][3];//Her renk kendi sýrasý geldiðinde 1 den 35 e kadar sýralandý bu sayede teker teker deðiþmek yerine gelen zarýn üstüne ekleyerek hareket iþlemi yaptým 
	copych[n2]=&ch[1][3];
	copych[n3]=&ch[2][3];
	copych[n4]=&ch[3][3];
	copych[n5]=&ch[3][2];
	copych[n6]=&ch[3][1];
	copych[n7]=&ch[3][0];//Baþka bir pointerin(*ch) deðerini tutmak için copych nin iki pointerin iþareti almasý gerekti ve zar atarken sýralý olmasý iþime yarayacaðý için ayrýyeten sýralý diziye kaydettim. Her renkte de sýra yenilendi.
	copych[n8]=&ch[4][0];
	copych[n9]=&ch[5][0];
	copych[n10]=&ch[5][1];
	copych[n11]=&ch[5][2];
	copych[n12]=&ch[5][3];
	copych[n13]=&ch[6][3];
	copych[n14]=&ch[7][3];
	copych[n15]=&ch[8][3];
	copych[n16]=&ch[8][4];
	copych[n17]=&ch[8][5];
	copych[n18]=&ch[7][5];
	copych[n19]=&ch[6][5];
	copych[n20]=&ch[5][5];
	copych[n21]=&ch[5][6];
	copych[n22]=&ch[5][7];
	copych[n23]=&ch[5][8];
	copych[n24]=&ch[4][8];
	copych[n25]=&ch[3][8];
	copych[n26]=&ch[3][7];
	copych[n27]=&ch[3][6];
	copych[n28]=&ch[3][5];
	copych[n29]=&ch[2][5];
	copych[n30]=&ch[1][5];
	copych[n31]=&ch[0][5];
	copych[n32]=&ch[0][4];
	copych[70]=&ch[0][0];//blue ilk yerleri
	copych[71]=&ch[0][1];
	copych[72]=&ch[1][0];
	copych[73]=&ch[1][1];
	
	copych[37]=&ch[0][7];//red ilk yerleri
	copych[38]=&ch[0][8];
	copych[39]=&ch[1][7];
	copych[40]=&ch[1][8];
	
	copych[41]=&ch[7][0];//green ilk yerleri
	copych[42]=&ch[7][1];
	copych[43]=&ch[8][0];
	copych[44]=&ch[8][1];
	
	copych[45]=&ch[7][7];//yellow ilk yerleri
	copych[46]=&ch[7][8];
	copych[47]=&ch[8][7];
	copych[48]=&ch[8][8];
	
	copych[n33]=&ch[1][4];
	copych[n34]=&ch[2][4];
	copych[n35]=&ch[3][4];

	
	
                          
	copych[n36]=&ch[4][7];
	copych[n37]=&ch[4][6];
	copych[n38]=&ch[4][5];
	
	copych[n39]=&ch[4][1];
	copych[n40]=&ch[4][2];
	copych[n41]=&ch[4][3];
                          
	copych[n42]=&ch[7][4];
	copych[n43]=&ch[6][4];
	copych[n44]=&ch[5][4];
	
	
	
}
void print(char *ch[100][100])
{
	int i,j;
		for(i=0;i<9;i++)
    	{
		   for(j=0;j<9;j++)
	   	   {
	    		printf("%s",ch[i][j]);
	    		printf("|");
	    	}
	    	printf("\n");
		
    	}
}

void move(char *ch[100][100],int *count1,char **copych[100],int bldc,int grdc,int yldc,int rddc,int *count2,int *count3,int *count4,char pawn[10])
{
	int player;
	printf("How many players do you want to play with?");
	scanf(" %i",&player);
	
	
	while(1==1)
	{
		if(player==4||player==3||player==2||player==1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_BLUE | BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
		
		printf("Its Blue turn,throw the dice:");
		 bldc=dice();
		 getch();
		printf("%i\n",bldc);
		if(bldc!=6)
        {
        	int i,j;
        	moveforblue(ch,copych,&bldc,i,j);
    	
    				
		}
		if(bldc==6)
		{
	    	
			    copy(ch,copych,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,60,61,63,64,65,66,67,68,69);// mavi için 1 35 arasý sýralandý 32 33 34 35 yuva yerleri, 60 gibi yüksek sayýlar ise boþ kalmamasý için  
				char decision[10];
				char pawn[10];
		    	printf("if you want to add pawn to the game type addpawn   or if you want to move the pawn type movepawn: ");//6 geldiðinde addpawn yazarsa piyonu oyuna sokar movepawn yazarsa oyundaki piyonu oynar.
				scanf("%s",decision);
				printf("\n");
				
				if(strcmp(decision,"addpawn")==0)
				{
					printf("Which pawn?");// oynayacaðý piyon seçilir
					scanf("%s",pawn);
					int num1=1;
					int num2=70;
					int num3=71;
					int num4=72;
					int num5=73;
					char cha2[10]="B1";
					char cha3[10]="B2";
					char cha4[10]="B3";
					char cha5[10]="B4";
					baslangicdegisim(pawn,cha2,&num1,&num2,copych,ch);
					baslangicdegisim(pawn,cha3,&num1,&num3,copych,ch);
					baslangicdegisim(pawn,cha4,&num1,&num4,copych,ch);
					baslangicdegisim(pawn,cha5,&num1,&num5,copych,ch);
					
	            }
	            if(strcmp(decision,"movepawn")==0)
	            {
	            	int i,j;
	            	moveforblue(ch,copych,&bldc,i,j);
				}
	    }
		}  
		if(player==4||player==3||player==2)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),   FOREGROUND_RED | BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
	    printf("Its Red turn,throw the dice:");//ayný iþlemler sýrayla diðer taþlara uygulanýr
	    getch();
		rddc=dice();
		printf("%i\n",rddc);
		
		if(rddc!=6)
		{
			int i,j;
			moveforred(ch,copych,&rddc,i,j);
		}
		if(rddc==6)
		{
		    copy(ch,copych,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,60,61,62,33,34,35,64,74,75,76,77,78);//red için sýralandý
			
	            char decision[10];
				char pawn[10];
				printf("if you want to add pawn to the game type addpawn   or if you want to move the pawn type movepawn: ");
				scanf("%s",decision);
				printf("\n");
				
			if(strcmp(decision,"addpawn")==0)
			{    printf("Which pawn?");
			     scanf("%s",pawn);
			     int num10=1;
			     int num11=37;
			     int num12=38;
			     int num13=39;
			     int num14=40;
			     char cha6[10]="R1";
				char cha7[10]="R2";
				char cha8[10]="R3";
				char cha9[10]="R4";
			     baslangicdegisim(pawn,cha6,&num10,&num11,copych,ch);
				baslangicdegisim(pawn,cha7,&num10,&num12,copych,ch);
				baslangicdegisim(pawn,cha8,&num10,&num13,copych,ch);
				baslangicdegisim(pawn,cha9,&num10,&num14,copych,ch);
	    	
     		
         	}
         	if(strcmp(decision,"movepawn")==0)
	        {
	        	int i,j;
	            moveforred(ch,copych,&rddc,i,j);
			}
 	
    	}
        }
        if(player==4||player==3)
        {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_GREEN | BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
    	printf("Its Green turn,throw the dice:");
    	getch();
		grdc=dice();
		printf("%i\n",grdc);
		if(grdc!=6)
		{
			int i,j;
			moveforgreen(ch,copych,&grdc,i,j);
		}
		if(grdc==6)
		{
	    copy(ch,copych,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,60,61,62,63,74,75,33,34,35,76,77,78);//green için sýralandý maviyi 1-35 sýralý seçtim diðerlerinin de ona göre alacaðý piyonlari belirledim
	     char decision[10];
				char pawn[10];
				printf("if you want to add pawn to the game type addpawn   or if you want to move the pawn type movepawn: ");
				scanf("%s",decision);
				printf("\n");
				
			if(strcmp(decision,"addpawn")==0)
			{   printf("Which pawn?");
				scanf("%s",pawn);
				int num15=1;
			     int num16=41;
			     int num17=42;
			     int num18=43;
			     int num19=44;
			     char cha10[10]="G1";
				char cha11[10]="G2";
				char cha12[10]="G3";
				char cha13[10]="G4";
			     baslangicdegisim(pawn,cha10,&num15,&num16,copych,ch);
				baslangicdegisim(pawn,cha11,&num15,&num17,copych,ch);
				baslangicdegisim(pawn,cha12,&num15,&num18,copych,ch);
				baslangicdegisim(pawn,cha13,&num15,&num19,copych,ch);
	    	
	    	
     	    }
     		if(strcmp(decision,"movepawn")==0)
	        {
	        	int i,j;
	        	moveforgreen(ch,copych,&bldc,i,j);
			}
 	
    	}
        }
        if(player==4)
        {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN);
    	printf("Its Yellow turn,throw the dice:");
    	getch();
		yldc=dice();
		printf("%i\n",yldc);
		if(yldc!=6)
		{
			int i,j;
			moveforyellow(ch,copych,&yldc,i,j);
		}
		if(yldc==6)
		{
	            copy(ch,copych,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,60,61,62,63,74,75,76,77,78,33,34,35);//yellow için sýralandý
	            char decision[10];
				char pawn[10];
				printf("if you want to add pawn to the game type addpawn   or if you want to move the pawn type movepawn: ");
				scanf("%s",decision);
				printf("\n");
				
			if(strcmp(decision,"addpawn")==0)
			{
				printf("Which pawn?");
				scanf("%s",pawn);
				int num20=1;
				int num21=45;
			     int num22=46;
			     int num23=47;
			     int num24=48;
			     char cha14[10]="Y1";
				char cha15[10]="Y2";
				char cha16[10]="Y3";
				char cha17[10]="Y4";
			     baslangicdegisim(pawn,cha14,&num20,&num21,copych,ch);
				baslangicdegisim(pawn,cha15,&num20,&num22,copych,ch);
				baslangicdegisim(pawn,cha16,&num20,&num23,copych,ch);
				baslangicdegisim(pawn,cha17,&num20,&num24,copych,ch);
     	    }
     	    if(strcmp(decision,"movepawn")==0)
	        {
	        	int i,j;
	        	moveforyellow(ch,copych,&yldc,i,j);
			}
     	    
 	
    	}
        }
    	getch();
		
	}
}
int dice()
{
	srand(time(NULL));     
    int r = rand()%6 + 1;
    return r;
}
void moveforred(char *ch[100][100],char **copych[100],int *dice,int t,int i)
{
	 copy(ch,copych,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,60,61,62,33,34,35,64,74,75,76,77,78);
	int k=0;
	i=1;
	while(i<36&&k==0)//k  arttýðýnda diziden çýkmasý için while döngüsü açtým çünkü bir kere yazdýrýnca diðer turlarda bloklara girmeyip diziden çýkmasý gerek yoksa while bitene kadar birkaç kere yazdýrma yapýlýyor ve yerler deðiþiyor
	{
	        
		if((strcmp(*copych[i],"R1")==0)||(strcmp(*copych[i],"R2")==0)||(strcmp(*copych[i],"R3")==0)||(strcmp(*copych[i],"R4")==0))
        {
        	    
        		if((*dice+i)%32==0)
        		{
        			t=32;
				}
				if((*dice+i)<32)
				{
					t=(*dice+i)%32;
				}
				if((*dice+i)==35)
        		{
        			t=35;
				}
				if((*dice+i)==34)// 32 33 34 35 yuvalarýn deðerleri
        		{
        			t=34;
				}
				if((*dice+i)==33)
        		{
        			t=33;
				}
				if((*dice+i)>35)
        		{
        			t=35;
				}
				//yukarýdaki iþlemler t nin yani piyonla yeri deðiþecek olanýn sayýsýný veriyor  baþka bir piyonla mý yoksa (__) yani boþlukla mý yeri deðiþecek ona göre kontrol yaptým 
				
		
	    	if((strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0))//piyonla boþluðun yeri deðiþecekse buraya giriyor
	    	{
	    
                	char *tmp43;
                    tmp43=*copych[i];
                	*copych[i]=*copych[t];
                    *copych[t]=tmp43;
                 	print(ch);
                 	k++;
				
		    	
	    	
	        
		    }
		    
			    if(k==0)
			    {
				
				if(strcmp(*copych[t],"__")!=0)
				{
				if(strcmp(*copych[i],"__")!=0)//piyonla piyonun yeri deðiþecekse ve bir piyon yenecekse bura giriyor
				{
					
					int count10=0;
			    	if((strcmp(*copych[i],"B1")!=0)&&(strcmp(*copych[i],"B2")!=0)&&(strcmp(*copych[i],"B3")!=0)&&(strcmp(*copych[i],"B4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str[10]="B1";
			    		int num=70;
			    		tasyeme(str,&num,copych,ch,&t,&i,&count10);
        	        	char str1[10]="B2";
			    		int num2=71;
			    		tasyeme(str1,&num2,copych,ch,&t,&i,&count10);
    	            	char str2[10]="B3";
			    		int num3=72;
			    		tasyeme(str2,&num3,copych,ch,&t,&i,&count10);
			    		char str3[10]="B4";
			    		int num4=73;
			    		tasyeme(str3,&num4,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"R1")!=0)&&(strcmp(*copych[i],"R2")!=0)&&(strcmp(*copych[i],"R3")!=0)&&(strcmp(*copych[i],"R4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str4[10]="R1";
			    		int num5=37;
			    		tasyeme(str4,&num5,copych,ch,&t,&i,&count10);
        	        	char str5[10]="R2";
			    		int num6=38;
			    		tasyeme(str5,&num6,copych,ch,&t,&i,&count10);
    	            	char str6[10]="R3";
			    		int num7=39;
			    		tasyeme(str6,&num7,copych,ch,&t,&i,&count10);
	                	char str7[10]="R4";
			    		int num8=40;
			    		tasyeme(str7,&num8,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"G1")!=0)&&(strcmp(*copych[i],"G2")!=0)&&(strcmp(*copych[i],"G3")!=0)&&(strcmp(*copych[i],"G4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str8[10]="G1";
			    		int num9=41;
			    		tasyeme(str8,&num9,copych,ch,&t,&i,&count10);
        	        	char str9[10]="G2";
			    		int num10=42;
			    		tasyeme(str9,&num10,copych,ch,&t,&i,&count10);
    	            	char str10[10]="G3";
			    		int num11=43;
			    		tasyeme(str10,&num11,copych,ch,&t,&i,&count10);
	                	char str11[10]="G4";
			    		int num12=44;
			    		tasyeme(str11,&num12,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"Y1")!=0)&&(strcmp(*copych[i],"Y2")!=0)&&(strcmp(*copych[i],"Y3")!=0)&&(strcmp(*copych[i],"Y4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str12[10]="Y1";
			    		int num13=45;
			    		tasyeme(str12,&num13,copych,ch,&t,&i,&count10);
        	        	char str13[10]="Y2";
			    		int num14=46;
			    		tasyeme(str13,&num14,copych,ch,&t,&i,&count10);
    	            	char str14[10]="Y3";
			    		int num15=47;
			    		tasyeme(str14,&num15,copych,ch,&t,&i,&count10);
	                	char str15[10]="Y4";
			    		int num16=48;
			    		tasyeme(str15,&num16,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	
			        }
			    }
			    }
			    }
            	
	    
        }
        i++;
		sonuc(copych,"R1","R2","R3","R4","RED");
    }
}
void moveforblue(char *ch[100][100],char **copych[100],int *dice,int t,int i)
{
	copy(ch,copych,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,60,61,63,64,65,66,67,68,69);
	
	int k=0;
	i=1;
	while(i<36&&k==0)
	{
	
		         
		if((strcmp(*copych[i],"B1")==0)||(strcmp(*copych[i],"B2")==0)||(strcmp(*copych[i],"B3")==0)||(strcmp(*copych[i],"B4")==0))
        {
        	    
        		if((*dice+i)%32==0)
        		{
        			t=32;
				}
				if((*dice+i)<32)
				{
					t=(*dice+i)%32;
				}
				if((*dice+i)==35)
        		{
        			t=35;
				}
				if((*dice+i)==34)
        		{
        			t=34;
				}
				if((*dice+i)==33)
        		{
        			t=33;
				}
				if((*dice+i)>35)
        		{
        			t=35;
				}
				
				
	    	if((strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0))
	    	{
	    
                	char *tmp43;
                    tmp43=*copych[i];
                	*copych[i]=*copych[t];
                    *copych[t]=tmp43;
                 	print(ch);
                 	k++;
				
		    }
		    
			    if(k==0)
			    {
				
				if(strcmp(*copych[t],"__")!=0)
				{
				if(strcmp(*copych[i],"__")!=0)
				{
					
					int count10=0;
			    	if((strcmp(*copych[i],"B1")!=0)&&(strcmp(*copych[i],"B2")!=0)&&(strcmp(*copych[i],"B3")!=0)&&(strcmp(*copych[i],"B4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str[10]="B1";
			    		int num=70;
			    		tasyeme(str,&num,copych,ch,&t,&i,&count10);
        	        	char str1[10]="B2";
			    		int num2=71;
			    		tasyeme(str1,&num2,copych,ch,&t,&i,&count10);
    	            	char str2[10]="B3";
			    		int num3=72;
			    		tasyeme(str2,&num3,copych,ch,&t,&i,&count10);
			    		char str3[10]="B4";
			    		int num4=73;
			    		tasyeme(str3,&num4,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"R1")!=0)&&(strcmp(*copych[i],"R2")!=0)&&(strcmp(*copych[i],"R3")!=0)&&(strcmp(*copych[i],"R4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str4[10]="R1";
			    		int num5=37;
			    		tasyeme(str4,&num5,copych,ch,&t,&i,&count10);
        	        	char str5[10]="R2";
			    		int num6=38;
			    		tasyeme(str5,&num6,copych,ch,&t,&i,&count10);
    	            	char str6[10]="R3";
			    		int num7=39;
			    		tasyeme(str6,&num7,copych,ch,&t,&i,&count10);
	                	char str7[10]="R4";
			    		int num8=40;
			    		tasyeme(str7,&num8,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"G1")!=0)&&(strcmp(*copych[i],"G2")!=0)&&(strcmp(*copych[i],"G3")!=0)&&(strcmp(*copych[i],"G4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str8[10]="G1";
			    		int num9=41;
			    		tasyeme(str8,&num9,copych,ch,&t,&i,&count10);
        	        	char str9[10]="G2";
			    		int num10=42;
			    		tasyeme(str9,&num10,copych,ch,&t,&i,&count10);
    	            	char str10[10]="G3";
			    		int num11=43;
			    		tasyeme(str10,&num11,copych,ch,&t,&i,&count10);
	                	char str11[10]="G4";
			    		int num12=44;
			    		tasyeme(str11,&num12,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"Y1")!=0)&&(strcmp(*copych[i],"Y2")!=0)&&(strcmp(*copych[i],"Y3")!=0)&&(strcmp(*copych[i],"Y4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str12[10]="Y1";
			    		int num13=45;
			    		tasyeme(str12,&num13,copych,ch,&t,&i,&count10);
        	        	char str13[10]="Y2";
			    		int num14=46;
			    		tasyeme(str13,&num14,copych,ch,&t,&i,&count10);
    	            	char str14[10]="Y3";
			    		int num15=47;
			    		tasyeme(str14,&num15,copych,ch,&t,&i,&count10);
	                	char str15[10]="Y4";
			    		int num16=48;
			    		tasyeme(str15,&num16,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	
			        }
			    }
			    }
			    }
            	
	    
        }
        i++;
	    sonuc(copych,"B1","B2","B3","B4","BLUE");
    }
}
void moveforgreen(char *ch[100][100],char **copych[100],int *dice,int t,int i)
{
	copy(ch,copych,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,60,61,62,63,74,75,33,34,35,76,77,78);
	
	int k=0;
	i=1;
	while(i<36&&k==0)
	{
	
				
		if((strcmp(*copych[i],"G1")==0)||(strcmp(*copych[i],"G2")==0)||(strcmp(*copych[i],"G3")==0)||(strcmp(*copych[i],"G4")==0))
        {
        	    
        		if((*dice+i)%32==0)
        		{
        			t=32;
				}
				if((*dice+i)<32)
				{
					t=(*dice+i)%32;
				}
				if((*dice+i)==35)
        		{
        			t=35;
				}
				if((*dice+i)==34)
        		{
        			t=34;
				}
				if((*dice+i)==33)
        		{
        			t=33;
				}
				if((*dice+i)>35)
        		{
        			t=35;
				}
				
				
		
	    	if((strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0))
	    	{
	    
                	char *tmp43;
                    tmp43=*copych[i];
                	*copych[i]=*copych[t];
                    *copych[t]=tmp43;
                 	print(ch);
                 	k++;
				
		    }
		    
			    if(k==0)
			    {
				
				if(strcmp(*copych[t],"__")!=0)
				{
				if(strcmp(*copych[i],"__")!=0)
				{
					
					int count10=0;
			    	if((strcmp(*copych[i],"B1")!=0)&&(strcmp(*copych[i],"B2")!=0)&&(strcmp(*copych[i],"B3")!=0)&&(strcmp(*copych[i],"B4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str[10]="B1";
			    		int num=70;
			    		tasyeme(str,&num,copych,ch,&t,&i,&count10);
        	        	char str1[10]="B2";
			    		int num2=71;
			    		tasyeme(str1,&num2,copych,ch,&t,&i,&count10);
    	            	char str2[10]="B3";
			    		int num3=72;
			    		tasyeme(str2,&num3,copych,ch,&t,&i,&count10);
			    		char str3[10]="B4";
			    		int num4=73;
			    		tasyeme(str3,&num4,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"R1")!=0)&&(strcmp(*copych[i],"R2")!=0)&&(strcmp(*copych[i],"R3")!=0)&&(strcmp(*copych[i],"R4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    		
			    		char str4[10]="R1";
			    		int num5=37;
			    		tasyeme(str4,&num5,copych,ch,&t,&i,&count10);
        	        	char str5[10]="R2";
			    		int num6=38;
			    		tasyeme(str5,&num6,copych,ch,&t,&i,&count10);
    	            	char str6[10]="R3";
			    		int num7=39;
			    		tasyeme(str6,&num7,copych,ch,&t,&i,&count10);
	                	char str7[10]="R4";
			    		int num8=40;
			    		tasyeme(str7,&num8,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"G1")!=0)&&(strcmp(*copych[i],"G2")!=0)&&(strcmp(*copych[i],"G3")!=0)&&(strcmp(*copych[i],"G4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str8[10]="G1";
			    		int num9=41;
			    		tasyeme(str8,&num9,copych,ch,&t,&i,&count10);
        	        	char str9[10]="G2";
			    		int num10=42;
			    		tasyeme(str9,&num10,copych,ch,&t,&i,&count10);
    	            	char str10[10]="G3";
			    		int num11=43;
			    		tasyeme(str10,&num11,copych,ch,&t,&i,&count10);
	                	char str11[10]="G4";
			    		int num12=44;
			    		tasyeme(str11,&num12,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"Y1")!=0)&&(strcmp(*copych[i],"Y2")!=0)&&(strcmp(*copych[i],"Y3")!=0)&&(strcmp(*copych[i],"Y4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str12[10]="Y1";
			    		int num13=45;
			    		tasyeme(str12,&num13,copych,ch,&t,&i,&count10);
        	        	char str13[10]="Y2";
			    		int num14=46;
			    		tasyeme(str13,&num14,copych,ch,&t,&i,&count10);
    	            	char str14[10]="Y3";
			    		int num15=47;
			    		tasyeme(str14,&num15,copych,ch,&t,&i,&count10);
	                	char str15[10]="Y4";
			    		int num16=48;
			    		tasyeme(str15,&num16,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	
			        }
			    }
			    }
			    }
            	
	    
        }
        i++;
        sonuc(copych,"G1","G2","G3","G4","GREEN");
    }
}
void moveforyellow(char *ch[100][100],char **copych[100],int *dice,int t,int i)
{
	copy(ch,copych,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,60,61,62,63,74,75,76,77,78,33,34,35);
   	
	int k=0;
	i=1;
	while(i<36&&k==0)
	{
	
			
		if((strcmp(*copych[i],"Y1")==0)||(strcmp(*copych[i],"Y2")==0)||(strcmp(*copych[i],"Y3")==0)||(strcmp(*copych[i],"Y4")==0))
        {
        	    
        		if((*dice+i)%32==0)
        		{
        			t=32;
				}
				if((*dice+i)<32)
				{
					t=(*dice+i)%32;
				}
				if((*dice+i)==35)
        		{
        			t=35;
				}
				if((*dice+i)==34)
        		{
        			t=34;
				}
				if((*dice+i)==33)
        		{
        			t=33;
				}
				if((*dice+i)>35)
        		{
        			t=35;
				}
				
				
		
	    	if((strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0)||(strcmp(*copych[t],"__")==0))
	    	{
	    
                	char *tmp43;
                    tmp43=*copych[i];
                	*copych[i]=*copych[t];
                    *copych[t]=tmp43;
                 	print(ch);
                 	k++;
				
		    	
		    }
			    if(k==0)
			    {
				
				if(strcmp(*copych[t],"__")!=0)
				{
				if(strcmp(*copych[i],"__")!=0)
				{
					
					int count10=0;
			    	if((strcmp(*copych[i],"B1")!=0)&&(strcmp(*copych[i],"B2")!=0)&&(strcmp(*copych[i],"B3")!=0)&&(strcmp(*copych[i],"B4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	
			    		char str[10]="B1";
			    		int num=70;
			    		tasyeme(str,&num,copych,ch,&t,&i,&count10);
        	        	char str1[10]="B2";
			    		int num2=71;
			    		tasyeme(str1,&num2,copych,ch,&t,&i,&count10);
    	            	char str2[10]="B3";
			    		int num3=72;
			    		tasyeme(str2,&num3,copych,ch,&t,&i,&count10);
			    		char str3[10]="B4";
			    		int num4=73;
			    		tasyeme(str3,&num4,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"R1")!=0)&&(strcmp(*copych[i],"R2")!=0)&&(strcmp(*copych[i],"R3")!=0)&&(strcmp(*copych[i],"R4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    				k++;
			    	
			    		char str4[10]="R1";
			    		int num5=37;
			    		tasyeme(str4,&num5,copych,ch,&t,&i,&count10);
        	        	char str5[10]="R2";
			    		int num6=38;
			    		tasyeme(str5,&num6,copych,ch,&t,&i,&count10);
    	            	char str6[10]="R3";
			    		int num7=39;
			    		tasyeme(str6,&num7,copych,ch,&t,&i,&count10);
	                	char str7[10]="R4";
			    		int num8=40;
			    		tasyeme(str7,&num8,copych,ch,&t,&i,&count10);
						}
			    	
	                    
			    	}
			    	if((strcmp(*copych[i],"G1")!=0)&&(strcmp(*copych[i],"G2")!=0)&&(strcmp(*copych[i],"G3")!=0)&&(strcmp(*copych[i],"G4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	   
			    		char str8[10]="G1";
			    		int num9=41;
			    		tasyeme(str8,&num9,copych,ch,&t,&i,&count10);
        	        	char str9[10]="G2";
			    		int num10=42;
			    		tasyeme(str9,&num10,copych,ch,&t,&i,&count10);
    	            	char str10[10]="G3";
			    		int num11=43;
			    		tasyeme(str10,&num11,copych,ch,&t,&i,&count10);
	                	char str11[10]="G4";
			    		int num12=44;
			    		tasyeme(str11,&num12,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	}
			    	if((strcmp(*copych[i],"Y1")!=0)&&(strcmp(*copych[i],"Y2")!=0)&&(strcmp(*copych[i],"Y3")!=0)&&(strcmp(*copych[i],"Y4")!=0))
			    	{
			    		if(count10==0)
			    		{
			    			k++;
			    	    
			    		char str12[10]="Y1";
			    		int num13=45;
			    		tasyeme(str12,&num13,copych,ch,&t,&i,&count10);
        	        	char str13[10]="Y2";
			    		int num14=46;
			    		tasyeme(str13,&num14,copych,ch,&t,&i,&count10);
    	            	char str14[10]="Y3";
			    		int num15=47;
			    		tasyeme(str14,&num15,copych,ch,&t,&i,&count10);
	                	char str15[10]="Y4";
			    		int num16=48;
			    		tasyeme(str15,&num16,copych,ch,&t,&i,&count10);
						}
			    		
	                    
			    	
			        }
			    }
			    }
			    }
            	
	    
        }
        i++;
        sonuc(copych,"Y1","Y2","Y3","Y4","YELLOW");
    }
}
void baslangicdegisim(char *pawn,char *str,int *index,int *index2,char **copych[100],char *ch[100][100])
{
	if(strcmp(pawn,str)==0)
	{
	    if(strcmp(*copych[*index],"__")==0)
	    {
     	     char *tmp;
  	     	tmp= *copych[*index];
	       	*copych[*index]=*copych[*index2];
         	*copych[*index2]=tmp;		     
        	print(ch);
    	}
					 
	}
	

}
void tasyeme(char *strr,int *index3,char **copych[100],char *ch[100][100],int *t,int *i,int *count10)
{
	if(strcmp(*copych[*t],strr)==0)
	{
    	char *tmp4;
    	tmp4=*copych[*t];
    	*copych[*t]=*copych[*index3];
		*copych[*index3]=tmp4;
		tmp4= *copych[*t];
	    *copych[*t]=*copych[*i];
		*copych[*i]=tmp4;
		print(ch);
		printf("\a");
		(*count10)++;
	}
}
void sonuc(char **copych[100],char *ch1,char *ch2,char *ch3,char *ch4,char ch5[10])
{
	if(strcmp(*copych[32],ch1)==0||strcmp(*copych[32],ch2)==0||strcmp(*copych[32],ch3)==0||strcmp(*copych[32],ch4)==0)
	{
		if(strcmp(*copych[33],ch1)==0||strcmp(*copych[33],ch2)==0||strcmp(*copych[33],ch3)==0||strcmp(*copych[33],ch4)==0)
		{
			if(strcmp(*copych[34],ch1)==0||strcmp(*copych[34],ch2)==0||strcmp(*copych[34],ch3)==0||strcmp(*copych[34],ch4)==0)
			{
				if(strcmp(*copych[35],ch1)==0||strcmp(*copych[35],ch2)==0||strcmp(*copych[35],ch3)==0||strcmp(*copych[35],ch4)==0)
				{
					printf("!!!!!!!!!!!!!!!!!GAME OVER %s WIN!!!!!!!!!!!!!!!!!!\n",ch5);
				}
			}
		}
	}
}
void welcome()
{
   
   printf("\tWelcome to the  game.(press any key to continue)\n");
   getch();
   system("cls");
   printf("\tGame rules:\n" 
"1.Each player has 4 pieces.\n"
"2. There might be 2, 3, or 4 players (Red (R) ,Yellow (Y), Green (G) and Blue (B))\n"
"3. At each round the respective player rolls the single dice (1-6).\n"
"4. Each piece is allowed to leave from the nest, if the dice shows 6 and if the place to move on is empty\n"
"5. At each cell, only one single piece could exist.\n"
"6. Each player is allowed to place any number of his/her pieces into the raceway.\n"
"7. If the player rolls six, he/she could either place a piece into the board from the nest or play any piece on the board.\n"
"8. A piece could move forward even if there is a piece of any opponent on its way."
"9. If a piece stops at the same place of another piece of the same player, the player is not allowed to move it. He/she should wait for his/her next turn.\n"
"10.Nobody could hurt a piece if it reaches at the final destination except the last one.\n"
"11. If any piece could reach to the location of another players piece, the piece should return to its nest.But if its happening when a piece is trying to get in the game, the piece which is trying to get in the game can not move and cant eat that another piece\n"
"12. The player whose all 4 pieces reach at final destination becomes the WINNER.\n "
"13.If a piece is trying to get into the game, the place to move(starting place) must empty.  \n"
"14. Every time, the  to be moved piece of the same player is the one that being behind.");
   printf("\n\nPress any key to play game...");
   getch();
   
}



