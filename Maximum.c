//WAP TO FIND THE MAXIMAM ELEMENT OF THE ARRAY
#include<stdio.h>

int main(){
	int arr[100],n,i,max=0;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of a array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	for(i=0;i<n;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	printf("The maximum number in an array is: %d",max);
	return 0;
}
