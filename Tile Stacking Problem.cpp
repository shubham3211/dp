#include <iostream>
using namespace std;
int Mm,Mk;
int stackTile(int n,int m,int k){
	cout<<n<<" "<<m<<" "<<k<<endl;
	if(n==0){
		cout<<"Ans"<<endl;
		cout<<n<<" "<<m<<" "<<k<<endl;
		return 1;
	}
	if(m<=0){
		return 0;
	}
	int ans1=0;
	// ans1=stackTile(n-1,m+1,Mk);
	// // cout<<ans1<<" ";
	if(k!=0)	
	ans1+=stackTile(n-1,m,k-1);
	// // cout<<ans2<<endl;
	// return ans1+ans2;
	ans1+=stackTile(n,m-1,Mk);
	ans1+=stackTile(n-1,m-1,Mk);
	return ans1;
}
int main(){
	int n,m,k,ans=0;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the value of m";
	cin>>m;
	cout<<"Enter the value of k";
	cin>>k;
	Mm=m;
	Mk=k;
	ans=stackTile(n,Mm,Mk);
	cout<<ans;
}