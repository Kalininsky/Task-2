#include <iostream>
using namespace std;

int** Create(size_t n, size_t m)
{
    int** M = new int* [n];
    for (size_t i = 0; i < n; ++i)
    {
        M[i] = new int[m];
    }
    return M;
}
//
// Удаление матрицы
//
void Free(int** M, size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        delete[] M[i];
    }
    delete[] M;
}
//
// ввод матрицы
//
void Input(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << "M[" << i << "][" << j << "] = ";
            std::cin >> M[i][j];
        }
    }
}
//
// заполнение матрицы случайными числами из диапазона [0, 99]
//
void FillRandomNumbers(int** Task, const size_t Hw, const size_t Dz)
{
    srand((unsigned int)time(0)); // инициализируем ПГСЧ

    for (size_t x = 0; x < Hw; x++)
        for (size_t v = 0; v < Dz; v++)
            Task[x][v] = rand() % 100; // присваиваем СЧ
}
//
// Печать матрицы 
//
void Print(int** M, size_t n, size_t m) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << M[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}


int main()
{

    setlocale(LC_ALL, "Rus");

    size_t n, m;

    // вводим размерность матрицы
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> m;

    // выделяем память под матрицу
    int** A = Create(n, m);

    // ввод матрицы
    //Input( A, n, m );
    // заполнение случайными числами (вместо ввода)
    FillRandomNumbers(A, n, m);


    // Вывод матрицы
    Print(A, n, m);

    // освобождаем память, выделенную под матрицу и вектор
    Free(A, n);



    return 0;
}


