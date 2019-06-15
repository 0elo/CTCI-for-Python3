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



void ChapterOne::test() {

	std::cout << "Chapter 1 | Arrays and Strings" << std::endl << std::endl;

	// 1.1 Is Unique
	std::cout << "1.1 Is Unique: Implement an algorithm to determine if "
		"a string has all unique characters. What if you cannot use "
        "additional data structures?" << std::endl << std::endl;
	
	std::string unique_string = "abcdefgh1234567890jklmnopqrstuvwxyz";
	std::string not_unique_string = unique_string + "xdxdxd";

	std::cout << "Testing with unique string: " << unique_string << std::endl;
	assert(isUnique_vector(unique_string) == true);
	assert(isUnique_bitset(unique_string) == true);
	assert(isUnique_noDS(unique_string) == true);
	std::cout << "Testing with not unique string:" << not_unique_string << std::endl;
	assert(isUnique_vector(not_unique_string) == false);
	assert(isUnique_bitset(not_unique_string) == false);
	assert(isUnique_noDS(not_unique_string) == false);



}