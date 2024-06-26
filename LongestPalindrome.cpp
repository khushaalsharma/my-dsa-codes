// Longest Palindrome in a string
//Brute Force: Tabulation -> fill the diagonal matrix of (str.len X str.len) as i and j as start and end index of substring, check if it is plaindrome if yes and longer than current solution store it

//Correct Way: Using Dynamic Programming
//O(n2) time and space [space can be optimised to O(n)
//ALGORITHM:The algorithm below is very simple and easy to understand. The idea is to Fix a center and expand in both directions for longer palindromes and keep track of the longest palindrome seen so far.
//Maintain a variable ‘ maxLength = 1 ‘ (for storing LPS length) and ‘ start =0 ‘ (for storing starting index of LPS ).
// The idea is very simple, we will traverse through the entire string with i=0 to i<(length of string).
// while traversing, initialize ‘low‘ and ‘high‘ pointer such that low= i-1 and high= i+1.
// keep incrementing ‘high’ until str[high]==str[i] .
// similarly keep decrementing ‘low’ until str[low]==str[i].
// finally we will keep incrementing ‘high’ and decrementing ‘low’ until str[low]==str[high].
// calculate length=high-low-1, if length > maxLength then maxLength = length and start = low+1 .
// Print the LPS and return maxLength.

//CODE:

// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
// easy to understand as compared to previous version.
#include <bits/stdc++.h>
using namespace std;

// A utility function to print
// a substring str[low..high]
// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(string str)
{
	int n = str.size(); // calculating size of string
	if (n < 2)
		return n; // if string is empty then size will be 0.
				// if n==1 then, answer will be 1(single
				// character will always palindrome)

	int maxLength = 1, start = 0;
	int low, high;
	for (int i = 0; i < n; i++) {
		low = i - 1;
		high = i + 1;
		while (high < n
			&& str[high] == str[i]) // increment 'high'
			high++;

		while (low >= 0
			&& str[low] == str[i]) // decrement 'low'
			low--;

		while (low >= 0 && high < n
			&& str[low] == str[high]) {
			low--;
			high++;
		}

		int length = high - low - 1;
		if (maxLength < length) {
			maxLength = length;
			start = low + 1;
		}
	}

	cout << "Longest palindrome substring is: ";
	cout << str.substr(start, maxLength);
	return maxLength;
}

// Driver program to test above functions
int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: " << longestPalSubstr(str)
		<< endl;
	return 0;
}

 
