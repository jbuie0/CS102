// lab5b.cpp
// Jalen Buie
// 4/14/2021
//This code is a online shopping cart simulator. It prompts user for item name, quantity, price and outputs overall price of items in shopping cart.

#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <vector>
#include <iomanip>

using namespace std;

//Sets up class for item.

class Item

{
public:
    Item();
    void setName(string name);               //Mutator
    void setPrice(double price);             //Mutator
    void setQuantity(int quantity);          // Mutator
    void setDescription(string description); // Mutator

    Item(string name, double price, int quantity, string description);

    void Print();                  //Accessor
    string GetName() const;        //Accessor
    double GetPrice() const;       //Accessor
    int GetQuantity() const;       //Accessor
    string GetDescription() const; //Accessor
    void PrintDescription();       //Accessor

private: // Private variables
    string name;
    double price;
    int quantity;
    string description;
};
class ShoppingCart // Sets up class for the shopping cart
{

private: //Private variables
    string customerName;
    string currentDate;
    vector<Item> cartItems;

public:
    ShoppingCart();
    //Parameterized constructor
    ShoppingCart(string name, string date);
    //Accessors
    string GetCustomerName();
    string GetDate();
    //Add a new item into cart
    void AddItem(const Item &item);
    //search for an item
    int FindItemIndex(const string &name) const;
    //Remove an item from cart
    void RemoveItem(const string &name);
    //change quantity
    void ChangeQuantity(const string &name, int newQuantity);
    //return sum of total quantity
    int GetTotalQuantity() const;
    //return sum of total cost
    double GetTotalCost() const;
    //summary of all items
    void PrintTotal();
    //Total description of cart
    void PrintDescriptions();
};

//ShoppingCart Definition
ShoppingCart::ShoppingCart()
{
    currentDate = "April 1,2020";
    customerName = "None";
}
//Parameterized constructor
ShoppingCart::ShoppingCart(string name, string date)
{
    this->currentDate = date;
    this->customerName = name;
}
//Accessors
string ShoppingCart::GetCustomerName()
{
    return customerName;
}
string ShoppingCart::GetDate()
{
    return currentDate;
}
//Adds a new item to cart
void ShoppingCart::AddItem(const Item &item)
{
    cartItems.push_back(item);
}
//Find item within cart
int ShoppingCart::FindItemIndex(const string &name) const
{
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].GetName() == name)
        {

            return i;
        }
    }
    return -1;
}
//Remove item from cart
void ShoppingCart::RemoveItem(const string &name)
{

    int i = FindItemIndex(name);
    if (i == -1)
        cout << "Item not found in cart.\n";
    else
    {
        cartItems.erase(cartItems.begin() + i);
        return;
    }
}
//Modify items within cart
void ShoppingCart::ChangeQuantity(const string &name, int newQuantity)
{
    int i = FindItemIndex(name);
    if (i == -1)
        cout << "Item not found in cart.\n";
    else
    {
        cartItems[i].setQuantity(newQuantity);
    }
}
//Quantity
int ShoppingCart::GetTotalQuantity() const
{
    int total = 0;
    for (int i = 0; i < cartItems.size(); i++)
    {
        total += cartItems[i].GetQuantity();
    }
    return total;
}
//Cost
double ShoppingCart::GetTotalCost() const
{
    double total = 0;
    for (int i = 0; i < cartItems.size(); i++)
    {
        total += cartItems[i].GetPrice() * cartItems[i].GetQuantity();
    }
    return total;
}

//Total
void ShoppingCart::PrintTotal()
{
    cout << customerName << "'s Shopping Cart - " << currentDate << "\nNumber of Items: " << GetTotalQuantity() << "\n"
         << "\n";
    if (cartItems.size() == 0)
    {
        cout << "SHOPPING CART IS EMPTY";
    }
    cout << "\n";
    for (int i = 0; i < cartItems.size(); i++)
    {
        cartItems[i].Print();
    }
    cout << "\nTotal: $" << GetTotalCost() << "\n";
}
//Description
void ShoppingCart::PrintDescriptions()
{
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << "\n";
    cout << "\n"
         << "Item Descriptions\n";
    for (int i = 0; i < cartItems.size(); i++)
    {
        cartItems[i].PrintDescription();
    }
}

char printMenu();
int main()
{
    Item item;
    string name;
    int num = 0;
    double price;
    int quantity;
    vector<Item> items;
    string tempString;
    stringstream ss;
    cout << fixed << setprecision(2);
    string description;
    string date;
    ShoppingCart cart(name, date);
    char choice;
    char q;
    do
    {
        choice = printMenu();
        //Adds item to shopping cart
        if (choice == 'a')
        {
            cin.ignore();
            cout << "\nADD ITEM TO CART\n";
            cout << "Enter the item name:\n";
            getline(cin, name);
            cout << "Enter the item description:\n";
            getline(cin, description);
            cout << "Enter the item price:\n";
            cin >> price;
            cout << "Enter the item quantity:\n";
            cin >> quantity;
            Item item(name, price, quantity, description);
            cart.AddItem(item);
        }
        //Deletes an item from shopping cart
        else if (choice == 'd')
        {
            cin.ignore();
            cout << "\nREMOVE ITEM FROM CART\n";
            cout << "Enter name of item to remove:";
            getline(cin, name);
            cout << "\n";
            cart.RemoveItem(name);
        }
        //Change quantity of items in shopping cart
        else if (choice == 'c')
        {
            cin.ignore();
            cout << "\nCHANGE ITEM QUANTITY\n";
            cout << "Enter the item name:";
            getline(cin, name);
            cout << "\n";
            cout << "Enter the new quantity:";
            cin >> quantity;
            cout << "\n";
            cart.ChangeQuantity(name, quantity);
        }
        //Print descritpiotn of items
        else if (choice == 'i')
        {
            cout << "\n";
            cout << "OUTPUT ITEMS' DESCRIPTIONS"
                 << "\n";
            cart.PrintDescriptions();
        }
        //Print cart total
        else if (choice == 'o')
        {
            cout << "\n";
            cout << "OUTPUT SHOPPING CART"
                 << "\n";
            cart.PrintTotal();
        }
    } while (choice != q); // CODE EXITS ONCE Q ENTERED
    return 0;
}

char printMenu()
{
    char q;
    cout << "MENU\na - Add item to cart\nd - Remove item from cart\nc - Change item quantity\n"
         << "i - Output items' descriptions\no - Output shopping cart\nq - Quit\n";
    cout << "\nChoose an option:";
    cin >> q;
    q = tolower(q);
    while (q != 'a' && q != 'd' && q != 'c' && q != 'i' && q != 'o' && q != 'q')
    {
        cout << "\nChoose an option:";
        cin >> q;
        q = tolower(q);
    }
    cout << "\n";

    return q;
}

Item::Item() // Constructor. Sets name to none, price to 0, and quantity to 0.

{
    name = "none";
    price = 0;
    quantity = 0;
    description = "none";
}

Item::Item(string name, double price, int quantity, string description)
{
    this->name = name;
    this->price = price;
    this->quantity = quantity;
    this->description = description;
}

void Item::setName(string name) // Assigns name
{
    this->name = name;
}

void Item::setDescription(string description) // Assigns description
{
    this->description = description;
}

void Item::setPrice(double price) // Assigns price
{

    this->price = price;
}

void Item::setQuantity(int quantity) // Assigns quantity
{

    this->quantity = quantity;
}

string Item::GetName() const // Returns value of name
{
    return name;
}

string Item::GetDescription() const // Returns value of description
{
    return description;
}

double Item::GetPrice() const //Returns value of price
{

    return price;
}

int Item::GetQuantity() const //Returns value of quantity
{

    return quantity;
}

void Item::Print() // Accessor that prints out name,quantity, and price
{
    cout << name << ": " << quantity << " at $" << price << " = $" << (price * quantity) << "\n";
}

void Item::PrintDescription() // Accessor that prints out description of an item.
{
    cout << name << ": " << description << "\n";
}
