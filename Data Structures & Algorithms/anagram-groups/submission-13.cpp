#include <vector>
#include <string>
#include <cstring>
#include <cstdint>

class Solution {
    static inline uint64_t mix(uint64_t a, uint64_t b) noexcept {
        __uint128_t r = (__uint128_t)(a ^ 0xa0761d6478bd642full)
                      * (b ^ 0xe7037ed1a0b428dbull);
        return (uint64_t)r ^ (uint64_t)(r >> 64);
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        const uint32_t n = (uint32_t)strs.size();
        if (!n) return {};

        struct alignas(32) Sig { uint8_t c[32]; };   // 26 counts + 6 pad
        vector<Sig>      sig(n);
        vector<uint64_t> hsh(n);

        for (uint32_t i = 0; i < n; ++i) {
            Sig& s = sig[i];
            memset(s.c, 0, 32);
            const char* p = strs[i].data();
            for (const char* e = p + strs[i].size(); p != e; ++p)
                ++s.c[(uint8_t)*p - 'a'];

            uint64_t w0, w1, w2, w3;
            memcpy(&w0, s.c,      8);
            memcpy(&w1, s.c +  8, 8);
            memcpy(&w2, s.c + 16, 8);
            memcpy(&w3, s.c + 24, 8);
            hsh[i] = mix(w0, w1) ^ mix(w2, w3 + 0x9E3779B97F4A7C15ull);
        }

        // open addressing, linear probe, load factor 0.5
        uint32_t cap = 1;
        while (cap < (n << 1)) cap <<= 1;
        const uint32_t mask = cap - 1;

        // slot = [tag:32 | idx+1:32], 0 == empty. One cache line per probe.
        vector<uint64_t> tbl(cap, 0);
        vector<uint32_t> gid(n);
        vector<uint32_t> sz;
        sz.reserve(n);
        uint32_t groups = 0;

        for (uint32_t i = 0; i < n; ++i) {
            const uint64_t h   = hsh[i];
            const uint64_t tag = h & 0xFFFFFFFF00000000ull;
            uint32_t slot = (uint32_t)h & mask;

            for (;;) {
                const uint64_t e = tbl[slot];
                if (!e) {                                  // empty -> new group
                    tbl[slot] = tag | (uint64_t)(i + 1);
                    gid[i] = groups++;
                    sz.push_back(1);
                    break;
                }
                if ((e & 0xFFFFFFFF00000000ull) == tag) {  // tag hit, verify
                    const uint32_t j = (uint32_t)e - 1;
                    if (!memcmp(&sig[j], &sig[i], 32)) {
                        ++sz[gid[i] = gid[j]];
                        break;
                    }
                }
                slot = (slot + 1) & mask;
            }
        }

        vector<vector<string>> res(groups);
        for (uint32_t g = 0; g < groups; ++g) res[g].reserve(sz[g]);
        for (uint32_t i = 0; i < n; ++i) res[gid[i]].push_back(std::move(strs[i]));
        return res;
    }
};