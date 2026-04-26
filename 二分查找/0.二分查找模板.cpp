#include<iostream>
#include<vector>
using namespace std;
vector<int>arr;
//¶ş·Ö²éÕÒ

int findMinGreenIndex(vector<int>& arr, int target) {
	int l = -1, r = arr.size();
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		if (arr[mid] >= target) {
			r = mid;
		}
		else {
			l = mid;
		}
	}

	return r;
}