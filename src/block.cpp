# include "block.h"

Block::Block(int index, string previousHash, string data){
    this->index = index;
    this->previousHash = previousHash;
    this->data = data;
    timestamp = time(nullptr);
    nonce = 0;
    hash = calculateHash();
}

string Block::getHash() {
    return hash;
}

string Block::getPreviousHash() {
    return previousHash;
}

string Block::calculateHash() {
    stringstream ss;
    ss << index << previousHash << data << timestamp << nonce;
    string input = ss.str();        
    unsigned char hashResult[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*) input.c_str(), input.size(), hashResult);
    stringstream hexStream;
    for (unsigned char i : hashResult)
        hexStream << hex << setw(2) << setfill('0') << (int)i;
    return hexStream.str();
}

void Block::mineBlock(int difficulty) {
    string prefix(difficulty, '0');
    while (hash.substr(0, difficulty) != prefix) {
        nonce++;
        hash = calculateHash();
    }
}

int Block::getIndex() {
    return index;
}

string Block::getData() {
    return data;
}

time_t Block::getTimestamp() {
    return timestamp;
}

int Block::getNonce() {
    return nonce;
}