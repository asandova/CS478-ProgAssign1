#include "CharacterFreq.h"

CharacterFreq::CharacterFreq() {
	alphabet = vector<AlphaFreq>();

	for (int i = 0; i < 26; i++) {
		AlphaFreq n;
		n.character = 'A' + i;
		n.freq = 0;
		alphabet.push_back(n);
	}
}

void CharacterFreq::increment(char c) {
	alphabet[c - 'A'].freq++;
}

vector<AlphaFreq> CharacterFreq::getAlphabet() {
	return alphabet;
}

void CharacterFreq::sortAlpha() {

	for (int i = 0; i < alphabet.size(); i++) {
		for (int j = i; j < alphabet.size(); j++) {
			if (alphabet[i].character > alphabet[j].character) {
				AlphaFreq temp;
				temp = alphabet[i];
				alphabet[i] = alphabet[j];
				alphabet[j] = temp;
			}
		}
	}

}
void CharacterFreq::sortFreq() {
	for (int i = 0; i < alphabet.size(); i++) {
		for (int j = i; j < alphabet.size(); j++) {
			if (alphabet[i].freq < alphabet[j].freq) {
				AlphaFreq temp;
				temp = alphabet[i];
				alphabet[i] = alphabet[j];
				alphabet[j] = temp;
			}
		}
	}
}

string CharacterFreq::SAlphabet() {
	string s = "";
	for (vector<AlphaFreq>::iterator itr = alphabet.begin(); itr != alphabet.end(); ++itr) {
		s = s + itr->character;
	}
	return s;
}