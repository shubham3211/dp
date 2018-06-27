#include <iostream>
#include <utility>
using namespace std;
typedef pair<bool,int> pi;
pi donations(int *heights,int n){
	
}
int main(){
	int n,heights[100];
	pi ans;
	cout<<"Enter the no of temples";
	cin>>n;
	cout<<"Enter the heights";
	for(int i=0;i<n;i++){
		cin>>heights[i];
	}
	ans=donations(heights,n);
	cout<<ans.second;
}