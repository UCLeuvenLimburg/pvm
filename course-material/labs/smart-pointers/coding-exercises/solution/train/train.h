#ifndef TRAIN_H
#define TRAIN_H

#include <memory>


struct Wagon
{	
	std::shared_ptr<Wagon> next_in_line;
	int passenger_capacity, passenger_count;

	Wagon(int capacity) : next_in_line(nullptr), passenger_capacity(capacity), passenger_count(0) { }

	int board_passengers(int);
};


class Train
{
	std::shared_ptr<Wagon> _first_wagon;

public:
	Train() : _first_wagon(nullptr) { }

	int count_wagons() const;

	std::shared_ptr<Wagon> last_wagon();
	const std::shared_ptr<Wagon> last_wagon() const;

	void add_wagon(int);
	std::shared_ptr<Wagon> nth_wagon(int);
	const std::shared_ptr<Wagon> nth_wagon(int) const;

	int board_passengers(int);
};

#endif
