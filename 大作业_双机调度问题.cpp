#include<iostream>
#include<algorithm>
#include<string.h>
#include<limits.h>
#include<list>
#define MAX_SIZE 500
using namespace std;

int plan = 1; //方案编号

int max(int x, int y); //求最大值 
int min(int x, int y); //求最小值 
int solve(int a[], int n); //求最短时间 
void method(int a[], int sum, list<int> list1, list<int> list2, list<int> list3, int index, int n); //求解决方案 

int main() {
	int n; //任务数量
	int a[MAX_SIZE]; //完成每项任务需要的时间
	int ans; //最短时间
	cout << "请输入任务总数：";
	cin >> n;
	cout << "请输入完成每项任务需要的时间（用空格分开）：";
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ans = solve(a, n);
	cout << "两台机器完成全部任务的最短时间为：" << ans << endl;
	list<int> list1; //满足时间和为最短时间的每个时间 
	list<int> list2; //list1中时间对应的任务编号 
	list<int> list3; //1-n的任务编号，用于求补集 
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
	int totle_time = 0; //所有任务共需时间
	int dp[MAX_SIZE][MAX_SIZE]; //B机器所需的最短时间 
	int time[MAX_SIZE]; //最短时间 
	for (int i = 0; i < n; ++i) {
		totle_time += a[i]; //计算所有任务共需时间 
	}

	//当执行第1个任务时的情况 
	for (int j = 0; j < totle_time + 1; ++j) {
		if (j < a[0]) {
			dp[0][j] = a[0];
		}
		else {
			dp[0][j] = 0;
		}
	}

	//当执行第2至最后一个任务时的情况 
	for (int i = 1; i < n; ++i) {
		time[i] = INT_MAX;
		for (int j = 0; j < totle_time + 1; ++j) {
			if (j < a[i]) {
				dp[i][j] = dp[i - 1][j] + a[i];  //当执行的时间j小于A机器所需时间时，认为B机器执行第i+1个任务 

			}
			else {
				dp[i][j] = min(dp[i - 1][j] + a[i], dp[i - 1][j - a[i]]); //若B机器执行快，则选择在上一行的时间上加上第i+1个任务需要的时间，否则令A机器执行 
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
		cout << "方案"<<plan<<"："<<endl;
		plan++;

		//以list3为全集，求关于list2的补集 
		list<int> list4;
		for (list<int>::const_iterator it = list3.begin(); it !=list3.end(); it++){
			if (!(find(list2.begin(), list2.end(), *it) != list2.end())) {
				list4.push_back(*it);
			}
		}

		list<int>::iterator itor = list2.begin();
		cout << "机器A执行的任务编号为：";
		while (itor != list2.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;

		itor = list4.begin();
		cout << "机器B执行的任务编号为：";
		while (itor != list4.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;
		
		cout << "方案" << plan << "：" << endl;
		plan++;

		itor = list4.begin();
		cout << "机器A执行的任务编号为：";
		while (itor != list4.end()) {
			cout << *itor++ << " ";
		}
		cout << endl;

		itor = list2.begin();
		cout << "机器B执行的任务编号为：";
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
