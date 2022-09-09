#include <ostream> 
#include <fstream> 
#include <sstream> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <csignal> 
#include <regex> 
#include <type_traits> 
#include <set> 
#include <iostream> 
using namespace std;
// Returns the product of two non-negative integers, m and n, 
// using only repeated addition. 
int multiplyTwoNumbers(unsigned int m, unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    return m + multiplyTwoNumbers(m, n-1);
}

// Returns the number of occurrences of digit in the decimal 
// representation of num. digit is an int between 0 and 9 
// inclusive. 
// 
// Pseudocode Example: 
//    tabulationStation(18838, 8) => 3 
//    tabulationStation(55555, 3) => 0 
//    tabulationStation(0, 0)     => 0 or 1 (either if fine) 
int tabulationStation(int num, int digit)
{
    if (num < 10)
    {
        if (num == digit)
        {
            return 1;
        }
        return 0;
    }

    if (num % 10 == digit)
    {
        return 1 + tabulationStation(num / 10, digit);
    }
    else return tabulationStation(num / 10, digit);
}

// Returns a string where the same characters next each other in 
// string n are separated by "55" (you can assume the input  
// string will not have 5’s) 
// 
// Pseudocode Example: 
//    highFives("goodbye") => "go55odbye" 
//    highFives("yyuu")    => "y55yu55u" 
//    highFives("aaaa")    => "a55a55a55a" 
// 
string highFives(string n)
{
    if (n.length() == 0)
        return "";
    else if (n.length() == 1)
        return n;
    else
    {
        string first = n.substr(0, n.length() / 2);
        string second = n.substr(n.length() / 2);
        if (first[first.length() - 1] == second[0])
        {
            return highFives(first) + "55" + highFives(second);
        }
        else
        {
            return highFives(first) + highFives(second);
        }
    }
}

// str contains a single pair of parentheses, return a new  
// string made of only the parentheses and whatever those  
// parentheses contain 
// 
//  Pseudocode Example: 
//     jheriCurls("abc{ghj}789") => "{ghj}" 
//     jheriCurls("{x}7")        => "{x}" 
//     jheriCurls("4agh{y}")    => "{y}" 
//     jheriCurls("4agh{}")     => "{}" 
// 
string jheriCurls(string str)
{
    if (str[0] == '{' && str[str.length() - 1] == '}')
        return str;
    else if (str[0] == '{')
    {
        return jheriCurls(str.substr(0, str.length() - 1));
    }
    else if (str[str.length() - 1] == '}')
        return jheriCurls(str.substr(1));
    else
        return jheriCurls(str.substr(1, str.length() - 1));
}

// Return true if the total of any combination of elements in  
// the array a equals the value of the target. 
// 
//  Pseudocode Example: 
//     aggregationNation({2, 4, 8}, 3, 10) => true 
//     aggregationNation({2, 4, 8}, 3, 6)  => true 
//     aggregationNation({2, 4, 8}, 3, 11) => false 
//     aggregationNation({2, 4, 8}, 3, 0)  => true 
//     aggregationNation({}, 0, 0)         => true 
// 
bool aggregationNation(const int a[], int size, int target)
{
    if (target == 0 || size == 0)
        return true;
    else if (a[size - 1] == target)
        return true;
    else if (size == 1 && target != 0)
        return false;
    else
    {
        if (aggregationNation(a, size - 1, target - a[size - 1]))
            return true;
        if (aggregationNation(a, size - 1, target))
            return true;
    }
    return false;
}

// Return true if there is a path from (sr,sc) to (er,ec) 
// through the maze; return false otherwise 
bool onMyWayHome(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
        return true;

    maze[sr][sc] = '*';//'*' == visited
    if (sr != nRows - 1 && maze[sr + 1][sc] != 'X' && maze[sr + 1][sc] != '@' && maze[sr + 1][sc] != '*')
        if (onMyWayHome(maze, nRows, nCols, sr + 1, sc, er, ec))
            return true;
    if (sr != 0 && maze[sr - 1][sc] != 'X' && maze[sr - 1][sc] != '@' && maze[sr - 1][sc] != '*')
        if (onMyWayHome(maze, nRows, nCols, sr - 1, sc, er, ec))
            return true;
    if (sc != nCols - 1 && maze[sr][sc + 1] != 'X' && maze[sr][sc + 1] != '@' && maze[sr][sc + 1] != '*')
        if (onMyWayHome(maze, nRows, nCols, sr, sc + 1, er, ec))
            return true;
    if (sc != 0 && maze[sr][sc - 1] != 'X' && maze[sr][sc - 1] != '@' && maze[sr][sc - 1] != '*')
        if (onMyWayHome(maze, nRows, nCols, sr, sc - 1, er, ec))
            return true;

    return false;
}

void testone(int n)
{
    static string maze1[10] = {
        { "XXXXXXXXXX" },
        { "X.X..X...X" },
        { "X.XX.X.XXX" },
        { "X....X.X.X" },
        { "XX.X.X...X" },
        { "XXX..X.X.X" },
        { "X...X...XX" },
        { "X.XX..X.XX" },
        { "X....X...X" },
        { "XXXXXXXXXX" },
    };

    static string maze2[10] = {
        { "XXXXXXXXXX" },
        { "X.X..X...X" },
        { "X.XX.X.XXX" },
        { "X....X.X.X" },
        { "XX.X.X...X" },
        { "XXX.XX.X.X" },
        { "X...X...XX" },
        { "X.XX..X.XX" },
        { "X....X...X" },
        { "XXXXXXXXXX" },
    };

    static string maze3[10] = {
        { "XXXXXXXXXX" },
        { "XX.....XXX" },
        { "X..XX....X" },
        { "X...X...XX" },
        { "X.X.XXX..X" },
        { "XXXX..X..X" },
        { "XX....X..X" },
        { "X.......XX" },
        { "X..XXXXXXX" },
        { "XXXXXXXXXX" },
    };

    static string maze4[10] = {
        { "XXXXXXXXXX" },
        { "XX.....XXX" },
        { "X..XX....X" },
        { "X...X...XX" },
        { "X.X.XXX..X" },
        { "XXXX..X..X" },
        { "XX....X..X" },
        { "X.....X.XX" },
        { "X..XXXXXXX" },
        { "XXXXXXXXXX" },
    };

    static string maze5[10] = {
        { "XXXXXXXXXX" },
        { "X.X..X...X" },
        { "X.XX.X.XXX" },
        { "X....X.X.X" },
        { "XX.X.X...X" },
        { "XXX.XX.X.X" },
        { "X...X...XX" },
        { "X.XX..X.XX" },
        { "X....X...X" },
        { "XXXXXXXXXX" },
    };

    int a[4] = { 2,  25, -1, 3 };
    int b[3] = { 2,  4,  8 };
    int c[3] = { 1,  2,  3 };
        switch (n)
        {
        default: {
            assert(false);
        } break; case  1: {
            assert(multiplyTwoNumbers(3, 5) == 15);
        } break; case  2: {
            assert(multiplyTwoNumbers(4, 3) == 12);
        } break; case  3: {
            assert(multiplyTwoNumbers(0, 8) == 0);
        } break; case  4: {
            assert(multiplyTwoNumbers(1, 2));
        } break; case  5: {
            assert(tabulationStation(18838, 8) == 3);
        } break; case  6: {
            assert(tabulationStation(10300, 0) == 3);
        } break; case  7: {
            assert(tabulationStation(1234, 5) == 0);
        } break; case  8: {
            assert(tabulationStation(4245, 4) == 2);
        } break; case  9: {
            assert(tabulationStation(1111111, 1) == 7);
        } break; case 10: {
            assert(jheriCurls("abcd{ghj}789") == "{ghj}");
        } break; case 11: {
            assert(jheriCurls("{xxx}789") == "{xxx}");
        } break; case 12: {
            assert(jheriCurls("789{xxx}") == "{xxx}");
        } break; case 13: {
            assert(jheriCurls("{asdf}") == "{asdf}");
        } break; case 14: {
            assert(jheriCurls("a{}a") == "{}");
        } break; case 15: {
            assert(aggregationNation(a, 0, 0));
            //assert(!aggregationNation(a, 0, 1));
        } break; case 16: {
            assert(aggregationNation(a, 4, 24));
            assert(!aggregationNation(a, 4, 31));
        } break; case 17: {
            assert(aggregationNation(b, 3, 12));
            assert(!aggregationNation(b, 3, 11));
        } break; case 18: {
            assert(aggregationNation(b, 3, 10));
            assert(aggregationNation(b, 3, 0));
            assert(!aggregationNation(b, 3, 1));
        } break; case 19: {
            assert(aggregationNation(c, 3, 6));
                assert(!aggregationNation(c, 3, 7));
        } break; case 20: {
            assert(aggregationNation(c, 3, 1));
            assert(!aggregationNation(c, 3, 10));
        } break; case 21: {
            assert(highFives("goodbye") == "go55odbye");
        } break; case 22: {
            assert(highFives("nothinghere") == "nothinghere");
        } break; case 23: {
            assert(highFives("yyasdf") == "y55yasdf");
        } break; case 24: {
            assert(highFives("axxyya") == "ax55xy55ya");
        } break; case 25: {
            assert(highFives("aaa") == "a55a55a");
        } break; case 26: {
            assert(onMyWayHome(maze1, 10, 10, 8, 6, 1, 1));
        } break; case 27: {
            assert(!onMyWayHome(maze2, 10, 10, 8, 6, 1, 1));
        } break; case 28: {
            assert(onMyWayHome(maze5, 10, 10, 8, 6, 1, 8));
        } break; case 29: {
            assert(onMyWayHome(maze3, 10, 10, 4, 3, 7, 1));
        } break; case 30: {
            assert(!onMyWayHome(maze4, 10, 10, 4, 3, 7, 1));
        }
        }
}

int main()
{
    for (int n = 1; n <= 30; n++) {
        testone(n);
        cout << n << " passed" << endl;
    }

    return 0;
}
