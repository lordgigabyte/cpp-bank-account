#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>


class Transaction {

private:
	std::string type;
	double amount;

public:

	Transaction(std::string type, double amount) {

		this->type = type;
		this->amount = amount;

	}

	std::string getType() const {
		return type;
	}

	double getAmount() const {
		return amount;
	}


};

class BankAccount {

private:
	double balance = 0;
	std::vector <Transaction> transaction_history;


public: 

	bool undo() {

			if (transaction_history.empty()) {
				
				return false;

			}

			Transaction latestTransaction = transaction_history.back();

			if (latestTransaction.getType() == "Deposit") {

				balance -= latestTransaction.getAmount();

				transaction_history.pop_back();

				return true;

			}

			else if (latestTransaction.getType() == "Withdraw") {

				balance += latestTransaction.getAmount();

				transaction_history.pop_back();

				return true;

			}

		return false;


	}

	void deposit(double amount) {

		if (amount < 0) {
			throw std::invalid_argument("Cannot deposit negative amount of money \n");
		}

		balance += amount;
		transaction_history.push_back(Transaction{ "Deposit", amount});
		
	}

	void withdraw(double amount) {

		if (amount < 0 || amount > getBalance()) {
			throw std::invalid_argument("Unable to withdraw more than current balance \n");
		}

		balance -= amount;
		transaction_history.push_back(Transaction{ "Withdraw", amount });

	}

	double getBalance() const {
		return balance;
	}

	const std::vector <Transaction>& getTransactionHistory() const {
		return transaction_history;
	}

};

double amountPrompt(const std::string& message) {

	double amount;

	while (true) {

		std::cout << message;
		std::cin >> amount; 

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input a NUMBER, please. :) \n";

			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return amount;


	}
}

int main() {

	BankAccount account;

	std::string response;
	std::vector <std::string> valid_responses = { "Deposit", "Withdraw", "Show balance", "Exit", "Transaction history", "Undo"};


	while (true) {

		std::cout << "\nHello and welcome, what would you like to do?\nDeposit\nWithdraw\nShow balance\nTransaction history\nUndo\nExit \n";
		std::getline(std::cin, response);

		if (std::find(valid_responses.begin(), valid_responses.end(), response) == valid_responses.end()) {
			std::cout << "Not a valid answer \n";
			continue;
		}

		if (response == "Deposit") {

			double amount = amountPrompt("\nEnter deposit amount: ");

			try {
				account.deposit(amount);
				std::cout << "You deposited: " << amount << " successfully! \n";
			}
			catch (const std::invalid_argument& ex) {

				std::cout << ex.what() << '\n';
				continue;
			}
		}


		else if (response == "Withdraw") {

			double amount = amountPrompt("\nEnter withdrawal amount: ");

			try {
				account.withdraw(amount);
				std::cout << "You withdrew: " << amount << " successfully! \n";
			}
			catch (const std::invalid_argument& ex) {

				std::cout << ex.what() << '\n';
				continue;
			}

		}

		else if (response == "Show balance") {
			std::cout << '\n' << account.getBalance();
		}

		else if (response == "Transaction history") {

			if (account.getTransactionHistory().empty()) {
				std::cout << "\nThere is no existing transaction history";
			}

			else {

				for (const auto& transaction : account.getTransactionHistory()) {
					std::cout << '\n' << transaction.getType() << " " << transaction.getAmount() << '\n';
				}
			}
		}

		else if (response == "Undo") {

			if (account.undo()) {

				std::cout << "\nYou succesfully undid your latest transaction! \n";
			}

			else {

				std::cout << "\nYou have no transaction history to undo! \n";

			}
		}

		else if (response == "Exit") {
			break;
		}

	}
	return 0;

}