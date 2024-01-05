bool CollisionMap(struct Araba araba1, struct Obje disDuvar, struct Obje icDuvar)
{
    if(araba1.solustkosex < disDuvar.solx ||
        araba1.solaltkosex < disDuvar.solx ||
        araba1.sagustkosex < disDuvar.solx ||
        araba1.sagaltkosex < disDuvar.solx ||

        araba1.solustkosex > disDuvar.sagx ||
        araba1.solaltkosex > disDuvar.sagx ||
        araba1.sagustkosex > disDuvar.sagx ||
        araba1.sagaltkosex > disDuvar.sagx ||

        araba1.solustkosey < disDuvar.usty ||
        araba1.solaltkosey < disDuvar.usty ||
        araba1.sagustkosey < disDuvar.usty ||
        araba1.sagaltkosey < disDuvar.usty ||

        araba1.solustkosey > disDuvar.alty ||
        araba1.solaltkosey > disDuvar.alty ||
        araba1.sagustkosey > disDuvar.alty ||
        araba1.sagaltkosey > disDuvar.alty ||


        ((araba1.solustkosex > icDuvar.solx) && araba1.sagustkosex < icDuvar.solx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.sagustkosex > icDuvar.solx) && araba1.solustkosex < icDuvar.solx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.solaltkosex > icDuvar.solx) && araba1.sagaltkosex < icDuvar.solx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.sagaltkosex > icDuvar.solx) && araba1.solaltkosex < icDuvar.solx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||

        ((araba1.solustkosex < icDuvar.sagx) && araba1.sagustkosex > icDuvar.sagx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.sagustkosex < icDuvar.sagx) && araba1.solustkosex > icDuvar.sagx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.solaltkosex < icDuvar.sagx) && araba1.sagaltkosex > icDuvar.sagx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||
        ((araba1.sagaltkosex < icDuvar.sagx) && araba1.solaltkosex > icDuvar.sagx && araba1.solaltkosey > icDuvar.usty && araba1.sagustkosey < icDuvar.alty) ||

        ((araba1.solustkosey > icDuvar.usty) && araba1.sagustkosey < icDuvar.usty && araba1.solaltkosex < icDuvar.sagx && araba1.sagustkosex > icDuvar.solx) ||
        ((araba1.sagustkosey > icDuvar.usty) && araba1.solustkosey < icDuvar.usty && araba1.solaltkosex < icDuvar.sagx && araba1.sagustkosex > icDuvar.solx) ||
        ((araba1.solaltkosey > icDuvar.usty) && araba1.sagaltkosey < icDuvar.usty && araba1.solaltkosex < icDuvar.sagx && araba1.sagustkosex > icDuvar.solx) ||
        ((araba1.sagaltkosey > icDuvar.usty) && araba1.solaltkosey < icDuvar.usty && araba1.solaltkosex < icDuvar.sagx && araba1.sagustkosex > icDuvar.solx) ||

        ((araba1.solustkosey < icDuvar.alty) && araba1.sagustkosey > icDuvar.alty && araba1.sagustkosex < icDuvar.sagx && araba1.solaltkosex > icDuvar.solx) ||
        ((araba1.sagustkosey < icDuvar.alty) && araba1.solustkosey > icDuvar.alty && araba1.sagustkosex < icDuvar.sagx && araba1.solaltkosex > icDuvar.solx) ||
        ((araba1.solaltkosey < icDuvar.alty) && araba1.sagaltkosey > icDuvar.alty && araba1.sagustkosex < icDuvar.sagx && araba1.solaltkosex > icDuvar.solx) ||
        ((araba1.sagaltkosey < icDuvar.alty) && araba1.solaltkosey > icDuvar.alty && araba1.sagustkosex < icDuvar.sagx && araba1.solaltkosex > icDuvar.solx)  )
        {
            return true;
        }
    else
    {
        return false;
    }
}

bool CollisionBitisCizgisi(struct Araba araba1, struct Obje BitisCizgisi)
{
    if(araba1.Merkez_y > BitisCizgisi.usty  && araba1.Merkez_x > BitisCizgisi.solx && araba1.Merkez_x < BitisCizgisi.sagx)
    {
        if(araba1.solustkosey < BitisCizgisi.usty  ||
           araba1.sagustkosey < BitisCizgisi.usty  ||
           araba1.solaltkosey < BitisCizgisi.usty  ||
           araba1.sagaltkosey < BitisCizgisi.usty   )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

bool CollisionTersBitisCizgisiUst(struct Araba araba1, struct Obje BitisCizgisi)
{
    if( (araba1.Merkez_x > BitisCizgisi.solx && araba1.Merkez_x < BitisCizgisi.sagx))
    {
        if((araba1.solustkosey > 310 && araba1.solustkosey < 320))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool CollisionTersBitisCizgisiAlt(struct Araba araba1, struct Obje BitisCizgisi)
{
    if( (araba1.Merkez_x > BitisCizgisi.solx && araba1.Merkez_x < BitisCizgisi.sagx))
    {
        if((araba1.solaltkosey > 310 && araba1.solaltkosey < 320))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void CollisionDusman(struct Araba araba1, struct Araba araba2, float *hiz2, float *hiz1)
{
    if(( araba1.solustkosex < araba2.sagaltkosex && araba1.solustkosex > araba2.solustkosex && araba1.solustkosey > araba2.solustkosey && araba1.solustkosey < araba2.sagaltkosey ||
         araba1.solaltkosex < araba2.sagaltkosex && araba1.solaltkosex > araba2.solustkosex && araba1.solaltkosey > araba2.solustkosey && araba1.solaltkosey < araba2.sagaltkosey ||
         araba1.sagustkosex < araba2.sagaltkosex && araba1.sagustkosex > araba2.solustkosex && araba1.sagustkosey > araba2.solustkosey && araba1.sagustkosey < araba2.sagaltkosey ||
         araba1.sagaltkosex < araba2.sagaltkosex && araba1.sagaltkosex > araba2.solustkosex && araba1.sagaltkosey > araba2.sagaltkosey && araba1.sagaltkosey < araba2.sagaltkosey ||

         araba1.solustkosex < araba2.sagustkosex && araba1.solustkosex > araba2.solaltkosex && araba1.solustkosey > araba2.solustkosey && araba1.solustkosey < araba2.sagaltkosey ||
         araba1.solaltkosex < araba2.sagustkosex && araba1.solaltkosex > araba2.solaltkosex && araba1.solaltkosey > araba2.solustkosey && araba1.solaltkosey < araba2.sagaltkosey ||
         araba1.sagustkosex < araba2.sagustkosex && araba1.sagustkosex > araba2.solaltkosex && araba1.sagustkosey > araba2.solustkosey && araba1.sagustkosey < araba2.sagaltkosey ||
         araba1.sagaltkosex < araba2.sagustkosex && araba1.sagaltkosex > araba2.solustkosex && araba1.sagaltkosey > araba2.sagaltkosey && araba1.sagaltkosey < araba2.sagaltkosey ||

         araba1.solustkosex < araba2.solaltkosex && araba1.solustkosex > araba2.sagustkosex && araba1.solustkosey > araba2.solustkosey && araba1.solustkosey < araba2.sagaltkosey ||
         araba1.solaltkosex < araba2.solaltkosex && araba1.solaltkosex > araba2.sagustkosex && araba1.solaltkosey > araba2.solustkosey && araba1.solaltkosey < araba2.sagaltkosey ||
         araba1.sagustkosex < araba2.solaltkosex && araba1.sagustkosex > araba2.sagustkosex && araba1.sagustkosey > araba2.solustkosey && araba1.sagustkosey < araba2.sagaltkosey ||
         araba1.sagaltkosex < araba2.sagaltkosex && araba1.sagaltkosex > araba2.sagustkosex && araba1.sagaltkosey > araba2.sagaltkosey && araba1.sagaltkosey < araba2.sagaltkosey ||

         araba1.solustkosex < araba2.solustkosex && araba1.solustkosex > araba2.sagaltkosex && araba1.solustkosey > araba2.solustkosey && araba1.solustkosey < araba2.sagaltkosey ||
         araba1.solaltkosex < araba2.solustkosex && araba1.solaltkosex > araba2.sagaltkosex && araba1.solaltkosey > araba2.solustkosey && araba1.solaltkosey < araba2.sagaltkosey ||
         araba1.sagustkosex < araba2.solustkosex && araba1.sagustkosex > araba2.sagaltkosex && araba1.sagustkosey > araba2.solustkosey && araba1.sagustkosey < araba2.sagaltkosey ||
         araba1.sagaltkosex < araba2.solustkosex && araba1.sagaltkosex > araba2.sagaltkosex && araba1.sagaltkosey > araba2.sagaltkosey && araba1.sagaltkosey < araba2.sagaltkosey)
         ||

        (araba1.solustkosex > araba2.sagaltkosex && araba1.solustkosex < araba2.solustkosex && araba1.solustkosey < araba2.solustkosey && araba1.solustkosey > araba2.sagaltkosey ||
         araba1.solaltkosex > araba2.sagaltkosex && araba1.solaltkosex < araba2.solustkosex && araba1.solaltkosey < araba2.solustkosey && araba1.solaltkosey > araba2.sagaltkosey ||
         araba1.sagustkosex > araba2.sagaltkosex && araba1.sagustkosex < araba2.solustkosex && araba1.sagustkosey < araba2.solustkosey && araba1.sagustkosey > araba2.sagaltkosey ||
         araba1.sagaltkosex > araba2.sagaltkosex && araba1.sagaltkosex < araba2.solustkosex && araba1.sagaltkosey < araba2.sagaltkosey && araba1.sagaltkosey > araba2.sagaltkosey ||

         araba1.solustkosex > araba2.sagustkosex && araba1.solustkosex < araba2.solaltkosex && araba1.solustkosey < araba2.solustkosey && araba1.solustkosey > araba2.sagaltkosey ||
         araba1.solaltkosex > araba2.sagustkosex && araba1.solaltkosex < araba2.solaltkosex && araba1.solaltkosey < araba2.solustkosey && araba1.solaltkosey > araba2.sagaltkosey ||
         araba1.sagustkosex > araba2.sagustkosex && araba1.sagustkosex < araba2.solaltkosex && araba1.sagustkosey < araba2.solustkosey && araba1.sagustkosey > araba2.sagaltkosey ||
         araba1.sagaltkosex > araba2.sagustkosex && araba1.sagaltkosex < araba2.solustkosex && araba1.sagaltkosey < araba2.sagaltkosey && araba1.sagaltkosey > araba2.sagaltkosey ||

         araba1.solustkosex > araba2.solaltkosex && araba1.solustkosex < araba2.sagustkosex && araba1.solustkosey < araba2.solustkosey && araba1.solustkosey > araba2.sagaltkosey ||
         araba1.solaltkosex > araba2.solaltkosex && araba1.solaltkosex < araba2.sagustkosex && araba1.solaltkosey < araba2.solustkosey && araba1.solaltkosey > araba2.sagaltkosey ||
         araba1.sagustkosex > araba2.solaltkosex && araba1.sagustkosex < araba2.sagustkosex && araba1.sagustkosey < araba2.solustkosey && araba1.sagustkosey > araba2.sagaltkosey ||
         araba1.sagaltkosex > araba2.sagaltkosex && araba1.sagaltkosex < araba2.sagustkosex && araba1.sagaltkosey < araba2.sagaltkosey && araba1.sagaltkosey > araba2.sagaltkosey ||

         araba1.solustkosex > araba2.solustkosex && araba1.solustkosex < araba2.sagaltkosex && araba1.solustkosey < araba2.solustkosey && araba1.solustkosey > araba2.sagaltkosey ||
         araba1.solaltkosex > araba2.solustkosex && araba1.solaltkosex < araba2.sagaltkosex && araba1.solaltkosey < araba2.solustkosey && araba1.solaltkosey > araba2.sagaltkosey ||
         araba1.sagustkosex > araba2.solustkosex && araba1.sagustkosex < araba2.sagaltkosex && araba1.sagustkosey < araba2.solustkosey && araba1.sagustkosey > araba2.sagaltkosey ||
         araba1.sagaltkosex > araba2.solustkosex && araba1.sagaltkosex < araba2.sagaltkosex && araba1.sagaltkosey < araba2.sagaltkosey && araba1.sagaltkosey > araba2.sagaltkosey))
    {
        *hiz2 = 0;
        *hiz1 = 0;
    }
    else
    {
        *hiz2 = 10;
    }

}

bool CollisionDusmanBitisCizgisi(struct Araba araba2, struct Obje BitisCizgisi)
{
    if(araba2.Merkez_y > BitisCizgisi.usty && araba2.Merkez_x > BitisCizgisi.solx && araba2.Merkez_x < BitisCizgisi.sagx)
    {
        if(araba2.solustkosey < BitisCizgisi.usty)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

