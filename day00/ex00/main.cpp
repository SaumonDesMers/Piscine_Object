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

		int getId() const { return _id; }
		void setId(int id) { this->_id = id; }
		void credit(int value) { this->_credit += value; }

	public:

		int getCredit() const { return _credit; }

		friend std::ostream& operator << (std::ostream& os, const Account& account) {
			os << "[" << account.getId() << "] - [" << account.getCredit() << "]";
			return os;
		}
	};

private:

	typedef std::map<int, Account*> AccountMap;

public:

	Bank(int liquidity) : _liquidity(liquidity), _maxId(0) {}

	~Bank() {
		for (AccountMap::iterator it = this->_clientAccounts.begin(); it != this->_clientAccounts.end(); ++it)
			delete it->second;
	}

	int getLiquidity() const { return _liquidity; }

	Account *createAccount() {
		int newAccountId = this->_maxId++;
		Account *account = new Account(newAccountId, 0);
		this->_clientAccounts[newAccountId] = account;
		return account;
	}

	void deleteAccount(Account *account) {
		if (account == NULL)
			THROW("Invalid account");
		
		this->_clientAccounts.erase(account->getId());
		delete account;
	}

	void creditAccount(Account *account, int value) {
		if (account == NULL)
			THROW("Invalid account");

		this->addLiquidity(value * 0.05);
		account->credit(value * 0.95);
	}

	void giveLoan(Account *account, int value) {
		if (account == NULL)
			THROW("Invalid account");
		if (value < 0 || value > this->_liquidity)
			THROW("Invalid value");
		
		this->addLiquidity(-value);
		account->credit(value);
	}

	Account *operator [] (int id) {
		AccountMap::iterator it = this->_clientAccounts.find(id);
		if (it == this->_clientAccounts.end())
			THROW("Invalid account id");
		return it->second;
	}

	friend std::ostream& operator << (std::ostream& os, const Bank& bank) {
		os << "Bank informations : " << std::endl;
		os << "Liquidity : " << bank.getLiquidity() << std::endl;
		for (AccountMap::const_iterator it = bank._clientAccounts.begin(); it != bank._clientAccounts.end(); ++it)
			os << *it->second << std::endl;
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

		Bank::Account *accountA = bank.createAccount();
		bank.creditAccount(accountA, 100);

		std::cout << bank << std::endl;

		Bank::Account *accountB = bank.createAccount();
		bank.creditAccount(accountB, 200);
		bank.giveLoan(accountA, 100);

		std::cout << bank << std::endl;

		// bank.creditAccount(NULL, 100);
		// bank.giveLoan(accountA, 1000);


	} catch (std::runtime_error &e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
