#ifndef SHA_2_HPP
#define SHA_2_HPP

#include <string>
#include <vector>
#include <bitset>
#include <bit>

class SHA256
{
    uint32_t                     h_s[8];
    const static uint32_t        k[];
    const short                  BYTE        = 8;
    const short                  TWO_BYTE    = 2 * BYTE;
    const short                  WORD        = 4 * BYTE;
    uint32_t                     m_bytes     = 0;
    std::size_t                  len_in_bits = 0;
    const uint32_t               ONE_BIT     = 0x80;
    const uint32_t               NULL_BYTE   = 0x0;
    uint32_t                     BLOCK_SIZE  = 0;
    uint32_t                     ZERO_BLOCKS = 0;
    std::size_t                  start_index = 0;
    std::size_t                  end_index   = 0;
    std::string                  data_buffer;
    std::string                  sha256_hash = "";
    std::vector<std::bitset<32>> sha256buf;
    std::vector<std::bitset<32>> h_v;
    std::vector<std::bitset<32>> w;

public:

    std::string sha256               (std::string message);
    void        init                 ();
    void        binary_data_repres   ();
    void        fill_data_blocks     ();
    void        transform            ();
    void        move_data_to_temp_buf(std::size_t index);
};
#endif
