#ifndef SHA_2_HPP
#define SHA_2_HPP

#include <string>
#include <vector>
#include <bitset>
#include <cmath>

class SHA256
{
    using                     vector32bit = std::vector<std::bitset<32>>;
    uint32_t                  h_s[8];
    const static uint32_t     k[];
    const short               BYTE        = 8;
    const short               TWO_BYTE    = 2 * BYTE;
    const short               WORD        = 4 * BYTE;
    uint32_t                  m_bytes     = 0;
    std::size_t               len_in_bits = 0;
    const uint32_t            ONE_BIT     = 0x80;
    const uint32_t            NULL_BYTE   = 0x0;
    //static const unsigned int BLOCK_SIZE  = 0;
    std::string               data_buffer;
    vector32bit               sha256buf;
public:

    std::string sha256          (std::string message);
    void        init            ();
    void        binary_repres   ();
    void        fill_data_blocks();
    void        transform       ();
};
#endif
