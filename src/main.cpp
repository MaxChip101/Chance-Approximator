#include <iostream>
#include <random>
#include <time.h>
#include <chrono>

using namespace std;

int main() {

    int iterations;
    int chance_size;

    cout << "chance (1/?): ";
    cin >> chance_size;
    cout << "iterations: ";
    cin >> iterations;

    float calculated_chance;

    auto start = chrono::high_resolution_clock::now();

    srand(time(NULL));
    int random;
    for(int i = 0; i < iterations; i++) {
        random = rand() % chance_size + 1;
        if(random == 1) {
            calculated_chance += 1;
        }
        cout << random << ", ";
    }

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

    calculated_chance = float(calculated_chance) / float(iterations);

    cout << endl << "calculated in: " << float(duration.count()) / 1000000.0 << " seconds" << endl;
    cout << "calculated chance: " << calculated_chance << endl;
    cout << "actual chance: " << 1 / float(chance_size) << endl;

    return 0;
}