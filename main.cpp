#include <iostream>

uint32_t ssum(uint32_t left, uint32_t right){

    uint8_t rl, gl, bl, rr, gr, br;

    rl = left/(UINT16_MAX+1);
    rr = right/(UINT16_MAX+1);
    gl = left/(UINT8_MAX+1);
    gr = right/(UINT8_MAX+1);
    bl =left%(UINT16_MAX+1);
    br =right%(UINT16_MAX+1);

    uint8_t r, g, b;

    if(rl + rr >= UINT8_MAX){

        r = UINT8_MAX;

    }else{

        r = rl + rr;

    }

    if(gl + gr >= UINT8_MAX){

        g = UINT8_MAX;

    }else{

        g = gl + gr;

    }

    if(bl + br >= UINT8_MAX){

        b = UINT8_MAX;

    }else{

        b = bl + br;

    }

    return b + g*(UINT8_MAX+1) + r*(UINT16_MAX+1);

};

uint32_t ssum2(uint32_t left, uint32_t right){

    uint32_t signmask = 0x80808080;
    uint32_t t0 = (right ^ left) & signmask; // не общие старшие разряды
    uint32_t t1 = (right & left) & signmask; // общие старшие разряды
    left &= ~signmask; // убираем старшие разряды,
    right &= ~signmask; // чтобы не было переполнения при сложении
    left += right; // складываем
    t1 |= t0 & left; // добавление старших разрядов появившихся при сложении
    t1 = (t1 << 1) - (t1 >> 7); // ?
    return (left ^ t0) | t1; // зачем ксорить ?

};

int main() {
    std::cout << ssum(0x290198, 0x982901) << std::endl;
    std::cout << ssum(0x290198, 0x982901) << std::endl;
    return 0;
}