#ifndef NUM_PAIRS_H
#define NUM_PAIRS_H

#define BIT_AMICABLE 0x1
#define BIT_BETROTHED 0x2
#define BIT_SOCIABLE 0x4

// Number pair structure
// Relationship between the numbers in a pair:
// First bit: amicable
// Second bit: betrothed
// Third bit: sociable
struct num_pair {
    unsigned long num[2];
    unsigned long relationship;
};

void init_num_pair(struct num_pair *, unsigned long, unsigned long);
void update_relationship(struct num_pair *);
void print_relationship(struct num_pair *);

// Num pairs operations
int is_amicable(unsigned long, unsigned long);
int is_betrothed(unsigned long, unsigned long);
int is_sociable(unsigned long, unsigned long);

#endif  /* NUM_PAIRS_H */