#ifndef __TRIPLEDESECBPERMOP__
#define __TRIPLEDESECBPERMOP__

#include "../plainkeycipher.h"

// Test vectors from <http://csrc.nist.gov/groups/STM/cavp/documents/des/KAT_TDES.zip>

static const std::vector <PlainKeyCipher> TDES_PERMOP = {
    std::make_tuple("0000000000000000", "1046913489980131", "88d55e54f54c97b4"),
    std::make_tuple("0000000000000000", "1007103489988020", "0c0cc00c83ea48fd"),
    std::make_tuple("0000000000000000", "10071034c8980120", "83bc8ef3a6570183"),
    std::make_tuple("0000000000000000", "1046103489988020", "df725dcad94ea2e9"),
    std::make_tuple("0000000000000000", "1086911519190101", "e652b53b550be8b0"),
    std::make_tuple("0000000000000000", "1086911519580101", "af527120c485cbb0"),
    std::make_tuple("0000000000000000", "5107b01519580101", "0f04ce393db926d5"),
    std::make_tuple("0000000000000000", "1007b01519190101", "c9f00ffc74079067"),
    std::make_tuple("0000000000000000", "3107915498080101", "7cfd82a593252b4e"),
    std::make_tuple("0000000000000000", "3107919498080101", "cb49a2f9e91363e3"),
    std::make_tuple("0000000000000000", "10079115b9080140", "00b588be70d23f56"),
    std::make_tuple("0000000000000000", "3107911598080140", "406a9a6ab43399ae"),
    std::make_tuple("0000000000000000", "1007d01589980101", "6cb773611dca9ada"),
    std::make_tuple("0000000000000000", "9107911589980101", "67fd21c17dbb5d70"),
    std::make_tuple("0000000000000000", "9107d01589190101", "9592cb4110430787"),
    std::make_tuple("0000000000000000", "1007d01598980120", "a6b7ff68a318ddd3"),
    std::make_tuple("0000000000000000", "1007940498190101", "4d102196c914ca16"),
    std::make_tuple("0000000000000000", "0107910491190401", "2dfa9f4573594965"),
    std::make_tuple("0000000000000000", "0107910491190101", "b46604816c0e0774"),
    std::make_tuple("0000000000000000", "0107940491190401", "6e7e6221a4f34e87"),
    std::make_tuple("0000000000000000", "19079210981a0101", "aa85e74643233199"),
    std::make_tuple("0000000000000000", "1007911998190801", "2e5a19db4d1962d6"),
    std::make_tuple("0000000000000000", "10079119981a0801", "23a866a809d30894"),
    std::make_tuple("0000000000000000", "1007921098190101", "d812d961f017d320"),
    std::make_tuple("0000000000000000", "100791159819010b", "055605816e58608f"),
    std::make_tuple("0000000000000000", "1004801598190101", "abd88e8b1b7716f1"),
    std::make_tuple("0000000000000000", "1004801598190102", "537ac95be69da1e1"),
    std::make_tuple("0000000000000000", "1004801598190108", "aed0f6ae3c25cdd8"),
    std::make_tuple("0000000000000000", "1002911598100104", "b3e35a5ee53e7b8d"),
    std::make_tuple("0000000000000000", "1002911598190104", "61c79c71921a2ef8"),
    std::make_tuple("0000000000000000", "1002911598100201", "e2f5728f0995013c"),
    std::make_tuple("0000000000000000", "1002911698100101", "1aeac39a61f0a464"),
};

#endif // __TRIPLEDESECBPERMOP__