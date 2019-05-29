/*Problem:
  For every mark if greater then 38 and less then 3 from the nearest multiple of 5->round up
  else keep same mark
  Return in a vector
*/

//Solution:
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the gradingStudents function below.
 */
vector<int> gradingStudents(vector<int> grades) {
	/*
	 * Write your code here.
	 */
	vector<int> rounded;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] > 37) {
			string b = to_string(grades[i]);
			char oneb = b.at(1);
			int ones = oneb - 48;
			int add;
			if (ones < 5) {
				add = 5 - ones;
			}
			else {
				add = 10 - ones;
			}
			if (((grades[i] + add) - grades[i]) < 3) {
				rounded.push_back(grades[i] + add);
			}
			else {
				rounded.push_back(grades[i]);
			}
		}
		else {
			rounded.push_back(grades[i]);
		}
	}
	return rounded;

}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> grades(n);

	for (int grades_itr = 0; grades_itr < n; grades_itr++) {
		int grades_item;
		cin >> grades_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		grades[grades_itr] = grades_item;
	}

	vector<int> result = gradingStudents(grades);

	for (int result_itr = 0; result_itr < result.size(); result_itr++) {
		fout << result[result_itr];

		if (result_itr != result.size() - 1) {
			fout << "\n";
		}
	}

	fout << "\n";

	fout.close();

	return 0;
}
