#include "pricedurationcalc_v.h"

//priceDurationCalc_V::priceDurationCalc_V()
//{

//}

int priceDurationCalc_V::calcPayementFromSec(int duration, int price)
{
    return ((duration * price) / oneHourSec);
}

int priceDurationCalc_V::calcSecDurationFromPayement(int money, int price)
{
    return ((money * oneHourSec) / price);
}
