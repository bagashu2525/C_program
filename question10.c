//IMPLEMENT AN ALGORITH TO SEARCH FOR AN ELEMENT IN SORTED AND ROTATED ARRAY(ROTATED BINARY SEARCH).

#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[100],n,i,flag=0;
	int mid,lower=0,higher,key;
	
	printf("Enter the size of the array:");
	scanf("%d",&n);
	
	printf("Enter the elements:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	
	printf("Enter the element to searched:");
	scanf("%d",&key);
	
	higher=n-1;
	while(lower<=higher){
		mid=(lower+higher)/2;
		if(a[mid]==key){
			flag=1;
			break;
		}
		else if(a[mid]>=a[lower]){
			if(a[lower]<=key && key<=a[mid]){
				higher=mid-1;
			}
			else{
				lower=mid+1;
			}
		}
		else{
			if(a[higher]>=key && key>=a[mid]){
				lower=mid+1;
				
			}
			else{
				higher=mid-1;
			}
		}
	}
	if(flag==1)
		printf("The index of the searched element is %d",mid);
	else
		printf("The element is absent");
}
