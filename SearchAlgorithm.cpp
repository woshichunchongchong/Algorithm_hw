#include<iostream>
using namespace std;

int SequentialSearch(int a[],int value,int n);
int BinarySearch(int a[],int value,int left,int right);

int main(){
	int a[100010];
	int n;
	cout<<"请输入数组长度：";
	cin>>n;
	cout<<"请输入数组：";
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int value;
	cout<<"请输入要查找下标的数字："; 
	cin>>value;
	cout<<"通过顺序查找，数字的下标为: "<<SequentialSearch(a,value,n)<<endl;
	cout<<"通过二分查找，数字的下标为："<<BinarySearch(a,value,0,n-1)<<endl;
}

int SequentialSearch(int a[],int value,int n){
	for(int i=0;i<n;++i){
		if(value==a[i]){
			return i+1;
		}
	}
	return 0;
}

int BinarySearch(int a[],int value,int left,int right){
	int mid=(left+right)/2;
	if(left>right){
		return 0;
	}
	if(a[mid]>value){
		return BinarySearch(a,value,left,mid-1);
	}
	else if(a[mid]<value){
		return BinarySearch(a,value,mid+1,right);
	}
	else if(a[mid]==value){
		return mid+1;
	}
}
