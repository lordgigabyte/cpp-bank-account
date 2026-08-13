# cpp-bank-account

This is my first C++ project. It's a simple banking program that taught me the core principles of C++, such as: encapsulation, references, iterators, exceptions and more. 

## Features:
**Deposit**
  - Lets the user deposit a given positive amount of money into your bank account.
  
**Withdraw**
  - Lets the user withdraw a given amount of money in the range of the bank account balance and  non negative.

**Show balance**
  - Lets the user check the current balance of their bank account.

**Transaction history**
  - Lets the user check their transaction history in that specific session.

**Undo**
  - Lets the user undo withdrawals and deposits, also shows in the transaction history.

**Exit**
  - Lets the user exit the program.

## Build & run
This project was built and tested in Visual Studio.

1. Clone the repository.
2. Open "herewego.slnx" in Visual Studio.
3. Build and run (Ctrl+F5 or the green run button).
No external dependencies, just the C++ standard library is used.

## Why I made it:
I made this project while learning C++ and it took me about 5 days of active one hour sessions, I learned a lot of things and also felt some familiarities from my Java background, though this felt like i had a lot more control and responsibility of the program itself. This will in no way be an easy journey, but I am definitely looking forward to it. The most interesting parts i learned were probably things like iterators or references since I haven't really used things like references in the past.


## Example interaction:
```
  Hello and welcome, what would you like to do?
  Deposit
  Withdraw
  Show balance
  Transaction history
  Undo
  Exit
  Deposit
  
  Enter deposit amount: 1000
  You deposited: 1000 successfully!
  
  Hello and welcome, what would you like to do?
  Deposit
  Withdraw
  Show balance
  Transaction history
  Undo
  Exit
  Withdraw
  
  Enter withdrawal amount: 264
  You withdrew: 264 successfully!
  
  Hello and welcome, what would you like to do?
  Deposit
  Withdraw
  Show balance
  Transaction history
  Undo
  Exit
  Transaction history
  
  Deposit 1000
  
  Withdraw 264
``` 







