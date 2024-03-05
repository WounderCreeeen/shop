#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product {
private:
    string name;
    int quantity;
    double price;
    string description;

public:
    Product(string n, int q, double p, string d) : name(n), quantity(q), price(p), description(d) {}

    string getName() const { return name; }
    int getQuantity() const { return quantity; }
    double getPrice() const { return price; }
    string getDescription() const { return description; }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
        cout << "--------------------------";
    }
};

class Showcase {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void display() const {
        for (size_t i = 0; i < products.size(); ++i) {
            cout << "Product " << i + 1 << ":" << endl;
            products[i].display();
            cout << endl;
        }
    }

    int size() const {
        return products.size();
    }

    const Product& getProduct(int index) const {
        return products[index];
    }
};

class ShoppingCart {
private:
    vector<pair<Product, int>> products;
    double totalCost;

public:
    ShoppingCart() : totalCost(0) {}

    void addProduct(const Product& product, int quantity) {
        products.push_back(make_pair(product, quantity));
        totalCost += quantity * product.getPrice();
    }

    int size() const {
        int count = 0;
        for (auto& p : products) {
            count += p.second;
        }
        return count;
    }

    void display() const {
        for (size_t i = 0; i < products.size(); ++i) {
            cout << "Product " << i + 1 << ":" << endl;
            products[i].first.display();
            cout << endl;
            cout << "Quantity: " << products[i].second << endl;
            cout << endl;
        }
        cout << "Total Cost: $" << totalCost << endl;
    }
};

int main() {
    Product product1("Laptop", 10, 999.99, "A high-performance laptop.");
    Product product2("Smartphone", 20, 599.99, "A latest model smartphone.");
    Product product3("Tablet", 30, 199.99, "A latest model tablet.");
    Product product4("TV", 40, 499.99, "A high-resolution TV with qled display.");

    Showcase showcase;
    showcase.addProduct(product1);
    showcase.addProduct(product2);
    showcase.addProduct(product3);
    showcase.addProduct(product4);

    int choice;
    ShoppingCart cart;
    do {
        cout << "Welcome to the Store!" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. Add Product to Cart" << endl;
        cout << "3. Display Cart" << endl;
        cout << "4. Exit" << endl;
        cout << "-----------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showcase.display();
            break;
        case 2:
            int productIndex, quantity;
            cout << "Enter the product number to add to cart: ";
            cin >> productIndex;
            cout << "Enter the quantity: ";
            cin >> quantity;
            if (productIndex > 0 && productIndex <= showcase.size()) {
                cart.addProduct(showcase.getProduct(productIndex - 1), quantity);
                cout << "Product added to cart!" << endl;
                cout << "-----------------------" << endl;
            }
            else {
                cout << "Invalid product number!" << endl;
                cout << "-----------------------" << endl;
            }
            break;
        case 3:
            cout << "Shopping Cart:" << endl;
            cart.display();
            cout << "Total items: " << cart.size() << endl;
            break;
        case 4:
            cout << "Thank you for visiting the Store!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}