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

int main() {
    std::cout << ssum(0x290198, 0x982901) << std::endl;
    return 0;
}