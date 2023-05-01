#include <iostream>
using namespace std;

class Hash_Class {
  int hash_table[20];
  int max = 20;
  int key;

public:
  Hash_Class() {

    for (int i = 0; i < max; i++) {
      hash_table[i] = -1;
    }
  }
  void insert_LP();
  void insert_LPR();
  void Display();
  void Search_LP();
};

void Hash_Class::Display() {
  cout << "Index"
       << "\t\t"
       << "Key" << endl;
  for (int i = 0; i < max; i++) {
    cout << i << "\t\t" << hash_table[i] << endl;
  }
}

void Hash_Class::insert_LP() {
label:
  cout << "Enter the Key" << endl;
  cin >> key;

  int loc = key % max;
  int i;
  if (hash_table[loc] == -1) {
    hash_table[loc] = key;
  } else {
    i = (loc + 1) % max;
    while (hash_table[i] != -1 && i != loc) {
      i = (i + 1) % max;
    }
    if (i == loc) {
      cout << "Hash Table is Full Now..." << endl;
      return;
    }
    hash_table[i] = key;
  }
  int choice;
  cout << "Enter 0 to exit" << endl;
  cin >> choice;
  if (choice == 0) {
    return;
  }
  printf("\n\n");
  goto label;
}

void Hash_Class::Search_LP() {
  int i;
  cout << "Enter the Key to be Searched" << endl;
  cin >> key;

  int loc = key % max;
  if (hash_table[loc] == key) {
    cout << "Key Found Succesfully at Index - " << loc << endl;
    return;
  } else {
    i = (loc + 1) % max;
    while (i != loc) {
      if (hash_table[i] == key) {
        cout << "Key Found Succesfully at Index - " << i << endl;
        return;
      }
      i = (i + 1) % max;
    }
  }
  cout << "Opps...Key Not Found...." << endl;
}

void Hash_Class::insert_LPR() {
label:
  cout << "Enter the Key Value" << endl;
  cin >> key;

  int loc = key % max;
  if (hash_table[loc] == -1) {
    hash_table[loc] = key;
  } else {
    int temp = key;
    if (loc != (hash_table[loc] % max)) {
      temp = hash_table[loc];
      hash_table[loc] = key;
    }
    int i = (loc + 1) % max;
    while (i != loc && hash_table[i] != -1) {
      i = (i + 1) % max;
    }
    if (i == loc) {
      cout << "Hash is Full...." << endl;
      return;
    }
    hash_table[i] = temp;
  }
  int choice;
  cout << "Enter 0 to exit" << endl;
  cin >> choice;
  if (choice == 0) {
    return;
  }
  printf("\n\n");
  goto label;
}

int main() {
  Hash_Class h;
  int choice;
  while (true) {
    cout << "Enter 1 to insert using linear probing" << endl;
    cout << "Enter 2 to search using linear probing" << endl;
    cout << "Enter 3 to insert using linear probing with replacement" << endl;
    cout << "Enter 4 to search using linear probing with replacement" << endl;
    cout << "Enter 5 to display the hash table" << endl;
    cout << "Enter 6 to exit" << endl;

    if (!(cin >> choice)) {
      cout << "Invalid input, please enter a number" << endl;
    }

    switch (choice) {
    case 1:
      h.insert_LP();
      break;

    case 2:
      h.Search_LP();
      break;

    case 3:
      h.insert_LPR();
      break;

    case 4:
      h.Display();
      break;

    case 6:
      cout << "Exiting program..." << endl;
      return 0;

    default:
      cout << "Invalid choice, please enter a number between 1 and 6" << endl;
      break;
    }
  }
}