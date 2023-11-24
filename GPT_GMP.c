#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <gmp.h>

void gcd(mpz_t result, const mpz_t a, const mpz_t b) {
    mpz_t temp;
    mpz_init(temp);

    mpz_set(temp, b);
    while (mpz_cmp_ui(temp, 0) != 0) {
        mpz_set(result, b);
        mpz_set(b, a);
        mpz_fdiv_r(temp, a, b);
        mpz_set(a, result);
    }

    mpz_set(result, a);

    mpz_clear(temp);
}

void pollards_rho(mpz_t result, const mpz_t n) {
    mpz_t x, y, c, d, temp;
    mpz_inits(x, y, c, d, temp, NULL);

    if (mpz_even_p(n)) {
        mpz_set_ui(result, 2);
        return;
    }

    gmp_randstate_t state;
    gmp_randinit_mt(state);
    mpz_urandomm(x, state, n);
    mpz_set(y, x);
    mpz_urandomm(c, state, n);
    mpz_set_ui(d, 1);

    void f(mpz_t res, const mpz_t val) {
        mpz_set(temp, val);
        mpz_powm_ui(res, val, 2, n);
        mpz_add(res, res, c);
        mpz_fdiv_r(res, res, n);
    }

    while (mpz_cmp_ui(d, 1) == 0) {
        f(x, x);
        f(y, y);
        f(y, y);
        gcd(d, x, y);
    }

    mpz_set(result, d);

    mpz_clears(x, y, c, d, temp, NULL);
    gmp_randclear(state);
}

void factorize(const mpz_t n) {
    mpz_t temp, factors;
    mpz_inits(temp, factors, NULL);

    mpz_set(temp, n);
    printf("The prime factors of ");
    mpz_out_str(stdout, 10, n);
    printf(" are: ");

    while (mpz_cmp_ui(temp, 1) > 0) {
        pollards_rho(factors, temp);
        mpz_out_str(stdout, 10, factors);
        printf(" ");

        mpz_fdiv_q(temp, temp, factors);
    }

    printf("\n");

    mpz_clears(temp, factors, NULL);
}

void really_expensive_function() {
  for (int i = 0; i < 10000; ++i) {
    printf("Hi\n");
  }
}

int main() {
  clock_t start = clock();
  mpz_t n;
  mpz_init_set_str(n, "2147483647", 10); // Replace with your number
  factorize(n);
  mpz_clear(n);
  clock_t end   = clock();
  printf("Took %f seconds\n", (((float)(end-start) / CLOCKS_PER_SEC)));
  return 0;
}
