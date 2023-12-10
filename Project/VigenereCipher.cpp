#include <iostream>
#include <string>
using namespace std;

class VigenereCipher {
public:
    string secretKey;
    // Constructor to initialize the cipher with a key
    VigenereCipher(string key) {
        for (char ch : key) {
            // Convert all characters of the key to uppercase
            if (isupper(ch))
                this->secretKey += ch;
            else if (islower(ch))
                this->secretKey += toupper(ch);
        }
    }

    // Method to encrypt the given text using Vigenère cipher
    string encryptText(string text) {
        string encrypted;
        for (int i = 0, j = 0; i < text.length(); ++i) {
            char letter = text[i];
            // Convert lowercase to uppercase and ignore non-alphabetic characters
            if (islower(letter))
                letter = toupper(letter);
            else if (!isupper(letter))
                continue;
            // Encrypt the letter and add it to the encrypted string
            encrypted += (letter + secretKey[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % secretKey.length();
        }
        return encrypted;
    }

    // Method to decrypt the given text using Vigenère cipher
    string decryptText(string text) {
        string decrypted;
        for (int i = 0, j = 0; i < text.length(); ++i) {
            char letter = text[i];
            // Convert lowercase to uppercase and ignore non-alphabetic characters
            if (islower(letter))
                letter = toupper(letter);
            else if (!isupper(letter))
                continue;
            // Decrypt the letter and add it to the decrypted string
            decrypted += (letter - secretKey[j] + 26) % 26 + 'A';
            j = (j + 1) % secretKey.length();
        }
        return decrypted;
    }
};

int main() {
    char buffer[200];
    string key;
    int option;

    // Prompt the user to choose between encryption and decryption
    cout << "Choose an option: \n(1)Encrypt\n(2)Decrypt\n";
    cin >> option;

    // Prompt the user to enter the secret key
    cout << "Enter the secret key: ";
    cin >> key;
    // Clear the input buffer
    cin.ignore();
    // Create an instance of VigenereCipher with the provided key
    VigenereCipher cipher(key);

    if (option == 1) {
        // Handle encryption
        cout << "Type a message to encrypt: ";
        cin.getline(buffer, 200);
        string original = buffer;
        string encryptedMessage = cipher.encryptText(original);
        cout << "The encrypted message is: " << encryptedMessage << endl;
    } else if (option == 2) {
        // Handle decryption
        cout << "Type a message to decrypt: ";
        cin.getline(buffer, 200);
        string original = buffer;
        string decryptedMessage = cipher.decryptText(original);
        cout << "The decrypted message is: " << decryptedMessage << endl;
    } else {
        // Handle invalid option
        cout << "Exiting the program.";
    }

    return 0;
}
