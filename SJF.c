#include <stdio.h>
int main()
{
   int n;
   printf("Enter the no of processes\n");
   scanf("%d",&n);
   int a[n];
   int b[n],c[n],t[n],w[n];
   printf("Enter arrival times\n");
   for(int i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
    printf("Enter burst times\n");
   for(int i=0;i<n;i++)
   {
      scanf("%d",&b[i]);
   }
   for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
    {
    	if(a[j]==0)
    	continue;
         
       else if(b[j]>b[j+1])
       {
          int temp=b[j];
          b[j]=b[j+1];
          b[j+1]=temp;
          int k=a[j];
          a[j]=a[j+1];
          a[j+1]=k;
        }
        }
        }
     c[0]=b[0]+a[0];   
    for(int i=1;i<n;i++)
    {
           c[i]=c[i-1]+b[i];
          }
   for(int i=0;i<n;i++)
   {
   	t[i]=c[i]-a[i];
   }
   for(int i=0;i<n;i++)
   {
        w[i]=t[i]-b[i];
   }
   printf("arrivaltime\tbursttime\tcompletiontime\tturnaroundtime\twaitingtime\t\n");
   for(int i=0;i<n;i++)
   {
      printf("%d\t\t%d\t\t%d\t\t\t%d\t%d\n",a[i],b[i],c[i],t[i],w[i]);
   }
   return 0;
   }
