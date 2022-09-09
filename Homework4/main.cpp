#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include "WordTree.h"
#include <cassert>
using namespace std;
int main() {
	ifstream fin;
	ofstream fout;
	string filename;
	cout << "Enter name of file with text to analyze: ";
	cin >> filename;
	fin.open(filename.c_str());
	if (fin.fail()) {
		cout << "Error opening file.\n";
		exit(1);
	}
	cout << "\nAnalyzing " << filename << ".\n";
	WordTree myTree;
	// insert code here
	WordType v;
	while (fin >> v)
	{
		WordType input = "";
		WordType input2 = "";
		for (int i = 0; i < v.size(); i++)
		{		
			if (isalpha(v[i]) || v[i] == '\'')
				input += tolower(v[i]);
			else if (v[i] == '-' && i + 1 < v.size() && isalpha(v[i + 1]))
			{
				for (int j = i + 1; j < v.size(); j++)
				{
					if (isalpha(v[i]) || v[i] == '\'')
					input2 += tolower(v[j]);
				}
				if (input2 != "")
				{
					cout << input2 << endl;
					myTree.add(input2);
				}
				break;
			}

		}
		if (input != "")
			myTree.add(input);
	}

	fin.close();
	fout.open("results.txt");
	cout << "\nWord counts:\n\n";
	cout << myTree;
	fout << myTree;
	cout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
	fout << "\nTotal number of words in text: " << myTree.totalWords() << ".\n";
	cout << "Number of distinct words appearing in text: "
		<< myTree.distinctWords() << ".\n";
	fout << "Number of distinct words appearing in text: "
		<< myTree.distinctWords() << ".\n";
	fout.close();

	WordTree k;

	k.add("Kim");
	k.add("Kanye");
	k.add("Kanye");
	k.add("Kanye");

	WordTree w;

	w.add("Harry");
	w.add("Niall");
	w.add("Niall");
	w.add("Liam");
	w.add("Louis");
	w.add("Harry");
	w.add("Niall");
	w.add("Zayn");

	assert(k.distinctWords() == 2);
	assert(k.totalWords() == 4);
	WordTree CopyTest = w;
	cout << CopyTest;
	WordTree AssignTest = CopyTest;
	AssignTest = k;
	cout << AssignTest;
	WordTree EmptyTest;
	cout << EmptyTest;
	return 0;
}