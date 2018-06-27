#include <iostream>
#include <vector>
using namespace std;
void check(char ch[]){
	ch[0] = 's';
}
void changeVector(int &a){
	a = 2;
}
int main(){
	std::vector<int> v;
	int a = 5;
	// // float b;
	// // b = (float)5/2;
	// // cout<<b;
	// int a[10]={1},*p;
	// // p=A;s
	// // cout<<p;
	// int b[5][5];
	// for(int i=0;i<5;i++)
	// {
	// 	for(int j=0;j<5;j++){
	// 		b[i][j] = 0;
	// 	}
	// }
	// cout<<"a"<<endl;
	// cout<<a<<" "<<*a<<endl;
	// cout<<"b"<<endl;
	// cout<<b+1<<" "<<*(b+1)<<endl;
	// // cout<<"b[0]"<<b[0];
	// char ch[29];
	// ch[0]='d';
	// check(ch);
	// cout<<ch[0];
	changeVector(a);
	cout<<a;
}