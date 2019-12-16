#ifndef PRICEDURATIONCALC_V_H
#define PRICEDURATIONCALC_V_H


class priceDurationCalc_V
{
public:
//    priceDurationCalc_V();
    static constexpr int oneHourSec = 3600;
    static int calcPayementFromSec(int duration, int price);
    static int calcSecDurationFromPayement(int money, int price);

};

#endif // PRICEDURATIONCALC_V_H
