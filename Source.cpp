#include <vector>
#include <iostream>

#define INF 1000 * 1000 * 1000

using namespace std;

vector<vector<double> > a;
vector<bool> used;
vector<double> ans;
vector<int> last;

void pa() {
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\t";
	cout << endl;
}

void dx(int bg) {
	for (int i = 0; i < a.size(); i++) {
		if (!used[i] && a[bg][i] != 0 && ans[i] > a[bg][i] + ans[bg]) {
			ans[i] = a[bg][i] + ans[bg];
			last[i] = bg;
		}
	}
	used[bg] = 1;
	pa();

	int ind = -1; double min = INF;
	for (int i = 0; i < a.size(); i++) {
		if (!used[i] && (ind == -1 || ans[i] < min)) {
			ind = i;
			min = ans[i];
		}
	}

	for (int i = 0; i < last.size(); i++) {
		cout << last[i] << "\t";
	}
	cout << " : way" << endl;

	if (ind == -1) {
	}
	else {
		dx(ind);
	}
}

void main() {
	int n;
	cout << "input n" << endl;
	cin >> n;
	a.resize(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] < 0) exit(0);
		}
	}

	used.resize(n, 0);
	ans.resize(n, INF);
	int begin;
	cout << "input begin" << endl;
	cin >> begin;

	ans[begin] = 0;
	used[begin] = 1;
	last.resize(n, -1);

	dx(begin);
	system("pause");
}