/*
 * Title: hw7_3
 * Abstract: displays the performance of three different sorting algorithms 
 * Author: Albert Salas
 * ID: 7777
 * Date: 03/27/2020
 */

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

/*
 * Makes a copy of the original array
 * so that the sorting algorithms
 * use the same set of numbers
 * when measuring performance
 */
int *copyArray(const int *orig, int size) {
    int *newArr;
    newArr = new int[size];
    for (int i = 0; i < size; i++) {
        newArr[i] = orig[i];
    }
    return newArr;
}

double averageTime(const double *arr, int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total / size;
}

// https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int num = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
}

void insertionSort(double arr[], int size) {
    for (int i = 1; i < size; i++) {
        double num = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = num;
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    auto *L = new int[n1];
    auto *R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// https://www.geeksforgeeks.org/merge-sort/
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// https://www.geeksforgeeks.org/quick-sort/
void quickSort(int a[], int lo, int hi) {
    while (lo < hi) {
        int j = partition(a, lo, hi);
        if (j - lo < hi - j) {
            quickSort(a, lo, j - 1);
            lo = j + 1;
        } else {
            quickSort(a, j + 1, hi);
            hi = j - 1;
        }
    }
}

void run(int arr[], int inputSize) {
    using namespace chrono;
    auto *insertionSortRuntimes = new double[3];
    auto *mergeSortRuntimes = new double[3];
    auto *quickSortRuntimes = new double[3];
    int counter = 0;

    cout << "========================== 1st Run =========================" << endl;

    cout << "Insertion sort:";
    int *copy = copyArray(arr, inputSize);
    auto start = system_clock::now();
    insertionSort(copy, inputSize);
    auto end = system_clock::now();
    delete[] copy;
    duration<double> elapsedTime = end - start;
    insertionSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << insertionSortRuntimes[counter] << " milliseconds \n";

    cout << "Merge sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    mergeSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    mergeSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << mergeSortRuntimes[counter] << " milliseconds \n";

    cout << "Quick sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    quickSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    quickSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << quickSortRuntimes[counter] << " milliseconds \n";

    cout << "============================================================\n" << endl;
    cout << "========================== 2nd Run =========================" << endl;
    counter++;

    cout << "Insertion sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    insertionSort(copy, inputSize);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    insertionSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << insertionSortRuntimes[counter] << " milliseconds \n";

    cout << "Merge sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    mergeSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    mergeSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << mergeSortRuntimes[counter] << " milliseconds \n";

    cout << "Quick sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    quickSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    quickSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << quickSortRuntimes[counter] << " milliseconds \n";

    cout << "============================================================\n" << endl;
    cout << "========================== 3rd Run =========================" << endl;
    counter++;

    cout << "Insertion sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    insertionSort(copy, inputSize);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    insertionSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << insertionSortRuntimes[counter] << " milliseconds \n";

    cout << "Merge sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    mergeSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    mergeSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << mergeSortRuntimes[counter] << " milliseconds \n";

    cout << "Quick sort:";
    copy = copyArray(arr, inputSize);
    start = system_clock::now();
    quickSort(copy, 0, inputSize - 1);
    end = system_clock::now();
    delete[] copy;
    elapsedTime = end - start;
    quickSortRuntimes[counter] = elapsedTime.count() * 1000;
    cout << quickSortRuntimes[counter] << " milliseconds \n";

    auto *averageTimes = new double[3];
    averageTimes[0] = averageTime(insertionSortRuntimes, 3);
    averageTimes[1] = averageTime(mergeSortRuntimes, 3);
    averageTimes[2] = averageTime(quickSortRuntimes, 3);
    double iTime = averageTimes[0];
    double mTime = averageTimes[1];
    double qTime = averageTimes[2];
    insertionSort(averageTimes, 3);

    cout << "============================================================\n" << endl;
    cout << "========================== Ranking =========================" << endl;
    for (int i = 0; i < 3; i++) {
        if (averageTimes[i] == iTime) {
            cout << "(" << i + 1 << ") " << "Insertion sort" << endl;
            iTime = -1;
        } else if (averageTimes[i] == mTime) {
            cout << "(" << i + 1 << ") " << "Merge sort" << endl;
            mTime = -1;
        } else if (averageTimes[i] == qTime) {
            cout << "(" << i + 1 << ") " << "Quick sort" << endl;
            qTime = -1;
        }

    }
    cout << "============================================================" << endl;
}

void fill(int *arr, int order, int inputSize) {
    cout << "============================================================" << endl;
    if (order == 1) {
        cout << "Generate input data in ascending order . . .\n";
        for (int i = 0; i < inputSize; i++) {
            arr[i] = i + 1;
        }
    } else if (order == 2) {
        cout << "Generate input data in descending order . . .\n";
        for (int i = 0; i < inputSize; i++) {
            arr[i] = inputSize - i;
        }
    } else if (order == 3) {
        cout << "Generate input data in random order . . .\n";
        random_device generator;
        mt19937 mt(generator());
        uniform_int_distribution<int> dist(0, inputSize);
        for (int i = 0; i < inputSize; i++) {
            arr[i] = dist(mt);
        }
    }
    cout << "Done.\n"
            "============================================================ \n" << endl;
}

int main() {
    int inputSize;
    cout << "Enter input size:";
    cin >> inputSize;
    int order;
    cout << "========== Select Order of Input Numbers ==========\n"
            "     1. Ascending Order\n"
            "     2. Descending Order\n"
            "     3. Random Order\n"
            "Choose order:";
    cin >> order;
    int *arr = new int[inputSize];
    fill(arr, order, inputSize);
    run(arr, inputSize);
    return 0;
}