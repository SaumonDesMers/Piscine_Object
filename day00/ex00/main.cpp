#include <iostream>
#include <vector>
#include <map>

#define THROW(e) throw std::runtime_error(std::string(__FUNCTION__) + ": " + e)

class Bank
{

public:

	class Account
	{
		friend class Bank;

		int _id;
		int _credit;

		Account(int id, int credit) : _id(id), _credit(credit) {}

		void setId(int id) { this->_id = id; }
		void credit(int value) { this->_credit += value; }

	public:

		int getCredit() const { return _credit; }
		int getId() const { return _id; }

		friend std::ostream& operator << (std::ostream& os, const Account& account) {
			os << "[" << account.getId() << "] - [" << account.getCredit() << "]";
			return os;
		}
	};

private:

	typedef std::map<int, Account> AccountMap;

public:

	Bank(int liquidity) : _liquidity(liquidity), _maxId(0) {}

	~Bank() {}

	int getLiquidity() const { return _liquidity; }

	int createAccount() {
		int newAccountId = this->_maxId++;
		this->_clientAccounts.insert(std::make_pair(newAccountId, Account(newAccountId, 0)));
		return newAccountId;
	}

	void deleteAccount(int id) {
		this->_clientAccounts.erase(id);
	}

	void creditAccount(int id, int value) {
		if (this->_clientAccounts.count(id) == 0)
			THROW("Invalid account id");
		if (value < 0)
			THROW("Invalid value");
		this->addLiquidity(value * 0.05);
		this->_clientAccounts.at(id).credit(value * 0.95);
	}

	void giveLoan(int id, int value) {
		if (this->_clientAccounts.count(id) == 0)
			THROW("Invalid account id");
		if (value < 0 || value > this->_liquidity)
			THROW("Invalid value");
		
		this->addLiquidity(-value);
		this->_clientAccounts.at(id).credit(value);
	}

	const Account &operator [] (int id) const {
		AccountMap::const_iterator it = this->_clientAccounts.find(id);
		if (it == this->_clientAccounts.end())
			THROW("Invalid account id");
		return it->second;
	}

	friend std::ostream& operator << (std::ostream& os, const Bank& bank) {
		os << "Bank informations : " << std::endl;
		os << "Liquidity : " << bank.getLiquidity() << std::endl;
		for (AccountMap::const_iterator it = bank._clientAccounts.begin(); it != bank._clientAccounts.end(); ++it)
			os << it->second << std::endl;
		return os;
	}

private:

	int _liquidity;
	int _maxId;
	AccountMap _clientAccounts;

	void addLiquidity(int liquidity) { this->_liquidity += liquidity; }
};

int main() {
	try {

		Bank bank = Bank(999);

		int accountA_id = bank.createAccount();
		bank.creditAccount(accountA_id, 100);

		std::cout << bank << std::endl;

		int accountB_id = bank.createAccount();
		bank.creditAccount(accountB_id, 200);
		bank.giveLoan(accountA_id, 100);

		std::cout << bank << std::endl;

		bank.deleteAccount(accountA_id);

		std::cout << bank << std::endl;

		Bank::Account accountB = bank[accountB_id];
		std::cout << accountB << std::endl;

		// bank.creditAccount(-1, 100);
		// bank.giveLoan(accountA_id, 1000);


	} catch (std::runtime_error &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
