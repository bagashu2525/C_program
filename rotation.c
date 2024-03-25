//WAP TO ROTATE AN ARRAY BY A GIVEN NUMBER OF POSITIONS.

#include <stdio.h>
#include <stdlib.h>

void rotation(int a[], int r, int n,int d){
	int temp,i,j;
	
	if(d){
		for(i=0;i<r;i++){
			temp=a[0];
			for(j=1;j<n;j++){
				a[j-1]=a[j];
			}
			a[n-1]=temp;
		}
	}
	else{
		for(i=0;i<r;i++){
			temp=a[n-1];
			for(j=n-1;j>=1;j--){
				a[j]=a[j-1];
			}
			a[0]=temp;
		}
	}

	
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
int main(){
	int arr[100],n,i,r,d;
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of an array:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("How many rotation do you want? ");
	scanf("%d",&r);
	printf("Mention the direction of rotation (1 for left and 0 for right): ");
	scanf("%d",&d);
	rotation(arr,r,n,d);
	
}
