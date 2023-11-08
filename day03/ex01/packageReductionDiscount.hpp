#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
#define PACKAGEREDUCTIONDISCOUNT_HPP

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {

public:

	PackageReductionDiscountCommand(int id, Date date, std::string const &customer) : Command(id, date, customer) {}

protected:

	int apply_discount(int price) const {
		if (price > 150)
			price -= 10;
		return price;
	}

};

#endif // PACKAGEREDUCTIONDISCOUNT_HPP