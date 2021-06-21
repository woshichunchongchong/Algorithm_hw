#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n,m;
int dp[MAX_SIZE][MAX_SIZE]; //��jԪͶ��ǰi������� 
int val[MAX_SIZE][MAX_SIZE]; 

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			cin>>val[i][j];    //Ͷ��i��jԪ��õ����� 
		}
	}
	
	//dp
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=j;k++){
				if(dp[i][j]<dp[i-1][j-k]+val[i][k]){
					dp[i][j]=dp[i-1][j-k]+val[i][k];  
				}
			}
		}
	}
	cout<<"�������Ϊ��"<<dp[n][m]<<endl; 
}
