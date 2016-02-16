#include<conio.h>
#include<iostream>
#include<windows.h>

using namespace std;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;

	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

	scrn.X = xpos; scrn.Y = ypos;

	SetConsoleCursorPosition(hOuput, scrn);
}

struct car
{
	char model[20];
	char firm[20];
	char tip[20];
	int dvig;
	int cost;
};

int main()
{
	setlocale(0, "");
	int q;
	void create();
	void view();
	void s_tip();
	void s_moshdv();
	void s_cost();
	system("cls");
	do
	{
		cout << " --------------  МЕНЮ  --------------------------\n";
		cout << "=================================================\n";
		cout << "1- entering information in the file about the machines " << endl;
		cout << "2- output of information from the file " << endl;
		cout << "3- list of cars with body type introduced " << endl;
		cout << "4- list of cars in the input band reception power " << endl;
		cout << "5- list of cars in the input Price range " << endl;
		cout << "6- output " << endl;
		cout << "Enter the menu and press enter" << endl;
		cin >> q;
		switch (q)
		{
		case 1: create(); break;
		case 2: view(); break;
		case 3: s_tip(); break;
		case 4: s_moshdv(); break;
		case 5: s_cost(); break;
		}
	} while (q != 6);
	return 0;
}
//file creating
void create()
{
	system("cls");
	FILE *in;
	int n, i = 0;
	char name[20];
	cout << "Enter name FILE: ";
	cin >> name;
	in = fopen(name, "w");
	cout << "\nEnter information:\n";
	cout << "\nEnter the number of vehicles: ";
	cin >> n;
	fprintf(in, "%d\n", n);
	car *kn;
	kn = new car[n];
	system("cls");
	cout << "Entering data into the table";
	int y = 2, x = 0;
	while (i<n + 2)
	{
		gotoxy(0, y); cout << "  --------------------------------------------------------------------------\n";
		y = y + 2;
		i++;
	}
	int j = 0;
	y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(2, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(21, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(40, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(53, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(65, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(76, y); cout << "|";
		y = y + 1;
		j++;
	}
	i = 0;
	x = 0;
	y = 3;
	int k = 0;
	while (i<n)
	{
		gotoxy(3, 3); cout << "Model";
		gotoxy(22, 3); cout << "Firm";
		gotoxy(41, 3); cout << "Body Type";
		gotoxy(55, 3); cout << "Engine power.";
		gotoxy(67, 3); cout << "Cost";
		gotoxy(3, y + 2); cin >> kn[i].model;
		gotoxy(22, y + 2); cin >> kn[i].firm;
		gotoxy(41, y + 2); cin >> kn[i].tip;
		gotoxy(55, y + 2); cin >> kn[i].dvig;
		gotoxy(67, y + 2); cin >> kn[i].cost;

		y = y + 2;
		fprintf(in, "%s %s %s %d %d\n", kn[i].model, kn[i].firm, kn[i].tip, kn[i].dvig, kn[i].cost);//запись информации в файл
		i++;
		k++;
	}

	fclose(in);
	delete kn;
	cout << "\n\nData is successfully written FILE\n" << endl;
	getche();
	system("cls");
}
void view()
{
	system("cls");
	FILE *in;
	char name[20];
	int i, n;
	cout << "\nEnter output FILE: \n";
	cin >> name;
	system("cls");
	in = fopen(name, "r");
	fscanf(in, "%d\n", &n);
	car *kn;
	kn = new car[n];
	for (i = 0; i<n; i++)
	{
		fscanf(in, "%s %s %s %d %d\n", &kn[i].model, &kn[i].firm, &kn[i].tip, &kn[i].dvig, &kn[i].cost);
	}
	cout << "Data on cars from a file " << name;
	int x = 0, y = 3;
	int j = 0;
	y = 3;


	while (j<2 * (n + 1))
	{
		gotoxy(2, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(21, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(40, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(53, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(65, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(76, y); cout << "|";
		y = y + 1;
		j++;
	}
	i = 0;
	x = 0;
	y = 3;
	int k = 0;
	//вывод данных в виде таблицы
	while (i<n)
	{

		gotoxy(3, 3); cout << "Model";
		gotoxy(22, 3); cout << "Firm";
		gotoxy(41, 3); cout << "Body Type";
		gotoxy(55, 3); cout << "Engine power.";
		gotoxy(67, 3); cout << "Cost";
		gotoxy(3, y + 2); cin >> kn[i].model;
		gotoxy(22, y + 2); cin >> kn[i].firm;
		gotoxy(41, y + 2); cin >> kn[i].tip;
		gotoxy(55, y + 2); cin >> kn[i].dvig;
		gotoxy(67, y + 2); cin >> kn[i].cost;
		y = y + 2;
		i++;
		k++;
	}
	i = 0; y = 2;
	while (i<n + 2)
	{
		gotoxy(0, y); cout << "  --------------------------------------------------------------------------\n";
		y = y + 2;
		i++;
	}
	delete kn;
	getche();
	fclose(in);
	system("cls");
}
void s_tip() 
{
	system("cls");
	FILE *in, *out;
	char name_in[20], name_out[20];
	char tip[20];
	int i, n;
	int k = 0, j = -1;
	int index[20];
	cout << "\nEnter input FILE: \n";
	cin >> name_in;
	cout << "Enter output FILE: \n";
	cin >> name_out;
	system("cls");
	in = fopen(name_in, "r");
	out = fopen(name_out, "w");
	fscanf(in, "%d\n", &n);
	car *kn;
	kn = new car[n];
	cout << "Enter the name of a body type\n";
	scanf("\n");
	gets(tip);
	for (i = 0; i<n; i++)
	{
		fscanf(in, "%s %s %s %d %d\n", &kn[i].model, &kn[i].firm, &kn[i].tip, &kn[i].dvig, &kn[i].cost);
	}
	for (i = 0; i < n; i++)
	{
		j++;
		if (strcmp(kn[i].tip, tip) == 0)
		{
			index[j] = i;
			k++;
		}
		else
			j--;
	}
	n = k;
	fprintf(out, "%d\n", n);
	system("cls");
	cout << "List the type of car bodies: " << tip;
	int x = 0, y = 3;

	while (j<2 * (n + 1))
	{
		gotoxy(2, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(21, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(40, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(53, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(65, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(76, y); cout << "|";
		y = y + 1;
		j++;
	}
	i = 0;
	x = 0;
	y = 3;
	k = 0;
	while (i<n)
	{

		gotoxy(3, 3); cout << "Model";
		gotoxy(22, 3); cout << "Firm";
		gotoxy(41, 3); cout << "Body Type";
		gotoxy(55, 3); cout << "Engine power.";
		gotoxy(67, 3); cout << "Cost";
		gotoxy(3, y + 2); cout << kn[index[i]].model;
		gotoxy(22, y + 2); cout << kn[index[i]].firm;
		gotoxy(41, y + 2); cout << kn[index[i]].tip;
		gotoxy(55, y + 2); cout << kn[index[i]].dvig;
		gotoxy(67, y + 2); cout << kn[index[i]].cost;
		y = y + 2;
		fprintf(out, "%s %s %s %d %d\n", kn[index[i]].model, kn[index[i]].firm, kn[index[i]].tip, kn[index[i]].dvig, kn[index[i]].cost);//запись информации в файл
		i++;
		k++;
	}
	i = 0; y = 2;
	while (i<n + 2)
	{
		gotoxy(0, y); cout << "  --------------------------------------------------------------------------\n";
		y = y + 2;
		i++;
	}
	delete kn;
	getche();
	fclose(in);
	fclose(out);
	system("cls");
}
void s_moshdv()
{
	system("cls");
	FILE *in, *out;
	char name_in[20], name_out[20];
	char tip[20];
	int mosh_min, mosh_max;
	int i, n;
	int k = 0, j = -1;
	int index[20];
	cout << "\nEnter input FILE: \n";
	cin >> name_in;
	cout << "\nEnter output FILE: \n";
	cin >> name_out;
	system("cls");
	in = fopen(name_in, "r");
	out = fopen(name_out, "w");
	fscanf(in, "%d\n", &n);
	car *kn;
	kn = new car[n];
	for (i = 0; i<n; i++)
	{
		fscanf(in, "%s %s %s %d %d\n", &kn[i].model, &kn[i].firm, &kn[i].tip, &kn[i].dvig, &kn[i].cost);
	}
	cout << "Enter min power\n";
	cin >> mosh_min;
	cout << "Enter max power\n";
	cin >> mosh_max;
	for (int i = 0; i<n; i++)
	{
		j++;
		if (mosh_min <= kn[i].dvig && kn[i].dvig <= mosh_max)
		{
			index[j] = i;
			k++;
		}
		else
			j--;
	}
	n = k;
	fprintf(out, "%d\n", n);
	system("cls");
	cout << "List of cars with engine capacity in the range of" << mosh_min << " till " << mosh_max;
	int x = 0, y = 3;

	while (j<2 * (n + 1))
	{
		gotoxy(2, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(21, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(40, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(53, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(65, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(76, y); cout << "|";
		y = y + 1;
		j++;
	}
	i = 0;
	x = 0;
	y = 3;
	k = 0;
	int q = 0;
	while (i<n)
	{

		gotoxy(3, 3); cout << "Model";
		gotoxy(22, 3); cout << "Firm";
		gotoxy(41, 3); cout << "Body Type";
		gotoxy(55, 3); cout << "Engine power.";
		gotoxy(67, 3); cout << "Cost";
		gotoxy(3, y + 2); cout << kn[index[i]].model;
		gotoxy(22, y + 2); cout << kn[index[i]].firm;
		gotoxy(41, y + 2); cout << kn[index[i]].tip;
		gotoxy(55, y + 2); cout << kn[index[i]].dvig;
		gotoxy(67, y + 2); cout << kn[index[i]].cost;
		y = y + 2;
		fprintf(out, "%s %s %s %d %d\n", kn[index[i]].model, kn[index[i]].firm, kn[index[i]].tip, kn[index[i]].dvig, kn[index[i]].cost);//запись информации в файл
		i++;
		k++;
	}
	i = 0; y = 2;
	while (i<n + 2)
	{
		gotoxy(0, y); cout << "  --------------------------------------------------------------------------\n";
		y = y + 2;
		i++;
	}
	delete kn;
	getche();
	fclose(in);
	fclose(out);
	system("cls");
}
void s_cost()
{
	system("cls");
	FILE *in, *out;
	char name_in[20], name_out[20];
	char tip[20];
	int cost_min, cost_max;
	int i, n;
	int k = 0, j = -1;
	int index[20];
	cout << "\nEnter input FILE: \n";
	cin >> name_in;
	cout << "Enter output FILE: \n";
	cin >> name_out;
	system("cls");
	in = fopen(name_in, "r");
	out = fopen(name_out, "w");
	fscanf(in, "%d\n", &n);
	car *kn;
	kn = new car[n];
	for (i = 0; i<n; i++)
	{
		fscanf(in, "%s %s %s %d %d\n", &kn[i].model, &kn[i].firm, &kn[i].tip, &kn[i].dvig, &kn[i].cost);
	}
	cout << "Enter min cost\n";
	cin >> cost_min;
	cout << "Enter max cost\n";
	cin >> cost_max;
	for (int i = 0; i<n; i++)
	{
		j++;
		if (cost_min <= kn[i].cost && kn[i].cost <= cost_max)
		{
			index[j] = i;
			k++;
		}
		else
			j--;
	}
	n = k;
	fprintf(out, "%d\n", n);
	system("cls");
	cout << "List value in the range of vehicles" << cost_min << " till " << cost_max;
	int x = 0, y = 3;

	while (j<2 * (n + 1))
	{
		gotoxy(2, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(21, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(40, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(53, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(65, y); cout << "|";
		y = y + 1;
		j++;
	}
	j = 0; y = 3;
	while (j<2 * (n + 1))
	{
		gotoxy(76, y); cout << "|";
		y = y + 1;
		j++;
	}
	i = 0;
	x = 0;
	y = 3;
	k = 0;
	int q = 0;
	while (i<n)
	{

		gotoxy(3, 3); cout << "Model";
		gotoxy(22, 3); cout << "Firm";
		gotoxy(41, 3); cout << "Body Type";
		gotoxy(55, 3); cout << "Engine power.";
		gotoxy(67, 3); cout << "Cost";
		gotoxy(3, y + 2); cout << kn[index[i]].model;
		gotoxy(22, y + 2); cout << kn[index[i]].firm;
		gotoxy(41, y + 2); cout << kn[index[i]].tip;
		gotoxy(55, y + 2); cout << kn[index[i]].dvig;
		gotoxy(67, y + 2); cout << kn[index[i]].cost;
		y = y + 2;
		fprintf(out, "%s %s %s %d %d\n", kn[index[i]].model, kn[index[i]].firm, kn[index[i]].tip, kn[index[i]].dvig, kn[index[i]].cost);//запись информации в файл
		i++;
		k++;
	}
	i = 0; y = 2;
	while (i<n + 2)
	{
		gotoxy(0, y); cout << "  --------------------------------------------------------------------------\n";
		y = y + 2;
		i++;
	}
	delete kn;
	getche();
	fclose(in);
	fclose(out);
	system("cls");
}
