#include<iostream>
#include<string.h>
#include<algorithm>
#define MAX_SIZE 100
using namespace std;

int n, m;
int dp[MAX_SIZE][MAX_SIZE]; //�˻�Ai...j���õ����ٻ����������
int pos[MAX_SIZE][MAX_SIZE];  //���һ�γ˷������λ��
int p[MAX_SIZE];

int main() {
	cout << "n��ֵ��";
	cin >> n;
	cout << "����������p��Ԫ�أ�";
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	//dp ���� 
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

	cout << "�˻�Ϊ��" << dp[1][n - 1] << endl;
	cout << "��С����Ϊ��" << pos[1][n - 1] << endl;
}
