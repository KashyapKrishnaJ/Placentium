# ifndef BLOCKCHAIN_H
# define BLOCKCHAIN_H

# include <vector>
# include <iostream>
# include "block.h"

using namespace std;

class Blockchain {
    private:
        vector<Block> chain;
        int difficulty;
        void addBlock(Block nthblock);
        bool isChainValid();
    
    public:
        Blockchain(Block genesisBlock, int difficulty);
        Block getLatestBlock();
        void setDifficulty(int difficulty);
        int getDifficulty();
        int getLength();
        void addData(string data);

        void mineChain();
        void validateChain();
        void displayChain();
        void displayValidity();
};

# endif BLOCKCHAIN_H