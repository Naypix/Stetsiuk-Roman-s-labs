#pragma once
#include <iostream>
#include <string>
using namespace std;

class kafedra {
private:
    string zav_kafedry;
    int quantityOfWorkers;
public:
    kafedra();
    kafedra(string a, int b);
    string GetZavName();
    void SetZavName(string a);
    int GetQuantityOfworkers();
    void SetQuantityOfWorkers(int b);
    void PrintKafedra();
};

class institute {
private:
    string dyrector;
    kafedra* arrKafedra;
    int kafCount;

public:
    institute();
    institute(string a, int n);
    ~institute();
    void SetKafedra(int i, const kafedra& k);
    string GetDyrectorName();
    void SetDyrectorName(string a);
    void PrintInstitute();
    int TotalWorkers();
};

class university {
private:
    string rektor;
    institute* arrInstitutes;
    int instCount;
public:
    university();
    university(string a, int n);
    ~university();
    void SetInstitute(int idx, const institute& ins);
    int TotalWorkers();
    string GetRektorName();
    void SetRektorName(string a);
    void PrintUniversity();
};

