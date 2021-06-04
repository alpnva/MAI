#include "KP9.h"


void printTable(const Key* k, const Val* v, const int size)
{
	int i;

	printf("+--------+------------------------------------------------------------+\n");
	printf("|  Ключ |                          Значение                          |\n");
	printf("+--------+------------------------------------------------------------+\n");

	for (i = 0; i < size; i++)
		printf("|%8d|%60s|\n", k[i].key, v[i].val);

	printf("+--------+------------------------------------------------------------+\n");
}

int binSearch(const Key* k, const Val* v, const int size, const Key key)
{
	int start = 0, end = size - 1, mid;

	if (size <= 0)
		return -1;

	while (start < end)
	{
		mid = start + (end - start) / 2;

		if (isEqualKeys(k[mid], key))
			return mid;
		else if (comparator(k[mid], key))
			start = mid + 1;
		else
			end = mid;
	}

	if (isEqualKeys(k[end], key))
		return end;

	return -1;
}

void swap(Key* k1, Key* k2, Val* v1, Val* v2)
{
	Key t;
	Val f;
	t = *k1;
	*k1 = *k2;
	*k2 = t;
	f = *v1;
	*v1 = *v2;
	*v2 = f;
}

void sort(Key* k, Val* v, const int size)
{
	int i;

	for (i = (size - 2) / 2; i >= 0; i--)
		sift(k, v, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&k[0], &k[i], &v[0], &v[i]);
		sift(k, v, 0, i);
	}
}

void sift(Key* k, Val* v, int start, int end)
{
	int root = start;
	int child = root * 2 + 1;

	while (child < end)
	{
		if (child + 1 < end && k[child].key < k[child + 1].key)
			child++;

		if (k[root].key >= k[child].key)
			break;

		swap(&k[root], &k[child], &v[root], &v[child]);

		root = child;
		child = root * 2 + 1;
	}
}


void scramble(Key* k, Val* v, const int size)
{
	int i, j, z;

	srand((unsigned int)time(0));

	for (z = 0; z < size; z++)
	{
		i = randomAB(0, size - 1);
		j = randomAB(0, size - 1);

		swapRows(k, v, i, j);
	}
}

void reverse(Key* k, Val* v, const int size)
{
	int i, j;

	for (i = 0, j = size - 1; i < j; i++, j--)
		swapRows(k, v, i, j);
}

void getRow(FILE* stream, char* str, const int size)
{
	int cnt = 0, ch;

	while ((ch = getc(stream)) != '\n' && cnt < size - 1)
		str[cnt++] = ch;

	str[cnt] = '\0';
}

void swapRows(Key* k, Val* v, const int a, const int b)
{
	Key tmpKey;
	Val tmpVal;

	tmpKey = k[a];
	k[a] = k[b];
	k[b] = tmpKey;

	tmpVal = v[a];
	v[a] = v[b];
	v[b] = tmpVal;
}

int comparator(const Key k1, const Key k2)
{
	return k2.key >= k1.key;
}

int isEqualKeys(const Key k1, const Key k2)
{
	return k1.key == k2.key;
}

int randomAB(const int a, const int b)
{
	return a + rand() % (b - a + 1);
}

int isSorted(const Key* k, const int size)
{
	int i;

	for (i = 0; i < size - 1; i++)
		if (!comparator(k[i], k[i + 1]))
			return 0;

	return 1;
}
