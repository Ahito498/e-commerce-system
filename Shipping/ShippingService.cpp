#include "ShippingService.h"
#include <iostream>


using namespace std;

void ShippingService::shipItems(const vector<ShippableProduct*>& items) {
    if (items.empty()) {
        cout << "No shippable items to ship." << endl;
        return;
    }

    cout << "\nShipping the following items:" << endl;
    for (size_t i = 0; i < items.size(); ++i) {
        cout << "- " << items[i]->getName()
             << " (" << items[i]->getWeight() << "kg)" << endl;
    }

    cout << "Shipping request completed." << endl;
}
