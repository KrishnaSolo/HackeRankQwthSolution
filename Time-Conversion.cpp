/* Problem: 
   Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.
   Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. 
         Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.
*/

//Solution:
#include <bits/stdc++.h>
#include <string>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
	char c = s.at(8);
	string final;
	if (c == 'P') {
		if (s.at(0) == '1' && s.at(1) == '2') {
			string hh = "12";
			s.erase(8, 2);
			s.erase(0, 2);
			final = hh + s;
		}
		else {
			char h1 = s.at(0);
			int ht = h1 - 48; //48 used to convert to int (ASCII - '0')
			ht = ht + 1;
			char h2 = s.at(1);
			int h0 = h2 - 48;
			h0 = h0 + 2;
			string hh = to_string(ht) + to_string(h0);
			s.erase(8, 2);
			s.erase(0, 2);
			final = hh + s;
		}
	}
	else {
		if (s.at(0) == '1' && s.at(1) == '2') {
			string hh = "00";
			s.erase(8, 2);
			s.erase(0, 2);
			final = hh + s;
		}
		else {
			s.erase(8, 2);
			final = s;
		}

	}
	return final;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = timeConversion(s);

	fout << result << "\n";

	fout.close();

	return 0;
}
