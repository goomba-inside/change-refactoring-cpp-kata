#pragma once

#include <cstdlib>
#include <vector>

class ChangeItForMe {
public:
    std::vector<int> transact(int cost, int tender)
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

        auto dv = std::div(tender, 10);
        int  dd = dv.quot;
        tender  = dv.rem;

        int n = tender / 5;
        if (n > 0)
            tender -= n * 5;

        return {tender, n, dd, q, d};
    }

    std::vector<int> calculate(int amount)
    {
        // Calculate transaction
        return transact(0, amount);
    }
};