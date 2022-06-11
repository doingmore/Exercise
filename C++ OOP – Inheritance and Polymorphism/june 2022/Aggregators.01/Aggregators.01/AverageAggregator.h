#ifndef AVERAGE_AGREGATOR_H
#define AVERAGE_AGREGATOR_H

#include <string>

class AverageAggregator : public StreamAggregator
{
private:
	int m_average_sum;
public:
	AverageAggregator(std::istringstream& stream) : StreamAggregator{ stream }, m_average_sum{0} {}

	void aggregate(int next) override
	{
		StreamAggregator::aggregate(next);
		m_average_sum = m_average_sum + next;
		aggregationResult = m_average_sum / getNumAggregated();
	}
};


#endif // !AVERAGE_AGREGATOR_H