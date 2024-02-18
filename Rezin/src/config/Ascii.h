// Copyright (c) 2018, The TurtleCoin Developers
//
// Please see the included LICENSE file for more information
#include <config/CryptoNoteConfig.h>
#include <config/WalletConfig.h>

#pragma once

const std::string asciiArt =
"\n"
"\n                       \n"
" _____    _____   _____ \n"
"|  __ \\  / ____| / ____|\n"
"| |__) || |     | |     \n"
"|  _  / | |     | |     \n"
"| | \\ \\ | |____ | |____ \n"
"|_|  \\_\\ \\_____| \\_____|\n";

const std::string asciiArtStart =
"\n"
"\n"
"     ______    ______   ______       \n"
"   (_____ \\  / _____) / _____)  \n"
"    _____) )| /      | /        Block Time: " + std::to_string(CryptoNote::parameters::DIFFICULTY_TARGET) + " seconds   \n"
"   (_____ ( | |      | |       Maximum Supply: " + std::to_string((CryptoNote::parameters::MONEY_SUPPLY / pow(10, CryptoNote::parameters::CRYPTONOTE_DISPLAY_DECIMAL_POINT))) + " " + std::string(WalletConfig::ticker) + "\n" 
"        | || \\_____ | \\_____   P2P Port: " + std::to_string(CryptoNote::P2P_DEFAULT_PORT) + "\n"
"        |_| \\______) \\______)    RPC Port: " + std::to_string(CryptoNote::RPC_DEFAULT_PORT) + "\n"
"     Wallet Port: " + std::to_string(CryptoNote::SERVICE_DEFAULT_PORT) + "\n"
"      Ticker: " + WalletConfig::ticker + "\n"
"     Decimals: " + std::to_string(CryptoNote::parameters::CRYPTONOTE_DISPLAY_DECIMAL_POINT) + "\n"
"       PoS Height: " + std::to_string(CryptoNote::parameters::STAKING_ENABLE_HEIGHT) + "\n"
"   \n" // "   %%%%             %%%%%%               %%%%    PoN Height: " + std::to_string(CryptoNote::parameters::PON_ENABLE_HEIGHT) + "\n"
