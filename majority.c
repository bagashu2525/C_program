//IMPLEMENT AN ALGORITHM TO FIND THE MAJORITY ELEMENT OF THE ARRAY

#include<stdio.h>
#include<stdlib.h>
int checkCount(int *arr,int key,int n){
	int count=0,i;
	for(i=0;i<n; i++){
		if(arr[i]==key) ++count;
	}
	return count;
}
int main(){
	int arr[100],n,i,j,max=0,maxIndex;
	printf("Enter the size of the sorted array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++){
		int count=checkCount(arr,arr[i],n);
		if(max<count){
			max=count;
			maxIndex=arr[i];
		} 
	}
	printf("The majority element is %d and it is present %d times",maxIndex,max);
}
