#include <iostream>
#include <vector>

#include "command.hpp"
#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int main() {

	std::vector<Article> articles;
	articles.push_back(Article(10, 1));
	articles.push_back(Article(20, 2));
	articles.push_back(Article(30, 3));
	articles.push_back(Article(40, 1));
	articles.push_back(Article(50, 5));
	articles.push_back(Article(60, 3));
	articles.push_back(Article(70, 1));

	Command command(0, Date(2, 1, 2020), "Bob");
	ThuesdayDiscountCommand thuesdayDiscountCommand(0, Date(2, 1, 2020), "Bob");
	PackageReductionDiscountCommand packageReductionDiscountCommand(0, Date(2, 1, 2020), "Bob");

	for (size_t i = 0; i < articles.size(); i++) {
		command.add_article(articles[i]);
		thuesdayDiscountCommand.add_article(articles[i]);
		packageReductionDiscountCommand.add_article(articles[i]);
	}

	std::cout << "Command total price: " << command.get_total_price() << std::endl;
	std::cout << "TuesdayDiscountCommand total price: " << thuesdayDiscountCommand.get_total_price() << std::endl;
	std::cout << "PackageReductionDiscountCommand total price: " << packageReductionDiscountCommand.get_total_price() << std::endl;

	return 0;
}