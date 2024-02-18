// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2014-2018, The Monero Project
// Copyright (c) 2018-2019, The TurtleCoin Developers
// Copyright (c) 2024, The Rezin Team
//
// Please see the included LICENSE file for more information.

#pragma once

#include <boost/uuid/uuid.hpp>
#include <crypto/hash.h>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <limits>
#include <string>

namespace CryptoNote
{
  namespace parameters
  {
    const uint64_t DIFFICULTY_TARGET                                       = 30;                              /* Every block takes 30 seconds */
    const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX                 = 0x66712;                          /* Wallet addresses prefix: Na1 */
    const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                             = 500000000;
    const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                          = 500000000;
    const size_t   CRYPTONOTE_MAX_TX_SIZE                                  = 1000000000;
    const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW                    = 10;
    const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT                      = 6 * DIFFICULTY_TARGET;
    const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V3                   = 6 * DIFFICULTY_TARGET;
    const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V4                   = 6 * DIFFICULTY_TARGET;
    const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW                       = 11;
    const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V3                    = 11;

    const uint64_t MONEY_SUPPLY                                            = UINT64_C(80'000'000'00000000);   /* 80'000'000 NLM */
    const uint64_t BLOCK_REWARD                                            = UINT64_C(400'000000);            /* Miner Reward: 4.00000000 NLM */
    const uint64_t GENESIS_BLOCK_REWARD                                    = UINT64_C(800'000'00000000);      /* Premine Reward: 800'000.00000000 NLM (1%) */

    const uint64_t BLOCK_REWARD_P2                                         = UINT64_C(200'000000);            /* Miner Reward: 2.00000000 NLM */
    const uint64_t MASTERNODE_BLOCK_REWARD_P2                              = UINT64_C(300'000000);            /* Masternode Reward: 3.00000000 NLM (75%) */
    const uint64_t STAKING_BLOCK_REWARD_P2                                 = UINT64_C(100'000000);            /* Staking Reward: 1.00000000 NLM (25%) */

    const uint64_t BLOCK_REWARD_P3                                         = UINT64_C(200'000000);            /* Miner Reward: 2.00000000 NLM */
    const uint64_t MASTERNODE_BLOCK_REWARD_P3                              = UINT64_C(400'000000);            /* Masternode Reward: 4.00000000 NLM (75%) */
    const uint64_t STAKING_BLOCK_REWARD_P3                                 = UINT64_C(200'000000);            /* Staking Reward: 2.00000000 NLM (25%) */
    
    const uint64_t PON_BLOCK_REWARD                                        = UINT64_C(100'000000);            /* PoN Reward: 1.00000000 NLM */

    const uint32_t MASTERNODE_ENABLE_HEIGHT                                = 259200;                          /* Masternodes (Phase 2) will start at height 259,200 */
    const uint32_t STAKING_ENABLE_HEIGHT                                   = MASTERNODE_ENABLE_HEIGHT;        /* Staking (Phase 2) will start at height 259,200 */

    const uint32_t MASTERNODE_PHASE3_HEIGHT                                = 518400;                          /* Masternodes Phase 3 at block height 518,400 */
    const uint32_t STAKING_PHASE3_HEIGHT                                   = MASTERNODE_PHASE3_HEIGHT;        /* Staking Phase 3 at block height 518,400 */

    const uint32_t PON_ENABLE_HEIGHT                                       = 5000000;                         /* Proof of Node (PoN) enable height */

    const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                             = 0;
    const size_t   ZAWY_DIFFICULTY_V2                                      = 0;
    const uint8_t  ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION                = 3;
    const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX                           = 0;
    const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V2                        = 0;
    const uint64_t LWMA_2_DIFFICULTY_BLOCK_INDEX_V3                        = 0;
    const unsigned EMISSION_SPEED_FACTOR                                   = 20;
    const unsigned EMISSION_SPEED_FACTOR_V2                                = 24;
    const unsigned EMISSION_SPEED_FACTOR_V2_BLOCK_VERSION                  = 3;                               /* = BLOCK_MAJOR_VERSION_3 */

    static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");
    static_assert(EMISSION_SPEED_FACTOR_V2 <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR_V2");

    const char GENESIS_COINBASE_TX_HEX[] = 
      "010a01ff00018088debe01029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd08807121015f345651bdefec4e8fd9a5fe41c3985eb4a51351e50a72720fa5f80f42f6230c";

    static_assert(
      sizeof(GENESIS_COINBASE_TX_HEX) / sizeof(*GENESIS_COINBASE_TX_HEX) != 1,
      "GENESIS_COINBASE_TX_HEX must not be empty.");

    /* This is the unix timestamp of the first "mined" block (technically block 2, not the genesis block)
       You can get this value by doing "print_block 2" in Rezind. It is used to know what timestamp
       to import from when the block height cannot be found in the node or the node is offline. */
    const uint64_t GENESIS_BLOCK_TIMESTAMP                                 = 1704803400;                    /* 01:30 PM GMT+1, 9th of January 2024 */
    const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW                         = 100;
    const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE               = 100000;                        /* size of block (bytes) after which reward for block calculated using block size */
    const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2            = 20000;
    const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1            = 10000;
    const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT       = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
    const size_t   CRYPTONOTE_BLOCK_REDUCTION_SIZE                         = 50000;
    const size_t   CRYPTONOTE_BLOCK_REDUCTION_RATE                         = 2;                             /* rotating 2 reduced blocks + 1 full block */
    const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE                  = 600;
    static_assert(CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE > CRYPTONOTE_BLOCK_REDUCTION_SIZE, "Reduction can not be bigger than full.");
    static_assert(CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100 < CRYPTONOTE_BLOCK_REDUCTION_SIZE, "Reduction is too small.");

    const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT                        = 8;
    const uint64_t MINIMUM_FEE = UINT64_C(1000);
    
    /* New fee V2
       Fee per byte is rounded up in chunks. This helps makes estimates
       more accurate. It's suggested to make this a power of two, to relate
       to the underlying storage cost / page sizes for storing a transaction. */
    const uint64_t FEE_PER_BYTE_CHUNK_SIZE                                 = 256;

    /* Fee to charge per byte of transaction. Will be applied in chunks, see
       above. This value comes out to 1.953125. We use this value instead of
       something like 200 because it makes for pretty resulting fees
       - 5 NLM vs 5.12 NLM. You can read this as.. the fee per chunk
       is 512000 atomic units. The fee per byte is 512000 / chunk size. */
    const double   MINIMUM_FEE_PER_BYTE_V1                                 = 100 / FEE_PER_BYTE_CHUNK_SIZE;

    /* Height for our first fee to byte change to take effect. */
    const uint64_t MINIMUM_FEE_PER_BYTE_V1_HEIGHT = 10000000; // 10M
    
    /* Backward compatibility */
    const uint64_t ACCEPTABLE_FEE                                          = UINT64_C(1000);     /* with this fee, tx is always accepted whatever size - 0.00000100 NLM */
    const uint64_t ACCEPTABLE_FEE_V1                                       = UINT64_C(1000);     /* with this fee, tx is always accepted whatever size - 0.00000100 NLM */

    /* This section defines our minimum and maximum mixin counts required for transactions */
    const uint64_t MINIMUM_MIXIN_V1                                        = 0;
    const uint64_t MAXIMUM_MIXIN_V1                                        = 7;
    const uint64_t MINIMUM_MIXIN_V2                                        = 0;
    const uint64_t MAXIMUM_MIXIN_V2                                        = 3;
    const uint64_t MINIMUM_MIXIN_V3                                        = MINIMUM_MIXIN_V2;
    const uint64_t MAXIMUM_MIXIN_V3                                        = MAXIMUM_MIXIN_V2;

    /* The heights to activate the mixin limits at */
    const uint32_t MIXIN_LIMITS_V1_HEIGHT                                  = 0;
    const uint32_t MIXIN_LIMITS_V2_HEIGHT                                  = 500000;
    const uint32_t MIXIN_LIMITS_V3_HEIGHT                                  = 1000000;

    /* The mixin to use by default with zedwallet and turtle-service */
    /* DEFAULT_MIXIN_V0 is the mixin used before MIXIN_LIMITS_V1_HEIGHT is started */
    const uint64_t DEFAULT_MIXIN_V0                                        = 0;
    const uint64_t DEFAULT_MIXIN_V1                                        = 0;
    const uint64_t DEFAULT_MIXIN_V2                                        = 0;
    const uint64_t DEFAULT_MIXIN_V3                                        = DEFAULT_MIXIN_V2;

    const uint64_t DEFAULT_DUST_THRESHOLD                                  = UINT64_C(0);
    const uint64_t DEFAULT_DUST_THRESHOLD_V2                               = UINT64_C(0);
    const uint32_t DUST_THRESHOLD_V2_HEIGHT                                = 0;
    const uint32_t FUSION_DUST_THRESHOLD_HEIGHT_V2                         = 0;
    const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY                       = 24 * 60 * 60 / DIFFICULTY_TARGET;

    const size_t   DIFFICULTY_WINDOW                                       = 60;
    const size_t   DIFFICULTY_WINDOW_V1                                    = 60;
    const size_t   DIFFICULTY_WINDOW_V2                                    = 60;
    const uint64_t DIFFICULTY_WINDOW_V3                                    = 60;
    const uint64_t DIFFICULTY_BLOCKS_COUNT                                 = DIFFICULTY_WINDOW + 1;
    const uint64_t DIFFICULTY_BLOCKS_COUNT_V3                              = DIFFICULTY_WINDOW_V3 + 1;
    const size_t   DIFFICULTY_CUT                                          = 60;
    const size_t   DIFFICULTY_CUT_V1                                       = 60;
    const size_t   DIFFICULTY_CUT_V2                                       = 60;
    const size_t   DIFFICULTY_LAG                                          = 0;
    const size_t   DIFFICULTY_LAG_V1                                       = 0;
    const size_t   DIFFICULTY_LAG_V2                                       = 0;
    
    const size_t   MAX_BLOCK_SIZE_INITIAL                                  = 100000;
    const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR                   = 100 * 1024;
    const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR                 = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
    const uint64_t MAX_EXTRA_SIZE                                          = 140000;
    const uint64_t MAX_EXTRA_SIZE_V2                                       = 1024;
    const uint64_t MAX_EXTRA_SIZE_V2_HEIGHT                                = 0;

    /* 30,000,000 NLM -> Max supply / mixin+1 outputs                 */
    /* This is enforced on the daemon side. An output > 30,000,000 causes an invalid block.   */
    const uint64_t MAX_OUTPUT_SIZE_NODE                                    = 30'000'000'00000000;

    /* 500,000 NLM */
    /* This is enforced on the client side. An output > 500,000 will not be created in a transaction */
    const uint64_t MAX_OUTPUT_SIZE_CLIENT                                  = 500'000'00000000;
    const uint64_t MAX_OUTPUT_SIZE_HEIGHT                                  = 500000;

    /* For new projects forked from this code base, the values immediately below
       should be changed to 0 to prevent issues with transaction processing
       and other possible unexpected behavior */
    const uint64_t TRANSACTION_SIGNATURE_COUNT_VALIDATION_HEIGHT           = 0;
    const uint64_t BLOCK_BLOB_SHUFFLE_CHECK_HEIGHT                         = 0;
    const uint64_t TRANSACTION_INPUT_BLOCKTIME_VALIDATION_HEIGHT           = 0;

    /* This describes how many blocks of "wiggle" room transactions have regarding
       when the outputs can be spent based on a reasonable belief that the outputs
       would unlock in the current block period */
    const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS               = 1;
    const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS              = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

    const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                          = 60 * 60 * 24;     // seconds, one day
    const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME           = 60 * 60 * 24 * 7; // seconds, one week
    const uint64_t CRYPTONOTE_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL       = 7;

    const size_t   FUSION_TX_MAX_SIZE                                      = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
    const size_t   FUSION_TX_MIN_INPUT_COUNT                               = 12;
    const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO                        = 4;

    /* This sets the maximum number of fusion transactions that can be present in the pool
       at any given time. Incoming fusion transactions that attempt to exceed this limit
       will be rejected from the pool and will not be added. This mechanism is in place
       to help curtail fusion transaction spam. */
    const size_t   FUSION_TX_MAX_POOL_COUNT                                = 20;
    const size_t   NORMAL_TX_MAX_OUTPUT_COUNT_V1                           = 90;
    const size_t   NORMAL_TX_MAX_OUTPUT_COUNT_V1_HEIGHT                    = 250;
    const uint32_t UPGRADE_HEIGHT_V2                                       = 1; 
    const uint32_t UPGRADE_HEIGHT_V3                                       = 2;
    const uint32_t UPGRADE_HEIGHT_V4                                       = 3; 
    const uint32_t UPGRADE_HEIGHT_V5                                       = 4;
    const uint32_t UPGRADE_HEIGHT_V6                                       = 5;
    const uint32_t UPGRADE_HEIGHT_CURRENT                                  = UPGRADE_HEIGHT_V6;
    const unsigned UPGRADE_VOTING_THRESHOLD                                = 90;
    const uint32_t UPGRADE_VOTING_WINDOW                                   = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
    const uint32_t UPGRADE_WINDOW                                          = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;
    
    static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
    static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

    /* Hard fork block heights */
    const uint64_t FORK_HEIGHTS[] = {
      250,    /* 0 ~ TRANSACTION_SIGNATURE_COUNT_VALIDATION, BLOCK_BLOB_SHUFFLE_CHECK, TRANSACTION_INPUT_BLOCKTIME_VALIDATION, NORMAL_TX_MAX_OUTPUT_COUNT_V1 */
      50000,  /* 1 ~ MIXIN LIMIT V2 */
      250000, /* 2 ~ MIXIN LIMIT V3 */
      500000  /* 3 ~ MAX_OUTPUT_SIZE */
    };

    /* MAKE SURE TO UPDATE THIS VALUE WITH EVERY MAJOR RELEASE BEFORE A FORK - Count from 0 */
    const uint64_t SOFTWARE_SUPPORTED_FORK_INDEX                           = 0;
    const uint64_t FORK_HEIGHTS_SIZE                                       = sizeof(FORK_HEIGHTS) / sizeof(*FORK_HEIGHTS);
    const uint8_t  CURRENT_FORK_INDEX                                      = FORK_HEIGHTS_SIZE == 0 ? 0 : SOFTWARE_SUPPORTED_FORK_INDEX;
    //static_assert(CURRENT_FORK_INDEX >= 0, "CURRENT FORK INDEX must be >= 0");
    static_assert(FORK_HEIGHTS_SIZE == 0 || CURRENT_FORK_INDEX < FORK_HEIGHTS_SIZE, "CURRENT_FORK_INDEX out of range of FORK_HEIGHTS!");

    const char CRYPTONOTE_BLOCKS_FILENAME[]                                = "blocks.bin";
    const char CRYPTONOTE_BLOCKINDEXES_FILENAME[]                          = "blockindexes.bin";
    const char CRYPTONOTE_POOLDATA_FILENAME[]                              = "poolstate.bin";
    const char P2P_NET_DATA_FILENAME[]                                     = "p2pstate.bin";
    const char MINER_CONFIG_FILE_NAME[]                                    = "miner_conf.json";
  }

  const char    CRYPTONOTE_NAME[]                                          = "Rezin";
  const uint8_t TRANSACTION_VERSION_1                                      = 1;
  const uint8_t TRANSACTION_VERSION_2                                      = 2;
  const uint8_t CURRENT_TRANSACTION_VERSION                                = TRANSACTION_VERSION_1;

  const uint8_t BLOCK_MAJOR_VERSION_1                                      = 1;                /* Height 1 */
  const uint8_t BLOCK_MAJOR_VERSION_2                                      = 2;                /* UPGRADE_HEIGHT_V2 */
  const uint8_t BLOCK_MAJOR_VERSION_3                                      = 3;                /* UPGRADE_HEIGHT_V3 */
  const uint8_t BLOCK_MAJOR_VERSION_4                                      = 4;                /* UPGRADE_HEIGHT_V4 */
  const uint8_t BLOCK_MAJOR_VERSION_5                                      = 5;                /* UPGRADE_HEIGHT_V5 */
  const uint8_t BLOCK_MAJOR_VERSION_6                                      = 6;                /* UPGRADE_HEIGHT_V6 */

  const uint8_t BLOCK_MINOR_VERSION_0                                      = 0;
  const uint8_t BLOCK_MINOR_VERSION_1                                      = 1;

  const std::unordered_map<uint8_t, std::function<void(const void *data, size_t length, Crypto::Hash &hash)>>
    HASHING_ALGORITHMS_BY_BLOCK_VERSION = {
      {BLOCK_MAJOR_VERSION_1, Crypto::cn_turtle_lite_slow_hash_v2},    /* Height 1 */
      {BLOCK_MAJOR_VERSION_2, Crypto::cn_turtle_lite_slow_hash_v2},    /* UPGRADE_HEIGHT_V2 */
      {BLOCK_MAJOR_VERSION_3, Crypto::cn_turtle_lite_slow_hash_v2},    /* UPGRADE_HEIGHT_V3 */
      {BLOCK_MAJOR_VERSION_4, Crypto::cn_turtle_lite_slow_hash_v2},    /* UPGRADE_HEIGHT_V4 */
      {BLOCK_MAJOR_VERSION_5, Crypto::cn_turtle_lite_slow_hash_v2},    /* UPGRADE_HEIGHT_V5 */
      {BLOCK_MAJOR_VERSION_6, Crypto::cn_turtle_lite_slow_hash_v2}     /* UPGRADE_HEIGHT_V6 */
    };


  const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT                    = 10000;           // by default, blocks ids count in synchronizing
  const uint64_t BLOCKS_SYNCHRONIZING_DEFAULT_COUNT                        = 20;              // by default, blocks count in blocks downloading
  const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT                     = 100;
  const int      P2P_DEFAULT_PORT                                          = 21000;           // P2P Port
  const int      RPC_DEFAULT_PORT                                          = 21001;           // RPC Port
  const int      SERVICE_DEFAULT_PORT                                      = 21002;           // Service Port
  const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                            = 1000;
  const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                             = 5000;

  const uint8_t  P2P_CURRENT_VERSION                                       = 1;                // Current version
  const uint8_t  P2P_MINIMUM_VERSION                                       = 1;                // Minimum supported version
  const uint8_t  P2P_UPGRADE_WINDOW                                        = 1;                // Version to upgrade from

  const uint8_t  P2P_LITE_BLOCKS_PROPOGATION_VERSION                       = 0;
  const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE                      = 32 * 1024 * 1024; // 32 MB
  const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                             = 32;               // 32 Connections
  const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT                 = 70;
  const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                            = 60;               // 60 Seconds
  const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                               = 50000000;         // 50,000,000 bytes maximum packet size
  const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                            = 250;

  const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                            = 5000;             // 5 Seconds
  const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT                       = 2000;             // 2 Seconds
  const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                                = 60 * 2 * 1000;    // 2 Minutes
  const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT                      = 5000;             // 5 Seconds
  const char     P2P_STAT_TRUSTED_PUB_KEY[]                                = "";

  #if !defined(USE_LEVELDB)
    const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE                   = 256;            // 256 MB
    const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE                    = 64;             // 64 MB
    const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES                         = 50;             // 500 Files
    const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT               = 4;              // 4 DB Threads
    const uint64_t DATABASE_MAX_BYTES_FOR_LEVEL_BASE                       = 512;            // 512 MB
  #else
    const uint64_t DATABASE_WRITE_BUFFER_MB_DEFAULT_SIZE                   = 64;             // 64 MB
    const uint64_t DATABASE_READ_BUFFER_MB_DEFAULT_SIZE                    = 64;             // 64 MB
    const uint32_t DATABASE_DEFAULT_MAX_OPEN_FILES                         = 128;            // 128 Files
    const uint16_t DATABASE_DEFAULT_BACKGROUND_THREADS_COUNT               = 8;              // 8 DB Threads
  #endif

  const char LATEST_VERSION_URL[]                                          = "https://github.com/Rezin-Coin/Rezin/releases";
  const std::string LICENSE_URL                                            = "https://github.com/Rezin-coin/Rezin/blob/master/LICENSE";

  const static boost::uuids::uuid CRYPTONOTE_NETWORK = {
    {0xdd, 0xae, 0xba, 0xed, 0xcc, 0xfa, 0xbc, 0xba, 0x12, 0x34, 0x56, 0x78, 0x90, 0x9c, 0xba, 0xdc}
  };

  const char *const SEED_NODES[] = {
    "192.168.0.119:21000",
    "192.168.0.112:21100"
  };
}
