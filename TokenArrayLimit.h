//
// Created by gackt on 2/29/20.
//

#ifndef TRAFFIC_SHAPING_ARRAY_TOKENARRAYLIMIT_H
#define TRAFFIC_SHAPING_ARRAY_TOKENARRAYLIMIT_H

#include <list>
#include <cstdint>
#include <atomic>
#include <chrono>

class TokenArrayLimit {
public:
    TokenArrayLimit(const uint64_t init_size_);

    virtual ~TokenArrayLimit() = default;

    void updateSize(const uint64_t adjust_size_);

    bool  getPermits();

    bool getOnePermit();

private:
    const std::uint16_t time_scalue_ = 100; // 100 millisecond time scale
    std::atomic_uint64_t size_;  // token-size
    std::list<std::chrono::high_resolution_clock::time_point> tokens_;
};


#endif //TRAFFIC_SHAPING_ARRAY_TOKENARRAYLIMIT_H
