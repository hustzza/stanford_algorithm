#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long int runcount = 0;
void Merge(int A[],int TmpArray[],int lpos,int rpos,int rightend)
{
	int i,leftend,numint,tmppos;

	leftend = rpos - 1;
	tmppos = lpos;
	numint = rightend - lpos + 1;
	while (lpos <=leftend && rpos<=rightend)
		if(A[lpos]<=A[rpos])
		{
			TmpArray[tmppos++] = A[lpos++];
		}
		else
		{
			TmpArray[tmppos++] = A[rpos++];
			runcount += (leftend+1-lpos);
		}
	while(lpos<=leftend) 
		TmpArray[tmppos++] = A[lpos++];
	while(rpos<=rightend)
		TmpArray[tmppos++]=A[rpos++];
	for(i=0;i<numint;i++,rightend--)
		A[rightend] = TmpArray[rightend];
	
}
void MSort(int A[],int TmpArray[],int left,int right)
{
	int center;

	if(left<right)
	{
		center = (left+right)/2;
		MSort(A,TmpArray,left,center);
		MSort(A,TmpArray,center+1,right);
 		Merge(A,TmpArray,left,center+1,right);
	}
}
void Mergesort(int A[],int N)
{
	int* TmpArray;
	int i;
	TmpArray = (int*)malloc(N*sizeof(int));
	if(TmpArray != NULL)
	{
		MSort(A,TmpArray,0,N-1);
 		
		free(TmpArray);
	}
	else
		printf("No space for tmp array!!!");
}
int main()
{
	FILE* fp;
	char a[10];
	int data[100000]; 
	int i;
	fp=fopen("IntegerArray.txt","r");
	if(fp!=NULL)
	{
		for(i=0;i<100000;i++)
		{
		fgets(a,1000,fp);
		data[i]=atoi(a);
		}
	}
	else
		printf("Error");
	    
	Mergesort(data,sizeof(data)/4);
	printf("%u",runcount);
	getchar();
	return 0;
}
