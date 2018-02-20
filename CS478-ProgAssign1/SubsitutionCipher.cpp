#include "SubsitutionCipher.h"
#include <cctype>
#include <fstream>
#include <iostream>
using namespace std;

const char* SubCipher::FreqAlpha = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

CharacterFreq SubCipher::CharFreq(string Cipher) {
	CharacterFreq f = CharacterFreq();

	for (size_t i = 0; i < Cipher.size(); i++) {
		char c = Cipher[i];
		if ( isalpha(c) ) {
			c = toupper(c);
			f.increment(c);
		}
	}
	return f;
}

string SubCipher::readCipher(const char* filename) {
	/*
		ReadCipher takes a text file and reads each line and outputs a string of that data
		if the file failed to open a empty string is returned
	*/
	fstream f;
	f.open(filename, fstream::in);
	char line[256];
	string Cipher = "";
	if (f.is_open()) {
		while (!f.eof()) {
			f.getline(line,256);
			cout << line << endl;//debug
			Cipher += string(line);
		}
		f.close();
	}
	else {
		cout << "failed to open: " << filename << endl;
		
	}
	return Cipher;
}

string SubCipher::decode(string cipher,string key) {
	/*
		decode will translate a string of cipher text to plaintext
		it requires the cipher texts and a key
		Key is the analyzed character freqency in the given cipher
		then it gets the index of each character in the cipher text to where that character is in the key
		then with the index it concatinates the character at index in the known character freqency of the alphabet FreqAlpha to string text
		then returns text 
	*/
	string text = "";
	for (string::iterator itr = cipher.begin(); itr != cipher.end(); ++itr) {
		char c = *itr;
		for (int i = 0; i < key.size(); i++) {
			if (*itr == key[i]) {
				text += FreqAlpha[i];
			}
		}
		
	}
	return text;
}

string SubCipher::encode(string text, string key) {
	string cipherText = "";
	
	for (string::iterator itr = text.begin(); itr != text.end(); ++itr) {
		char c = *itr;
		for (int i = 0; i < 26; i++) {
			if (*itr == FreqAlpha[i]) {
				cipherText += key[i];
			}
		}

	}
	return cipherText;
}
