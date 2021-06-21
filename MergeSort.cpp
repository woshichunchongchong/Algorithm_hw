#include<iostream>
#include<string.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))
using namespace std;

void merge(int a[],int start,int mid,int end){
	int left[mid-start+1];
	int right[end-mid];
	int leftt=0,rightt=0;
	for(int i=start;i<=mid;++i){
		left[leftt++]=a[i];
	}
	for(int i=mid+1;i<=end;++i){
		right[rightt++]=a[i];
	}
	int i=0,j=0,flag=start;
	while(i<ARRAY_SIZE(left) && j<ARRAY_SIZE(right)){
		if(left[i]<right[j]){
			a[flag++]=left[i++];
		}
		else{
			a[flag++]=right[j++];
		}
	}
	while(i<ARRAY_SIZE(left)){
		a[flag++]=left[i++];
	}
	while(j<ARRAY_SIZE(right)){
		a[flag++]=right[j++];
	}
}

void mergesort(int a[],int start,int end){
	if(start<end){
		int mid=start+(end-start)/2;
		mergesort(a,start,mid);
		mergesort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}



int main(){
	int n,start=0,end;
	int a[100010];
	cout<<"输入数组长度：";
	cin>>n;
	end=n-1;
	cout<<"输入数组：";
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	mergesort(a,start,end);
	cout<<"经过二分归并排序后的数组为："<<endl;
	for(int i=0;i<n;++i){
		cout<<a[i]<<" ";
	} 
	cout<<endl;
}
