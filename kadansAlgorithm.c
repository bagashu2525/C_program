//WA FUNCTION TO FIND THE CONTIGUOUS SUBARRAY WITH THE LARGEST SUM.(KADAN'S ALGORITH)

#include<stdio.h>
#include<stdlib.h>

void subarray(int arr[],int n,int *max,int *ans_start,int *ans_end){
	int i,sum=0,start;
	for(i=0;i<n;i++){
		if(sum==0){
			start=i;
		}
		sum+=arr[i];
		if(*max<sum){
			*max=sum;
			*ans_start=start;
			*ans_end=i;
		}
		if(sum<0){
			sum=0;
		}
	}

}
int main(){
	int a[100],n,i,max=-9999,start,end;
	
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	printf("Enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	subarray(a,n,&max,&start,&end);
	printf("The largest sum of the subarray is: %d\n",max);
	printf("The subarray is: \n");
	for(i=start;i<=end;i++){
		printf("%d ",a[i]);
	}
	
	
}


