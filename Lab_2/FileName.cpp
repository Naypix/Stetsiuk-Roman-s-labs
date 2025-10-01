#include <Windows.h>
#include "Header.h"
#include <string.h>


kafedra::kafedra() {
    zav_kafedry = "";
    quantityOfWorkers = 0;
}
kafedra::kafedra(string a, int b) {
    zav_kafedry = a;
    quantityOfWorkers = b;
}
string kafedra::GetZavName() {
    return zav_kafedry;
}
void kafedra::SetZavName(string a) {
    zav_kafedry = a;
}
int kafedra::GetQuantityOfworkers() {
    return quantityOfWorkers;
}
void kafedra::SetQuantityOfWorkers(int b) {
    quantityOfWorkers = b;
}
void kafedra::PrintKafedra() {
    cout << "Завідуючий кафедри : " << zav_kafedry
        << "\nКількість працівників : " << quantityOfWorkers << endl;
}


institute::institute() {
    dyrector = "";
    kafCount = 0;
    arrKafedra = nullptr;
}
institute::institute(string a, int n) {
    dyrector = a;
    kafCount = n;
    arrKafedra = new kafedra[n];
}
institute::~institute() {
    delete[] arrKafedra;
}
void institute::SetKafedra(int i, const kafedra& k) {
    if (i >= 0 && i < kafCount) {
        arrKafedra[i] = k;
    }
}
string institute::GetDyrectorName() {
    return dyrector;
}
void institute::SetDyrectorName(string a) {
    dyrector = a;
}
void institute::PrintInstitute() {
    cout << "Директор : " << dyrector << endl;
    for (int i = 0; i < kafCount; i++) {
        cout << "  Кафедра #" << i + 1 << ":\n";
        arrKafedra[i].PrintKafedra();
    }
    cout << "  Всього працівників в інституті: " << TotalWorkers() << endl;
}
int institute::TotalWorkers() {
    int sum = 0;
    for (int i = 0; i < kafCount; i++) {
        sum += arrKafedra[i].GetQuantityOfworkers();
    }
    return sum;
}



university::university() {
    rektor = "";
    instCount = 0;
    arrInstitutes = nullptr;
}
university::university(string a, int n) {
    rektor = a;
    instCount = n;
    arrInstitutes = new institute[n];
}
university::~university() {
    delete[] arrInstitutes;
}
void university::SetInstitute(int idx, const institute& ins) {
    if (idx >= 0 && idx < instCount) {
        arrInstitutes[idx] = ins;
    }
}
int university::TotalWorkers() {
    int sum = 0;
    for (int i = 0; i < instCount; i++) {
        sum += arrInstitutes[i].TotalWorkers();
    }
    return sum;
}
string university::GetRektorName() {
    return rektor;
}
void university::SetRektorName(string a) {
    rektor = a;
}
void university::PrintUniversity() {
    cout << "Ректор : " << rektor << endl;
    for (int i = 0; i < instCount; i++) {
        cout << "\nІнститут #" << i + 1 << ":\n";
        arrInstitutes[i].PrintInstitute();
    }
    cout << "\nЗагальна кількість працівників університету: " << TotalWorkers() << endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    kafedra k1("Стецюк", 20);
    kafedra k2("Іваненко", 15);

    institute inst("Слобода", 2);
    inst.SetKafedra(0, k1);
    inst.SetKafedra(1, k2);

    university uni("Рощук", 1);
    uni.SetInstitute(0, inst);

    uni.PrintUniversity();
    return 0;
}
