#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int dp[MAX_SIZE][MAX_SIZE]; 
char s1[MAX_SIZE],s2[MAX_SIZE];

int main() {
	cout<<"请输入两个字符串，回车分隔：" ;
	cin>>s1+1;
	cin>>s2+1;
	int len1=strlen(s1+1),len2=strlen(s2+1);
	
	//初始化 
	for(int i=0;i<=len1;++i){
		dp[i][0]=0;
	}
	
	for(int i=0;i<=len2;++i){
		dp[0][i]=0;
	}
	
	for(int i=1;i<=len1;++i){
		for(int j=1;j<=len2;++j){
			if(s1[i]==s2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				if(dp[i-1][j]>dp[i][j-1]){
					dp[i][j]=dp[i-1][j];
				} 
				else{
					dp[i][j]=dp[i][j-1];
				}
			}
		}
	}
	cout<<"最长公共子序列长度为："<<dp[len1][len2]<<endl;
	return 0;
}
