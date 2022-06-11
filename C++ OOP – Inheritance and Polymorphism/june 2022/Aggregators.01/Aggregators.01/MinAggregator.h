#ifndef MIN_AGGREGATOR_H
#define MIN_AGGREGATOR_H

class MinAggregator : public StreamAggregator
{
public:
	MinAggregator(std::istringstream& stream) : StreamAggregator{ stream }
	{
		aggregationResult = INT_MAX;
	}
	
	void aggregate(int next) override
	{
		StreamAggregator::aggregate(next);
		if (next < aggregationResult)
		{
			aggregationResult = next;
		}
	}
};


#endif // !MIN_AGGREGATOR_H
