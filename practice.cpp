#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, M;
	cin >> n >> M;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int freq[101] = {0};//for frequency array
	int count = 0;
	int total = 0, x = 0, y;
	for(int i = 0; i < n; i++) {
		x = total - M + arr[i];
		cout << "total: " << total << endl;
		count = 0;
		if(x > 0) {
			for(int j = 100; j > 0; j--) {
				y = freq[j] * j;
				if(x <= y) {
					count += (x + j - 1) / j;
					cout << count << endl;
					break;
				}
				count += freq[j];
				x = x - y;
			}
		}
		freq[arr[i]]++;
		total += arr[i];
		cout << count << " ";
	}
}