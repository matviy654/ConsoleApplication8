#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>

const int N = 4;

// Перевантажені функції 
void initMatrix(int matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = rand() % 100;
}

void initMatrix(double matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = (rand() % 100) / 10.0;
}

void initMatrix(char matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            matrix[i][j] = 'A' + (rand() % 26); // Заповнення
}

// Перевантажені функції виведення матриці
void printMatrix(int matrix[][N], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void printMatrix(double matrix[][N], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

void printMatrix(char matrix[][N], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            std::cout << matrix[i][j] << "\t";
        std::cout << std::endl;
    }
}

// Перевантажені функції для пошуку  елементів на головній діагоналі
int minDiag(int matrix[][N], int N) {
    int min = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] < min)
            min = matrix[i][i];
    return min;
}

int maxDiag(int matrix[][N], int N) {
    int max = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] > max)
            max = matrix[i][i];
    return max;
}

double minDiag(double matrix[][N], int N) {
    double min = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] < min)
            min = matrix[i][i];
    return min;
}

double maxDiag(double matrix[][N], int N) {
    double max = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] > max)
            max = matrix[i][i];
    return max;
}

char minDiag(char matrix[][N], int N) {
    char min = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] < min)
            min = matrix[i][i];
    return min;
}

char maxDiag(char matrix[][N], int N) {
    char max = matrix[0][0];
    for (int i = 1; i < N; ++i)
        if (matrix[i][i] > max)
            max = matrix[i][i];
    return max;
}

// Перевантажені функції для сортування рядків матриці
void sortRows(int matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        std::sort(matrix[i], matrix[i] + N);
}

void sortRows(double matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        std::sort(matrix[i], matrix[i] + N);
}

void sortRows(char matrix[][N], int N) {
    for (int i = 0; i < N; ++i)
        std::sort(matrix[i], matrix[i] + N);
}


int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Функція для генерації випадкового числа
std::string generateNumber() {
    std::string number;
    while (number.length() < 4) {
        char digit = '0' + rand() % 10;
        if (number.find(digit) == std::string::npos) {
            number += digit;
        }
    }
    return number;
}

// Рекурсивна функція для підрахунку спроб у грі "Бики та корови"
int guessNumber(const std::string& secret, int attempts = 0) {
    std::string guess;
    std::cout << "Введіть 4-значне число: ";
    std::cin >> guess;

    if (guess == secret) {
        std::cout << "Ви вгадали число! Кількість спроб: " << attempts + 1 << std::endl;
        return attempts + 1;
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i]) {
            bulls++;
        }
        else if (secret.find(guess[i]) != std::string::npos) {
            cows++;
        }
    }

    std::cout << "Бики: " << bulls << ", Корови: " << cows << std::endl;
    return guessNumber(secret, attempts + 1);
}

int main() {
    srand(time(0));

    // Завдання 1: Робота з матрицями
    int matrixInt[N][N];
    double matrixDouble[N][N];
    char matrixChar[N][N];

    initMatrix(matrixInt, N);
    initMatrix(matrixDouble, N);
    initMatrix(matrixChar, N);

    std::cout << "Int matrix:\n";
    printMatrix(matrixInt, N);
    std::cout << "Min element on diagonal: " << minDiag(matrixInt, N) << std::endl;
    std::cout << "Max element on diagonal: " << maxDiag(matrixInt, N) << std::endl;
    sortRows(matrixInt, N);
    std::cout << "Sorted rows:\n";
    printMatrix(matrixInt, N);

    std::cout << "\nDouble matrix:\n";
    printMatrix(matrixDouble, N);
    std::cout << "Min element on diagonal: " << minDiag(matrixDouble, N) << std::endl;
    std::cout << "Max element on diagonal: " << maxDiag(matrixDouble, N) << std::endl;
    sortRows(matrixDouble, N);
    std::cout << "Sorted rows:\n";
    printMatrix(matrixDouble, N);

    std::cout << "\nChar matrix:\n";
    printMatrix(matrixChar, N);
    std::cout << "Min element on diagonal: " << minDiag(matrixChar, N) << std::endl;
    std::cout << "Max element on diagonal: " << maxDiag(matrixChar, N) << std::endl;
    sortRows(matrixChar, N);
    std::cout << "Sorted rows:\n";
    printMatrix(matrixChar, N);

    // Завдання 2: Рекурсивна функція для знаходження НСД
    int a, b;
    std::cout << "\nВведіть два числа для обчислення НСД: ";
    std::cin >> a >> b;
    std::cout << "НСД: " << gcd(a, b) << std::endl;

    // Завдання 3: Гра "Бики та корови"
    std::string secret = generateNumber();
    std::cout << "\nГра 'Бики та корови'.\n";
    guessNumber(secret);

    return 0;
}
