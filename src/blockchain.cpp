# include "blockchain.h"

Blockchain::Blockchain(Block genesisBlock, int difficulty) {
    this->difficulty = difficulty;
    chain.push_back(genesisBlock);
}

void Blockchain::addBlock(Block nthBlock) {
    nthBlock.mineBlock(difficulty);
    chain.push_back(nthBlock);
}

Block Blockchain::getLatestBlock() {
    return chain.back();
}

void Blockchain::setDifficulty(int difficulty) {
    this->difficulty = difficulty;
}

int Blockchain::getDifficulty() {
    return difficulty;
}

int Blockchain::getLength() {
    return chain.size();
}

void Blockchain::addData(string data) {
    Block mthBlock = getLatestBlock();
    addBlock(Block(getLength(), mthBlock.getHash(), data));
}

bool Blockchain::isChainValid() {
    string prefix(difficulty, '0');
    for (Block i : chain) {
        if (i.getIndex() == 0)
            continue;
        Block currentBlock = i;
        Block previousBlock = chain[i.getIndex() - 1];
        if (currentBlock.getHash() != currentBlock.calculateHash())
            return false;
        if (currentBlock.getPreviousHash() != previousBlock.getHash())
            return false;
        if (currentBlock.getHash().substr(0, difficulty) != prefix)
            return false;
    }
    return true;
}

void Blockchain::mineChain() {
    cout << "Mining Chain..." << endl;
    for (Block i : chain) {
        i.mineBlock(difficulty);
    }
}

void Blockchain::validateChain() {
    if (!isChainValid()) {
        mineChain();
    }
}

void Blockchain::displayChain() {
    for (Block block : chain) {
        cout << "Block " << block.getHash() << endl;
        cout << "Index: " << block.getIndex() << endl;
        cout << "Previous Hash: " << block.getPreviousHash() << endl;
        cout << "Data: " << block.getData() << endl;
        cout << "Timestamp: " << block.getTimestamp() << endl;
        cout << "Nonce: " << block.getNonce() << endl;
        cout << endl;
    }
}

void Blockchain::displayValidity() {
    if (isChainValid()) {
        cout << "Chain is Valid" << endl;
    }
    else {
        cout << "Chain is not Valid" << endl;
    }
}