#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include "kontrol.h"
#include "struct.h"
#include "collision.h"
#include "dusman.h"

#define PIST_GENISLIK   1920
#define PIST_YUKSEKLIK  1080
#define ARABA_GENISLIK  160
#define ARABA_YUKSEKLIK 70

int main()
{
    //--------Tanimlama---------//

    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_install_mouse(), "mouse");
    al_init_font_addon();
    must_init(al_init_ttf_addon(), "ttfaddon");


    ALLEGRO_TIMER* kronometre = al_create_timer(1.0/30.0);
    must_init(kronometre, "kronometre");

    ALLEGRO_EVENT_QUEUE* sira = al_create_event_queue();
    must_init(sira, "sira");

    ALLEGRO_DISPLAY* Goruntuleyici = al_create_display(1920, 1080);
    must_init(Goruntuleyici, "Goruntuleyici");

    ALLEGRO_FONT* font = al_create_builtin_font();
    must_init(font, "font");

    must_init(al_init_primitives_addon(), "sekiller");

    must_init(al_init_image_addon(), "resimler");

    ALLEGRO_KEYBOARD_STATE klavyedurum;
    must_init(&klavyedurum, "klavyedurum");

    ALLEGRO_MOUSE_STATE mousedurum;
    must_init(&mousedurum, "mousedurum");

    al_register_event_source(sira, al_get_keyboard_event_source());
    al_register_event_source(sira, al_get_display_event_source(Goruntuleyici));
    al_register_event_source(sira, al_get_timer_event_source(kronometre));
    al_register_event_source(sira, al_get_mouse_event_source());

    ALLEGRO_BITMAP* pist = al_load_bitmap("pist.png");
    resim_kontrol(pist, "pist");

    ALLEGRO_BITMAP* araba = al_load_bitmap("araba.png");
    resim_kontrol(araba, "araba");

    ALLEGRO_BITMAP* araba2 = al_load_bitmap("araba2.png");
    resim_kontrol(araba2, "araba2");

    ALLEGRO_BITMAP* baslat = al_load_bitmap("baslat.png");
    resim_kontrol(baslat, "baslat");

    ALLEGRO_BITMAP* cikis = al_load_bitmap("cikis.png");
    resim_kontrol(cikis, "cikis");

    ALLEGRO_BITMAP* tekraroyna = al_load_bitmap("tekraroyna.png");
    resim_kontrol(tekraroyna, "tekraroyna");

    ALLEGRO_BITMAP* kazandin = al_load_bitmap("kazandin.png");
    resim_kontrol(kazandin, "kazandin");

    ALLEGRO_BITMAP* kaybettin = al_load_bitmap("kaybettin.png");
    resim_kontrol(kaybettin, "tekraroyna");

    font = al_load_ttf_font("font.ttf",50,0);

    ALLEGRO_EVENT event;

    bool done = false;
    bool redraw = true;
    bool carpisti = false;
    bool Baslangic = false;
    bool OyuncuBitis = true;
    bool gidebilir = true;
    bool AIBitis = true;

    bool baslatb = false;
    bool cikisb = false;
    bool tekraroynatb = false;

    bool oyunda = false;

    bool usttenBcarpti = false;
    bool alttanBcarpti = true;

    float merkezx1, merkezy1, derece1, hiz1, farex, farey, merkezx2, merkezy2, derece2, hiz2;
    merkezx1 = 220;
    merkezy1 = 250;
    derece1 = 90;
    hiz1 = 0;
    farex = 200;
    farey = 200;
    merkezx2 = 120;
    merkezy2 = 250;
    derece2 = 90;
    hiz2 = 10;

    //--------Tanimlama---------//

    //--------Oyun Baslatma----//
    al_start_timer(kronometre);
    while(1)
    {
        //-----Ic Tanimlama---//
        al_wait_for_event(sira, &event);
        al_get_keyboard_state(&klavyedurum);

        struct Araba araba1;
        arabaTanitim(&araba1,merkezx1,merkezy1,derece1);

        struct Araba arabaAI;
        arabaTanitim(&arabaAI,merkezx2,merkezy2,derece2);

        struct Obje disDuvar;
        disDuvarTanitim(&disDuvar);

        struct Obje icDuvar;
        icDuvarTanitim(&icDuvar);

        struct Obje BitisCizgisi;
        BitisCizgisiTanitim(&BitisCizgisi);

        OyuncuBitis = CollisionBitisCizgisi(araba1, BitisCizgisi);

        AIBitis = CollisionDusmanBitisCizgisi(arabaAI, BitisCizgisi);

        carpisti = CollisionMap(araba1,disDuvar,icDuvar);

        usttenBcarpti = CollisionTersBitisCizgisiUst(araba1, BitisCizgisi);

        alttanBcarpti = CollisionTersBitisCizgisiAlt(araba1, BitisCizgisi);

        CollisionDusman(araba1, arabaAI, &hiz2, &hiz1);
        //-----Ic Tanimlama---//

       if(Baslangic)
        {
            switch(event.type)
            {
              case ALLEGRO_EVENT_TIMER:
                if(carpisti)
                {
                    hiz1 = 0;
                }

                //-------Araba Kontrol-------//
                if(al_key_down(&klavyedurum, ALLEGRO_KEY_A) && !carpisti && gidebilir && !alttanBcarpti && !usttenBcarpti)
                {
                    derece1-=5;
                    if(derece1<=0)
                    {
                        derece1=360;
                    }
                }

                if(al_key_down(&klavyedurum, ALLEGRO_KEY_D) && !carpisti && gidebilir && !alttanBcarpti && !usttenBcarpti)
                {
                    derece1+=5;
                    if(derece1>=360)
                    {
                        derece1=0;
                    }
                }

                if(al_key_down(&klavyedurum, ALLEGRO_KEY_W) && gidebilir)
                {
                    if(usttenBcarpti)
                    {
                        hiz1 = 0;
                    }
                    else
                    {
                        if(hiz1<10)
                        hiz1++;
                        if(hiz1>=10)
                        {
                            if(al_key_down(&klavyedurum, ALLEGRO_KEY_SPACE))
                            {
                                hiz1++;
                                if(hiz1 >= 15)
                                {
                                    hiz1 =15;
                                }
                            }
                            else
                            {
                                hiz1 = 10;
                            }

                        }

                    }

                }

                if(al_key_down(&klavyedurum, ALLEGRO_KEY_S) && gidebilir)
                {
                    if(alttanBcarpti)
                    {
                        hiz1 = 0;
                    }
                    else
                    {
                        if(hiz1>-5)
                            hiz1--;

                        if(hiz1<-5)
                            hiz1 = -5;
                    }
                }

                if(hiz1 != 0 && !al_key_down(&klavyedurum, ALLEGRO_KEY_W) && !al_key_down(&klavyedurum, ALLEGRO_KEY_S))
                {
                    if(hiz1>0)
                    {
                        hiz1-= 0.6;
                    }
                    if(hiz1<0)
                    {
                        hiz1+= 0.6;
                    }
                    if(-0.61<hiz1 && hiz1<0.61)
                    {
                        hiz1 = 0;
                    }
                }
                //-------Araba Kontrol-------//


                //-------Konum Degistirme---//
                merkezy1-= hiz1*sin(derece1*3.14159/180);
                merkezx1-= hiz1*cos(derece1*3.14159/180);

                dusmanHareket(arabaAI, &derece2);

                if(AIBitis && OyuncuBitis)
                {
                    merkezx2-=hiz2*cos(derece2*3.14159/180);
                    merkezy2-=hiz2*sin(derece2*3.14159/180);
                }
                //-------Konum Degistirme---//


                redraw = true;
                break;




            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
         }
        }

        //-------Fare Kontrolu-------//
        if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            farex = event.mouse.x;
            farey = event.mouse.y;
            if(farey > 390 && farey <455 && farex>880 && farex<1035)
            {
                baslatb = true;
            }
            else
            {
                baslatb = false;
            }
            if(farey > 520 && farey <590 && farex>895 && farex<1025)
            {
                cikisb = true;
            }
            else
            {
                cikisb = false;
            }
            if(farey > 390 && farey <455 && farex>820 && farex<1100)
            {
                tekraroynatb = true;
            }
            else
            {
                tekraroynatb = false;
            }
        }

        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && !oyunda)
        {
             if(baslatb && !Baslangic)
            {
                Baslangic = true;
            }
            else
            {
                Baslangic = false;
            }
            if(cikisb && !Baslangic)
            {
                return 0;
            }
            if(tekraroynatb && !gidebilir)
            {
                    merkezx1 = 220;
                    merkezy1 = 250;
                    derece1 = 90;
                    hiz1 = 0;
                    farex = 200;
                    farey = 200;
                    merkezx2 = 120;
                    merkezy2 = 250;
                    derece2 = 90;
                    hiz2 = 1;
                    done = false;
                    redraw = true;
                    carpisti = false;
                    OyuncuBitis = true;
                    gidebilir = true;
                    AIBitis = true;
                    baslatb = false;
                    cikisb = false;
                    tekraroynatb = false;
                    usttenBcarpti = false;
                    alttanBcarpti = true;
                    oyunda = false;
                    Baslangic = true;
            }
        }
        //-------Fare Kontrolu-------//


        //-------Goruntu Cizdirme----//
        if(redraw && al_is_event_queue_empty(sira))
        {
            if(!Baslangic)
            {
                al_draw_bitmap(pist,0,0,0);

                if(baslatb)
                {
                    al_draw_tinted_bitmap(baslat,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-78,(PIST_YUKSEKLIK/2)-148,0);
                }
                else
                {
                    al_draw_tinted_bitmap(baslat,al_map_rgb(0,0,0),(PIST_GENISLIK/2)-78,(PIST_YUKSEKLIK/2)-148,0);
                }

                if(cikisb)
                {
                    al_draw_tinted_bitmap(cikis,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-65,(PIST_YUKSEKLIK/2)-11,0);
                }
                else
                {
                    al_draw_tinted_bitmap(cikis,al_map_rgb(0,0,0),(PIST_GENISLIK/2)-65,(PIST_YUKSEKLIK/2)-11,0);
                }
                al_draw_text(font,al_map_rgb(0,0,0), 300, 400, 0, "Hareket Etmek Icin: W,A,S,D");
                al_draw_text(font,al_map_rgb(0,0,0), 300, 470, 0, "Turbo Icin: SPACE");
            }
            else
            {
                oyunda = true;
                al_draw_bitmap(pist,0,0,0);

                al_draw_rotated_bitmap(araba,ARABA_GENISLIK/2,ARABA_YUKSEKLIK/2,araba1.Merkez_x,araba1.Merkez_y,derece1*3.14/180,0);

                al_draw_rotated_bitmap(araba2,ARABA_GENISLIK/2,ARABA_YUKSEKLIK/2,arabaAI.Merkez_x,arabaAI.Merkez_y,derece2*3.14/180,0);

                al_draw_text(font,al_map_rgb(0,0,0), 300, 400, 0, "Hareket Etmek Icin: W,A,S,D");
                al_draw_text(font,al_map_rgb(0,0,0), 300, 470, 0, "Turbo Icin: SPACE");

                if(!OyuncuBitis || !AIBitis)
                {
                    oyunda = false;
                    gidebilir = false;
                    hiz1 = 0;
                }
                if(!gidebilir)
                {
                    if(tekraroynatb)
                    {
                        al_draw_tinted_bitmap(tekraroyna,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-142,(PIST_YUKSEKLIK/2)-148,0);
                    }
                    else
                    {
                        al_draw_tinted_bitmap(tekraroyna,al_map_rgb(0,0,0),(PIST_GENISLIK/2)-142,(PIST_YUKSEKLIK/2)-148,0);
                    }
                    if(!AIBitis)
                    {
                        al_draw_tinted_bitmap(kaybettin,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-180,(PIST_YUKSEKLIK/2)-280,0);
                    }
                    if(!OyuncuBitis)
                    {
                        al_draw_tinted_bitmap(kazandin,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-170,(PIST_YUKSEKLIK/2)-280,0);
                    }
                    if(cikisb)
                    {
                    al_draw_tinted_bitmap(cikis,al_map_rgb(255,255,255),(PIST_GENISLIK/2)-65,(PIST_YUKSEKLIK/2)-11,0);
                    }
                    else
                    {
                    al_draw_tinted_bitmap(cikis,al_map_rgb(0,0,0),(PIST_GENISLIK/2)-65,(PIST_YUKSEKLIK/2)-11,0);
                    }

                }

                redraw = false;
            }

            al_flip_display();

        }
        //-------Goruntu Cizdirme----//

    }
    al_destroy_bitmap(pist);
    al_destroy_bitmap(araba);
    al_destroy_bitmap(baslat);
    al_destroy_bitmap(cikis);
    al_destroy_font(font);
    al_destroy_display(Goruntuleyici);
    al_destroy_timer(kronometre);
    al_destroy_event_queue(sira);


}
