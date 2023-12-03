#include <iostream>
#include <algorithm>

double calculateProductOfPositives(double arr[], int size) {
    double product = 1.0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            product *= arr[i];
        }
    }

    return product;
}

int main() {
    const int maxSize = 100;

    int size;
    std::cout << "Введіть розмір масиву (не більше " << maxSize << "): ";
    std::cin >> size;

    if (size <= 0 || size > maxSize) {
        std::cerr << "Некоректний розмір масиву." << std::endl;
        return 1;
    }

    double array[maxSize];
    std::cout << "Введіть елементи масиву:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Елемент " << i + 1 << ": ";
        std::cin >> array[i];
    }

    double productOfPositives = calculateProductOfPositives(array, size);
    std::cout << "Добуток додатних елементів: " << productOfPositives << std::endl;

    auto minElementIterator = std::min_element(array, array + size);
    int minElementIndex = std::distance(array, minElementIterator);
    double sumBeforeMinElement = 0.0;

    for (int i = 0; i < minElementIndex; ++i) {
        sumBeforeMinElement += array[i];
    }

    std::cout << "Сума елементів до мінімального елемента: " << sumBeforeMinElement << std::endl;

    for (int i = 0; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }

    for (int i = 1; i < size; i += 2) {
        for (int j = i + 2; j < size; j += 2) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }

    std::cout << "Відсортований масив:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}