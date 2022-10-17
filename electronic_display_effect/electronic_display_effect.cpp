#include<iostream>
#include<Windows.h>
#include<string>

using namespace std;

void OutLine(int a, int b)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)a,(short)b });
}

void main()
{
	string st;
	string stt;
	int speed = 0;
	cout << " 출력할 텍스트를 입력해주세요. : ";
	getline(cin, st);
	int size = st.length();
	cout << " 속도를 설정해주세요.( 초 단위 ) : ";
	st += " ";
	while (1)
	{
		if (scanf_s("%d", &speed) == 0)			// 0 또는 문자입력
		{
			cout << " 다시 입력하세요 " << endl;
			cout << " 속도 : ";
			rewind(stdin);
		}
		else
		{
			if (speed > 0)
				break;
			cout << " 다시 입력하세요 " << endl;		// 음수
			cout << " 속도 : ";
			rewind(stdin);
		}
	}

	while (1)
	{
		int e = 0;
		stt = st;
		//system("cls");

		OutLine(50, 10);
		cout << "┌";
		for (e; e < size; e++)
			cout << "─";
		OutLine(50 + e + 1, 10);
		cout << " ┐ ";
		OutLine(50, 11);
		cout << "│" << st << "│ ";
		OutLine(50, 12);
		cout << "└";
		for (e = 0; e < size; e++)
			cout << "─";
		OutLine(50 + e + 1, 12);
		cout << " ┘ " << endl;
		string::iterator iter = st.begin();
		if (st[0] & 0x80)
		{
			iter += (0);
			st.erase(iter);
			st.erase(iter);
		}
		else
		{
			iter += (0);
			st.erase(iter);
		}

		if (stt[0] & 0x80)
		{
			st += stt[0];
			st += stt[1];
		}
		else
			st += stt[0];

		Sleep(speed * 1000);
	}
}