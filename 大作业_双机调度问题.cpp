#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
#include<list>
#define MAX_SIZE 500
using namespace std;

int plan = 1; //�������

int max(int x, int y); //�����ֵ 
int min(int x, int y); //����Сֵ 
int solve(int a[], int n); //�����ʱ�� 
void method(int a[], int sum, list<int> list1, list<int> list2, list<int> list3, int index, int n); //�������� 

int main() {
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
	list<int> list1; //����ʱ���Ϊ���ʱ���ÿ��ʱ�� 
	list<int> list2; //list1��ʱ���Ӧ�������� 
	list<int> list3; //1-n�������ţ������󲹼� 
	for (int i = 1; i <= n; ++i) {
		list3.push_back(i); 
	}
	method(a, ans, list1, list2, list3, -1, n);
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

void method(int a[], int sum, list<int> list1, list<int> list2, list<int> list3, int index, int n) {
	if (sum == 0) {
		cout << "����"<<plan<<"��"<<endl;
		plan++;

		//��list3Ϊȫ���������list2�Ĳ��� 
		list<int> list4;
		for (list<int>::const_iterator it = list3.begin(); it !=list3.end(); it++){
			if (!(find(list2.begin(), list2.end(), *it) != list2.end())) {
				list4.push_back(*it);
			}
		}

		list<int>::iterator itor = list2.begin();
		cout << "����Aִ�е�������Ϊ��";
		while (itor != list2.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;

		itor = list4.begin();
		cout << "����Bִ�е�������Ϊ��";
		while (itor != list4.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;
		
		cout << "����" << plan << "��" << endl;
		plan++;

		itor = list4.begin();
		cout << "����Aִ�е�������Ϊ��";
		while (itor != list4.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;

		itor = list2.begin();
		cout << "����Bִ�е�������Ϊ��";
		while (itor != list2.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;
	}
	else if (sum > 0) {
		for (int i = index + 1; i < n; ++i) {
			list1.push_back(a[i]);
			list2.push_back(i+1);
			method(a, sum - a[i], list1, list2, list3, i, n);
			list1.pop_back();
			list2.pop_back();
		}
	}
}
