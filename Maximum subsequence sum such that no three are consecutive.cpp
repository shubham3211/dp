#include <iostream>
#include <algorithm>
using namespace std;
int max_sum(int *arr,int n,int pos,int sum,int cons,int lastPos){
	int sum1=0,sum2=0;
	if(pos==n){
		return sum;
	}
	sum1=max_sum(arr,n,pos+1,sum,1,lastPos);
	if(!(abs(lastPos-pos)==1&&cons==3)){
		sum2=max_sum(arr,n,pos+1,sum+arr[pos],cons+1,pos);
	}
	return max(sum1,sum2);
}
int max_sum_Dp(int *arr,int n){
	int sum[100]={0},sum1,sum2,sum3;
	sum[1]=arr[0];
	sum[2]=arr[1]+sum[1];
	for(int i=3;i<=n;i++){
		sum1=sum[i-1];
		sum2=sum[i-2]+arr[i-1];
		sum3=sum[i-3]+arr[i-1]+arr[i-2];
		sum[i]=max(sum1,max(sum2,sum3));
	}
	return sum[n];
}
int main(){
	int n,arr[100],ans=0;
	cout<<"Enter the value of n";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=max_sum_Dp(arr,n);
	cout<<ans;
}