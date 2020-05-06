#include "../include/inventoryManager.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

int productCount = 0;

// Print formatter function
template <class T> void printOut(T t, int w) {
  std::cout << std::left << " " << std::setw(w) << std::setfill(' ') << t;
}

// Product class implementation
Product::Product() {}
Product::Product(string &n, string &d, const int q, const float p)
    : id(++productCount), name(n), description(d), quantity(q), price(p) {}
int Product::GetId() { return id; }
string Product::GetName() { return name; }
string Product::GetDescription() { return description; }
int Product::GetQuantity() { return quantity; }
float Product::GetPrice() { return price; }
void Product::SetName(string &n) { name = n; }
void Product::SetDescription(string &d) { description = d; }
void Product::SetQuantity(const int q) { quantity = q; }
void Product::SetPrice(const float p) { price = p; }

// InventoryManager class implementation
InventoryManager::InventoryManager() {}
int InventoryManager::GetSize() { return products.size(); }
bool InventoryManager::IsFound(int id) {
  bool found = false;
  for (auto i = products.begin(); i != products.end(); i++)
    if (i->GetId() == id)
      found = true;

  return found;
}
void InventoryManager::AddProduct(const Product &p) { products.push_back(p); }
void InventoryManager::ModifyProduct(const int id, string &n, string &d,
                                     const int q, const float p) {
  products[id - 1].SetName(n);
  products[id - 1].SetDescription(d);
  products[id - 1].SetQuantity(q);
  products[id - 1].SetPrice(p);
}
void InventoryManager::ViewAllProducts() {
  printOut("ID", 5);
  printOut("NAME", 25);
  printOut("DESCRIPTION", 50);
  printOut("QUANTITY", 10);
  printOut("PRICE(RM)", 10);

  for (Product p : products) {
    std::cout << "\n\n";
    printOut(p.GetId(), 5);
    printOut(p.GetName(), 25);
    printOut(p.GetDescription(), 50);
    printOut(p.GetQuantity(), 10);
    printOut(p.GetPrice(), 10);
  }
}
void InventoryManager::DeleteProduct(int id) {
  products.erase(products.begin() + (id - 1));
}