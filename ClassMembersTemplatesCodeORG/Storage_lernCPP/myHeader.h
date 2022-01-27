#ifndef myHeader_H
#define myHeader_H

template <typename T>
class storage8
{
private:
	T m_array[8];
public:
	void set(const int &a)
	{
		m_array[a] = a;
	}

	void set (const int& a, const double& b)
	{
		m_array[a] = b;
	}

	const T& get(const int index) { return m_array[index]; }

};



#endif // !myHeader_H
