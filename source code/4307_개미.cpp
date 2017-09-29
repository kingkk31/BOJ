#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int l, n;
		cin >> l >> n;
		
		vector<int> ant;
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			ant.push_back(a);
		}
		
		int maxi = 0, mini = 0;

		if (l - ant[0] >= ant[0]) {
			maxi = l - ant[0];
			mini = ant[0];
		}
		else if (l - ant[0] < ant[0]) {
			mini = l - ant[0];
			maxi = ant[0];
		}
				
		for (int j = 1; j < ant.size(); j++) {
			maxi = max(maxi, max(l - ant[j], ant[j]));
			mini = max(mini, min(l - ant[j], ant[j]));
		}

		cout << mini << " " << maxi << endl;
	}
}
