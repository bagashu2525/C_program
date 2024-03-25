//CREATE A PROGRAM TO FIND THE INTERSECTION OF TWO ARRAYS.
#include<stdio.h>

int main(){
	int arr1[100],arr2[100],n1,n2,i,j;
	int intersection[100],inter=0;
	printf("Enter the size of array1: ");
	scanf("%d",&n1);
	printf("Enter the elements of a array:\n");
	for(i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter the size of array2: ");
	scanf("%d",&n2);
	printf("Enter the elements of a array:\n");
	for(i=0;i<n2;i++){
		scanf("%d",&arr2[i]);
	}
	
	//intersection
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			if(arr1[i]==arr2[j]){
				intersection[inter]=arr1[i];
				inter++;
				break;
			}
		}
	}
	if(inter>0){
		printf("The intersection of the arrays: \n");
		for(i=0;i<inter;i++){
			printf("%d ",intersection[i]);
		}
	}else{
		printf("There is no intersection");
	}	
}
