#include <iostream>
#include <ctime>
#include "Account.class.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ){
    char buffer[80];
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    std::strftime(buffer,80,"[%Y%m%d_%H%M%S] ",timeinfo);
    std::cout << buffer;

}

int	Account::getNbAccounts( void ){
    return _nbAccounts;
}
int	Account::getTotalAmount( void ){
    return _totalAmount;
}
int	Account::getNbDeposits( void ){
    return _totalNbDeposits;;
}
int	Account::getNbWithdrawals( void ){
    return _totalNbWithdrawals;
}
void Account::displayAccountsInfos( void ){
    _displayTimestamp();
    std::cout << "accounts: " << _nbAccounts 
    << ";total:" << _totalAmount 
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
}


Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals= 0;

    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";created\n";
}

Account::Account(void){
    _accountIndex = _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals= 0;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";created\n";
};

Account::~Account(void){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";closed\n";
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}

void Account::makeDeposit( int deposit ){
    _nbDeposits++;
    _totalNbDeposits++;
    int p_amount = _amount;
    _amount += deposit;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits
    << std::endl;
}
bool Account::makeWithdrawal( int withdrawal ){
    // We assume that the bank cannot loose money from elsewhere
    //and therefore always has enough money if customer has.
    if (_amount < withdrawal || withdrawal < 0) {// I can see you trying to steal money from me ;)
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
        << ";p_amount:" << _amount
        << ";withdrawal:refused\n";
        return 1;
    }
    int p_amount = _amount;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";withdrawal:" << withdrawal
    << ";amount:" << _amount
    << ";nb_withdrawals:" << _nbWithdrawals
    << std::endl;
    return 0;
}
int Account::checkAmount( void ) const{
    _nbCallsToCheckAmount++;
    return _amount;
}
void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << std::endl;
}