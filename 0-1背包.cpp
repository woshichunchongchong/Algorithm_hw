#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
#include<list>
#define MAX_SIZE 500
using namespace std;


int max(int x, int y); //�����ֵ 
int min(int x, int y); //����Сֵ 
int solve(int a[], int n); //�����ʱ�� 

int main(){
	int n; //��������
	int a[MAX_SIZE]; //���ÿ��������Ҫ��ʱ��
	int ans; //���ʱ��
	cout << "����������������";
	cin >> n;
	cout << "���������ÿ��������Ҫ��ʱ�䣨�ÿո�ֿ�����";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ans = solve(a, n);
	cout << "��̨�������ȫ����������ʱ��Ϊ��" << ans << endl;
	return 0;
}

int max(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

int min(int x, int y) {
	if (x > y) {
		return y;
	}
	else {
		return x;
	}
}

int solve(int a[], int n) {
	int totle_time = 0; //����������ʱ��
	int dp[MAX_SIZE][MAX_SIZE]; //B������������ʱ�� 
	int time[MAX_SIZE]; //���ʱ�� 
	for (int i = 0; i < n; ++i) {
		totle_time += a[i]; //��������������ʱ�� 
	}

	//��ִ�е�1������ʱ����� 
	for (int j = 0; j < totle_time + 1; ++j) {
		if (j < a[0]) {
			dp[0][j] = a[0];
		}
		else {
			dp[0][j] = 0;
		}
	}

	//��ִ�е�2�����һ������ʱ����� 
	for (int i = 1; i < n; ++i) {
		time[i] = INT_MAX;
		for (int j = 0; j < totle_time + 1; ++j) {
			if (j < a[i]) {
				dp[i][j] = dp[i - 1][j] + a[i];  //��ִ�е�ʱ��jС��A��������ʱ��ʱ����ΪB����ִ�е�i+1������ 

			}
			else {
				dp[i][j] = min(dp[i - 1][j] + a[i], dp[i - 1][j - a[i]]); //��B����ִ�п죬��ѡ������һ�е�ʱ���ϼ��ϵ�i+1��������Ҫ��ʱ�䣬������A����ִ�� 
			}
			time[i] = min(time[i], max(j, dp[i][j]));
		}
	}
	
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < totle_time + 1; ++j) {
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	return time[n - 1];
}
