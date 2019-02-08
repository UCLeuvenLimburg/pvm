#include "train.h"
#include <algorithm>
#include <assert.h>


int Wagon::board_passengers(int passengers)
{
	if (this->next_in_line)
	{
		passengers = this->next_in_line->board_passengers(passengers);
	}

	int free = this->passenger_capacity - this->passenger_count;
	int transferred = std::min(free, passengers);

	this->passenger_count += transferred;
	int left_over = passengers - transferred;

	assert(this->passenger_count <= this->passenger_capacity);
	assert(left_over == 0 || this->passenger_count == this->passenger_capacity);
	assert(left_over >= 0);

	return left_over;
}


std::shared_ptr<Wagon> Train::last_wagon()
{
	if (!_first_wagon)
	{
		return nullptr;
	}
	else
	{
		auto current = _first_wagon;

		while (current->next_in_line)
		{
			current = current->next_in_line;
		}

		return current;
	}
}

const std::shared_ptr<Wagon> Train::last_wagon() const
{
	if (!_first_wagon)
	{
		return nullptr;
	}
	else
	{
		auto current = _first_wagon;

		while (current->next_in_line)
		{
			current = current->next_in_line;
		}

		return current;
	}
}

void Train::add_wagon(int capacity)
{
	auto new_wagon = std::make_shared<Wagon>(capacity);

	if (_first_wagon == nullptr)
	{
		_first_wagon = new_wagon;
	}
	else
	{
		last_wagon()->next_in_line = new_wagon;
	}
}

int Train::board_passengers(int passengers)
{
	if (!_first_wagon)
	{
		return passengers;
	}
	else
	{
		return _first_wagon->board_passengers(passengers);
	}
}

int Train::count_wagons() const
{
	int count = 0;
	auto current = this->_first_wagon;

	while (current)
	{
		++count;
		current = current->next_in_line;
	}
	
	return count;
}

std::shared_ptr<Wagon> Train::nth_wagon(int n)
{
	auto current = this->_first_wagon;

	while (current != nullptr && n > 0)
	{
		current = current->next_in_line;
		--n;
	}

	return current;
}

const std::shared_ptr<Wagon> Train::nth_wagon(int n) const
{
	auto current = this->_first_wagon;

	while (current != nullptr && n > 0)
	{
		current = current->next_in_line;
		--n;
	}

	return current;
}
