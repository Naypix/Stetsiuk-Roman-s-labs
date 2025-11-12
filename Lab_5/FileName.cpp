#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AbstractFile {
public:
    virtual void openFile(const string& filename) = 0; 
    virtual void writeData(const string& data) = 0;   
    virtual void readData() = 0;                       
    virtual ~AbstractFile() {}                    
};


class TextFile : public AbstractFile {
private:
    fstream file;
    string filename;
public:
    void openFile(const string& fname) override {
        filename = fname;
        file.open(filename, ios::in | ios::out | ios::trunc);
        if (!file.is_open())
            cout << "File cannot be opened!" << endl;
        else
            cout << " File is opened succesfully!" << endl;
    }

    void writeData(const string& data) override {
        if (file.is_open()) {
            file << data << endl;
            cout << "Data added to a file." << endl;
        }
        else {
            cout << "File cannot be opened!" << endl;
        }
    }

    void readData() override {
        if (file.is_open()) {
            file.seekg(0);
            cout << "\nContent of '" << filename << "':" << endl;
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
        }
        else {
            cout << "Файл не відкрито!" << endl;
        }
    }

    ~TextFile() {
        if (file.is_open()) file.close();
    }
};

int main() {
    AbstractFile* fileOne = new TextFile();

    fileOne->openFile("data.txt");
    fileOne->writeData("Stetsiuk Roman");
    fileOne->writeData("KN-22/2");
    fileOne->readData();

    delete fileOne;
    return 0;
}
