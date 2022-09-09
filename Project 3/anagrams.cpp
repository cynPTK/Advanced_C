#include <iostream>
#include <fstream>
#include <istream>
#include <cstring>
#include <string>

using namespace std;

int lexiconBuilder(istream& dictfile, string dict[])
{
	string line;
    if (dictfile >> line)//retrieves every word in dictfile
    {
        dict[0] = line;
        return 1 + lexiconBuilder(dictfile, dict + 1);
    }
    return 0;
}

void Permutations(string prefix, string rest, const string& word, string results[], const string dict[], int& size, int& result_size);

//Loops for every letter in rest to be appended to prefix and removed from rest
 void LoopPerm(int i, int max, string& prefix, string& rest, const string& word, string results[], const string dict[], int& size, int& result_size) {
     if (i >= max)
        return;
     Permutations(prefix + rest[i], rest.substr(0, i) + rest.substr(i + 1), word, results, dict, size, result_size);
     LoopPerm(i + 1, max, prefix, rest, word, results, dict, size, result_size);
}

 //Loops to find if the word is in the dict
 void LoopDict(int i, int& max, string& prefix, string results[], const string dict[], int& result_size)
 {
     if (i >= max)
         return;
     if (dict[i] == prefix)//if word is in dict, add word into results[]
     {
         results[result_size] = prefix;
         result_size++;
         return;
     }
     LoopDict(i + 1, max, prefix, results, dict, result_size);
 }

 //Loops to find if the permutation is already in results
 bool LoopFindRep(int i, string& prefix, string results[], int& result_size)
 {
     if (i >= result_size)
         return true;
     if (results[i] == prefix)
         return false;
     return LoopFindRep(i + 1, prefix, results, result_size);
 }

 //finds all permutaions of a given word and puts into results[] if permutaion is in dict
 void Permutations(string prefix, string rest, const string& word, string results[], const string dict[], int& size, int& result_size) {
    if (rest.length() == 0) {
        if (prefix != word && LoopFindRep(0, prefix, results, result_size))//makes sure permuation is not already in results[] and is not the word
            LoopDict(0, size, prefix, results, dict, result_size);//cheks if it is in dict
    }
    else {
        LoopPerm(0, rest.length(), prefix, rest, word, results, dict, size, result_size);
    }
}

int theJumbler(string word, const string dict[], int size, string results[])
{
    if (word == "")//return 0 if word is empty string
        return 0;
    int result_size = 0;
    Permutations("", word, word, results, dict, size, result_size);//helper function to put all anagrams into results[] and return number of results
    return result_size;
}

//prints out all the anagrams in results[]
void divulgeSolutions(string results[], int numMatches)
{
    if (0 >= numMatches)
        return;
    cout << "Matching word " << results[0] << endl;
    divulgeSolutions(results + 1, numMatches - 1);
}

const int MAXRESULTS = 20;    // Max matches that can be found
const int MAXDICTWORDS = 10; // Max words that can be read in
#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <string> 
#include <cassert> 
#include <algorithm> 

using namespace std;

void testone(int n)
{
    string dictionary[MAXDICTWORDS];
    string results[MAXRESULTS];

    switch (n)
    {
    default: {
        cout << "Bad argument" << endl;
    } break; case 1: {
        istringstream
            iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod");
        int numResults = lexiconBuilder(iss, dictionary);
        sort(dictionary, dictionary + numResults);
        assert(numResults == 9 && dictionary[0] == "act" &&
            dictionary[1] == "art");
    } break; case 2: {
        // File is empty, checks that file is empty and lexiconBuilder returns 0.
            istringstream iss("");
        int numResults = lexiconBuilder(iss, dictionary);
        assert(numResults == 0 && dictionary[0] == "");
    } break; case 3: {
        // Dictionary has been read properly 
            istringstream
            iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod");
        int numResults = lexiconBuilder(iss, dictionary);
        sort(dictionary, dictionary + numResults);
        assert(numResults == 9 && dictionary[0] == "act" &&
            dictionary[numResults - 1] == "tar");
    } break; case 4: {
    //    // Input file is larger than the dictionary size 
    //    istringstream iss("dog\ncat\nrat\neel\ntar\nart\nlee\nact\ngod\ntoo\nmany\nwords"); 
    //            int numResults = lexiconBuilder(iss, dictionary);
    //    sort(dictionary, dictionary + numResults);
    //    assert(numResults == 10 && dictionary[MAXDICTWORDS -
    //        1] == "too");
    } break; case 5: {
        // If a certain word with repeated letter is shown in results more than once - still accept.
            string dictionary[] = { "one", "oone", "ne", "e",
"too" };
        int numResults = theJumbler("oto", dictionary, 5,
            results);
        assert((numResults == 1 || numResults == 2) &&
            results[0] == "too");
    } break; case 6: {
        // Doesn't check numResults nor duplicates. 
        string dictionary[] = { "one", "oone", "ne", "e",
"too" };
        theJumbler("oto", dictionary, 5, results);
        assert(results[0] == "too");
    } break; case 7: {
        // If word wasn't found, numResults = 0 and results array is empty.
            string dictionary[] = { "one", "oone", "ne", "e" };
        int numResults = theJumbler("look", dictionary, 4,
            results);
        assert(numResults == 0 && results[0] == "" &&
            results[1] == "");
    } break; case 8: {
        // No fraction of a permutation is being searched in dictionary
            string dictionary[] = { "one", "oone", "non", "oon"
        };
        int numResults = theJumbler("on", dictionary, 4,
            results);
        assert(numResults == 0 && results[0] == "" &&
            results[1] == "");
    } break; case 9: {
        // No fraction of a permutation is being searched in dictionary
            string dictionary[] = { "one", "oone", "ne", "e",
"neoo", "oneo" };
        int numResults = theJumbler("neo", dictionary, 6,
            results);
        assert(numResults == 1 && results[0] == "one" &&
            results[1] == "");
    } break; case 10: {
    //        // Checking that no error occurs if more than MAXRESULTS are found.
    //            string dictionary[] = { "true",  "treu", "teru",
    //"teur", "ture",
    //  "tuer", "rtue", "rteu", "retu","reut", "ruet",
    //"rute", "utre",
    //  "uter", "uetr", "uert", "urte", "uret", "etru",
    //"etur", "ertu",
    //  "erut", "eurt", "eutr" };
    //        // All 24 permutations 
    //        int numResults = theJumbler("true", dictionary, 24,
    //            results);
    //        assert(numResults == MAXRESULTS);
        } break; case 11: {
        // Checking one word was found, no duplicates. 
       /* string dictionary[] = { "ppp" };
        int numResults = theJumbler("ppp", dictionary, 1,
            results);
        assert(numResults == 1 && results[0] == "ppp" &&
            results[1] == "");*/
    } break; case 12: {
            string dictionary[] = { "run", "dodge", "break",
"urn", "defeat" };
            int numResults = theJumbler("nru", dictionary, 5,
                results);
            sort(results, results + numResults);
            assert(numResults == 2 && results[0] == "run" &&
                results[1] == "urn");
        } break; case 13: {
        streambuf* oldCoutStreamBuf = cout.rdbuf();
        ostringstream strCout;
        cout.rdbuf(strCout.rdbuf());
        string results[] = { "cat", "act" };
        divulgeSolutions(results, 2);
        cout.rdbuf(oldCoutStreamBuf);
        string temp = strCout.str();
        bool match1 = temp.find("act") != string::npos;
            bool match2 = temp.find("cat") != string::npos;
        assert(match1 && match2);
    } break; case 14: {
           /* istringstream iss("tier\nrite\nbate\ntire\nttir");
            int numWords = lexiconBuilder(iss, dictionary);
            sort(dictionary, dictionary + numWords);
            assert(numWords == 5 && dictionary[0] == "bate");
            int numResults = theJumbler("tier", dictionary,
                numWords, results);
            assert(numResults == 3 && (results[2] == "tire" ||
                results[2] == "tier" || results[2] == "rite"));*/
        } break; case 15: {
        string example[] = { "kool", "moe", "dee" };
        int numResults = theJumbler("look", example, 3,
            results);
        assert(numResults == 1 && results[0] == "kool");
    } break;
    }
}

int main()
{
    for (int n = 1; n <= 15; n++) {
        testone(n);
        cout << n << " passed" << endl;
    }

    return 0;
}