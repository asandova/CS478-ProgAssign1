#include <iostream>
#include "SubsitutionCipher.h"
#include "CharacterFreq.h"
//#include "bof.c"

using namespace std;

void testall() {

	string s = SubCipher::readCipher("ciphertext.txt");
	cout << s << endl;
	CharacterFreq t = SubCipher::CharFreq(s);
	t.sortFreq();
	cout << "Key: " << t.SAlphabet() << endl;
	string d = SubCipher::decode(s, t.SAlphabet());
	cout << d << endl;

}
int main() {
	testall();

	return 1;
}