#ifndef UTILS_H
#define UTILS_H


int find_divisible(int x, int y, int z);

int find_nth_divisible(int n, int f_i, int z);

int validate_identity_number(char identity_number[]);

int create_customer(char identity_number[], int password);

int check_login(char identitiy_number[], int password);

int withdrawable_amount(float cash_amount);



#endif
