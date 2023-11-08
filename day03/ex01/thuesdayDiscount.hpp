#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {

public:

	ThuesdayDiscountCommand(int id, Date date, std::string const &customer) : Command(id, date, customer) {}

protected:

	int apply_discount(int price) const {
		if (_date.getDay() == Tuesday)
			price *= 0.9;
		return price;
	}

};

#endif // THUESDAYDISCOUNT_HPP