#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#define MAX_SIZE 10000
using namespace std;

int select(int a[],int left,int right,int k) 
{
	int n=right-left;
	
	if (n<5){
		sort(a,a+n);
		return a[left+k-1];
	}
	
	int i,t=n/5,m[t];
	for(i=0;i<t;i++) {
		sort(a+left+i*5,a+left+i*5+5);
		m[i] = a[left+i*5+2];
	}
	sort(m,m+i);
	int mid=m[i/2];
	int a1[n],a2[n],a3[n];
	int s1=0,s2=0,s3=0;
	for(int i=left;i<right;i++){
		if(a[i]<mid){
			a1[s1++]=a[i];
		}
		else if(a[i]==mid){
			a2[s2++]=a[i];
		}
		else{
			a3[s3++]=a[i];
		}
	}
	if(s1>=k){
		return select(a1,0,s1,k);
	}
	if (s1+s2>=k){
		return mid;
	}
	else{
		return select(a3,0,s3,k-s1-s2);
	}		
}

int main(){
    int n,k;
    cout<<"请输入数组长度：";
    cin>>n;
    int a[n];
    cout<<"请输入数组：";
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	cout<<"请输入k：";
	cin>>k;
	printf("第%d小元素为%d",k, select(a,0,n,k));
    return 0;
}
