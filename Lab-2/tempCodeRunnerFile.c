   clock_t t2 = clock();
    clock_t t3 = t2-t1;
    double result = (double)(t3 / CLOCKS_PER_SEC);
    printf("%lf",result);
    