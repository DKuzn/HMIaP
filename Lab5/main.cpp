#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>

template <typename T>
std::vector<T> ArrayInit(T n)
{
    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::vector<T> array = {};
    for (T i = 0; i < n; i++) {
        array.push_back(1 + mersenne() % 100);
    }
    return array;
}

template <typename T>
void OutputArray(std::vector<T> array)
{
    T n = array.size();
    for (T i = 0; i < n; i++) {
        std::cout << std::setw(3) << array[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T> MergeSort(std::vector<T> array)
{
    T n = array.size();
    T step = 1;
    std::vector<T> temp = {};
    for (T i = 0; i < n; i++){
        temp.push_back(0);
    }
    while (step < n){
        T index = 0;
        T l = 0;
        T m = l + step;
        T r = l + step * 2;
        while (l < n){
            if (m >= n){
                m = n;
            }
            if (r >= n){
                r = n;
            }
            T i1 = l, i2 = m;
            while (i1 < m && i2 < r){
                if (array[i1] < array[i2]){
                    temp[index++] = array[i1++];
                }
                else {
                    temp[index++] = array[i2++];
                }
            }
            while (i1 < m){
                temp[index++] = array[i1++];
            }
            while (i2 < r){
                temp[index++] = array[i2++];
            }
            l += step * 2;
            m += step * 2;
            r += step * 2;
        }
        for (T i = 0; i < n; i++){
            array[i] = temp[i];
        }
        step *= 2;
    }
    return array;
}

template <typename T>
T prog(T n)
{
    std::vector<T> array = ArrayInit(n);
    std::cout << "Исходный массив:" << "\n";
    OutputArray(array);
    std::vector<T> sarray = MergeSort(array);
    std::cout << "Отсортированный массив:" << "\n";
    OutputArray(sarray);
}

int main()
{
    int n = 10;
    float m = 10;
    char p = 10;
    prog(n);
    prog(m);
    prog(p);
    return 0;
}
