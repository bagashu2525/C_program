//IMPLEMENT AN ALGORITHM TO FIND THE MISSING NUMBER IN AN ARRAY OF INTEGERS FROM 1 TO N

#include <stdio.h>
#include <stdlib.h>

int missing(int a[], int n){
	int miss=((n+1)*(n+2))/2;
	int i;
	for(i=0;i<n;i++){
		miss-=a[i];
	}
	return miss;
}
int main(){
	int arr[100],n,i,temp,missing_num;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements range from 1 to %d a array:\n",n+1);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	missing_num=missing(arr,n);
	printf("The missing number is: %d",missing_num);
}
