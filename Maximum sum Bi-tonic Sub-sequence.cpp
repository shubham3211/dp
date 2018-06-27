#include <iostream>
#include <climits>
using namespace std;
int maxSumBitonic(int arr[],int n,int pos,int maximum,int minimum,int max_mode,int sum){
	if(pos==n){
		return sum;
	}
	int sum1=0,sum2=0,sum3=0;
	sum1=maxSumBitonic(arr,n,pos+1,maximum,minimum,max_mode,sum);
	if(max_mode&&arr[pos]>maximum){
		sum2=maxSumBitonic(arr,n,pos+1,arr[pos],minimum,max_mode,sum+arr[pos]);
	} else if(arr[pos]<minimum){
		sum3=maxSumBitonic(arr,n,pos+1,maximum,arr[pos],0,sum+arr[pos]);
	}
	return max(sum1,max(sum2,sum3));
}
int maxSumBitonicDp(int arr[],int n){
	int dpi[100]={0},dpd[100]={0},maximum=0;
	for(int i=0;i<n;i++){
		dpi[i]=dpd[i]=arr[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]&&dpi[j]+arr[i]>dpi[i]){
				dpi[i]=arr[i]+dpi[j];
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j]&&dpd[j]+arr[i]>dpd[i]){
				dpd[i]=arr[i]+dpd[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		maximum=max(maximum,dpi[i]+dpd[i]-arr[i]);
	}
	return maximum;

}
int main(){
	int arr[100],n,ans=0;
	cout<<"Enter the length";
	cin>>n;
	cout<<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=maxSumBitonicDp(arr,n);
	cout<<ans;
}