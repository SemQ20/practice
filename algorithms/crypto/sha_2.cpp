#include <iostream>
#include "sha_2.hpp"
#include "../nAlgorithms.hpp"

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

void SHA256::binary_data_repres(){
    /* Binary representation message */
    for(std::size_t i = 0; i <= data_buffer.size() + 1;){
        if((data_buffer.size() +1) - i >= 4){
            sha256buf.push_back(data_buffer[i] << 24 | data_buffer[i + 1] << 16 |
                                data_buffer[i + 2] << 8 | data_buffer[i + 3]);
            ++m_bytes;
            i += 4;
        }else{
            if((data_buffer.size() +1) - i == 3){
                sha256buf.push_back(data_buffer[i] | data_buffer[i + 1] | data_buffer[i + 2] | NULL_BYTE);
                ++i;
                ++m_bytes;
            }else if((data_buffer.size() +1) - i == 2){
                sha256buf.push_back(data_buffer[i] | data_buffer[i + 1] | NULL_BYTE | NULL_BYTE);
                i+=2;
                ++m_bytes;
            }else if((data_buffer.size() +1) - i == 1){
                sha256buf.push_back(data_buffer[i] | NULL_BYTE | NULL_BYTE | NULL_BYTE);
                i+=3;
                ++m_bytes;
            }else if(i >= data_buffer.size()) ++i; // end of cycle
        }
    }
    sha256buf.push_back(ONE_BIT); // add 1 to end at message
    BLOCK_SIZE = m_bytes / TWO_BYTE;
}

void SHA256::init(){
    /* initialize koefficients:*/
    h_s[0] = 0x6a09e667;
    h_s[1] = 0xbb67ae85;
    h_s[2] = 0x3c6ef372;
    h_s[3] = 0xa54ff53a;
    h_s[4] = 0x510e527f;
    h_s[5] = 0x9b05688c;
    h_s[6] = 0x1f83d9ab;
    h_s[7] = 0x5be0cd19;
    len_in_bits = {data_buffer.size() * BYTE};

    /* initialize helper variables */
    for(std::size_t i = 0; i <= 7; ++i){
        h_v.push_back(h_s[i]);
    }
}

void SHA256::fill_data_blocks(){
    ZERO_BLOCKS = 15 - ((m_bytes + 1) % (TWO_BYTE)); // 15 because last 16 byte - lenght message in bits
    for(std::size_t i = 0; i <= ZERO_BLOCKS; ++i){
        sha256buf.push_back(NULL_BYTE); //fill data blocks to (data MOD 16) bytes
        ++m_bytes;
    }
    sha256buf.push_back(len_in_bits); // last 16 byte
    ++m_bytes; // measure last byte
    ++ZERO_BLOCKS; // real zero blocks
    /* data lenght / 16 */
    BLOCK_SIZE = ZERO_BLOCKS != 0 ? BLOCK_SIZE + 1 : BLOCK_SIZE;
}

void SHA256::transform(){
    std::bitset<32> tmp    = 0x0;
    std::bitset<32> tmp1   = 0x0;
    std::bitset<32> sigma0 = 0x0;
    std::bitset<32> sigma1 = 0x0;
    std::bitset<32> Ma     = 0x0;
    std::bitset<32> Ch     = 0x0;
    std::bitset<32> t    = 0x0;
    std::bitset<32> t1   = 0x0;

    while(BLOCK_SIZE > 0){
        SHA256::move_data_to_temp_buf(start_index);
        /* generate 48 words to 64: */
        for(std::size_t i = 16; i <= 63; ++i){
            tmp  = (std::__rotr(w[i - 15].to_ullong(), 7)) xor (std::__rotr(w[i - 15].to_ullong(), 18)) xor (w[i - 15].to_ullong() >> 3);
            tmp1 = (std::__rotr(w[i - 2].to_ullong(), 17)) xor (std::__rotr(w[i - 2].to_ullong(), 19))  xor (w[i - 2].to_ullong()  >> 10);
            w.push_back(w[i - 16].to_ullong() + tmp.to_ullong() + w[i-7].to_ullong() + tmp1.to_ullong());
        }
        
        for(std::size_t i = 0; i <= 63; ++i){
            sigma0 = (std::__rotr(h_v[0].to_ullong(), 2)) xor (std::__rotr(h_v[0].to_ullong(), 13)) xor (std::__rotr(h_v[0].to_ullong(), 22));
            Ma     = (h_v[0].to_ullong() and h_v[1].to_ullong()) xor (h_v[0].to_ullong() and h_v[2].to_ullong()) xor (h_v[1].to_ullong() and h_v[2].to_ullong());
            t1     = sigma0.to_ullong() + Ma.to_ullong();
            sigma1 = (std::__rotr(h_v[4].to_ullong(), 6)) xor (std::__rotr(h_v[4].to_ullong(), 11)) xor (std::__rotr(h_v[4].to_ullong(), 25));
            Ch     = (h_v[4].to_ullong() and h_v[5].to_ullong()) xor ((not(h_v[4].to_ullong())) and h_v[6].to_ullong());
            t      = h_v[7].to_ullong() + sigma1.to_ullong() + Ch.to_ullong() + k[i] + w[i].to_ullong();

            h_v[7] = h_v[6];
            h_v[6] = h_v[5];
            h_v[5] = h_v[4];
            h_v[4] = h_v[3].to_ullong() + t.to_ullong();
            h_v[3] = h_v[2];
            h_v[2] = h_v[1];
            h_v[1] = h_v[0];
            h_v[0] = t.to_ullong() + t1.to_ullong();
        }
    }
        
}

void SHA256::move_data_to_temp_buf(std::size_t index){
    end_index += 16;
    std::size_t j = 0;
    for(start_index; start_index <= end_index; start_index++){
        w.push_back(sha256buf[start_index]);
    }
    BLOCK_SIZE--;
}

void SHA256::hash_compute(){
    for(std::size_t i = 0; i <= 7; ++i){
        h_s[i] += h_v[i].to_ullong();
        sha256_hash += decimalToHex(h_s[i]);
    }
}

std::string SHA256::sha256(std::string message) {
    data_buffer = std::move(message);
    SHA256::init();
    SHA256::binary_data_repres();
    SHA256::fill_data_blocks();
    SHA256::transform();
    SHA256::hash_compute();
    return sha256_hash;
}