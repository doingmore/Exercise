#ifndef FILTER_FACTORY_H
#define FILTER_FACTORY_H

class FilterFactory : public Filter
{
private:
	int capitalLetters_begin = 65;
	int capitalLetters_end = 90;
	int lowerLetters_begin = 97;
	int lowerLetters_end = 122;
	int digits_begin = 48;
	int digits_end = 57;
protected:
	bool shouldFilterOut(char symbol) const override
	{
		return true;
	}
public:
	FilterFactory() {}

	 FilterFactory buildFilter(const std::string& definition) const
	{

		return this;
	}

	virtual ~FilterFactory() {}
};

#endif // !FILTER_FACTORY_H
