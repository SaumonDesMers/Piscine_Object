#pragma once

#include "staff.hpp"

class Headmaster : public Staff {
	
public:

	Headmaster(std::string const & name): Staff(name) {}

	void receiveForm(Form* form) {
		this->_formToValidate.insert(form);
	}

	void signForms() {
		for (std::set<Form *>::iterator it = this->_formToValidate.begin(); it != this->_formToValidate.end(); it++) {
			Form *form = *it;
			// if (form->isComplete()) {
			// 	std::cout << "Headmaster " << this->name() << " is signing form " << form->name() << std::endl;
			// 	form->sign(this);
			// } else {
			// 	std::cout << "Headmaster " << this->name() << " is rejecting form " << form->name() << std::endl;
			// }
			try {
				form->sign(this);
				std::cout << "Headmaster " << this->name() << " is signing form " << form->name() << std::endl;
			} catch (std::exception & e) {
				std::cout << "Headmaster " << this->name() << " is rejecting form " << form->name() << ": " << e.what() << std::endl;
			}
		}
	}

private:

	std::set<Form*> _formToValidate;

};