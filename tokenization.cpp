#include <bits/stdc++.h>
using namespace std;
/*

int a = b + c + 100;
a=a*100*200;
a=a100/24;

*/
bool isDelim(char ch) {
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
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
	if (str.size() == 0)	return false;
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

int ops = 0, kwrd = 0, intgrs = 0, idntifrs = 0, nidntifrs = 0;

void parse(string& s) {
	int l = 0, r = 0, len = s.size();

	while (r <= len && l <= r) {
		if (!isDelim(s[r])) {
			r++;
		}

		if (isDelim(s[r]) && l == r) {
			if (isOperator(s[r])) ops++;
			r++;
			l = r;
		} else if (isDelim(s[r]) && l != r || (r == len && l != r)) {

			string ss = s.substr(l, r - l);
			if (ss.size() == 0)	continue;
			if (isKeyword(ss))	kwrd++;

			else if (isInteger(ss))	intgrs++;

			else if (validIdentifier(ss) && !isDelim(s[r - 1]))
				idntifrs++;

			else if (!validIdentifier(ss) && !isDelim(ss[r - 1]))
				nidntifrs++;
			r++;
			l = r;
		}
	}
}

int main() {
	string s;
	while (getline(cin, s)) {
		parse(s);
	}
	cout << "Operators: " << ops << "\n";
	cout << "Identifiers: " << idntifrs << "\n";
	cout << "Keywords: " << kwrd << "\n";
	cout << "Integers: " << intgrs << "\n";
	cout << "Not Identifiers: " << nidntifrs << "\n";
	return 0;
}
