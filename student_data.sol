//SPDX-License-Identifier: MIT
pragma solidity ^0.8.0; // Updated to allow any version from 0.8.0 to less than 0.9.0

// Contract to manage student data
contract StudentMarksManagementSys {
    // Structure to store student details
    struct Student {
        uint ID;          // Student ID
        string fName;    // First Name
        string lName;    // Last Name
        uint marks;      // Marks
    }

    address owner;                     // Contract owner
    uint public stdCount = 0;         // Counter for students
    mapping(uint => Student) public stdRecords; // Mapping of student records

    // Modifier to restrict access to only the owner
    modifier onlyOwner() {
        require(owner == msg.sender, "Only owner can call this function");
        _;
    }

    // Constructor to initialize the contract owner
    constructor() {
        owner = msg.sender;
    }

    // Function to add new student records
    function addNewRecords(uint _ID, string memory _fName, string memory _lName, uint _marks) public onlyOwner {
        stdCount += 1; // Increment student count
        stdRecords[stdCount] = Student(_ID, _fName, _lName, _marks); // Store student record
    }

    // Function to add bonus marks to the last added student
    function bonusMarks(uint _bonus) public onlyOwner {
        require(stdCount > 0, "No students added yet");
        stdRecords[stdCount].marks += _bonus; // Add bonus marks
    }

    // Fallback function to receive Ether
    receive() external payable {}
}






// pragma solidity >=0.8.0;

// contract Student {
//     struct student {
//         uint256 prn;
//         string name;
//         string class;
//         string department;
//     }
//     uint256 PRN;
//     mapping(uint256 => student) studentMap;

//     function addStudent(
//         string memory name,
//         string memory class,
//         string memory department
//     ) public {
//         PRN += 1;
//         studentMap[PRN] = student(PRN, name, class, department);
//     }

//     function getStudent(uint256 _id) public view returns (student memory) {
//         return studentMap[_id];
//     }

//     function totalStudents() public view returns (uint256) {
//         return (PRN);
//     }

//     fallback() external {
//         addStudent("Unknown", "FE", "CSE");
//     }
// }



