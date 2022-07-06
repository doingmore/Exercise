#ifndef SORT_BY_H
#define SORT_BY_H


void swap(Company** left, Company** right)
{
	Company* temporarity = *left;
	*left = *right;
	*right = temporarity;
}


void sortBy(Company** begin , Company** end , bool(*func)(const Company& left , const Company& right ) )
{
	Company** state = begin;

	for (Company** out = begin; out != end; out++)
	{
		state++;
		for (Company** in = state; in != end; in++)
		{
			if ( !func(**out,**in) )
			{
				swap(out,in);
			}
		}
	}
}


#endif // !SORT_BY_H
