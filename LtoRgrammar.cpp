#include<bits/stdc++.h>

using namespace std;

int main() {
	map < char, vector<string> > prod;
	int n;
	cout << "Enter number of productions : ";
	cin >> n;
	cout << "Enter productions : " << endl;
	for (int i = 0; i < n; i++) {
		char ch;
		string s;
		cin >> ch;
		cout << " -> ";
		cin >> s;
		prod[ch].push_back(s);
	}
	cout << "Given grammar is :" << endl << endl;
	for (auto i : prod) {
		cout << i.first << " -> ";
		vector<string>& vs = i.second;
		for (int j = 0; j < vs.size(); j++) {
			cout << vs[j];
			if (j != vs.size() - 1)
				cout << " | ";
		}
		cout << endl;
	}
	for (auto itr : prod) {
		vector<string> alpha, beta;
		vector<string>& vs = itr.second;
		for (int i = 0; i < vs.size(); i++) {
			if (itr.first == vs[i][0]) {
				alpha.push_back(vs[i].substr(1, vs[i].size() - 1));
			}
			else {
				beta.push_back(vs[i]);
			}
		}
		if (alpha.size() < 1)
			continue;
		vs.clear();
		char ch = 'A' + prod.size();
		for (int i = 0; i < beta.size(); i++) {
			vs.push_back(beta[i] + ch);
		}
		for (int i = 0; i < alpha.size(); i++) {
			prod[ch].push_back(alpha[i] + ch);
		}
		prod[ch].push_back("^");
	}
	cout << "Output Grammar is :" << endl << endl;

	for (auto i : prod) {
		cout << i.first << " -> ";
		vector<string>& vs = i.second;
		for (int j = 0; j < vs.size(); j++) {
			cout << vs[j];
			if (j != vs.size() - 1)
				cout << " | ";
		}
		cout << endl;
	}
}
