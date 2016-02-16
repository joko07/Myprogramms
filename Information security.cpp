#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>

char txt[100] = "mama papa dedad mama papad mama";
char a[15][15], c[15][15];
int b[15];
char f1[10], f2[10], N[10], d[20][20];
int k, kk, l, i, s, j, B;

using namespace std;

void read(char ff[10])
{
	char ch;
	i = 0; j = 0; k = 0;
	system("cls");
	FILE *fout;
	fout = fopen(ff, "r");
	cout << "\n\n\n\n		            FILE " << N << " opened" << endl << "		  -------------------------------" << endl;
	do
	{
		ch = fgetc(fout);
		printf("%c", ch);
		if (ch != ' ')
		{
			d[i][j] = ch;
			b[i]++;
			j++;
		}
		else
		{
			i++;
			k++;
			j = 0;
		}
	} while (ch != EOF);
	fclose(fout);
	getche();
}

void text_v_massiv_slov()
{
	s = strlen(txt);
	FILE *f;
	i = 0; k = 0; l = -1;
	for (i = 0; i<s; i++)
	{
		if (txt[i] != ' ')
		{
			l++;
			a[k][l] = txt[i];
			b[k]++;
		}
		else
		{
			a[k][l + 1] = '\0';
			k++;
			b[k] = 0;
			l = -1;
		}
	}
}


void newfile()
{
	system("cls");
	cout << "\n\n\n\n\n  		Enter file name:  ";
	cin >> f1;
	FILE *f;
	f = fopen(f1, "w");
	cout << "\n\n\n\n\n\n\n\n		  ----------Vvedite text---------" << endl;
	scanf("\n");
	gets(txt);
	text_v_massiv_slov();
	for (i = 0; i <= k; i++)
		fprintf(f, "%s ", a[i]);
	fclose(f);

}

void sortirovka_texta()
{
	FILE *f;
	cout << "\n\n\n\n\n\n\n\n		  -------------------------------" << endl;
	cout << "		   Vvedite file name gotovogo texta :";
	cin >> f2;
	char g[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z' };
	//g[25] = 'z';
	int c; c = 0;
	int p; p = 0;
	f = fopen(f2, "w");
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j<b[i]; j++)
		{
			for (int y = 0; y <= 25; y++)
			{
				if (g[y] == d[i][j])
				{
					if (c == 0){ c++; p = p + 1; }
					else  {
						if (c == 1){ c++; p = p + 2; }
						else    { c = 0; p = p - 3; }
					}
					if ((p + y)<0)
						p = p + y + 26;
					if ((p + y)<26)
						p = p + y;
					else
						p = p + y - 26;
					d[i][j] = g[p]; p = 0;
					fprintf(f, "%c", d[i][j]);
					break;
				}
			}
		}
		fprintf(f, " ");
	}
	fprintf(f, "\n");
	fclose(f);
}

void DES()
{
	FILE *f;
	cout << "\n\n\n\n\n\n\n\n		  -------------------------------" << endl;
	cout << "		   Vvedite file name gotovogo texta :";
	cin >> f2;
	char g[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y','z' };
	//g[25] = 'z';
	int c; c = 0;
	int p; p = 0;
	f = fopen(f2, "w");
	for (i = 0; i <= k; i++)
	{
		for (j = 0; j<b[i]; j++)
		{
			for (int y = 0; y <= 25; y++)
			{
				if (g[y] == d[i][j])
				{
					if (c == 0){ c++; p = p - 1; }
					else  {
						if (c == 1){ c++; p = p - 2; }
						else    { c = 0; p = p + 3; }
					}
					if ((p + y)<0)
						p = p + y + 26;
					else
					{
						if ((p + y)<26)
							p = p + y;
						else
							p = p + y - 26;
					}
					d[i][j] = g[p]; p = 0;
					fprintf(f, "%c", d[i][j]);
					break;
				}
			}
		}
		fprintf(f, " ");
	}
	fprintf(f, "\n");
	fclose(f);
}




void launch_programm()
{
	system("cls");
	cout << "---------------------" << endl << "To launch programm prees 'Enter' ";
	system("pause");
	text_v_massiv_slov();
	//zapis_slov_v_FILE();
	sortirovka_texta();
}



void read_files()
{
	cout << "\n\n\n\n\n\n\n\n		  -------------------------------" << endl;
	cout << "                  	Chose file's name" << endl; cin >> N;
	read(N);
}


void menu()
{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n		  -------------------------------" << endl;
	cout << "		    To read files         ---- 1" << endl;
	cout << "		    To create a new file  ---- 2" << endl;
	cout << "		    Sortirovka texta      ---- 3" << endl;
	cout << "		    DES			  ---- 4" << endl;
	cout << "		    Exit  ---- 0" << endl;
	cin >> B;
	if (cin.good())
		if (B != 0)
		{
			system("cls");
			switch (B)
			{
			case 1: read_files(); break;
			case 2: newfile(); break;
			case 3: sortirovka_texta(); break;
			case 4: DES(); break;
			}
			menu();
		}
}


int main()
{

	menu();
	return 0;
}
