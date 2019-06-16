#ifndef CHAPTER_ONE_H
#define CHAPTER_ONE_H

#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm> // For sort
#include <numeric> // For accumulate

#include <assert.h> // For testing

// Arrays and Strings
class ChapterOne {
public:

	// 1.1 Is Unique
	bool isUnique_vector(const std::string &str);
	bool isUnique_bitset(const std::string &str);
	bool isUnique_noDS(const std::string &str);

	// 1.2 Check Permuation
	bool checkPermutation_sort(std::string &str1, std::string &str2);
	bool checkPermutation_count(std::string &str1, std::string &str2);

	// 1.3 URLify
	void urlify(char *str, int len);

	// 1.4 Palindrome Permutation

	// 1.5 One Away

	// 1.6 String Compression

	// 1.7 Rotate Matrix

	// 1.8 Zero Matrix

	// 1.9 String Rotation

	// Support functions
	inline static void sort_string(std::string &str) {
		sort(str.begin(), str.end()); // O(nlogn) sort from <algorithm>
	}

	// Test functionality
	void test();

	ChapterOne() {}
	~ChapterOne() {}

private:
};

#endif // CHAPTER_ONE_H_