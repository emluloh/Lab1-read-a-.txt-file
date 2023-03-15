//Eileen Luloh

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

typedef struct
{
  int idEmpStruct; //Variable to store the employee id
  string nameEmpStruct; //Variable to store the Employee name
}Employee;

typedef struct
{
  int idCusStruct; //Variable to store the Customer id
  string nameCusStruct; //Variable to store the Customer name
  double accBalCusStruct; //Variable to store the Customer account balance
}Customer;

int main()
{
int numEmployees = 0; //amount of employees
int numCustomers = 0; //amount of customers
Employee E[50]; //array of employee struct
Customer C[50]; //array of customer struct
char type, transact; //Variable to store the type of data and transaction type
int id; //to hold IDs from file
string name; //to hold names from file
double balance, amt; //Variable to store balance and transaction amt
int i, j; //Loop Variables
ifstream infile;
infile.open("transactiondata.txt");

while(infile >> type) //loop until type is retrieved
{ 
  if(type == 'e') //type 'e' means employee
  {
    infile >> id; //read employee id
    infile >> name; //read employee name
    E[numEmployees].idEmpStruct = id; //puts id in struct variable
    E[numEmployees].nameEmpStruct = name; //puts name in struct variable
    numEmployees++; //move to the next employee
  }
    else if(type == 'c') //type 'c' means customer
    {
      infile >> id; //read customer id from file
      infile >> name; //read customer name from file
      infile >> balance; //read customer account balance from file
      C[numCustomers].idCusStruct = id; //assign id to structure variable idCusStruct
      C[numCustomers].nameCusStruct = name; //Assign name to structure variable nameCusStruct
      C[numCustomers].accBalCusStruct = balance; //Assign balance to structure variable accBalCusStruct
      numCustomers++; //Increment numCustomers by 1
    }
      else if(type == 't') //type 't' means transaction
      { 
        infile >> id; //read customer id
          for(i = 0; i<numCustomers; i++) //loop for each customer data
          {
            if(C[i].idCusStruct == id) //loop breaks if id matches and i contains index
            {
              break;
            }
          }

infile >> id; //Reading the employee id

for(j = 0; j<numEmployees; j++) //Loop through each employee data
{
  if(E[j].idEmpStruct == id) //loop breaks if id matches and i contains index
  {
  break;
  }
}

infile >> transact; //read transaction type from file
infile >> amt; //read the transaction amount from file
//display data, if the following if else if is placed before this display data the last line of transactions won't be shown
cout << setw(10) << right << C[i].nameCusStruct << setw(15) << right << E[j].nameEmpStruct <<" ";
cout << setprecision(2) << fixed;

if(transact == 'd') //If transaction type is d, means amount to be deposited
  {
    C[i].accBalCusStruct = C[i].accBalCusStruct + amt; //Add the amount to current Customer balance and display it
    cout <<"  +$" << setw(5) << right << amt <<"   $" << setw(5) << right << C[i].accBalCusStruct <<"\n";
  }
    else if(transact == 'w')
    { //If transaction type is w, means amount to be withdrawn
      C[i].accBalCusStruct = C[i].accBalCusStruct - amt; //Subtract the amount from current Customer balance and display it
      cout <<"  -$" << setw(5) << right << amt <<"   $" << setw(5) << right << C[i].accBalCusStruct <<"\n";
    }
  }
}
infile.close(); 
}