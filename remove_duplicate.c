//WA FUNCTION TO REMOVE DUPLICATES FROM A SORTED ARRAY.

#include<stdio.h>
#include<stdlib.h>

int removeDup(int *a,int n,int *newarr){
	int i,c=n,j=0;
	
	for(i=0;i<n-1;i++){
		if(a[i]!=a[i+1]){
			newarr[j]=a[i];
			j++;
		}
		
	}
	newarr[j]=a[n-1];
	j++;
	return j;
	
}
int main(){
	int arr[100],n,i, newarr[100];
	printf("Enter the size of the sorted array:");
	scanf("%d",&n);
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int index=removeDup(arr,n,newarr);
	
	for(i=0;i<index;i++){
		printf("%d",newarr[i]);
	}
}
