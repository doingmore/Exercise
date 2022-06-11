#ifndef SUM_AGGREGATOR_H
#define SUM_AGGREGATOR_H

class SumAggregator : public StreamAggregator
{
public:
	SumAggregator(std::istream& stream) : StreamAggregator{ stream } {}

	void aggregate(int next) override
	{
		StreamAggregator::aggregate(next);
		aggregationResult = aggregationResult + next;
	}

	virtual ~SumAggregator() {}
};

#endif // !SUM_AGGREGATOR_H

