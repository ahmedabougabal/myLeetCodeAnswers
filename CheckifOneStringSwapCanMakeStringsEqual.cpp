#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	bool areAlmostEqual(string s1, string s2)
	{
		bool res = false;
		vector<int> diff;
		if (s1 == s2)
		{
			return true;
		}

		for (int i = 0; i < s1.size(); ++i)
		{
			if (s1[i] != s2[i])
			{
				diff.push_back(i);
			}
		}
		if (diff.size() == 2)
		{
			cout << "s1[diff[0]] = " << s1[diff[0]] << endl;
			cout << "s2[diff[1]] = " << s2[diff[1]] << endl;
			cout << "===\n";
			cout << "s1[diff[1]] = " << s1[diff[1]] << endl;
			cout << "s2[diff[0]] = " << s2[diff[0]] << endl;
			res = s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
		}

		return res;
	}
};
int main()
{
	cout << boolalpha;
	Solution sol;
	string s1 = "bank";
	string s2 = "kanb";
	cout << sol.areAlmostEqual(s1, s2); // !true
	cout << "\n=======================\n";
	string s3 = "attack";
	string s4 = "defend";
	cout << sol.areAlmostEqual(s3, s4); // ! false
	cout << "\n=======================\n";
	string s5 = "kelb";
	string s6 = "kelb";
	cout << sol.areAlmostEqual(s5, s6); // !true
	cout << "\n=======================\n";
	string s7 = "abcd";
	string s8 = "dcba";
	cout << sol.areAlmostEqual(s7, s8); //! should be false
	return 0;
}
