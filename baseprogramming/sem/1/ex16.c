#include <stdio.h>

int main() {
    int days_per_month;
    double avg_earnings_eur;
    double exchange_rate;
    double yearly_salary, bonus, total_earnings_before_tax, total_earnings_after_tax, net_daily_earnings;

    printf("enter the number of days worked per month: ");
    scanf("%d", &days_per_month);

    printf("enter the average earnings per day in euros: ");
    scanf("%lf", &avg_earnings_eur);

    printf("enter the exchange rate of euro to lev: ");
    scanf("%lf", &exchange_rate);

    yearly_salary = days_per_month * avg_earnings_eur * 12;
    bonus = 2.5 * yearly_salary;
    total_earnings_before_tax = yearly_salary + bonus;
    total_earnings_after_tax = total_earnings_before_tax * 0.75;
    net_daily_earnings = total_earnings_after_tax / 365;

    printf("Ivan's net average daily earnings in bgn after taxes: %.2lf\n", net_daily_earnings / exchange_rate);

    return 0;
}
