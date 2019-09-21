//Insertion Sort------prolonged swapping
#include<stdio.h>
int main()
{
 int i,j,temp,arr[]={ 25,17,31,13,2 };
 for( i=0 ; i<5 ; i++ )
 {
  if(arr[0]>arr[i])
   {
   	 temp=arr[i];
     for(j=i;j>0;j--)
     arr[j]=arr[j-1];
     arr[0]=temp;	
   	
   }
}
   	for(i=0;i<5;i++)
   	printf("%d ",arr[i]);
   	return 0 ;
}

//-----> Bubble Sort
//-----> Selection Sort
//-----> Insertion Sort
//-----> Merge Sort
//-----> Quick Sort
