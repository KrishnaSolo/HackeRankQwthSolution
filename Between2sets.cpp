/*Problem:
		  You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:

		  1.	The elements of the first array are all factors of the integer being considered
		  2.	The integer being considered is a factor of all elements of the second array

		These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.
*/

//Solution
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


int getTotalX(vector<int> a, vector<int> b) {

	int count = 0;
	int n = a.size();

	vector<int> hold;
	vector<int> inter;
	int end = b[0];
	int begin = a[n - 1];
	int temp = begin;

	if (end < begin) {
		return count;
	}

	while (temp != end) {
		hold.push_back(temp);
		temp += begin;

	}
	hold.push_back(end);
	int intert = 0;
	for (int i = 0; i < hold.size(); i++) {
		intert = 0;
		for (int j = 0; j < n; j++) {
			if (hold[i] % a[j] == 0) {
				intert += 1;

			}
			if (intert == n) {
				inter.push_back(hold[i]);
			}
		}
	}

	intert = 0;
	for (int i = 0; i < inter.size(); i++) {
		intert = 0;
		for (int j = 0; j < b.size(); j++) {
			if (b[j] % inter[i] == 0) {
				intert += 1;

			}
			if (intert == b.size()) {
				count += 1;
			}
		}
	}

	return count;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(n);

	for (int a_itr = 0; a_itr < n; a_itr++) {
		int a_item = stoi(a_temp[a_itr]);

		a[a_itr] = a_item;
	}

	string b_temp_temp;
	getline(cin, b_temp_temp);

	vector<string> b_temp = split_string(b_temp_temp);

	vector<int> b(m);

	for (int b_itr = 0; b_itr < m; b_itr++) {
		int b_item = stoi(b_temp[b_itr]);

		b[b_itr] = b_item;
	}

	int total = getTotalX(a, b);

	fout << total << "\n";

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char& x, const char& y) {
		return x == y and x == ' ';
		});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
