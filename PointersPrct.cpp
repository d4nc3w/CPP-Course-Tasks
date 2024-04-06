#include <iostream>
#include <vector>

void MaxMin(const int *tab, const int size, int *max, int &min, int **cMax, int *&cMin) {
    int inMax = tab[0];
    int inMin = tab[0];
    int inCMax = 1;
    int inCMin = 1;
    for (int i = 1; i < size; ++i) {
        if (tab[i] == inMax)
            inCMax++;
        if (tab[i] == inMin)
            inCMin++;
        if (tab[i] > inMax) {
            inMax = tab[i];
            inCMax = 1;
        }
        if (tab[i] < inMin) {
            inMin = tab[i];
            inCMin = 1;
        }
    }
    *max = inMax;
    min = inMin;
    **cMax = inCMax;
    *cMin = inCMin;
}

int main() {
    int min;
    int max;
    int cMax;
    int cMin;

    int *pCmax = &cMax;
    int *pCMin = &cMin;

    const int size = 12;
    int tab[size] = {1, 2, 3, 42, 5, 32, 22, 1, 1, 3, 2, 42};

    MaxMin(tab, size, &max, min, &pCmax, pCMin);

    std::cout << "max -> " << max << std::endl;
    std::cout << "min -> " << min << std::endl;
    std::cout << "cMax -> " << cMax << std::endl;
    std::cout << "cMin -> " << cMin << std::endl;
}
