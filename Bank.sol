// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract Bank {
    int private bal;  // balance variable

    constructor() {
        bal = 0;
    }

    // Function to get the balance
    function getBalance() public view returns (int) {
        return bal;
    }

    // Function to withdraw amount
    function withdraw(int amt) public {
        require(bal >= amt, "Insufficient balance"); // Ensure sufficient funds
        bal -= amt;
    }

    // Function to deposit amount
    function deposit(int amt) public {
        bal += amt;
    }
}








// pragma solidity ^0.8.0;

// contract Bank {
//     // Make the balance variable public
//     mapping(address => uint256) public balance;

//     // Function to deposit amount, marked as public
//     function deposit(uint256 amount) public {
//         require(amount > 0, "Amount must be positive");
//         balance[msg.sender] += amount;
//     }

//     // Function to get balance, marked as public
//     function getBalance() public view returns (uint256) {
//         return balance[msg.sender];
//     }

//     // Function to withdraw amount, marked as public
//     function withdraw(uint256 amount) public {
//         require(amount <= balance[msg.sender], "Insufficient balance");
//         balance[msg.sender] -= amount;
//     }
// }







// pragma solidity ^0.8.0;

// contract Bank {
//     struct Account {
//         int balance;
//         string owner;
//         bool exists; // Flag to check if account exists
//     }

//     mapping(address => Account) private accounts; // Mapping of user addresses to their accounts

//     event Deposited(address indexed account, int amount);
//     event Withdrawn(address indexed account, int amount);
//     event AccountCreated(address indexed account, string ownerName);
//     event AccountDeleted(address indexed account);

//     constructor() {
//         // Initialize the contract
//     }

//     // Function to get the balance of the caller
//     function getBalance() public view returns (int) {
//         require(accounts[msg.sender].exists, "Account does not exist");
//         return accounts[msg.sender].balance;
//     }

//     // Function to withdraw amount
//     function withdraw(int amt) public {
//         require(accounts[msg.sender].exists, "Account does not exist");
//         require(accounts[msg.sender].balance >= amt, "Insufficient balance"); // Ensure sufficient funds
//         accounts[msg.sender].balance -= amt;
//         emit Withdrawn(msg.sender, amt); // Emit withdrawal event
//     }

//     // Function to deposit amount
//     function deposit(int amt) public {
//         require(accounts[msg.sender].exists, "Account does not exist");
//         require(amt > 0, "Deposit amount must be positive"); // Ensure positive deposit
//         accounts[msg.sender].balance += amt;
//         emit Deposited(msg.sender, amt); // Emit deposit event
//     }

//     // Function to create an account with an owner name
//     function createAccount(string memory ownerName) public {
//         require(!accounts[msg.sender].exists, "Account already exists"); // Prevent duplicate accounts
//         accounts[msg.sender] = Account(0, ownerName, true);
//         emit AccountCreated(msg.sender, ownerName); // Emit account creation event
//     }

//     // Function to delete the user's account
//     function deleteAccount() public {
//         require(accounts[msg.sender].exists, "Account does not exist"); // Ensure account exists

//         // Reset the account's balance and existence flag
//         delete accounts[msg.sender];
        
//         emit AccountDeleted(msg.sender); // Emit account deletion event
//     }
// }
