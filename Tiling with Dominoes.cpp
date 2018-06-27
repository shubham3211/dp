#include <iostream>
using namespace std;
int count(int n){
	int a[100],b[100];
	a[0] = 1,a[1] = 0,b[0] = 0,b[1] = 1;
	for(int i=2;i<=n;i++){
		a[i] = a[i-2] + 2*b[i-1];
		b[i] = a[i-1] + b[i-2];
	}
	// return a[n];
}
// int countRecur(int n,char type){	
// 	if(n == 0 && type == 'b' || n == 1 && type == 'a'){
// 		return 0;
// 	}
// 	if(n == 0 && type == 'a' || n == 1 && type == 'b'){
// 		return 1;
// 	}
// 	int a,b;
// 	a = countRecur(n-2,'a') + 2*countRecur(n-1,'b');
// 	return a;
// }
int main(){
	int n,ans;
	cout<<"enter the value of n";
	cin>>n;
	ans = countRecur(n,'a');
	cout<<"No of Ways are"<<ans;
}