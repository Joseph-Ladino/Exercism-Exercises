#include "bank_account.h"

namespace Bankaccount {

	void Bankaccount::open() {
		auto lock = std::unique_lock(m);

		if (accountOpened) throw std::runtime_error("account is already opened");
		accountOpened = true;
	}

	void Bankaccount::close() {
		auto lock = std::unique_lock(m);

		if (!accountOpened) throw std::runtime_error("account is not opened");

		accountOpened = false;
		accountBalance = 0;
	}

	void Bankaccount::deposit(int amount) {
		auto lock = std::unique_lock(m);

		if (!accountOpened) throw std::runtime_error("account is not opened");
		if (amount < 0) throw std::runtime_error("deposit amount cannot be negative");

		accountBalance += amount;
	}

	void Bankaccount::withdraw(int amount) {
		auto lock = std::unique_lock(m);

		if (!accountOpened) throw std::runtime_error("account is not opened");
		if (amount < 0 || amount > accountBalance) throw std::runtime_error("withdraw amount invalid");

		accountBalance -= amount;
	}

	int Bankaccount::balance() {
		auto lock = std::unique_lock(m);

		if (!accountOpened) throw std::runtime_error("account is not opened");

		return accountBalance;
	}
}