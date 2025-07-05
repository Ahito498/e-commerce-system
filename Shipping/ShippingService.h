#ifndef SHIPPING_SERVICE_H
#define SHIPPING_SERVICE_H

#include "../Product/ShippableProduct.h"
#include <vector>

namespace ShippingService {
    void shipItems(const std::vector<ShippableProduct*>& items);
}

#endif
