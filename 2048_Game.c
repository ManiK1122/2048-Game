#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void score(int [][6]);
int eqlr(int []);
void zeror(int []);
int eqll(int []);
void zerol(int [ ]);
void display(int [6][6]);
int gameover(int [][6]);
void playgame(int [][6]);
int main()
{
	int a[6][6]={0};             //taking 6*6 matrix to put zeros around 4*4 matrix
	
	printf("1.left\n2.right\n3.up\n4.down\n5.exit\n");
        printf("\nwelcomme to 2048 game\n\n"); 	
	printf("\nstart the game goodluck:)\n");
	playgame(a);                //calling function playgame which helps player to play his game
	return 0;
}
void playgame(int a[6][6])
{
	int k,z,i,j,ch;
	srand(time(0));        //to generate different values in rand()
	int b[4];
	while(1)
	{
		do
		{
			i=(rand()%4)+1;    //to get different positions i and j till a[i][j]=0 and then a[i][j]=2
			j=(rand()%4)+1;
		}while(a[i][j]);
		a[i][j]=2;

		display(a);          //displays the matrix  4*4 of 6*6
		printf("enter choice:");
		scanf("%d",&ch);    //reads the users choice 
		switch(ch)
		{
			case 1:
			case 2:for(i=1;i<5;i++)
				{
					for(j=1,k=0;j<5;j++,k++)
					{
						b[k]=a[i][j];      //taking each row of 2d array as a 1d array
					}
					if(ch==1)
					{	
						zerol(b);     //arranges the zeros to right in 1d array passed
						eqll(b);     //adds all adjacent eqaul values in the 1d array                                                                towards left
					}
					else if(ch==2)
					{
						zeror(b);   //arranges zeros to left in 1d array passed
						eqlr(b);   //adds all adjacent equal values towards right in 1d                                                            array passed
					}	
					for(k=0;k<4;k++)
						a[i][k+1]=b[k]; //copying the values of 1d array into respective 								row of 2d array
				}
			       break;
			case 3:
			case 4:for(i=1;i<5;i++)
			       {
				       for(j=1,k=0;j<5;j++,k++)
					       b[k]=a[j][i];
				       if(ch==3)
				       {
					       zerol(b);
					       eqll(b);        //same operations as in case 1 and 2 but in 									coloumn in these cases
				       }
				       else if(ch==4)
				       {
					       zeror(b);
					       eqlr(b);
				       }
				       for(k=0;k<4;k++)
					       a[k+1][i]=b[k];
			       }
			       break;
			case 5:printf("\nyou exited\n\n");
			       score(a);
			       exit(1);
			default:printf("\nyou entered wrong choice try again\n\n");
		}
		if(gameover(a))
		{
			score(a);
			break;
		}
	}
}
int eqlr(int a[ ])
{
	int j,i=3;
	while(i)
	{
	 	if(a[i]==a[i-1])
		{
			a[i]+=a[i-1];

		for(j=i-1;j>0;j--)
			a[j]=a[j-1];            //this function checks if adjacent numbers are equal if yes then 						adds them towards right in 1d array passed  
		a[j]=0;
		}
		i--;

	}
}
void zeror(int a[])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(a[i]==0)
		{
			for(j=i;j>0;j--)
				a[j]=a[j-1];   //this function moves all zeros to left in 1d array passed
			a[j]=0;
		}
	}
}
int eqll(int a[])
{
	int j,i=0;
	while(i!=3)
	{
		if(a[i]==a[i+1])
		{
			a[i]+=a[i+1];
			for(j=i+1;j<3;j++)
				a[j]=a[j+1];  //this function checks if adjacent numbers are equal if yes then     						adds them towards left in 1d array passed
			a[j]=0;
		}
		i++;
	}
}
void zerol(int a[])
{ 
	int i,j;
	for(i=3;i>=0;i--)  
	{
		if(a[i]==0)
		{
		for(j=i;j<3;j++)
			a[j]=a[j+1];  //this function moves all zeros to right in 1d array passed
		a[j]=0;
		}
	}
}
void display(int a[6][6])
{
	int i,j;
	printf("\nafter move:\n\n");
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
			printf("%d\t",a[i][j]);  //displays 4*4 of 6*6 matrix 
		printf("\n");
	}
}
int gameover(int a[6][6])
{
	int i,j;
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			if(a[i][j]==a[i][j+1]||a[i][j]==a[i][j-1]||a[i][j]==a[i+1][j]||a[i][j]==a[i-1][j]||a[i][j			   ]==0)
			{return 0;}
		}
	}
		return 1; //this function checks for atleast one adjacent equal number if yes returns 0 else 			            returns 1
}
void score(int a[][6])
{
	int i,j,c;c=a[1][1];
	for(i=1;i<5;i++)
	{
		for(j=1;j<5;j++)
		{
			if(a[i][j]>c)
				c=a[i][j];
		}
	}
	if(c==2048)
		printf("\nyeah you won the game\n\n");
	else 
		printf("\ngood try gameover try again:)\n\nscore=%d\n\n",c);
	//this function prints the highest number made by the player in the grid or matrix 
}
		


	

