#include <iostream>
using namespace std;
int max_sum(int *arr,int n){
	int maxEndingHere=0,maxTillNow=0,length=0,max_length=0;
	for(int i=0;i<n;i++){
		maxEndingHere+=arr[i];
		length++;
		if(maxEndingHere<0){
			maxEndingHere=0;
			length=0;
		}
		if(maxEndingHere>maxTillNow){
			maxTillNow=maxEndingHere;
			max_length=length;
		}
	}
	return max_length;
}
int main(){
	int n,arr[100],ans=0;
	cout<<"Enter the number of elements";
	cin>>n;
	cout<"Enter the elements";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	ans=max_sum(arr,n);
	cout<<ans;
}