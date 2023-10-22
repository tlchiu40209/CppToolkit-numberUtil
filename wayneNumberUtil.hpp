/*
 * wayneNumberUtil.hpp
 *
 *  Created on: 2023年10月22日
 *      Author: weich
 */

#ifndef LIB_WAYNENUMBERUTIL_HPP_
#define LIB_WAYNENUMBERUTIL_HPP_
#include <cstring>
#include <climits>
#include <vector>
#include "wayneIO.hpp";

namespace wayne {
	namespace numberUtil {

		std::vector<char> intToHexBytes(int number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		std::vector<char> longToHexBytes(long number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		std::vector<char> unsignedIntToHexBytes(unsigned int number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		std::vector<char> unsignedLongToHexBytes(unsigned long number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');

		char* intToHexBytesStatic(int number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		char* longToHexBytesStatic(long number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		char* unsignedIntToHexBytesStatic(unsigned int number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');
		char* unsignedLongToHexBytesStatic(unsigned long number, bool isFixedLength = false, int fixedLength = 0, char padByte = '\x00');

		int hexBytesStaticToInt(char* hexBytes, int hexLength, bool isPositive = true);
		long hexBytesStaticToLong(char* hexBytes, int hexLength, bool isPositive = true);
		unsigned int unsignedHexBytesStaticToInt(char* hexBytes, int hexLength);
		unsigned long unsignedHexBytesStaticToLong(char* hexBytes, int hexLength);

		int hexBytesToInt(std::vector<char> hexBytes, bool isPositive = true);
		long hexBytesToLong(std::vector<char> hexBytes, bool isPositive = true);
		unsigned int unsignedHexBytesToInt(std::vector<char> hexBytes);
		unsigned long unsignedHexBytesToLong(std::vector<char> hexBytes);

		unsigned int getOnesComplimentUnsignedInt(int negativeNumber, unsigned int byteLength);
		unsigned long getOnesComplimentUnsignedLong(long negativeNumber, unsigned int byteLength);
		unsigned int getTwosComplimentUnsignedInt(int negativeNumber, unsigned int byteLength);
		unsigned long getTwosComplimentUnsignedLong(long negativeNumber, unsigned int byteLength);


	} /* namespace numberUtil */
} /* namespace wayne */

#endif /* LIB_WAYNENUMBERUTIL_HPP_ */
