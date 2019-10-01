#include <bits/stdc++.h>
using namespace std;
/*
int a = b + c + 100;
a=a*100*200;
a=a100/24;
*/
bool isDelim(char ch) {
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == ';' ||
	        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
	        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
	        ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '\n')
		return true;
	return false;
}

bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=')
		return true;
	return false;
}

bool validIdentifier(string& str) {
	if ((str[0] >= '0' && str[0] <= '9') || isDelim(str[0]))
		return false;
	return true;
}

bool isKeyword(string& str) {
	vector<string>vs = {"if", "else", "while", "break", "continue", "int", "return", "char"};
	for (int i = 0; i < vs.size(); i++) {
		if (vs[i] == str)	return true;
	}
	return false;
}

bool isInteger(string& str) {
	int i, len = str.size();
	if (!len)
		return false;
	for (i = 0; i < len; i++) {
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] == '-' && i > 0)) {
			continue;
		}
		return false;
	}
	return true;
}

map<string, int> mp;
int KEY = 0, NOT_IDENTIFIER = 0, CONSTANT = 0, IDENTIFIER = 0;

void parse(string& s) {
	int l = 0, r = 0, len = s.size();

	while (r <= len && l <= r) {
		if (!isDelim(s[r])) {
			r++;
		}

		if (isDelim(s[r]) && l == r) {
			if (isOperator(s[r])) {
				cout << s[r] << " ";
			}
			r++;
			l = r;
		} else if (isDelim(s[r]) && l != r || (r == len && l != r)) {

			string ss = s.substr(l, r - l);
			if(ss.size()==0)	continue;
			if (isKeyword(ss)) {
				KEY++;
				mp[ss] = KEY;
				cout << ss << " ";
			}

			else if (isInteger(ss)) {
				if (mp.find(ss) == mp.end()) {
					CONSTANT++;
					mp[ss] = CONSTANT;
				}
				cout << "Const" << mp[ss];
			}

			else if (validIdentifier(ss) && !isDelim(s[r - 1])) {
				if (mp.find(ss) == mp.end()) {
					IDENTIFIER++;
					mp[ss] = IDENTIFIER;
				}
				cout << "Id" << mp[ss];
			}

			else if (!validIdentifier(ss) && !isDelim(ss[r - 1])) {
				if (mp.find(ss) == mp.end()) {
					NOT_IDENTIFIER++;
					mp[ss] = NOT_IDENTIFIER;
				}
				cout << "N_Id" << mp[ss];
			}
			cout << s[r];
			r++;
			l = r;
		}
	}
}

void removeWhites(string & s) {
	string newS = "";
	for (char c : s) {
		if (c == '\n' || c == '\t')	continue;
		newS.push_back(c);
	}
	s = newS;
}

int main() {
	string s;
	string program = "";
	while (getline(cin, s)) {
		program = program + "\n" + s;
	}
	removeWhites(program);
	cout << "Program: \n";
	cout << program << "\n\n";

	cout<<"Lexical Analyser Output:\n";
	parse(program);
	cout << "\n\n";
	return 0;
}
