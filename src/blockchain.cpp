# include "blockchain.h"

using namespace std;

const string genesisData = "Placentium - A blockchain solution to a decentralised filesystem for the future of cloud storage and hosting.";

const int difficulty = 3;

class Blockchain {
    private:
        vector<Block> chain;
        int difficulty;
        
    public:
        Blockchain(Block genesisBlock) {
            chain.push_back(genesisBlock);
        }

        void addBlock(Block nthBlock) {
            chain.push_back(nthBlock);
        }

        Block getLatestBlock() {
            return chain[chain.size() - 1];
        }

        bool isChainValid() {
            for (int i = 1; i < chain.size(); i++) {
                Block currentBlock = chain[i];
                Block previousBlock = chain[i - 1];
                if (currentBlock.getHash() != currentBlock.calculateHash())
                    return false;
                if (currentBlock.getPreviousHash() != previousBlock.getHash())
                    return false;
            }
            return true;
        }

        bool isValidPoW(){
            for (int i = 0; i < chain.size(); i++) {
                Block currentBlock = chain[i];
                string prefix(difficulty, '0');
                if (currentBlock.getHash().substr(0, difficulty) != prefix)
                    return false;
            }
            return true;
        }
};