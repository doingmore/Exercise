#ifndef AverageAggregator_H
#define AverageAggregator_H

#include <sstream>

#include "Aggregator.h"

class AverageAggregator : public StreamAggregator
{
protected:
	int m_sum;
public:
	AverageAggregator(std::istream& numbers) : StreamAggregator{numbers} , m_sum(0)
	{
	}

	virtual void aggregate(int next) 
	{
		StreamAggregator::aggregate(next);
		m_sum = m_sum + next;
		aggregationResult = (m_sum / getNumAggregated());
	}
	
};


#endif // !AverageAggregator_H