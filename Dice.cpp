#include <ctime>

#include "Dice.h"

std::uniform_int_distribution<int> RandomDice::die{1,6};

std::default_random_engine RandomDice::generator{ static_cast<unsigned int>(time(NULL)) };
//std::default_random_engine RandomDice::generator{static_cast<unsigned long>(time(NULL))};

Dice::Dice(Color _color) : d_color(_color)
{
	roll();
}
int Dice::roll()
{
	return d_face = RandomDice::die(RandomDice::generator);
}

std::ostream& operator<<(std::ostream& _out, const Dice& _dice)
{
	switch(_dice.d_color)
	{
		case Color::RED:
            _out << "red ";
            break;

		case Color::YELLOW:
            _out << "yellow ";
            break;

		case Color::BLUE:
            _out << "blue ";
            break;

        case Color::GREEN:
            _out << "green ";
            break;

        case Color::WHITE:
            _out << "white  ";

	}

	_out << _dice.d_face;
	return _out;
}

RollOfDice RollOfDice::roll()
{
	for(auto &die : *this)
	{
		die.roll();
	}
	return *this;
}

//revise if inheritance is not permited
RollOfDice RollOfDice::pair(const int _index1, const int _index2) const
{
	RollOfDice pairedRoll;
	pairedRoll.push_back((*this)[_index1]);
	pairedRoll.push_back((*this)[_index2]);

	return pairedRoll;
}

RollOfDice::operator int() const
{
	int total = 0;
	for(auto die : *this)
		total += die.d_face;
	return total;
}

std::ostream& operator<<(std::ostream& _out, const RollOfDice& _roll)
{
	_out << "Roll: ";
	for(auto die : _roll)
		_out << die << ", ";

	_out << "Total: " << static_cast<int>(_roll) << std::endl;

	return _out;
}
