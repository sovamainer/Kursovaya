#include <iostream>
#include <Windows.h>

using namespace std;

void printMas(int* p, int size) {
    for (int j = 0; j < size * size; j++) {
        if (j % size == 0 and j != 0) {
            cout << "\n";
        }
        cout << " " << *(p + j) << " ";
    }

    Sleep(250);
    system("cls");
}

void swapBlocksCircle(int* p, int size, bool mas) {
    if (mas) {
        cout << "Изначальная матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }

        for (int j = 0; j < size / 2; j++) {
            for (int i = 0; i < size / 2; i++) {
                int key1 = *(p + i + j * size), key2 = *(p + i + size / 2 + j * size), key3 = *(p + i + size * (size / 2) + j * size), key4 = *(p + i + size * size / 2 + (size / 2) + j * size);
                *(p + i + size / 2 + j * size) = *(p + i + j * size);
                *(p + i + size * size / 2 + (size / 2) + j * size) = key2;
                *(p + i + size * size / 2 + j * size) = key4;
                *(p + i + j * size) = key3;
            }
        }

        cout << endl << endl << "Изменённая матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        cout << "Матрица не создана" << endl;
        system("pause");
    }
}

void swapX(int* p, int size, bool mas) {
    if (mas) {
        cout << "Изначальная матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }

        for (int j = 0; j < size / 2; j++) {
            for (int i = 0; i < size / 2; i++) {
                swap(*(p + i + j * size), *(p + i + size / 2 + size * (size / 2) + j * size));
                swap(*(p + size / 2 + i + j * size), *(p + size * (size / 2) + i + j * size));
            }
        }

        cout << endl << endl << "Изменённая матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        cout << "Матрица не создана" << endl;
        system("pause");
    }
}

void swapUpAndDown(int* p, int size, bool mas) {
    if (mas) {
        cout << "Изначальная матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }

        for (int j = 0; j < size / 2; j++) {
            for (int i = 0; i < size / 2; i++) {
                swap(*(p + i + j * size), *(p + size * size / 2 + i + j * size));
                swap(*(p + i + j * size + size / 2), *(p + size * size / 2 + i + j * size + size / 2));
            }
        }

        cout << endl << endl << "Изменённая матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        cout << "Матрица не создана" << endl;
        system("pause");
    }
}

void swapLeftRight(int* p, int size, bool mas) {
    if (mas) {
        cout << "Изначальная матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }

        for (int j = 0; j < size / 2; j++) {
            for (int i = 0; i < size / 2; i++) {
                swap(*(p + i + j * size), *(p + size / 2 + i + j * size));
                swap(*(p + i + j * size + size * size / 2), *(p + size / 2 + i + j * size + size * size / 2));
            }
        }

        cout << endl << endl << "Изменённая матрица" << endl << endl;
        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }
        cout << endl;
        system("pause");
    }
    else {
        cout << "Матрица не создана" << endl;
        system("pause");
    }
}

void fillSnakeMatrix(int* p, int size) {
    int rowStart = 0, rowEnd = size - 1;
    int colStart = 0, colEnd = size - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int i = colStart; i <= colEnd; i++) {
            *(p + rowStart * size + i) = rand() % (size * size) + 1;
            printMas(p, size);
        }
        rowStart += 1;

        for (int i = rowStart; i <= rowEnd; i++) {
            *(p + i * size + colEnd) = rand() % (size * size) + 1;

            for (int j = 0; j < size * size; j++) {
                if (j % size == 0 and j != 0) {
                    cout << "\n";
                }
                cout << " " << *(p + j) << " ";
            }

            Sleep(250);
            system("cls");
        }
        colEnd -= 1;

        if (rowStart <= rowEnd) {
            for (int i = colEnd; i >= colStart; i--) {
                *(p + rowEnd * size + i) = rand() % (size * size) + 1;

                for (int j = 0; j < size * size; j++) {
                    if (j % size == 0 and j != 0) {
                        cout << "\n";
                    }
                    cout << " " << *(p + j) << " ";
                }

                Sleep(250);
                system("cls");
            }
            rowEnd -= 1;
        }

        if (colStart <= colEnd) {
            for (int i = rowEnd; i >= rowStart; i--) {
                *(p + i * size + colStart) = rand() % (size * size) + 1;

                for (int j = 0; j < size * size; j++) {
                    if (j % size == 0 and j != 0) {
                        cout << "\n";
                    }
                    cout << " " << *(p + j) << " ";
                }

                Sleep(250);
                system("cls");
            }
            colStart += 1;
        }
    }
    system("pause");
}

void fillVertical(int* p, int size) {
    if (size == 6) {
        int next = 0;

        for (int i = 0; i < size; i++) {
            *(p + i * size + next) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + next - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 2 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + 3 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 4 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size - 1 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        system("pause");
    }
    if (size == 8) {
        int next = 0;

        for (int i = 0; i < size; i++) {
            *(p + i * size + next) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + next - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 2 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + 3 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 4 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size - 3 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 6 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size - 1 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        system("pause");
    }
    if (size == 10) {
        int next = 0;

        for (int i = 0; i < size; i++) {
            *(p + i * size + next) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + next - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 2 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + (size - 1) * size + 3 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 4 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size + size - 5 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 6 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size + size - 3 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + 8 + i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;

        for (int i = 0; i < size; i++) {
            *(p + size * size + size - 1 - i * size) = rand() % (size * size) + 1;

            printMas(p, size);
        }
        next += 1;
        system("pause");
    }
}

void insertSort(int* p, const int size, bool flag) {
    if (flag) {

        int j, key;
        for (int i = 1; i < size * size; i++) {
            key = *(p + i);
            j = i - 1;


            while (j >= 0 && *(p + j) > key) {
                *(p + j + 1) = *(p + j);
                j = j - 1;
            }

            *(p + j + 1) = key;
        }
    }
}

void mathMethods(int* p, int size, bool mas) {
    if (mas) {
        cout << "[1] Сложение\n"
            "[2] Вычитание\n"
            "[3] Произведение\n"
            "[4] Деление\n";
        int sign, num_sum;
        cin >> sign;

        switch (sign) {
        case(1):
            cout << "Введите число: ";
            cin >> num_sum;
            for (int i = 0; i < size * size; i++) {
                *(p + i) += num_sum;
            }
            break;
        case(2):
            cout << "Введите число: ";
            cin >> num_sum;
            for (int i = 0; i < size * size; i++) {
                *(p + i) -= num_sum;
            }
            break;
        case(3):
            cout << "Введите число: ";
            cin >> num_sum;
            for (int i = 0; i < size * size; i++) {
                *(p + i) *= num_sum;
            }
            break;
        case(4):
            cout << "Введите число: ";
            cin >> num_sum;
            if (num_sum != 0) {
                for (int i = 0; i < size * size; i++) {
                    *(p + i) /= num_sum;
                }
            }
            else {
                cout << endl << "Нельзя делить на 0" << endl;
            }
            break;
        }
    }
    else {
        cout << "Матрица не создана" << endl;
    }
    system("pause");
}

void sumMatrix(int* p, const int size, bool mas, int* pm) {
    if (mas) {
        cout << "Изначальная матрица" << endl << endl;

        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }

        cout << endl << "Получившаяся матрица" << endl << endl;

        for (int i = 0; i < size * size; i++) {
            *(pm + i) = rand() % size * size + 1;
            *(p + i) += *(pm + i);
        }

        for (int j = 0; j < size * size; j++) {
            if (j % size == 0 and j != 0) {
                cout << "\n";
            }
            cout << " " << *(p + j) << " ";
        }
        cout << endl;
        system("pause");
        system("cls");
    }
    else {
        cout << "Матрица не создана" << endl;
        system("pause");
    }
}

int main3()
{
    setlocale(LC_ALL, "RU");

    srand(time(NULL));

    const int size1 = 6;
    const int size2 = 8;
    const int size3 = 10;

    int mas1[size1][size1] = {};
    int mas2[size2][size2] = {};
    int mas3[size3][size3] = {};

    int mas1m[size1][size1] = {};
    int mas2m[size2][size2] = {};
    int mas3m[size3][size3] = {};

    int* p1 = *mas1;
    int* p2 = *mas2;
    int* p3 = *mas3;

    int* p1m = *mas1m;
    int* p2m = *mas2m;
    int* p3m = *mas3m;

    bool mas6 = false;
    bool mas8 = false;
    bool mas10 = false;

    int num = -1, number = -1;
    while (num != 0) {
        cout << "Команды: " << endl;
        cout << "[1] Заполнение матрицы 6 x 6 змейкой\n"
            "[2] Заполнение матрицы 8 x 8 змейкой\n"
            "[3] Заполнение матрицы 10 x 10 змейкой\n"
            "[4] Заполнение матрицы 6 x 6 с переходом по вертикали\n"
            "[5] Заполнение матрицы 8 x 8 с переходом по вертикали\n"
            "[6] Заполнение матрицы 10 x 10 с переходом по вертикали\n"
            "[7] Переставление блоков матриц по кругу\n"
            "[8] Переставление блоков матриц по диагонали\n"
            "[9] Переставление блоков матриц сверху вниз\n"
            "[10] Переставление блоков матриц слева направо\n"
            "[11] Сортировка матрицы\n"
            "[12] Математические операции\n"
            "[13] ИДЗ: Сумма матриц\n";
        cout << "Команда: ";
        cin >> num;

        switch (num) {

        case(1):
            for (int i = 0; i < size1 * size1; i++) {
                *(p1 + i) = 0;
            }
            system("cls");

            fillSnakeMatrix(p1, size1);
            mas6 = true;
            system("cls");
            break;

        case(2):
            for (int i = 0; i < size2 * size2; i++) {
                *(p2 + i) = 0;
            }
            system("cls");

            fillSnakeMatrix(p2, size2);
            mas8 = true;
            system("cls");
            break;

        case(3):
            for (int i = 0; i < size3 * size3; i++) {
                *(p3 + i) = 0;
            }
            system("cls");

            fillSnakeMatrix(p3, size3);
            mas10 = true;
            system("cls");
            break;

        case(4):
            for (int i = 0; i < size1 * size1; i++) {
                *(p1 + i) = 0;
            }
            system("cls");

            fillVertical(p1, size1);
            mas6 = true;
            system("cls");
            break;

        case(5):
            for (int i = 0; i < size2 * size2; i++) {
                *(p2 + i) = 0;
            }
            system("cls");

            fillVertical(p2, size2);
            mas8 = true;
            system("cls");
            break;

        case(6):
            for (int i = 0; i < size3 * size3; i++) {
                *(p3 + i) = 0;
            }
            system("cls");

            fillVertical(p3, size3);
            mas10 = true;
            system("cls");
            break;

        case(7):
            system("cls");
            int number;
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                swapBlocksCircle(p1, size1, mas6);
                system("cls");
                break;
            case(2):
                swapBlocksCircle(p2, size2, mas8);
                system("cls");
                break;
            case(3):
                swapBlocksCircle(p3, size3, mas10);
                system("cls");
                break;
            }
            break;

        case(8):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                swapX(p1, size1, mas6);
                system("cls");
                break;
            case(2):
                swapX(p2, size2, mas8);
                system("cls");
                break;
            case(3):
                swapX(p3, size3, mas10);
                system("cls");
                break;
            }
            break;

        case(9):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                swapUpAndDown(p1, size1, mas6);
                system("cls");
                break;
            case(2):
                swapUpAndDown(p2, size2, mas8);
                system("cls");
                break;
            case(3):
                swapUpAndDown(p3, size3, mas10);
                system("cls");
                break;
            }
            break;

        case(10):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                swapLeftRight(p1, size1, mas6);
                system("cls");
                break;
            case(2):
                swapLeftRight(p2, size2, mas8);
                system("cls");
                break;
            case(3):
                swapLeftRight(p3, size3, mas10);
                system("cls");
                break;
            }
            break;

        case(11):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                insertSort(p1, size1, mas6);
                if (mas6) {
                    for (int j = 0; j < size1 * size1; j++) {
                        if (j % size1 == 0 and j != 0) {
                            cout << "\n";
                        }
                        cout << " " << *(p1 + j) << " ";
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << "Матрица не создана" << endl;
                    system("pause");
                    system("cls");
                }
                break;

            case(2):
                insertSort(p2, size2, mas8);
                if (mas8) {
                    for (int j = 0; j < size2 * size2; j++) {
                        if (j % size2 == 0 and j != 0) {
                            cout << "\n";
                        }
                        cout << " " << *(p2 + j) << " ";
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << "Матрица не создана" << endl;
                    system("pause");
                    system("cls");
                }
                break;

            case(3):
                insertSort(p3, size3, mas10);
                if (mas10) {
                    for (int j = 0; j < size3 * size3; j++) {
                        if (j % size3 == 0 and j != 0) {
                            cout << "\n";
                        }
                        cout << " " << *(p3 + j) << " ";
                    }
                    cout << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << "Матрица не создана" << endl;
                    system("pause");
                    system("cls");
                }
                break;
            }
            break;

        case(12):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                mathMethods(p1, size1, mas6);
                system("cls");
                break;
            case(2):
                mathMethods(p2, size2, mas8);
                system("cls");
                break;
            case(3):
                mathMethods(p3, size3, mas10);
                system("cls");
                break;
            }
            break;

        case(13):
            system("cls");
            cout << "[1]6 x 6\n"
                "[2]8 x 8\n"
                "[3]10 x 10\n";
            cout << "Введите номер: ";
            cin >> number;
            system("cls");
            switch (number) {
            case(1):
                sumMatrix(p1, size1, mas6, p1m);
                system("cls");
                break;
            case(2):
                sumMatrix(p2, size2, mas8, p2m);
                system("cls");
                break;
            case(3):
                sumMatrix(p3, size3, mas10, p3m);
                system("cls");
                break;
            }
            break;
        }
        system("cls");
    }
    return 0;
}