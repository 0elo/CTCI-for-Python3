#include "chapter_one.h"

using namespace std;

/* 1.1 Is Unique
 * Implement an algorithm to determine if a string has all unique
 * characters. What if you cannot use additional data structures?
 */

bool ChapterOne::isUnique_vector(const string &str) {
	
	// There are only 128 unique characters in ASCII
	if (str.length() > 128) return false;

	// Using array
	//bool char_set[128] = { 0 };

	// Using vector
	vector<bool> char_set(128);

	// Iterate through string looking for reused characters
	for (size_t i = 0; i < str.length(); i++) {

		if (char_set[str[i]]) {
			cout << "First repeated character found: " << str[i] << endl;
			return false;
		}

		char_set[str[i]] = true;
	}

	return true;
}

bool ChapterOne::isUnique_bitset(const string & str) {
	
	if (str.length() > 128) return false;

	// Using bitset
	std::bitset<128> bits;

	for (size_t i = 0; i < str.length(); i++) {
		if (bits.test(str[i])) return false;

		bits.set(str[i]);
	}

	return true;
}

bool ChapterOne::isUnique_noDS(const string &str) {
	
	if (str.length() > 128) return false;

	// Using no data structure
	for (size_t i = 0; i < str.length(); i++) {
		for (size_t j = i + 1; j < str.length(); j++) {
			if (str[i] == str[j]) return false;
		}
	}
	
	return true;
}

/* 1.2 Check Permutation
 * Given two strings, write a method to decide if one is a permuatation
 * of the other
 */

bool ChapterOne::checkPermutation_sort(string &str1, string &str2) {
	
	if (str1.length() != str2.length()) return false;

	sort_string(str1);
	sort_string(str2);

	// Sort strings and return string comparison

	return str1.compare(str2) == 0;
}

bool ChapterOne::checkPermutation_count(string &str1, string &str2) {

	if (str1.length() != str2.length()) return false;

	// Assume 128 ASCII char set
	int char_counts[128] = { 0 };

	for (size_t i = 0; i < str1.length(); i++) {
		char_counts[str1[i]]++;
	}

	for (size_t i = 0; i < str2.length(); i++) {
		char_counts[str2[i]]++;

		if (char_counts[str2[i]] < 0) {
			cout << "Offending character: " << str1[i] << endl;
			return false;
		}
	}

	return accumulate(char_counts, char_counts + 128, 0);
}

void ChapterOne::test() {

	cout << "Chapter 1 | Arrays and Strings" << endl << endl;

	// 1.1 Is Unique
	cout << "1.1 Is Unique:" << endl << "Implement an algorithm to "
		"determine if a string has all unique characters. What if you "
        "cannot use additional data structures?" << endl << endl;
	
	string unique_string = "abcdefgh1234567890jklmnopqrstuvwxyz";
	string not_unique_string = unique_string + "xdxdxd";

	cout << "Testing with unique string: " << unique_string << endl;
	assert(true == isUnique_vector(unique_string));
	assert(true == isUnique_bitset(unique_string));
	assert(true == isUnique_noDS(unique_string));
	cout << "Testing with not unique string:" << not_unique_string << endl;
	assert(false == isUnique_vector(not_unique_string));
	assert(false == isUnique_bitset(not_unique_string));
	assert(false == isUnique_noDS(not_unique_string));

	cout << endl;

	// 1.2 Check Permutation
	cout << "1.2 Check Permutation:" << endl << "Given two strings, write a method "
		"to decide if one is a permutation of the other." << endl << endl;

	string permutation_string = "xdxdxd" + unique_string;

	cout << "Testing with two strings that are permutations: " << permutation_string <<
		", " << not_unique_string << endl;
	assert(true == checkPermutation_sort(permutation_string, not_unique_string));
	assert(true == checkPermutation_count(permutation_string, not_unique_string));
	cout << "Testing with two strings that are not permutations: " << permutation_string <<
		", " << unique_string << endl;
	assert(false == checkPermutation_sort(permutation_string, unique_string));
	assert(false == checkPermutation_count(permutation_string, unique_string));

}