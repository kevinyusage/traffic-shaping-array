//
// Created by gackt on 2/29/20.
//

#include <cstdio>
#include "TokenArrayLimit.h"

TokenArrayLimit::TokenArrayLimit(const uint64_t init_size_) {
    this->size_ = init_size_;
}

void TokenArrayLimit::updateSize(const uint64_t adjust_size_){
    this->size_ = adjust_size_;
}

bool TokenArrayLimit::getPermits(){
    return false;  // pending develop
}

bool TokenArrayLimit::getOnePermit(){
    auto curr = std::chrono::high_resolution_clock::now();
    auto head = this->tokens_.front();

    std::chrono::duration<double, std::milli> elapsed = curr - head;

    if (this->tokens_.size() < this->size_) {
        this->tokens_.push_back(curr);
        return true;
    } else if(elapsed.count() > this->time_scalue_) {
        this->tokens_.pop_front();
        this->tokens_.push_back(curr);
        return true;
    }

    return false;
}

#define BOOL_STR(b) (b ? "true" : "false")

int main(){
    fprintf(stdout, "now start \n");

    TokenArrayLimit tokenArrayLimit(10);
    int round = 15;
    do {
        bool ret = tokenArrayLimit.getOnePermit();
        fprintf(stdout, "get token ? : %s \n", BOOL_STR(ret));
        --round;
    } while (round >0 );

    return 0;
}
