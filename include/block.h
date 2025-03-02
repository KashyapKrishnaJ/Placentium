#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <ctime>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>


using namespace std;

class Block {
    private:
        int index;
        string previousHash;
        string data;
        string hash;
        time_t timestamp;
        int nonce;

    public:
        Block(int index, string previousHash, string data);
        string getHash();
        int getIndex();
        string getData();
        time_t getTimestamp();
        int getNonce();
        string getPreviousHash();
        string calculateHash();
        void mineBlock(int difficulty);
};

#endif BLOCK_H