#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <gmp.h>

typedef mpz_t* ll;

ll GCD(ll a, ll b)
{
    mpz_gcd(*a, *a, *b);
    return a;
}

ll gen_rand(ll min, ll max)
{
    mpz_t rand_num;
    mpz_init(rand_num);

    mpz_urandomb(rand_num, *max - *min + 1, rand() % 100);

    mpz_add(rand_num, rand_num, *min);

    return rand_num;
}

ll f_seq(ll x, ll c, ll n)
{
    mpz_t result;
    mpz_init(result);

    mpz_mul(result, *x, *x);
    mpz_add(result, result, *c);
    mpz_mod(result, result, *n);

    return result;
}

ll Pollard_rho(ll n)
{
    mpz_t x, y, c, d;
    mpz_inits(x, y, c, d, NULL);

    if (mpz_even_p(*n))
    {
        mpz_set_ui(*d, 2);
        return d;
    }

    mpz_set(x, *gen_rand(1, n - 1));
    mpz_set(y, x);
    mpz_set(c, *gen_rand(1, n - 1));
    mpz_set_ui(d, 1);

    while (mpz_cmp_ui(*d, 1) == 0)
    {
        mpz_set(x, *f_seq(x, c, n));
        mpz_set(y, *f_seq(*f_seq(y, c, n), c, n));

        mpz_abs(d, *GCD(*x - *y, n));
    }

    return d;
}

void factors(ll n)
{
    ll* List_array;
    ll factor;
    int i = 0;
    ll n_copy;
    mpz_init_set(n_copy, n);

    List_array = (ll*)malloc(sizeof(ll) * mpz_get_ui(n));
    while (mpz_cmp_ui(*n, 1) > 0)
    {
        mpz_inits(*factor, NULL);
        mpz_set(*factor, *Pollard_rho(n));
        List_array[i] = factor;
        mpz_fdiv_q(*n, *n, *factor);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        gmp_printf("%Zd ", *List_array[j]);
    }
    printf("\n");

    free(List_array);
}

int main(void)
{
    mpz_t num;
    mpz_init_set_str(num, "1718944270642558716715", 10);

    factors(num);

    mpz_clear(num);
    printf("Done\n");

    return 0;
}
