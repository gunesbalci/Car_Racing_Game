void must_init(bool test, const char *description)
{
    if(test)
        return;

    printf("%s Baslatilamadi\n",description);
    exit(1);
}

void resim_kontrol(ALLEGRO_BITMAP* resim, const char *description)
{
    if(!resim)
    {
        printf("%s yuklenemedi", description);
    }
}
