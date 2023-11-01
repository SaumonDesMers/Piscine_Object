#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
#define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {

public:

	PackageReductionDiscountCommand(int id, Date date, std::string const &customer) : Command(id, date, customer) {}

	int get_total_price() const {
		int total = 0;
		for (size_t i = 0; i < this->_articles.size(); i++)
			total += _articles[i].price * _articles[i].quantity;
		if (total > 150)
			total -= 10;
		return total;
	}

};

#endif // PACKAGEREDUCTIONDISCOUNT_HPP