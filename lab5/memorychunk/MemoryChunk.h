//
// Created by mat on 29.03.17.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H

#include <cstdint>
#include <algorithm>

namespace mc {
    class MemoryChunk {
//        Rule ofFive
    public:
        MemoryChunk(size_t sz);

        int8_t *MemoryAt(size_t offset) const;

        size_t ChunkSize() const;

//        Rule of Five
        MemoryChunk(const MemoryChunk &mm);

        MemoryChunk(MemoryChunk &&mm);

        MemoryChunk &operator=(const MemoryChunk &mm);

        MemoryChunk &operator=(MemoryChunk &&mm);

        ~MemoryChunk();

    private:
        int8_t *mem_;
        size_t howbig_;
    };

}
#endif //JIMP_EXERCISES_MEMORYCHUNK_H
