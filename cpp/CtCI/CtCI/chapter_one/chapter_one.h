#ifndef CHAPTER_ONE_H_
#define CHAPTER_ONE_H_

#include <string>
#include <vector>
#include <iostream>
#include <bitset>

#include <assert.h> // For testing

class ChapterOne {
public:

	// 1.1 Is Unique
	bool isUnique_vector(const std::string &str);
	bool isUnique_bitset(const std::string &str);
	bool isUnique_noDS(const std::string &str);

	// 1.2 Check Permuation
	bool checkPermutation();

	// 1.3 URLify

	// 1.4 Palindrome Permutation

	// 1.5 One Away

	// 1.6 String Compression

	// 1.7 Rotate Matrix

	// 1.8 Zero Matrix

	// 1.9 String Rotation

	void test();

	ChapterOne() {}
	~ChapterOne() {}

private:
};

#endif // CHAPTER_ONE_H_