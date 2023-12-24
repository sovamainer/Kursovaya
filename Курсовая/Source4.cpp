#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <cctype>
using namespace std;

string fileLine() {
	ifstream File;
	File.open("Lab4_test.txt");
	if (!File.is_open())
	{
		cout << "������� ���� �� �������! \n";
	}
	string output;
	getline(File, output);
	File.close();
	return output;
}

bool existDigits(string& word) {
	for (char c : word) {
		if (isdigit(c)) {
			return true;
		}
	}
	return false;
}

string removeWordsDigits(const string& word) {
	stringstream stream(word);
	string sentence;
	string result;

	while (stream >> sentence) {
		if (!existDigits(sentence)) {
			result += sentence + " ";
		}
	}

	if (!result.empty()) {
		result.pop_back();
	}

	return result;
}

void stringLength(string& word) {
	stringstream stream(word);
	string sentence;

	while (stream >> sentence) {
		cout << sentence.length() << " ";
	}
}

int main4()
{
	system("cls");
	int number = -1;
	while (number != 0) {
		setlocale(LC_ALL, "RU");
		cout << "�������� �������:\n"
			"[1]������� ������� � ����������\n"
			"[2]������� ������� � �����\n"
			"[0]����� �� ���������\n"
			"�������: ";

		int choise;
		string strok, strok2;
		cin >> choise;

		system("cls");
		cout << "������ �������: ������ ���� �����: " << choise << endl;

		switch (choise) {
		case(1):
			cin.ignore();
			getline(cin, strok);
			break;
		case(2):
			strok2 = fileLine();
			break;
		}
		if (choise == 0) {
			break;
		}
		cout << "\n";

		string input;

		if (choise == 1) {
			input = strok;
		}
		else {
			input = strok2;
		}
		string output;
		string result;

		bool prevSpace = false;
		bool firstSymbol = true;
		bool previousPunct = false;

		for (char c : input) {

			if (c == ' ') {
				if (!prevSpace) {
					output += c;
					prevSpace = true;
				}
			}
			else {
				if (firstSymbol) {
					if (islower(input[0])) {
						output += (input[0] - 32);
						firstSymbol = false;
					}
					else {
						output += c;
						firstSymbol = false;
					}
				}
				else {
					output += tolower(c);
					prevSpace = false;
				}
			}
		}

		for (char c : output) {
			if (ispunct(c)) {
				if (!previousPunct) {
					result += c;
					previousPunct = true;
				}
			}
			else {
				result += c;
				previousPunct = false;
			}
		}
		cout << "������ �������: �������������� ������\n";

		cout << result << endl << endl;

		cout << "������ �������: ����� ���� ������������������, �� ���������� � ����� ������ �����\n";

		string result_3 = removeWordsDigits(result);

		cout << result_3 << endl;

		cout << "\n��������� �������: ����� ����� ������� ����� ����������� ������������������\n";

		stringLength(input);

		cout << endl;

		system("pause");
		system("cls");
	}
	return 0;
}