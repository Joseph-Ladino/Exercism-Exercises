#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <stdexcept>
#include <mutex>
#include <thread>

namespace Bankaccount {
	class Bankaccount {
		int accountBalance = 0;
		bool accountOpened = false;
		std::mutex m;

	public:
		void open();
		void close();
		void deposit(int amount);
		void withdraw(int amount);
		int balance();

	};  // class Bankaccount

}  // namespace Bankaccount

#endif  // BANK_ACCOUNT_H