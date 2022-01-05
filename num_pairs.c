#include <stdio.h>
#include "num_pairs.h"

void init_num_pair(struct num_pair *pair, unsigned long a, unsigned long b)
{
    pair->num[0] = a;
    pair->num[1] = b;
    pair->relationship = 0;
}

void update_relationship(struct num_pair *pair)
{
    if (is_amicable(pair->num[0], pair->num[1])) {
        pair->relationship |= BIT_AMICABLE;
    }
    if (is_betrothed(pair->num[0], pair->num[1])) {
        pair->relationship |= BIT_BETROTHED;
    }
    if (is_sociable(pair->num[0], pair->num[1])) {
        pair->relationship |= BIT_SOCIABLE;
    }
}

void print_relationship(struct num_pair *pair)
{
    if (pair->relationship == 0) {
        printf("No relationship\n");
        return;
    }
    if ((pair->relationship & BIT_AMICABLE) != 0) {
        printf("Amicable\n");
    }
    if ((pair->relationship & BIT_BETROTHED) != 0) {
        printf("Betrothed\n");
    }
    if ((pair->relationship & BIT_SOCIABLE) != 0) {
        printf("Sociable\n");
    }
}

int is_amicable(unsigned long a, unsigned long b)
{
    // Amicable numbers: Two differnet natural numbers such that the 
    // sum of the proper divisors of each is equal to the other number
    if (a == b) {
        return 0;
    }
    
    unsigned long i, sum_a, sum_b;
    sum_a = 0;
    sum_b = 0;
    for (i = 1; i < a; i++) {
        if ((a % i) == 0) {
            sum_a += i;
        }
    }
    for (i = 1; i < b; i++) {
        if ((b % i) == 0) {
            sum_b += i;
        }
    }

    if ((sum_a == b) && (sum_b == a)) {
        return 1;
    } else {
        return 0;
    }
}

int is_betrothed(unsigned long a, unsigned long b)
{
    // Betrothed numbers: Two differnet natural numbers such that the 
    // sum of the proper divisors of each is equal to the other number + 1
    if (a == b) {
        return 0;
    }
    
    unsigned long i, sum_a, sum_b;
    sum_a = 0;
    sum_b = 0;
    for (i = 1; i < a; i++) {
        if ((a % i) == 0) {
            sum_a += i;
        }
    }
    for (i = 1; i < b; i++) {
        if ((b % i) == 0) {
            sum_b += i;
        }
    }

    if ((sum_a == b + 1) && (sum_b == a + 1)) {
        return 1;
    } else {
        return 0;
    }
}

int is_sociable(unsigned long a, unsigned long b)
{
    // TODO
    return 0;
}