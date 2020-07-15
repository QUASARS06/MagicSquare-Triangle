#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int y;
void oddTriangle(int,int,int);
void evenTriangle(int,int,int);
void oddSquare(int);
void doublyEvenSquare(int);
void singlyEvenSquare(int);
void printTriangle(int[],int[],int[],int,int,int);
void printSquare(int[][y],int);


int main()
{

    int s,n,z;
    printf("---------------------");
    printf("\nENTER THE ORDER : ");
    scanf("%d",&y);
    printf("---------------------\n");

    if(y>2)
    {
    s= 1.5*y*y-2.5*y+3;     //Sum for Magic Triangle
    z= 0.5*y*(y*y+1);       //Sum for Magic Square
    n=(3*y)-3;                //Highest possible element in Triangle

    printf("\n\n------------------------------------");
    printf("\n SUM OF EACH SIDE OF TRIANGLE IS %d|",s);
    printf("\n------------------------------------");

    if(y%2==1)
    oddTriangle(n,y,s);

    else
    evenTriangle(n,y,s);

    printf("\n\n------------------------------------------------");
    printf("\n SUM OF EACH SIDE AND DIAGONAL OF SQUARE IS %d|",z);
    printf("\n------------------------------------------------\n");

    if(y%2==1)
    oddSquare(y);

    else
    if (y%4==0)
      doublyEvenSquare(y);
    else
        singlyEvenSquare(y);
    }
    else
        printf("\n!!! MAGIC TRIANGLE AND SQUARES ARE ONLY POSSIBLE FOR ORDERS GREATER THAN 2 !!!\n\n\n\n");

    return 0;
}

void oddTriangle(int n,int y,int s)
{
    int arr1[y-2],arr2[y],arr3[y-2];        //arr2 : Array of Base of Triangle Elements
    arr2[0]=3;                              //arr1 : Right Side Elements
                                            //arr1 : Left Side Elements

    int c=0;
    int index2=1;
    int index1=0;
    int index3=0;

    for(int i=4;i<=9&&i<=n;i++)
        {
                if(c==0){
                arr2[index2]=i;
                index2++;
                }

                else if(c==1){
                arr3[index3]=i;
                index3++;
                }

                else if(c==2){
                arr1[index1]=i;
                index1++;
                }

                c++;
                if(c>2)
                    c=0;
        }

    c=0;

    for(int i=10;i<=15&&i<=n;i++)
        {
                if(c==0){
                arr1[index1]=i;
                index1++;
                }

                else if(c==1){
                arr3[index3]=i;
                index3++;
                }

                else if(c==2){
                arr2[index2]=i;
                index2++;
                }

                c++;
                if(c>2)
                    c=0;
        }

        c=0;
        int alt=1;

        for(int i=16;i<=n;i++)
        {
            if((i-1)%3==0&&(i-1)>15)
            alt*=-1;
            if(alt>0)
            {
                if(c==0){
                arr2[index2]=i;
                index2++;
                }

                else if(c==1){
                arr3[index3]=i;
                index3++;
                }

                else if(c==2){
                arr1[index1]=i;
                index1++;
                }

            }

            else if(alt<0)
            {
                if(c==0){
                arr1[index1]=i;
                index1++;
                }

                else if(c==1){
                arr3[index3]=i;
                index3++;
                }

                else if(c==2){
                arr2[index2]=i;
                index2++;
                }

            }
                c++;
                if(c>2)
                    c=0;
        }
        arr2[y-1]=2;
        printf("\n");

//        for(int i=0;i<y-2;i++)
//            printf("%d ",arr1[i]);
//        printf("\n");
//
//        for(int i=0;i<y;i++)
//            printf("%d ",arr2[i]);
//        printf("\n");
//
//        for(int i=0;i<y-2;i++)
//            printf("%d ",arr3[i]);
//        printf("\n");

        printTriangle(arr1,arr2,arr3,y,n,s);

}

void evenTriangle(int n,int y,int s)
{
    int arr1[y-2],arr2[y],arr3[y-2];
    arr2[0]=3;

    int c=0;
    int index2=1;
    int index1=0;
    int index3=0;

    for(int i=4;i<=6&&i<=n;i++)
    {
            if(c==0){
            arr2[index2]=i;
            index2++;
            }

            else if(c==1){
            arr1[index1]=i;
            index1++;
            }

            else if(c==2){
            arr3[index3]=i;
            index3++;
            }

                c++;
                if(c>2)
                    c=0;

    }
    c=0;
    int alt=-1;
    for(int i=7;i<=n;i++)
        {
            if((i-1)%3==0)
            alt*=-1;

            if(alt>0)
            {
                if(c==0){
                arr3[index3]=i;
                index3++;
                }
                else if(c==1){
                arr2[index2]=i;
                index2++;
                }

                else if(c==2){
                arr1[index1]=i;
                index1++;
                }

            }

            else if(alt<0)
            {
                if(c==0){
                arr1[index1]=i;
                index1++;
                }

                else if(c==1){
                arr2[index2]=i;
                index2++;
                }

                else if(c==2){
                arr3[index3]=i;
                index3++;
                }

            }
                c++;
                if(c>2)
                    c=0;

        }
        arr2[y-1]=2;
        printf("\n");
//
//        for(int i=0;i<y-2;i++)
//            printf("%d ",arr1[i]);
//        printf("\n");
//
//        for(int i=0;i<y;i++)
//            printf("%d ",arr2[i]);
//        printf("\n");
//
//        for(int i=0;i<y-2;i++)
//            printf("%d ",arr3[i]);
//        printf("\n");

        printTriangle(arr1,arr2,arr3,y,n,s);
}

void oddSquare(int y)
{
  int sqarr[y][y];
  int i=0, j=y/2;     // start position

  memset(sqarr, 0, sizeof(sqarr));

  for (int k=1; k<=y*y; ++k)
  {
    sqarr[i][j] = k;

    i--;
    j++;

    if (k%y == 0)
    {
      i += 2;
      --j;
    }
    else
    {
      if (j==y)
        j -= y;
      else if (i<0)
        i += y;
    }

  }
      printSquare(sqarr,y);
}

void doublyEvenSquare(int y)
{
    int sqarr[y][y], i, j;
    memset(sqarr, 0, sizeof(sqarr));

    for ( i = 0; i < y; i++)
        for ( j = 0; j < y; j++)
            sqarr[i][j] = (y*i) + j + 1;


    for ( i = 0; i < y/4; i++)
        for ( j = 0; j < y/4; j++)
            sqarr[i][j] = (y*y + 1) - sqarr[i][j];


    for ( i = 0; i < y/4; i++)
        for ( j = 3 * (y/4); j < y; j++)
            sqarr[i][j] = (y*y + 1) - sqarr[i][j];


    for ( i = 3 * y/4; i < y; i++)
        for ( j = 0; j < y/4; j++)
            sqarr[i][j] = (y*y+1) - sqarr[i][j];


    for ( i = 3 * y/4; i < y; i++)
        for ( j = 3 * y/4; j < y; j++)
            sqarr[i][j] = (y*y + 1) - sqarr[i][j];


    for ( i = y/4; i < 3 * y/4; i++)
        for ( j = y/4; j < 3 * y/4; j++)
            sqarr[i][j] = (y*y + 1) - sqarr[i][j];

    printSquare(sqarr,y);
}

void singlyEvenSquare(int y)
{

    int sqarr1[y/2][y/2],sqarr2[y/2][y/2],sqarr3[y/2][y/2],sqarr4[y/2][y/2];
    memset(sqarr1, 0, sizeof(sqarr1));
    memset(sqarr2, 0, sizeof(sqarr2));
    memset(sqarr3, 0, sizeof(sqarr3));
    memset(sqarr4, 0, sizeof(sqarr4));

    int i=0, j=y/4;
    for (int k=1; k<=(y*y)/4; ++k)
    {
        sqarr1[i][j] = k;

        i--;
        j++;

        if (k%(y/2) == 0)
        {
            i += 2;
            --j;
        }
        else
        {
            if (j==(y/2))
                j -= (y/2);
            else if (i<0)
                i += (y/2);
        }

    }
    for(int k=0;k<y/2;k++)
    {
        for(int q=0;q<y/2;q++)
        {
            sqarr2[k][q]=sqarr1[k][q]+(y/2)*(y/2);
            sqarr3[k][q]=sqarr2[k][q]+(y/2)*(y/2);
            sqarr4[k][q]=sqarr3[k][q]+(y/2)*(y/2);
        }

    }

    int chngstart = (y-2)/4;
    int chngend = chngstart-1;
    int t;

   for(int i=0;i<y/2;i++)
    {
        for(int j=0;j<chngstart;j++)
        {
            if((i==(y/4))&&j==0)
                continue;
            else
            {
                t=sqarr1[i][j];
                sqarr1[i][j]=sqarr4[i][j];
                sqarr4[i][j]=t;
            }
        }
    }

    t=sqarr1[chngstart][y/4];
    sqarr1[chngstart][y/4]=sqarr4[chngstart][y/4];
    sqarr4[chngstart][y/4]=t;

    for(int i=0;i<y/2;i++)
    {
        for(int j=(y/2)-chngend;j<y/2;j++)
        {
                t=sqarr3[i][j];
                sqarr3[i][j]=sqarr2[i][j];
                sqarr2[i][j]=t;
        }
    }

    int sqarr[y][y];
    memset(sqarr, 0, sizeof(sqarr));

    for(int i=0;i<y;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(i<y/2)
            {
                if(j<y/2)
                    sqarr[i][j]=sqarr1[i][j];

                else if(j>=y/2&&j<y)
                    sqarr[i][j]=sqarr3[i][j-(y/2)];

            }
            else if(i>=y/2&&i<y)
            {
                if(j<y/2)
                    sqarr[i][j]=sqarr4[i-(y/2)][j];

                else if(j>=y/2&&j<y)
                    sqarr[i][j]=sqarr2[i-(y/2)][j-(y/2)];

            }
        }
    }
    printSquare(sqarr,y);


}

void printTriangle(int arr1[],int arr2[],int arr3[],int y,int n,int s)
{
    for(int i=1;i<y;i++)
        {
            for(int j=1;j<=(y-i);j++)
                printf("  ");

            if(i==1)
            {
                printf(" 1\n");
                continue;
            }
            else
            {
                    printf("%2d",arr3[i-2]);

                    for(int k=1;k<=(2*i)-3;k++){
//                     if(i==((y/2)+1)&&(k==((2*i-3)/2+1)))
//                        printf("%d",s);
//                    else
                        printf("  ");
                    }

                    printf("%2d",arr1[i-2]);

            }
            printf("\n");
        }
        for(int i=0;i<y;i++){
                if(i==0)
                printf("%2d  ",arr2[i]);
                else
                printf("%2d  ",arr2[i]);
        }


}

void printSquare(int sqarr[][y], int y)
{
  for (int i=0; i<y; i++)
  {
    for (int j=0; j<y; j++)
      printf(" %3d", sqarr[i][j]);

    printf("\n");
  }

  printf("\n\n");
}
