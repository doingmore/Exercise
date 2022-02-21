#ifndef SumAggregator_H
#define SumAggregator_H

#include <sstream>

#include "Aggregator.h"

class SumAggregator : public StreamAggregator
{
protected:
	int m_sum;
public:
	SumAggregator(std::istream& numbers) : StreamAggregator{numbers} , m_sum(0)
	{
	}
	 
	virtual void aggregate(int next) 
	{
		m_sum+=next;
		aggregationResult = m_sum;
	}

};


#endif // !SumAggregator_H