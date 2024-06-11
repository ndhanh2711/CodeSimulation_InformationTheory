#include <iostream>
#include <limits>
#include <string>

using namespace std;
string rm_Spaces(const string &input) {
  string result;
  for (char c : input) {
    if (c != ' ') {
      result += c;
    }
  }
  return result;
}
string encrypt_Scytale(const string &chuoi, int a) {
  string result = rm_Spaces(chuoi);
  int n = result.length();
  int socot = (n + a - 1) / a;
  int space = a * socot - n;
  char **arr = new char *[a];
  for (int i = 0; i < a; i++) {
    arr[i] = new char[socot];
  }

  int chiso = 0;
  if (n == a * socot) {
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < socot; j++) {
        arr[i][j] = result[chiso];
        chiso++;
      }
    }
  }

  else {
    for (int i = 0; i < a - space; i++) {
      for (int j = 0; j < socot; j++) {
        if (chiso < n) {
          arr[i][j] = result[chiso];
          chiso++;
        }
      }
    }
    for (int i = a - space; i < a; i++) {
      for (int j = 0; j < socot - 1; j++) {
        arr[i][j] = result[chiso];
        chiso++;
      }
      arr[i][socot - 1] = ' ';
    }
  }

  string mahoa;
  for (int j = 0; j < socot; j++) {
    for (int i = 0; i < a; i++) {
      mahoa += arr[i][j];
    }
  }

  for (int i = 0; i < a; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  string Mahoa = rm_Spaces(mahoa);
  return Mahoa;
}
string decrypt_Scytale(const string &chuoi, int a) {
  int n = chuoi.length();
  int socot = (n + a - 1) / a;
  char *e = new char[a * socot];
  int chiso_e = 0;
  for (int i = 0; i < a * socot; i++) {
    if (chiso_e < n) {
      e[i] = chuoi[chiso_e];
      chiso_e++;
    } else {
      e[i] = ' ';
    }
  }

  char **arr = new char *[a];
  for (int i = 0; i < a; i++) {
    arr[i] = new char[socot];
  }
  int chiso = 0;
  for (int j = 0; j < socot; j++) {
    for (int i = 0; i < a; i++) {
      arr[i][j] = e[chiso];
      chiso++;
    }
  }

  string giaiMa;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < socot; j++) {
      giaiMa += arr[i][j];
    }
  }

  for (int i = 0; i < a; i++) {
    delete[] arr[i];
  }
  delete[] arr;
  string GiaiMa = rm_Spaces(giaiMa);

  return GiaiMa;
}
int enter_key() {
  int num;
  cout << "Enter key: ";
  while (true) {
    cin >> num;
    if (cin.fail() || num <= 0) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid value. Please try again. ";
    } else {
      return num;
    }
  }
}

string enter_text() {
  string input;
  bool valid;
  do {
    valid = true;
    cout << "Enter text (only 0 and 1): ";
    getline(cin, input);
    for (char c : input) {
      if (c != '0' && c != '1') {
        valid = false;
        cout << "Invalid input. ";
        break;
      }
    }
  } while (!valid);
  return input;
}
string enter_text2() {
  string input;
  cout << "Enter text: ";
  getline(cin,input);
  return input;
}
int main() {
    while(1){
        int lc;
        cout << "_____________MENU____________" << endl;
        cout << "| 1. Message Encryption       |" << endl;
        cout << "| 2. Binary Sequence Encoding |" << endl;
        cout << "| 0. end the program          |" << endl;
        cout << "!-----------------------------|" << endl;
        cout << "Select: ";
        cin >> lc;
        if(lc == 2){
        int option;
        while (1) {
            cout << ".____SCYTALE CIPHER____." << endl;
            cout << "|  1. ECRYPT           |" << endl;
            cout << "|  2. DECRYPTION       |" << endl;
            cout << "|  0. Exit             |" << endl;
            cout << "!______________________!" << endl;
            cout << "SELECT OPTION: ";
            while (true) {
            cin >> option;
            cin.ignore();
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number. ";
                continue;
            }
            if (option == 1 || option == 2 || option == 0) {
                break;
            } else {
                cout << "Invalid selection. Please choose again (choose 1 or 2). ";
            }
            }
            if (option == 1) {
            string plaintext = enter_text();
            int rows = enter_key();
            string encryptedText = encrypt_Scytale(plaintext, rows);
            cout << "Text after encoding: " << encryptedText << endl;
            } else if (option == 2) {
            string ciphertext = enter_text();
            int rows = enter_key();
            string decryptedText = decrypt_Scytale(ciphertext, rows);
            cout << "Text after decoding: " << decryptedText << endl;
            } else if (option == 0) {
            break;
            }
        }
        }
    
        else if(lc == 1){
            while(1){
            cout << "____SCYTALE CIPHER____" << endl;
            cout << "|  1. ECRYPT           |" << endl;
            cout << "|  2. DECRYPTION       |" << endl;
            cout << "|  0. Exit.            |" << endl;
            cout << "!______________________!" << endl;
            cout << "SELECT OPTION: ";
            int option;
            while (true){
            cin >> option;
            cin.ignore(); 
            if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                        cout << "Invalid input. Please enter a number. ";
                        continue;
                    }
                if (option == 1 || option == 2 || option == 0) {
                break;
                } else {
                cout << "Invalid selection. Please choose again (choose 1 or 2). " ;
                }
            }
            if (option == 1) {
                string plaintext = enter_text2();
                int rows = enter_key();
                string encryptedText = encrypt_Scytale(plaintext, rows);
                cout << "Text after encoding: " << encryptedText << endl;
            } else if (option == 2) {
                string ciphertext = enter_text2();
                int rows = enter_key();
                string decryptedText = decrypt_Scytale(ciphertext, rows);
                cout << "Text after decoding: " << decryptedText << endl;
            }
                else if(option == 0){
                break;
                }
            }
        }
    }
  return 0;
}