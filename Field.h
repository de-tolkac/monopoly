#pragma once

#include <string>

struct Field {
    enum Type {Basic, Chance, Treasury, GoToJail};

    int position;
    std::string name;
    size_t counter = 0;
    Type type;

    // Graphical representation
    int x, y, width, height;
};

void initField(Field (&map)[41]) {
    map[0].name  = "Вперёд";
    map[0].position  = 0;
    map[0].type = Field::Basic;
    map[0].x = 100;
    map[0].y = 100;
    map[0].width = 100;
    map[0].height = 100;

    map[1].name  = "Житная ул.";
    map[1].position  = 1;
    map[1].type = Field::Basic;

    map[2].name  = "Общественная казна";
    map[2].position  = 2;
    map[2].type = Field::Treasury;

    map[3].name  = "Нагатинская ул.";
    map[3].position  = 3;
    map[3].type = Field::Basic;

    map[4].name  = "Подоходный налог";
    map[4].position  = 4;
    map[4].type = Field::Basic;

    map[5].name  = "Рижская железная дорога";
    map[5].position  = 5;
    map[5].type = Field::Basic;

    map[6].name  = "Варшавское шоссе";
    map[6].position  = 6;
    map[6].type = Field::Basic;

    map[7].name  = "Шанс";
    map[7].position  = 7;
    map[7].type = Field::Chance;

    map[8].name  = "Ул. Огарева";
    map[8].position  = 8;
    map[8].type = Field::Basic;

    map[9].name  = "Первая парковая ул.";
    map[9].position  = 9;
    map[9].type = Field::Basic;

    map[10].name = "Просто посетили";
    map[10].position  = 10;
    map[10].type = Field::Basic;
    map[10].x = 100;
    map[10].y = 821;
    map[10].width = 100;
    map[10].height = 100;

    map[11].name = "Ул. Полянка";
    map[11].position  = 11;
    map[11].type = Field::Basic;

    map[12].name = "Электростанция";
    map[12].position  = 12;
    map[12].type = Field::Basic;

    map[13].name = "Ул. Сретенка";
    map[13].position  = 13;
    map[13].type = Field::Basic;

    map[14].name = "Ростовская наб.";
    map[14].position  = 14;
    map[14].type = Field::Basic;

    map[15].name = "Курская железная дорога";
    map[15].position  = 15;
    map[15].type = Field::Basic;

    map[16].name = "Рязанский проспект";
    map[16].position  = 16;
    map[16].type = Field::Basic;

    map[17].name = "Общественная казна";
    map[17].position  = 17;
    map[17].type = Field::Treasury;
    
    map[18].name = "Ул. Вавилова";
    map[18].position  = 18;
    map[18].type = Field::Basic;

    map[19].name = "Рублевское шоссе";
    map[19].position  = 19;
    map[19].type = Field::Basic;

    map[20].name = "Бесплатная стоянка";
    map[20].position  = 20;
    map[20].type = Field::Basic;
    map[20].x = 821;
    map[20].y = 821;
    map[20].width = 100;
    map[20].height = 100;

    map[21].name = "Ул. Тверская";
    map[21].position  = 21;
    map[21].type = Field::Basic;

    map[22].name = "Шанс";
    map[22].position  = 22;
    map[22].type = Field::Chance;

    map[23].name = "Пушкинская ул.";
    map[23].position  = 23;
    map[23].type = Field::Basic;

    map[24].name = "Площадь Маяковского";
    map[24].position  = 24;
    map[24].type = Field::Basic;

    map[25].name = "Казанская железная дорога";
    map[25].position  = 25;
    map[25].type = Field::Basic;

    map[26].name = "Ул. Грузинский Вал";
    map[26].position  = 26;
    map[26].type = Field::Basic;

    map[27].name = "Ул. Чайковского";
    map[27].position  = 27;
    map[27].type = Field::Basic;

    map[28].name = "Водопровод";
    map[28].position  = 28;
    map[28].type = Field::Basic;

    map[29].name = "Смоленская площадь";
    map[29].position  = 29;
    map[29].type = Field::Basic;

    map[30].name = "Отправляйтесь в тюрьму";
    map[30].position  = 30;
    map[30].type = Field::GoToJail;
    map[30].x = 821;
    map[30].y = 100;
    map[30].width = 100;
    map[30].height = 100;

    map[31].name = "Ул. Щусева";
    map[31].position  = 31;
    map[31].type = Field::Basic;

    map[32].name = "Гоголевский бульвар";
    map[32].position  = 32;
    map[32].type = Field::Basic;

    map[33].name = "Общественная казна";
    map[33].position  = 33;
    map[33].type = Field::Treasury;

    map[34].name = "Кутузовский проспект";
    map[34].position  = 34;
    map[34].type = Field::Basic;

    map[35].name = "Ленинградская железная дорога";
    map[35].position  = 35;
    map[35].type = Field::Basic;

    map[36].name = "Шанс";
    map[36].position  = 36;
    map[36].type = Field::Chance;

    map[37].name = "Ул. Малая Бронная";
    map[37].position  = 37;
    map[37].type = Field::Basic;

    map[38].name = "Сверхналог";
    map[38].position  = 38;
    map[38].type = Field::Basic;

    map[39].name = "Ул. Арбат";
    map[39].position  = 39;
    map[39].type = Field::Basic;
    
    map[40].name = "В тюрьме";
    map[40].position  = 10;
    map[40].type = Field::Basic;
    map[40].x = 100;
    map[40].y = 961;
    map[40].width = 100;
    map[40].height = 100;

    for (int i = 0; i < 9; ++i) {
        map[1 + i].x = 100;
        map[1 + i].y = 200 + i * 69;
        map[1 + i].height = 100;
        map[1 + i].width = 69;

        map[31 + i].x = 200 + i * 69;
        map[31 + i].y = 100;
        map[31 + i].height = 69;
        map[31 + i].width = 100;

        map[11 + i].x = 200 + i * 69;
        map[11 + i].y = 821;
        map[11 + i].height = 69;
        map[11 + i].width = 100;

        map[21 + i].x = 821;
        map[21 + i].y = 200 + i * 69;
        map[21 + i].height = 100;
        map[21 + i].width = 69;
    }
}