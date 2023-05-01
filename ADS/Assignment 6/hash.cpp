#include <iostream>
#include <fstream>
using namespace std;

struct Record {
    std::string name;
    int age;
};

int hash_function(std::string key, int size) {
    int sum = 0;
    for (char c : key) {
        sum += c;
    }
    return sum % size;
}

class DirectAccessFile {
private:
    Record *table;
    int size;
    int count;
public:
    DirectAccessFile(int size);
    ~DirectAccessFile();
    void add_record(Record record);
    Record search_record(std::string name);
};

DirectAccessFile::DirectAccessFile(int size) {
    this->size = size;
    count = 0;
    table = new Record[size];
    for (int i = 0; i < size; i++) {
        table[i].name = "";
    }
}

DirectAccessFile::~DirectAccessFile() {
    delete[] table;
}

void DirectAccessFile::add_record(Record record) {
    int index = hash_function(record.name, size);
    int i = 0;
    while (i < size) {
        int probe_index = (index + i) % size;
        if (table[probe_index].name == "") {
            table[probe_index] = record;
            count++;
            return;
        }
        i++;
    }
}

Record DirectAccessFile::search_record(std::string name) {
    int index = hash_function(name, size);
    int i = 0;
    while (i < size) {
        int probe_index = (index + i) % size;
        if (table[probe_index].name == name) {
            return table[i];
        }
    }
}

int main() {
    DirectAccessFile file(10);

    // Add some records to the database
    file.add_record({"Alice", 25});
    file.add_record({"Bob", 30});
    file.add_record({"Charlie", 35});
    file.add_record({"Dave", 40});

    // Search for a record by name
    Record record = file.search_record("Charlie");
    std::cout << "Record found: " << record.name << ", " << record.age << std::endl;

    // Modify a record's age

    // Display the entire database
    

    return 0;
}