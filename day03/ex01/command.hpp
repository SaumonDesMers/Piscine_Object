#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <vector>

enum Day {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
};

enum Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	Septemper,
	October,
	November,
	December
};

class Date {

public:

	Date(int day, int month, int year) : _day(day), _month(month), _year(year) {}

	Day getDay() const { return static_cast<Day>(_day % 7); }
	Month getMonth() const { return static_cast<Month>(_month); }
	int getYear() const { return _year; }

private:

	int _day;
	int _month;
	int _year;

};

class Article {

public:

	int price;
	int quantity;

	Article(int price, int quantity) : price(price), quantity(quantity) {}
	
};

class Command {

public:

	Command(int id, Date date, std::string client) : _id(id), _date(date), _client(client) {}

	void add_article(Article const & article) {
		_articles.push_back(article);
	}

	virtual int get_total_price() const {
		int total = 0;
		for (size_t i = 0; i < _articles.size(); i++)
			total += _articles[i].price * _articles[i].quantity;
		return total;
	}
	
protected:

	int _id;
	Date _date;
	std::string _client;
	std::vector<Article> _articles;
};

#endif // COMMAND_HPP