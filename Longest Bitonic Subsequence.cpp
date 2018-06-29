#include <iostream>
#include <vector>
using namespace std;
int n;
int lonestBitonic(int arr[],int lastEle,int status,int pos){
	if(pos==n){
		return 0;
	}
	int ans=0;
	if(status && arr[pos]>lastEle){
		ans=1+lonestBitonic(arr,arr[pos],1,pos+1);
	}else if(arr[pos]<lastEle){
		ans=1+lonestBitonic(arr,arr[pos],0,pos+1);
	} else {
		ans=lonestBitonic(arr,arr[pos],status,pos+1);
	}
	return ans;
}
int lonestBitonicDp(int arr[]){
	int lis[700],lds[700];
	std::vector<int> ldsv[100],lisv[100];
	for(int i=0;i<n;i++){
		lis[i]=1;
		lds[i]=1;
		lisv[i].push_back(arr[i]);
		ldsv[i].push_back(arr[i]);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
				lisv[i]=lisv[j];
				lisv[i].push_back(arr[i]);
			}
		}
	}
	for(int i=n-2;i>=0;i--){
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j] && lds[i]<lds[j]+1){
				lds[i]=lds[j]+1;
				ldsv[i]=ldsv[j];
				ldsv[i].push_back(arr[i]);
			}
		}
	}
	int ans=0,pos;
	for(int i=0;i<n;i++){
		if(lis[i]+lds[i]-1>ans){
			ans=lis[i]+lds[i]-1;
			pos=i;
		}
	}
	for(std::vector<int>::iterator it=lisv[pos].begin();it!=lisv[pos].end();it++){
		cout<<*it<<" ";
	}
	ldsv[pos].pop_back();
	for(std::vector<int>::iterator it=ldsv[pos].end()-1;it>=ldsv[pos].begin();it--){
		cout<<*it<<" ";
	}
	cout<<endl;
	return ans;
}
int main(){
	int arr[100],ans=0;
	cout<<"Enter the number of elements";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// ans=lonestBitonic(arr,0,1,0);
	ans=lonestBitonicDp(arr);
	cout<<ans<<endl;
}