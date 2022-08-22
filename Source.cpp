#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
class Playlist
{
public:
	char name[15];
	char executor[20];
	char song[40];
	Playlist Vvod();
	void Show(Playlist tmp);
	Playlist* Add(Playlist* mas, int& n)
	{
		mas = (Playlist*)realloc(mas, (n + 1) * sizeof(Playlist));
		mas[n] = Vvod();
		n++;
		return mas;
	}

	void Print(Playlist* mas, int n)
	{
		for (int i = 0; i < n; i++)
		{
			Show(mas[i]);
			cout << "\n";
		}
	}
	void Find(Playlist* mas, int n)
{
	char str[15];
	cout << "Enter executor : ";
	gets_s(str);
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mas[i].executor, str) == 0)
		{
			Show(mas[i]);
			f = 1;
		}
	}
	if (f == 0)
		cout << "Error.\n";
}
	Playlist* Del(Playlist* mas, int& n)
{
	char str[30];
	cout << "Vvedite name filma: ";
	gets_s(str);
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (_stricmp(mas[i].name, str) == 0)
		{
			for (int j = i; j < n - 1; j++)
				mas[j] = mas[j + 1];
			mas = (Playlist*)realloc(mas, (n - 1) * sizeof(Playlist));
			n--;
			i--;
			f = 1;
		}
	}
	if (f == 0)
	{
		cout << "Error.\n";
	}
	else
	{
		cout << "Playlist - delete.\n";
	}
	return mas;
}
	void Write(Playlist* mas)
	{
		ofstream out;
		out.open("text.txt", ios::app);
		if (out.is_open())
		{
			out << mas;
		}
		else { cout << "You are TRASH!"; }
	}
};
Playlist Playlist::Vvod()
{
	Playlist tmp;
	cout << "Enter playlist name : ";
	gets_s(tmp.name);
	cout << "Enter executor : ";
	gets_s(tmp.executor);
	cout << "Enter songs";
	gets_s(tmp.song);
	return tmp;
}
inline void Playlist::Show(Playlist tmp)
{
	cout << "Playlist name : " << tmp.name << " \n " << "Executor : " << tmp.executor << "\n" << "Songs : " << tmp.song << endl;
}
int main()
{
	Playlist* baza = nullptr;
	Playlist x;
	int n = 0;
	char ch;
	do
	{
		system("cls");
		cout << "Menu.\n";
		cout << "1 - Add playlist.\n";
		cout << "2 - Vivod .\n";
		cout << "3 - Search by artist .\n";
		cout << "4 - Delete playlist .\n";
		cout << "5 - Write and appending to file .\n";
		cout << "6 - Overwriting to a file .\n";
		cout << "Esc - Vihod.\n";
		cout << "Vash vibor: ";
		ch = _getch();
		switch (ch)
		{
		case '1':
			system("cls");
			baza = x.Add(baza, n);
			break;
		case '2':
			system("cls");
			if (n != 0)
			{
				x.Print(baza, n);
			}
			else
			{
				cout << "Baza danih pusta.\n";
			}
			system("pause");
			break;
		case '3':
			system("cls");
						if (n != 0)
						{
							x.Find(baza, n);
						}
						else
						{
							cout << "Baza danih pusta.\n";
						}
						system("pause");
						break;
		case '4':
			system("cls");
						if (n != 0)
						{
							baza = x.Del(baza, n);
						}
						else
						{
							cout << "Baza danih pusta.\n";
						}
						system("pause");
						break;
		case '5':
			system("cls");
			x.Write(baza);
			system("pause");
			break;
		}
	} while (ch != 27);
	free(baza);
}