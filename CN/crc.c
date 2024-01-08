#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[]="10011";
int e,c,a,i,n;

void xor()
{
    for(n = 1;n < N; n++)
        cs[n] = (( cs[n] == g[n])?'0':'1');
}

void crc()
{
    for(i=0;i<N;i++)
        cs[i]=t[i];
    do
    {
        if(cs[0]=='1')
            xor();
        for(c=0;c<N-1;c++)
            cs[c]=cs[c+1];
        cs[c]=t[i++];
    }while(i<=a+N-1);
}


int main()
{
    printf("\nEnter data : ");
    scanf("%s",t);
    printf("\n----------------------------------------");
    printf("\nGenerating polynomial : %s",g);
    a=strlen(t);
    for(i=a;i<a+N-1;i++)
        t[i]='0';
    printf("\n----------------------------------------");
    printf("\nModified data is : %s",t);
    printf("\n----------------------------------------");
    crc();
    printf("\nChecksum is : %s",cs);
    for(i=a;i<a+N-1;i++)
        t[i]=cs[i-a];
    printf("\n----------------------------------------");
    printf("\nFinal codeword is : %s",t);
    printf("\n----------------------------------------");
    printf("\nTest error detection 0(yes) 1(no)? : ");
    scanf("%d",&e);
    if(e==0)
    {
        printf("\nEnter the position where error is to be inserted : ");
        scanf("%d",&e);
        t[e-1]=(t[e-1]=='0')?'1':'0';
        printf("\n----------------------------------------");
        printf("\nErroneous data : %s\n",t);
        crc();
        for(i=0;(i<N-1) && (cs[i]!='1');i++);
        if(i<N-1)
            printf("\nError detected\n\n");
        else
            printf("\nNo error detected\n\n");
        printf("\n----------------------------------------\n");
    }
    return 0;
}