#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;   //no of months applicable to
  double contribution;   //number of dollars spent or contributed to the account per month
  double rate_of_return;  //rate of return (assumed after inflation)
};

typedef struct _retire_info retire_info;

double calculate_balance(retire_info r, double initial){
  double balance;
  balance = r.contribution+initial+(r.rate_of_return*initial);
  return balance;
}

void print_balance(int age,double init_balance,retire_info x){
  int ageYears,ageMonths;
  double curr_balance;
  ageYears = age/12;
  ageMonths = age%12;
  curr_balance=calculate_balance(x,init_balance);
  printf("Age %3d month %2d you have $%.2lf\n",ageYears,ageMonths,curr_balance); 
  }

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double current_balance=initial;
  for(int i=1;i<working.months+retired.months;i++){
    if(i<=working.months){
      print_balance(startAge+i,current_balance,working);
      current_balance=calculate_balance(working,current_balance);
    }
    else{
      print_balance(startAge+i,current_balance,retired);
      current_balance=calculate_balance(retired,current_balance);
    }
  }
}

int main(){
  int starting_age=327;
  double initial_savings=21345.0;
  retire_info Working;
  retire_info Retired;
  
  Working.months=489;
  Working.contribution=1000.0;
  Working.rate_of_return=0.045/12.0;

  Retired.months=384;
  Retired.contribution=-4000.0;
  Retired.rate_of_return=0.01/12.0;
  
  printf("Age %3d month %2d you have $%.2lf\n",starting_age/12,starting_age%12,initial_savings); 
  retirement(starting_age,initial_savings,Working,Retired);

  return EXIT_SUCCESS;
}

  

  
  
  
  
  
  
