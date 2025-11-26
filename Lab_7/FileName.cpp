#include <iostream>
#include <stack>
#include <random>
using namespace std;

int simulate(double mu, double eta, int steps) {
    stack<int> st;
    int maxSize = 0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < steps; i++) {
        double r = dist(gen);

        if (r < mu) {
            st.push(1);
        }
        else if (r < mu + eta) {
            if (!st.empty())
                st.pop();
        }

        if (st.size() > maxSize)
            maxSize = st.size();
    }

    return maxSize;
}

int main() {
    double mu, eta;
    cout << " Enter mu: ";
    cin >> mu;
    cout << "Enter eta: ";
    cin >> eta;

    const int RUNS = 50; 
    const int STEPS = 100000; 

    double sumMax = 0;

    for (int i = 0; i < RUNS; i++) {
        sumMax += simulate(mu, eta, STEPS);
    }

    cout << "Averege maximum size of stack = "
        << (sumMax / RUNS) << endl;

    return 0;
}
