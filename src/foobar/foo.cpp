// Copyright (c) 2017-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

/*!
 * \file gen_multisig.cpp
 * 
 * \brief Generates a set of multisig wallets
 */
#include <iostream>
#include <sstream>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include "include_base_utils.h"
#include "crypto/crypto.h"  // for crypto::secret_key definition
#include "common/i18n.h"
#include "common/command_line.h"
#include "common/util.h"
#include "common/scoped_message_writer.h"
#include "wallet/wallet_args.h"
#include "wallet/wallet2.h"

using namespace std;
using namespace epee;
using namespace cryptonote;
using boost::lexical_cast;

using rct::key;

//other basepoint H = toPoint(cn_fast_hash(G)), G the basepoint
static const key H = {{0x8b, 0x65, 0x59, 0x70, 0x15, 0x37, 0x99, 0xaf, 0x2a, 0xea, 0xdc, 0x9f, 0xf1, 0xad, 0xd0, 0xea, 0x6c, 0x72, 0x51, 0xd5, 0x41, 0x54, 0xcf, 0xa9, 0x2c, 0x17, 0x3a, 0x0d, 0xd3, 0x9c, 0x1f, 0x94}};

void initOne(key &result) {
  for (size_t j = 0; j < 32; ++j) {
    result[j] = 0;
  }
//  result[31] = 1;
}

// https://monero.stackexchange.com/questions/2575/can-i-manually-check-consistency-of-pedersen-commitments-in-ringct
int main(int argc, char *argv[]) {
//  key k0{};
//  key k1{};
//  initOne(k0);
//  initOne(k1);
  const key &identity = rct::identity();
  const key &G = rct::scalarmultBase(identity);
  const key &G2 = rct::addKeys(G, G);
  const key &result = rct::scalarmultKey(G, identity);
  const crypto::hash &hash = crypto::cn_fast_hash(&G, 32);

  cout << "hello " << identity << "\n";
  cout << "hello " << G << "\n";
  cout << "hello " << result << "\n";
  cout << "hello " << G2 << "\n";
}
