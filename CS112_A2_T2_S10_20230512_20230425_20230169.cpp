// Youssef Mohamed Mahmoud Mohamed - id : 20230512 Problem 2 (Atbash)
// Samya mostafa mohamed attia - id : 20230169 Problem 9 (Rail Fence)
// Menna Moustafa Mohamed Othman - id : 20230425 Problem 5 (Simple Substitution)


#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

string atbashEncrypt(string message) {
    array<char, 53> alphabetical = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                     'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ' };
    array<char, 53> reversedAlphabetical = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n',
                                             'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a',
                                             'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N',
                                             'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A', ' ' };


    string encrypt;
    for (char c : message)
    {
        // see the character index in the alphabet array
        size_t index = 0;
        for (; index < alphabetical.size(); ++index) {
            if (alphabetical[index] == c) {
                // Replace the character with the corresponding character in the reverse alphabet
                encrypt += reversedAlphabetical[index];
                break;
            }
        }
    }
    return encrypt;
}




string simpleSubistitution(string message, string cipherAlphabets) {
    // Encrypt the plaintext using the cipher alphabets
    string ciphertext;
    for (char c : message) {
        if (isalpha(c)) {
            char encryptedChar = cipherAlphabets[static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(tolower(c)) - 'a'];
            ciphertext += encryptedChar;
        }
        else {
            ciphertext += c;
        }
    }
    return ciphertext;
}


// Function to remove non-alphabetic characters and convert to lowercase
string cleanText(const string& text) {
    string cleanedText; // Initialize an empty string to store the cleaned text

    // Iterate through each character in the input text
    for (char c : text) {
        // Check if the character is alphabetic
        if (isalpha(c)) {
            cleanedText += tolower(c); // Convert the character to lowercase and add it to the cleaned text
        }
    }

    return cleanedText; // Return the cleaned text
}

// Function to encrypt a message using the Rail Fence cipher
string encryptRailFence(const string& plaintext, int key) {
    string cleanedText = cleanText(plaintext); // Clean the plaintext
    string encryptedText; // Initialize an empty string to store the encrypted text

    // Iterate through each row in the Rail Fence pattern
    for (int row = 0; row < key; ++row) {
        int index = row; // Initialize the index for the current row
        bool down = true; // Initialize a flag to indicate the direction of movement

        // Loop through the characters in the cleaned text
        while (index < cleanedText.length()) {
            encryptedText += cleanedText[index]; // Add the character to the encrypted text

            // Calculate the next index based on the current row and direction
            if (row == 0 || row == key - 1) {
                index += 2 * (key - 1); // For the first and last rows, move by the cycle length
            }
            else {
                if (down) {
                    index += 2 * (key - row - 1); // Move down the diagonal
                }
                else {
                    index += 2 * row; // Move up the diagonal
                }
                down = !down; // Toggle the direction flag
            }
        }
    }

    return encryptedText; // Return the encrypted text
}

// Function to decrypt a message encrypted with the Rail Fence cipher
string decryptRailFence(const string& ciphertext, int key) {
    string cleanedText = cleanText(ciphertext); // Clean the ciphertext
    string decryptedText(cleanedText.length(), ' '); // Initialize a string to store the decrypted text with spaces
    int cycleLength = 2 * (key - 1); // Calculate the length of each cycle
    int index = 0; // Initialize the index for filling the decrypted text

    // Iterate through each row in the Rail Fence pattern
    for (int row = 0; row < key; ++row) {
        int i = row; // Initialize the index for the current row
        bool down = true; // Initialize a flag to indicate the direction of movement

        // Loop through the characters in the cleaned text
        while (i < cleanedText.length()) {
            decryptedText[i] = cleanedText[index++]; // Fill the decrypted text with characters from the cleaned text

            // Calculate the next index based on the current row and direction
            if (row == 0 || row == key - 1) {
                i += cycleLength; // For the first and last rows, move by the cycle length
            }
            else {
                if (down) {
                    i += 2 * (key - row - 1); // Move down the diagonal
                }
                else {
                    i += 2 * row; // Move up the diagonal
                }
                down = !down; // Toggle the direction flag
            }
        }
    }

    return decryptedText; // Return the decrypted text
}

int main() {
    int cipherChoice;
    int operationChoice;
    string message;
    int key;

    do {
        // Display menu options
        cout << "Ahlan ya user ya habibi." << endl;
        cout << "Choose a cipher type:" << endl;
        cout << "1- Atbash Cipher" << endl;
        cout << "2- Rail Fence Cipher" << endl;
        cout << "3- Substitution Cipher" << endl;
        cout << "4- End" << endl;
        cout << ">> ";
        cin >> cipherChoice;




        switch (cipherChoice) {
            case 1: // Encrypt a message
                cout << "Choose operation:" << endl;
                cout << "1- Encrypt" << endl;
                cout << "2- Decrypt" << endl;
                cout << ">> ";
                cin >> operationChoice;

                cout << "Please enter the message: ";
                cin.ignore();
                getline(cin, message);

                if (operationChoice == 1) {
                    string result = atbashEncrypt(message);
                    cout << "Encrypted message: " << result << endl;
                }
                else if (operationChoice == 2) {
                    string result = atbashEncrypt(message);
                    cout << "Decrypted message: " << result << endl;
                }
                else {
                    cout << "Invalid choice. Please enter a valid option." << endl;
                }
                break;



            case 2:
                cout << "Choose operation:" << endl;
                cout << "1- Encrypt" << endl;
                cout << "2- Decrypt" << endl;
                cout << ">> ";
                cin >> operationChoice;

                cout << "Please enter the message: ";
                cin.ignore();
                getline(cin, message);
                cout << "Enter the key for decryption: ";
                cin >> key; // Read the decryption key

                if (operationChoice == 1) {
                    string result = encryptRailFence(message, key);
                    cout << "Encrypted message: " << result << endl;
                }
                else if (operationChoice == 2) {
                    string result = decryptRailFence(message, key);
                    cout << "Decrypted message: " << result << endl;
                }
                else {
                    cout << "Invalid choice. Please enter a valid option." << endl;
                }
                break;
            case 3:
                string inputKey;

                cout << "please enter your key : ";
                cin >> inputKey;

                for (char& C : inputKey) { C = tolower(C); }
                // Check if the key has 5 letters or not

                if (inputKey.length() < 5 || inputKey.length() > 5) {
                    cout << "please enter 5 letters : ";
                    cin >> inputKey;
                }

                // Check if the key has unique letters
                if (int(inputKey[0]) == int(inputKey[1]) || int(inputKey[0]) == int(inputKey[2]) || int(inputKey[0]) == int(inputKey[3]) ||
                    int(inputKey[0]) == int(inputKey[4]) || int(inputKey[1]) == int(inputKey[2]) || int(inputKey[1]) == int(inputKey[3]) ||
                    int(inputKey[1]) == int(inputKey[4]) || int(inputKey[2]) == int(inputKey[3]) || int(inputKey[2]) == int(inputKey[4]) ||
                    int(inputKey[3]) == int(inputKey[4])) {

                    cout << "please enter 5 unique letters : ";
                    cin >> inputKey;
                }

                // Array of alphabets
                string alphabets = "abcdefghijklmnopqrstuvwxyz";

                // Delete characters from alphabets that are in the key
                for (char c : inputKey) {
                    alphabets.erase(remove(alphabets.begin(), alphabets.end(), c), alphabets.end());
                }

                // Cipher alphabets
                string cipherAlphabets = inputKey + alphabets;



                cout << "Choose operation:" << endl;
                cout << "1- Encrypt" << endl;
                cout << "2- Decrypt" << endl;
                cout << ">> ";
                cin >> operationChoice;

                cout << "Please enter the message: ";
                cin.ignore();
                getline(cin, message);


                if (operationChoice == 1) {
                    string result = simpleSubistitution(message, cipherAlphabets);
                    cout << "Encrypted message: " << result << endl;
                }
                else if (operationChoice == 2) {
                    string result = simpleSubistitution(message, cipherAlphabets);
                    cout << "Decrypted message: " << result << endl;
                }
                else {
                    cout << "Invalid choice. Please enter a valid option." << endl;
                }
                break;

        }
    } while (cipherChoice != 4);


    return 0;
}
