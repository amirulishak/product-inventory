#ifndef PRODUCT_H_
#define PRODUCT_H_
#include <string>
#include <vector>

using std::string;

class Product {
private:
  // Data members
  int id;
  string name;
  float price;
  int quantity;
  string description;

public:
  // Constructors
  Product();
  Product(string &n, string &d, const int q, const float p);
  // Getters
  int GetId();
  string GetName();
  string GetDescription();
  int GetQuantity();
  float GetPrice();
  // Setters
  void SetName(string &n);
  void SetDescription(string &d);
  void SetQuantity(const int q);
  void SetPrice(const float p);
};

class InventoryManager {
private:
  std::vector<Product> products;

public:
  // Constructors
  InventoryManager();
  // Getters
  int GetId();
  int GetSize();

  // Member functions
  bool IsFound(int id);
  void AddProduct(const Product &p);
  void ModifyProduct(const int id, string &n, string &d, const int q,
                     const float p);
  void ViewAllProducts();
  void DeleteProduct(int id);
};
#endif
