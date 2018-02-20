#ifndef SUBSTITUTIONCIPHER
#define SUBSTITUTIONCIPHER
#include <string>
#include <vector>
#include "CharacterFreq.h"

using namespace std;

class SubCipher {
	public:
		//stores the Freqency alphabet.
		static const char * FreqAlpha;
		//counts the frequency of each letter in the given cipher text
		static CharacterFreq CharFreq(string Cipher);
		//Reads a file containing the cipher text, return a string
		static string readCipher(const char* filename);
		//decode the cipher text with the analysed character freqency map named key
		static string decode(string cipher,string key);
		//encode the text with the precalulated freqency mapping name key(for texting)
		static string encode(string text,string key);

};
#endif // !SUBSTITUTIONCIPHER
