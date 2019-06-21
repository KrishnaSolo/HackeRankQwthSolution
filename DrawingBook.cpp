/*Problem:
		 Given number of pages and page number - find shortest pages to flip to reach
*/

//Solution:
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
	/*
	 * Write your code here.
	 */
	int lowest = 0;
	int frmb = 0; int end = 0;

	if (p % 2 == 0) {
		if ((p - 1) == 1) {
			frmb = 1;
		}
		else {
			frmb = (p - 1) / 2 + 1;
		}
	}
	else {
		frmb = (p - 1) / 2;
	}
	if (p % 2 == 0 && n % 2 == 0) {
		end = (n - p) / 2;
	}
	else if (p % 2 == 1 && n % 2 == 1) {
		end = (n - p) / 2;
	}
	else if ((n % 2 != 0) && (p % 2 == 0)) {
		if ((n - p) == 1) {
			end = 0;
		}
		else {
			end = (n - p) / 2;
		}
	}
	else {
		if ((n - p) == 1) {
			end = 1;
		}
		else {
			end = (n - p) / 2 + 1;
		}
	}
	if (end > frmb) {
		lowest = frmb;
	}
	else {
		lowest = end;
	}
	return lowest;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int p;
	cin >> p;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	int result = pageCount(n, p);

	fout << result << "\n";

	fout.close();

	return 0;
}
