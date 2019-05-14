// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019 The CryptoDev developers
// Copyright (c) 2019 The peony developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
      (0    , uint256("00000d7547bc34273b08721bea1230f5c4aad3e134d40a10de51b80c78876209"))
      (2660 , uint256("7ec1d827b095ed22c9247db2323a213d02c51c848f03b9dcbdc122e8f2a99490"))
      (14000, uint256("18d8e725eab8e855c684e925640883090024f78a9f284af78b3842da04bf4982"))
      (15000, uint256("3e2a5f9991e005827dc989547596f39150bc5b59554fe55fffeddb4dda6ab6b2"))
      (18000, uint256("b2c3cbf00988159f01a40724be619208e0cc4b2d09df59e74df76c8f3ebbc68f"))
      (20000, uint256("bebcafb4911dc62fa275407fca13eeeeff357a00418c36fdbc42b6f4624d9513"))
      (30000, uint256("e2297149725d93c6f23d9eb898eae185cf92d2fd6f7183b116bdf2e308e09e87"))
      (40000, uint256("a9c924d8a9b266db84d34c429bc875fed81cfe3f716a4c60e3ccf8048e452927"))
      (50000, uint256("eef108f288467c95f778f7f3024011d45743043caa49d2d6b71bf1aa325d21db"))
      (60000, uint256("513582acc107fe4cba507e8e6a9be871f2d37b53c7c8878bae1c48505769dbbc"))
      (91890, uint256("f8282e0bea3ea57edc31c409d921df9ed534de0783b5bb4c55aebd244886da86"))
      (91890, uint256("05edf4a99bd721ba30e03be0f03b6bb11a742e8f281118ca2c8b1e68d3b747b8"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1557854947, // * UNIX timestamp of last checkpoint block
    244794,     // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("000002dc60cd57672b0e7bf2d17f4d75a1d4e895e77987523103e0bbe61c258b"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1549653940,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("3f0533cd28408f4c06c1726bbbaa400038ed4c62eb6d1d841edc85b378b3251f"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1549653940,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x4b;
        pchMessageStart[1] = 0xac;
        pchMessageStart[2] = 0x2d;
        pchMessageStart[3] = 0xf9;
        vAlertPubKey = ParseHex("026004632f2494ae8121dced2cf3bee3eef8c3d8620ae029fa522497d6c3c3b9ff");
        nDefaultPort = 16889;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // PNY starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 3000000000;
        nMaxReorganizationDepth = 100;

        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // PNY: 1 day
        nTargetSpacing = 1 * 60;  // PNY: 1 minute
        nMaturity = 30;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000001 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 400;
        nModifierUpdateBlock = 0;
        nZerocoinStartHeight = 205;
        nZerocoinStartTime = 1556301910; // October 17, 2017 4:30:00 AM
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 999999999; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 1; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 205; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nBlockDoubleAccumulated = 10;
        nEnforceNewSporkKey = 1556236801; //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1556236799; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;
        nSupplyBeforeFakeSerial = 0 * COIN;   // zerocoin supply at block nFakeSerialBlockheightEnd

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Apple to pay teenager who found FaceTime bug // From BBC 8th of February, 2019";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 50 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("046901033eeb013d794cbbc51a8b6bc5fff90c86bd35d07e3edac2ed065cc738d6bc51ab0214747a0d774fd32c260e01bf8c5d398e981d53cce04785dd20b32d84") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1549653940;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 3378718;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00000d7547bc34273b08721bea1230f5c4aad3e134d40a10de51b80c78876209"));
        assert(genesis.hashMerkleRoot == uint256("0xd4429f27b883d1601606004a030e04ad6c0c225ddb25f4b7bee32a1135b07c18"));

	    vSeeds.push_back(CDNSSeedData("dnsseed.p2p2.me", "dnsseed.peonycoin.io"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 55);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 117);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 118);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x2D)(0x02)(0x31)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x25)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        nBudgetCycleBlocks = 43200; //!< Amount of blocks in a months period of time (using 1 minutes per) = (60*24*30)
        strSporkKey = "04f9f94fe0f327d275c1d90b1c46adc3800386a3d83aaebe6e4fffadfa8e6d12b644ce64758acd471fb67ee8f355b250a0ee319b7d0cb7429f265fd1ea03476e39";
        strSporkKeyOld = "02adf304ea83f5ef9fe03287309ec485796c4702c248ca9e51138721c768e1a7a5";
        strObfuscationPoolDummyAddress = "PXGq4gnCBB18E582Ag7uNeLRrkmKCiUxrf";
        nStartMasternodePayments = 1403728576; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 100; //The required confirmations for a zpny to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x77;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("040537664e4e85ccd3ded3a420921dc1a76eadf6a641ee3d2b532fe90b21202d1562785a3e159bd04315c658e7621c55dd991d28dbbbec5461acb3c94352a872e8");
        nDefaultPort = 41121;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // PNY: 1 day
        nTargetSpacing = 1 * 60;  // PNY: 1 minute
        nLastPOWBlock = 2;
        nMaturity = 5;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 50000000 * COIN;
        nZerocoinStartHeight = 205;
        nZerocoinStartTime = 1556301910;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 999999999; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 1; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 999999999; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 205; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1556236801; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1556236801; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;
        nSupplyBeforeFakeSerial = 0;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1549653940;
        genesis.nNonce = 9239648;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000002dc60cd57672b0e7bf2d17f4d75a1d4e895e77987523103e0bbe61c258b"));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 46); // Testnet peony addresses start with 'k'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 41);  // Testnet peony script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 174);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet peony BIP32 pubkeys
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x61)(0x60)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet peony BIP32 prvkeys
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x88)(0x57)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet peony BIP44
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        nBudgetCycleBlocks = 144; //!< Ten cycles per day on testnet
        strSporkKey = "0463ae6d69bb1ea031c446f5eb734267f89225474ee63dda9a2b05afd8acc323d8643c4a21783d7fea78d1bf5c30b9822c6cba9105f98d990135a2245a6c05269e";
        strSporkKeyOld = "04bfe44aa466e8c9a39228dd72e24551bbdaedcff8a3c78da593487d372f8850ed21d542f81dc68de3d2c12fe4685692c5e2fc660caa8c6fb11b146ff0f00d4f2f";
        strObfuscationPoolDummyAddress = "Ki19CsPJJKcjio3scVDHqoxMV3uhn7K6V8";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nDefaultPort = 51476;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // PNY: 1 day
        nTargetSpacing = 1 * 60;        // PNY: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nLastPOWBlock = 250;
        nMaturity = 30;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 0; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 21000001 * COIN;
        nZerocoinStartHeight = 300;
        nBlockZerocoinV2 = 300;
        nZerocoinStartTime = 1556301910;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 999999999; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 999999999; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 999999999; //Last valid accumulator checkpoint

        // Fake Serial Attack
        nFakeSerialBlockheightEnd = -1;

        //! Modify the regtest genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1549653940;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 1517143;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x3f0533cd28408f4c06c1726bbbaa400038ed4c62eb6d1d841edc85b378b3251f"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fSkipProofOfWorkCheck = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
