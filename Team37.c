
// Name: Y.S.P Sandeep   Id: 2021A7PS3113H
// Name: P.Manoj         Id: 2021A7PS2629H

#include<stdio.h>
#include<stdbool.h>
int main(int argc,char *argv[])
{
    FILE * fPointer;
    fPointer=fopen(argv[1],"r");
   int edges=0;
   int nodes=0;
   fscanf(fPointer,"%d",&nodes);
   fscanf(fPointer,"%d",&edges);
   int adjmatrix[nodes][nodes];
   int totalEdges=2*edges;
   int storeEdges[totalEdges];
   int degree[nodes];
   int temp=0;

// initializing degree,storeEdges, adjmatrix values to zeros

for(int i=0;i<=nodes-1;i++)
{
   degree[i]=0;
}
for(int i=0;i<=totalEdges-1;i++)       
{
    storeEdges[i]=0;
}
for(int i=0;i<=nodes-1;i++)
{
   for(int j=0;j<=nodes-1;j++)
   {
      adjmatrix[i][j]=0;
   }
}
int i=0;
while(1)
{
   if(fscanf(fPointer,"%d",&temp)==1)
   
   {
      storeEdges[i]=temp;
      i++;
   }
   else
   {
      break;
   }
}

// traversing the adjacency matrix.

for(int i=0;i<=totalEdges-1;i+=2)
{
   adjmatrix[storeEdges[i]-1][storeEdges[i+1]-1]=1;
}

for(int i=0;i<=nodes-1;i++)
{
   for(int j=0;j<=nodes-1;j++)
   {
      degree[i]+=adjmatrix[i][j]+adjmatrix[j][i];
   }

}

// sorting in a non-increasing order

int largest=0;
int remember=0;
for(int i=0;i<=nodes-1;i++)
{int temp=0;
for(int j=i;j<=nodes-1;j++)
{
 if(degree[j]>largest)
 {largest=degree[j];
  remember=j;}
}
temp=degree[i];
degree[i]=largest;
degree[remember]=temp;
largest=0;

 
}
for(int i=0;i<=nodes-1;i++)
{
   printf("%d",degree[i]);
}
}