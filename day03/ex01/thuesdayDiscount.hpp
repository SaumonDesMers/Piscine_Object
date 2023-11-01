#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {

public:

	ThuesdayDiscountCommand(int id, Date date, std::string const &customer) : Command(id, date, customer) {}

	int get_total_price() const {
		int total = 0;
		for (size_t i = 0; i < this->_articles.size(); i++)
			total += _articles[i].price * _articles[i].quantity;
		if (this->_date.getDay() == Tuesday)
			total *= 0.9;
		return total;
	}

};

#endif // THUESDAYDISCOUNT_HPP