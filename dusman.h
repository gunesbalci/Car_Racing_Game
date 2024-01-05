float dusmanHareket(struct Araba araba2, float*derece)
{
    if(*derece<180 && *derece >= 90)
    {
        if(araba2.Merkez_y<220)
        {
            *derece += 5;
        }
    }

    if(*derece<270 && *derece >= 180)
    {
        if(araba2.Merkez_x>1710)
        {
            *derece += 5;
        }
    }

    if(*derece<360 && *derece >= 270)
    {
        if(araba2.Merkez_y>860)
        {
            *derece += 5;
        }
    }
    if(*derece == 360)
    {
        *derece = 0;
    }
    if(*derece<90 && *derece >= 0)
    {
        if(araba2.Merkez_x<212)
        {
            *derece += 5;
        }
    }

}
