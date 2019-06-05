/*Problem:
		  Given an array find element with most occurances and if two elements have same amount choose smaller element 
*/

//Solution:
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
	pair<int, int> a;
	pair<int, int> b;
	pair<int, int> c;
	pair<int, int> d;
	pair<int, int> e;
	for (int i = 0; i < arr.size(); i++) {
		if (1 == arr[i]) {
			a.first += 1;
			a.second = 1;
		}
		else if (2 == arr[i]) {
			b.first += 1;
			b.second = 2;
		}
		else if (3 == arr[i]) {
			c.first += 1;
			c.second = 3;
		}
		else if (4 == arr[i]) {
			d.first += 1;
			d.second = 4;
		}
		else if (5 == arr[i]) {
			e.first += 1;
			e.second = 5;
		}
	}
	vector<pair<int, int> > max;
	max.push_back(a); max.push_back(b); max.push_back(c); max.push_back(d);
	max.push_back(e);
	sort(max.rbegin(), max.rend());
	vector<int> final;
	for (auto a : max) {
		if (max[0].first == a.first) {
			final.push_back(a.second);
		}
	}
	sort(final.begin(), final.end());
	return final[0];

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string arr_count_temp;
	getline(cin, arr_count_temp);

	int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

	string arr_temp_temp;
	getline(cin, arr_temp_temp);

	vector<string> arr_temp = split(rtrim(arr_temp_temp));

	vector<int> arr(arr_count);

	for (int i = 0; i < arr_count; i++) {
		int arr_item = stoi(arr_temp[i]);

		arr[i] = arr_item;
	}

	int result = migratoryBirds(arr);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string& str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string& str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}

vector<string> split(const string& str) {
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos) {
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
