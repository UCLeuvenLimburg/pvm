namespace solution
{
    unsigned sqr(unsigned x)
    {
        return x * x;
    }

    bool is_divisible_by(unsigned a, unsigned b)
    {
        return b != 0 ? a % b == 0 : false;
    }

    bool is_prime(unsigned n)
    {
        if (n < 2)
        {
            return false;
        }
        else
        {
            unsigned k = 2;

            while (sqr(k) <= n)
            {
                if (is_divisible_by(n, k))
                {
                    return false;
                }

                ++k;
            }

            return true;
        }
    }

    unsigned nth_prime(unsigned n)
    {
        unsigned k = 2;

        while (n > 0)
        {
			k++;

            if (is_prime(k))
            {
                n--;
            }
        }

        return k;
    }
}