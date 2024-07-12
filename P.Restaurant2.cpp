#include <iostream>
#include <vector>
#include <string>

using namespace std;

class FoodItem {
public:
    string name;
    double price;

    FoodItem(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

double calculateFinalPrice(double price, double vat) {
    return price + (price * vat / 100);
}

int main() {
    vector<FoodItem> menu;
    int numberOfItems;
    double vat;

    cout << "تعداد آیتم‌های منو را وارد کنید: ";
    cin >> numberOfItems;

    for (int i = 0; i < numberOfItems; i++) {
        string name;
        double price;

        cout << "نام غذا " << i + 1 << ": ";
        cin.ignore();
        getline(cin, name);
        cout << "قیمت غذا " << i + 1 << ": ";
        cin >> price;

        menu.push_back(FoodItem(name, price));
    }

    cout << "درصد ارزش افزوده را وارد کنید: ";
    cin >> vat;

    cout << "\nمنوی نهایی با قیمت‌های نهایی:\n";
    for (const auto& item : menu) {
        double finalPrice = calculateFinalPrice(item.price, vat);
        cout << "نام غذا: " << item.name << " - قیمت نهایی: " << finalPrice << endl;
    }

    return 0;
}
