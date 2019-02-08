#ifndef TRAIN_H
#define TRAIN_H

#include <memory>


struct Wagon
{	
	/*
		public fields
		  next_in_line            next wagon in queue
		  passenger_capacity      number of passengers that can fit into this wagon
		  passenger_count         number of passengers that occupy this wagon

		methods
		  tests don't call methods on Wagon objects
		  feel free to define any methods you like
	*/	
};


class Train
{
	/*
		public methods
			constructor					creates a train with 0 wagons
			count_wagons()				counts the number of wagons
			last_wagon()				returns the last wagon or nullptr if there is none
			add_wagon(int capacity)		adds wagon with specified capacity to the end of the train
			nth_wagon(int n)			returns nth_wagon (zero based indexing) or nullptr if there is no such wagon
			board_passengers(int n)		fills wagons with passengers, starting with last wagon; returns the number of passengers which could not fit in the train
	*/
};

#endif
