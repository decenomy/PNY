// Copyright (c) 2016-2018 The Zcash developers
// Copyright (c) 2020 The PIVX developers
// Copyright (c) 2020 The CryptoDev developers
// Copyright (c) 2020 The peony developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PNY_KEY_IO_SAPLING_H
#define PNY_KEY_IO_SAPLING_H

#include "chainparams.h"
#include "sapling/zip32.h"

namespace KeyIO {

    std::string EncodePaymentAddress(const libzcash::PaymentAddress& zaddr);
    libzcash::PaymentAddress DecodePaymentAddress(const std::string& str);
    bool IsValidPaymentAddressString(const std::string& str);

    std::string EncodeSpendingKey(const libzcash::SpendingKey& zkey);
    libzcash::SpendingKey DecodeSpendingKey(const std::string& str);
}

#endif //PNY_KEY_IO_SAPLING_H
