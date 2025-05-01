#pragma once

#include <vector>

class ChangeItForMe {
public:
    static std::vector<int> transact(const int cost, int tender)
    {
        tender = tender - cost;

        int d = 0;
        for (; tender >= 100; tender += -100)
            d = d + 1;

        int q = 0;
        while (tender >= 25) {
            tender -= 25;
            q += 1;
        }

        auto [dd, rem] = std::div(tender, 10);
        tender         = rem;

        int n = tender / 5;
        if (n > 0)
            tender -= n * 5;

        return {tender, n, dd, q, d};
    }

    static std::vector<int> calculate(const int amount)
    {
        // Calculate transaction
        return transact(0, amount);
    }
};