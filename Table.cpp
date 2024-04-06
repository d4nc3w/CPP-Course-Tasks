#include <iostream>

void minMaxRep(int a[], size_t size, int* mn, size_t& in, int*& mx, size_t& ix) {
    int max = a[0];
    int min = a[0];
    int cmax = 1;
    int cmin = 1;
    for (int i = 1; i < size; ++i) {
        if  (a[i] == max)
            cmax++;
        if (a[i] == min)
            cmin++;
        if (a[i] > max) {
            max = a[i];
            cmax = 1;
        }
        if (a[i] < min) {
            min = a[i];
            cmin = 1;
        }
    }
    *mx = max;
    *mn = min;
    ix = cmax;
    in = cmin;
}

int main() {
    using std::cout;
    int a[]{2,3,4,2,7,4,7,2};
    size_t size = sizeof(a)/sizeof(*a);
    int mn, mx;
    int *pMin = &mn;
    int *pMax = &mx;
    size_t in, ix;
    minMaxRep(a,size,pMin,in,pMax,ix);cout << "Array: [ ";
    for (size_t i = 0; i < size; ++i)
        cout << a[i] << " ";
        cout << "]\n";
        cout << "Min = " << mn << ", " << in << " times\n";
        cout << "Max = " << mx << ", " << ix << " times\n";

}

