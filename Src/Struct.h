#ifndef _SRC_STRUCT_H_
#define _SRC_STRUCT_H_
#include <iostream>
/*
* ���ļ�����дһЩ��Ҫ�õ������ݽṹ���������͵�
*/

using namespace std;

struct SetInt
{
private:
	int* index;		// Ԫ����element�е��±꣬������ʱΪ 0
	int* element;	// Ԫ�� [1,cnt]
	int cnt;		// Ԫ�ظ���
public:
	SetInt()
	{
		index = NULL;
		element = NULL;
		cnt = 0;
	}
	SetInt(int maxSize)
	{
		index = new int[maxSize + 10]();
		element = new int[maxSize + 10]();
		cnt = 0;
	}
	~SetInt()
	{
		delete[] index;
		delete[] element;
	}

	int& operator[](int i) { return element[i]; }
	// ������������ʱ��ǳ��������ѳ�Ա�����ĵ�ַ����������
	//�βε�����������ʱ�Ὣͬһ���ַ��delete��������ͻ����
	SetInt& operator=(const SetInt& s) 
	{
		for (int i = 1; i <= s.size(); ++i)
		{
			element[i] = s.element[i];
			index[element[i]] = s.index[element[i]];
		}
		cnt = s.cnt;
		return *this;
	}
	int get_index(int u) { return index[u]; }

	void insert(int u)	// ����һ���¶���
	{
		if (index[u] != 0) return;
		element[++cnt] = u;
		index[u] = cnt;
	}
	void erase(int u)	// ɾ������
	{
		if (index[u] == 0) return;
		index[element[cnt]] = index[u];
		element[index[u]] = element[cnt];
		index[u] = 0;
		cnt--;
	}

	void swap(int u, int v)
	{
		element[index[u]] = v;
		element[index[v]] = u;
		int tmp = index[u];
		index[u] = index[v];
		index[v] = tmp;
	}

	void update()
	{
		for (int i = 1; i <= cnt; ++i)
		{
			index[element[i]] = i;
		}
	}

	void clear()
	{
		fill(begin(), end(), 0);
		cnt = 0;
	}

	int size() const { return cnt; }
	int* begin() const { return element + 1; }
	int* end() const { return element + cnt + 1; }
	bool exist(int u) { return index[u] != 0; }
	bool empty() { return cnt == 0; }
};

#endif // !_SRC_STRUCT_H_

