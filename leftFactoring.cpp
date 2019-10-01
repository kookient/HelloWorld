#include <bits/stdc++.h>
using namespace std;

//E->aE+bcD|aE+cBD
class Production {
public:
	vector<string> vs;
	string left;

	Production(string s) {
		int i;
		for (i = 0; i < s.size() - 1; i++) {
			if (s[i] == '-' && s[i + 1] == '>') {
				break;
			}
		}
		left = s.substr(0, i);

		s = s.substr(i + 2, s.size());

		// cout << s << " " << left << "\n";
		char* tt = new char[s.size() + 1];
		strcpy(tt, s.c_str());

		char* token = strtok(tt, "|");
		while (token) {
			string temp(token);
			vs.push_back(temp);
			token = strtok(NULL, "|");
		}
		sort(vs.begin(), vs.end());
	}

	string getPrefix(string a, string b) {
		int upto = min(a.size(), b.size());
		int i;
		for (i = 0; i < upto; i++) {
			if (a[i] != b[i])	break;
		}
		return a.substr(0, i);
	}

	string getCommon() {
		string s = vs[0];
		for (int i = 1; i < vs.size(); i++) {
			s = getPrefix(s, vs[i]);
		}
		return s;
	}

	void print() {
		cout << left << ": ";
		for (auto& s : vs) {
			cout << s << " | ";
		}
		cout << "\n";
	}

	void new_print() {
		string tt = getCommon();
		cout << left << "-> " << tt << "X\n";
		cout << "X-> ";
		for (int i = 0; i < vs.size() - 1; i++) {
			cout << vs[i].substr(tt.size(), vs[i].size()) << "|";
		}
		cout << vs.back().substr(tt.size(), vs.back().size()) << "\n";
	}

};
int main() {
	string s;
	cout << "Enter Production: ";
	cin >> s;
	Production p(s);
	cout<<"Original Production:\n";
	p.print();
	cout<<"New Productions so formed:\n";
	p.new_print();
	return 0;
}
