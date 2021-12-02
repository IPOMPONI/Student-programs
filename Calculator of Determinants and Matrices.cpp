#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void The_determinant_of_the_II_order()                                                                         // Задача 1. Нахождение определителя 2го порядка
{
    int o;
    double a11, a12, a21, a22, x;                                                                             // aij - элемент определителя (строка i/столбец j) ; x - результат
    cout << "Определитель II порядка:\n";
    cout << "\nВведите количество знаков после запятой: "; cin >> o; cout << "\n";
    cout << "Введите значения а11; а12;\n";
    cout << "Введите значения а21; а22;\n\n";
    cout << "|"; cin >> a11 >> a12;  
    cout << "|"; cin >> a21 >> a22;  
    x = a11 * a22 - a21 * a12;
    cout << "\nОтвет: " << fixed << setprecision(o) << x << "\n\n";
    system("pause");
}

void The_determinant_of_the_III_order()                                                                       // Задача 2. Нахождение определителя 3го порядка
{
    int o;
    double a11, a12, a13, a21, a22,a23, a31, a32, a33, x;                                                    // aij - элемент определителя (строка i/столбец j) ; x - результат
    cout << "Определитель III порядка:\n";
    cout << "\nВведите количество знаков после запятой: "; cin >> o; cout << "\n";
    cout << "Введите значения а11; а12; a13;\n";
    cout << "Введите значения а21; а22; а23;\n";
    cout << "Введите значения а31; а32; а33;\n\n";
    cout << "|"; cin >> a11 >> a12 >> a13;
    cout << "|"; cin >> a21 >> a22 >> a23;
    cout << "|"; cin >> a31 >> a32 >> a33;
    x = a11 * a22 * a33 + a12 * a23 * a31 + a21 * a32 * a13 - a31 * a22 * a13 - a21 * a12 * a33 - a32 * a23 * a11;
    cout << "\nОтвет: " << fixed << setprecision(o) << x << "\n\n";
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Gauss_Logic(                                                                                        
    int m,                                                                                               // Число строк матрицы
    int n,                                                                                              // Число столбцов матрицы
    double* Mem,                                                                                       // Адрес массива элементов матрицы
    double Freq = 0.0001                                                                              // Точность вычислений
)                                                                                                    
{                                                                                                    
    int i, j, ac, l;
    double rk;

    i = 0; j = 0;
    while (i < m && j < n)                                                                          // Поиск max элемента в j-ом столбце, начиная с i-ой строки
    {
        rk = 0;
        for (ac = i; ac < m; ++ac)
        {
            if (fabs(Mem[ac * n + j]) > rk)
            {
                l = ac;
                rk = fabs(Mem[ac * n + j]);
            }
        }
        if (rk <= Freq)                                                                          // Если все элемекнты j-го столбца не превосходят заданную точность      
        {
            for (ac = i; ac < m; ++ac)
            {
                Mem[ac * n + j] = 0;                                                            // Обнуление столбца, начиная с i-ой строки
            }
            ++j;
            continue;
        }

        if (l != i)
        {
            for (ac = j; ac < n; ++ac)                                                       // Замена местами i-ой и l-ой строк
            {
                rk = Mem[i * n + ac];
                Mem[i * n + ac] = Mem[l * n + ac];
                Mem[l * n + ac] = (-rk);                                                   // Изменение знака строки  
            }
        }
                                            
        for (ac = i + 1; ac < m; ++ac)                                                   // Обнуление j-го столбца, начиная со след. строки
        {               
            rk = (-Mem[ac * n + j] / Mem[i * n + j]);
            Mem[ac * n + j] = 0;
            for (l = j + 1; l < n; ++l)
            {
                Mem[ac * n + l] += rk * Mem[i * n + l];
            }
        }
        ++i; ++j;                                                                     // Переход к следующему минору
    }
    return i;                                                                        // Возврвт числа ненулевых строк
}

void Step_Matrix()                                                                  // Задача 3. Приведение матрицы к ступенчатому виду методом Гаусса
{
    int m, n, i, j, o, rank;
    double* Mem;
    double Freq = 0.0001, Det;

    cout << "Введите количество знаков после запятой: "; cin >> o; cout << "\n";

    cout << "Введите размеры матрицы m x n: "; cin >> m >> n; cout << "\n";     

    Mem = new double[m * n];                                                     // Выделение памяти под элементы матрицы

    cout << "Введите элементы матрицы:\n\n";                                        
    for (i = 0; i < m; ++i)                                                     // Заполнение матрицы
    {
        for (j = 0; j < n; ++j)
        {
            cin >> (Mem[i * n + j]);
        }
    }

    rank = Gauss_Logic(m, n, Mem, Freq);

    cout << "\nСтупенчатый вид матрицы:\n\n";                                    // Вывод матрицы на экран
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout << fixed << setprecision(o) << Mem[i * n + j] << " ";
        }
        cout << "\n";
    }

    cout << "\nРанг матрицы: " << rank << "\n\n";

    delete[]Mem;
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Matrix_Addition(                                                      // Сумма матриц
    int m,
    int n,
    int o,
    double Res[25][25],
    double A[25][25],
    double B[25][25]
)
{
    int i, j;
    cout << "\nРезультат суммы 2х матриц, есть матрица: \n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            Res[i][j] = A[i][j] + B[i][j];
            cout << fixed << setprecision(o) << Res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

int Matrix_Subtraction(                                              // Вычитание матриц
    int m,
    int n,
    int o,
    double Res[25][25],
    double A[25][25],
    double B[25][25]
)
{
    int i, j;
    cout << "\nРезультат разности 2х матриц, есть матрица: \n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            Res[i][j] = A[i][j] - B[i][j];
            cout << fixed << setprecision(o) << Res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

int Matrix_Multiplication(                                        // Произведение матриц
    int m,
    int n,
    int o,
    double Res[25][25],
    double A[25][25],
    double B[25][25]
)
{
    int i, j, k;
    cout << "\nРезультат произведения 2х матриц, есть матрица: \n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            Res[i][j] = 0;
            for (k = 0; k < m; ++k)
            {
                Res[i][j] += A[i][k] * B[k][j];
            }
            cout << fixed << setprecision(o) << Res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    return 0;
}

void Selection_of_operations_on_matrices(                        // Подменю выбора основных действий над матрицами (+/-/=)
    char ch,
    int m,
    int n,
    int o,
    double Res[25][25],
    double A[25][25],
    double B[25][25]
)
{
    switch (ch)
    {
    case('+'):  Matrix_Addition(m, n, o, Res, A, B);
        break;
    case('-'): Matrix_Subtraction(m, n, o, Res, A, B);
        break;
    case('*'): Matrix_Multiplication(m, n, o, Res, A, B);
        break;
    }
}
void Entering_two_matrices()                                     // Задача 4. Ввод и заполнение 2х матриц                             
{
    int m, n, i, j, o;
    double A[25][25], B[25][25], Res[25][25];
    char ch;
    cout << "Введите количество знаков после запятой для результата: "; cin >> o; cout << "\n";
    cout << "Введите размеры матрицы А m x n: "; cin >> m >> n; cout << "\n";
    cout << "Введите элементы матрицы A:\n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }

    cout << "\nВведите операцию действия над матрицами (Сложение(+)/Вычитание(-)/Умножение(*)): ";  cin >> ch; '+' || '-' && '*'; cout << "\n";
    
    cout << "Введите размеры матрицы B m x n: "; cin >> m >> n; cout << "\n";
    cout << "Введите элементы матрицы B:\n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cin >> B[i][j];
        }
    }
    
    Selection_of_operations_on_matrices(ch, m, n, o, Res, A, B);
    
    system("pause");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Multiplying_a_matrix_by_a_number()                 // Задача 5. Умножение матрицы на число
{
    int m, n, i, j, k, o;
    double A[25][25], B[25][25], Res[25][25];
    char ch;
    cout << "Введите количество знаков после запятой для результата: "; cin >> o; cout << "\n";
    cout << "Введите, во сколько раз нужно увеличить матрицу: ";  cin >> k; cout << "\n";
    cout << "Введите размеры матрицы m x n: "; cin >> m >> n; cout << "\n";
    cout << "Введите элементы матрицы :\n\n";
    for (i = 0; i < m; ++i)                          
    {
        for (j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }
    cout << "\nРезультат умножения матрицы на число, есть матрица: \n\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            Res[i][j] = A[i][j] * k;
            cout << fixed << setprecision(o) << Res[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    system("pause");
}

 
void Choice()                                    // Главное меню
{
    int c;
    while (true)
    {
        system("cls");
        cout << "Выберите одно из следующих действий:\n\n";
        cout << "1. Определитель II порядка.\n";
        cout << "2. Определитель III порядка.\n";
        cout << "3. Приведение матрицы к ступенчатому виду методом Гаусса.\n";
        cout << "4. Основные действия над матрицами (+/-/*).\n";
        cout << "5. Умножение матрицы на число.\n\n";
        cout << "Ваш выбор: "; cin >> c; cout << "\n";

        switch (c)
        {
        case(1): The_determinant_of_the_II_order();
            break;
        case(2): The_determinant_of_the_III_order();
            break;
        case(3): Step_Matrix();
            break;
        case(4): Entering_two_matrices();
            break;
        case(5):  Multiplying_a_matrix_by_a_number();
            break;
        }
        cout << "\n\n";
    }
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "RU");
    Choice();
    return 0;
}

