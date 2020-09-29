#include <cstring>
#include <iostream>
#include <cstdlib>
#include "sha_2.hpp"

const uint32_t SHA256::k[64] =
                            {0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
                             0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
                             0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
                             0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
                             0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
                             0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
                             0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
                             0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
                             0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
                             0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
                             0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
                             0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
                             0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
                             0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
                             0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
                             0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

void SHA256::binary_repres(){
    /* Binary representation message */
    for(std::size_t i = 0; i <= data_buffer.size() + 1;){
        if((data_buffer.size() +1) - i >= 4){
            sha256buf.push_back(data_buffer[i] << 24 | data_buffer[i + 1] << 16 |
                                data_buffer[i + 2] << 8 | data_buffer[i + 3]);
            std::cout << sha256buf[m_bytes].to_ullong() << '\n';
            ++m_bytes;
            i += 4;
        }else{
            if((data_buffer.size() +1) - i == 3){
                sha256buf.push_back(data_buffer[i] | data_buffer[i + 1] | data_buffer[i + 2] | NULL_BYTE);
                std::cout << sha256buf[m_bytes].to_ullong() << '\n';
                ++i;
                ++m_bytes;
            }else if((data_buffer.size() +1) - i == 2){
                sha256buf.push_back(data_buffer[i] | data_buffer[i + 1] | NULL_BYTE | NULL_BYTE);
                std::cout << sha256buf[m_bytes].to_ullong() << '\n';
                i+=2;
                ++m_bytes;
            }else if((data_buffer.size() +1) - i == 1){
                sha256buf.push_back(data_buffer[i] | NULL_BYTE | NULL_BYTE | NULL_BYTE);
                std::cout << sha256buf[m_bytes].to_ullong() << '\n';
                i+=3;
                ++m_bytes;
            }else if(i >= data_buffer.size()) ++i; // end of cycle
        }
    }
    sha256buf.push_back(ONE_BIT); // add 1 to end at message
}

void SHA256::init(){
    h_s[0] = 0x6a09e667;
    h_s[1] = 0xbb67ae85;
    h_s[2] = 0x3c6ef372;
    h_s[3] = 0xa54ff53a;
    h_s[4] = 0x510e527f;
    h_s[5] = 0x9b05688c;
    h_s[6] = 0x1f83d9ab;
    h_s[7] = 0x5be0cd19;
    len_in_bits = {data_buffer.size() * BYTE};
    //sha256buf.push_back(len_in_bits);
}

void SHA256::fill_data_blocks(){
    uint32_t b_rem = 15 - ((m_bytes + 1) % (2 * BYTE));
    for(std::size_t i = 0; i <= b_rem; ++i){
        sha256buf.push_back(NULL_BYTE); //fill data blocks to (data MOD 16) bytes
        ++m_bytes;
    }
    sha256buf.push_back(len_in_bits);
    ++m_bytes;
    std::cout << m_bytes << '\n';
    std::cout << sha256buf[m_bytes].to_ullong() << '\n';
}

void SHA256::transform(){
    std::bitset<32> tmp1;
    std::bitset<32> tmp2;
    /* 
        * need a create massive buffer to all logic with bytes 
        * need to create tmp buffer
        * realize algorithm logic
    */
}

std::string SHA256::sha256(std::string message) {
    data_buffer = std::move(message);
    SHA256::init();
    SHA256::binary_repres();
    SHA256::fill_data_blocks();
    return "";
}