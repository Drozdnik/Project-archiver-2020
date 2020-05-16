#include <iostream>

using namespace std;

class slovo

{

protected:

	char p_c[100]; // массив слова

	int sm_num[40]; // считает колличество элементов

	char p_list[40];//соответствие букв и колличества букв

	int len;

public:

	slovo(char* x) // инициализация

	{

		int i = 0;

		while (x[i] != '\0')

		{

			p_c[i] = x[i];

			i++;

		}

		p_c[i] = '\0';

		i = 0;

		int j = 0;

		int k = 0;

		int f = 0;

		int y3 = 0;

		while (p_c[i] != '\0')

		{

			while (p_c[j] != '\0')

			{

				if ((p_c[i] == p_c[j]) and (j < i)) {

					break;

				}

				p_list[y3] = p_c[i];

				if (p_c[i] == p_c[j])

				{

					k++;

				}

				j++;

			}

			if (k != 0) {

				sm_num[f] = k;

				k = 0;

				f++;

				y3++;

			}

			i++;

			j = 0;

		}

		p_list[y3] = '\0';

		{//сортировка чисел

			int j1 = 0;

			int i1 = 1;

			while (sm_num[j1] >= 0)

			{

				if (sm_num[j1] < 0)break;

				while (sm_num[i1] >= 0)

				{

					if (sm_num[i1 - 1] > sm_num[i1])

					{

						int vs;

						int vs1;

						vs = sm_num[i1];

						vs1 = p_list[i1];

						sm_num[i1] = sm_num[i1 - 1];

						p_list[i1] = p_list[i1 - 1];

						sm_num[i1 - 1] = vs;

						p_list[i1 - 1] = vs1;

					}

					i1++;

				}

				i1 = 1;

				j1++;

			}

		}

	}

	void show_sm_num(void)

	{

		int i = 0;

		while (sm_num[i] >= -1)

		{

			cout << sm_num[i] << " ";

			i++;

		}

		cout << endl;

	}//вывод

};

class bintree : public slovo

{

private:

	int p[40][40];//тут хранятся коды всех символов

	int pos_2[40][40]; //сумма ; как выставлять 0 и 1; последовательность элементов для присваивания 0 и 1

	int pos_1[40];// позиции элементов в последовательности

	int X[40];//запасной массив

	int shifr[1000];//массив с шифром

public:

	bintree(char* x) :slovo(x)

	{

		int i = 0;// по основному массиву

		int u = sm_num[0];//два элемента

		int b = 0;//для суммы

		int h = 0;// по элементам запасного массива

		int g = 0;

		int q;

		int pos_i = 0;//по элементам pos_2

		while (sm_num[g] > 0)

		{

			pos_1[g] = g;

			g++;

		}

		cout << endl;

		g = 0;

		while (sm_num[g] > 0)

		{

			X[g] = sm_num[g];

			g++;

		}

		//вывод

		int i3 = 0;

		while (X[i3] >= 0)

		{

			cout << X[i3] << " ";

			i3++;

		}

		int i4 = 0;

		cout << endl;

		cout << " pos : ";

		while (pos_1[i4] >= 0)

		{

			cout << pos_1[i4] << " ";

			i4++;

		}

		cout << endl;

		while (1)

		{

			if (X[1] < 0)break;

			if (pos_1[0] == -1 and pos_1[1] == -1)

			{

				int i5 = 0;//чтобы найти сумму

				int j5 = 1;

				while (pos_2[i5][j5] >= 0)

				{

					if (pos_2[i5][0] == X[0]) {

						while (pos_2[i5][j5] >= 0) {

							pos_2[pos_i][1 + j5] = pos_2[i5][1 + j5];

							j5++;

						}

						pos_2[i5][0] = 0;

						pos_2[pos_i][1] = j5 - 2;

					}

					i5++;

				}

				int i6 = 0;

				int j6 = 0;

				while (pos_2[i6][j6] >= 0)

				{

					if (pos_2[i6][0] == X[1]) {

						while (pos_2[i6][j6] >= 0) {

							pos_2[pos_i][j5 + j6] = pos_2[i6][2 + j6];

							j6++;

						}

						pos_2[i6][0] = 0;

					}

					i6++;

				}

			}

			else if (pos_1[0] != -1 and pos_1[1] != -1)

			{

				pos_2[pos_i][1] = 1;

				pos_2[pos_i][2] = pos_1[0];

				pos_2[pos_i][3] = pos_1[1];

			}

			else if (pos_1[0] == -1)

			{

				int i5 = 0;//чтобы найти сумму

				int j5 = 0;

				while (pos_2[i5][j5] >= 0)

				{

					if (pos_2[i5][0] == X[0]) {

						while (pos_2[i5][j5] >= 0) {

							pos_2[pos_i][1 + j5] = pos_2[i5][1 + j5];

							j5++;

						}

					}

					i5++;

				}

				pos_2[pos_i][1] = j5 - 2;

				pos_2[pos_i][j5] = pos_1[1];

			}

			else if (pos_1[1] == -1)

			{

				int i5 = 0;//чтобы найти сумму

				int j5 = 0;

				while (pos_2[i5][j5] >= 0)

				{

					if (pos_2[i5][0] == X[1]) {

						while (pos_2[i5][j5] >= 0) {

							pos_2[pos_i][2 + j5] = pos_2[i5][1 + j5];

							j5++;

						}

						pos_2[i5][0] = 0;

					}

					i5++;

				}

				pos_2[pos_i][1] = 1;

				pos_2[pos_i][2] = pos_1[0];

			}

			X[0] = X[0] + X[1];

			pos_1[0] = -1;

			pos_2[pos_i][0] = X[0];

			pos_i++;

			int i2 = 1;

			while (X[i2] > 0)

			{

				X[i2] = X[i2 + 1];

				pos_1[i2] = pos_1[i2 + 1];

				i2++;

			}

			i++;

			//сортировка по позрастанию

			int j1 = 0;

			int i1 = 1;

			while (X[j1] >= 0)

			{

				if (X[j1] < 0)break;

				while (X[i1] >= 0)

				{

					if (X[i1 - 1] > X[i1])

					{

						int vs1;

						int vs;

						vs1 = pos_1[i1];

						vs = X[i1];

						pos_1[i1] = pos_1[i1 - 1];

						X[i1] = X[i1 - 1];

						pos_1[i1 - 1] = vs1;

						X[i1 - 1] = vs;

					}

					i1++;

				}

				i1 = 1;

				j1++;

			}

			//вывод

			int i3 = 0;

			while (X[i3] >= 0)

			{

				cout << X[i3] << " ";

				i3++;

			}

			cout << endl;

			i3 = 0;

			cout << " pos : ";

			while (X[i3] >= 0)

			{

				cout << pos_1[i3] << " ";

				i3++;

			}

			cout << endl;

		}

		//выставление 0 и 1

		i = 0;

		int j = 0;

		int summ = 0;

		int pos_k = 1;

		while (pos_2[summ][0] >= -1) {

			summ++;

		}

		while (summ >= 0)

		{

			while (pos_k <= pos_2[summ][1])

			{

				int y = 0;

				while (1) {

					if (p[pos_2[summ][1 + pos_k]][y] < 0)break;

					y++;

				}

				p[pos_2[summ][1 + pos_k]][y] = 0;

				pos_k++;

			}

			while (pos_2[summ][pos_k] >= 0)

			{

				int y = 0;

				while (1) {

					if (p[pos_2[summ][1 + pos_k]][y] < 0)break;

					y++;

				}

				p[pos_2[summ][1 + pos_k]][y] = 1;

				pos_k++;

			}

			pos_k = 1;

			summ--;

		}

	};

	void show(void)

	{

		int i = 0;

		int j = 0;

		while (pos_2[i][j] >= 0)

		{

			while (pos_2[i][j] >= -1) {

				cout << pos_2[i][j] << " ";

				j++;

			}

			j = 0;

			cout << endl;

			i++;

		}

		cout << endl;

		i = 0;

		j = 0;

		while (p[i][j] >= -1)

		{

			cout << p_list[i] << " = ";

			while (p[i][j] >= -1) {

				cout << p[i][j] << " ";

				j++;

			}

			j = 0;

			cout << endl;

			i++;

		}

	}

	void shifr_m(void)

	{

		int i = 0;

		int j = 0;

		int f = 0;

		while (p_c[i] != '\0')

		{

			if (p_c[i] == p_list[j])

			{

				int k = 0;

				while (p[j][k] >= -1)

				{

					shifr[f] = p[j][k];

					k++;

					f++;

				}

				i++;

				j = -1;

			}

			j++;

		}

	}

	void shifr_v(void) {

		int i = 0;

		cout << "shifr := ";

		while (shifr[i] >= -1) {

			cout << shifr[i];

			i++;

		}

		cout << endl;

	}

};

char st[100];

int main()

{

	cin.get(st, 20);

	bintree p_1(st);

	p_1.show();

	p_1.shifr_m();

	p_1.shifr_v();

	return 0;

}
