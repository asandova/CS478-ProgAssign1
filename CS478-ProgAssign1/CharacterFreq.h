#ifndef CHARACTERFREQ_H
#define CHARACTERFREQ_H
#include <vector>

using namespace std;

struct AlphaFreq {
	char character;
	size_t freq;
	//AlphaFreq(char c) :character(c), freq(0) {};
	//AlphaFreq() :character('\0'), freq(0) {};
};

class CharacterFreq {

private:
	vector<AlphaFreq> alphabet;
public:
	CharacterFreq();
	void increment(char c);
	vector<AlphaFreq> getAlphabet();
	void sortAlpha();
	void sortFreq();
	string SAlphabet();
};

#endif // !CHARACTERFREQ_H

