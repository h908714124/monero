#include <iostream>
#include "ringct/rctTypes.h"
#include "ringct/rctOps.h"
#include "../../tests/io.h"

using namespace std;

using rct::key;

// https://monero.stackexchange.com/questions/2575/can-i-manually-check-consistency-of-pedersen-commitments-in-ringct
int main(int argc, char *argv[]) {

  const key &fee = rct::d2h(30000000000);
  const key &feeH = rct::scalarmultH(fee);
  key pseudoOuts[3];

  key pseudoOuts0;
  hexdecode("276f03ba8c7852cb545830f7fedcdcd08789675d2a6c265bea236d0de90f6b11", 64, &pseudoOuts0);
  key pseudoOuts1;
  hexdecode("c611cc551db3b05ad6e5dba4ce89a8eeeb18317d8b565031941e98b6b9b8db4f", 64, &pseudoOuts1);
  key pseudoOuts2;
  hexdecode("8a088f1ccd11dd1633a663538faa9cb18c157b4fd37c421697a6356b4d7a98f6", 64, &pseudoOuts2);
  key pseudoOuts3;
  hexdecode("9e1238add1c1a4712904e5d5d8913482dcd6d31af166bc73918fd8148a42f22b", 64, &pseudoOuts3);

  key outPk0;
  hexdecode("f9cabc6b0fd32822feb3e13c70b54b2cdc2a3ce7c88ac661c29ab20732e2974f", 64, &outPk0);
  key outPk1;
  hexdecode("cfb010382648e11d7d5744fe8051c8606f31c901f9ede5b7e392f73790f9e7f8", 64, &outPk1);

  const key &sumIn = rct::addKeys(rct::addKeys(rct::addKeys(pseudoOuts0, pseudoOuts1), pseudoOuts2), pseudoOuts3);
  const key &sumOut = rct::addKeys(rct::addKeys(outPk0, outPk1), feeH);

  cout << "sumIn:  " << sumIn << "\n";
  cout << "sumOut: " << sumOut << "\n";

}
