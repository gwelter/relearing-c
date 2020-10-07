#include <stdio.h>

#define FIRST_RATE 300
#define SECOND_RATE 150

#define HOURLY_PAY 12.0
#define OVERTIME 40

float overtime_hourly_payment(float hours) {
    return (hours - OVERTIME) * 0.5 * HOURLY_PAY;  //50% bonus
}

float total_hourly_payment(float hours) {
    float extra_payment = hours > OVERTIME ? overtime_hourly_payment(hours) : 0;
    return hours * HOURLY_PAY + extra_payment;
}

float calculate_tax(float gross_pay) {
    float first_gross_amount = gross_pay > FIRST_RATE ? FIRST_RATE : gross_pay;
    float second_gross_amount = gross_pay > FIRST_RATE ? gross_pay - FIRST_RATE : 0;
    float third_gross_amount = gross_pay > (FIRST_RATE + SECOND_RATE) ? gross_pay - FIRST_RATE - SECOND_RATE : 0;

    float first_tax_rate = first_gross_amount * .15;
    float second_tax_rate = second_gross_amount * .20;
    float third_tax_rate = third_gross_amount * .25;

    return first_tax_rate + second_tax_rate + third_tax_rate;
}

int main() {
    float worked_hours;
    printf("Please inform the amount of worked hours: ");
    scanf("%f", &worked_hours);

    float gross_pay = total_hourly_payment(worked_hours);
    float taxes = calculate_tax(gross_pay);
    float free_money = gross_pay - taxes;

    printf("gross_pay: \t$%.2f\n", gross_pay);
    printf("taxes: \t\t$%.2f\n", taxes);
    printf("free_money: \t$%.2f\n", free_money);

    return 0;
}