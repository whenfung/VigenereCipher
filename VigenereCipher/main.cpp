#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class VigenereCipher {
public:
	string plaintext = "";
	string ciphertext = "";
	VigenereCipher(string keyword) {
		secretKeyWord = keyword;
		initSecretKeyNum();
	}

	string Encrypt(string plaintext) {
		//转成小写字母
		transform(plaintext.begin(), plaintext.end(), plaintext.begin(), tolower);	
		ciphertext = transPlainToCipher(plaintext);
		return ciphertext;
	}

	string Decrypt(string ciphertext) {
		plaintext = transCipherToPlain(ciphertext);
		return plaintext;
	}

private:
	string secretKeyWord = "china";
	int secretKeyNum[5];

	//Get secretKeyNum，得到密钥数字编号，比如a为0
	void initSecretKeyNum() {
		for (unsigned int i = 0; i < secretKeyWord.size(); ++i)
		{
			secretKeyNum[i] = secretKeyWord[i] - 'a';
		}
	}

	//Trans plaintext to ciphertext
	string transPlainToCipher(string plaintext) {
		ciphertext = "";
		for (unsigned int i = 0; i < plaintext.size(); ++i)
		{
			if (plaintext[i] != ' ')//排除空格
			{
				ciphertext += (char)((plaintext[i] - 'a' + secretKeyNum[i % secretKeyWord.size()]) % 26 + 'a');
			}
			else
			{
				ciphertext += ' ';
			}
		}
		return ciphertext;
	}

	//Trans ciphertext to plaintext
	string transCipherToPlain(string ciphertext) {
		plaintext = "";
		for (unsigned int i = 0; i < ciphertext.size(); ++i)
		{
			if (ciphertext[i] != ' ')
			{
				plaintext += (char)((ciphertext[i] - 'a' - secretKeyNum[i % secretKeyWord.size()] + 26) % 26 + 'a');
			}
			else
			{
				plaintext += ' ';
			}
		}
		return plaintext;
	}
};

int main() {
	string plaintext = "vige";
	string ciphertext = "vjie";
	string key = "abc";
	VigenereCipher vc(key);

	plaintext = vc.Decrypt(ciphertext);
	cout << plaintext << endl;
	getchar();
	return 0;
}