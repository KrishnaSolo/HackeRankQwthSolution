/*Problem:
	     Given a vector of scores iterate over and return how many times the lowest values was lowered and largest value was increased
*/

//Solution
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the breakingRecords function below.
vector<int> breakingRecords(vector<int> scores) {
	int low = scores[0]; //set to first index
	int high = scores[0];
	int lc = 0; int hc = 0; //counters

	for (int i = 0; i < scores.size(); i++) {
		int temp = scores[i]; // new temp created to hold score at that index
		if (temp > high) { //ensure it is greater, replace and increment
			high = temp;
			hc += 1;
		}
		else if (temp < low) { //same as above
			low = temp;
			lc += 1;
		}
		else {
			lc += 0; hc += 0; //do nothing
		}
	}
	std::vector<int> final;
	final.push_back(hc);
	final.push_back(lc);
	return final;

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string scores_temp_temp;
	getline(cin, scores_temp_temp);

	vector<string> scores_temp = split_string(scores_temp_temp);

	vector<int> scores(n);

	for (int i = 0; i < n; i++) {
		int scores_item = stoi(scores_temp[i]);

		scores[i] = scores_item;
	}

	vector<int> result = breakingRecords(scores);

	for (int i = 0; i < result.size(); i++) {
		fout << result[i];

		if (i != result.size() - 1) {
			fout << " ";
		}
	}

	fout << "\n";

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
