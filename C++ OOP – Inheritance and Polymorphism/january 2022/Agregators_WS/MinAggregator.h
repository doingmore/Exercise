#ifndef MinAggregator_H
#define MinAggregator_H

#include <sstream>

#include "Aggregator.h"

class MinAggregator : public StreamAggregator
{
protected:
	int m_minNumber;
public:
	MinAggregator(std::istream& stream) : StreamAggregator{stream} , m_minNumber(INT_MAX)
	{
	}
	
	virtual void aggregate(int next) 
	{
		if (next < m_minNumber)
		{
			m_minNumber = next;
			aggregationResult = m_minNumber;
		}
	} 

};


#endif // !MinAggregator_H
