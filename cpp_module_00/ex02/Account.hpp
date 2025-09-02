#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
public:
	typedef Account t;

	// Constructors and Destructor
	Account(int initial_deposit);
	~Account();

	// Instance methods
	void makeDeposit(int deposit);
	bool makeWithdrawal(int withdrawal);
	int checkAmount() const;
	void displayStatus() const;

	// Static methods
	static int getNbAccounts();
	static int getTotalAmount();
	static int getNbDeposits();
	static int getNbWithdrawals();
	static void displayAccountsInfos();

private:
	// Instance variables
	static int _nbAccounts;
	static int _totalAmount;
	static int _totalNbDeposits;
	static int _totalNbWithdrawals;

	int _accountIndex;
	int _amount;
	int _nbDeposits;
	int _nbWithdrawals;

	// Private methods
	Account();
	static void _displayTimestamp();
};

#endif
