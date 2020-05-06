// #include "../include/formattedPrint.h"
#include "../include/inventoryManager.h"

#include <cstdlib>
#include <iostream>
#include <stdio.h>

int main() {
  char choice, another;
  string name, description, temp;
  int id, quantity;
  float price;
  InventoryManager IM = InventoryManager();

  while (1) {
    system("clear");

    std::cout << "\n\t\t\t====== PRODUCT INVENTORY SYSTEM ======";
    std::cout << "\n\n                                          ";
    std::cout << "\n\n";
    std::cout << "\n \t\t\t\t 1. Add    Products";
    std::cout << "\n \t\t\t\t 2. List   Products";
    std::cout << "\n \t\t\t\t 3. Modify Products";
    std::cout << "\n \t\t\t\t 4. Delete Products";
    std::cout << "\n \t\t\t\t 5. Exit   Program";
    std::cout << "\n\n";
    std::cout << "\t\t\t\t Select Your Choice :=> ";

    choice = getchar();
    std::cin.ignore();

    switch (choice) {
    case '1':
      another = 'Y';
      while (another == 'Y' || another == 'y') {
        system("clear");
        std::cout << "\n Enter the product name: ";
        std::getline(std::cin, name);
        std::cout << " Enter the product description: ";
        std::getline(std::cin, description);
        std::cout << " Enter the product quantity: ";
        std::getline(std::cin, temp);
        quantity = stoi(temp);
        std::cout << " Enter the product price: ";
        std::getline(std::cin, temp);
        price = stof(temp);
        IM.AddProduct(Product(name, description, quantity, price));
        std::cout << " The product has been succesfully added.";
        std::cout << "\n\n Add Another Product (Y/N) :=> ";
        another = getchar();
        std::cin.ignore();
      }
      break;

    case '2':
      system("clear");
      std::cout << "\n == List of Products in the Database ==";
      std::cout << "\n\n\n";
      IM.ViewAllProducts();
      std::cout << "\n\n";
      std::cout << "\n Press Enter to Continue... ";
      another = getchar();
      break;

    case '3':
      another = 'Y';
      while (another == 'Y' || another == 'y') {
        system("clear");
        std::cout << "\n Enter the product id to be modified: ";
        std::getline(std::cin, temp);
        id = stoi(temp);
        if (IM.IsFound(id) == true) {
          std::cout << " Enter the new product name: ";
          std::getline(std::cin, name);
          std::cout << " Enter the new product description: ";
          std::getline(std::cin, description);
          std::cout << " Enter the new product quantity: ";
          std::getline(std::cin, temp);
          quantity = stoi(temp);
          std::cout << " Enter the new product price: ";
          std::getline(std::cin, temp);
          price = stof(temp);
          IM.ModifyProduct(id, name, description, quantity, price);
          std::cout << " The product has been succesfully modified.";
        } else
          std::cout << " Sorry, the product id doesn't exist in the database.";
        std::cout << "\n\n Modify Another Product (Y/N) :=> ";
        another = getchar();
        std::cin.ignore();
      }
      break;

    case '4':
      another = 'Y';
      while (another == 'Y' || another == 'y') {
        system("clear");
        std::cout << "\n Enter the product id to be deleted: ";
        std::getline(std::cin, temp);
        id = stoi(temp);
        if (IM.IsFound(id) == true) {
          IM.DeleteProduct(id);
          std::cout << " The product has been succesfully deleted.";
        } else
          std::cout << " Sorry, the product id doesn't exist in the database.";
        std::cout << "\n\n Delete Another Product (Y/N) :=> ";
        another = getchar();
        std::cin.ignore();
      }
      break;

    case '5':
      system("clear");
      std::cout << "\n Program exiting.";
      std::cout << "\n Press Enter to Continue... ";
      another = getchar();
      exit(0);
    }
  }

  return 0;
}