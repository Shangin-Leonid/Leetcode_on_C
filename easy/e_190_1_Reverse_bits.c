

uint32_t reverseBits(uint32_t n)
{
    uint32_t mask = 0b00000000000000000000000000000001,
            mask_reverse = 0b10000000000000000000000000000000,
            reverse_val = 0b00000000000000000000000000000000;
    while(mask)
    {
        if(n & mask)
            reverse_val = reverse_val | mask_reverse;
        mask <<= 1;
        mask_reverse >>= 1;
    }
    return reverse_val;
}
