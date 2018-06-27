#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;
int lis(int *arr,int length,int maximum,int pos){
	int ans=0,l1=0,l2=0;
	if(pos==length){
		return 0;
	}
	l1=lis(arr,length,maximum,pos+1);
	if(arr[pos]>maximum){
		l2=1+lis(arr,length,arr[pos],pos+1);
	}
	return max(l1,l2);
}
int lisDp(int arr[],int n){
	int dp[100]={0};
	memset(dp,1,sizeof(dp));
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
	}
	cout<<"Max elment is "<<*max_element(dp,dp+n);
}
int main(){
	int length,arr[100],ans=0;
	cout<<"Enter the length";
	cin>>length;
	cout<<"Enter the elements";
	for(int i=0;i<length;i++){
		cin>>arr[i];
	}
	lisDp(arr,length);
	
}