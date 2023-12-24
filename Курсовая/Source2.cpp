#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace chrono;


int fill_mas(int mas[], const int size, int mas_unsorted[], int mas_unsorted_false[]) {
    cout << "������� �������: 1\n";
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 199 - 99;
        mas_unsorted[i] = mas[i];
        mas_unsorted_false[i] = mas[i];
    }

    cout << "������ ������� ������\n\n";
    return(0);
}

int print_mas(int mas[], const int size, bool flag) {
    cout << "������� �������: 9\n";
    if (flag) {
        cout << "������:\n";
        for (int i = 0; i < size; i++) {
            cout << mas[i] << " ";
        }
        cout << "\n\n";
    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int insert_sort(int mas[], const int size, bool flag) {
    if (flag) {

        int j, key;
        for (int i = 1; i < size; i++) {
            key = mas[i];
            j = i - 1;


            while (j >= 0 && mas[j] > key) {
                mas[j + 1] = mas[j];
                j = j - 1;
            }

            mas[j + 1] = key;
        }
    }
    return(0);
}

int sort_mas(int mas[], const int size, bool flag) {
    cout << "������� �������: 2\n";

    if (flag) {

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds result;

        start = steady_clock::now();

        insert_sort(mas, size, flag);

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "������ ������������\n";
        cout << "����� ����������(� ������������): " << result.count() << "\n";
    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int find_max_min(int mas[], const int size, bool flag, int mas_unsorted[], int mas_unsorted_false[]) {
    cout << "������� �������: 3\n";
    if (flag) {

        insert_sort(mas_unsorted_false, size, flag);

        int max, min;

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds result;

        start = steady_clock::now();

        max = mas_unsorted_false[size - 1];

        min = mas_unsorted_false[0];

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "������������ ��������: " << max << "\n";
        cout << "����������� ��������: " << min << "\n";
        cout << "����� ������ � ��������������� �������(� ������������): " << result.count() << "\n\n";

        int max_ = mas_unsorted[0], min_ = mas_unsorted[0];

        start = steady_clock::now();

        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] > max_) {
                max_ = mas_unsorted[i];
            }
            if (mas_unsorted[i] < min_) {
                min_ = mas_unsorted[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        cout << "������������ ��������: " << max_ << "\n";
        cout << "����������� ��������: " << min_ << "\n";
        cout << "����� ������ � ����������������� �������(� ������������): " << result.count() << "\n";

    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int middle_max_min(int mas[], const int size, bool flag, int mas_unsorted[], int mas_unsorted_false[]) {
    cout << "������� �������: 4\n\n";
    if (flag) {

        insert_sort(mas_unsorted_false, size, flag);

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds result;

        start = steady_clock::now();

        int max = mas_unsorted_false[size - 1], min = mas_unsorted_false[0];

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        int middle = (max + min) / 2;
        int count = 0;
        cout << "������� ��������: " << middle << "\n";
        cout << "������� ���������, ������ �������� ��������: ";
        for (int i = 0; i < size; i++) {
            if (mas_unsorted_false[i] == middle) {
                cout << i << " ";
                count += 1;
            }
        }
        cout << "\n����������: " << count << "\n";
        cout << "����� ������ � ��������������� �������(� ������������): " << result.count() << "\n\n";

        start = steady_clock::now();

        int max_ = mas_unsorted[0], min_ = mas_unsorted[0];
        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] > max_) {
                max_ = mas_unsorted[i];
            }
        }
        for (int i = 0; i < size; i++) {
            if (mas_unsorted[i] < min_) {
                min_ = mas_unsorted[i];
            }
        }

        end = steady_clock::now();
        result = duration_cast<nanoseconds>(end - start);

        int middle_ = (max_ + min_) / 2;
        int count_ = 0;
        cout << "������� ��������: " << middle_ << "\n";
        cout << "������� ���������, ������ �������� ��������: ";
        for (int i = 0; i < size; i++) {
            if (mas[i] == middle_) {
                cout << i << " ";
                count_ += 1;
            }
        }
        cout << "\n����������: " << count_ << "\n";
        cout << "����� ������ � ����������������� �������(� ������������): " << result.count() << "\n";

    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int less_than_a(int mas[], const int size, bool flag, bool flag_sort) {
    cout << "������� �������: 5\n";
    if (flag) {
        if (flag_sort) {
            cout << "������� �����: ";
            int a, count = 0;

            while (!(cin >> a)) {
                cout << "������ �����. ������������ ��� ������.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < size; i++) {
                if (mas[i] < a) {
                    count += 1;
                }
            }
            cout << "\n���������� ���������, �������, ��� �: " << count << "\n";
        }
        else {
            cout << "������ �� ������������\n";
        }
    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int more_than_b(int mas[], const int size, bool flag, bool flag_sort) {
    cout << "������� �������: 6\n";
    if (flag) {
        if (flag_sort) {
            int b, count = 0;
            cout << "������� �����: ";

            while (!(cin >> b)) {
                cout << "������ �����. ������������ ��� ������.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            for (int i = 0; i < size; i++) {
                if (mas[i] > b) {
                    count += 1;
                }
            }
            cout << "\n���������� ���������, �������, ��� b: " << count << "\n";
        }
        else {
            cout << "������ �� ������������\n";
        }
    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int binary_Search(int mas[], const int size, bool flag, bool flag_sort, int start, int end, int value) {
    if (flag) {
        if (flag_sort) {
            if (end >= start) {
                int mid = start + (end - start) / 2;

                if (mas[mid] == value) {
                    return mid;
                }

                if (mas[mid] > value) {
                    return binary_Search(mas, size, flag, flag_sort, start, mid - 1, value);
                }

                return binary_Search(mas, size, flag, flag_sort, mid + 1, end, value);
            }
        }
        else {
            cout << "������ �� ������������\n";
        }
    }
    else {
        cout << "������ �� ������\n";
    }
    return(-1);
}

int transpose(int mas[], const int size, bool flag) {
    cout << "������� �������: 8\n";
    if (flag) {
        int elem1, elem2;
        cout << "������� �������: ";
        cin >> elem1 >> elem2;
        int temp;

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
        nanoseconds results;

        start = steady_clock::now();

        temp = mas[elem1 - 1];
        mas[elem1 - 1] = mas[elem2 - 1];
        mas[elem2 - 1] = mas[elem1 - 1];
        cout << "�������� ������������\n";

        end = steady_clock::now();
        results = duration_cast<nanoseconds>(end - start);

        cout << "����� ������������(� ������������): " << results.count() << endl;
    }
    else {
        cout << "������ �� ������\n";
    }
    return(0);
}

int idz(int mas[], const int size, bool flag) {
    if (flag) {
        cout << "������� �����, �� ������� ����� ��������� ������ ������ �������:\n"
            "�����: ";
        int numbero, chet_num = 0, nechet_num = 0;
        cin >> numbero;

        for (int i = 0; i < size; i += 2) {
            mas[i] -= numbero;
            mas[i] *= rand() % 9 + 1;
        }

        for (int i = 0; i < size; i++) {
            if (i % 2 == 0 && mas[i] % 2 == 0) {
                chet_num += 1;
            }
            if (i % 2 != 0 && mas[i] % 2 != 0) {
                nechet_num += 1;
            }
        }
        cout << "���������� ������ ��������� � ������� ����������: " << chet_num << endl << endl;
        cout << "���������� �������� ��������� � ��������� ����������: " << nechet_num << endl << endl;

        int count = 0;

        for (int j = 1; j < 10; j++) {
            count = 0;
            for (int i = 0; i < size; i++) {
                if (mas[i] % j == 0) {
                    count += 1;
                }
            }
            cout << "���������� ���������, ��������� ��  " << j << ": " << count << endl << endl;
        }
    }
    else {
        cout << "������ �� ������\n";
    }
    return 0;
}

int main2()
{
    setlocale(LC_ALL, "RU");
    bool flag = false, flag_sort = false;
    int num = 1;
    const int size = 100;
    int mas[size] = {};
    int mas_unsorted[size] = {};
    int mas_unsorted_false[size] = {};
    while (num != 0) {
        cout << "������� �������: \n"
            "[1]��������� ������\n"
            "[2]���������� �������\n"
            "[3]����� ������������� � ������������ ��������\n"
            "[4]����� �������� ���������� ������������� � ������������ ��������\n"
            "[5]����� ���������� ��������� �������, �������, ��� ����� a\n"
            "[6]����� ���������� ��������� �������, �������, ��� ����� b\n"
            "[7]�������� �����\n"
            "[8]�������� ������� �������� �������\n"
            "[9]������� ������\n"
            "[10]���\n"
            "[0]����� �� ���������\n";
        cout << "�������: ";

        while (!(cin >> num)) {
            cout << "������ �����. ������������ ��� ������.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        switch (num) {

        case(1):
            system("cls");
            fill_mas(mas, size, mas_unsorted, mas_unsorted_false);
            flag = true;
            system("pause");
            break;

        case(2):
            system("cls");
            sort_mas(mas, size, flag);
            flag_sort = true;
            system("pause");
            break;

        case(3):
            system("cls");
            find_max_min(mas, size, flag, mas_unsorted, mas_unsorted_false);
            system("pause");
            break;

        case(4):
            system("cls");
            middle_max_min(mas, size, flag, mas_unsorted, mas_unsorted_false);
            system("pause");
            break;

        case(5):
            system("cls");
            less_than_a(mas, size, flag, flag_sort);
            system("pause");
            break;

        case(6):
            system("cls");
            more_than_b(mas, size, flag, flag_sort);
            system("pause");
            break;

        case(7):
            system("cls");
            int value;
            cout << "������� �������: 7\n������� �����: ";

            while (!(cin >> value)) {
                cout << "������ �����. ������������ ��� ������.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (num == 7) {
                time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
                nanoseconds results;

                start = steady_clock::now();

                int result = binary_Search(mas, size, flag, flag_sort, 0, size - 1, value);


                if (result == -1) {
                    cout << "������� �� ������" << endl;
                }
                else {
                    cout << "������� ��������� � ������� " << result + 1 << endl;

                    end = steady_clock::now();
                    results = duration_cast<nanoseconds>(end - start);

                    cout << "����� ��������� ������(� ������������): " << results.count() << endl;

                    start = steady_clock::now();

                    for (int i = 0; i < size; i++) {
                        if (mas[i] == value) {
                            cout << "������� ��������� � ������� " << i + 1 << endl;
                            break;
                        }
                    }

                    end = steady_clock::now();
                    results = duration_cast<nanoseconds>(end - start);
                    cout << "����� �������� ��������(� ������������): " << results.count() << endl;
                }
            }
            system("pause");
            break;

        case(8):
            system("cls");
            transpose(mas, size, flag);
            flag_sort = false;
            system("pause");
            break;

        case(9):
            system("cls");
            print_mas(mas, size, flag);
            system("pause");
            break;

        case(10):
            system("cls");
            idz(mas, size, flag);
            system("pause");
            break;
        }
        system("cls");
    }
    return(0);
}