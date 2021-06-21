#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n, m;
int dp[MAX_SIZE][MAX_SIZE]; //乘积Ai...j所用的最少基本运算次数
int pos[MAX_SIZE][MAX_SIZE];  //最后一次乘法运算的位置
int p[MAX_SIZE];

int main() {
	cout << "n的值：";
	cin >> n;
	cout << "请输入向量p的元素：";
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	//dp 迭代 
	for (int i = 1; i < n; i++) {
		dp[i][i] = 0;
	}
	for (int m = 2; m < n; m++) {
		for (int i = 1; i < n - m + 1; i++) {
			int j = i + m - 1;
			dp[i][j] = dp[i + 1][j] + p[i - 1] * p[i] * p[j];
			pos[i][j] = i;
			for (int k = i; k <= j - 1; k++) {
				int tmp = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (tmp < dp[i][j]) {
					dp[i][j] = tmp;
					pos[i][j] = k;
				}
			}
		}
	}

	cout << "乘积为：" << dp[1][n - 1] << endl;
	cout << "最小次数为：" << pos[1][n - 1] << endl;
}
