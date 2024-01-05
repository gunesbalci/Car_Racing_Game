#define ARABA_GENISLIKI  60
#define ARABA_YUKSEKLIKI 130

struct Araba
{
    int ID;
    float solustkosex;
    float solustkosey;
    float sagustkosex;
    float sagustkosey;
    float solaltkosex;
    float solaltkosey;
    float sagaltkosex;
    float sagaltkosey;
    float Merkez_x;
    float Merkez_y;
    float derece;
};

struct Obje
{
    float solx;
    float usty;
    float sagx;
    float alty;
};

void arabaTanitim(struct Araba *araba1, float x,float y, float derece)
{
        araba1->Merkez_x = x;
        araba1->Merkez_y = y;

        araba1->derece = derece;

        araba1->solustkosex = x-((ARABA_GENISLIKI/3)*(sin(derece*(3.14159/180))))      - ((ARABA_GENISLIKI)*(cos(derece*(3.14159/180))));
        araba1->solustkosey = y-((ARABA_YUKSEKLIKI/2)*(sin(derece*(3.14159/180))))     + ((30)*(cos(derece*(3.14159/180))));

        araba1->solaltkosex = x-((ARABA_GENISLIKI/3)*(sin(derece*(3.14159/180))))      + ((ARABA_GENISLIKI)*(cos(derece*(3.14159/180))));
        araba1->solaltkosey = y+(((ARABA_YUKSEKLIKI/2)-5)*(sin(derece*(3.14159/180)))) + ((30)*(cos(derece*(3.14159/180))));

        araba1->sagustkosex = x+((ARABA_GENISLIKI/3)*(sin(derece*(3.14159/180))))      - ((ARABA_GENISLIKI)*(cos(derece*(3.14159/180))));
        araba1->sagustkosey = y-((ARABA_YUKSEKLIKI/2)*(sin(derece*(3.14159/180))))     - ((20)*(cos(derece*(3.14159/180))));

        araba1->sagaltkosex = x+((ARABA_GENISLIKI/3)*(sin(derece*(3.14159/180))))      + ((ARABA_GENISLIKI)*(cos(derece*(3.14159/180))));
        araba1->sagaltkosey = y+(((ARABA_YUKSEKLIKI/2)-5)*(sin(derece*(3.14159/180)))) - ((20)*(cos(derece*(3.14159/180))));



}

void disDuvarTanitim(struct Obje *disDuvar)
{
        disDuvar->usty = 65;
        disDuvar->alty = 1005;
        disDuvar->sagx = 1865;
        disDuvar->solx = 65;
}

void icDuvarTanitim(struct Obje *icDuvar)
{

        icDuvar->usty = 250;
        icDuvar->alty = 772;
        icDuvar->solx = 281;
        icDuvar->sagx = 1653;
}

void BitisCizgisiTanitim(struct Obje *BitisCizgisi)
{

        BitisCizgisi->usty = 338;
        BitisCizgisi->solx = 58;
        BitisCizgisi->sagx = 286;
}

