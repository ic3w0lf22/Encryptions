#include "./XTEA.h"

XTEA::XTEA(){
    keyset = false;
}

XTEA::XTEA(const std::string & KEY, const uint8_t & ROUNDS, const uint32_t & DELTA){//, const uint32_t & TOTAL = 0xc6ef3720){
    keyset = false;
    setkey(KEY, ROUNDS, DELTA);
}

void XTEA::setkey(const std::string & KEY, const uint8_t & ROUNDS, const uint32_t & DELTA){
    if (keyset){
        std::cerr << "Error: Key has already been set." << std::endl;
        throw 1;
    }

    if (KEY.size() != 16){
        std::cerr << "Error: Key must be 128 bits in length." << std::endl;
        throw 1;
    }

    delta = DELTA;
    cycles = ROUNDS >> 1;
    for(uint8_t x = 0; x < 4; x++){
        key[x] = (uint32_t) toint(KEY.substr(x << 2, 4), 256);
    }
    keyset = true;
}

std::string XTEA::encrypt(const std::string & DATA){
    if (!keyset){
        std::cerr << "Error: Key has not been set." << std::endl;
        throw 1;
    }

    if (DATA.size() != 8){
        std::cerr << "Error: Data must be 64 bits in length." << std::endl;
        throw 1;
    }

    uint32_t data[2] = {(uint32_t) toint(DATA.substr(0, 4), 256), (uint32_t) toint(DATA.substr(4, 4), 256)};
    total = 0;
    for(uint8_t i = 0; i < cycles; i++){
        data[0] += (((data[1] << 4) ^ (data[1] >> 5)) + data[1]) ^ (total + key[total & 3]);
        total += delta;
        data[1] += (((data[0] << 4) ^ (data[0] >> 5)) + data[0]) ^ (total + key[(total >> 11) & 3]);
    }
    return unhexlify(makehex(data[0], 8) + makehex(data[1], 8));
}

std::string XTEA::decrypt(const std::string & DATA){
    if (!keyset){
        std::cerr << "Error: Key has not been set." << std::endl;
        throw 1;
    }

    if (DATA.size() != 8){
        std::cerr << "Error: Data must be 64 bits in length." << std::endl;
        throw 1;
    }

    uint32_t data[2] = {(uint32_t) toint(DATA.substr(0, 4), 256), (uint32_t) toint(DATA.substr(4, 4), 256)};
    total = delta * cycles;
    for(uint8_t i = 0; i < cycles; i++){
        data[1] -= (((data[0] << 4) ^ (data[0] >> 5)) + data[0]) ^ (total + key[(total >> 11) & 3]);
        total -= delta;
        data[0] -= (((data[1] << 4) ^ (data[1] >> 5)) + data[1]) ^ (total + key[total & 3]);
    }
    return unhexlify(makehex(data[0], 8) + makehex(data[1], 8));
}

unsigned int XTEA::blocksize(){
    return 64;
}
