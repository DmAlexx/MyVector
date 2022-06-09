#include <iostream>
#include <string>

using namespace std;

namespace 
{
	const int VECTOR_CAPACITY_COEF = 2;
	const int DEFAULT_VECTOR_CAPACITY = 16;
}

template<typename T>
class MyVector
{
private:
	T* m_arr = nullptr;
	int m_length;
	int m_capacity = DEFAULT_VECTOR_CAPACITY;

public:
	
	MyVector(int length)
		: m_length(length) 
		, m_capacity(DEFAULT_VECTOR_CAPACITY)
	{
		m_arr = new T[m_capacity];
	}

	~MyVector()
	{
		if (m_arr)
		{
			delete[] m_arr;
		}
	}

	int size()
	{
		return m_length;
	}
	
	int capacity()
	{
		return m_capacity;
	}
	
	void insert(unsigned int position, T value)
	{
		if (position > 0 && position <= m_length)
		{
			if (m_length == m_capacity)
			{
				T* arrTemp = new T[m_length];
				for (int i = 0; i < m_length; ++i)
				{
					arrTemp[i] = m_arr[i];
				}
				delete[] m_arr;
				m_capacity = m_capacity + DEFAULT_VECTOR_CAPACITY * VECTOR_CAPACITY_COEF;
				m_arr = new T[m_capacity];
				m_length++;
				for (int i = 0; i < (position - 1); ++i)
				{
					m_arr[i] = arrTemp[i];
				}
				m_arr[position - 1] = value;
				for (int i = (position); i < m_length; ++i)
				{
					m_arr[i] = arrTemp[i - 1];
				}
				delete[] arrTemp;
			}
			else
			{

				T* arrTemp = new T[m_length];
				for (int i = 0; i < m_length; ++i)
				{
					arrTemp[i] = m_arr[i];
				}
				m_length++;
				for (int i = 0; i < (position - 1); ++i)
				{
					m_arr[i] = arrTemp[i];
				}
				m_arr[position - 1] = value;
				for (int i = position; i <= m_length; ++i)
				{
					m_arr[i] = arrTemp[i - 1];
				}
				delete[] arrTemp;
			}
		}
		else
		{
			cout << "Wrong position " << endl;
		}
	}

	void clear() 
	{
		if (m_arr)
		{
			delete[] m_arr;
		}
		m_arr = new T[m_capacity];
	}

	void fillArray()
	{
		for (int i = 0; i < m_length; ++i)
		{
			m_arr[i] = i+1;
		}
	}

	void print()
	{
		if (m_length > 0)
		{
			for (int i = 0; i < m_length; ++i)
			{
				cout << m_arr[i] << "\t";
			}
			cout << endl << endl;
		}
		else
		{
			cout << "Array is empty" << endl;
		}
	}

	void push_back(T value)
	{
		if (m_length == m_capacity)
		{
			T* arrTemp = new T[m_length];
			for (int i = 0; i < m_length; ++i)
			{
				arrTemp[i] = m_arr[i];
			}
			delete[] m_arr;
			m_capacity = m_capacity + DEFAULT_VECTOR_CAPACITY * VECTOR_CAPACITY_COEF;
			m_arr = new T[m_capacity];
			for (int i = 0; i < m_length; ++i)
			{
				m_arr[i] = arrTemp[i];
			}
			delete[] arrTemp;
			m_arr[m_length++] = value;
		}
		else
		{
			m_arr[m_length++] = value;
		}
	}

	MyVector& operator=(const MyVector& a)
	{
		for (int i = 1; i < m_length; ++i)
		{
			m_arr[i] = a.m_arr[i];
		}
		return *this;
	}

	MyVector(const MyVector& a)
	{
		for (int i = 1; i < m_length; ++i)
		{
			m_arr[i] = a.m_arr[i];
		}
	}

	T& operator*() const { return *m_arr; }
	T* operator->() const { return m_arr; }
};


int main()
{
	setlocale(LC_ALL, "ru");
	MyVector<int> array2(16);
	array2.fillArray();
	cout << "size of array = " << array2.size() << endl;
	cout << "capacity = " << array2.capacity() << endl;
	array2.print();
	array2.push_back(14);
	cout << "size of array = " << array2.size() << endl;
	cout << "capacity = " << array2.capacity() << endl;
	array2.print();
	array2.insert(6,44);
	cout << "size of array = " << array2.size() << endl;
	cout << "capacity = " << array2.capacity() << endl;
	array2.print();
	return 0;
}