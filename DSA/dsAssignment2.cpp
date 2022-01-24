#include <bits/stdc++.h>
using namespace std;

int shortestChainLen(
string start, string target,
set<string>& D)
{

	if(start == target)
	return 0;

	if (D.find(target) == D.end())
		return 0;

	int level = 0, wordlength = start.size();

	queue<string> Q;
	Q.push(start);

	while (!Q.empty()) {

		++level;

		int sizeofQ = Q.size();

		for (int i = 0; i < sizeofQ; ++i) {

			string word = Q.front();
			Q.pop();

			for (int pos = 0; pos < wordlength; ++pos) {

				char orig_char = word[pos];

				for (char c = 'a'; c <= 'z'; ++c) {
					word[pos] = c;

					if (word == target)
						return level + 1;

					if (D.find(word) == D.end())
						continue;
					D.erase(word);

					Q.push(word);
				}

				word[pos] = orig_char;
			}
		}
	}

	return 0;
}

int main()
{

	set<string> D;
	D.insert("poon");
	D.insert("plee");
	D.insert("same");
	D.insert("poie");
	D.insert("plie");
	D.insert("poin");
	D.insert("plea");
	string start = "toon";
	string target = "plea";
	cout << "Length of shortest chain is: "
		<< shortestChainLen(start, target, D);
	return 0;
}