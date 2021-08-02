#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double Calculate_Monthly_Payment(double, double, double);
void Loan_Information(double, double, double, double);
void Amorization_Table(double,double,double);
int main(void){
    double numYears;
    double numMonths;
    double loanAmount;
    double apr;
    double paymentMonthly;
    
    printf("Please enter number of years for the loan:\n");
    scanf("%lf", &numYears);
    
    printf("Please enter the loan amount:\n");
    scanf("%lf", &loanAmount);

    printf("Please enter the Annual Percentage Rate:\n");
    scanf("%lf", &apr);
   
   numMonths = numYears * 12;
    
   
    Loan_Information(numYears, numMonths, loanAmount, apr);
    Amorization_Table(numMonths, loanAmount, apr);
    
    return 0;
}


double Calculate_Monthly_Payment(double numMonths, double loanAmount, double apr){
    double intrestMonthly;
    double p;
    double q;
    double paymentMonthly;
    
    intrestMonthly = (apr/12)/100;
    
    p = pow(1+intrestMonthly,numMonths);
    
    q = p/(p-1);
    
    paymentMonthly = (loanAmount * intrestMonthly * q);
    

    return paymentMonthly;
    
    
}

void Loan_Information(double numYears, double numMonths,double loanAmount, double apr){
double paymentMonthly = Calculate_Monthly_Payment(numMonths,loanAmount,apr);
double intrestMonthly = (apr/12)/100;
printf("Number of Years is %0.2lf\n", numYears);

printf("Number of Months is %0.2lf\n", numMonths);

printf("The Loan Amount is $%0.2lf\n", loanAmount);

printf("The APR is %0.4lf\n", apr);

printf("The monthly intrest rate is %0.6lf\n", intrestMonthly);

printf("The Monthly payment is $%0.2lf\n", paymentMonthly);


Calculate_Monthly_Payment(numMonths,loanAmount,apr);
return;
}

void Amorization_Table(double numMonths, double loanAmount, double apr){
    int i;
    double intrestMonthly = (apr/12)/100;
    double paymentMonthly = Calculate_Monthly_Payment(numMonths,loanAmount,apr);
    double intrestPaid = loanAmount * intrestMonthly;
    double principalPaid = paymentMonthly - intrestPaid;
    double newBalance = loanAmount;
    double totalAmount;
    double  totalIntrest=0.0;
    printf("Month:     Old         Monthly        Intrest       Principal        New\n");
    printf("          Amount:      Payment:        Paid:          Paid:        Balance:\n");
    printf("******************************************************************************\n");
    for(i=1;i<=numMonths; ++i){
        newBalance = loanAmount - (paymentMonthly-(loanAmount*intrestMonthly));
        totalIntrest = totalIntrest+intrestPaid;
 printf("%5d:    %10.2lf   %10.2lf    %10.2lf     %10.2lf       %10.2lf\n",i, loanAmount, paymentMonthly,intrestPaid, principalPaid, newBalance);
            loanAmount = loanAmount - (paymentMonthly-(loanAmount*intrestMonthly));
            intrestPaid = loanAmount * intrestMonthly;
            principalPaid = paymentMonthly - intrestPaid;
        
            
    }
    totalAmount = paymentMonthly * numMonths;
    printf("The total amount paid is $%0.2lf\n", totalAmount);
    
    printf("You payed %0.2lf in intrest\n", totalIntrest);
    printf("******************************************************************************\n");
    
    return;
}

