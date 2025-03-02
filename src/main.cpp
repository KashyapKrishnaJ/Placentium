# include <iostream>
# include "blockchain.h"

using namespace std;

const string genesisData = "Placentium - A blockchain solution to a decentralised filesystem for the future of cloud storage and hosting.";

const int difficulty = 3;

int main(){
    Block genesisBlock(0, "0", genesisData);
    Blockchain placentium(genesisBlock, difficulty);
    placentium.addData("Hello World!!");
    placentium.addData("I'm a blockchain!!");

    placentium.displayChain();
    placentium.displayValidity();
    cout << endl;
    placentium.validateChain();
    placentium.displayChain();
    placentium.displayValidity();
    cout << endl;

    return 0;
}